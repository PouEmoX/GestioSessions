#pragma once

namespace GestioSessions {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inici
	/// </summary>
	public ref class Inici : public System::Windows::Forms::Form
	{
	public:
		Inici(void)
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
		~Inici()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button2;

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Plum;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(-1, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(214, 501);
			this->panel1->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Plum;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(214, 106);
			this->panel2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Dock = System::Windows::Forms::DockStyle::Top;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(0, 106);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 49);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Buscar Sessions";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Plum;
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 155);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(214, 67);
			this->panel3->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Dock = System::Windows::Forms::DockStyle::Top;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(0, 222);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(214, 49);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Meves Sessions";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Plum;
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 271);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(214, 67);
			this->panel4->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Dock = System::Windows::Forms::DockStyle::Top;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(0, 338);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(214, 49);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Crear Sessió";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Inici
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(898, 501);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inici";
			this->Text = L"Inici";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
