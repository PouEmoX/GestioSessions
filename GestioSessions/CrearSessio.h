#pragma once
#include "TxAltaSessio.h"

namespace GestioSessions {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de CrearSessio
	/// </summary>
	public ref class CrearSessio : public System::Windows::Forms::Form
	{
	public:
		CrearSessio(void)
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
		~CrearSessio()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txt_tema;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txt_dia;



	private: System::Windows::Forms::Button^ btn_creaSessio;


	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txt_tema = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_dia = (gcnew System::Windows::Forms::TextBox());
			this->btn_creaSessio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txt_tema
			// 
			this->txt_tema->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_tema->Location = System::Drawing::Point(193, 206);
			this->txt_tema->Name = L"txt_tema";
			this->txt_tema->Size = System::Drawing::Size(228, 30);
			this->txt_tema->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(211, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(237, 54);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Crear Sessió";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(187, 171);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 32);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Tema";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(187, 250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 32);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Dia";
			// 
			// txt_dia
			// 
			this->txt_dia->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_dia->Location = System::Drawing::Point(193, 285);
			this->txt_dia->Name = L"txt_dia";
			this->txt_dia->Size = System::Drawing::Size(228, 30);
			this->txt_dia->TabIndex = 6;
			// 
			// btn_creaSessio
			// 
			this->btn_creaSessio->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_creaSessio->Location = System::Drawing::Point(250, 367);
			this->btn_creaSessio->Name = L"btn_creaSessio";
			this->btn_creaSessio->Size = System::Drawing::Size(132, 40);
			this->btn_creaSessio->TabIndex = 10;
			this->btn_creaSessio->Text = L"Crea";
			this->btn_creaSessio->UseVisualStyleBackColor = true;
			this->btn_creaSessio->Click += gcnew System::EventHandler(this, &CrearSessio::btn_creaSessio_Click);
			// 
			// CrearSessio
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(654, 455);
			this->Controls->Add(this->btn_creaSessio);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_dia);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_tema);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"CrearSessio";
			this->Text = L"CrearSessio";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	std::string convertirString(System::String^ strNet) {
		// Obtener la longitud del string .NET
		int length = strNet->Length;

		// Reservar memoria para el buffer de caracteres
		char* chars = new char[length + 1];

		// Copiar los caracteres desde el string .NET al buffer de caracteres
		for (int i = 0; i < length; ++i) {
			chars[i] = static_cast<char>(strNet[i]);
		}

		// Agregar el carácter nulo al final del buffer de caracteres
		chars[length] = '\0';

		// Crear un std::string desde el buffer de caracteres
		std::string strStd(chars);

		// Liberar la memoria del buffer de caracteres
		delete[] chars;

		// Retornar el std::string convertido
		return strStd;
	}

	private: System::Void btn_creaSessio_Click(System::Object^ sender, System::EventArgs^ e) {
		TxAltaSessio tAS(convertirString(txt_tema->Text), convertirString(txt_dia->Text));

		try {
			tAS.Executa();
		}
		catch (Exception^ e) {
			MessageBox::Show("Error al crear la sessió " + e->Message);
		}
		finally {
			txt_tema->Text = "";
			txt_dia->Text = "";
		}
	}
};
}
