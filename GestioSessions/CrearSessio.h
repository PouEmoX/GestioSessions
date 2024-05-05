#pragma once


namespace GrupEstudi {

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
			this->ForeColor = System::Drawing::Color::Black;
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_tema;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txt_dia;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txt_hora;

	private: System::Windows::Forms::Button^ btn_crearSessio;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_tema = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_dia = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_hora = (gcnew System::Windows::Forms::TextBox());
			this->btn_crearSessio = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(209, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(278, 40);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Crear grup de estudi";
			// 
			// txt_tema
			// 
			this->txt_tema->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_tema->Location = System::Drawing::Point(255, 147);
			this->txt_tema->Name = L"txt_tema";
			this->txt_tema->Size = System::Drawing::Size(172, 29);
			this->txt_tema->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.75F));
			this->label2->Location = System::Drawing::Point(250, 106);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Tema de estudi";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.75F));
			this->label3->Location = System::Drawing::Point(250, 205);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Dia";
			// 
			// txt_dia
			// 
			this->txt_dia->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_dia->Location = System::Drawing::Point(255, 246);
			this->txt_dia->Name = L"txt_dia";
			this->txt_dia->Size = System::Drawing::Size(172, 29);
			this->txt_dia->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.75F));
			this->label4->Location = System::Drawing::Point(250, 299);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(55, 28);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Hora";
			// 
			// txt_hora
			// 
			this->txt_hora->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_hora->Location = System::Drawing::Point(255, 340);
			this->txt_hora->Name = L"txt_hora";
			this->txt_hora->Size = System::Drawing::Size(172, 29);
			this->txt_hora->TabIndex = 5;
			// 
			// btn_crearSessio
			// 
			this->btn_crearSessio->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_crearSessio->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12.25F));
			this->btn_crearSessio->Location = System::Drawing::Point(240, 423);
			this->btn_crearSessio->Name = L"btn_crearSessio";
			this->btn_crearSessio->Size = System::Drawing::Size(196, 31);
			this->btn_crearSessio->TabIndex = 7;
			this->btn_crearSessio->Text = L"Crear Sessió";
			this->btn_crearSessio->UseVisualStyleBackColor = true;
			// 
			// CrearSessio
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(670, 494);
			this->Controls->Add(this->btn_crearSessio);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txt_hora);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_dia);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_tema);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"CrearSessio";
			this->Text = L"CrearSessio";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


};
}
