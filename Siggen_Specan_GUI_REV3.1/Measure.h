#pragma once
#include "Header.h"
#include "ethFunctions.h"
#include "usbFunctions.h"

int ampF;
double frequF;
int ampAF;
int units = 0;
int unitsInc = 0;
int unitsSpecSpan = 0;
int unitsSpecBand = 0;
int unitsSpecVidBand = 0;
int eth = 2;
int eth2 = 2;
int advanced = 0;
bool ppeOFF = false;
bool avgOFF = false;
//bool pause = false;
std::string inc;
std::string incFREQ;
std::string stdPath;
std::string stdAtten;
std::string stdAtten2;
std::string stdAtten3;
std::string stdAtten4;
std::string stdAtten5;

namespace SiggenSpecanGUI31 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;


	/// <summary>
	/// Summary for Measure
	/// </summary>
	public ref class Measure : public System::Windows::Forms::Form
	{

	public:
		Measure(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Measure()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:






	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;












	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;



	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;



	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;



	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;


	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::Label^  label34;


	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label36;
	private: System::Windows::Forms::Label^  label37;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker3;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker4;

	private: System::Windows::Forms::Label^  label39;
	private: System::Windows::Forms::Label^  label40;
	private: System::Windows::Forms::Label^  label41;
	private: System::Windows::Forms::Label^  label42;
	private: System::Windows::Forms::Label^  label43;
	private: System::Windows::Forms::Label^  label44;
	private: System::Windows::Forms::Label^  label45;
	private: System::Windows::Forms::Label^  label46;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::ComboBox^  comboBox9;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;




	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label21;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  comboBox10;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::Label^  label47;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Label^  label28;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::ComboBox^  comboBox16;
	private: System::Windows::Forms::Label^  label48;
	private: System::Windows::Forms::Label^  label49;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::ComboBox^  comboBox15;
	private: System::Windows::Forms::ComboBox^  comboBox14;
	private: System::Windows::Forms::ComboBox^  comboBox13;
	private: System::Windows::Forms::ComboBox^  comboBox12;

	private: System::Windows::Forms::Label^  label63;
	private: System::Windows::Forms::Label^  label64;
	private: System::Windows::Forms::ComboBox^  comboBox21;
	private: System::Windows::Forms::ComboBox^  comboBox17;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::Label^  label55;
	private: System::Windows::Forms::TextBox^  textBox29;

	private: System::Windows::Forms::ComboBox^  comboBox18;
	private: System::Windows::Forms::Label^  label56;
	private: System::Windows::Forms::TextBox^  textBox31;


	private: System::Windows::Forms::Label^  label57;
	private: System::Windows::Forms::TextBox^  textBox33;


	private: System::Windows::Forms::Label^  label59;

	private: System::Windows::Forms::Label^  label61;
	private: System::Windows::Forms::Label^  label62;
	private: System::Windows::Forms::Label^  label51;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::Label^  label52;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::Label^  label53;
	private: System::Windows::Forms::Label^  label54;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::Label^  label50;
	private: System::Windows::Forms::Label^  label66;
	private: System::Windows::Forms::Label^  label65;
	private: System::Windows::Forms::Label^  label60;
	private: System::Windows::Forms::TextBox^  textBox35;
	private: System::Windows::Forms::TextBox^  textBox34;
	private: System::Windows::Forms::TextBox^  textBox32;
	private: System::Windows::Forms::TextBox^  textBox30;
	private: System::Windows::Forms::Label^  label58;
	private: System::Windows::Forms::TextBox^  textBox36;
	private: System::Windows::Forms::Label^  label70;
	private: System::Windows::Forms::ComboBox^  comboBox22;
	private: System::Windows::Forms::ComboBox^  comboBox20;
	private: System::Windows::Forms::ComboBox^  comboBox19;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label14;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker5;
	private: System::Windows::Forms::ComboBox^  comboBox23;
	private: System::Windows::Forms::ComboBox^  comboBox24;
	private: System::Windows::Forms::ComboBox^  comboBox25;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label35;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox37;
	private: System::Windows::Forms::Label^  label38;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label67;
	private: System::Windows::Forms::Label^  label68;
	private: System::Windows::Forms::Label^  label69;
	private: System::Windows::Forms::Label^  label71;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker6;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::CheckBox^  checkBox4;
	private: System::Windows::Forms::CheckBox^  checkBox3;
	private: System::Windows::Forms::Label^  label72;
	private: System::Windows::Forms::TextBox^  textBox38;
	private: System::Windows::Forms::Label^  label73;
	private: System::Windows::Forms::ComboBox^  comboBox26;
	private: System::Windows::Forms::Label^  label74;
	private: System::Windows::Forms::ComboBox^  comboBox27;
	private: System::Windows::Forms::TextBox^  textBox39;
	private: System::Windows::Forms::TextBox^  textBox40;
	private: System::Windows::Forms::CheckBox^  checkBox5;
	private: System::Windows::Forms::CheckBox^  checkBox6;

	private: System::ComponentModel::BackgroundWorker^  backgroundWorker7;
private: System::Windows::Forms::CheckBox^  checkBox7;



























	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker3 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker4 = (gcnew System::ComponentModel::BackgroundWorker());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox22 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox20 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox19 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox36 = (gcnew System::Windows::Forms::TextBox());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->textBox35 = (gcnew System::Windows::Forms::TextBox());
			this->textBox34 = (gcnew System::Windows::Forms::TextBox());
			this->textBox32 = (gcnew System::Windows::Forms::TextBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->label73 = (gcnew System::Windows::Forms::Label());
			this->comboBox26 = (gcnew System::Windows::Forms::ComboBox());
			this->label74 = (gcnew System::Windows::Forms::Label());
			this->comboBox27 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox39 = (gcnew System::Windows::Forms::TextBox());
			this->textBox40 = (gcnew System::Windows::Forms::TextBox());
			this->label72 = (gcnew System::Windows::Forms::Label());
			this->textBox38 = (gcnew System::Windows::Forms::TextBox());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->label71 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox23 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox24 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox25 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox37 = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->comboBox21 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox17 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox18 = (gcnew System::Windows::Forms::ComboBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->textBox33 = (gcnew System::Windows::Forms::TextBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->comboBox15 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox14 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox13 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox12 = (gcnew System::Windows::Forms::ComboBox());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->comboBox16 = (gcnew System::Windows::Forms::ComboBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBox10 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker5 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker6 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker7 = (gcnew System::ComponentModel::BackgroundWorker());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(182, 141);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"192.168.2.136";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(33, 141);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 15);
			this->label1->TabIndex = 7;
			this->label1->Text = L"IP of GPIB";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(33, 167);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 15);
			this->label2->TabIndex = 8;
			this->label2->Text = L"SigGen Address";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(33, 195);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 15);
			this->label3->TabIndex = 9;
			this->label3->Text = L"SpecAn Address";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(14, 347);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 15);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Amplitude";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(14, 373);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(95, 15);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Start Frequency";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(14, 399);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(87, 15);
			this->label6->TabIndex = 12;
			this->label6->Text = L"End Frequency";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(87, 300);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(102, 24);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Frequency";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(411, 300);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(237, 24);
			this->label9->TabIndex = 29;
			this->label9->Text = L"Amplitude and Frequency";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(362, 446);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(87, 15);
			this->label11->TabIndex = 27;
			this->label11->Text = L"End Frequency";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(362, 420);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(95, 15);
			this->label12->TabIndex = 26;
			this->label12->Text = L"Start Frequency";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(362, 342);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(93, 15);
			this->label13->TabIndex = 25;
			this->label13->Text = L"Start Amplitude";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(362, 368);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(85, 15);
			this->label17->TabIndex = 33;
			this->label17->Text = L"End Amplitude";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(362, 394);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(122, 15);
			this->label18->TabIndex = 34;
			this->label18->Text = L"Amplitude Increment";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(151, 521);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 26);
			this->button1->TabIndex = 35;
			this->button1->Text = L"Start";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Measure::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(151, 553);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 26);
			this->button2->TabIndex = 36;
			this->button2->Text = L"Stop";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Measure::button2_Click);
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(83, 540);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(62, 19);
			this->label19->TabIndex = 37;
			this->label19->Text = L"Waiting";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label20->Location = System::Drawing::Point(269, 347);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(31, 15);
			this->label20->TabIndex = 38;
			this->label20->Text = L"dBm";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label24->Location = System::Drawing::Point(617, 344);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(31, 15);
			this->label24->TabIndex = 42;
			this->label24->Text = L"dBm";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(617, 370);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(31, 15);
			this->label25->TabIndex = 43;
			this->label25->Text = L"dBm";
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(617, 394);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(31, 15);
			this->label26->TabIndex = 44;
			this->label26->Text = L"dBm";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(182, 167);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 48;
			this->textBox2->Text = L"19";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(182, 193);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 49;
			this->textBox3->Text = L"20";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(163, 345);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 50;
			this->textBox4->Text = L"0";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(163, 371);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 51;
			this->textBox5->Text = L"20000000";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(163, 397);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 52;
			this->textBox6->Text = L"40000000";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(163, 423);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 53;
			this->textBox7->Text = L"100000";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(511, 340);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 57;
			this->textBox8->Text = L"-10";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(511, 366);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 58;
			this->textBox9->Text = L"0";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox10
			// 
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(511, 392);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 59;
			this->textBox10->Text = L"1";
			this->textBox10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox11
			// 
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox11->Location = System::Drawing::Point(511, 418);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 60;
			this->textBox11->Text = L"20000000";
			this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox15
			// 
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(511, 444);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(100, 20);
			this->textBox15->TabIndex = 61;
			this->textBox15->Text = L"40000000";
			this->textBox15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox16
			// 
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox16->Location = System::Drawing::Point(511, 470);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(100, 20);
			this->textBox16->TabIndex = 62;
			this->textBox16->Text = L"100000";
			this->textBox16->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label30->Location = System::Drawing::Point(453, 540);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(62, 19);
			this->label30->TabIndex = 65;
			this->label30->Text = L"Waiting";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(521, 553);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 26);
			this->button3->TabIndex = 64;
			this->button3->Text = L"Stop";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Measure::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(521, 521);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 26);
			this->button4->TabIndex = 63;
			this->button4->Text = L"Start";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Measure::button4_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker1_RunWorkerCompleted);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker2_DoWork);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker2_ProgressChanged);
			this->backgroundWorker2->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker2_RunWorkerCompleted);
			// 
			// textBox17
			// 
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(182, 219);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(100, 20);
			this->textBox17->TabIndex = 66;
			this->textBox17->Text = L"0";
			this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label31->Location = System::Drawing::Point(33, 221);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(95, 15);
			this->label31->TabIndex = 67;
			this->label31->Text = L"Reference Level";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label32->Location = System::Drawing::Point(288, 221);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(31, 15);
			this->label32->TabIndex = 68;
			this->label32->Text = L"dBm";
			// 
			// textBox19
			// 
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox19->Location = System::Drawing::Point(182, 245);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(100, 20);
			this->textBox19->TabIndex = 71;
			this->textBox19->Text = L"5";
			this->textBox19->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label34->Location = System::Drawing::Point(33, 249);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(47, 15);
			this->label34->TabIndex = 72;
			this->label34->Text = L"Sweeps";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Keysight", L"Anritsu" });
			this->comboBox1->Location = System::Drawing::Point(151, 20);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(112, 21);
			this->comboBox1->TabIndex = 75;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox1_SelectedIndexChanged);
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label36->Location = System::Drawing::Point(6, 22);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(139, 15);
			this->label36->TabIndex = 76;
			this->label36->Text = L"Select Signal Generator";
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label37->Location = System::Drawing::Point(156, 43);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(0, 15);
			this->label37->TabIndex = 77;
			// 
			// backgroundWorker3
			// 
			this->backgroundWorker3->WorkerReportsProgress = true;
			this->backgroundWorker3->WorkerSupportsCancellation = true;
			this->backgroundWorker3->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker3_DoWork);
			this->backgroundWorker3->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker3_ProgressChanged);
			this->backgroundWorker3->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker3_RunWorkerCompleted);
			// 
			// backgroundWorker4
			// 
			this->backgroundWorker4->WorkerReportsProgress = true;
			this->backgroundWorker4->WorkerSupportsCancellation = true;
			this->backgroundWorker4->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker4_DoWork);
			this->backgroundWorker4->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker4_ProgressChanged);
			this->backgroundWorker4->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker4_RunWorkerCompleted);
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label39->Location = System::Drawing::Point(87, 587);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(88, 19);
			this->label39->TabIndex = 79;
			this->label39->Text = L"Amplitude: ";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label40->Location = System::Drawing::Point(87, 615);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(89, 19);
			this->label40->TabIndex = 80;
			this->label40->Text = L"Frequency: ";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label41->Location = System::Drawing::Point(194, 587);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(17, 19);
			this->label41->TabIndex = 81;
			this->label41->Text = L"0";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label42->Location = System::Drawing::Point(194, 615);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(17, 19);
			this->label42->TabIndex = 82;
			this->label42->Text = L"0";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label43->Location = System::Drawing::Point(564, 615);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(17, 19);
			this->label43->TabIndex = 86;
			this->label43->Text = L"0";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label44->Location = System::Drawing::Point(564, 587);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(17, 19);
			this->label44->TabIndex = 85;
			this->label44->Text = L"0";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label45->Location = System::Drawing::Point(457, 615);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(89, 19);
			this->label45->TabIndex = 84;
			this->label45->Text = L"Frequency: ";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label46->Location = System::Drawing::Point(457, 587);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(88, 19);
			this->label46->TabIndex = 83;
			this->label46->Text = L"Amplitude: ";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox2->Location = System::Drawing::Point(272, 371);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(52, 21);
			this->comboBox2->TabIndex = 87;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox2_SelectedIndexChanged);
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox3->Location = System::Drawing::Point(272, 397);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(52, 21);
			this->comboBox3->TabIndex = 88;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox3_SelectedIndexChanged);
			// 
			// comboBox4
			// 
			this->comboBox4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox4->Location = System::Drawing::Point(272, 423);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(52, 21);
			this->comboBox4->TabIndex = 89;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox4_SelectedIndexChanged);
			// 
			// comboBox5
			// 
			this->comboBox5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox5->Location = System::Drawing::Point(620, 418);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(52, 21);
			this->comboBox5->TabIndex = 90;
			this->comboBox5->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox5_SelectedIndexChanged);
			// 
			// comboBox6
			// 
			this->comboBox6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox6->Location = System::Drawing::Point(620, 444);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(52, 21);
			this->comboBox6->TabIndex = 91;
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox6_SelectedIndexChanged);
			// 
			// comboBox7
			// 
			this->comboBox7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox7->Location = System::Drawing::Point(620, 470);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(52, 21);
			this->comboBox7->TabIndex = 92;
			this->comboBox7->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox7_SelectedIndexChanged);
			// 
			// comboBox8
			// 
			this->comboBox8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Frequency Increment", L"# of Measurements" });
			this->comboBox8->Location = System::Drawing::Point(17, 423);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(140, 21);
			this->comboBox8->TabIndex = 93;
			this->comboBox8->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox8_SelectedIndexChanged);
			// 
			// comboBox9
			// 
			this->comboBox9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Frequency Increment", L"# of Measurements" });
			this->comboBox9->Location = System::Drawing::Point(365, 470);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(140, 21);
			this->comboBox9->TabIndex = 94;
			this->comboBox9->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox9_SelectedIndexChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(-5, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(694, 688);
			this->tabControl1->TabIndex = 95;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->checkBox7);
			this->tabPage1->Controls->Add(this->checkBox4);
			this->tabPage1->Controls->Add(this->checkBox3);
			this->tabPage1->Controls->Add(this->checkBox2);
			this->tabPage1->Controls->Add(this->comboBox22);
			this->tabPage1->Controls->Add(this->comboBox20);
			this->tabPage1->Controls->Add(this->comboBox19);
			this->tabPage1->Controls->Add(this->textBox36);
			this->tabPage1->Controls->Add(this->label70);
			this->tabPage1->Controls->Add(this->label66);
			this->tabPage1->Controls->Add(this->label65);
			this->tabPage1->Controls->Add(this->label60);
			this->tabPage1->Controls->Add(this->textBox35);
			this->tabPage1->Controls->Add(this->textBox34);
			this->tabPage1->Controls->Add(this->textBox32);
			this->tabPage1->Controls->Add(this->textBox30);
			this->tabPage1->Controls->Add(this->label58);
			this->tabPage1->Controls->Add(this->label36);
			this->tabPage1->Controls->Add(this->comboBox9);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->textBox1);
			this->tabPage1->Controls->Add(this->label37);
			this->tabPage1->Controls->Add(this->textBox10);
			this->tabPage1->Controls->Add(this->comboBox1);
			this->tabPage1->Controls->Add(this->comboBox8);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->textBox9);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->textBox11);
			this->tabPage1->Controls->Add(this->comboBox7);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label39);
			this->tabPage1->Controls->Add(this->textBox15);
			this->tabPage1->Controls->Add(this->comboBox6);
			this->tabPage1->Controls->Add(this->label9);
			this->tabPage1->Controls->Add(this->label24);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label40);
			this->tabPage1->Controls->Add(this->textBox16);
			this->tabPage1->Controls->Add(this->label34);
			this->tabPage1->Controls->Add(this->comboBox5);
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label25);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label41);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->textBox19);
			this->tabPage1->Controls->Add(this->comboBox4);
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->label26);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label42);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->comboBox3);
			this->tabPage1->Controls->Add(this->label13);
			this->tabPage1->Controls->Add(this->textBox7);
			this->tabPage1->Controls->Add(this->textBox2);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label46);
			this->tabPage1->Controls->Add(this->label30);
			this->tabPage1->Controls->Add(this->comboBox2);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->textBox3);
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label45);
			this->tabPage1->Controls->Add(this->textBox17);
			this->tabPage1->Controls->Add(this->label32);
			this->tabPage1->Controls->Add(this->label43);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->textBox4);
			this->tabPage1->Controls->Add(this->label44);
			this->tabPage1->Controls->Add(this->label31);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(686, 662);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Frequency & Amplitude Sweeps";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox7->Location = System::Drawing::Point(496, 249);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(97, 19);
			this->checkBox7->TabIndex = 141;
			this->checkBox7->Text = L"Average OFF";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox7_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox4->Location = System::Drawing::Point(350, 93);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(51, 19);
			this->checkBox4->TabIndex = 139;
			this->checkBox4->Text = L"USB";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox4_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox3->Location = System::Drawing::Point(227, 93);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(73, 19);
			this->checkBox3->TabIndex = 138;
			this->checkBox3->Text = L"Ethernet";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox3_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox2->Location = System::Drawing::Point(350, 249);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(130, 19);
			this->checkBox2->TabIndex = 137;
			this->checkBox2->Text = L"Calibrate PPE OFF";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox2_CheckedChanged);
			// 
			// comboBox22
			// 
			this->comboBox22->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox22->FormattingEnabled = true;
			this->comboBox22->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hz", L"kHz", L"MHz", L"GHz" });
			this->comboBox22->Location = System::Drawing::Point(602, 219);
			this->comboBox22->Name = L"comboBox22";
			this->comboBox22->Size = System::Drawing::Size(52, 21);
			this->comboBox22->TabIndex = 110;
			this->comboBox22->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox22_SelectedIndexChanged);
			// 
			// comboBox20
			// 
			this->comboBox20->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox20->FormattingEnabled = true;
			this->comboBox20->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hz", L"kHz", L"MHz", L"GHz" });
			this->comboBox20->Location = System::Drawing::Point(602, 193);
			this->comboBox20->Name = L"comboBox20";
			this->comboBox20->Size = System::Drawing::Size(52, 21);
			this->comboBox20->TabIndex = 109;
			this->comboBox20->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox20_SelectedIndexChanged);
			// 
			// comboBox19
			// 
			this->comboBox19->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox19->FormattingEnabled = true;
			this->comboBox19->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hz", L"kHz", L"MHz", L"GHz" });
			this->comboBox19->Location = System::Drawing::Point(602, 167);
			this->comboBox19->Name = L"comboBox19";
			this->comboBox19->Size = System::Drawing::Size(52, 21);
			this->comboBox19->TabIndex = 108;
			this->comboBox19->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox19_SelectedIndexChanged);
			// 
			// textBox36
			// 
			this->textBox36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox36->Location = System::Drawing::Point(151, 47);
			this->textBox36->Name = L"textBox36";
			this->textBox36->Size = System::Drawing::Size(521, 20);
			this->textBox36->TabIndex = 107;
			this->textBox36->Text = L"C:\\Users\\Aaron\'s PC\\Desktop\\Projects\\Sig\\Siggen_Specan_GUI\\example.csv";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label70->Location = System::Drawing::Point(6, 49);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(84, 15);
			this->label70->TabIndex = 106;
			this->label70->Text = L"Filename/path";
			// 
			// label66
			// 
			this->label66->AutoSize = true;
			this->label66->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label66->Location = System::Drawing::Point(347, 221);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(98, 15);
			this->label66->TabIndex = 102;
			this->label66->Text = L"Video Bandwidth";
			// 
			// label65
			// 
			this->label65->AutoSize = true;
			this->label65->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label65->Location = System::Drawing::Point(347, 195);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(126, 15);
			this->label65->TabIndex = 101;
			this->label65->Text = L"Resolution Bandwidth";
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label60->Location = System::Drawing::Point(347, 169);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(34, 15);
			this->label60->TabIndex = 100;
			this->label60->Text = L"Span";
			// 
			// textBox35
			// 
			this->textBox35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox35->Location = System::Drawing::Point(496, 219);
			this->textBox35->Name = L"textBox35";
			this->textBox35->Size = System::Drawing::Size(100, 20);
			this->textBox35->TabIndex = 99;
			this->textBox35->Text = L"1";
			this->textBox35->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox34
			// 
			this->textBox34->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox34->Location = System::Drawing::Point(496, 193);
			this->textBox34->Name = L"textBox34";
			this->textBox34->Size = System::Drawing::Size(100, 20);
			this->textBox34->TabIndex = 98;
			this->textBox34->Text = L"1";
			this->textBox34->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox32
			// 
			this->textBox32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox32->Location = System::Drawing::Point(496, 167);
			this->textBox32->Name = L"textBox32";
			this->textBox32->Size = System::Drawing::Size(100, 20);
			this->textBox32->TabIndex = 97;
			this->textBox32->Text = L"100";
			this->textBox32->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox30
			// 
			this->textBox30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox30->Location = System::Drawing::Point(496, 141);
			this->textBox30->Name = L"textBox30";
			this->textBox30->Size = System::Drawing::Size(100, 20);
			this->textBox30->TabIndex = 96;
			this->textBox30->Text = L"120";
			this->textBox30->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label58->Location = System::Drawing::Point(347, 141);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(37, 15);
			this->label58->TabIndex = 95;
			this->label58->Text = L"Scale";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->checkBox5);
			this->tabPage2->Controls->Add(this->checkBox6);
			this->tabPage2->Controls->Add(this->label73);
			this->tabPage2->Controls->Add(this->comboBox26);
			this->tabPage2->Controls->Add(this->label74);
			this->tabPage2->Controls->Add(this->comboBox27);
			this->tabPage2->Controls->Add(this->textBox39);
			this->tabPage2->Controls->Add(this->textBox40);
			this->tabPage2->Controls->Add(this->label72);
			this->tabPage2->Controls->Add(this->textBox38);
			this->tabPage2->Controls->Add(this->label67);
			this->tabPage2->Controls->Add(this->label68);
			this->tabPage2->Controls->Add(this->label69);
			this->tabPage2->Controls->Add(this->label71);
			this->tabPage2->Controls->Add(this->textBox13);
			this->tabPage2->Controls->Add(this->label15);
			this->tabPage2->Controls->Add(this->comboBox23);
			this->tabPage2->Controls->Add(this->comboBox24);
			this->tabPage2->Controls->Add(this->comboBox25);
			this->tabPage2->Controls->Add(this->label16);
			this->tabPage2->Controls->Add(this->label33);
			this->tabPage2->Controls->Add(this->label35);
			this->tabPage2->Controls->Add(this->textBox14);
			this->tabPage2->Controls->Add(this->textBox18);
			this->tabPage2->Controls->Add(this->textBox20);
			this->tabPage2->Controls->Add(this->textBox37);
			this->tabPage2->Controls->Add(this->label38);
			this->tabPage2->Controls->Add(this->textBox12);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->label63);
			this->tabPage2->Controls->Add(this->label64);
			this->tabPage2->Controls->Add(this->comboBox21);
			this->tabPage2->Controls->Add(this->comboBox17);
			this->tabPage2->Controls->Add(this->textBox28);
			this->tabPage2->Controls->Add(this->label55);
			this->tabPage2->Controls->Add(this->textBox29);
			this->tabPage2->Controls->Add(this->comboBox18);
			this->tabPage2->Controls->Add(this->label56);
			this->tabPage2->Controls->Add(this->textBox31);
			this->tabPage2->Controls->Add(this->label57);
			this->tabPage2->Controls->Add(this->textBox33);
			this->tabPage2->Controls->Add(this->label59);
			this->tabPage2->Controls->Add(this->label61);
			this->tabPage2->Controls->Add(this->label62);
			this->tabPage2->Controls->Add(this->label51);
			this->tabPage2->Controls->Add(this->textBox25);
			this->tabPage2->Controls->Add(this->textBox26);
			this->tabPage2->Controls->Add(this->label52);
			this->tabPage2->Controls->Add(this->textBox27);
			this->tabPage2->Controls->Add(this->label53);
			this->tabPage2->Controls->Add(this->label54);
			this->tabPage2->Controls->Add(this->textBox24);
			this->tabPage2->Controls->Add(this->label50);
			this->tabPage2->Controls->Add(this->comboBox15);
			this->tabPage2->Controls->Add(this->comboBox14);
			this->tabPage2->Controls->Add(this->comboBox13);
			this->tabPage2->Controls->Add(this->comboBox12);
			this->tabPage2->Controls->Add(this->label49);
			this->tabPage2->Controls->Add(this->button6);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->comboBox16);
			this->tabPage2->Controls->Add(this->label48);
			this->tabPage2->Controls->Add(this->checkBox1);
			this->tabPage2->Controls->Add(this->textBox23);
			this->tabPage2->Controls->Add(this->label47);
			this->tabPage2->Controls->Add(this->textBox22);
			this->tabPage2->Controls->Add(this->label29);
			this->tabPage2->Controls->Add(this->textBox21);
			this->tabPage2->Controls->Add(this->label28);
			this->tabPage2->Controls->Add(this->label27);
			this->tabPage2->Controls->Add(this->label23);
			this->tabPage2->Controls->Add(this->label22);
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->comboBox10);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(686, 662);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Attenuators & Filters ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox5->Location = System::Drawing::Point(352, 83);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(51, 19);
			this->checkBox5->TabIndex = 146;
			this->checkBox5->Text = L"USB";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox5_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox6->Location = System::Drawing::Point(229, 83);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(73, 19);
			this->checkBox6->TabIndex = 145;
			this->checkBox6->Text = L"Ethernet";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox6_CheckedChanged);
			// 
			// label73
			// 
			this->label73->AutoSize = true;
			this->label73->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label73->Location = System::Drawing::Point(356, 256);
			this->label73->Name = L"label73";
			this->label73->Size = System::Drawing::Size(95, 15);
			this->label73->TabIndex = 139;
			this->label73->Text = L"Start Frequency";
			// 
			// comboBox26
			// 
			this->comboBox26->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox26->FormattingEnabled = true;
			this->comboBox26->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox26->Location = System::Drawing::Point(614, 280);
			this->comboBox26->Name = L"comboBox26";
			this->comboBox26->Size = System::Drawing::Size(52, 21);
			this->comboBox26->TabIndex = 144;
			this->comboBox26->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox26_SelectedIndexChanged);
			// 
			// label74
			// 
			this->label74->AutoSize = true;
			this->label74->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label74->Location = System::Drawing::Point(356, 282);
			this->label74->Name = L"label74";
			this->label74->Size = System::Drawing::Size(87, 15);
			this->label74->TabIndex = 140;
			this->label74->Text = L"End Frequency";
			// 
			// comboBox27
			// 
			this->comboBox27->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox27->FormattingEnabled = true;
			this->comboBox27->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox27->Location = System::Drawing::Point(614, 254);
			this->comboBox27->Name = L"comboBox27";
			this->comboBox27->Size = System::Drawing::Size(52, 21);
			this->comboBox27->TabIndex = 143;
			this->comboBox27->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox27_SelectedIndexChanged);
			// 
			// textBox39
			// 
			this->textBox39->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox39->Location = System::Drawing::Point(505, 280);
			this->textBox39->Name = L"textBox39";
			this->textBox39->Size = System::Drawing::Size(100, 20);
			this->textBox39->TabIndex = 142;
			this->textBox39->Text = L"2000";
			this->textBox39->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox40
			// 
			this->textBox40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox40->Location = System::Drawing::Point(505, 254);
			this->textBox40->Name = L"textBox40";
			this->textBox40->Size = System::Drawing::Size(100, 20);
			this->textBox40->TabIndex = 141;
			this->textBox40->Text = L"20";
			this->textBox40->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label72
			// 
			this->label72->AutoSize = true;
			this->label72->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label72->Location = System::Drawing::Point(43, 283);
			this->label72->Name = L"label72";
			this->label72->Size = System::Drawing::Size(47, 15);
			this->label72->TabIndex = 138;
			this->label72->Text = L"Sweeps";
			// 
			// textBox38
			// 
			this->textBox38->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox38->Location = System::Drawing::Point(144, 281);
			this->textBox38->Name = L"textBox38";
			this->textBox38->Size = System::Drawing::Size(100, 20);
			this->textBox38->TabIndex = 137;
			this->textBox38->Text = L"5";
			this->textBox38->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label67
			// 
			this->label67->AutoSize = true;
			this->label67->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label67->Location = System::Drawing::Point(526, 601);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(88, 19);
			this->label67->TabIndex = 133;
			this->label67->Text = L"Amplitude: ";
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label68->Location = System::Drawing::Point(526, 629);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(89, 19);
			this->label68->TabIndex = 134;
			this->label68->Text = L"Frequency: ";
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label69->Location = System::Drawing::Point(633, 601);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(17, 19);
			this->label69->TabIndex = 135;
			this->label69->Text = L"0";
			// 
			// label71
			// 
			this->label71->AutoSize = true;
			this->label71->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label71->Location = System::Drawing::Point(633, 629);
			this->label71->Name = L"label71";
			this->label71->Size = System::Drawing::Size(17, 19);
			this->label71->TabIndex = 136;
			this->label71->Text = L"0";
			// 
			// textBox13
			// 
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(144, 125);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 20);
			this->textBox13->TabIndex = 132;
			this->textBox13->Text = L"192.168.2.101";
			this->textBox13->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(43, 127);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 15);
			this->label15->TabIndex = 131;
			this->label15->Text = L"IP of Board";
			// 
			// comboBox23
			// 
			this->comboBox23->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox23->FormattingEnabled = true;
			this->comboBox23->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hz", L"kHz", L"MHz", L"GHz" });
			this->comboBox23->Location = System::Drawing::Point(611, 151);
			this->comboBox23->Name = L"comboBox23";
			this->comboBox23->Size = System::Drawing::Size(52, 21);
			this->comboBox23->TabIndex = 130;
			this->comboBox23->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox23_SelectedIndexChanged);
			// 
			// comboBox24
			// 
			this->comboBox24->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox24->FormattingEnabled = true;
			this->comboBox24->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hz", L"kHz", L"MHz", L"GHz" });
			this->comboBox24->Location = System::Drawing::Point(611, 125);
			this->comboBox24->Name = L"comboBox24";
			this->comboBox24->Size = System::Drawing::Size(52, 21);
			this->comboBox24->TabIndex = 129;
			this->comboBox24->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox24_SelectedIndexChanged);
			// 
			// comboBox25
			// 
			this->comboBox25->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox25->FormattingEnabled = true;
			this->comboBox25->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Hz", L"kHz", L"MHz", L"GHz" });
			this->comboBox25->Location = System::Drawing::Point(250, 307);
			this->comboBox25->Name = L"comboBox25";
			this->comboBox25->Size = System::Drawing::Size(52, 21);
			this->comboBox25->TabIndex = 128;
			this->comboBox25->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox25_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(356, 153);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(98, 15);
			this->label16->TabIndex = 127;
			this->label16->Text = L"Video Bandwidth";
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(356, 127);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(126, 15);
			this->label33->TabIndex = 126;
			this->label33->Text = L"Resolution Bandwidth";
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label35->Location = System::Drawing::Point(43, 309);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(34, 15);
			this->label35->TabIndex = 125;
			this->label35->Text = L"Span";
			// 
			// textBox14
			// 
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(505, 151);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 20);
			this->textBox14->TabIndex = 124;
			this->textBox14->Text = L"1";
			this->textBox14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox18
			// 
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox18->Location = System::Drawing::Point(505, 125);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(100, 20);
			this->textBox18->TabIndex = 123;
			this->textBox18->Text = L"1";
			this->textBox18->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox20
			// 
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox20->Location = System::Drawing::Point(144, 307);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(100, 20);
			this->textBox20->TabIndex = 122;
			this->textBox20->Text = L"100";
			this->textBox20->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox37
			// 
			this->textBox37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox37->Location = System::Drawing::Point(144, 255);
			this->textBox37->Name = L"textBox37";
			this->textBox37->Size = System::Drawing::Size(100, 20);
			this->textBox37->TabIndex = 121;
			this->textBox37->Text = L"120";
			this->textBox37->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label38->Location = System::Drawing::Point(43, 257);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(37, 15);
			this->label38->TabIndex = 120;
			this->label38->Text = L"Scale";
			// 
			// textBox12
			// 
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(154, 45);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(509, 20);
			this->textBox12->TabIndex = 117;
			this->textBox12->Text = L"C:\\Users\\Aaron\'s PC\\Desktop\\Projects\\Sig\\Siggen_Specan_GUI\\example.csv";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(13, 47);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(84, 15);
			this->label14->TabIndex = 116;
			this->label14->Text = L"Filename/path";
			// 
			// label63
			// 
			this->label63->AutoSize = true;
			this->label63->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label63->Location = System::Drawing::Point(9, 20);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(139, 15);
			this->label63->TabIndex = 114;
			this->label63->Text = L"Select Signal Generator";
			// 
			// label64
			// 
			this->label64->AutoSize = true;
			this->label64->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label64->Location = System::Drawing::Point(151, 42);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(0, 15);
			this->label64->TabIndex = 115;
			// 
			// comboBox21
			// 
			this->comboBox21->FormattingEnabled = true;
			this->comboBox21->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Keysight", L"Anritsu" });
			this->comboBox21->Location = System::Drawing::Point(154, 18);
			this->comboBox21->Name = L"comboBox21";
			this->comboBox21->Size = System::Drawing::Size(105, 21);
			this->comboBox21->TabIndex = 113;
			this->comboBox21->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox21_SelectedIndexChanged);
			// 
			// comboBox17
			// 
			this->comboBox17->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox17->FormattingEnabled = true;
			this->comboBox17->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Frequency Increment", L"# of Measurements" });
			this->comboBox17->Location = System::Drawing::Point(359, 306);
			this->comboBox17->Name = L"comboBox17";
			this->comboBox17->Size = System::Drawing::Size(140, 21);
			this->comboBox17->TabIndex = 112;
			this->comboBox17->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox17_SelectedIndexChanged);
			// 
			// textBox28
			// 
			this->textBox28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox28->Location = System::Drawing::Point(505, 228);
			this->textBox28->Name = L"textBox28";
			this->textBox28->Size = System::Drawing::Size(100, 20);
			this->textBox28->TabIndex = 105;
			this->textBox28->Text = L"1";
			this->textBox28->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label55->Location = System::Drawing::Point(356, 230);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(126, 15);
			this->label55->TabIndex = 99;
			this->label55->Text = L"Amplitude Decrement";
			// 
			// textBox29
			// 
			this->textBox29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox29->Location = System::Drawing::Point(505, 202);
			this->textBox29->Name = L"textBox29";
			this->textBox29->Size = System::Drawing::Size(100, 20);
			this->textBox29->TabIndex = 104;
			this->textBox29->Text = L"-14";
			this->textBox29->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// comboBox18
			// 
			this->comboBox18->Font = (gcnew System::Drawing::Font(L"Times New Roman", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox18->FormattingEnabled = true;
			this->comboBox18->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"kHz", L"MHz", L"GHz" });
			this->comboBox18->Location = System::Drawing::Point(614, 306);
			this->comboBox18->Name = L"comboBox18";
			this->comboBox18->Size = System::Drawing::Size(52, 21);
			this->comboBox18->TabIndex = 111;
			this->comboBox18->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox18_SelectedIndexChanged);
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label56->Location = System::Drawing::Point(356, 204);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(85, 15);
			this->label56->TabIndex = 98;
			this->label56->Text = L"End Amplitude";
			// 
			// textBox31
			// 
			this->textBox31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox31->Location = System::Drawing::Point(505, 176);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(100, 20);
			this->textBox31->TabIndex = 103;
			this->textBox31->Text = L"10";
			this->textBox31->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label57->Location = System::Drawing::Point(611, 180);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(31, 15);
			this->label57->TabIndex = 100;
			this->label57->Text = L"dBm";
			// 
			// textBox33
			// 
			this->textBox33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox33->Location = System::Drawing::Point(505, 306);
			this->textBox33->Name = L"textBox33";
			this->textBox33->Size = System::Drawing::Size(100, 20);
			this->textBox33->TabIndex = 108;
			this->textBox33->Text = L"100000";
			this->textBox33->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label59
			// 
			this->label59->AutoSize = true;
			this->label59->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label59->Location = System::Drawing::Point(611, 206);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(31, 15);
			this->label59->TabIndex = 101;
			this->label59->Text = L"dBm";
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label61->Location = System::Drawing::Point(611, 230);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(31, 15);
			this->label61->TabIndex = 102;
			this->label61->Text = L"dBm";
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label62->Location = System::Drawing::Point(356, 178);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(93, 15);
			this->label62->TabIndex = 95;
			this->label62->Text = L"Start Amplitude";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label51->Location = System::Drawing::Point(250, 231);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(31, 15);
			this->label51->TabIndex = 85;
			this->label51->Text = L"dBm";
			// 
			// textBox25
			// 
			this->textBox25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox25->Location = System::Drawing::Point(144, 203);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(100, 20);
			this->textBox25->TabIndex = 82;
			this->textBox25->Text = L"20";
			this->textBox25->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox26
			// 
			this->textBox26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox26->Location = System::Drawing::Point(144, 177);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(100, 20);
			this->textBox26->TabIndex = 81;
			this->textBox26->Text = L"19";
			this->textBox26->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label52->Location = System::Drawing::Point(43, 231);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(95, 15);
			this->label52->TabIndex = 84;
			this->label52->Text = L"Reference Level";
			// 
			// textBox27
			// 
			this->textBox27->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox27->Location = System::Drawing::Point(144, 229);
			this->textBox27->Name = L"textBox27";
			this->textBox27->Size = System::Drawing::Size(100, 20);
			this->textBox27->TabIndex = 83;
			this->textBox27->Text = L"10";
			this->textBox27->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label53->Location = System::Drawing::Point(43, 204);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(96, 15);
			this->label53->TabIndex = 80;
			this->label53->Text = L"SpecAn Address";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label54->Location = System::Drawing::Point(43, 176);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(95, 15);
			this->label54->TabIndex = 79;
			this->label54->Text = L"SigGen Address";
			// 
			// textBox24
			// 
			this->textBox24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox24->Location = System::Drawing::Point(144, 151);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(100, 20);
			this->textBox24->TabIndex = 56;
			this->textBox24->Text = L"0";
			this->textBox24->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label50->Location = System::Drawing::Point(43, 153);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(64, 15);
			this->label50->TabIndex = 55;
			this->label50->Text = L"IP of GPIB";
			// 
			// comboBox15
			// 
			this->comboBox15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox15->FormattingEnabled = true;
			this->comboBox15->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"0", L"0.25", L"0.5", L"1", L"2", L"4", L"8",
					L"16", L"31.75 (010000000)", L"63.5 (100000000)", L"31.75 (001111111)", L"63.5 (011111111)", L"127", L"95.25 (110000000)", L"111.25",
					L"95.25 (101111111)"
			});
			this->comboBox15->Location = System::Drawing::Point(181, 577);
			this->comboBox15->Name = L"comboBox15";
			this->comboBox15->Size = System::Drawing::Size(121, 21);
			this->comboBox15->TabIndex = 29;
			this->comboBox15->Visible = false;
			// 
			// comboBox14
			// 
			this->comboBox14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox14->FormattingEnabled = true;
			this->comboBox14->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"0", L"0.25", L"0.5", L"1", L"2", L"4", L"8",
					L"16", L"31.75 (010000000)", L"63.5 (100000000)", L"31.75 (001111111)", L"63.5 (011111111)", L"127", L"95.25 (110000000)", L"111.25",
					L"95.25 (101111111)"
			});
			this->comboBox14->Location = System::Drawing::Point(181, 550);
			this->comboBox14->Name = L"comboBox14";
			this->comboBox14->Size = System::Drawing::Size(121, 21);
			this->comboBox14->TabIndex = 28;
			this->comboBox14->Visible = false;
			// 
			// comboBox13
			// 
			this->comboBox13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox13->FormattingEnabled = true;
			this->comboBox13->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"0", L"0.25", L"0.5", L"1", L"2", L"4", L"8",
					L"16", L"31.75 (010000000)", L"63.5 (100000000)", L"31.75 (001111111)", L"63.5 (011111111)", L"127", L"95.25 (110000000)", L"111.25",
					L"95.25 (101111111)"
			});
			this->comboBox13->Location = System::Drawing::Point(181, 523);
			this->comboBox13->Name = L"comboBox13";
			this->comboBox13->Size = System::Drawing::Size(121, 21);
			this->comboBox13->TabIndex = 27;
			this->comboBox13->Visible = false;
			// 
			// comboBox12
			// 
			this->comboBox12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox12->FormattingEnabled = true;
			this->comboBox12->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"0", L"0.25", L"0.5", L"1", L"2", L"4", L"8",
					L"16", L"31.75 (010000000)", L"63.5 (100000000)", L"31.75 (001111111)", L"63.5 (011111111)", L"127", L"95.25 (110000000)", L"111.25",
					L"95.25 (101111111)"
			});
			this->comboBox12->Location = System::Drawing::Point(181, 496);
			this->comboBox12->Name = L"comboBox12";
			this->comboBox12->Size = System::Drawing::Size(121, 21);
			this->comboBox12->TabIndex = 26;
			this->comboBox12->Visible = false;
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label49->Location = System::Drawing::Point(479, 552);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(62, 19);
			this->label49->TabIndex = 24;
			this->label49->Text = L"Waiting";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(557, 566);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 23;
			this->button6->Text = L"Stop";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Measure::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(557, 537);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 22;
			this->button5->Text = L"Start";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Measure::button5_Click);
			// 
			// comboBox16
			// 
			this->comboBox16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox16->FormattingEnabled = true;
			this->comboBox16->Items->AddRange(gcnew cli::array< System::Object^  >(16) {
				L"0", L"0.25", L"0.5", L"1", L"2", L"4", L"8",
					L"16", L"31.75 (010000000)", L"63.5 (100000000)", L"31.75 (001111111)", L"63.5 (011111111)", L"127", L"95.25 (110000000)", L"111.25",
					L"95.25 (101111111)"
			});
			this->comboBox16->Location = System::Drawing::Point(181, 469);
			this->comboBox16->Name = L"comboBox16";
			this->comboBox16->Size = System::Drawing::Size(121, 21);
			this->comboBox16->TabIndex = 21;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label48->Location = System::Drawing::Point(99, 471);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(71, 15);
			this->label48->TabIndex = 20;
			this->label48->Text = L"Attenuation";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkBox1->Location = System::Drawing::Point(599, 6);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(77, 19);
			this->checkBox1->TabIndex = 19;
			this->checkBox1->Text = L"Advanced";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &Measure::checkBox1_CheckedChanged);
			// 
			// textBox23
			// 
			this->textBox23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox23->Location = System::Drawing::Point(415, 494);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(100, 20);
			this->textBox23->TabIndex = 18;
			this->textBox23->Visible = false;
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label47->Location = System::Drawing::Point(361, 496);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(48, 15);
			this->label47->TabIndex = 17;
			this->label47->Text = L"Filter 3";
			this->label47->Visible = false;
			// 
			// textBox22
			// 
			this->textBox22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox22->Location = System::Drawing::Point(415, 468);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(100, 20);
			this->textBox22->TabIndex = 16;
			this->textBox22->Visible = false;
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label29->Location = System::Drawing::Point(361, 470);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(48, 15);
			this->label29->TabIndex = 15;
			this->label29->Text = L"Filter 2";
			this->label29->Visible = false;
			// 
			// textBox21
			// 
			this->textBox21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox21->Location = System::Drawing::Point(415, 442);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(100, 20);
			this->textBox21->TabIndex = 14;
			this->textBox21->Visible = false;
			// 
			// label28
			// 
			this->label28->AutoSize = true;
			this->label28->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label28->Location = System::Drawing::Point(361, 444);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(48, 15);
			this->label28->TabIndex = 13;
			this->label28->Text = L"Filter 1";
			this->label28->Visible = false;
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label27->Location = System::Drawing::Point(99, 579);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(76, 15);
			this->label27->TabIndex = 7;
			this->label27->Text = L"Attenuator 5";
			this->label27->Visible = false;
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label23->Location = System::Drawing::Point(99, 552);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(76, 15);
			this->label23->TabIndex = 6;
			this->label23->Text = L"Attenuator 4";
			this->label23->Visible = false;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label22->Location = System::Drawing::Point(99, 525);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(76, 15);
			this->label22->TabIndex = 5;
			this->label22->Text = L"Attenuator 3";
			this->label22->Visible = false;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label21->Location = System::Drawing::Point(99, 498);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(76, 15);
			this->label21->TabIndex = 4;
			this->label21->Text = L"Attenuator 2";
			this->label21->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(99, 471);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(76, 15);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Attenuator 1";
			this->label10->Visible = false;
			// 
			// comboBox10
			// 
			this->comboBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox10->FormattingEnabled = true;
			this->comboBox10->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"VLB", L"MB Main", L"MB AUX", L"HB" });
			this->comboBox10->Location = System::Drawing::Point(181, 442);
			this->comboBox10->Name = L"comboBox10";
			this->comboBox10->Size = System::Drawing::Size(121, 21);
			this->comboBox10->TabIndex = 1;
			this->comboBox10->SelectedIndexChanged += gcnew System::EventHandler(this, &Measure::comboBox10_SelectedIndexChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(99, 444);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(69, 15);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Path Select";
			// 
			// backgroundWorker5
			// 
			this->backgroundWorker5->WorkerReportsProgress = true;
			this->backgroundWorker5->WorkerSupportsCancellation = true;
			this->backgroundWorker5->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker5_DoWork);
			this->backgroundWorker5->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker5_ProgressChanged);
			this->backgroundWorker5->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker5_RunWorkerCompleted);
			// 
			// backgroundWorker6
			// 
			this->backgroundWorker6->WorkerReportsProgress = true;
			this->backgroundWorker6->WorkerSupportsCancellation = true;
			this->backgroundWorker6->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker6_DoWork);
			this->backgroundWorker6->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker6_ProgressChanged);
			this->backgroundWorker6->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker6_RunWorkerCompleted);
			// 
			// backgroundWorker7
			// 
			this->backgroundWorker7->WorkerReportsProgress = true;
			this->backgroundWorker7->WorkerSupportsCancellation = true;
			this->backgroundWorker7->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Measure::backgroundWorker7_DoWork);
			this->backgroundWorker7->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &Measure::backgroundWorker7_ProgressChanged);
			this->backgroundWorker7->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &Measure::backgroundWorker7_RunWorkerCompleted);
			// 
			// Measure
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(682, 682);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Measure";
			this->Text = L"Measure";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

			this->comboBox1->SelectedIndex = 0;
			this->comboBox2->SelectedIndex = 0;
			this->comboBox3->SelectedIndex = 0;
			this->comboBox4->SelectedIndex = 0;
			this->comboBox5->SelectedIndex = 0;
			this->comboBox6->SelectedIndex = 0;
			this->comboBox7->SelectedIndex = 0;
			this->comboBox8->SelectedIndex = 0;
			this->comboBox9->SelectedIndex = 0;
			this->comboBox17->SelectedIndex = 1;
			this->comboBox19->SelectedIndex = 1;
			this->comboBox20->SelectedIndex = 1;
			this->comboBox21->SelectedIndex = 0;
			this->comboBox22->SelectedIndex = 1;
			this->comboBox23->SelectedIndex = 1;
			this->comboBox24->SelectedIndex = 1;
			this->comboBox25->SelectedIndex = 1;
			this->comboBox26->SelectedIndex = 1;
			this->comboBox27->SelectedIndex = 1;

			this->label10->Visible = false;
			this->label21->Visible = false;
			this->label22->Visible = false;
			this->label23->Visible = false;
			this->label27->Visible = false;
			this->label28->Visible = false;
			this->label29->Visible = false;
			this->label47->Visible = false;
			this->label49->Visible = true;
			this->comboBox12->Visible = false;
			this->comboBox13->Visible = false;
			this->comboBox14->Visible = false;
			this->comboBox15->Visible = false;
			this->comboBox16->Visible = true;
			this->textBox21->Visible = false;
			this->textBox22->Visible = false;
			this->textBox23->Visible = false;
		}
		#pragma endregion
		// Waiting for button one to be clicked (Start for Freq)
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			label19->Text = "Started";
			if (backgroundWorker1->IsBusy == true)
			{
				backgroundWorker1->CancelAsync();
			}
			else if (backgroundWorker3->IsBusy == true)
			{
				backgroundWorker3->CancelAsync();
			}
			else
			{
				system("CLS");
				String ^ in5 = textBox5->Text;
				std::string initFREQ = msclr::interop::marshal_as<std::string>(in5);
				String ^ in6 = textBox6->Text;
				std::string endFREQ = msclr::interop::marshal_as<std::string>(in6);
				String ^ in7 = textBox7->Text;
				inc = msclr::interop::marshal_as<std::string>(in7);
				double endF = std::stod(endFREQ);
				double initF = std::stod(initFREQ);
				double mea = std::stod(inc);
				// Setting increment for # of Measurements
				if (comboBox8->SelectedIndex > -1)
				{
					if (comboBox8->SelectedItem == "# of Measurements")
					{
						switch (units)
						{
						case 0:
							unitsInc = 0;
							break;
						case 1:
							unitsInc = 1;
							break;
						case 2:
							unitsInc = 2;
							break;
						}
						double total = endF - initF;
						double incF = total / mea;

						inc = std::to_string(incF);
					}
					else if (comboBox8->SelectedItem == "Frequency Increment")
					{
						if (comboBox3->SelectedIndex > -1)
						{
							if (comboBox2->SelectedItem == "kHz")
							{
								units = 0;
							}
							else if (comboBox2->SelectedItem == "MHz")
							{
								units = 1;
							}
							else if (comboBox2->SelectedItem == "GHz")
							{
								units = 2;
							}
						}
						if (comboBox4->SelectedIndex > -1)
						{
							if (comboBox4->SelectedItem == "kHz")
							{
								unitsInc = 0;
							}
							else if (comboBox4->SelectedItem == "MHz")
							{
								unitsInc = 1;
							}
							else if (comboBox4->SelectedItem == "GHz")
							{
								unitsInc = 2;
							}
						}
					}
				}
				// Start background worker
				if (comboBox1->SelectedIndex > -1)
				{
					if (comboBox1->SelectedItem == "Keysight")
					{
						backgroundWorker1->RunWorkerAsync(1);
					}
					else if (comboBox1->SelectedItem == "Anritsu")
					{
						backgroundWorker3->RunWorkerAsync(1);
					}
				}
				else
				{
					label37->Text = "Please Select Signal Generator";
				}
			}
		}
		// Waiting for button two to be clicked (Stop for Freq)
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			// Reading in values from textboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			// Stoping background worker and Specan
			backgroundWorker1->CancelAsync();
			backgroundWorker3->CancelAsync();
			//specReset(IP, SPECAN_ADDR);
			label19->Text = "Stopping";
		}
		 // Waiting for button 3 to be clicked (Stop for Amp & Freq)
		private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			// Reading in values from texboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			// Stoping background worker
			backgroundWorker2->CancelAsync();
			backgroundWorker4->CancelAsync();
			//specReset(IP, SPECAN_ADDR);
			label30->Text = "Stopping";
		}
		// Waiting for button 4 to be clicked (Start for Amp & Freq)
		private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			label30->Text = "Started";
			if (backgroundWorker2->IsBusy == true)
			{
				backgroundWorker2->CancelAsync();
			}
			else if (backgroundWorker4->IsBusy == true)
			{
				backgroundWorker4->CancelAsync();
			}
			else
			{
				system("CLS");
				// Setting increment for # of Measurements
				String ^ in11 = textBox11->Text;
				std::string initFREQ = msclr::interop::marshal_as<std::string>(in11);
				String ^ in15 = textBox15->Text;
				std::string endFREQ = msclr::interop::marshal_as<std::string>(in15);
				String ^ in16 = textBox16->Text;
				incFREQ = msclr::interop::marshal_as<std::string>(in16);
				double endF = std::stod(endFREQ);
				double initF = std::stod(initFREQ);
				double mea = std::stod(incFREQ);

				if (comboBox9->SelectedIndex > -1)
				{
					if (comboBox9->SelectedItem == "# of Measurements")
					{
						switch (units)
						{
						case 0:
							unitsInc = 0;
							break;
						case 1:
							unitsInc = 1;
							break;
						case 2:
							unitsInc = 2;
							break;
						}
						double total = endF - initF;
						double incF = total / mea;

						incFREQ = std::to_string(incF);
					}
					else if (comboBox9->SelectedItem == "Frequency Increment")
					{
						if (comboBox5->SelectedIndex > -1)
						{
							if (comboBox6->SelectedItem == "kHz")
							{
								units = 0;
							}
							else if (comboBox6->SelectedItem == "MHz")
							{
								units = 1;
							}
							else if (comboBox6->SelectedItem == "GHz")
							{
								units = 2;
							}
						}
						if (comboBox7->SelectedIndex > -1)
						{
							if (comboBox7->SelectedItem == "kHz")
							{
								unitsInc = 0;
							}
							else if (comboBox7->SelectedItem == "MHz")
							{
								unitsInc = 1;
							}
							else if (comboBox7->SelectedItem == "GHz")
							{
								unitsInc = 2;
							}
						}
					}
				}
				// Start background worker
				if (comboBox1->SelectedIndex > -1)
				{
					if (comboBox1->SelectedItem == "Keysight")
					{
						backgroundWorker2->RunWorkerAsync(1);
					}
					else if (comboBox1->SelectedItem == "Anritsu")
					{
						backgroundWorker4->RunWorkerAsync(1);
					}
				}
				else
				{
					label37->Text = "Please Select Signal Generator";
				}
			}
		}
		private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			if (backgroundWorker5->IsBusy == true)
			{
				backgroundWorker5->CancelAsync();
			}
			else if (backgroundWorker6->IsBusy == true)
			{
				backgroundWorker6->CancelAsync();
			}
			else
			{
				label49->Text = "Started";
				system("CLS");
				System::String^ sPath = comboBox10->GetItemText(comboBox10->SelectedItem);
				stdPath = msclr::interop::marshal_as<std::string>(sPath);
				System::String^ sAtten = comboBox16->GetItemText(comboBox16->SelectedItem);
				stdAtten = msclr::interop::marshal_as<std::string>(sAtten);
				System::String^ sAtten2 = comboBox12->GetItemText(comboBox12->SelectedItem);
				stdAtten2 = msclr::interop::marshal_as<std::string>(sAtten2);
				System::String^ sAtten3 = comboBox13->GetItemText(comboBox13->SelectedItem);
				stdAtten3 = msclr::interop::marshal_as<std::string>(sAtten3);
				System::String^ sAtten4 = comboBox14->GetItemText(comboBox14->SelectedItem);
				stdAtten4 = msclr::interop::marshal_as<std::string>(sAtten4);
				System::String^ sAtten5 = comboBox15->GetItemText(comboBox15->SelectedItem);
				stdAtten5 = msclr::interop::marshal_as<std::string>(sAtten5);
				String ^ in33 = textBox33->Text;
				incFREQ = msclr::interop::marshal_as<std::string>(in33);
				String ^ in40 = textBox40->Text;
				std::string initFREQ = msclr::interop::marshal_as<std::string>(in40);
				String ^ in39 = textBox39->Text;
				std::string endFREQ = msclr::interop::marshal_as<std::string>(in39);
				double endF = std::stod(endFREQ);
				double initF = std::stod(initFREQ);
				double mea = std::stod(incFREQ);
				// Reading in values from textboxes
				if (comboBox17->SelectedIndex > -1)
				{
					if (comboBox17->SelectedItem == "# of Measurements")
					{
						switch (units)
						{
						case 0:
							unitsInc = 0;
							break;
						case 1:
							unitsInc = 1;
							break;
						case 2:
							unitsInc = 2;
							break;
						}
						double total = endF - initF;
						double incF = total / mea;

						inc = std::to_string(incF);
					}
					else if (comboBox17->SelectedItem == "Frequency Increment")
					{
						if (comboBox27->SelectedIndex > -1)
						{
							if (comboBox26->SelectedItem == "kHz")
							{
								units = 0;
							}
							else if (comboBox26->SelectedItem == "MHz")
							{
								units = 1;
							}
							else if (comboBox26->SelectedItem == "GHz")
							{
								units = 2;
							}
						}
						if (comboBox18->SelectedIndex > -1)
						{
							if (comboBox18->SelectedItem == "kHz")
							{
								unitsInc = 0;
							}
							else if (comboBox18->SelectedItem == "MHz")
							{
								unitsInc = 1;
							}
							else if (comboBox18->SelectedItem == "GHz")
							{
								unitsInc = 2;
							}
						}
					}
				}
				// Start background worker
				if (comboBox21->SelectedIndex > -1)
				{
					if (comboBox21->SelectedItem == "Keysight")
					{
						backgroundWorker5->RunWorkerAsync(1);
					}
					else if (comboBox21->SelectedItem == "Anritsu")
					{
						backgroundWorker6->RunWorkerAsync(1);
					}
				}
				else
				{
					label64->Text = "Please Select Signal Generator";
				}
			}
		}
		private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			// Reading in values from textboxes
			String ^ in24 = textBox24->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in24);
			const char* IP = ip.c_str();
			String ^ in25 = textBox25->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in25);
			const char* SPECAN_ADDR = SPEC.c_str();
			// Stoping background worker and Specan
			backgroundWorker5->CancelAsync();
			backgroundWorker6->CancelAsync();
			//specReset(IP, SPECAN_ADDR);
			label49->Text = "Stopping";
		}
		private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			if (backgroundWorker7->IsBusy == true)
			{
				backgroundWorker7->CancelAsync();
			}
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in2 = textBox2->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in2);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in4 = textBox4->Text;
			std::string POW = msclr::interop::marshal_as<std::string>(in4);
			String ^ in6 = textBox6->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in6);
			String ^ in17 = textBox17->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in17);
			String ^ in19 = textBox19->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in19);
			String ^ in30 = textBox30->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in30);
			String ^ in32 = textBox32->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in32);
			String ^ in34 = textBox34->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in34);
			String ^ in35 = textBox35->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in35);
			String ^ in36 = textBox36->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in36);

			double iInc = convertInc(inc);
			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(16);
			streamObj << (frequF + iInc);
			std::string resumeFreq = streamObj.str();

			backgroundWorker7->RunWorkerAsync(1);
			//pause = false;
		}
		// Background worker one (runs Freq on another thread)
		private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in2 = textBox2->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in2);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in4 = textBox4->Text;
			std::string POW = msclr::interop::marshal_as<std::string>(in4);
			String ^ in5 = textBox5->Text;
			std::string initFREQ = msclr::interop::marshal_as<std::string>(in5);
			String ^ in6 = textBox6->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in6);
			String ^ in17 = textBox17->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in17);
			String ^ in19 = textBox19->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in19);
			String ^ in30 = textBox30->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in30);
			String ^ in32 = textBox32->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in32);
			String ^ in34 = textBox34->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in34);
			String ^ in35 = textBox35->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in35);
			String ^ in36 = textBox36->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in36);
			// Checking for cancelation
			if (backgroundWorker1->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling measure function to begin taking specified measurements for Freq
			if (eth == 1)
			{
				ethMeasureK(file, IP, SIGGEN_ADDR, SPECAN_ADDR, POW, initFREQ, endFREQ, inc, rLev, sweeps, scale, span, band, vidBand, backgroundWorker1);
			}
			else if (eth == 0)
			{
				usbMeasureK(file, IP, SIGGEN_ADDR, SPECAN_ADDR, POW, initFREQ, endFREQ, inc, rLev, sweeps, scale, span, band, vidBand, backgroundWorker1);
			}
			// Stopping background worker
			backgroundWorker1->CancelAsync();
		}
		// Background worker two (runs Amp & Freq on another thread)
		private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in2 = textBox2->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in2);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in8 = textBox8->Text;
			std::string initPOW = msclr::interop::marshal_as<std::string>(in8);
			String ^ in9 = textBox9->Text;
			std::string endPOW = msclr::interop::marshal_as<std::string>(in9);
			String ^ in10 = textBox10->Text;
			std::string incPOW = msclr::interop::marshal_as<std::string>(in10);
			String ^ in11 = textBox11->Text;
			std::string initFREQ = msclr::interop::marshal_as<std::string>(in11);
			String ^ in15 = textBox15->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in15);
			String ^ in17 = textBox17->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in17);
			String ^ in19 = textBox19->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in19);
			String ^ in30 = textBox30->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in30);
			String ^ in32 = textBox32->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in32);
			String ^ in34 = textBox34->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in34);
			String ^ in35 = textBox35->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in35);
			String ^ in36 = textBox36->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in36);
			// Checking for cancelation
			if (backgroundWorker2->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling ampFreq function to begin measuring specified measurements for Amp & Freq
			if (eth == 1)
			{
				ethAmpFreqK(file, IP, SIGGEN_ADDR, SPECAN_ADDR, initPOW, endPOW, incPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, backgroundWorker2);
			}
			else if (eth == 0)
			{
				usbAmpFreqK(file, IP, SIGGEN_ADDR, SPECAN_ADDR, initPOW, endPOW, incPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, backgroundWorker2);
			}
			// Stopping background worker
			backgroundWorker2->CancelAsync();
		}
		private: System::Void backgroundWorker3_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in2 = textBox2->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in2);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in4 = textBox4->Text;
			std::string POW = msclr::interop::marshal_as<std::string>(in4);
			String ^ in5 = textBox5->Text;
			std::string initFREQ = msclr::interop::marshal_as<std::string>(in5);
			String ^ in6 = textBox6->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in6);
			String ^ in17 = textBox17->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in17);
			String ^ in19 = textBox19->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in19);
			String ^ in30 = textBox30->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in30);
			String ^ in32 = textBox32->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in32);
			String ^ in34 = textBox34->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in34);
			String ^ in35 = textBox35->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in35);
			String ^ in36 = textBox36->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in36);
			// Checking for cancelation
			if (backgroundWorker3->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling measure function to begin taking specified measurements for Freq
			if (eth == 1)
			{
				ethMeasureA(file, IP, SIGGEN_ADDR, SPECAN_ADDR, POW, initFREQ, endFREQ, inc, rLev, sweeps, scale, span, band, vidBand, backgroundWorker3);
			}
			else if (eth == 0)
			{
				usbMeasureA(file, IP, SIGGEN_ADDR, SPECAN_ADDR, POW, initFREQ, endFREQ, inc, rLev, sweeps, scale, span, band, vidBand, backgroundWorker3);
			}
			// Stopping background worker
			backgroundWorker3->CancelAsync();
		}
		private: System::Void backgroundWorker4_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in2 = textBox2->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in2);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in8 = textBox8->Text;
			std::string initPOW = msclr::interop::marshal_as<std::string>(in8);
			String ^ in9 = textBox9->Text;
			std::string endPOW = msclr::interop::marshal_as<std::string>(in9);
			String ^ in10 = textBox10->Text;
			std::string incPOW = msclr::interop::marshal_as<std::string>(in10);
			String ^ in11 = textBox11->Text;
			std::string initFREQ = msclr::interop::marshal_as<std::string>(in11);
			String ^ in15 = textBox15->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in15);
			String ^ in17 = textBox17->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in17);
			String ^ in19 = textBox19->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in19);
			String ^ in30 = textBox30->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in30);
			String ^ in32 = textBox32->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in32);
			String ^ in34 = textBox34->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in34);
			String ^ in35 = textBox35->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in35);
			String ^ in36 = textBox36->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in36);
			// Checking for cancelation
			if (backgroundWorker4->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling ampFreq function to begin measuring specified measurements for Amp & Freq
			if (eth == 1)
			{
				ethAmpFreqA(file, IP, SIGGEN_ADDR, SPECAN_ADDR, initPOW, endPOW, incPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, backgroundWorker4);
			}
			else if (eth == 0)
			{
				usbAmpFreqA(file, IP, SIGGEN_ADDR, SPECAN_ADDR, initPOW, endPOW, incPOW, initFREQ, endFREQ, incFREQ, rLev, sweeps, scale, span, band, vidBand, backgroundWorker4);
			}
			// Stopping background worker
			backgroundWorker4->CancelAsync();
		}
		private: System::Void backgroundWorker5_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in13 = textBox13->Text;
			std::string ipB = msclr::interop::marshal_as<std::string>(in13);
			const char* IPB = ipB.c_str();
			String ^ in24 = textBox24->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in24);
			const char* IP = ip.c_str();
			String ^ in26 = textBox26->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in26);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in25 = textBox25->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in25);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in31 = textBox31->Text;
			std::string initPOW = msclr::interop::marshal_as<std::string>(in31);
			String ^ in29 = textBox29->Text;
			std::string endPOW = msclr::interop::marshal_as<std::string>(in29);
			String ^ in28 = textBox28->Text;
			std::string incPOW = msclr::interop::marshal_as<std::string>(in28);
			String ^ in27 = textBox27->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in27);
			String ^ in37 = textBox37->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in37);
			String ^ in20 = textBox20->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in20);
			String ^ in18 = textBox18->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in18);
			String ^ in14 = textBox14->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in14);
			String ^ in12 = textBox12->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in12);
			String ^ in38 = textBox38->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in38);
			String ^ in40 = textBox40->Text;
			std::string initFREQ = msclr::interop::marshal_as<std::string>(in40);
			String ^ in39 = textBox39->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in39);
			String ^ in21 = textBox21->Text;
			std::string swf1 = msclr::interop::marshal_as<std::string>(in21);
			String ^ in22 = textBox22->Text;
			std::string swf2 = msclr::interop::marshal_as<std::string>(in22);
			String ^ in23 = textBox23->Text;
			std::string swf3 = msclr::interop::marshal_as<std::string>(in23);

			// Checking for cancelation
			if (backgroundWorker5->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling function to create and send the PDW packet
			maxPowerSweep(file, IPB, IP, SIGGEN_ADDR, SPECAN_ADDR, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incFREQ, stdPath, stdAtten, stdAtten2, stdAtten3, stdAtten4, stdAtten5, swf1, swf2, swf3, backgroundWorker5, false);
			// Stopping background worker
			backgroundWorker5->CancelAsync();
		}
		private: System::Void backgroundWorker6_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in13 = textBox13->Text;
			std::string ipB = msclr::interop::marshal_as<std::string>(in13);
			const char* IPB = ipB.c_str();
			String ^ in24 = textBox24->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in24);
			const char* IP = ip.c_str();
			String ^ in26 = textBox26->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in26);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in25 = textBox25->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in25);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in31 = textBox31->Text;
			std::string initPOW = msclr::interop::marshal_as<std::string>(in31);
			String ^ in29 = textBox29->Text;
			std::string endPOW = msclr::interop::marshal_as<std::string>(in29);
			String ^ in28 = textBox28->Text;
			std::string incPOW = msclr::interop::marshal_as<std::string>(in28);
			String ^ in27 = textBox27->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in27);
			String ^ in37 = textBox37->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in37);
			String ^ in20 = textBox20->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in20);
			String ^ in18 = textBox18->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in18);
			String ^ in14 = textBox14->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in14);
			String ^ in12 = textBox12->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in12);
			String ^ in38 = textBox38->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in38);
			String ^ in40 = textBox40->Text;
			std::string initFREQ = msclr::interop::marshal_as<std::string>(in40);
			String ^ in39 = textBox39->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in39);
			String ^ in21 = textBox21->Text;
			std::string swf1 = msclr::interop::marshal_as<std::string>(in21);
			String ^ in22 = textBox22->Text;
			std::string swf2 = msclr::interop::marshal_as<std::string>(in22);
			String ^ in23 = textBox23->Text;
			std::string swf3 = msclr::interop::marshal_as<std::string>(in23);
			// Checking for cancelation
			if (backgroundWorker6->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling function to create and send the PDW packet
			maxPowerSweep(file, IPB, IP, SIGGEN_ADDR, SPECAN_ADDR, sweeps, rLev, scale, span, band, vidBand, initPOW, endPOW, incPOW, initFREQ, endFREQ, incFREQ, stdPath, stdAtten, stdAtten2, stdAtten3, stdAtten4, stdAtten5, swf1, swf2, swf3, backgroundWorker5, true);
			// Stopping background worker
			backgroundWorker6->CancelAsync();
		}
		private: System::Void backgroundWorker7_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			// Reading in values from textboxes
			String ^ in1 = textBox1->Text;
			std::string ip = msclr::interop::marshal_as<std::string>(in1);
			const char* IP = ip.c_str();
			String ^ in2 = textBox2->Text;
			std::string SIG = msclr::interop::marshal_as<std::string>(in2);
			const char* SIGGEN_ADDR = SIG.c_str();
			String ^ in3 = textBox3->Text;
			std::string SPEC = msclr::interop::marshal_as<std::string>(in3);
			const char* SPECAN_ADDR = SPEC.c_str();
			String ^ in4 = textBox4->Text;
			std::string POW = msclr::interop::marshal_as<std::string>(in4);
			String ^ in6 = textBox6->Text;
			std::string endFREQ = msclr::interop::marshal_as<std::string>(in6);
			String ^ in17 = textBox17->Text;
			std::string rLev = msclr::interop::marshal_as<std::string>(in17);
			String ^ in19 = textBox19->Text;
			std::string sweeps = msclr::interop::marshal_as<std::string>(in19);
			String ^ in30 = textBox30->Text;
			std::string scale = msclr::interop::marshal_as<std::string>(in30);
			String ^ in32 = textBox32->Text;
			std::string span = msclr::interop::marshal_as<std::string>(in32);
			String ^ in34 = textBox34->Text;
			std::string band = msclr::interop::marshal_as<std::string>(in34);
			String ^ in35 = textBox35->Text;
			std::string vidBand = msclr::interop::marshal_as<std::string>(in35);
			String ^ in36 = textBox36->Text;
			std::string file = msclr::interop::marshal_as<std::string>(in36);

			double iInc = convertInc(inc);
			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(16);
			streamObj << (frequF + iInc);
			std::string resumeFreq = streamObj.str();

			// Checking for cancelation
			if (backgroundWorker7->CancellationPending)
			{
				e->Cancel = true;
			}
			// Calling measure function to begin taking specified measurements for Freq
			if (eth == 1)
			{
				ethMeasureA(file, IP, SIGGEN_ADDR, SPECAN_ADDR, POW, resumeFreq, endFREQ, inc, rLev, sweeps, scale, span, band, vidBand, backgroundWorker7);
			}
			else if (eth == 0)
			{
				usbMeasureA(file, IP, SIGGEN_ADDR, SPECAN_ADDR, POW, resumeFreq, endFREQ, inc, rLev, sweeps, scale, span, band, vidBand, backgroundWorker7);
			}
			// Stopping background worker
			backgroundWorker7->CancelAsync();
		}
		private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label19->Text = "Done";
		}
		private: System::Void backgroundWorker2_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label30->Text = "Done";
		}
		private: System::Void backgroundWorker3_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label19->Text = "Done";
		}
		private: System::Void backgroundWorker4_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label30->Text = "Done";
		}
		private: System::Void backgroundWorker5_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label49->Text = "Done";
		}
		private: System::Void backgroundWorker6_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label49->Text = "Done";
		}
		private: System::Void backgroundWorker7_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			label19->Text = "Done";
			backgroundWorker7->CancelAsync();
			//button7->Enabled = true;
		}
		private: System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label41->Text = System::Convert::ToString(ampF) + " dBm";
			if (units == 0) { label42->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label42->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label42->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void backgroundWorker2_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label44->Text = System::Convert::ToString(ampAF) + " dBm";
			if (units == 0) { label43->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label43->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label43->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void backgroundWorker3_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label41->Text = System::Convert::ToString(ampF) + " dBm";
			if (units == 0) { label42->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label42->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label42->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void backgroundWorker4_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label44->Text = System::Convert::ToString(ampAF) + " dBm";
			if (units == 0) { label43->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label43->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label43->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void backgroundWorker5_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label69->Text = System::Convert::ToString(ampAF) + " dBm";
			if (units == 0) { label71->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label71->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label71->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void backgroundWorker6_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label69->Text = System::Convert::ToString(ampAF) + " dBm";
			if (units == 0) { label71->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label71->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label71->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void backgroundWorker7_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			label41->Text = System::Convert::ToString(ampF) + " dBm";
			if (units == 0) { label42->Text = System::Convert::ToString(frequF) + " kHz"; }
			else if (units == 1) { label42->Text = System::Convert::ToString(frequF) + " MHz"; }
			else if (units == 2) { label42->Text = System::Convert::ToString(frequF) + " GHz"; }
		}
		private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox1->SelectedIndex > -1)
			{
				if (comboBox1->SelectedItem == "Keysight")
				{
					textBox2->Text = "19";
				}
				else if (comboBox1->SelectedItem == "Anritsu")
				{
					textBox2->Text = "5";
				}
			}
			else
			{
				label37->Text = "Please Select Signal Generator";
			}
		}
		private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox3->SelectedIndex > -1)
			{
				if (comboBox2->SelectedItem == "kHz")
				{
					textBox5->Text = "20000000";
					textBox6->Text = "40000000";
					comboBox3->SelectedIndex = 0;
					units = 0;
				}
				else if (comboBox2->SelectedItem == "MHz")
				{
					textBox5->Text = "20000";
					textBox6->Text = "40000";
					comboBox3->SelectedIndex = 1;
					units = 1;
				}
				else if (comboBox2->SelectedItem == "GHz")
				{
					textBox5->Text = "20";
					textBox6->Text = "40";
					comboBox3->SelectedIndex = 2;
					units = 2;
				}
			}
		}
		private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox2->SelectedIndex > -1)
			{
				if (comboBox3->SelectedItem == "kHz")
				{
					textBox5->Text = "20000000";
					textBox6->Text = "40000000";
					comboBox2->SelectedIndex = 0;
					units = 0;
				}
				else if (comboBox3->SelectedItem == "MHz")
				{
					textBox5->Text = "20000";
					textBox6->Text = "40000";
					comboBox2->SelectedIndex = 1;
					units = 1;
				}
				else if (comboBox3->SelectedItem == "GHz")
				{
					textBox5->Text = "20";
					textBox6->Text = "40";
					comboBox2->SelectedIndex = 2;
					units = 2;
				}
			}
		}
		private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox4->SelectedIndex > -1)
			{
				comboBox8->SelectedIndex = 0;
				if (comboBox4->SelectedItem == "kHz")
				{
					textBox7->Text = "100000";
					unitsInc = 0;
				}
				else if (comboBox4->SelectedItem == "MHz")
				{
					textBox7->Text = "100";
					unitsInc = 1;
				}
				else if (comboBox4->SelectedItem == "GHz")
				{
					textBox7->Text = "0.1";
					unitsInc = 2;
				}
			}
		}
		private: System::Void comboBox5_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox6->SelectedIndex > -1)
			{
				if (comboBox5->SelectedItem == "kHz")
				{
					textBox11->Text = "20000000";
					textBox15->Text = "40000000";
					comboBox6->SelectedIndex = 0;
					units = 0;
				}
				else if (comboBox5->SelectedItem == "MHz")
				{
					textBox11->Text = "20000";
					textBox15->Text = "40000";
					comboBox6->SelectedIndex = 1;
					units = 1;
				}
				else if (comboBox5->SelectedItem == "GHz")
				{
					textBox11->Text = "20";
					textBox15->Text = "40";
					comboBox6->SelectedIndex = 2;
					units = 2;
				}
			}
		}
		private: System::Void comboBox6_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox5->SelectedIndex > -1)
			{
				if (comboBox6->SelectedItem == "kHz")
				{
					textBox11->Text = "20000000";
					textBox15->Text = "40000000";
					comboBox5->SelectedIndex = 0;
					units = 0;
				}
				else if (comboBox6->SelectedItem == "MHz")
				{
					textBox11->Text = "20000";
					textBox15->Text = "40000";
					comboBox5->SelectedIndex = 1;
					units = 1;
				}
				else if (comboBox6->SelectedItem == "GHz")
				{
					textBox11->Text = "20";
					textBox15->Text = "40";
					comboBox5->SelectedIndex = 2;
					units = 2;
				}
			}
		}
		private: System::Void comboBox7_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox7->SelectedIndex > -1)
			{
				comboBox9->SelectedIndex = 0;
				if (comboBox7->SelectedItem == "kHz")
				{
					textBox16->Text = "100000";
					unitsInc = 0;
				}
				else if (comboBox7->SelectedItem == "MHz")
				{
					textBox16->Text = "100";
					unitsInc = 1;
				}
				else if (comboBox7->SelectedItem == "GHz")
				{
					textBox16->Text = "0.1";
					unitsInc = 2;
				}
			}
		}
		private: System::Void comboBox8_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox8->SelectedIndex > -1)
			{
				if (comboBox8->SelectedItem == "Frequency Increment")
				{
					if (comboBox4->SelectedItem == "kHz")
					{
						textBox7->Text = "100000";
						unitsInc = 0;
					}
					else if (comboBox4->SelectedItem == "MHz")
					{
						textBox7->Text = "100";
						unitsInc = 1;
					}
					else if (comboBox4->SelectedItem == "GHz")
					{
						textBox7->Text = "0.1";
						unitsInc = 2;
					}
					else if (comboBox4->SelectedIndex == -1)
					{
						comboBox4->SelectedIndex = 0;
					}
				}
				else if (comboBox8->SelectedItem == "# of Measurements")
				{
					textBox7->Text = "10";
					comboBox4->SelectedIndex = -1;
				}
			}
		}
		private: System::Void comboBox9_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox9->SelectedIndex > -1)
			{
				if (comboBox9->SelectedItem == "Frequency Increment")
				{
					textBox16->Text = "100000";
					comboBox7->SelectedIndex = 0;
				}
				else if (comboBox9->SelectedItem == "# of Measurements")
				{
					textBox16->Text = "10";
					comboBox7->SelectedIndex = -1;
				}
			}
		}
		private: System::Void comboBox10_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox1->Checked)
			{
				checkBox1_CheckedChanged(sender, e);
			}
		}
		private: System::Void comboBox17_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox17->SelectedIndex > -1)
			{
				if (comboBox17->SelectedItem == "Frequency Increment")
				{
					if (comboBox18->SelectedItem == "kHz")
					{
						textBox33->Text = "100000";
						unitsInc = 0;
					}
					else if (comboBox18->SelectedItem == "MHz")
					{
						textBox33->Text = "100";
						unitsInc = 1;
					}
					else if (comboBox18->SelectedItem == "GHz")
					{
						textBox33->Text = "0.1";
						unitsInc = 2;
					}
					else if (comboBox18->SelectedIndex == -1)
					{
						comboBox18->SelectedIndex = 0;
					}
				}
				else if (comboBox17->SelectedItem == "# of Measurements")
				{
					textBox33->Text = "10";
					comboBox18->SelectedIndex = -1;
				}
			}
		}
		private: System::Void comboBox18_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox18->SelectedIndex > -1)
			{
				comboBox17->SelectedIndex = 0;
				if (comboBox18->SelectedItem == "kHz")
				{
					textBox33->Text = "100000";
					unitsInc = 0;
				}
				else if (comboBox18->SelectedItem == "MHz")
				{
					textBox33->Text = "100";
					unitsInc = 1;
				}
				else if (comboBox18->SelectedItem == "GHz")
				{
					textBox33->Text = "0.1";
					unitsInc = 2;
				}
			}
		}
		private: System::Void comboBox19_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox19->SelectedIndex > -1)
			{
				if (comboBox19->SelectedItem == "Hz")
				{
					textBox32->Text = "100000000";
					unitsSpecSpan = 0;
				}
				else if (comboBox19->SelectedItem == "kHz")
				{
					textBox32->Text = "100000";
					unitsSpecSpan = 1;
				}
				else if (comboBox19->SelectedItem == "MHz")
				{
					textBox32->Text = "100";
					unitsSpecSpan = 2;
				}
				else if (comboBox19->SelectedItem == "GHz")
				{
					textBox32->Text = "0.1";
					unitsSpecSpan = 3;
				}
			}
		}
		private: System::Void comboBox20_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox20->SelectedIndex > -1)
			{
				if (comboBox20->SelectedItem == "Hz")
				{
					textBox34->Text = "1000000";
					unitsSpecBand = 0;
				}
				else if (comboBox20->SelectedItem == "kHz")
				{
					textBox34->Text = "1000";
					unitsSpecBand = 1;
				}
				else if (comboBox20->SelectedItem == "MHz")
				{
					textBox34->Text = "1";
					unitsSpecBand = 2;
				}
				else if (comboBox20->SelectedItem == "GHz")
				{
					textBox34->Text = "0.001";
					unitsSpecBand = 3;
				}
			}
		}
		private: System::Void comboBox21_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox21->SelectedIndex > -1)
			{
				if (comboBox21->SelectedItem == "Keysight")
				{
					textBox26->Text = "19";
				}
				else if (comboBox21->SelectedItem == "Anritsu")
				{
					textBox26->Text = "5";
				}
			}
			else
			{
				label64->Text = "Please Select Signal Generator";
			}
		}
		private: System::Void comboBox22_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox22->SelectedIndex > -1)
			{
				if (comboBox22->SelectedItem == "Hz")
				{
					textBox35->Text = "1000000";
					unitsSpecVidBand = 0;
				}
				else if (comboBox22->SelectedItem == "kHz")
				{
					textBox35->Text = "1000";
					unitsSpecVidBand = 1;
				}
				else if (comboBox22->SelectedItem == "MHz")
				{
					textBox35->Text = "1";
					unitsSpecVidBand = 2;
				}
				else if (comboBox22->SelectedItem == "GHz")
				{
					textBox35->Text = "0.001";
					unitsSpecVidBand = 3;
				}
			}
		}
		private: System::Void comboBox23_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox23->SelectedIndex > -1)
			{
				if (comboBox23->SelectedItem == "Hz")
				{
					textBox14->Text = "50";
					unitsSpecVidBand = 0;
				}
				else if (comboBox23->SelectedItem == "kHz")
				{
					textBox14->Text = "1000";
					unitsSpecVidBand = 1;
				}
				else if (comboBox23->SelectedItem == "MHz")
				{
					textBox14->Text = "1";
					unitsSpecVidBand = 2;
				}
				else if (comboBox23->SelectedItem == "GHz")
				{
					textBox14->Text = "0.001";
					unitsSpecVidBand = 3;
				}
			}
		}
		private: System::Void comboBox24_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox24->SelectedIndex > -1)
			{
				if (comboBox24->SelectedItem == "Hz")
				{
					textBox18->Text = "100";
					unitsSpecBand = 0;
				}
				else if (comboBox24->SelectedItem == "kHz")
				{
					textBox18->Text = "1000";
					unitsSpecBand = 1;
				}
				else if (comboBox24->SelectedItem == "MHz")
				{
					textBox18->Text = "1";
					unitsSpecBand = 2;
				}
				else if (comboBox24->SelectedItem == "GHz")
				{
					textBox18->Text = "0.001";
					unitsSpecBand = 3;
				}
			}
		}
		private: System::Void comboBox25_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox25->SelectedIndex > -1)
			{
				if (comboBox25->SelectedItem == "Hz")
				{
					textBox20->Text = "1000";
					unitsSpecSpan = 0;
				}
				else if (comboBox25->SelectedItem == "kHz")
				{
					textBox20->Text = "100000";
					unitsSpecSpan = 1;
				}
				else if (comboBox25->SelectedItem == "MHz")
				{
					textBox20->Text = "100";
					unitsSpecSpan = 2;
				}
				else if (comboBox25->SelectedItem == "GHz")
				{
					textBox20->Text = "0.1";
					unitsSpecSpan = 3;
				}
			}
		}
		private: System::Void comboBox26_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox26->SelectedIndex > -1)
			{
				if (comboBox26->SelectedItem == "kHz")
				{
					textBox40->Text = "2000";
					textBox39->Text = "2000000";
					comboBox27->SelectedIndex = 0;
					units = 0;
				}
				else if (comboBox26->SelectedItem == "MHz")
				{
					textBox40->Text = "20";
					textBox39->Text = "2000";
					comboBox27->SelectedIndex = 1;
					units = 1;
				}
				else if (comboBox26->SelectedItem == "GHz")
				{
					textBox40->Text = "0.02";
					textBox39->Text = "2";
					comboBox27->SelectedIndex = 2;
					units = 2;
				}
			}

		}
		private: System::Void comboBox27_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (comboBox27->SelectedIndex > -1)
			{
				if (comboBox27->SelectedItem == "kHz")
				{
					textBox40->Text = "2000";
					textBox39->Text = "2000000";
					comboBox26->SelectedIndex = 0;
					units = 0;
				}
				else if (comboBox27->SelectedItem == "MHz")
				{
					textBox40->Text = "20";
					textBox39->Text = "2000";
					comboBox26->SelectedIndex = 1;
					units = 1;
				}
				else if (comboBox27->SelectedItem == "GHz")
				{
					textBox40->Text = "0.02";
					textBox39->Text = "2";
					comboBox26->SelectedIndex = 2;
					units = 2;
				}
			}
		}
		private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox1->Checked == false)
			{
				advanced = 0;
				label10->Visible = false;
				label21->Visible = false;
				label22->Visible = false;
				label23->Visible = false;
				label27->Visible = false;
				label28->Visible = false;
				label29->Visible = false;
				label47->Visible = false;
				label48->Visible = true;
				comboBox12->Visible = false;
				comboBox13->Visible = false;
				comboBox14->Visible = false;
				comboBox15->Visible = false;
				textBox21->Visible = false;
				textBox22->Visible = false;
				textBox23->Visible = false;
			}
			else
			{
				advanced = 1;
				label10->Visible = true;
				label21->Visible = true;
				label22->Visible = true;
				label23->Visible = true;
				label27->Visible = true;
				label28->Visible = true;
				label29->Visible = true;
				label47->Visible = true;
				label48->Visible = false;
				comboBox12->Visible = true;
				comboBox13->Visible = true;
				comboBox14->Visible = true;
				comboBox15->Visible = true;
				textBox21->Visible = true;
				textBox22->Visible = true;
				textBox23->Visible = true;
				label47->Text = "Filter 3";

				if (comboBox10->SelectedIndex > -1)
				{
					if (comboBox10->SelectedItem == "MB Main")
					{
						label47->Text = "Filter 3";
						textBox22->Visible = false;
						textBox23->Visible = false;
						label29->Visible = false;
						label47->Visible = false;
					}
					else if (comboBox10->SelectedItem == "MB AUX")
					{
						label47->Text = "Filter";
						textBox21->Visible = false;
						textBox22->Visible = false;
						label28->Visible = false;
						label29->Visible = false;

					}
					else if (comboBox10->SelectedItem == "HB")
					{
						textBox21->Visible = false;
						textBox22->Visible = false;
						textBox23->Visible = false;
						label28->Visible = false;
						label29->Visible = false;
						label47->Visible = false;
					}
				}
			}
		}
		private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox2->Checked == false)
			{
				ppeOFF = false;
			}
			else if (checkBox2->Checked == true)
			{
				ppeOFF = true;
			}
		}
		private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox3->Checked == true) {
				eth = 1;
			}
			else if (checkBox3->Checked == false)
			{
				eth = 2;
			}
		}
		private: System::Void checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox4->Checked == true) 
			{
				eth = 0;
			}
			else if (checkBox4->Checked == false)
			{
				eth = 2;
			}
		}
		private: System::Void checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox5->Checked == true) {
				eth2 = 0;
			}
			else if (checkBox5->Checked == false)
			{
				eth2 = 2;
			}
		}
		private: System::Void checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox6->Checked == true)
			{
				eth2 = 1;
			}
			else if (checkBox6->Checked == false)
			{
				eth2 = 2;
			}
		}
		private: System::Void checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (checkBox7->Checked == false)
			{
				avgOFF = false;
			}
			else if (checkBox7->Checked == true)
			{
				avgOFF = true;
			}
		}
	};
}