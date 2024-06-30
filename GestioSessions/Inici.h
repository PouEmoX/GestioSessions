#pragma once
#include "CrearSessio.h"
#include "MevesSessions.h"
#include "CercarSessions.h"

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

	protected:




	private: System::Windows::Forms::Panel^ panel2;



	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ btn_exit;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ btn_crear_sessio;

	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btn_meves_sessions;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btn_buscar_sessio;

	private: System::Windows::Forms::Panel^ display_panel;





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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->btn_crear_sessio = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->btn_meves_sessions = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_buscar_sessio = (gcnew System::Windows::Forms::Button());
			this->display_panel = (gcnew System::Windows::Forms::Panel());
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::MediumPurple;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(228, 68);
			this->panel2->TabIndex = 3;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->btn_exit);
			this->panel6->Controls->Add(this->panel4);
			this->panel6->Controls->Add(this->btn_crear_sessio);
			this->panel6->Controls->Add(this->panel3);
			this->panel6->Controls->Add(this->btn_meves_sessions);
			this->panel6->Controls->Add(this->panel1);
			this->panel6->Controls->Add(this->btn_buscar_sessio);
			this->panel6->Controls->Add(this->panel2);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel6->Location = System::Drawing::Point(0, 0);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(228, 494);
			this->panel6->TabIndex = 3;
			// 
			// btn_exit
			// 
			this->btn_exit->BackColor = System::Drawing::Color::MediumPurple;
			this->btn_exit->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exit->Location = System::Drawing::Point(0, 449);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(228, 44);
			this->btn_exit->TabIndex = 9;
			this->btn_exit->Text = L"Sortir";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &Inici::btn_exit_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::MediumPurple;
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 324);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(228, 125);
			this->panel4->TabIndex = 6;
			// 
			// btn_crear_sessio
			// 
			this->btn_crear_sessio->BackColor = System::Drawing::Color::MediumPurple;
			this->btn_crear_sessio->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn_crear_sessio->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_crear_sessio->Location = System::Drawing::Point(0, 284);
			this->btn_crear_sessio->Name = L"btn_crear_sessio";
			this->btn_crear_sessio->Size = System::Drawing::Size(228, 40);
			this->btn_crear_sessio->TabIndex = 8;
			this->btn_crear_sessio->Text = L"Crear Sessió";
			this->btn_crear_sessio->UseVisualStyleBackColor = false;
			this->btn_crear_sessio->Click += gcnew System::EventHandler(this, &Inici::btn_crear_sessio_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::MediumPurple;
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 216);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(228, 68);
			this->panel3->TabIndex = 5;
			// 
			// btn_meves_sessions
			// 
			this->btn_meves_sessions->BackColor = System::Drawing::Color::MediumPurple;
			this->btn_meves_sessions->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn_meves_sessions->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_meves_sessions->Location = System::Drawing::Point(0, 176);
			this->btn_meves_sessions->Name = L"btn_meves_sessions";
			this->btn_meves_sessions->Size = System::Drawing::Size(228, 40);
			this->btn_meves_sessions->TabIndex = 7;
			this->btn_meves_sessions->Text = L"Meves Sessions";
			this->btn_meves_sessions->UseVisualStyleBackColor = false;
			this->btn_meves_sessions->Click += gcnew System::EventHandler(this, &Inici::btn_meves_sessions_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::MediumPurple;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 108);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(228, 68);
			this->panel1->TabIndex = 4;
			// 
			// btn_buscar_sessio
			// 
			this->btn_buscar_sessio->BackColor = System::Drawing::Color::MediumPurple;
			this->btn_buscar_sessio->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn_buscar_sessio->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buscar_sessio->Location = System::Drawing::Point(0, 68);
			this->btn_buscar_sessio->Name = L"btn_buscar_sessio";
			this->btn_buscar_sessio->Size = System::Drawing::Size(228, 40);
			this->btn_buscar_sessio->TabIndex = 6;
			this->btn_buscar_sessio->Text = L"Buscar Sessions";
			this->btn_buscar_sessio->UseVisualStyleBackColor = false;
			this->btn_buscar_sessio->Click += gcnew System::EventHandler(this, &Inici::btn_buscar_sessio_Click);
			// 
			// display_panel
			// 
			this->display_panel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->display_panel->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->display_panel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->display_panel->Location = System::Drawing::Point(228, 0);
			this->display_panel->Name = L"display_panel";
			this->display_panel->Size = System::Drawing::Size(670, 494);
			this->display_panel->TabIndex = 5;
			// 
			// Inici
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(898, 494);
			this->Controls->Add(this->display_panel);
			this->Controls->Add(this->panel6);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inici";
			this->Text = L"Inici";
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);

		}


#pragma endregion

		template<class T>
		void OpenPanel(T FormSon)
		{
			//Comprovamos si n'hi ha dades al panel
			if (this->display_panel->Controls->Count > 0) {
				this->display_panel->Controls->RemoveAt(0);
			}

			FormSon->TopLevel = false;
			FormSon->Dock = DockStyle::Fill;
			this->display_panel->Controls->Add(FormSon);
			this->display_panel->Tag = FormSon;
			FormSon->Show();
		}

private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void btn_crear_sessio_Click(System::Object^ sender, System::EventArgs^ e) {
	this->OpenPanel(gcnew GestioSessions::CrearSessio);
}
private: System::Void btn_meves_sessions_Click(System::Object^ sender, System::EventArgs^ e) {
	this->OpenPanel(gcnew GestioSessions::MevesSessions);
}
private: System::Void btn_buscar_sessio_Click(System::Object^ sender, System::EventArgs^ e) {
	this->OpenPanel(gcnew GestioSessions::CercarSessions);
}
};
}
