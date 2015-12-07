#pragma once
#include <string>

namespace Controller {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for controllerForm
	/// </summary>
	public ref class controllerForm : public System::Windows::Forms::Form
	{
	public:
		controllerForm(void)
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
		~controllerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^  serialPortArduino;
	protected:

	private: System::Windows::Forms::TrackBar^  trackBarBase;
	private: System::Windows::Forms::TrackBar^  trackBarShoulder;
	private: System::Windows::Forms::TrackBar^  trackBarElbow;
	private: System::Windows::Forms::TrackBar^  trackBarClaw;

	private: System::Windows::Forms::Label^  labelBase;
	private: System::Windows::Forms::Label^  labelShoulder;
	private: System::Windows::Forms::Label^  labelElbow;
	private: System::Windows::Forms::Label^  labelClaw;
	private: System::Windows::Forms::Button^  buttonCOMPort;

	private: System::Windows::Forms::Label^  labelBaseVal;
	private: System::Windows::Forms::Label^  labelShoulderVal;
	private: System::Windows::Forms::Label^  labelElbowVal;
	private: System::Windows::Forms::Label^  labelClawVal;
	private: System::Windows::Forms::ComboBox^  comboBoxCOMPort;
	private: System::Windows::Forms::Button^  buttonRefreshCOMPorts;
	private: System::Windows::Forms::TrackBar^  trackBarY;
	private: System::Windows::Forms::TrackBar^  trackBarX;


	private: System::Windows::Forms::Label^  labelYVal;
	private: System::Windows::Forms::Label^  labelXVal;


	private: System::Windows::Forms::Label^  labelFR;
	private: System::Windows::Forms::Label^  labelLR;
	private: System::Windows::Forms::Button^  buttonStop;

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPortArduino = (gcnew System::IO::Ports::SerialPort(this->components));
			this->trackBarBase = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarShoulder = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarElbow = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarClaw = (gcnew System::Windows::Forms::TrackBar());
			this->labelBase = (gcnew System::Windows::Forms::Label());
			this->labelShoulder = (gcnew System::Windows::Forms::Label());
			this->labelElbow = (gcnew System::Windows::Forms::Label());
			this->labelClaw = (gcnew System::Windows::Forms::Label());
			this->buttonCOMPort = (gcnew System::Windows::Forms::Button());
			this->labelBaseVal = (gcnew System::Windows::Forms::Label());
			this->labelShoulderVal = (gcnew System::Windows::Forms::Label());
			this->labelElbowVal = (gcnew System::Windows::Forms::Label());
			this->labelClawVal = (gcnew System::Windows::Forms::Label());
			this->comboBoxCOMPort = (gcnew System::Windows::Forms::ComboBox());
			this->buttonRefreshCOMPorts = (gcnew System::Windows::Forms::Button());
			this->trackBarY = (gcnew System::Windows::Forms::TrackBar());
			this->trackBarX = (gcnew System::Windows::Forms::TrackBar());
			this->labelYVal = (gcnew System::Windows::Forms::Label());
			this->labelXVal = (gcnew System::Windows::Forms::Label());
			this->labelFR = (gcnew System::Windows::Forms::Label());
			this->labelLR = (gcnew System::Windows::Forms::Label());
			this->buttonStop = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarBase))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarShoulder))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarElbow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarClaw))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarX))->BeginInit();
			this->SuspendLayout();
			// 
			// trackBarBase
			// 
			this->trackBarBase->Enabled = false;
			this->trackBarBase->Location = System::Drawing::Point(12, 25);
			this->trackBarBase->Maximum = 180;
			this->trackBarBase->Name = L"trackBarBase";
			this->trackBarBase->Size = System::Drawing::Size(593, 45);
			this->trackBarBase->TabIndex = 0;
			this->trackBarBase->TickFrequency = 5;
			this->trackBarBase->Value = 90;
			this->trackBarBase->ValueChanged += gcnew System::EventHandler(this, &controllerForm::trackBarBase_ValueChanged);
			this->trackBarBase->MouseCaptureChanged += gcnew System::EventHandler(this, &controllerForm::trackBarBase_MouseCaptureChanged);
			// 
			// trackBarShoulder
			// 
			this->trackBarShoulder->Enabled = false;
			this->trackBarShoulder->Location = System::Drawing::Point(12, 89);
			this->trackBarShoulder->Maximum = 135;
			this->trackBarShoulder->Name = L"trackBarShoulder";
			this->trackBarShoulder->Size = System::Drawing::Size(593, 45);
			this->trackBarShoulder->TabIndex = 1;
			this->trackBarShoulder->TickFrequency = 5;
			this->trackBarShoulder->Value = 90;
			this->trackBarShoulder->ValueChanged += gcnew System::EventHandler(this, &controllerForm::trackBarShoulder_ValueChanged);
			this->trackBarShoulder->MouseCaptureChanged += gcnew System::EventHandler(this, &controllerForm::trackBarShoulder_MouseCaptureChanged);
			// 
			// trackBarElbow
			// 
			this->trackBarElbow->Enabled = false;
			this->trackBarElbow->Location = System::Drawing::Point(12, 152);
			this->trackBarElbow->Maximum = 180;
			this->trackBarElbow->Minimum = 30;
			this->trackBarElbow->Name = L"trackBarElbow";
			this->trackBarElbow->Size = System::Drawing::Size(593, 45);
			this->trackBarElbow->TabIndex = 2;
			this->trackBarElbow->TickFrequency = 5;
			this->trackBarElbow->Value = 120;
			this->trackBarElbow->ValueChanged += gcnew System::EventHandler(this, &controllerForm::trackBarElbow_ValueChanged);
			this->trackBarElbow->MouseCaptureChanged += gcnew System::EventHandler(this, &controllerForm::trackBarElbow_MouseCaptureChanged);
			// 
			// trackBarClaw
			// 
			this->trackBarClaw->Enabled = false;
			this->trackBarClaw->Location = System::Drawing::Point(12, 216);
			this->trackBarClaw->Maximum = 125;
			this->trackBarClaw->Name = L"trackBarClaw";
			this->trackBarClaw->Size = System::Drawing::Size(593, 45);
			this->trackBarClaw->TabIndex = 3;
			this->trackBarClaw->TickFrequency = 5;
			this->trackBarClaw->ValueChanged += gcnew System::EventHandler(this, &controllerForm::trackBarClaw_ValueChanged);
			this->trackBarClaw->MouseCaptureChanged += gcnew System::EventHandler(this, &controllerForm::trackBarClaw_MouseCaptureChanged);
			// 
			// labelBase
			// 
			this->labelBase->AutoSize = true;
			this->labelBase->Location = System::Drawing::Point(12, 9);
			this->labelBase->Name = L"labelBase";
			this->labelBase->Size = System::Drawing::Size(31, 13);
			this->labelBase->TabIndex = 4;
			this->labelBase->Text = L"Base";
			// 
			// labelShoulder
			// 
			this->labelShoulder->AutoSize = true;
			this->labelShoulder->Location = System::Drawing::Point(12, 73);
			this->labelShoulder->Name = L"labelShoulder";
			this->labelShoulder->Size = System::Drawing::Size(49, 13);
			this->labelShoulder->TabIndex = 5;
			this->labelShoulder->Text = L"Shoulder";
			// 
			// labelElbow
			// 
			this->labelElbow->AutoSize = true;
			this->labelElbow->Location = System::Drawing::Point(12, 136);
			this->labelElbow->Name = L"labelElbow";
			this->labelElbow->Size = System::Drawing::Size(36, 13);
			this->labelElbow->TabIndex = 6;
			this->labelElbow->Text = L"Elbow";
			// 
			// labelClaw
			// 
			this->labelClaw->AutoSize = true;
			this->labelClaw->Location = System::Drawing::Point(12, 200);
			this->labelClaw->Name = L"labelClaw";
			this->labelClaw->Size = System::Drawing::Size(30, 13);
			this->labelClaw->TabIndex = 7;
			this->labelClaw->Text = L"Claw";
			// 
			// buttonCOMPort
			// 
			this->buttonCOMPort->Location = System::Drawing::Point(197, 271);
			this->buttonCOMPort->Name = L"buttonCOMPort";
			this->buttonCOMPort->Size = System::Drawing::Size(201, 23);
			this->buttonCOMPort->TabIndex = 8;
			this->buttonCOMPort->Text = L"Set COM Port";
			this->buttonCOMPort->UseVisualStyleBackColor = true;
			this->buttonCOMPort->Click += gcnew System::EventHandler(this, &controllerForm::buttonCOMPort_Click);
			// 
			// labelBaseVal
			// 
			this->labelBaseVal->AutoSize = true;
			this->labelBaseVal->Location = System::Drawing::Point(611, 36);
			this->labelBaseVal->Name = L"labelBaseVal";
			this->labelBaseVal->Size = System::Drawing::Size(36, 13);
			this->labelBaseVal->TabIndex = 10;
			this->labelBaseVal->Text = L"labelB";
			// 
			// labelShoulderVal
			// 
			this->labelShoulderVal->AutoSize = true;
			this->labelShoulderVal->Location = System::Drawing::Point(611, 100);
			this->labelShoulderVal->Name = L"labelShoulderVal";
			this->labelShoulderVal->Size = System::Drawing::Size(36, 13);
			this->labelShoulderVal->TabIndex = 11;
			this->labelShoulderVal->Text = L"labelS";
			// 
			// labelElbowVal
			// 
			this->labelElbowVal->AutoSize = true;
			this->labelElbowVal->Location = System::Drawing::Point(611, 163);
			this->labelElbowVal->Name = L"labelElbowVal";
			this->labelElbowVal->Size = System::Drawing::Size(36, 13);
			this->labelElbowVal->TabIndex = 12;
			this->labelElbowVal->Text = L"labelE";
			// 
			// labelClawVal
			// 
			this->labelClawVal->AutoSize = true;
			this->labelClawVal->Location = System::Drawing::Point(611, 227);
			this->labelClawVal->Name = L"labelClawVal";
			this->labelClawVal->Size = System::Drawing::Size(36, 13);
			this->labelClawVal->TabIndex = 13;
			this->labelClawVal->Text = L"labelC";
			// 
			// comboBoxCOMPort
			// 
			this->comboBoxCOMPort->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCOMPort->FormattingEnabled = true;
			this->comboBoxCOMPort->Location = System::Drawing::Point(13, 272);
			this->comboBoxCOMPort->Name = L"comboBoxCOMPort";
			this->comboBoxCOMPort->Size = System::Drawing::Size(178, 21);
			this->comboBoxCOMPort->TabIndex = 14;
			// 
			// buttonRefreshCOMPorts
			// 
			this->buttonRefreshCOMPorts->Location = System::Drawing::Point(404, 271);
			this->buttonRefreshCOMPorts->Name = L"buttonRefreshCOMPorts";
			this->buttonRefreshCOMPorts->Size = System::Drawing::Size(201, 23);
			this->buttonRefreshCOMPorts->TabIndex = 15;
			this->buttonRefreshCOMPorts->Text = L"Refresh COM Ports";
			this->buttonRefreshCOMPorts->UseVisualStyleBackColor = true;
			this->buttonRefreshCOMPorts->Click += gcnew System::EventHandler(this, &controllerForm::buttonRefreshCOMPorts_Click);
			// 
			// trackBarY
			// 
			this->trackBarY->Enabled = false;
			this->trackBarY->Location = System::Drawing::Point(653, 25);
			this->trackBarY->Maximum = 254;
			this->trackBarY->Minimum = -254;
			this->trackBarY->Name = L"trackBarY";
			this->trackBarY->Size = System::Drawing::Size(593, 45);
			this->trackBarY->TabIndex = 16;
			this->trackBarY->TickFrequency = 5;
			this->trackBarY->ValueChanged += gcnew System::EventHandler(this, &controllerForm::trackBarY_ValueChanged);
			this->trackBarY->MouseCaptureChanged += gcnew System::EventHandler(this, &controllerForm::trackBarY_MouseCaptureChanged);
			// 
			// trackBarX
			// 
			this->trackBarX->Enabled = false;
			this->trackBarX->Location = System::Drawing::Point(653, 89);
			this->trackBarX->Maximum = 254;
			this->trackBarX->Minimum = -254;
			this->trackBarX->Name = L"trackBarX";
			this->trackBarX->Size = System::Drawing::Size(593, 45);
			this->trackBarX->TabIndex = 17;
			this->trackBarX->TickFrequency = 5;
			this->trackBarX->ValueChanged += gcnew System::EventHandler(this, &controllerForm::trackBarX_ValueChanged);
			this->trackBarX->MouseCaptureChanged += gcnew System::EventHandler(this, &controllerForm::trackBarX_MouseCaptureChanged);
			// 
			// labelYVal
			// 
			this->labelYVal->AutoSize = true;
			this->labelYVal->Location = System::Drawing::Point(1252, 36);
			this->labelYVal->Name = L"labelYVal";
			this->labelYVal->Size = System::Drawing::Size(36, 13);
			this->labelYVal->TabIndex = 18;
			this->labelYVal->Text = L"labelY";
			// 
			// labelXVal
			// 
			this->labelXVal->AutoSize = true;
			this->labelXVal->Location = System::Drawing::Point(1252, 100);
			this->labelXVal->Name = L"labelXVal";
			this->labelXVal->Size = System::Drawing::Size(36, 13);
			this->labelXVal->TabIndex = 19;
			this->labelXVal->Text = L"labelX";
			// 
			// labelFR
			// 
			this->labelFR->AutoSize = true;
			this->labelFR->Location = System::Drawing::Point(650, 9);
			this->labelFR->Name = L"labelFR";
			this->labelFR->Size = System::Drawing::Size(90, 13);
			this->labelFR->TabIndex = 20;
			this->labelFR->Text = L"Forward/Reverse";
			// 
			// labelLR
			// 
			this->labelLR->AutoSize = true;
			this->labelLR->Location = System::Drawing::Point(650, 73);
			this->labelLR->Name = L"labelLR";
			this->labelLR->Size = System::Drawing::Size(55, 13);
			this->labelLR->TabIndex = 21;
			this->labelLR->Text = L"Left/Right";
			// 
			// buttonStop
			// 
			this->buttonStop->Location = System::Drawing::Point(653, 140);
			this->buttonStop->Name = L"buttonStop";
			this->buttonStop->Size = System::Drawing::Size(593, 154);
			this->buttonStop->TabIndex = 22;
			this->buttonStop->Text = L"Stop";
			this->buttonStop->UseVisualStyleBackColor = true;
			this->buttonStop->Click += gcnew System::EventHandler(this, &controllerForm::buttonStop_Click);
			// 
			// controllerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1285, 306);
			this->Controls->Add(this->buttonStop);
			this->Controls->Add(this->labelLR);
			this->Controls->Add(this->labelFR);
			this->Controls->Add(this->labelXVal);
			this->Controls->Add(this->labelYVal);
			this->Controls->Add(this->trackBarX);
			this->Controls->Add(this->trackBarY);
			this->Controls->Add(this->buttonRefreshCOMPorts);
			this->Controls->Add(this->comboBoxCOMPort);
			this->Controls->Add(this->labelClawVal);
			this->Controls->Add(this->labelElbowVal);
			this->Controls->Add(this->labelShoulderVal);
			this->Controls->Add(this->labelBaseVal);
			this->Controls->Add(this->buttonCOMPort);
			this->Controls->Add(this->labelClaw);
			this->Controls->Add(this->labelElbow);
			this->Controls->Add(this->labelShoulder);
			this->Controls->Add(this->labelBase);
			this->Controls->Add(this->trackBarClaw);
			this->Controls->Add(this->trackBarElbow);
			this->Controls->Add(this->trackBarShoulder);
			this->Controls->Add(this->trackBarBase);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"controllerForm";
			this->Text = L"Arm Controller";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &controllerForm::controllerForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &controllerForm::controllerForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarBase))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarShoulder))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarElbow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarClaw))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBarX))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

