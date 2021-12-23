#ifndef usbfunctions_h
#define usbfunctions_h
#include "Header.h"
#include "ComPort.h"

#define MODE_CMD "++mode 1\n"
#define AUTOTALK_CMD "++auto 1\n"
#define AUTOLISTEN_CMD "++auto 0\n"

void usbspecReset(DWORD written, DWORD error, char* port, const char* specGPIB)
{
	////////////////////////////////////////////////////////////
	// Intalizing buffer
	char buffer[256];
	////////////////////////////////////////////////////////////
	// Set auto listen
	written = 0;
	sprintf(buffer, AUTOLISTEN_CMD);
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x auto listen %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Specan)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(specGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x specan address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Set specan to reset
	written = 0;
	sprintf(buffer, "*RST\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RST %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
}

void usbSetupSpecan(DWORD written, DWORD error, char* port, const char* specGPIB, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string sweeps)
{
	// Reset specan
	usbspecReset(written, error, port, specGPIB);
	////////////////////////////////////////////////////////////
	// Intalizing buffer
	char buffer[256];
	////////////////////////////////////////////////////////////
	// Set auto listen
	written = 0;
	sprintf(buffer, AUTOLISTEN_CMD);
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x auto listen %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Specan)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(specGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x specan address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Setup SPECAN
	////////////////////////////////////////////////////////////
	// Write reference level to Specan
	std::string sRlev = ":DISP:TRAC:Y:SCAL:RLEV " + rLev + "\n";
	written = 0;
	sprintf(buffer, sRlev.c_str());
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x reference level %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write log scale 120 to Specan
	std::string sScal = ":DISP:TRAC:YSCAL " + scale + "\n";
	written = 0;
	sprintf(buffer, sScal.c_str());
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x scale %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Writing correct units to specan based on user input for span
	////////////////////////////////////////////////////////////
	if (unitsSpecSpan == 0)
	{
		////////////////////////////////////////////////////////////
		// Write span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "Hz\n";
		written = 0;
		sprintf(buffer, sSpan.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x span %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecSpan == 1)
	{
		////////////////////////////////////////////////////////////
		// Write span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "kHz\n";
		written = 0;
		sprintf(buffer, sSpan.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x span %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecSpan == 2)
	{
		////////////////////////////////////////////////////////////
		// Write span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "MHz\n";
		written = 0;
		sprintf(buffer, sSpan.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x span %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecSpan == 3)
	{
		////////////////////////////////////////////////////////////
		// Write span to Specan
		std::string sSpan = ":FREQ:SPAN " + span + "GHz\n";
		written = 0;
		sprintf(buffer, sSpan.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x span %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Writing correct units to specan based on user input for band
	////////////////////////////////////////////////////////////
	if (unitsSpecBand == 0)
	{
		////////////////////////////////////////////////////////////
		// Write resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "Hz\n";
		written = 0;
		sprintf(buffer, sBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecBand == 1)
	{
		////////////////////////////////////////////////////////////
		// Write resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "kHz\n";
		written = 0;
		sprintf(buffer, sBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecBand == 2)
	{
		////////////////////////////////////////////////////////////
		// Write resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "MHz\n";
		written = 0;
		sprintf(buffer, sBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecBand == 3)
	{
		////////////////////////////////////////////////////////////

		// Write resolution bandwidth to Specan
		std::string sBand = ":BAND " + band + "GHz\n";
		written = 0;
		sprintf(buffer, sBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Writing correct units to specan based on user input for video band
	////////////////////////////////////////////////////////////
	if (unitsSpecVidBand == 0)
	{
		// Write video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "Hz\n";
		written = 0;
		sprintf(buffer, sVidBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x video band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecVidBand == 1)
	{
		// Write video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "kHz\n";
		written = 0;
		sprintf(buffer, sVidBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x video band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecVidBand == 2)
	{
		// Write video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "MHz\n";
		written = 0;
		sprintf(buffer, sVidBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x video band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	else if (unitsSpecVidBand == 3)
	{
		////////////////////////////////////////////////////////////
		// Write video bandwidth to Specan
		std::string sVidBand = ":BAND:VID " + vidBand + "GHz\n";
		written = 0;
		sprintf(buffer, sVidBand.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x video band %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Write command to turn OFF single sweep to Specan
	written = 0;
	sprintf(buffer, ":INIT:CONT OFF\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x CONT %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write mode average to Specan
	if (!avgOFF)
	{
		written = 0;
		sprintf(buffer, ":DISP:WIND:TRAC:MODE AVER\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x average %s\n", error, port);
		}
	}
	////////////////////////////////////////////////////////////
	// Write number of sweeps for average to Specan
	std::string sSweeps = ":SENS:SWE:COUN " + sweeps + "\n";
	written = 0;
	sprintf(buffer, sSweeps.c_str());
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x sweeps %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
}

void usbFrequencySweepK(std::string file, DWORD written, DWORD error, char* port, double initF, double endF, double incF, const char* specGPIB, const char* sigGPIB, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// initializing variables
	char buffer[256];
	const DWORD TIMEOUT = 1500;     // Millisec
	//pause = false;
	double previousFreq = NULL;
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening a txt file
	std::ofstream myfile;
	////////////////////////////////////////////////////////////
	for (double freq = initF; freq <= endF; freq = freq + incF)
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
		//	}
		//	break;
		//case 1:
		//	if ((previousFreq != NULL && previousFreq < 2000 && freq >= 2000) || (previousFreq != NULL && previousFreq < 3100 && freq >= 3100)
		//		|| (previousFreq != NULL && previousFreq < 4000 && freq >= 4000) || (previousFreq != NULL && previousFreq < 4500 && freq >= 4500)
		//		|| (previousFreq != NULL && previousFreq < 5300 && freq >= 5300) || (previousFreq != NULL && previousFreq < 6100 && freq >= 6100)
		//		|| (previousFreq != NULL && previousFreq < 8000 && freq >= 8000) || (previousFreq != NULL && previousFreq < 10700 && freq >= 10700))
		//	{
		//		pause = true;
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
			// Setting siggen frequency, using the drift function to set speccan frequency, and opening the file to be appended to
			std::string sigFreq = std::to_string(freq);
			std::string specFreq = driftHB(freq);
			myfile.open(file, std::ios_base::app);
			////////////////////////////////////////////////////////////
			// Write auto listen
			written = 0;
			sprintf(buffer, AUTOLISTEN_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			written = 0;
			sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x siggen address %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Selecting correct units to send to siggen and specan based on user input
			////////////////////////////////////////////////////////////
			if (units == 0)
			{
				////////////////////////////////////////////////////////////
				// Write Frequency to Siggen
				printf("Frequency = %f kHz\n", freq);
				sigFreq = "FREQ " + sigFreq + "KHZ\n";
				written = 0;
				sprintf(buffer, sigFreq.c_str());
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x siggen frequency %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				written = 0;
				sprintf(buffer, "++addr %d\n", atoi(specGPIB));
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x auto listen %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Write center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "kHz\n";
				written = 0;
				sprintf(buffer, specFreq.c_str());
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x specan frequency %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
			}
			else if (units == 1)
			{
				////////////////////////////////////////////////////////////
				// Write Frequency to Siggen
				printf("Frequency = %f MHz\n", freq);
				sigFreq = "FREQ " + sigFreq + "MHZ\n";
				written = 0;
				sprintf(buffer, sigFreq.c_str());
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x siggen frequency %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				written = 0;
				sprintf(buffer, "++addr %d\n", atoi(specGPIB));
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x auto listen %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Write center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "MHz\n";
				written = 0;
				sprintf(buffer, specFreq.c_str());
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x specan frequency %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
			}
			else if (units == 2)
			{
				////////////////////////////////////////////////////////////
				// Write Frequency to Siggen
				printf("Frequency = %f GHz\n", freq);
				sigFreq = "FREQ " + sigFreq + "GHZ\n";
				written = 0;
				sprintf(buffer, sigFreq.c_str());
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x siggen frequency %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Specify address of instrument (Specan)
				written = 0;
				sprintf(buffer, "++addr %d\n", atoi(specGPIB));
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x auto listen %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Write center frequency to Specan
				specFreq = ":FREQ:CENT " + specFreq + "GHz\n";
				written = 0;
				sprintf(buffer, specFreq.c_str());
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x specan frequency %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
			// Report progress of frequency to update GUI on current measurement
			frequF = freq;
			background->ReportProgress(10);
			//////////////////////////////////////////////////////////////
			// Write trigger to Specan
			written = 0;
			sprintf(buffer, "*TRG\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x trigger %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			written = 0;
			sprintf(buffer, AUTOTALK_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto talk %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write operation complete query to Specan
			written = 0;
			sprintf(buffer, "*OPC?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x operation complete %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			////////////////////////////////////////////////////////////
			// Write event status register query to Specan 
			written = 0;
			sprintf(buffer, "*ESR?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x event status register %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			written = 0;
			sprintf(buffer, AUTOLISTEN_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write command to find the peak to Specan
			written = 0;
			sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x max peak %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write command to set the center frequency at the peak to Specan
			written = 0;
			sprintf(buffer, ":CALC:MARK:FUNC:CENT\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x center at marker %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			written = 0;
			sprintf(buffer, AUTOTALK_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto talk %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write peak calibration query to Specan based on frequency
			int ghz;
			if (units == 0) { ghz = 7000000; }
			else if (units == 1) { ghz = 7000; }
			else if (units == 2) { ghz = 7; }

			if (freq > ghz && ppeOFF == false)
			{
				written = 0;
				sprintf(buffer, ":CAL:PPE?\n");
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x calibration %s\n", error, port);
				}
				while (elapsedTime <= TIMEOUT)
				{
					DWORD bytesRead;

					error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
					if (error != 0)
					{
						printf("Error %08x reading %s.\n", error, port);
						break;
					}

					if (bytesRead > 0)
					{
						buffer[bytesRead] = 0;    // Append NULL to print to console
						lastRead = timeGetTime();
					}

					elapsedTime = timeGetTime() - lastRead;
				}
				////////////////////////////////////////////////////////////
				// Write operation complete query to Specan
				written = 0;
				sprintf(buffer, "*OPC?\n");
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x operation complete %s\n", error, port);
				}
				while (elapsedTime <= TIMEOUT)
				{
					DWORD bytesRead;

					error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
					if (error != 0)
					{
						printf("Error %08x reading %s.\n", error, port);
						break;
					}

					if (bytesRead > 0)
					{
						buffer[bytesRead] = 0;    // Append NULL to print to console
						lastRead = timeGetTime();
					}

					elapsedTime = timeGetTime() - lastRead;
				}
				////////////////////////////////////////////////////////////
				// Write event status register query to Specan 
				written = 0;
				sprintf(buffer, "*ESR?\n");
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x event status register %s\n", error, port);
				}
				while (elapsedTime <= TIMEOUT)
				{
					DWORD bytesRead;

					error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
					if (error != 0)
					{
						printf("Error %08x reading %s.\n", error, port);
						break;
					}

					if (bytesRead > 0)
					{
						buffer[bytesRead] = 0;    // Append NULL to print to console
						lastRead = timeGetTime();
					}

					elapsedTime = timeGetTime() - lastRead;
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto listen
				written = 0;
				sprintf(buffer, AUTOLISTEN_CMD);
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x auto listen %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Write trigger to Specan
				written = 0;
				sprintf(buffer, "*TRG\n");
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x trigger %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Set GPIB to auto talk
				written = 0;
				sprintf(buffer, AUTOTALK_CMD);
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x auto talk %s\n", error, port);
				}
				////////////////////////////////////////////////////////////
				// Write operation complete query to Specan
				written = 0;
				sprintf(buffer, "*OPC?\n");
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x operation complete %s\n", error, port);
				}
				while (elapsedTime <= TIMEOUT)
				{
					DWORD bytesRead;

					error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
					if (error != 0)
					{
						printf("Error %08x reading %s.\n", error, port);
						break;
					}

					if (bytesRead > 0)
					{
						buffer[bytesRead] = 0;    // Append NULL to print to console
						lastRead = timeGetTime();
					}

					elapsedTime = timeGetTime() - lastRead;
				}
				////////////////////////////////////////////////////////////
				// Write event status register query to Specan 
				written = 0;
				sprintf(buffer, "*ESR?\n");
				error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
				if (error != 0)
				{
					printf("Error %08x event status register %s\n", error, port);
				}
				while (elapsedTime <= TIMEOUT)
				{
					DWORD bytesRead;

					error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
					if (error != 0)
					{
						printf("Error %08x reading %s.\n", error, port);
						break;
					}

					if (bytesRead > 0)
					{
						buffer[bytesRead] = 0;    // Append NULL to print to console
						lastRead = timeGetTime();
					}

					elapsedTime = timeGetTime() - lastRead;
				}
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			written = 0;
			sprintf(buffer, AUTOLISTEN_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write command to find the peak to Specan
			written = 0;
			sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x max peak %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			written = 0;
			sprintf(buffer, AUTOTALK_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto talk %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write query to send back the marker placed on the peak's x coordinate (Frequency)
			written = 0;
			sprintf(buffer, ":CALC:MARK:X?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x mar x %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					std::string markX = buffer;
					std::string delim = "\n";
					markX = markX.substr(0, markX.find(delim));
					if (markX.empty()) {
						myfile.close();
						return;
					}
					// Outputing data
					printf("Mark X response: %s", buffer);
					myfile << markX;

					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			//////////////////////////////////////////////////////////
			// Write query to send back the marker placed on the peak's y coordinate (Amplitude)
			written = 0;
			sprintf(buffer, ":CALC:MARK:Y?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x mar x %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					printf("Mark Y response: %s", buffer);
					std::string markY = buffer;
					myfile << "," << markY;

					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
		//}
		previousFreq = freq;
		myfile.close();
	}
	////////////////////////////////////////////////////////////
	// Write RF Off to Siggen
	written = 0;
	sprintf(buffer, "OUTP OFF\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF OFF %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
}

void usbFrequencySweepA(std::string file, DWORD written, DWORD error, char* port, double initF, double endF, double incF, const char* specGPIB, const char* sigGPIB, System::ComponentModel::BackgroundWorker^ background)
{
	////////////////////////////////////////////////////////////
	// Intializing variables
	char buffer[256];
	const DWORD TIMEOUT = 1500;     // Millisec
	double previousFreq = NULL;
	//pause = false;
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening a txt file
	std::ofstream myfile;
	////////////////////////////////////////////////////////////
	for (double freq = initF; freq <= endF + 0.000001; freq = freq + incF)
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
		//	}
		//	break;
		//case 1:
		//	if ((previousFreq != NULL && previousFreq < 2000 && freq >= 2000) || (previousFreq != NULL && previousFreq < 3100 && freq >= 3100)
		//		|| (previousFreq != NULL && previousFreq < 4000 && freq >= 4000) || (previousFreq != NULL && previousFreq < 4500 && freq >= 4500)
		//		|| (previousFreq != NULL && previousFreq < 5300 && freq >= 5300) || (previousFreq != NULL && previousFreq < 6100 && freq >= 6100)
		//		|| (previousFreq != NULL && previousFreq < 8000 && freq >= 8000) || (previousFreq != NULL && previousFreq < 10700 && freq >= 10700))
		//	{
		//		pause = true;
		//	}
		//	break;
		//case 2:
		//	if ((previousFreq != NULL && previousFreq < 2 && freq >= 2) || (previousFreq != NULL && previousFreq < 3.1 && freq >= 3.1)
		//		|| (previousFreq != NULL && previousFreq < 4 && freq >= 4) || (previousFreq != NULL && previousFreq < 4.5 && freq >= 4.5)
		//		||(previousFreq != NULL && previousFreq < 5.3 && freq >= 5.3) || (previousFreq != NULL && previousFreq < 6.1 && freq >= 6.1)
		//		|| (previousFreq != NULL && previousFreq < 8 && freq >= 8) || (previousFreq != NULL && previousFreq < 10.7 && freq >= 10.7))
		//	{
		//		pause = true;
		//	}
		//	break;
		//}
		//if (!pause)
		//{
		////////////////////////////////////////////////////////////
		// Setting siggen frequency, using the drift function to set speccan frequency, and opening the file to be appended to
		std::string sigFreq = std::to_string(freq);
		std::string specFreq = driftHB(freq);
		myfile.open(file, std::ios_base::app);
		////////////////////////////////////////////////////////////
		// Write auto listen
		written = 0;
		sprintf(buffer, AUTOLISTEN_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto listen %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Specify address of instrument (Siggen)
		written = 0;
		sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x siggen address %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Selecting correct units to send to siggen and specan based on user input
		////////////////////////////////////////////////////////////
		if (units == 0)
		{
			////////////////////////////////////////////////////////////
			// Write Frequency to Siggen
			printf("Frequency = %f kHz\n", freq);
			sigFreq = "CF1 " + sigFreq + " KH\n";
			written = 0;
			sprintf(buffer, sigFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x siggen frequency %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Specan)
			written = 0;
			sprintf(buffer, "++addr %d\n", atoi(specGPIB));
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write center frequency to Specan
			specFreq = ":FREQ:CENT " + specFreq + "kHz\n";
			written = 0;
			sprintf(buffer, specFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x specan frequency %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
		}
		else if (units == 1)
		{
			////////////////////////////////////////////////////////////
			// Write Frequency to Siggen
			printf("Frequency = %f MHz\n", freq);
			sigFreq = "CF1 " + sigFreq + " MH\n";
			written = 0;
			sprintf(buffer, sigFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x siggen frequency %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Specan)
			written = 0;
			sprintf(buffer, "++addr %d\n", atoi(specGPIB));
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write center frequency to Specan
			specFreq = ":FREQ:CENT " + specFreq + "MHz\n";
			written = 0;
			sprintf(buffer, specFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x specan frequency %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
		}
		else if (units == 2)
		{
			////////////////////////////////////////////////////////////
			// Write Frequency to Siggen
			printf("Frequency = %f GHz\n", freq);
			sigFreq = "CF1 " + sigFreq + " GH\n";
			written = 0;
			sprintf(buffer, sigFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x siggen frequency %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Specan)
			written = 0;
			sprintf(buffer, "++addr %d\n", atoi(specGPIB));
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write center frequency to Specan
			specFreq = ":FREQ:CENT " + specFreq + "GHz\n";
			written = 0;
			sprintf(buffer, specFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x specan frequency %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
		}
		////////////////////////////////////////////////////////////
		// Report progress of frequency to update GUI on current measurement
		frequF = freq;
		background->ReportProgress(10);
		//////////////////////////////////////////////////////////////
		// Write trigger to Specan
		written = 0;
		sprintf(buffer, "*TRG\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x trigger %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Set GPIB to auto talk
		written = 0;
		sprintf(buffer, AUTOTALK_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto talk %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write operation complete query to Specan
		written = 0;
		sprintf(buffer, "*OPC?\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x operation complete %s\n", error, port);
		}
		while (elapsedTime <= TIMEOUT)
		{
			DWORD bytesRead;

			error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
			if (error != 0)
			{
				printf("Error %08x reading %s.\n", error, port);
				break;
			}

			if (bytesRead > 0)
			{
				buffer[bytesRead] = 0;    // Append NULL to print to console
				lastRead = timeGetTime();
			}

			elapsedTime = timeGetTime() - lastRead;
		}
		////////////////////////////////////////////////////////////
		// Write event status register query to Specan 
		written = 0;
		sprintf(buffer, "*ESR?\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x event status register %s\n", error, port);
		}
		while (elapsedTime <= TIMEOUT)
		{
			DWORD bytesRead;

			error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
			if (error != 0)
			{
				printf("Error %08x reading %s.\n", error, port);
				break;
			}

			if (bytesRead > 0)
			{
				buffer[bytesRead] = 0;    // Append NULL to print to console
				lastRead = timeGetTime();
			}

			elapsedTime = timeGetTime() - lastRead;
		}
		////////////////////////////////////////////////////////////
		// Set GPIB to auto listen
		written = 0;
		sprintf(buffer, AUTOLISTEN_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto listen %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write command to find the peak to Specan
		written = 0;
		sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x max peak %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write command to set the center frequency at the peak to Specan
		written = 0;
		sprintf(buffer, ":CALC:MARK:FUNC:CENT\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x center at marker %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Set GPIB to auto talk
		written = 0;
		sprintf(buffer, AUTOTALK_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto talk %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write peak calibration query to Specan based on frequency
		int ghz;
		if (units == 0) { ghz = 7000000; }
		else if (units == 1) { ghz = 7000; }
		else if (units == 2) { ghz = 7; }

		if (freq > ghz && ppeOFF == false)
			// if (freq > ghz)
		{
			written = 0;
			sprintf(buffer, ":CAL:PPE?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x calibration %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			////////////////////////////////////////////////////////////
			// Write operation complete query to Specan
			written = 0;
			sprintf(buffer, "*OPC?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x operation complete %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			////////////////////////////////////////////////////////////
			// Write event status register query to Specan 
			written = 0;
			sprintf(buffer, "*ESR?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x event status register %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto listen
			written = 0;
			sprintf(buffer, AUTOLISTEN_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write trigger to Specan
			written = 0;
			sprintf(buffer, "*TRG\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x trigger %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Set GPIB to auto talk
			written = 0;
			sprintf(buffer, AUTOTALK_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto talk %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Write operation complete query to Specan
			written = 0;
			sprintf(buffer, "*OPC?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x operation complete %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
			////////////////////////////////////////////////////////////
			// Write event status register query to Specan 
			written = 0;
			sprintf(buffer, "*ESR?\n");
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x event status register %s\n", error, port);
			}
			while (elapsedTime <= TIMEOUT)
			{
				DWORD bytesRead;

				error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
				if (error != 0)
				{
					printf("Error %08x reading %s.\n", error, port);
					break;
				}

				if (bytesRead > 0)
				{
					buffer[bytesRead] = 0;    // Append NULL to print to console
					lastRead = timeGetTime();
				}

				elapsedTime = timeGetTime() - lastRead;
			}
		}
		////////////////////////////////////////////////////////////
		// Set GPIB to auto listen
		written = 0;
		sprintf(buffer, AUTOLISTEN_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto listen %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write command to find the peak to Specan
		written = 0;
		sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x max peak %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Set GPIB to auto talk
		written = 0;
		sprintf(buffer, AUTOTALK_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto talk %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write query to send back the marker placed on the peak's x coordinate (Frequency)
		written = 0;
		sprintf(buffer, ":CALC:MARK:X?\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x mar x %s\n", error, port);
		}
		while (elapsedTime <= TIMEOUT)
		{
			DWORD bytesRead;

			error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
			if (error != 0)
			{
				printf("Error %08x reading %s.\n", error, port);
				break;
			}

			if (bytesRead > 0)
			{
				buffer[bytesRead] = 0;    // Append NULL to print to console
				std::string markX = buffer;
				std::string delim = "\n";
				markX = markX.substr(0, markX.find(delim));
				if (markX.empty()) {
					myfile.close();
					return;
				}
				// Outputing data
				printf("Mark X response: %s", buffer);
				myfile << markX;

				lastRead = timeGetTime();
			}

			elapsedTime = timeGetTime() - lastRead;
		}
		//////////////////////////////////////////////////////////
		// Write query to send back the marker placed on the peak's y coordinate (Amplitude)
		written = 0;
		sprintf(buffer, ":CALC:MARK:Y?\n");
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x mar x %s\n", error, port);
		}
		while (elapsedTime <= TIMEOUT)
		{
			DWORD bytesRead;

			error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
			if (error != 0)
			{
				printf("Error %08x reading %s.\n", error, port);
				break;
			}

			if (bytesRead > 0)
			{
				buffer[bytesRead] = 0;    // Append NULL to print to console
				printf("Mark Y response: %s", buffer);
				std::string markY = buffer;
				myfile << "," << markY;

				lastRead = timeGetTime();
			}

			elapsedTime = timeGetTime() - lastRead;
		}
		previousFreq = freq;
		myfile.close();
		}
	//}
	////////////////////////////////////////////////////////////
	// Write RF Off to Siggen
	written = 0;
	sprintf(buffer, "RF0\n");

	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF OFF %s\n", error, port);
	}
	////////////////////////////////////////////////////////////

}

void usbMeasureK(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string POW, std::string initFREQ, std::string endFREQ, std::string increment, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background) {
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
	// Initalizing and opening the txt file to clear previous data.
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	// Initializing variables
	char* port = "COM5";

	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opeing COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Function call to setup specan
	usbSetupSpecan(written, error, port, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x siggen address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write RF on to Siggen
	written = 0;
	sprintf(buffer, "OUTP ON\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF ON %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write power to Siggen
	std::string po = "POW " + POW + "DBM\n";
	written = 0;
	sprintf(buffer, po.c_str());
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x sweeps %s\n", error, port);
	}
	printf("Amplitude = %d dBm\n", P);
	////////////////////////////////////////////////////////////
	// Reporting progress to update GUI with current measurements
	ampF = P;
	background->ReportProgress(10);
	////////////////////////////////////////////////////////////
	// Increment sig gen frequency and take measurments from spec an with function call
	usbFrequencySweepK(file, written, error, port, initF, endF, inc, specGPIB, sigGPIB, background);
	////////////////////////////////////////////////////////////
	// Close COM port
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}

void usbMeasureA(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string POW, std::string initFREQ, std::string endFREQ, std::string increment, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background) {
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
	// Initalizing and opening the txt file to clear previous data.
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	// Intializing variables
	char* port = "COM5";

	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Function call to setup specan
	usbSetupSpecan(written, error, port, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x siggen address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write RF on to Siggen
	written = 0;
	sprintf(buffer, "RF1\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF ON %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write power to Siggen
	std::string po = "L1 " + POW + " DM\n";
	written = 0;
	sprintf(buffer, po.c_str());
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x sweeps %s\n", error, port);
	}
	printf("Amplitude = %d dBm\n", P);
	// Reporting progress to update GUI with current measurements
	ampF = P;
	background->ReportProgress(10);
	////////////////////////////////////////////////////////////
	// Increment sig gen frequency and take measurments from spec an with function call
	////////////////////////////////////////////////////////////
	usbFrequencySweepA(file, written, error, port, initF, endF, inc, specGPIB, sigGPIB, background);
	////////////////////////////////////////////////////////////
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}

void usbAmpFreqK(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, std::string incFREQ, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background)
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
	// Opening a txt file to clear previous input
	std::ofstream myfile;
	myfile.open(file);
	myfile.close();
	////////////////////////////////////////////////////////////
	// Intializing variables
	char* port = "COM5";

	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}

	////////////////////////////////////////////////////////////
	// Function call to setup specan
	usbSetupSpecan(written, error, port, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x siggen address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write Rf on to Specan
	written = 0;
	sprintf(buffer, "OUTP ON\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF ON %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Incrementing amplitude and frequency while taking measurements, then outputing said measurements 
	////////////////////////////////////////////////////////////
	// Set Pow and increment according to user input
	for (int pow = initP; pow <= endP; pow = pow + incP)
	{
		////////////////////////////////////////////////////////////
		// Set GPIB to auto listen
		written = 0;
		sprintf(buffer, AUTOLISTEN_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto listen %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Specify address of instrument (Siggen)
		written = 0;
		sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x siggen address %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "POW " + sPOW + "DBM\n";
		written = 0;
		sprintf(buffer, sPOW.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x power %s\n", error, port);
		}
		printf("Amplitude = %d dBm\n", pow);
		////////////////////////////////////////////////////////////
		// Reporting progress of the current measured amplitude to the GUI
		ampAF = pow;
		background->ReportProgress(10);
		////////////////////////////////////////////////////////////
		// Function call to sweep through frequencies specified by the user
		usbFrequencySweepK(file, written, error, port, initF, endF, incF, specGPIB, sigGPIB, background);
	}
	////////////////////////////////////////////////////////////
	// Closing COM port
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}

void usbAmpFreqA(std::string file, const char* ip, const char* sigGPIB, const char* specGPIB, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, std::string incFREQ, std::string rLev, std::string sweeps, std::string scale, std::string span, std::string band, std::string vidBand, System::ComponentModel::BackgroundWorker^ background)
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
	// Intializing variables
	char* port = "COM5";

	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Fumction call to setup specan
	usbSetupSpecan(written, error, port, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x siggen address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Write Rf on to Specan
	written = 0;
	sprintf(buffer, "RF1\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF ON %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Incrementing amplitude and frequency while taking measurements, then outputing said measurements 
	////////////////////////////////////////////////////////////
	// Set Pow and increment according to user input
	for (int pow = initP; pow <= endP; pow = pow + incP)
	{
		////////////////////////////////////////////////////////////
		// Set GPIB to auto listen
		written = 0;
		sprintf(buffer, AUTOLISTEN_CMD);
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x auto listen %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Specify address of instrument (Siggen)
		written = 0;
		sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x siggen address %s\n", error, port);
		}
		////////////////////////////////////////////////////////////
		// Write amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "OL" + sPOW + " DBM\n";
		written = 0;
		sprintf(buffer, sPOW.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x power %s\n", error, port);
		}
		printf("Amplitude = %d dBm\n", pow);
		////////////////////////////////////////////////////////////
		// Reporting progress of the current measured amplitude to the GUI
		ampAF = pow;
		background->ReportProgress(10);
		////////////////////////////////////////////////////////////
		// Increment siggen frequency and take measurments from specan through a function call
		usbFrequencySweepA(file, written, error, port, initF, endF, incF, specGPIB, sigGPIB, background);
	}
	////////////////////////////////////////////////////////////
	// Close COM port
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}

void usbharmonicMeasK(std::string file, const char* ip, const char* specGPIB, const char* sigGPIB, std::string sweeps, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, double incF, int max, System::ComponentModel::BackgroundWorker^ background)
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
		// Intializing variables
	char* port = "COM5";

	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	usbSetupSpecan(written, error, port, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	written = 0;
	sprintf(buffer, AUTOLISTEN_CMD);
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x auto listen %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x siggen address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Send Rf on to Specan
	written = 0;
	sprintf(buffer, "OUTP ON\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF ON %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Begin going through amplitudes and frequencies
	////////////////////////////////////////////////////////////
	for (int pow = initP; pow > endP; pow -= incP)
	{
		////////////////////////////////////////////////////////////
		// Send amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "POW " + sPOW + "DBM\n";
		written = 0;
		sprintf(buffer, sPOW.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x power %s\n", error, port);
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
			written = 0;
			sprintf(buffer, AUTOLISTEN_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			written = 0;
			sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x siggen address %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Send frequency to Siggen
			sigFreq = "FREQ " + sigFreq + " MHz\n";
			written = 0;
			sprintf(buffer, sigFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
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
					written = 0;
					sprintf(buffer, AUTOLISTEN_CMD);
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x auto listen %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Specify address of instrument (Specan)
					written = 0;
					sprintf(buffer, "++addr %d\n", atoi(specGPIB));
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x specan address %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Send center frequency to Specan
					specFreq = ":FREQ:CENT " + specFreq + " MHz\n";
					written = 0;
					sprintf(buffer, specFreq.c_str());
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x center frequency %s\n", error, port);
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
						written = 0;
						sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x max peak %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						// Enable "read-after-write" mode. 
						written = 0;
						sprintf(buffer, AUTOTALK_CMD);
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x auto talk %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						written = 0;
						sprintf(buffer, ":CAL:PPE?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x calibration %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Write operation complete query to Specan
						written = 0;
						sprintf(buffer, "*OPC?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x operation complete %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Write event status register query to Specan 
						written = 0;
						sprintf(buffer, "*ESR?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x event status register %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Set GPIB to auto listen
						written = 0;
						sprintf(buffer, AUTOLISTEN_CMD);
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x auto listen %s\n", error, port);
						}
						//////////////////////////////////////////////////////////////
						// Send trigger to Specan
						written = 0;
						sprintf(buffer, "*TRG\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x trigger %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						// Set GPIB to auto talk
						written = 0;
						sprintf(buffer, AUTOTALK_CMD);
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x auto talk %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						// Write operation complete query to Specan
						written = 0;
						sprintf(buffer, "*OPC?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x operation complete %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Write event status register query to Specan 
						written = 0;
						sprintf(buffer, "*ESR?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x event status register %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
					}
					////////////////////////////////////////////////////////////
					// Set GPIB to auto listen
					written = 0;
					sprintf(buffer, AUTOLISTEN_CMD);
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x auto listen %s\n", error, port);
					}
					//////////////////////////////////////////////////////////////
					// Send command to set a marker at the peak to Specan
					written = 0;
					sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x max peak %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Enable "read-after-write" mode. 
					written = 0;
					sprintf(buffer, AUTOTALK_CMD);
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x auto talk %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Write query to send back the marker placed on the peak's x coordinate (Frequency)
					written = 0;
					sprintf(buffer, ":CALC:MARK:X?\n");
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x mar x %s\n", error, port);
					}
					while (elapsedTime <= TIMEOUT)
					{
						DWORD bytesRead;

						error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
						if (error != 0)
						{
							printf("Error %08x reading %s.\n", error, port);
							break;
						}

						if (bytesRead > 0)
						{
							buffer[bytesRead] = 0;    // Append NULL to print to console
							std::string markX = buffer;
							std::string delim = "\n";
							markX = markX.substr(0, markX.find(delim));
							if (markX.empty()) {
								myfile.close();
								return;
							}
							// Outputing data
							printf("Mark X response: %s", buffer);
							myfile << markX;

							lastRead = timeGetTime();
						}

						elapsedTime = timeGetTime() - lastRead;
					}
					//////////////////////////////////////////////////////////
					// Write query to send back the marker placed on the peak's y coordinate (Amplitude)
					written = 0;
					sprintf(buffer, ":CALC:MARK:Y?\n");
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x mar x %s\n", error, port);
					}
					while (elapsedTime <= TIMEOUT)
					{
						DWORD bytesRead;

						error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
						if (error != 0)
						{
							printf("Error %08x reading %s.\n", error, port);
							break;
						}

						if (bytesRead > 0)
						{
							buffer[bytesRead] = 0;    // Append NULL to print to console
							printf("Mark Y response: %s", buffer);
							std::string markY = buffer;
							myfile << "," << markY;

							lastRead = timeGetTime();
						}

						elapsedTime = timeGetTime() - lastRead;
					}
					////////////////////////////////////////////////////////////
					myfile.close();
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Close COM port
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}

void usbharmonicMeasA(std::string file, const char* ip, const char* specGPIB, const char* sigGPIB, std::string sweeps, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, double incF, int max, System::ComponentModel::BackgroundWorker^ background)
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
	// Intializing variables
	char* port = "COM5";

	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	usbSetupSpecan(written, error, port, specGPIB, rLev, scale, span, band, vidBand, sweeps);
	////////////////////////////////////////////////////////////
	written = 0;
	sprintf(buffer, AUTOLISTEN_CMD);
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x auto listen %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Specify address of instrument (Siggen)
	written = 0;
	sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x siggen address %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Send Rf on to Specan
	written = 0;
	sprintf(buffer, "RF1\n");
	error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
	if (error != 0)
	{
		printf("Error %08x RF ON %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Begin going through amplitudes and frequencies
	////////////////////////////////////////////////////////////
	for (int pow = initP; pow > endP; pow -= incP)
	{
		////////////////////////////////////////////////////////////
		// Send amplitude to Siggen
		std::string sPOW = std::to_string(pow);
		sPOW = "L1 " + sPOW + "DBM\n";
		written = 0;
		sprintf(buffer, sPOW.c_str());
		error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
		if (error != 0)
		{
			printf("Error %08x power %s\n", error, port);
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
			written = 0;
			sprintf(buffer, AUTOLISTEN_CMD);
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Specify address of instrument (Siggen)
			written = 0;
			sprintf(buffer, "++addr %d\n", atoi(sigGPIB));
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x siggen address %s\n", error, port);
			}
			////////////////////////////////////////////////////////////
			// Send frequency to Siggen
			sigFreq = "CF1 " + sigFreq + " MH\n";
			written = 0;
			sprintf(buffer, sigFreq.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x auto listen %s\n", error, port);
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
					written = 0;
					sprintf(buffer, AUTOLISTEN_CMD);
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x auto listen %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Specify address of instrument (Specan)
					written = 0;
					sprintf(buffer, "++addr %d\n", atoi(specGPIB));
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x specan address %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Send center frequency to Specan
					specFreq = ":FREQ:CENT " + specFreq + " MHz\n";
					written = 0;
					sprintf(buffer, specFreq.c_str());
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x center frequency %s\n", error, port);
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
						written = 0;
						sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x max peak %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						// Enable "read-after-write" mode. 
						written = 0;
						sprintf(buffer, AUTOTALK_CMD);
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x auto talk %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						written = 0;
						sprintf(buffer, ":CAL:PPE?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x calibration %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Write operation complete query to Specan
						written = 0;
						sprintf(buffer, "*OPC?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x operation complete %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Write event status register query to Specan 
						written = 0;
						sprintf(buffer, "*ESR?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x event status register %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Set GPIB to auto listen
						written = 0;
						sprintf(buffer, AUTOLISTEN_CMD);
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x auto listen %s\n", error, port);
						}
						//////////////////////////////////////////////////////////////
						// Send trigger to Specan
						written = 0;
						sprintf(buffer, "*TRG\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x trigger %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						// Set GPIB to auto talk
						written = 0;
						sprintf(buffer, AUTOTALK_CMD);
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x auto talk %s\n", error, port);
						}
						////////////////////////////////////////////////////////////
						// Write operation complete query to Specan
						written = 0;
						sprintf(buffer, "*OPC?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x operation complete %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
						////////////////////////////////////////////////////////////
						// Write event status register query to Specan 
						written = 0;
						sprintf(buffer, "*ESR?\n");
						error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
						if (error != 0)
						{
							printf("Error %08x event status register %s\n", error, port);
						}
						while (elapsedTime <= TIMEOUT)
						{
							DWORD bytesRead;

							error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
							if (error != 0)
							{
								printf("Error %08x reading %s.\n", error, port);
								break;
							}

							if (bytesRead > 0)
							{
								buffer[bytesRead] = 0;    // Append NULL to print to console
								lastRead = timeGetTime();
							}

							elapsedTime = timeGetTime() - lastRead;
						}
					}
					////////////////////////////////////////////////////////////
					// Set GPIB to auto listen
					written = 0;
					sprintf(buffer, AUTOLISTEN_CMD);
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x auto listen %s\n", error, port);
					}
					//////////////////////////////////////////////////////////////
					// Send command to set a marker at the peak to Specan
					written = 0;
					sprintf(buffer, ":CALC:MARK:MAX:PEAK\n");
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x max peak %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Enable "read-after-write" mode. 
					written = 0;
					sprintf(buffer, AUTOTALK_CMD);
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x auto talk %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Write query to send back the marker placed on the peak's x coordinate (Frequency)
					written = 0;
					sprintf(buffer, ":CALC:MARK:X?\n");
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x mar x %s\n", error, port);
					}
					while (elapsedTime <= TIMEOUT)
					{
						DWORD bytesRead;

						error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
						if (error != 0)
						{
							printf("Error %08x reading %s.\n", error, port);
							break;
						}

						if (bytesRead > 0)
						{
							buffer[bytesRead] = 0;    // Append NULL to print to console
							std::string markX = buffer;
							std::string delim = "\n";
							markX = markX.substr(0, markX.find(delim));
							if (markX.empty()) {
								myfile.close();
								return;
							}
							// Outputing data
							printf("Mark X response: %s", buffer);
							myfile << markX;

							lastRead = timeGetTime();
						}

						elapsedTime = timeGetTime() - lastRead;
					}
					//////////////////////////////////////////////////////////
					// Write query to send back the marker placed on the peak's y coordinate (Amplitude)
					written = 0;
					sprintf(buffer, ":CALC:MARK:Y?\n");
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x mar x %s\n", error, port);
					}
					while (elapsedTime <= TIMEOUT)
					{
						DWORD bytesRead;

						error = PxSerialRead(buffer, sizeof(buffer) - 1, &bytesRead);
						if (error != 0)
						{
							printf("Error %08x reading %s.\n", error, port);
							break;
						}

						if (bytesRead > 0)
						{
							buffer[bytesRead] = 0;    // Append NULL to print to console
							printf("Mark Y response: %s", buffer);
							std::string markY = buffer;
							myfile << "," << markY;

							lastRead = timeGetTime();
						}

						elapsedTime = timeGetTime() - lastRead;
					}
					////////////////////////////////////////////////////////////
					myfile.close();
				}
				////////////////////////////////////////////////////////////
			}
			////////////////////////////////////////////////////////////
		}
		////////////////////////////////////////////////////////////
	}
	////////////////////////////////////////////////////////////
	// Close COM port
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}

void usbmaxPowerSweep(std::string file, const char* ip, const char* ipGPIB, const char* sigGPIB, const char* specGPIB, std::string sweeps, std::string rLev, std::string scale, std::string span, std::string band, std::string vidBand, std::string initPOW, std::string endPOW, std::string incPOW, std::string initFREQ, std::string endFREQ, std::string incFREQ, std::string path, std::string atten, std::string atten2, std::string atten3, std::string atten4, std::string atten5, std::string swf1, std::string swf2, std::string swf3, System::ComponentModel::BackgroundWorker^ background, bool type)
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
	bool alreadySent = false;
	//////////////////////////////////////////////////////////
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
	// Intializing variables
	char* port = "COM5";
	char cmd[253];
	char buffer[256];
	std::string cmdS;
	DWORD error = 0;
	DWORD written = 0;
	const DWORD TIMEOUT = 1500;     // Millisec
	DWORD elapsedTime = 0;
	DWORD lastRead = timeGetTime();
	////////////////////////////////////////////////////////////
	// Opening COM port
	error = PxSerialOpen(port);
	if (error != 0)
	{
		printf("Error %08x opening %s\n", error, port);
	}
	////////////////////////////////////////////////////////////
	// Creating the packet
	////////////////////////////////////////////////////////////
	// Selecting the path and setting max measurement frequency in MHz for each path for the harmonics
	if (path == "VLB")
	{
		packet = "000";
		max = 2000;
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
					written = 0;
					sprintf(buffer, packetHex.c_str());
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x hex packet %s\n", error, port);
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
					alreadySent = true;
					//////////////////////////////////////////////////////////
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
			// For loop to go through each frequency range
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
					written = 0;
					sprintf(buffer, packetHex.c_str());
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x hex packet %s\n", error, port);
					}
					////////////////////////////////////////////////////////////
					// Send MB Aux packet
					written = 0;
					sprintf(buffer, auxPacket.c_str());
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x aux packet %s\n", error, port);
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
					//////////////////////////////////////////////////////////
					alreadySent = true;
				}
				//////////////////////////////////////////////////////////
			}
			//////////////////////////////////////////////////////////
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
					written = 0;
					sprintf(buffer, packetHex.c_str());
					error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
					if (error != 0)
					{
						printf("Error %08x hex packet %s\n", error, port);
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
					//////////////////////////////////////////////////////////
					alreadySent = true;
				}
				//////////////////////////////////////////////////////////
			}
			//////////////////////////////////////////////////////////
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
			written = 0;
			sprintf(buffer, packetHex.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x hex packet %s\n", error, port);
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
		//////////////////////////////////////////////////////////
		// For the VLB path
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
			//////////////////////////////////////////////////////////
			// Build packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + swf1 + swf2 + swf3 + "0000";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			written = 0;
			sprintf(buffer, packetHex.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x hex packet %s\n", error, port);
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
			//////////////////////////////////////////////////////////
			// Creating the packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + swf1 + "000000" + rts + "00";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			written = 0;
			sprintf(buffer, packetHex.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x hex packet %s\n", error, port);
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
			written = 0;
			sprintf(buffer, packetHex.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x hex packet %s\n", error, port);
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
			// Build Packet
			packetBin = packet + attenByte + attenByte2 + attenByte3 + attenByte4 + attenByte5 + pdwNum + "000000000000000";
			packetHex = convertBinStrtoHexStr(packetBin);
			printf("packetHex : %s\n", packetHex.c_str());
			////////////////////////////////////////////////////////////
			// Send packet
			written = 0;
			sprintf(buffer, packetHex.c_str());
			error = PxSerialWrite(buffer, (DWORD)strlen(buffer), &written);
			if (error != 0)
			{
				printf("Error %08x hex packet %s\n", error, port);
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
	}
	//////////////////////////////////////////////////////////
	// Close COM port
	error = PxSerialClose();
	if (error != 0)
	{
		printf("Error %08x closing %s.\n", error, port);
	}
}
#endif