#ifndef ethfunctions_h
#define ethfunctions_h
#include "Header.h"

#define MODE_CMD "++mode 1\n"
#define AUTOTALK_CMD "++auto 1\n"
#define AUTOLISTEN_CMD "++auto 0\n"

// Function to reset the Specan
void ethspecReset(SOCKET sock, const char* specGPIB)
{
	//////////////////////////////////////////////////////////////
	//WSADATA wsaData;
	//// Initialize Winsock
	//if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	//{
	//	printf("WSAStartup failed: %d\n", WSAGetLastError());
	//}
	//////////////////////////////////////////////////////////////
	//SOCKET sock;
	//// Create a TCP socket
	//if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	//{
	//	printf("socket failed: %d\n", WSAGetLastError());
	//	closesocket(sock);
	//	WSACleanup();
	//}
	//////////////////////////////////////////////////////////////
	//// Creating a soc address
	//struct sockaddr_in service;

	//memset(&service, 0, sizeof(service));
	//service.sin_family = AF_INET;
	//service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	//service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	//////////////////////////////////////////////////////////////
	//// Connect to GPIB-ETHERNET adapter
	//if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	//{
	//	printf("connect failed: %d\n", WSAGetLastError());
	//	closesocket(sock);
	//	WSACleanup();
	//}
	//////////////////////////////////////////////////////////////
	// Initalizing variables for sending and receiving data
	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	size_t txbytes;
	////////////////////////////////////////////////////////////
	// Set GPIB to auto listen
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Specan)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send reset command to Specan
	txbytes = sprintf_s(buffer, "*RST\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("*RST send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
}

// Function to take in an int and converts it to a binary string
std::string intToBinary(int i) {
	std::string s;
	while (i != 0) {
		s = (i % 2 == 0 ? "0" : "1") + s;
		i /= 2;
	}
	return s;
}

// Function that takes in a double of the frequency to account for drift in the high band drawer
std::string driftHB(double freq)
{
	//std::string sigFreq = std::to_string(freq);
	double spfreq = 0;
	switch (units)
	{
	case 0:
		// Only apply drift for the HB drawer
		if (freq > 20000000)
		{
			double spefreq = freq / 1000000;
			spfreq = 69.156*spefreq + 23.42;
			spfreq /= 1000;
		}
		break;
	case 1:
		if (freq > 20000)
		{
			double spefreq = freq / 1000;
			spfreq = 69.156*spfreq + 23.42;
			spfreq /= 1000000;
		}
		break;
	case 2:
		if (freq > 20)
		{
			double spefreq = freq;
			spfreq = 69.156*spfreq + 23.42;
			spfreq /= 1000000000;
		}
		break;
	}
	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(16);
	streamObj << (freq + spfreq);
	std::string specFreq = streamObj.str();
	return specFreq;
}

// Function to convert the increament to the correct units
double convertInc(std::string increment) {
	double inc = std::stod(increment);
	if (units == 0 && unitsInc == 1)
	{
		inc *= 1000;
	}
	else if (units == 0 && unitsInc == 2)
	{
		inc *= 1000000;
	}
	else if (units == 1 && unitsInc == 0)
	{
		inc /= 1000;
	}
	else if (units == 1 && unitsInc == 2)
	{
		inc *= 1000;
	}
	else if (units == 2 && unitsInc == 0) {
		inc /= 1000000;
	}
	else if (units == 2 && unitsInc == 1) {
		inc /= 1000;
	}
	return inc;
}

