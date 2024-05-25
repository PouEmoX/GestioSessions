#pragma once
#include<fstream>
#include<vcclr.h>

#include"Inici.h"
#include"Register.h"
#include "CrearSessio.h"
#include "AuthSys.h"

#include "TxLogin.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO; // Espacio de nombres para E/S de .NET

	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	private:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txt_username;
	private: System::Windows::Forms::TextBox^ txt_pwd;



	private: System::Windows::Forms::Button^ btn_login;
	private: System::Windows::Forms::Button^ btn_exit;

		   String^ connection = "";
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ btn_register;

		   MySqlConnection^ conn;

		void LoadConfig() {
			String^ configPath = "..\\config.txt";

			try {
				StreamReader^ reader = gcnew StreamReader(configPath);

				while (!reader->EndOfStream) {
					String^ line = reader->ReadLine();
					connection += line;
				}

				reader->Close();
			}
			catch (IOException^ e) {
				MessageBox::Show("Imposible acceder a la información de la base de datos: " + e->Message);
			}

			conn = gcnew MySqlConnection(connection);
		}

	public:
		Login(void)
		{
			InitializeComponent();
			LoadConfig();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_username = (gcnew System::Windows::Forms::TextBox());
			this->txt_pwd = (gcnew System::Windows::Forms::TextBox());
			this->btn_login = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btn_register = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(326, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 47);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Gestió Sessions";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(347, 148);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Usuari";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(347, 225);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(117, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Contrasenya";
			// 
			// txt_username
			// 
			this->txt_username->BackColor = System::Drawing::SystemColors::ControlDark;
			this->txt_username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_username->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_username->ForeColor = System::Drawing::SystemColors::Window;
			this->txt_username->Location = System::Drawing::Point(352, 176);
			this->txt_username->Name = L"txt_username";
			this->txt_username->Size = System::Drawing::Size(198, 22);
			this->txt_username->TabIndex = 3;
			// 
			// txt_pwd
			// 
			this->txt_pwd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->txt_pwd->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_pwd->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_pwd->ForeColor = System::Drawing::SystemColors::Window;
			this->txt_pwd->Location = System::Drawing::Point(352, 253);
			this->txt_pwd->Name = L"txt_pwd";
			this->txt_pwd->Size = System::Drawing::Size(198, 22);
			this->txt_pwd->TabIndex = 4;
			this->txt_pwd->UseSystemPasswordChar = true;
			// 
			// btn_login
			// 
			this->btn_login->BackColor = System::Drawing::Color::White;
			this->btn_login->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_login->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_login->ForeColor = System::Drawing::Color::Gray;
			this->btn_login->Location = System::Drawing::Point(352, 311);
			this->btn_login->Name = L"btn_login";
			this->btn_login->Size = System::Drawing::Size(105, 34);
			this->btn_login->TabIndex = 5;
			this->btn_login->Text = L"Entrar";
			this->btn_login->UseVisualStyleBackColor = false;
			this->btn_login->Click += gcnew System::EventHandler(this, &Login::btn_login_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->BackColor = System::Drawing::Color::Gray;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exit->Location = System::Drawing::Point(463, 311);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(87, 34);
			this->btn_exit->TabIndex = 6;
			this->btn_exit->Text = L"Sortir";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &Login::btn_exit_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(329, 375);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(154, 25);
			this->label4->TabIndex = 7;
			this->label4->Text = L"No tens compte\?";
			// 
			// btn_register
			// 
			this->btn_register->AutoSize = true;
			this->btn_register->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_register->Location = System::Drawing::Point(479, 375);
			this->btn_register->Name = L"btn_register";
			this->btn_register->Size = System::Drawing::Size(100, 25);
			this->btn_register->TabIndex = 8;
			this->btn_register->Text = L"Registra\'t";
			this->btn_register->Click += gcnew System::EventHandler(this, &Login::btn_register_Click);
			// 
			// Login
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(880, 493);
			this->Controls->Add(this->btn_register);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_login);
			this->Controls->Add(this->txt_pwd);
			this->Controls->Add(this->txt_username);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		std::string convertirString(System::String^ str) {
			if (str == nullptr) {
				return "";
			}

			IntPtr p = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
			std::string os = static_cast<const char*>(p.ToPointer());
			System::Runtime::InteropServices::Marshal::FreeHGlobal(p);
			return os;
		}

		System::String^ convertirString(const std::string& str) {
			return gcnew System::String(str.c_str());
		}


	private: System::Void btn_login_Click(System::Object^ sender, System::EventArgs^ e) {
		// Convertir los datos de entrada a std::string
		std::string username = convertirString(txt_username->Text);
		std::string password = convertirString(txt_pwd->Text);

		// Crear una instancia de TxLogin y ejecutarla
		TxLogin txLogin = TxLogin(username, password);

		try {
			if (txLogin.Executa()) {
				// Crear una instancia del nuevo formulario
				GestioSessions::Inici^ inici = gcnew GestioSessions::Inici();

				// Establecer el formulario padre del nuevo formulario como este formulario principal
				inici->TopLevel = false;
				inici->AutoScroll = true;
				inici->Dock = DockStyle::Fill;

				// Agregar el formulario al panel contenedor del formulario principal
				this->Controls->Clear(); // Limpia cualquier control previo en el panel
				this->Controls->Add(inici);

				// Mostrar el formulario
				inici->Show();
			}
			else {
				// Mostrar mensaje de error si el inicio de sesión falla
				MessageBox::Show("Usuario o contraseña incorrectos");
			}
		}
		catch (Exception^ ex) {
			// Mostrar mensaje de error si ocurre una excepción
			MessageBox::Show("Error al iniciar sesión: " + ex->Message);
		}
	}

	private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}

	private: System::Void btn_register_Click(System::Object^ sender, System::EventArgs^ e) {
		
		GestioSessions::Register^ reg = gcnew GestioSessions::Register();

		reg->TopLevel = false;
		reg->AutoScroll = true;
		reg->Dock = DockStyle::Fill;

		this->Hide();

		this->Controls->Clear();
		this->Controls->Add(reg);

		reg->Show();
		
	}
		   
};
}