array<String^>^ serialPorts = nullptr;	//Array to store available COM ports

//Form load
private: System::Void controllerForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//Set the text of each label to the current value of it's corresponding slider
	this->labelBaseVal->Text = String::Concat("", trackBarBase->Value);
	this->labelShoulderVal->Text = String::Concat("", trackBarShoulder->Value);
	this->labelElbowVal->Text = String::Concat("", trackBarElbow->Value);
	this->labelClawVal->Text = String::Concat("", trackBarClaw->Value);
	this->labelYVal->Text = String::Concat("", trackBarY->Value);
	this->labelXVal->Text = String::Concat("", trackBarX->Value);

	loadCOMPorts(); //Load the list of COM ports
}

//Update each label when its corresponding slider changes
private: System::Void trackBarBase_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->labelBaseVal->Text = String::Concat("", trackBarBase->Value);
}

private: System::Void trackBarShoulder_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->labelShoulderVal->Text = String::Concat("", trackBarShoulder->Value);
}

private: System::Void trackBarElbow_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->labelElbowVal->Text = String::Concat("", trackBarElbow->Value);
}

private: System::Void trackBarClaw_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->labelClawVal->Text = String::Concat("", trackBarClaw->Value);
}

private: System::Void trackBarY_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->labelYVal->Text = String::Concat("", trackBarY->Value);
}

