#pragma once
#include "Aux.h"
#include "CtrlApuntarSessio.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace GestioSessions {

    public ref class ItemControlNI : public System::Windows::Forms::UserControl
    {
    public:
        ItemControlNI(void)
        {
            InitializeComponent();
        }

    protected:
        ~ItemControlNI()
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


        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lbl_username = (gcnew System::Windows::Forms::Label());
            this->lbl_Tema = (gcnew System::Windows::Forms::Label());
            this->lbl_dia = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // lbl_username
            // 
            this->lbl_username->AutoSize = true;
            this->lbl_username->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_username->Location = System::Drawing::Point(8, 8);
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
            this->lbl_Tema->Location = System::Drawing::Point(90, 8);
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
            this->lbl_dia->Location = System::Drawing::Point(172, 8);
            this->lbl_dia->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_dia->Name = L"lbl_dia";
            this->lbl_dia->Size = System::Drawing::Size(45, 19);
            this->lbl_dia->TabIndex = 2;
            this->lbl_dia->Text = L"label3";
            // 
            // ItemControlNI
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->lbl_dia);
            this->Controls->Add(this->lbl_Tema);
            this->Controls->Add(this->lbl_username);
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"ItemControlNI";
            this->Size = System::Drawing::Size(322, 34);
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    public:
        delegate void ItemActionEventHandler(ItemControlNI^ sender, EventArgs^ e);
        event ItemActionEventHandler^ ItemActionEvent;

    public:
        void SetData(String^ username, String^ tema, String^ dia)
        {
            lbl_username->Text = username;
            lbl_Tema->Text = tema;
            lbl_dia->Text = dia;
        }

        string convertirData(string data) {
            string dd = data.substr(0, 2);
            string mm = data.substr(3, 2);
            string yyyy = data.substr(6, 4);

            string dataConvertida = yyyy + "-" + mm + "-" + dd;

            return dataConvertida;
        }

#pragma endregion


    };
}
