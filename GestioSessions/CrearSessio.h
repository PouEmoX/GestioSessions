#pragma once
#include "TxAltaSessio.h"
#include "Aux.h"

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
			Data->MinDate = DateTime::Now;
			Hora->Value = DateTime::Parse("00:00");
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
	private: System::Windows::Forms::Button^ btn_creaSessio;
	private: System::Windows::Forms::DateTimePicker^ Data;
	private: System::Windows::Forms::DateTimePicker^ Hora;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	protected:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->txt_tema = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btn_creaSessio = (gcnew System::Windows::Forms::Button());
			this->Data = (gcnew System::Windows::Forms::DateTimePicker());
			this->Hora = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txt_tema
			// 
			this->txt_tema->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_tema->Location = System::Drawing::Point(192, 170);
			this->txt_tema->Name = L"txt_tema";
			this->txt_tema->Size = System::Drawing::Size(228, 26);
			this->txt_tema->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(211, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 45);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Crear Sessió";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(187, 142);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 25);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Tema";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(187, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(40, 25);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Dia";
			// 
			// btn_creaSessio
			// 
			this->btn_creaSessio->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_creaSessio->Location = System::Drawing::Point(234, 362);
			this->btn_creaSessio->Name = L"btn_creaSessio";
			this->btn_creaSessio->Size = System::Drawing::Size(132, 40);
			this->btn_creaSessio->TabIndex = 10;
			this->btn_creaSessio->Text = L"Crea";
			this->btn_creaSessio->UseVisualStyleBackColor = true;
			this->btn_creaSessio->Click += gcnew System::EventHandler(this, &CrearSessio::btn_creaSessio_Click);
			// 
			// Data
			// 
			this->Data->Location = System::Drawing::Point(192, 227);
			this->Data->Name = L"Data";
			this->Data->Size = System::Drawing::Size(228, 33);
			this->Data->TabIndex = 11;
			// 
			// Hora
			// 
			this->Hora->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->Hora->Location = System::Drawing::Point(192, 291);
			this->Hora->Name = L"Hora";
			this->Hora->ShowUpDown = true;
			this->Hora->Size = System::Drawing::Size(228, 33);
			this->Hora->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(187, 263);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 25);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Hora";
			// 
			// CrearSessio
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(654, 455);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Hora);
			this->Controls->Add(this->Data);
			this->Controls->Add(this->btn_creaSessio);
			this->Controls->Add(this->label3);
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

	private: System::Void btn_creaSessio_Click(System::Object^ sender, System::EventArgs^ e) {
		conversorString cs;
		String^ diaFormatat = Data->Value.ToString("yyyy-MM-dd");
		String^ horaFormatada = Hora->Value.ToString("HH:mm");
		TxAltaSessio tAS(cs.convertirString(txt_tema->Text), cs.convertirString(diaFormatat + " " + horaFormatada));

		if (txt_tema->Text == "") {
			MessageBox::Show("Has de possar un tema");
		}
		else {
			try {
				tAS.Executa();
				MessageBox::Show("Sessió creada exitosament.");
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al crear la sessió: " + ex->Message);
			}
			finally {
				txt_tema->Text = "";
				Data->Value = DateTime::Now;
				Hora->Value = DateTime::Parse("00:00");
			}
		}
	}
	};
}