private: System::Void trackBarX_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	this->labelXVal->Text = String::Concat("", trackBarX->Value);
}


//COM port button pressed
private: System::Void buttonCOMPort_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBoxCOMPort->Text != "") { //The user chose a COM port
		try {
			this->serialPortArduino->Close(); //Close any existing connections
			this->serialPortArduino->PortName = comboBoxCOMPort->Text; //Change the COM port
			this->serialPortArduino->Open(); //Open a new connection

			//Enable the sliders
			this->trackBarBase->Enabled = true;
			this->trackBarShoulder->Enabled = true;
			this->trackBarElbow->Enabled = true;
			this->trackBarClaw->Enabled = true;
			this->trackBarY->Enabled = true;
			this->trackBarX->Enabled = true;
		}
		catch (...) {
			this->serialPortArduino->Close(); //Close the connection
			MessageBox::Show("Unable to connect to the specified COM port.\n\nEnsure the device is connected and not already in use.", "Connection Failed", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); //Connection error message
		}
	}
}

//Form closing
private: System::Void controllerForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	this->serialPortArduino->Close(); //Close the connection
}

//Send the value of the slider to the Arduino when the slider is released
private: System::Void trackBarBase_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->serialPortArduino->Write(String::Concat("B", trackBarBase->Value));
	}
	catch (...) {
		connectionLost();
	}
}

