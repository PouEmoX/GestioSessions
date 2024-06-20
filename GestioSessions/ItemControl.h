#pragma once
#include "conversorString.h"
#include "CtrlApuntarSessio.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace GestioSessions {

    public ref class ItemControl : public System::Windows::Forms::UserControl
    {
    public:
        ItemControl(void)
        {
            InitializeComponent();
        }

    protected:
        ~ItemControl()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ lbl_username;
        System::Windows::Forms::Label^ lbl_Tema;
        System::Windows::Forms::Label^ lbl_dia;
        System::Windows::Forms::Button^ btn_action;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
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
            this->lbl_username->Location = System::Drawing::Point(18, 10);
            this->lbl_username->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_username->Name = L"lbl_username";
            this->lbl_username->Size = System::Drawing::Size(45, 19);
            this->lbl_username->TabIndex = 0;
            this->lbl_username->Text = L"label1";
            // 
            // lbl_Tema
            // 
            this->lbl_Tema->AutoSize = true;
            this->lbl_Tema->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_Tema->Location = System::Drawing::Point(118, 10);
            this->lbl_Tema->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_Tema->Name = L"lbl_Tema";
            this->lbl_Tema->Size = System::Drawing::Size(45, 19);
            this->lbl_Tema->TabIndex = 1;
            this->lbl_Tema->Text = L"label2";
            // 
            // lbl_dia
            // 
            this->lbl_dia->AutoSize = true;
            this->lbl_dia->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_dia->Location = System::Drawing::Point(212, 10);
            this->lbl_dia->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_dia->Name = L"lbl_dia";
            this->lbl_dia->Size = System::Drawing::Size(45, 19);
            this->lbl_dia->TabIndex = 2;
            this->lbl_dia->Text = L"label3";
            // 
            // btn_action
            // 
            this->btn_action->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_action->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->btn_action->Location = System::Drawing::Point(398, 8);
            this->btn_action->Margin = System::Windows::Forms::Padding(2);
            this->btn_action->Name = L"btn_action";
            this->btn_action->Size = System::Drawing::Size(86, 26);
            this->btn_action->TabIndex = 3;
            this->btn_action->Text = L"Apunta\'m";
            this->btn_action->UseVisualStyleBackColor = true;
            this->btn_action->Click += gcnew System::EventHandler(this, &ItemControl::btn_action_Click);
            // 
            // ItemControl
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->Controls->Add(this->btn_action);
            this->Controls->Add(this->lbl_dia);
            this->Controls->Add(this->lbl_Tema);
            this->Controls->Add(this->lbl_username);
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"ItemControl";
            this->Size = System::Drawing::Size(500, 42);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    public:
        delegate void ItemActionEventHandler(ItemControl^ sender, EventArgs^ e);
        event ItemActionEventHandler^ ItemActionEvent;

    public:
        void SetData(String^ username, String^ tema, String^ dia)
        {
            lbl_username->Text = username;
            lbl_Tema->Text = tema;
            lbl_dia->Text = dia;
        }

        string convertirData(string data) {
            // Asumimos que el formato de entrada es dd/mm/yyyy hh:mm:ss
            string dd = data.substr(0, 2);
            string mm = data.substr(3, 2);
            string yyyy = data.substr(6, 4);
            string time = data.substr(11); // Extrae la parte de la hora

            string dataConvertida = yyyy + "-" + mm + "-" + dd + " " + time;

            return dataConvertida;
        }

#pragma endregion
    private: System::Void btn_action_Click(System::Object^ sender, System::EventArgs^ e) {
        conversorString cs;
        CtrlApuntarSessio cAS;

        string fechaHoraConvertida = convertirData(cs.convertirString(lbl_dia->Text));

        cAS.apunta(cs.convertirString(lbl_username->Text), cs.convertirString(lbl_Tema->Text), fechaHoraConvertida);

        ItemActionEvent(this, EventArgs::Empty);
    }



    };
}