#pragma once
#include "TxAltaEstudiant.h"
#include "Aux.h"

namespace GestioSessions {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Registrar
	/// </summary>
	public ref class Registrar : public System::Windows::Forms::Form
	{
	public:
		Registrar(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Registrar()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txt_pwd;
	private: System::Windows::Forms::TextBox^ txt_username;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_pwd2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btn_exit;
	private: System::Windows::Forms::Button^ btn_reg;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_pwd = (gcnew System::Windows::Forms::TextBox());
			this->txt_username = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_pwd2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->btn_reg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txt_pwd
			// 
			this->txt_pwd->BackColor = System::Drawing::SystemColors::ControlDark;
			this->txt_pwd->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_pwd->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_pwd->ForeColor = System::Drawing::SystemColors::Window;
			this->txt_pwd->Location = System::Drawing::Point(355, 256);
			this->txt_pwd->Name = L"txt_pwd";
			this->txt_pwd->Size = System::Drawing::Size(198, 22);
			this->txt_pwd->TabIndex = 9;
			this->txt_pwd->UseSystemPasswordChar = true;
			// 
			// txt_username
			// 
			this->txt_username->BackColor = System::Drawing::SystemColors::ControlDark;
			this->txt_username->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_username->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_username->ForeColor = System::Drawing::SystemColors::Window;
			this->txt_username->Location = System::Drawing::Point(355, 179);
			this->txt_username->Name = L"txt_username";
			this->txt_username->Size = System::Drawing::Size(198, 22);
			this->txt_username->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(350, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Contrasenya";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(350, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(37, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Usuari";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label1->Location = System::Drawing::Point(327, 54);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(259, 47);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Gestió Sessions";
			// 
			// txt_pwd2
			// 
			this->txt_pwd2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->txt_pwd2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_pwd2->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_pwd2->ForeColor = System::Drawing::SystemColors::Window;
			this->txt_pwd2->Location = System::Drawing::Point(355, 318);
			this->txt_pwd2->Name = L"txt_pwd2";
			this->txt_pwd2->Size = System::Drawing::Size(198, 22);
			this->txt_pwd2->TabIndex = 11;
			this->txt_pwd2->UseSystemPasswordChar = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(350, 290);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Confirmar contrasenya";
			// 
			// btn_exit
			// 
			this->btn_exit->BackColor = System::Drawing::Color::Gray;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exit->Location = System::Drawing::Point(479, 374);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(87, 34);
			this->btn_exit->TabIndex = 13;
			this->btn_exit->Text = L"Sortir";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &Registrar::btn_exit_Click);
			// 
			// btn_reg
			// 
			this->btn_reg->BackColor = System::Drawing::Color::White;
			this->btn_reg->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_reg->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_reg->ForeColor = System::Drawing::Color::Gray;
			this->btn_reg->Location = System::Drawing::Point(348, 374);
			this->btn_reg->Name = L"btn_reg";
			this->btn_reg->Size = System::Drawing::Size(125, 34);
			this->btn_reg->TabIndex = 12;
			this->btn_reg->Text = L"Registar-se";
			this->btn_reg->UseVisualStyleBackColor = false;
			this->btn_reg->Click += gcnew System::EventHandler(this, &Registrar::btn_reg_Click);
			// 
			// Registrar
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->ClientSize = System::Drawing::Size(898, 494);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_reg);
			this->Controls->Add(this->txt_pwd2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txt_pwd);
			this->Controls->Add(this->txt_username);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Registrar";
			this->Text = L"Registrar";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoadLogin(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btn_reg_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txt_pwd->Text != txt_pwd2->Text || txt_username->Text == "") {
			MessageBox::Show("Dades incorrectes");

			txt_username->Text = "";
			txt_pwd->Text = "";
			txt_pwd2->Text = "";
		}
		else {
			conversorString cs;
			TxAltaEstudiant tAS = TxAltaEstudiant(cs.convertirString(txt_username->Text), cs.convertirString(txt_pwd->Text));
			try {
				tAS.Executa();
			}
			catch(Exception^ ex){
				MessageBox::Show("Error al crear usuari: " + ex->Message);
			}
			LoadLogin(sender, e);
		}
	}
};
}