private: System::Void trackBarShoulder_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->serialPortArduino->Write(String::Concat("S", trackBarShoulder->Value));
	}
	catch (...) {
		connectionLost();
	}
}

private: System::Void trackBarElbow_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->serialPortArduino->Write(String::Concat("E", trackBarElbow->Value));
	}
	catch (...) {
		connectionLost();
	}
}

private: System::Void trackBarClaw_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->serialPortArduino->Write(String::Concat("C", trackBarClaw->Value));
	}
	catch (...) {
		connectionLost();
	}
}

private: System::Void trackBarY_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->serialPortArduino->Write(String::Concat("Y", trackBarY->Value));
	}
	catch (...) {
		connectionLost();
	}
}

private: System::Void trackBarX_MouseCaptureChanged(System::Object^  sender, System::EventArgs^  e) {
	try {
		this->serialPortArduino->Write(String::Concat("X", trackBarX->Value));
	}
	catch (...) {
		connectionLost();
	}
}

//Refresh the list of COM Ports
private: System::Void buttonRefreshCOMPorts_Click(System::Object^  sender, System::EventArgs^  e) {
	loadCOMPorts(); //Load the list of COM ports
}

//Load the list of COM ports 
private: System::Void loadCOMPorts() {
	try {
		comboBoxCOMPort->Items->Clear(); //Clear the list of COM Ports
		this->serialPorts = System::IO::Ports::SerialPort::GetPortNames(); //Get an array of available serial ports and put it in the combo box
		this->comboBoxCOMPort->Items->AddRange(serialPorts); //Add the list of COM Ports to the combo box
	}
	catch (...) {
		MessageBox::Show("Unable to get COM ports.\n\nPlease try again.", "COM Ports", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); //COM ports error message
	}
}