// Ethernet version to setup specan
void ethSetupSpecan(SOCKET sock, const char* specGPIB, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string sweeps)
{
	// Reseting specan
	ethspecReset(sock, specGPIB);
	////////////////////////////////////////////////////////////
	// Intializing variables
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	////////////////////////////////////////////////////////////
	// Set auto listen
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Specan)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Setup SPECAN
	////////////////////////////////////////////////////////////
	// Send reference level to Specan

	std::string sRlev = ":DISP:TRAC:Y:SCAL:RLEV " + rLev + "\n";
	txbytes = sprintf_s(buffer, sRlev.c_str());

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RLEV send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send log scale 120 to Specan
	std::string sScal = ":DISP:TRAC:YSCAL " + scale + "\n";
	txbytes = sprintf_s(buffer, sScal.c_str());

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("SCAL send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Sending correct units to specan based on user input of span
	////////////////////////////////////////////////////////////
	if (unitsSpecSpan == 0)
	{
		////////////////////////////////////////////////////////////
		// Send span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "Hz\n";
		txbytes = sprintf_s(buffer, sSpan.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("SPAN send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecSpan == 1)
	{
		////////////////////////////////////////////////////////////
		// Send span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "kHz\n";
		txbytes = sprintf_s(buffer, sSpan.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("SPAN send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecSpan == 2)
	{
		////////////////////////////////////////////////////////////
		// Send span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "MHz\n";
		txbytes = sprintf_s(buffer, sSpan.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("SPAN send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecSpan == 3)
	{
		////////////////////////////////////////////////////////////
		// Send span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "GHz\n";
		txbytes = sprintf_s(buffer, sSpan.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("SPAN send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Sending correct units to specan based on user input of span
	////////////////////////////////////////////////////////////
	if (unitsSpecBand == 0)
	{
		////////////////////////////////////////////////////////////
		// Send resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "Hz\n";
		txbytes = sprintf_s(buffer, sBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("BAND send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecBand == 1)
	{
		////////////////////////////////////////////////////////////
		// Send resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "kHz\n";
		txbytes = sprintf_s(buffer, sBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("BAND send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecBand == 2)
	{
		////////////////////////////////////////////////////////////
		// Send resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "MHz\n";
		txbytes = sprintf_s(buffer, sBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("BAND send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecBand == 3)
	{
		////////////////////////////////////////////////////////////

		// Send resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "GHz\n";
		txbytes = sprintf_s(buffer, sBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("BAND send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Sending correct units to specan based on user input of span
	////////////////////////////////////////////////////////////
	if (unitsSpecVidBand == 0)
	{
		// Send video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "Hz\n";
		txbytes = sprintf_s(buffer, sVidBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("VID send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecVidBand == 1)
	{
		// Send video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "kHz\n";
		txbytes = sprintf_s(buffer, sVidBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("VID send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecVidBand == 2)
	{
		// Send video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "MHz\n";
		txbytes = sprintf_s(buffer, sVidBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("VID send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecVidBand == 3)
	{
		////////////////////////////////////////////////////////////
		// Send video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "GHz\n";
		txbytes = sprintf_s(buffer, sVidBand.c_str());

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("VID send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Send command to turn OFF single sweep to Specan
	txbytes = sprintf_s(buffer, ":INIT:CONT OFF\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("CONT OFF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send mode average to Specan
	if (!avgOFF)
	{
		txbytes = sprintf_s(buffer, ":DISP:WIND:TRAC:MODE AVER\n");

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("AVER send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
	}
	////////////////////////////////////////////////////////////
	// Send number of sweeps for average to Specan
	std::string sSweeps = ":SENS:SWE:COUN " + sweeps + "\n";
	txbytes = sprintf_s(buffer, sSweeps.c_str());

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("COUNT 5 send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
}
// Function to sweep through frequencies and record measurments taken for keysight siggen
void ethFrequencySweepK(SOCKET sock, std::string file,const char* sigGPIB, const char* specGPIB, double initF, double endF, double inc, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// Initalizing file
	std::ofstream myfile;
	////////////////////////////////////////////////////////////
	// Initializing variables
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	//pause = false;
	double previousFreq = NULL;
	////////////////////////////////////////////////////////////
	for (double freq = initF; freq < (endF + 0.000001); freq = freq + inc)
	{
		//switch (units)
		//{
		//case 0:
		//	if ((previousFreq != NULL && previousFreq < 2000000 && freq >= 2000000) || (previousFreq != NULL && previousFreq < 3100000 && freq >= 3100000)
		//		|| (previousFreq != NULL && previousFreq < 4000000 && freq >= 4000000) || (previousFreq != NULL && previousFreq < 4500000 && freq >= 4500000)
		//		|| (previousFreq != NULL && previousFreq < 5300000 && freq >= 5300000) || (previousFreq != NULL && previousFreq < 6100000 && freq >= 6100000)
		//		|| (previousFreq != NULL && previousFreq < 8000000 && freq >= 8000000) || (previousFreq != NULL && previousFreq < 10700000 && freq >= 10700000))
		//	{
		//		//pause = true;
		//	}
		//	break;
		//case 1:
		//	if ((previousFreq != NULL && previousFreq < 2000 && freq >= 2000) || (previousFreq != NULL && previousFreq < 3100 && freq >= 3100)
		//		|| (previousFreq != NULL && previousFreq < 4000 && freq >= 4000) || (previousFreq != NULL && previousFreq < 4500 && freq >= 4500)
		//		|| (previousFreq != NULL && previousFreq < 5300 && freq >= 5300) || (previousFreq != NULL && previousFreq < 6100 && freq >= 6100)
		//		|| (previousFreq != NULL && previousFreq < 8000 && freq >= 8000) || (previousFreq != NULL && previousFreq < 10700 && freq >= 10700))
		//	{
		//		//pause = true;
		//	}
		//	break;
		//case 2:
		//	if ((previousFreq != NULL && previousFreq < 2 && freq >= 2) || (previousFreq != NULL && previousFreq < 3.1 && freq >= 3.1)
		//		|| (previousFreq != NULL && previousFreq < 4 && freq >= 4) || (previousFreq != NULL && previousFreq < 4.5 && freq >= 4.5)
		//		|| (previousFreq != NULL && previousFreq < 5.3 && freq >= 5.3) || (previousFreq != NULL && previousFreq < 6.1 && freq >= 6.1)
		//		|| (previousFreq != NULL && previousFreq < 8 && freq >= 8) || (previousFreq != NULL && previousFreq < 10.7 && freq >= 10.7))
		//	{
		//		pause = true;
		//	}
		//	break;
		//}
		//if (!pause)
		//{
			////////////////////////////////////////////////////////////
			// Initalizing frequency string and opening file for appending writes
			std::string sigFreq = std::to_string(freq);
			std::string specFreq = driftHB(freq);
			myfile.open(file, std::ios_base::app);
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Selecting correct units to send to siggen and specan based on user input
			////////////////////////////////////////////////////////////
			if (units == 0)
			{
				////////////////////////////////////////////////////////////
				// Send Frequency to Siggen
				printf("Frequency = %f kHz\n", freq);
				sigFreq = "FREQ " + sigFreq + "KHZ\n";
				txbytes = sprintf_s(buffer, sigFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "kHz\n";
				txbytes = sprintf_s(buffer, specFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf(" Spec FREQ send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
			}
			else if (units == 1)
			{
				////////////////////////////////////////////////////////////
				// Send Frequency to Siggen
				printf("Frequency = %f MHz\n", freq);
				sigFreq = "FREQ " + sigFreq + "MHZ\n";
				txbytes = sprintf_s(buffer, sigFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "MHz\n";
				txbytes = sprintf_s(buffer, specFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("FREQ send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
			}
			else if (units == 2)
			{
				////////////////////////////////////////////////////////////
				// Send Frequency to Siggen
				printf("Frequency = %f GHz\n", freq);
				sigFreq = "FREQ " + sigFreq + "GHZ\n";
				txbytes = sprintf_s(buffer, sigFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "GHz\n";
				txbytes = sprintf_s(buffer, specFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("FREQ send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
			// Report rogress of frequency to update GUI on current measurement
			frequF = freq;
			background->ReportProgress(10);
			//////////////////////////////////////////////////////////////
			// Send trigger to Specan
			txbytes = sprintf_s(buffer, "*TRG\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("TRIG send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send operation complete query to Specan
			txbytes = strlen("*OPC?\n");
			if (send(sock, "*OPC?\n", (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("read failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			////////////////////////////////////////////////////////////
			// Send event status register query to Specan  
			txbytes = sprintf_s(buffer, "*ESR?\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("RF send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("ESR read failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}

				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send command to find the peak to Specan
			txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Max Peak send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send command to set the center frequency at the peak to Specan
			txbytes = sprintf_s(buffer, ":CALC:MARK:FUNC:CENT\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Center at marker send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send peak calibration query to Specan
			int ghz;
			if (units == 0) { ghz = 7000000; }
			else if (units == 1) { ghz = 7000; }
			else if (units == 2) { ghz = 7; }

			if (freq > ghz && ppeOFF == false)
				// if (freq > ghz)
			{
				txbytes = sprintf_s(buffer, ":CAL:PPE?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("PPE send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("PPE read failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Send operation complete query to Specan
				txbytes = sprintf_s(buffer, "*OPC?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("RF send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}

					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Send event status register query to Specan
				txbytes = sprintf_s(buffer, "*ESR?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("RF send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}

					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Set GPIB to auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send trigger to Specan
				txbytes = sprintf_s(buffer, "*TRG\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("TRIG send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send operation complete query to Specan
				txbytes = sprintf_s(buffer, "*OPC?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("*OPC? send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("read failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Send event status register query to Specan
				txbytes = sprintf_s(buffer, "*ESR?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("RF send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}

					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send command to find the peak to Specan
			txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Mark Peak send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();;
			}
			////////////////////////////////////////////////////////////
			// Send query to send back the marker placed on the peak's x coordinate (Frequency)
			txbytes = sprintf_s(buffer, ":CALC:MARK:X?\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Mark X send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}

				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			std::string markX = buffer;
			std::string delim = "\n";
			markX = markX.substr(0, markX.find(delim));
			if (markX.empty()) {
				myfile.close();
				closesocket(sock);
				WSACleanup();
				return;
			}
			// Outputing data
			printf("Mark X response: %s", buffer);
			myfile << markX;
			//////////////////////////////////////////////////////////
			// Send query to send back the marker placed on the peak's y coordinate (Amplitude)
			txbytes = sprintf_s(buffer, ":CALC:MARK:Y?\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Mark Y send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}

				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			// Outputing data
			printf("Mark Y response: %s", buffer);
			std::string markY = buffer;
			myfile << "," << markY;
			////////////////////////////////////////////////////////////
		//}
		previousFreq = freq;
		myfile.close();
	}
	////////////////////////////////////////////////////////////
	// RF Off of Siggen
	txbytes = sprintf_s(buffer, "OUTP OFF\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
}
// Function to sweep through frequencies and record measurments taken for anritsu siggen
void ethFrequencySweepA(SOCKET sock, std::string file, const char* sigGPIB, const char* specGPIB, double initF, double endF, double inc, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// Initalizing file
	std::ofstream myfile;
	////////////////////////////////////////////////////////////
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	//pause = false;
	double previousFreq = NULL;
	////////////////////////////////////////////////////////////
	for (double freq = initF; freq < (endF + 0.000001); freq = freq + inc)
	{
		//switch (units)
		//{
		//case 0:
		//	if ((previousFreq != NULL && previousFreq < 2000000 && freq >= 2000000) || (previousFreq != NULL && previousFreq < 3100000 && freq >= 3100000)
		//		|| (previousFreq != NULL && previousFreq < 4000000 && freq >= 4000000) || (previousFreq != NULL && previousFreq < 4500000 && freq >= 4500000)
		//		|| (previousFreq != NULL && previousFreq < 5300000 && freq >= 5300000) || (previousFreq != NULL && previousFreq < 6100000 && freq >= 6100000)
		//		|| (previousFreq != NULL && previousFreq < 8000000 && freq >= 8000000) || (previousFreq != NULL && previousFreq < 10700000 && freq >= 10700000))
		//	{
		//		pause = true;
		//		system("pause");
		//	}
		//	break;
		//case 1:
		//	if ((previousFreq != NULL && previousFreq < 2000 && freq >= 2000) || (previousFreq != NULL && previousFreq < 3100 && freq >= 3100)
		//		|| (previousFreq != NULL && previousFreq < 4000 && freq >= 4000) || (previousFreq != NULL && previousFreq < 4500 && freq >= 4500)
		//		|| (previousFreq != NULL && previousFreq < 5300 && freq >= 5300) || (previousFreq != NULL && previousFreq < 6100 && freq >= 6100)
		//		|| (previousFreq != NULL && previousFreq < 8000 && freq >= 8000) || (previousFreq != NULL && previousFreq < 10700 && freq >= 10700))
		//	{
		//		pause = true;
		//		system("pause");
		//	}
		//	break;
		//case 2:
		//	if ((previousFreq != NULL && previousFreq < 2 && freq >= 2) || (previousFreq != NULL && previousFreq < 3.1 && freq >= 3.1)
		//		|| (previousFreq != NULL && previousFreq < 4 && freq >= 4) || (previousFreq != NULL && previousFreq < 4.5 && freq >= 4.5)
		//		|| (previousFreq != NULL && previousFreq < 5.3 && freq >= 5.3) || (previousFreq != NULL && previousFreq < 6.1 && freq >= 6.1)
		//		|| (previousFreq != NULL && previousFreq < 8 && freq >= 8) || (previousFreq != NULL && previousFreq < 10.7 && freq >= 10.7))
		//	{
		//		pause = true;
		//		system("pause");
		//	}
		//	break;
		//}
		//if (!pause)
		//{
			////////////////////////////////////////////////////////////
			// Initalizing frequency string and opening file for appending writes
			std::string sigFreq = std::to_string(freq);
			std::string specFreq = driftHB(freq);
			myfile.open(file, std::ios_base::app);
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Selecting correct units to send to siggen and specan based on user input
			////////////////////////////////////////////////////////////
			if (units == 0)
			{
				////////////////////////////////////////////////////////////
				// Send Frequency to Siggen
				printf("Frequency = %f kHz\n", freq);
				sigFreq = "CF1 " + sigFreq + "KH\n";
				txbytes = sprintf_s(buffer, sigFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "kHz\n";
				txbytes = sprintf_s(buffer, specFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf(" Spec FREQ send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
			}
			else if (units == 1)
			{
				////////////////////////////////////////////////////////////
				// Send Frequency to Siggen
				printf("Frequency = %f MHz\n", freq);
				sigFreq = "CF1 " + sigFreq + "MH\n";
				txbytes = sprintf_s(buffer, sigFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "MHz\n";
				txbytes = sprintf_s(buffer, specFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("FREQ send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
			}
			else if (units == 2)
			{
				////////////////////////////////////////////////////////////
				// Send Frequency to Siggen
				printf("Frequency = %f GHz\n", freq);
				sigFreq = "CF1 " + sigFreq + "GH\n";
				txbytes = sprintf_s(buffer, sigFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "GHz\n";
				txbytes = sprintf_s(buffer, specFreq.c_str());

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("FREQ send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
			// Report rogress of frequency to update GUI on current measurement
			frequF = freq;
			background->ReportProgress(10);
			//////////////////////////////////////////////////////////////
			// Send trigger to Specan
			txbytes = sprintf_s(buffer, "*TRG\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("TRIG send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send operation complete query to Specan
			txbytes = strlen("*OPC?\n");
			if (send(sock, "*OPC?\n", (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("read failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			////////////////////////////////////////////////////////////
			// Send event status register query to Specan  
			txbytes = sprintf_s(buffer, "*ESR?\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("RF send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("ESR read failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}

				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send command to find the peak to Specan
			txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Max Peak send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send command to set the center frequency at the peak to Specan
			txbytes = sprintf_s(buffer, ":CALC:MARK:FUNC:CENT\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Center at marker send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send peak calibration query to Specan
			int ghz;
			if (units == 0) { ghz = 7000000; }
			else if (units == 1) { ghz = 7000; }
			else if (units == 2) { ghz = 7; }

			if (freq > ghz && ppeOFF == false)
				// if (freq > ghz)
			{
				txbytes = sprintf_s(buffer, ":CAL:PPE?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("PPE send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("PPE read failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Send operation complete query to Specan
				txbytes = sprintf_s(buffer, "*OPC?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("RF send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}

					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Send event status register query to Specan
				txbytes = sprintf_s(buffer, "*ESR?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("RF send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}

					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Set GPIB to auto listen
				txbytes = strlen(AUTOLISTEN_CMD);
				if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send trigger to Specan
				txbytes = sprintf_s(buffer, "*TRG\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("TRIG send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				txbytes = strlen(AUTOTALK_CMD);
				if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				////////////////////////////////////////////////////////////
				// Send operation complete query to Specan
				txbytes = sprintf_s(buffer, "*OPC?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("*OPC? send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("read failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
				////////////////////////////////////////////////////////////
				// Send event status register query to Specan
				txbytes = sprintf_s(buffer, "*ESR?\n");

				if (send(sock, buffer, (int)txbytes, 0) != txbytes)
				{
					printf("RF send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}
				// Read Response
				ptr = buffer;
				spaceleft = sizeof(buffer) - 1;

				do
				{
					rxbytes = 0;

					if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}

					// Adjust buffer pointer for next read
					ptr += rxbytes;
					spaceleft -= rxbytes;
				} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

				*ptr = 0;   // Null terminate buffer
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send command to find the peak to Specan
			txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Mark Peak send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			txbytes = strlen(AUTOTALK_CMD);
			if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();;
			}
			////////////////////////////////////////////////////////////
			// Send query to send back the marker placed on the peak's x coordinate (Frequency)
			txbytes = sprintf_s(buffer, ":CALC:MARK:X?\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Mark X send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}

				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			std::string markX = buffer;
			std::string delim = "\n";
			markX = markX.substr(0, markX.find(delim));
			if (markX.empty()) {
				myfile.close();
				closesocket(sock);
				WSACleanup();
				return;
			}
			// Outputing data
			printf("Mark X response: %s", buffer);
			myfile << markX;
			//////////////////////////////////////////////////////////
			// Send query to send back the marker placed on the peak's y coordinate (Amplitude)
			txbytes = sprintf_s(buffer, ":CALC:MARK:Y?\n");

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Mark Y send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			// Read Response
			ptr = buffer;
			spaceleft = sizeof(buffer) - 1;

			do
			{
				rxbytes = 0;

				if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
				{
					printf("send failed: %d\n", WSAGetLastError());
					closesocket(sock);
					WSACleanup();
				}

				// Adjust buffer pointer for next read
				ptr += rxbytes;
				spaceleft -= rxbytes;
			} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

			*ptr = 0;   // Null terminate buffer
			// Outputing data
			printf("Mark Y response: %s", buffer);
			std::string markY = buffer;
			myfile << "," << markY;
			////////////////////////////////////////////////////////////
		//}
		previousFreq = freq;
		myfile.close();
	}
	////////////////////////////////////////////////////////////
	// RF Off of Siggen
	txbytes = sprintf_s(buffer, "RF0\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
}

// Function to sweep through frequencies
void ethMeasureK(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string POW, std::string initFREQ, std::string endFREQ, std::string increment, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background) {
	////////////////////////////////////////////////////////////
	// Converting strings 
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);
	double inc = std::stod(increment);
	int P = std::stod(POW);
	////////////////////////////////////////////////////////////
	// Converting units between kHz, MHz, & GHz
	inc = convertInc(increment);
	////////////////////////////////////////////////////////////
	// Opening a txt file
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	WSADATA wsaData;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	SOCKET sock;
	// Create a TCP socket
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		printf("socket failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}

	// Creating a sock address 
	struct sockaddr_in service;

	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	////////////////////////////////////////////////////////////
	// Connect to GPIB-ETHERNET adapter
	if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	{
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Initalize variables
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	////////////////////////////////////////////////////////////
	// Send mode command. Configure GPIB-ETHERNET as GPIB Controller
	txbytes = strlen(MODE_CMD);
	if (send(sock, MODE_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Enable "read-after-write" mode.
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	ethSetupSpecan(sock, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// RF on of Siggen
	txbytes = sprintf_s(buffer, "OUTP ON\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Set power on Siggen
	std::string po = "POW " + POW + "DBM\n";
	txbytes = sprintf_s(buffer, po.c_str());
	printf("Amplitude = %d dBm\n", P);

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("POWER send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	// Reporting progress to update GUI with current measurements
	ampF = P;
	background->ReportProgress(10);
	////////////////////////////////////////////////////////////
	// Increment sig gen frequency and take measurments from spec an
	////////////////////////////////////////////////////////////
	ethFrequencySweepK(sock, file, sigGPIB, specGPIB, initF, endF, inc, background);
}

// Function to sweep through frequencies and amplitudes
void ethAmpFreqK(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, std::string incFREQ, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// Converting strings to be used by the function
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);
	double incF = std::stod(incFREQ);
	int initP = std::stod(initPOW);
	int endP = std::stod(endPOW);
	int incP = std::stod(incPOW);
	////////////////////////////////////////////////////////////
	// Converting units for incrementing
	incF = convertInc(incFREQ);
	////////////////////////////////////////////////////////////
	// Opening a txt file
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	WSADATA wsaData;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	SOCKET sock;
	// Create a TCP socket
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		printf("socket failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Creating a sock address
	struct sockaddr_in service;

	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	////////////////////////////////////////////////////////////
	// Connect to GPIB-ETHERNET adapter
	if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	{
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Initalizing variables to send and receive data
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	////////////////////////////////////////////////////////////
	// Send mode command. Configure GPIB-ETHERNET as GPIB Controller
	txbytes = strlen(MODE_CMD);
	if (send(sock, MODE_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Enable "read-after-write" mode.
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	ethSetupSpecan(sock, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send Rf on to Specan
	txbytes = sprintf_s(buffer, "OUTP ON\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Incrementing amplitude and frequency while taking measurements, then outputing said measurements 
	////////////////////////////////////////////////////////////
	// Set Pow and increment according to user input
	for (int pow = initP; pow <= endP; pow = pow + incP)
	{
		////////////////////////////////////////////////////////////
		// Specify address of instrument (Siggen)
		txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Send amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "POW " + sPOW + "DBM\n";
		txbytes = sprintf_s(buffer, sPOW.c_str());
		printf("Amplitude = %d dBm\n", pow);

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("POWER send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Reporting progress of the current measured amplitude to the GUI
		ampAF = pow;
		background->ReportProgress(10);
		////////////////////////////////////////////////////////////
		// Increment sig gen frequency and take measurments from spec an
		ethFrequencySweepK(sock, file, sigGPIB, specGPIB, initF, endF, incF, background);
	}
}

// Function to sweep through frequencies
void ethMeasureA(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string POW, std::string initFREQ, std::string endFREQ, std::string increment, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background) {
	////////////////////////////////////////////////////////////
	// Converting strings to use in the function
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);
	double inc = std::stod(increment);
	int P = std::stod(POW);
	////////////////////////////////////////////////////////////
	// Converting the increments units according to user input
	inc = convertInc(increment);
	////////////////////////////////////////////////////////////
	// Opening a clearing the text file
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	WSADATA wsaData;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	SOCKET sock;
	// Create a TCP socket
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		printf("socket failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Creating a socket address
	struct sockaddr_in service;

	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	////////////////////////////////////////////////////////////
	// Connect to GPIB-ETHERNET adapter
	if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	{
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Initalize variables for sending and receiving data
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	////////////////////////////////////////////////////////////
	// Send mode command. Configure GPIB-ETHERNET as GPIB Controller
	txbytes = strlen(MODE_CMD);
	if (send(sock, MODE_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	ethSetupSpecan(sock, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Set GPIB to auto listen
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// RF on of Siggen
	txbytes = sprintf_s(buffer, "RF1\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Set power on Siggen
	std::string po = "L1 " + POW + " DM\n";
	txbytes = sprintf_s(buffer, po.c_str());
	printf("Amplitude = %d dBm\n", P);

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("POWER send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Report progress of amplitude to the GUI
	ampF = P;
	background->ReportProgress(10);
	////////////////////////////////////////////////////////////
	// Increment sig gen frequency and take measurments from spec an
	ethFrequencySweepA(sock, file, sigGPIB, specGPIB, initF, endF, inc, background);
}

// Function to sweep through frequencies and amplitudes for Anritsu siggen
void ethAmpFreqA(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, std::string incFREQ, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// Converting strings used by the function
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);
	double incF = std::stod(incFREQ);
	int initP = std::stoi(initPOW);
	int endP = std::stoi(endPOW);
	int incP = std::stoi(incPOW);
	////////////////////////////////////////////////////////////
	// Converting the increment to the correct units
	incF = convertInc(incFREQ);
	////////////////////////////////////////////////////////////
	// Opening and clearing txt file
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	WSADATA wsaData;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	SOCKET sock;
	// Create a TCP socket
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		printf("socket failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Creating a sock address
	struct sockaddr_in service;

	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	////////////////////////////////////////////////////////////
	// Connect to GPIB-ETHERNET adapter
	if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	{
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Initalizing variables to send and receive data
	size_t txbytes;

	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	////////////////////////////////////////////////////////////
	// Send mode command. Configure GPIB-ETHERNET as GPIB Controller
	txbytes = strlen(MODE_CMD);
	if (send(sock, MODE_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	ethSetupSpecan(sock, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Set GPIB to auto talk
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send Rf on to Specan
	txbytes = sprintf_s(buffer, "RF1\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	// Setting ampitude and frequency and taking measurements
	////////////////////////////////////////////////////////////
	for (int pow = initP; pow <= endP; pow = pow + incP)
	{
		////////////////////////////////////////////////////////////
		// Set GPIB to auto talk
		txbytes = strlen(AUTOLISTEN_CMD);
		if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
		{
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Specify address of instrument (Siggen)
		txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Send amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "L1 " + sPOW + " DM\n";
		txbytes = sprintf_s(buffer, sPOW.c_str());
		printf("Amplitude = %d dBm\n", pow);

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("POWER send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Reporting progress on the current ampiltude to the GUI
		ampAF = pow;
		background->ReportProgress(10);
		////////////////////////////////////////////////////////////
		// Increment sig gen frequency and take measurments from spec an
		ethFrequencySweepA(sock, file, sigGPIB, specGPIB, initF, endF, incF, background);
	}
}

void ethHarmonicMeasK(std::string file, const char* ip, const char* specGPIB, const char* sigGPIB, std::string sweeps, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, double incF, int max, System::ComponentModel::BackgroundWorker^ background)
{
	// Converting strings to use in the function
	double initP = std::stod(initPOW);
	double endP = std::stod(endPOW);
	double incP = std::stod(incPOW);
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);
	////////////////////////////////////////////////////////////
	//Communication with GPIB
	////////////////////////////////////////////////////////////
	WSADATA wsaData2;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData2) != 0)
	{
		printf("WSAStartup failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	SOCKET sock;
	// Create a TCP socket
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		printf("socket failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Creating sock address
	struct sockaddr_in service;

	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	////////////////////////////////////////////////////////////
	// Connect to GPIB-ETHERNET adapter
	if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	{
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Initalizing variables for sending and receiving data
	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	size_t txbytes;
	////////////////////////////////////////////////////////////
	ethSetupSpecan(sock, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Set GPIB to auto talk
	txbytes = strlen(AUTOTALK_CMD);
	if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send Rf on to Specan
	txbytes = sprintf_s(buffer, "OUTP ON\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Begin going through amplitudes and frequencies
	////////////////////////////////////////////////////////////
	// Enable "read-after-write" mode. 
	txbytes = strlen(AUTOTALK_CMD);
	if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("Addr send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Set GPIB to auto listen
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	for (int pow = initP; pow > endP; pow -= incP)
	{
		////////////////////////////////////////////////////////////
		// Send amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "POW " + sPOW + "DBM\n";
		txbytes = sprintf_s(buffer, sPOW.c_str());
		printf("Amplitude = %d dBm\n", pow);

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("POWER send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Reporting progress on the current amplitude to the GUI
		ampAF = pow;
		background->ReportProgress(10);
		////////////////////////////////////////////////////////////
		for (double freq = initF; freq <= endF; freq += incF)
		{
			////////////////////////////////////////////////////////////
			std::string sigFreq = std::to_string(freq);
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Addr send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send frequency to Siggen
			sigFreq = "FREQ " + sigFreq + " MHz\n";
			txbytes = sprintf_s(buffer, sigFreq.c_str());

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Freq send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
		// Measureing 2 harmonics for each frequency
			for (double mul = 1; mul <= 3; mul++)
			{
				// Only measure harmonics within the range of the drawer
				if (freq <= max)
				{
					freq *= mul;
					////////////////////////////////////////////////////////////
					std::ofstream myfile;
					myfile.open(file, std::ios_base::app);
					std::string specFreq = driftHB(freq);
					////////////////////////////////////////////////////////////
					// Sending the correct units to the siggen and specan according to user input
					////////////////////////////////////////////////////////////
					// Set GPIB to auto listen
					txbytes = strlen(AUTOLISTEN_CMD);
					if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Specify address of instrument (Siggen)
					txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Addr send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Send center frequency to Specan
					specFreq = ":FREQ:CENT " + specFreq + " MHz\n";
					txbytes = sprintf_s(buffer, specFreq.c_str());

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Freq send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Reporting progress of the current frequency to the GUI
					frequF = freq;
					background->ReportProgress(10);
					////////////////////////////////////////////////////////////
					// Send peak calibration query to Specan
					int ghz;
					if (units == 0) { ghz = 7000000; }
					else if (units == 1) { ghz = 7000; }
					else if (units == 2) { ghz = 7; }

					if (freq > ghz && ppeOFF == false)
					{
						////////////////////////////////////////////////////////////
						// Send command to set a marker at the peak to Specan
						txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("Max Peak send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						// Enable "read-after-write" mode. 
						txbytes = strlen(AUTOTALK_CMD);
						if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						txbytes = sprintf_s(buffer, ":CAL:PPE?\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("PPE send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("PPE read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}
							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Send operation complete query to Specan
						txbytes = strlen("*OPC?\n");
						if (send(sock, "*OPC?\n", (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}
							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Send event status register query to Specan  
						txbytes = sprintf_s(buffer, "*ESR?\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("RF send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("ESR read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}

							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Set GPIB to auto listen
						txbytes = strlen(AUTOLISTEN_CMD);
						if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						//////////////////////////////////////////////////////////////
						// Send trigger to Specan
						txbytes = sprintf_s(buffer, "*TRG\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("TRIG send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						// Set GPIB to auto talk
						txbytes = strlen(AUTOTALK_CMD);
						if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						// Send operation complete query to Specan
						txbytes = strlen("*OPC?\n");
						if (send(sock, "*OPC?\n", (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}
							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Send event status register query to Specan  
						txbytes = sprintf_s(buffer, "*ESR?\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("RF send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("ESR read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}

							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
					}
					////////////////////////////////////////////////////////////
					// Set GPIB to auto listen
					txbytes = strlen(AUTOLISTEN_CMD);
					if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					//////////////////////////////////////////////////////////////
					// Send command to set a marker at the peak to Specan
					txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK");

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Max Peak send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Enable "read-after-write" mode. 
					txbytes = strlen(AUTOTALK_CMD);
					if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Send query to send back the marker placed on the peak's x coordinate (Frequency)
					txbytes = sprintf_s(buffer, ":CALC:MARK:X?\n");

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Mark X send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Read Response
					ptr = buffer;
					spaceleft = sizeof(buffer) - 1;

					do
					{
						rxbytes = 0;

						if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}

						// Adjust buffer pointer for next read
						ptr += rxbytes;
						spaceleft -= rxbytes;
					} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

					*ptr = 0;   // Null terminate buffer
					std::string markX = buffer;
					std::string delim = "\n";
					markX = markX.substr(0, markX.find(delim));
					if (markX.empty()) {
						myfile.close();
						closesocket(sock);
						WSACleanup();
						return;
					}
					// Outputing data
					printf("Mark X response: %s", buffer);
					myfile << markX;
					//////////////////////////////////////////////////////////
					// Send query to send back the marker placed on the peak's y coordinate (Amplitude)
					txbytes = sprintf_s(buffer, ":CALC:MARK:Y?\n");

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Mark Y send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Read Response
					ptr = buffer;
					spaceleft = sizeof(buffer) - 1;

					do
					{
						rxbytes = 0;

						if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}

						// Adjust buffer pointer for next read
						ptr += rxbytes;
						spaceleft -= rxbytes;
					} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

					*ptr = 0;   // Null terminate buffer
					// Outputing data
					printf("Mark Y response: %s", buffer);
					std::string markY = buffer;
					myfile << "," << markY;
					////////////////////////////////////////////////////////////
					myfile.close();
				}
			}
			////////////////////////////////////////////////////////////
		}
		////////////////////////////////////////////////////////////
	}
}

void ethHarmonicMeasA(std::string file, const char* ip, const char* specGPIB, const char* sigGPIB, std::string sweeps, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, double incF, int max, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// Converting strings to be used by the function
	double initP = std::stod(initPOW);
	double endP = std::stod(endPOW);
	double incP = std::stod(incPOW);
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);

	//Communication with GPIB
	////////////////////////////////////////////////////////////
	WSADATA wsaData2;
	// Initialize Winsock
	if (WSAStartup(MAKEWORD(2, 2), &wsaData2) != 0)
	{
		printf("WSAStartup failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	SOCKET sock;
	// Create a TCP socket
	if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
	{
		printf("socket failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Creating a sock address
	struct sockaddr_in service;

	memset(&service, 0, sizeof(service));
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = inet_addr(ip);     // GPIB-ETHERNET IP address
	service.sin_port = htons(1234);          // GPIB-ETHERNET Server port
	////////////////////////////////////////////////////////////
	// Connect to GPIB-ETHERNET adapter
	if (connect(sock, (struct sockaddr *) &service, sizeof(service)) < 0)
	{
		printf("connect failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Initializing variables for sending and receiving data
	char buffer[1024];
	char* ptr = buffer;
	int spaceleft = sizeof(buffer) - 1;   // Save space for NULL terminator
	int rxbytes = 0;
	size_t txbytes;
	////////////////////////////////////////////////////////////
	ethSetupSpecan(sock, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Set GPIB to auto talk
	txbytes = strlen(AUTOTALK_CMD);
	if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Send Rf on to Specan
	txbytes = sprintf_s(buffer, "RF1\n");

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("RF send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Begin going through amplitudes and frequencies
	////////////////////////////////////////////////////////////
	// Enable "read-after-write" mode. 
	txbytes = strlen(AUTOTALK_CMD);
	if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

	if (send(sock, buffer, (int)txbytes, 0) != txbytes)
	{
		printf("Addr send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Set GPIB to auto listen
	txbytes = strlen(AUTOLISTEN_CMD);
	if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
	{
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(sock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	for (int pow = initP; pow > endP; pow -= incP)
	{
		////////////////////////////////////////////////////////////
		// Send amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "L1 " + sPOW + " DM\n";
		txbytes = sprintf_s(buffer, sPOW.c_str());
		printf("Amplitude = %d dBm\n", pow);

		if (send(sock, buffer, (int)txbytes, 0) != txbytes)
		{
			printf("POWER send failed: %d\n", WSAGetLastError());
			closesocket(sock);
			WSACleanup();
		}
		////////////////////////////////////////////////////////////
		// Reporting progress on the current amplitude to the GUI
		ampAF = pow;
		background->ReportProgress(10);
		////////////////////////////////////////////////////////////
		for (double freq = initF; freq <= endF; freq += incF)
		{
			////////////////////////////////////////////////////////////
			std::string sigFreq = std::to_string(freq);
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			txbytes = strlen(AUTOLISTEN_CMD);
			if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
			{
				printf("send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			txbytes = sprintf_s(buffer, "++addr %d\n", atoi(sigGPIB));

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Addr send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
			////////////////////////////////////////////////////////////
			// Send frequency to Siggen
			sigFreq = "CF1 " + sigFreq + " MH\n";
			txbytes = sprintf_s(buffer, sigFreq.c_str());

			if (send(sock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Freq send failed: %d\n", WSAGetLastError());
				closesocket(sock);
				WSACleanup();
			}
				////////////////////////////////////////////////////////////
			// Measureing 2 harmonics for each frequency
			for (double mul = 1; mul <= 3; mul++)
			{
				freq *= mul;
				// Only measure harmonics within the range of the drawer
				if (freq <= max)
				{
					////////////////////////////////////////////////////////////
					std::ofstream myfile;
					myfile.open(file, std::ios_base::app);
					std::string specFreq = driftHB(freq);
					////////////////////////////////////////////////////////////
					// Sending the correct units to the siggen and specan according to user input
					////////////////////////////////////////////////////////////
					// Set GPIB to auto listen
					txbytes = strlen(AUTOLISTEN_CMD);
					if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Specify address of instrument (Siggen)
					txbytes = sprintf_s(buffer, "++addr %d\n", atoi(specGPIB));

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Addr send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Send center frequency to Specan
					specFreq = ":FREQ:CENT " + specFreq + " MHz\n";
					txbytes = sprintf_s(buffer, specFreq.c_str());

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Freq send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Reporting progress of the current frequency to the GUI
					frequF = freq;
					background->ReportProgress(10);
					////////////////////////////////////////////////////////////
					// Send peak calibration query to Specan
					int ghz;
					if (units == 0) { ghz = 7000000; }
					else if (units == 1) { ghz = 7000; }
					else if (units == 2) { ghz = 7; }

					if (freq > ghz && ppeOFF == false)
					{
						////////////////////////////////////////////////////////////
						// Send command to set a marker at the peak to Specan
						txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("Max Peak send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						// Enable "read-after-write" mode. 
						txbytes = strlen(AUTOTALK_CMD);
						if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						txbytes = sprintf_s(buffer, ":CAL:PPE?\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("PPE send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("PPE read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}
							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Send operation complete query to Specan
						txbytes = strlen("*OPC?\n");
						if (send(sock, "*OPC?\n", (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}
							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Send event status register query to Specan  
						txbytes = sprintf_s(buffer, "*ESR?\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("RF send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("ESR read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}

							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Set GPIB to auto listen
						txbytes = strlen(AUTOLISTEN_CMD);
						if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						//////////////////////////////////////////////////////////////
						// Send trigger to Specan
						txbytes = sprintf_s(buffer, "*TRG\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("TRIG send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						// Set GPIB to auto talk
						txbytes = strlen(AUTOTALK_CMD);
						if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						////////////////////////////////////////////////////////////
						// Send operation complete query to Specan
						txbytes = strlen("*OPC?\n");
						if (send(sock, "*OPC?\n", (int)txbytes, 0) != txbytes)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}
							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
						////////////////////////////////////////////////////////////
						// Send event status register query to Specan  
						txbytes = sprintf_s(buffer, "*ESR?\n");

						if (send(sock, buffer, (int)txbytes, 0) != txbytes)
						{
							printf("RF send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}
						// Read Response
						ptr = buffer;
						spaceleft = sizeof(buffer) - 1;

						do
						{
							rxbytes = 0;

							if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
							{
								printf("ESR read failed: %d\n", WSAGetLastError());
								closesocket(sock);
								WSACleanup();
							}

							// Adjust buffer pointer for next read
							ptr += rxbytes;
							spaceleft -= rxbytes;
						} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

						*ptr = 0;   // Null terminate buffer
					}
					////////////////////////////////////////////////////////////
					// Set GPIB to auto listen
					txbytes = strlen(AUTOLISTEN_CMD);
					if (send(sock, AUTOLISTEN_CMD, (int)txbytes, 0) != txbytes)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					//////////////////////////////////////////////////////////////
					// Send command to set a marker at the peak to Specan
					txbytes = sprintf_s(buffer, ":CALC:MARK:MAX:PEAK");

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Max Peak send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Enable "read-after-write" mode. 
					txbytes = strlen(AUTOTALK_CMD);
					if (send(sock, AUTOTALK_CMD, (int)txbytes, 0) != txbytes)
					{
						printf("send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Send query to send back the marker placed on the peak's x coordinate (Frequency)
					txbytes = sprintf_s(buffer, ":CALC:MARK:X?\n");

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Mark X send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Read Response
					ptr = buffer;
					spaceleft = sizeof(buffer) - 1;

					do
					{
						rxbytes = 0;

						if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}

						// Adjust buffer pointer for next read
						ptr += rxbytes;
						spaceleft -= rxbytes;
					} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

					*ptr = 0;   // Null terminate buffer
					std::string markX = buffer;
					std::string delim = "\n";
					markX = markX.substr(0, markX.find(delim));
					if (markX.empty()) {
						myfile.close();
						closesocket(sock);
						WSACleanup();
						return;
					}
					// Outputing data
					printf("Mark X response: %s", buffer);
					myfile << markX;
					//////////////////////////////////////////////////////////
					// Send query to send back the marker placed on the peak's y coordinate (Amplitude)
					txbytes = sprintf_s(buffer, ":CALC:MARK:Y?\n");

					if (send(sock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Mark Y send failed: %d\n", WSAGetLastError());
						closesocket(sock);
						WSACleanup();
					}
					// Read Response
					ptr = buffer;
					spaceleft = sizeof(buffer) - 1;

					do
					{
						rxbytes = 0;

						if ((rxbytes = recv(sock, ptr, spaceleft, 0)) < 0)
						{
							printf("send failed: %d\n", WSAGetLastError());
							closesocket(sock);
							WSACleanup();
						}

						// Adjust buffer pointer for next read
						ptr += rxbytes;
						spaceleft -= rxbytes;
					} while ((rxbytes != 0) && spaceleft && (*(ptr - 1) != '\n'));

					*ptr = 0;   // Null terminate buffer
					// Outputing data
					printf("Mark Y response: %s", buffer);
					std::string markY = buffer;
					myfile << "," << markY;
					////////////////////////////////////////////////////////////
					myfile.close();
				}
			}
			////////////////////////////////////////////////////////////
		}
		////////////////////////////////////////////////////////////
	}
}

void createMap(std::unordered_map<std::string, char> *um)
{
	(*um)["0000"] = '0';
	(*um)["0001"] = '1';
	(*um)["0010"] = '2';
	(*um)["0011"] = '3';
	(*um)["0100"] = '4';
	(*um)["0101"] = '5';
	(*um)["0110"] = '6';
	(*um)["0111"] = '7';
	(*um)["1000"] = '8';
	(*um)["1001"] = '9';
	(*um)["1010"] = 'A';
	(*um)["1011"] = 'B';
	(*um)["1100"] = 'C';
	(*um)["1101"] = 'D';
	(*um)["1110"] = 'E';
	(*um)["1111"] = 'F';
}

std::string convertBinStrtoHexStr(std::string bin)
{
	int s = bin.size();
	while (s % 4 != 0)
	{
		bin = '0' + bin;
		++s;
	}
	std::unordered_map<std::string, char> binHexMap;
	createMap(&binHexMap);
	int i = 0;
	std::string hex = "";
	while (1)
	{
		hex += binHexMap[bin.substr(i, 4)];
		i += 4;
		if (i == bin.size()) { break; }
	}
	return hex;
}

void maxPowerSweep(std::string file, const char* ip, const char* ipGPIB, const char* sigGPIB, const char* specGPIB, std::string sweeps, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, std::string incFREQ, std::string path, std::string atten, std::string atten2, std::string atten3, std::string atten4, std::string atten5, std::string swf1, std::string swf2, std::string swf3, System::ComponentModel::BackgroundWorker^ background, bool type)
{
	////////////////////////////////////////////////////////////
	// Initalizing variables used in the function
	std::string packet;
	std::string auxPacket;
	std::string attenByte;
	std::string attenByte2;
	std::string attenByte3;
	std::string attenByte4;
	std::string attenByte5;
	std::string pdwNum;				// PDW Number
	std::string rts;				// Rise time select
	std::string packetBin;
	std::string packetHex;
	int decAtten;
	int count = 0;
	int max;
	double incF = std::stod(incFREQ);
	double initF = std::stod(initFREQ);
	double endF = std::stod(endFREQ);
	size_t txbytes;
	char buffer[1024];
	bool alreadySent = false;
	////////////////////////////////////////////////////////////
	// Setting all relevent user inputs to MHz
	if (units == 0)
	{
		initF /= 1000;
		endF /= 1000;
	}
	else if (units == 2)
	{
		initF *= 1000;
		endF *= 1000;
	}
	////////////////////////////////////////////////////////////
	// Opening and clear txt file
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	// Setting increment to the correct units
	incF = convertInc(incFREQ);
	////////////////////////////////////////////////////////////
	// Initialize Winsock
	WSADATA wsaData1;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData1) != 0)
	{
		printf("WSAStartup Failed: %d\n", WSAGetLastError());
	}
	////////////////////////////////////////////////////////////
	// Create UDP socket
	SOCKET attenSock;
	if ((attenSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		printf("Socket Failed: %d\n", WSAGetLastError());
		closesocket(attenSock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Create struct for sockaddr
	struct sockaddr_in srv;
	memset(&srv, 0, sizeof(srv));
	srv.sin_family = AF_INET;
	srv.sin_addr.s_addr = inet_addr("192.168.2.101");

	srv.sin_port = htons(9900);
	////////////////////////////////////////////////////////////
	// Connect to device
	if (connect(attenSock, (struct sockaddr *) &srv, sizeof(srv)) < 0)
	{
		printf("Connect failed %d\n", WSAGetLastError());
		closesocket(attenSock);
		WSACleanup();
	}
	////////////////////////////////////////////////////////////
	// Creating the packet
	//////////////////////////////////////////////////////////
	// Selecting the path and setting max measurement frequency in MHz for each path for the harmonics
	if (path == "VLB")
	{
		packet = "000";
		max = 6000;
	}
	else if (path == "MB Main")
	{
		packet = "001";
		max = 18000;
	}
	else if (path == "MB AUX")
	{
		packet = "010";
		max = 18000;
	}
	else if (path == "HB")
	{
		packet = "011";
		max = 40000;
	}
	else
	{
		puts("Path not selected");
	}
	////////////////////////////////////////////////////////////
	// Selecting attenuation level and setting all five attenuators to the same level or selecting different levels for each
	// attenuator
	//////////////////////////////////////////////////////////
	// 0 db
	if (atten == "0")
	{
		attenByte = "000000000";
	}
	// 0.25 db
	else if (atten == "0.25")
	{
		attenByte = "000000001";
	}
	// 0.5 db
	else if (atten == "0.5")
	{
		attenByte = "000000010";
	}
	// 1 db
	else if (atten == "1")
	{
		attenByte = "000000100";
	}
	// 2 db
	else if (atten == "2")
	{
		attenByte = "000001000";
	}
	// 4 db
	else if (atten == "4")
	{
		attenByte = "000010000";
	}
	// 8 db
	else if (atten == "8")
	{
		attenByte = "000100000";
	}
	// 16 db
	else if (atten == "16")
	{
		attenByte = "001000000";
	}
	// 31.75 db
	else if (atten == "31.75 (010000000)")
	{
		attenByte = "010000000";
	}
	// 63.5 db
	else if (atten == "63.5 (100000000)")
	{
		attenByte = "100000000";
	}
	// 31.75 db
	else if (atten == "31.75 (001111111)")
	{
		attenByte = "001111111";
	}
	// 63.5 db
	else if (atten == "63.5 (011111111)")
	{
		attenByte = "011111111";
	}
	// 127 db
	else if (atten == "127")
	{
		attenByte = "111111111";
	}
	// 95.25 db
	else if (atten == "95.25 (110000000)")
	{
		attenByte = "110000000";
	}
	// 111.25 db
	else if (atten == "111.25")
	{
		attenByte = "111000000";
	}
	// 95.25 db
	else if (atten == "95.25 (101111111)")
	{
		attenByte = "101111111";
	}
	//////////////////////////////////////////////////////////
	// Advanced checkbox is checked so each attenuator can be set to different values and takes the first attenuators value
	// from the previous set of if/else statements
	if (advanced == 1)
	{
		//////////////////////////////////////////////////////////
		// Attenuator 2
		// 0 db
		if (atten2 == "0")
		{
			attenByte2 = "000000000";
		}
		// 0.25 db
		else if (atten2 == "0.25")
		{
			attenByte2 = "000000001";
		}
		// 0.5 db
		else if (atten2 == "0.5")
		{
			attenByte2 = "000000010";
		}
		// 1 db
		else if (atten2 == "1")
		{
			attenByte2 = "000000100";
		}
		// 2 db
		else if (atten2 == "2")
		{
			attenByte2 = "000001000";
		}
		// 4 db
		else if (atten2 == "4")
		{
			attenByte2 = "000010000";
		}
		// 8 db
		else if (atten2 == "8")
		{
			attenByte2 = "000100000";
		}
		// 16 db
		else if (atten2 == "16")
		{
			attenByte2 = "001000000";
		}
		// 31.75 db
		else if (atten2 == "31.75 (010000000)")
		{
			attenByte2 = "010000000";
		}
		// 63.5 db
		else if (atten2 == "63.5 (100000000)")
		{
			attenByte2 = "100000000";
		}
		// 31.75 db
		else if (atten2 == "31.75 (001111111)")
		{
			attenByte2 = "001111111";
		}
		// 63.5 db
		else if (atten2 == "63.5 (011111111)")
		{
			attenByte2 = "011111111";
		}
		// 127 db
		else if (atten2 == "127")
		{
			attenByte2 = "111111111";
		}
		// 95.25 db
		else if (atten2 == "95.25 (110000000)")
		{
			attenByte2 = "110000000";
		}
		// 111.25 db
		else if (atten2 == "111.25")
		{
			attenByte2 = "111000000";
		}
		// 95.25 db
		else if (atten2 == "95.25 (101111111)")
		{
			attenByte2 = "101111111";
		}
		//////////////////////////////////////////////////////////
		// Attenuator 3
		// 0 db
		if (atten3 == "0")
		{
			attenByte3 = "000000000";
		}
		// 0.25 db
		else if (atten3 == "0.25")
		{
			attenByte3 = "000000001";
		}
		// 0.5 db
		else if (atten3 == "0.5")
		{
			attenByte3 = "000000010";
		}
		// 1 db
		else if (atten3 == "1")
		{
			attenByte3 = "000000100";
		}
		// 2 db
		else if (atten3 == "2")
		{
			attenByte3 = "000001000";
		}
		// 4 db
		else if (atten3 == "4")
		{
			attenByte3 = "000010000";
		}
		// 8 db
		else if (atten3 == "8")
		{
			attenByte3 = "000100000";
		}
		// 16 db
		else if (atten3 == "16")
		{
			attenByte3 = "001000000";
		}
		// 31.75 db
		else if (atten3 == "31.75 (010000000)")
		{
			attenByte3 = "010000000";
		}
		// 63.5 db
		else if (atten3 == "63.5 (100000000)")
		{
			attenByte3 = "100000000";
		}
		// 31.75 db
		else if (atten3 == "31.75 (001111111)")
		{
			attenByte3 = "001111111";
		}
		// 63.5 db
		else if (atten3 == "63.5 (011111111)")
		{
			attenByte3 = "011111111";
		}
		// 127 db
		else if (atten3 == "127")
		{
			attenByte3 = "111111111";
		}
		// 95.25 db
		else if (atten3 == "95.25 (110000000)")
		{
			attenByte3 = "110000000";
		}
		// 111.25 db
		else if (atten3 == "111.25")
		{
			attenByte3 = "111000000";
		}
		// 95.25 db
		else if (atten3 == "95.25 (101111111)")
		{
			attenByte3 = "101111111";
		}
		//////////////////////////////////////////////////////////
		// Attenuator 4
		// 0 db
		if (atten4 == "0")
		{
			attenByte4 = "000000000";
		}
		// 0.25 db
		else if (atten4 == "0.25")
		{
			attenByte4 = "000000001";
		}
		// 0.5 db
		else if (atten4 == "0.5")
		{
			attenByte4 = "000000010";
		}
		// 1 db
		else if (atten4 == "1")
		{
			attenByte4 = "000000100";
		}
		// 2 db
		else if (atten4 == "2")
		{
			attenByte4 = "000001000";
		}
		// 4 db
		else if (atten4 == "4")
		{
			attenByte4 = "000010000";
		}
		// 8 db
		else if (atten4 == "8")
		{
			attenByte4 = "000100000";
		}
		// 16 db
		else if (atten4 == "16")
		{
			attenByte4 = "001000000";
		}
		// 31.75 db
		else if (atten4 == "31.75 (010000000)")
		{
			attenByte4 = "010000000";
		}
		// 63.5 db
		else if (atten4 == "63.5 (100000000)")
		{
			attenByte4 = "100000000";
		}
		// 31.75 db
		else if (atten4 == "31.75 (001111111)")
		{
			attenByte4 = "001111111";
		}
		// 63.5 db
		else if (atten4 == "63.5 (011111111)")
		{
			attenByte4 = "011111111";
		}
		// 127 db
		else if (atten4 == "127")
		{
			attenByte4 = "111111111";
		}
		// 95.25 db
		else if (atten4 == "95.25 (110000000)")
		{
			attenByte4 = "110000000";
		}
		// 111.25 db
		else if (atten4 == "111.25")
		{
			attenByte4 = "111000000";
		}
		// 95.25 db
		else if (atten4 == "95.25 (101111111)")
		{
			attenByte4 = "101111111";
		}
		//////////////////////////////////////////////////////////
		// Attenuator 5
		// 0 db
		if (atten5 == "0")
		{
			attenByte5 = "000000000";
		}
		// 0.25 db
		else if (atten5 == "0.25")
		{
			attenByte5 = "000000001";
		}
		// 0.5 db
		else if (atten5 == "0.5")
		{
			attenByte5 = "000000010";
		}
		// 1 db
		else if (atten5 == "1")
		{
			attenByte5 = "000000100";
		}
		// 2 db
		else if (atten5 == "2")
		{
			attenByte5 = "000001000";
		}
		// 4 db
		else if (atten5 == "4")
		{
			attenByte5 = "000010000";
		}
		// 8 db
		else if (atten5 == "8")
		{
			attenByte5 = "000100000";
		}
		// 16 db
		else if (atten5 == "16")
		{
			attenByte5 = "001000000";
		}
		// 31.75 db
		else if (atten5 == "31.75 (010000000)")
		{
			attenByte5 = "010000000";
		}
		// 63.5 db
		else if (atten5 == "63.5 (100000000)")
		{
			attenByte5 = "100000000";
		}
		// 31.75 db
		else if (atten5 == "31.75 (001111111)")
		{
			attenByte5 = "001111111";
		}
		// 63.5 db
		else if (atten5 == "63.5 (011111111)")
		{
			attenByte5 = "011111111";
		}
		// 127 db
		else if (atten5 == "127")
		{
			attenByte5 = "111111111";
		}
		// 95.25 db 
		else if (atten5 == "95.25 (110000000)")
		{
			attenByte5 = "110000000";
		}
		// 111.25 db
		else if (atten5 == "111.25")
		{
			attenByte5 = "111000000";
		}
		// 95.25 db
		else if (atten5 == "95.25 (101111111)")
		{
			attenByte5 = "101111111";
		}
		//////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Setting up the packet for the VLB drawer if the advanced check box is not checked
	//////////////////////////////////////////////////////////
	if (advanced == 0)
	{
		if (path == "VLB")
		{
			//////////////////////////////////////////////////////////
			// For loop to go through each case
			for (int i = 0; i < 16; i++)
			{
				//////////////////////////////////////////////////////////
				// PDW number (counter)
				if (count >= 4294967295)
				{
					count = 0;
				}
				else
				{
					pdwNum = intToBinary(count);
					while (pdwNum.length() < 32)
					{
						pdwNum = "0" + pdwNum;
					}
					count++;
				}
				////////////////////////////////////////////////////////////
				// RF ON, 20 - 35 MHz BPF
				if (i == 0)
				{

					if (initF <= 20 && endF >= 35)
					{
						swf1 = "0000";
						swf2 = "000";
						swf3 = "0000";
						initFREQ = "20";
						endFREQ = "35";
						alreadySent = false;
					}
				}
				// RF ON, 35 - 60 MHz BpF
				else if (i == 1)
				{

					if (initF <= 35 && endF >= 60)
					{
						swf1 = "0001";
						swf2 = "000";
						swf3 = "0001";
						initFREQ = "35";
						endFREQ = "60";
						alreadySent = false;
					}
				}
				// RF ON, 60 - 100 MHz BPF
				else if (i == 2)
				{
					if (initF <= 60 && endF >= 100)
					{
						swf1 = "0010";
						swf2 = "000";
						swf3 = "0010";
						initFREQ = "60";
						endFREQ = "100";
						alreadySent = false;
					}
				}
				// RF ON, 100 - 180 MHz BPF
				else if (i == 3)
				{
					if (initF <= 100 && endF >= 180)
					{
						swf1 = "0011";
						swf2 = "000";
						swf3 = "0011";

						initFREQ = "100";
						endFREQ = "180";
						alreadySent = false;
					}
				}
				// RF ON, 180 - 320 MHz BPF
				else if (i == 4)
				{
					if (initF <= 180 && endF >= 320)
					{
						swf1 = "0100";
						swf2 = "000";
						swf3 = "0100";

						initFREQ = "180";
						endFREQ = "320";
						alreadySent = false;
					}
				}
				// RF ON, 320 - 600 MHz BPF
				else if (i == 5)
				{
					if (initF <= 320 && endF >= 600)
					{
						swf1 = "0101";
						swf2 = "000";
						swf3 = "0101";

						initFREQ = "320";
						endFREQ = "600";
						alreadySent = false;
					}
				}
				// RF ON, 600 - 1100 MHz BPF
				else if (i == 6)
				{
					if (initF <= 600 && endF >= 1100)
					{
						swf1 = "0110";
						swf2 = "000";
						swf3 = "0110";

						initFREQ = "600";
						endFREQ = "1100";
						alreadySent = false;
					}
				}
				// RF ON, 1100 - 2000 MHz BPF
				else if (i == 7)
				{
					if (initF <= 1100 && endF >= 2000)
					{
						swf1 = "0111";
						swf2 = "000";
						swf3 = "0111";

						initFREQ = "1100";
						endFREQ = "2000";
						alreadySent = false;
					}
				}
				// RF ON, Ramp attenuation, 20 - 35 MHz BPF
				else if (i == 8)
				{
					if (attenByte == "111111111")
					{
						attenByte = "00000000";
					}
					decAtten = std::stoi(attenByte, 0, 2);
					decAtten++;
					attenByte = intToBinary(decAtten);
					while (attenByte.length() < 9)
					{
						attenByte = "0" + attenByte;
					}

					swf1 = "0000";
					swf2 = "000";
					swf3 = "0000";

					initFREQ = "20";
					endFREQ = "35";
					alreadySent = false;
				}
				// RF ON, Ramp attenuation, 180 - 320 MHz BPF
				else if (i == 9)
				{
					if (attenByte == "111111111")
					{
						attenByte = "00000000";
					}
					decAtten = std::stoi(attenByte, 0, 2);
					decAtten++;
					attenByte = intToBinary(decAtten);
					while (attenByte.length() < 9)
					{
						attenByte = "0" + attenByte;
					}

					swf1 = "0100";
					swf2 = "000";
					swf3 = "0100";

					initFREQ = "180";
					endFREQ = "320";
					alreadySent = false;
				}
				// RF ON, Ramp attenuation, 1100 - 2000 MHz BPF
				else if (i == 10)
				{
					if (attenByte == "111111111")
					{
						attenByte = "00000000";
					}
					decAtten = std::stoi(attenByte, 0, 2);
					decAtten++;
					attenByte = intToBinary(decAtten);
					while (attenByte.length() < 9)
					{
						attenByte = "0" + attenByte;
					}

					swf1 = "0111";
					swf2 = "000";
					swf3 = "0111";

					initFREQ = "1100";
					endFREQ = "2000";
					alreadySent = false;
				}
				// RF OFF, Ramp attenuation, 1100 - 2000 MHz BPF
				else if (i == 11)
				{
					// pin_sw = '1';
					if (attenByte == "111111111")
					{
						attenByte = "00000000";
					}
					decAtten = std::stoi(attenByte, 0, 2);
					decAtten++;
					attenByte = intToBinary(decAtten);
					while (attenByte.length() < 9)
					{
						attenByte = "0" + attenByte;
					}

					swf1 = "0111";
					swf2 = "000";
					swf3 = "0111";

					initFREQ = "1100";
					endFREQ = "2000";
					alreadySent = false;
				}
				// RF OFF, 127.75 dB attenuation, 4500 - 6000 MHz BPF
				else if (i == 12)
				{
					// pin_sw = '1';
					attenByte = "111111111";
					swf1 = "0111";
					swf2 = "000";
					swf3 = "0111";
					alreadySent = false;
				}
				// RF ON, 0 dB attenuation, 2000 - 3000 MHz BPF
				else if (i == 13)
				{
					attenByte = "000000000";
					swf1 = "0111";
					swf2 = "001";
					swf3 = "0111";
					alreadySent = false;
				}
				// RF ON, 0 dB attenuation, 3000 - 4500MHz BPF
				else if (i == 14)
				{
					attenByte = "000000000";
					swf1 = "0111";
					swf2 = "010";
					swf3 = "0111";
					alreadySent = false;
				}
				// RF ON, 0 dB attenuation, 4500 - 6000 MHz BPF
				else if (i == 15)
				{
					attenByte = "000000000";
					swf1 = "0111";
					swf2 = "011";
					swf3 = "0111";
					alreadySent = false;
				}
				//////////////////////////////////////////////////////////
				// Making sure not to send a single packet more than once
				if (alreadySent == false)
				{
					// Build packet
					packetBin = packet + attenByte + attenByte + attenByte + attenByte + attenByte + pdwNum + swf1 + swf2 + swf3 + "0000";
					packetHex = convertBinStrtoHexStr(packetBin);
					printf("packetHex : %s\n", packetHex.c_str());
					////////////////////////////////////////////////////////////
					// Send packet
					txbytes = sprintf_s(buffer, packetHex.c_str());
					if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Packet not sent: %d\n", WSAGetLastError());
						closesocket(attenSock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Passing along data to the packetSendMeas functions and checking to make sure the user frequency are
					// within the bounds of the function
					if (initF >= 20 && endF <= 6000)
					{
						//if (type == false)
						//{
						//	harmonicMeasK(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max background);
						//}
						//else
						//{
						//	harmonicMeasA(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max background);
						//}
					}
					else
					{
						puts("Frequency out of range (20 to 6000 MHz)");
						break;
					}
					//////////////////////////////////////////////////////////
					alreadySent = true;
				}
				//////////////////////////////////////////////////////////
			}
			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
		// Setting up the packet for the Main channels in the MB drawer if advanced is not checked
		//////////////////////////////////////////////////////////
		if (path == "MB Main")
		{
			//////////////////////////////////////////////////////////
			for (int i = 0; i < 8; i++)
			{
				//////////////////////////////////////////////////////////
				auxPacket = "010";
				//////////////////////////////////////////////////////////
				// PDW number (counter)
				if (count >= 4294967295)
				{
					count = 0;
				}
				else
				{
					pdwNum = intToBinary(count);
					while (pdwNum.length() < 32)
					{
						pdwNum = "0" + pdwNum;
					}
					count++;
				}
				//////////////////////////////////////////////////////////
				// 2 GHz to 3 GHz
				if (i == 0)
				{
					if (initF <= 2000 && endF >= 3000)
					{
						swf1 = "11110";
						swf3 = "000";
						rts = "00";

						initFREQ = "2";
						endFREQ = "3";
						alreadySent = false;
					}
				}
				// 3 GHz to 3.9 GHz
				else if (i == 1)
				{
					if (initF <= 3000 && endF >= 3900)
					{
						swf1 = "11110";
						swf3 = "001";
						rts = "00";

						initFREQ = "3";
						endFREQ = "3.9";
						alreadySent = false;
					}
				}
				// 3.9 GHz to 4.4 GHz
				else if (i == 2)
				{
					if (initF <= 3900 && endF >= 4400)
					{
						swf1 = "11101";
						swf3 = "001";
						rts = "00";

						initFREQ = "3.9";
						endFREQ = "4.4";
						alreadySent = false;
					}
				}
				// 4.4 GHz to 5.3 GHz
				else if (i == 3)
				{
					if (initF <= 4400 && endF >= 5300)
					{
						swf1 = "11101";
						swf3 = "010";
						rts = "00";

						initFREQ = "4.4";
						endFREQ = "5.3";
						alreadySent = false;
					}
				}
				// 5.3 GHz to 6 GHz
				else if (i == 4)
				{
					if (initF <= 5300 && endF >= 6000)
					{
						swf1 = "11011";
						swf3 = "010";
						rts = "00";

						initFREQ = "5.3";
						endFREQ = "6";
						alreadySent = false;
					}
				}
				// 6 GHz to 8 GHz 
				else if (i == 5)
				{
					if (initF <= 6000 && endF >= 8000)
					{
						swf1 = "11011";
						swf3 = "111";
						rts = "00";

						initFREQ = "6";
						endFREQ = "8";
						alreadySent = false;
					}
				}
				// 8 GHz to 10.7 GHz
				else if (i == 6)
				{
					if (initF <= 8000 && endF >= 10700)
					{
						swf1 = "10111";
						swf3 = "111";
						rts = "00";

						initFREQ = "8";
						endFREQ = "10.7";
						alreadySent = false;
					}
				}
				// 10.7 GHz to 18 GHz
				else if (i == 7)
				{
					if (initF <= 10700 && endF >= 18000)
					{
						swf1 = "01111";
						swf3 = "111";
						rts = "00";

						initFREQ = "10.7";
						endFREQ = "18";
						alreadySent = false;
					}
				}
				//////////////////////////////////////////////////////////
				// Making sure not to send a single packet more than once
				if (alreadySent == false)
				{
					// Build packet
					packetBin = packet + attenByte + attenByte + attenByte + attenByte + attenByte + pdwNum + swf1 + "000000" + rts + "00";
					auxPacket = auxPacket + attenByte + attenByte + attenByte + attenByte + attenByte + pdwNum + "00000000" + swf3 + rts + "00";
					packetHex = convertBinStrtoHexStr(packetBin);
					auxPacket = convertBinStrtoHexStr(auxPacket);
					printf("packetHex : %s\n", packetHex.c_str());
					printf("auxPacket : %s\n", auxPacket.c_str());
					////////////////////////////////////////////////////////////
					// Send packet
					txbytes = sprintf_s(buffer, packetHex.c_str());
					if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Packet not sent: %d\n", WSAGetLastError());
						closesocket(attenSock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Send MB Aux packet
					txbytes = sprintf_s(buffer, auxPacket.c_str());
					if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Aux Packet not sent: %d\n", WSAGetLastError());
						closesocket(attenSock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Making sure the user's input frequencies are within the bounds of the function
					if (initF >= 2000 && endF <= 18000)
					{
						if (type == false)
						{
							// rLev -50 for second harmonic
							// harmonicMeasK(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
						}
						else
						{
							// rLev -50 for second harmonic
							// harmonicMeasA(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
						}
					}
					else
					{
						puts("Frequency out of range (2 to 18 GHz)");
						break;
					}
					////////////////////////////////////////////////////////////
					alreadySent = true;
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
		// Setting up the packet for the Aux channels in the MB drawer if advanced is not checked
		//////////////////////////////////////////////////////////
		if (path == "MB AUX")
		{
			//////////////////////////////////////////////////////////
			for (int i = 0; i < 8; i++)
			{
				//////////////////////////////////////////////////////////
				auxPacket = "010";
				//////////////////////////////////////////////////////////
				// PDW number (counter)
				if (count >= 4294967295)
				{
					count = 0;
				}
				else
				{
					pdwNum = intToBinary(count);
					while (pdwNum.length() < 32)
					{
						pdwNum = "0" + pdwNum;
					}
					count++;
				}
				//////////////////////////////////////////////////////////
				// 2 GHz to 3 GHz
				if (i == 0)
				{
					if (initF <= 2000 && endF >= 3000)
					{
						swf3 = "000";
						rts = "00";

						initFREQ = "2";
						endFREQ = "3";
						alreadySent = false;
					}
				}
				// 3 GHz to 3.9 GHz
				else if (i == 1)
				{
					if (initF <= 3000 && endF >= 3900)
					{
						swf3 = "001";
						rts = "00";

						initFREQ = "3";
						endFREQ = "3.9";
						alreadySent = false;
					}
				}
				// 3.9 GHz to 4.4 GHz
				else if (i == 2)
				{
					if (initF <= 3900 && endF >= 4400)
					{
						swf3 = "001";
						rts = "00";

						initFREQ = "3.9";
						endFREQ = "4.4";
						alreadySent = false;
					}
				}
				// 4.4 GHz to 5.3 GHz
				else if (i == 3)
				{
					if (initF <= 4400 && endF >= 5300)
					{
						swf3 = "010";
						rts = "00";

						initFREQ = "4.4";
						endFREQ = "5.3";
						alreadySent = false;
					}
				}
				// 5.3 GHz to 6 GHz
				else if (i == 4)
				{
					if (initF <= 5300 && endF >= 6000)
					{
						swf3 = "010";
						rts = "00";

						initFREQ = "5.3";
						endFREQ = "6";
						alreadySent = false;
					}
				}
				// 6 GHz to 8 GHz
				else if (i == 5)
				{
					if (initF <= 6000 && endF >= 8000)
					{
						swf3 = "111";
						rts = "00";

						initFREQ = "6";
						endFREQ = "8";
						alreadySent = false;
					}
				}
				// 8 GHz to 10.7 GHz
				else if (i == 6)
				{
					if (initF <= 8000 && endF >= 10700)
					{
						swf3 = "111";
						rts = "00";

						initFREQ = "8";
						endFREQ = "10.7";
						alreadySent = false;
					}
				}
				// 10.7 GHz to 18 GHz
				else if (i == 7)
				{
					if (initF <= 10700 && endF >= 18000)
					{
						swf3 = "111";
						rts = "00";

						initFREQ = "10.7";
						endFREQ = "18";
						alreadySent = false;
					}
				}
				//////////////////////////////////////////////////////////
				// Making sure not to send a single packet more than once
				if (alreadySent == false)
				{
					// Build packet
					packetBin = packet + attenByte + attenByte + attenByte + attenByte + attenByte + pdwNum + "00000000" + swf3 + rts + "00";
					packetHex = convertBinStrtoHexStr(packetBin);
					printf("packetHex : %s\n", packetHex.c_str());
					////////////////////////////////////////////////////////////
					// Send packet
					txbytes = sprintf_s(buffer, packetHex.c_str());
					if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
					{
						printf("Packet not sent: %d\n", WSAGetLastError());
						closesocket(attenSock);
						WSACleanup();
					}
					////////////////////////////////////////////////////////////
					// Making sure the user's input frequencies are within bounds of the function
					if (initF >= 2000 && endF <= 18000)
					{
						if (type == false)
						{
							// rLev -50 for second harmonic
							// harmonicMeasK(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
						}
						else
						{
							// rLev -50 for second harmonic
							// harmonicMeasA(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
						}
					}
					else
					{
						puts("Frequency out of range (2 to 18 GHz)");
						break;
					}
					////////////////////////////////////////////////////////////
					alreadySent = true;
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
		// Setting up the packet for the HB drawer if advanced is not checked
		//////////////////////////////////////////////////////////
		if (path == "HB")
		{
			//////////////////////////////////////////////////////////
			// PDW number (counter)
			if (count >= 4294967295)
			{
				count = 0;
			}
			else
			{
				pdwNum = intToBinary(count);
				while (pdwNum.length() < 32)
				{
					pdwNum = "0" + pdwNum;
				}
				count++;
			}
			////////////////////////////////////////////////////////////
			// Build packet
			packetBin = packet + attenByte + attenByte + attenByte + attenByte + attenByte + pdwNum + "000000000000000";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			txbytes = sprintf_s(buffer, packetHex.c_str());
			if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Packet not sent: %d\n", WSAGetLastError());
				closesocket(attenSock);
				WSACleanup();
			}
			//////////////////////////////////////////////////////////
			// Making sure the user's input frequencies are within bounds of the function
			if (initF >= 20000 && endF <= 40000)
			{
				if (type == false)
				{
					// ethMeasureK(file, ipGPIB, sigGPIB, specGPIB, initPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, background);
				}
				else
				{
					// ethMeasureA(file, ipGPIB, sigGPIB, specGPIB, initPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, background);
				}
			}
			else
			{
				puts("Frequency out of range (20 to 40 GHz)");
			}
			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
	}
	//////////////////////////////////////////////////////////
	// Setting each attenuator to specific levels set by the user as long as advanced is checked
	//////////////////////////////////////////////////////////
	else if (advanced == 1)
	{
		if (path == "VLB")
		{
			//////////////////////////////////////////////////////////
			// PDW number (counter)
			if (count >= 4294967295)
			{
				count = 0;
			}
			else
			{
				pdwNum = intToBinary(count);
				while (pdwNum.length() < 32)
				{
					pdwNum = "0" + pdwNum;
				}
				count++;
			}
			////////////////////////////////////////////////////////////
			// Build packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + swf1 + swf2 + swf3 + "0000";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			txbytes = sprintf_s(buffer, packetHex.c_str());
			if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Packet not sent: %d\n", WSAGetLastError());
				closesocket(attenSock);
				WSACleanup();
			}
			//////////////////////////////////////////////////////////
			// Passing along data to the packetSendMeas functions and making sure the user's input frequencies are within
			// bounds of the function
			if (initF >= 20 && endF <= 6000)
			{
				//if (type == false)
				//{
				//	harmonicMeasK(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
				//}
				//else
				//{
				//	harmonicMeasA(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
				//}
			}
			else
			{
				puts("Frequency out of range (20 to 6000 MHz)");
			}
			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
		// For the MB Main path
		else if (path == "MB Main")
		{
			//////////////////////////////////////////////////////////
			auxPacket = "010";
			rts = "00";
			//////////////////////////////////////////////////////////
			// PDW number (counter)
			if (count >= 4294967295)
			{
				count = 0;
			}
			else
			{
				pdwNum = intToBinary(count);
				while (pdwNum.length() < 32)
				{
					pdwNum = "0" + pdwNum;
				}
				count++;
			}
			////////////////////////////////////////////////////////////
			// Build packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + swf1 + "000000" + rts + "00";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			txbytes = sprintf_s(buffer, packetHex.c_str());
			if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Packet not sent: %d\n", WSAGetLastError());
				closesocket(attenSock);
				WSACleanup();
			}
			//////////////////////////////////////////////////////////
			// Making sure the user's input frequencies are within bounds of the function
			if (initF >= 2000 && endF <= 18000)
			{
				if (type == false)
				{
					// rLev -50 for second harmonic
					// harmonicMeasK(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
				}
				else
				{
					// rLev -50 for second harmonic
					// harmonicMeasA(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
				}
			}
			else
			{
				puts("Frequency out of range (2 to 18 GHz)");
			}
			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
		// For the MB AUX path
		else if (path == "MB AUX")
		{
			//////////////////////////////////////////////////////////
			rts = "00";
			//////////////////////////////////////////////////////////
			// PDW number (counter)
			if (count >= 4294967295)
			{
				count = 0;
			}
			else
			{
				pdwNum = intToBinary(count);
				while (pdwNum.length() < 32)
				{
					pdwNum = "0" + pdwNum;
				}
				count++;
			}
			//////////////////////////////////////////////////////////
			// Build packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + "00000000" + swf3 + rts + "00";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			txbytes = sprintf_s(buffer, packetHex.c_str());
			if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Packet not sent: %d\n", WSAGetLastError());
				closesocket(attenSock);
				WSACleanup();
			}
			//////////////////////////////////////////////////////////
			// Making sure the user's input frequencies are within bounds of the function
			if (initF >= 2000 && endF <= 18000)
			{
				if (type == false)
				{
					// rLev -50 for second harmonic
					// harmonicMeasK(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
				}
				else
				{
					// rLev -50 for second harmonic
					// harmonicMeasA(file, ipGPIB, specGPIB, sigGPIB, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incF, max, background);
				}
			}
			else
			{
				puts("Frequency out of range (2 to 18 GHz)");
			}
			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
		// For the HB path
		else if (path == "HB")
		{
			//////////////////////////////////////////////////////////
			// PDW number (counter)
			if (count >= 4294967295)
			{
				count = 0;
			}
			else
			{
				pdwNum = intToBinary(count);
				while (pdwNum.length() < 32)
				{
					pdwNum = "0" + pdwNum;
				}
				count++;
			}
			//////////////////////////////////////////////////////////
			// Build packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + "000000000000000";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			txbytes = sprintf_s(buffer, packetHex.c_str());
			if (send(attenSock, buffer, (int)txbytes, 0) != txbytes)
			{
				printf("Packet not sent: %d\n", WSAGetLastError());
				closesocket(attenSock);
				WSACleanup();
			}
			//////////////////////////////////////////////////////////
			// Making sure the user's input frequencies are within bounds of the function
			if (initF >= 20000 && endF <= 40000)
			{
				if (type == false)
				{
					// ethMeasureK(file, ipGPIB, sigGPIB, specGPIB, initPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, background);
				}
				else
				{
					// ethMeasureA(file, ipGPIB, sigGPIB, specGPIB, initPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, background);
				}
			}
			else
			{
				puts("Frequency out of range (20 to 40 GHz)");
			}
			//////////////////////////////////////////////////////////
		}
		//////////////////////////////////////////////////////////
	}
	//////////////////////////////////////////////////////////
	closesocket(attenSock);
	WSACleanup();
}
#endif