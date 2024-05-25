#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace GestioSessions {

	/// <summary>
	/// Resumen de ItemControl
	/// </summary>
	public ref class ItemControl : public System::Windows::Forms::UserControl
	{
	public:
		ItemControl(void)
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
		~ItemControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbl_username;
	private: System::Windows::Forms::Label^ lbl_Tema;
	private: System::Windows::Forms::Label^ lbl_dia;
	private: System::Windows::Forms::Button^ btn_action;
	protected:

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
			this->lbl_username = (gcnew System::Windows::Forms::Label());
			this->lbl_Tema = (gcnew System::Windows::Forms::Label());
			this->lbl_dia = (gcnew System::Windows::Forms::Label());
			this->btn_action = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl_username
			// 
			this->lbl_username->AutoSize = true;
			this->lbl_username->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_username->Location = System::Drawing::Point(47, 23);
			this->lbl_username->Name = L"lbl_username";
			this->lbl_username->Size = System::Drawing::Size(55, 23);
			this->lbl_username->TabIndex = 0;
			this->lbl_username->Text = L"label1";
			// 
			// lbl_Tema
			// 
			this->lbl_Tema->AutoSize = true;
			this->lbl_Tema->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Tema->Location = System::Drawing::Point(212, 23);
			this->lbl_Tema->Name = L"lbl_Tema";
			this->lbl_Tema->Size = System::Drawing::Size(55, 23);
			this->lbl_Tema->TabIndex = 1;
			this->lbl_Tema->Text = L"label2";
			// 
			// lbl_dia
			// 
			this->lbl_dia->AutoSize = true;
			this->lbl_dia->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dia->Location = System::Drawing::Point(382, 23);
			this->lbl_dia->Name = L"lbl_dia";
			this->lbl_dia->Size = System::Drawing::Size(55, 23);
			this->lbl_dia->TabIndex = 2;
			this->lbl_dia->Text = L"label3";
			// 
			// btn_action
			// 
			this->btn_action->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_action->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_action->Location = System::Drawing::Point(537, 19);
			this->btn_action->Name = L"btn_action";
			this->btn_action->Size = System::Drawing::Size(80, 32);
			this->btn_action->TabIndex = 3;
			this->btn_action->Text = L"Action";
			this->btn_action->UseVisualStyleBackColor = true;
			// 
			// ItemControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->btn_action);
			this->Controls->Add(this->lbl_dia);
			this->Controls->Add(this->lbl_Tema);
			this->Controls->Add(this->lbl_username);
			this->Name = L"ItemControl";
			this->Size = System::Drawing::Size(650, 64);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	public:
		void SetData(String^ username, String^ tema, String^ dia)
		{
			lbl_username->Text = username;
			lbl_Tema->Text = tema;
			lbl_dia->Text = dia;
		}

#pragma endregion
	};
}