private: System::Void connectionLost() {
	this->serialPortArduino->Close(); //Close the connection

	//Disable the sliders
	this->trackBarBase->Enabled = false;
	this->trackBarShoulder->Enabled = false;
	this->trackBarElbow->Enabled = false;
	this->trackBarClaw->Enabled = false;
	this->trackBarY->Enabled = false;
	this->trackBarX->Enabled = false;

	//Reset the slider values
	this->trackBarBase->Value = 90;
	this->trackBarShoulder->Value = 90;
	this->trackBarElbow->Value = 120;
	this->trackBarClaw->Value = 0;
	this->trackBarY->Value = 0;
	this->trackBarX->Value = 0;

	MessageBox::Show("Lost connection to the specified COM port.\n\nEnsure the device is connected and not already in use.", "Connection Lost", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk); //Connection lost error message
}

private: System::Void buttonStop_Click(System::Object^  sender, System::EventArgs^  e) {
	//Stop the robot
	this->serialPortArduino->Write("Y0");
	this->serialPortArduino->Write("X0");
	this->trackBarY->Value = 0;
	this->trackBarX->Value = 0;
	this->labelYVal->Text = String::Concat("", trackBarY->Value);
	this->labelXVal->Text = String::Concat("", trackBarX->Value);
}
};
}
