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
    private: System::Windows::Forms::Label^ lbl_usernameNI;
    private: System::Windows::Forms::Label^ lbl_TemaNI;
    private: System::Windows::Forms::Label^ lbl_diaNI;
    protected:

    private:





        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lbl_usernameNI = (gcnew System::Windows::Forms::Label());
            this->lbl_TemaNI = (gcnew System::Windows::Forms::Label());
            this->lbl_diaNI = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // lbl_usernameNI
            // 
            this->lbl_usernameNI->AutoSize = true;
            this->lbl_usernameNI->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_usernameNI->Location = System::Drawing::Point(8, 8);
            this->lbl_usernameNI->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_usernameNI->Name = L"lbl_usernameNI";
            this->lbl_usernameNI->Size = System::Drawing::Size(45, 19);
            this->lbl_usernameNI->TabIndex = 0;
            this->lbl_usernameNI->Text = L"label1";
            // 
            // lbl_TemaNI
            // 
            this->lbl_TemaNI->AutoSize = true;
            this->lbl_TemaNI->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_TemaNI->Location = System::Drawing::Point(90, 8);
            this->lbl_TemaNI->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_TemaNI->Name = L"lbl_TemaNI";
            this->lbl_TemaNI->Size = System::Drawing::Size(45, 19);
            this->lbl_TemaNI->TabIndex = 1;
            this->lbl_TemaNI->Text = L"label2";
            // 
            // lbl_diaNI
            // 
            this->lbl_diaNI->AutoSize = true;
            this->lbl_diaNI->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lbl_diaNI->Location = System::Drawing::Point(172, 8);
            this->lbl_diaNI->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->lbl_diaNI->Name = L"lbl_diaNI";
            this->lbl_diaNI->Size = System::Drawing::Size(45, 19);
            this->lbl_diaNI->TabIndex = 2;
            this->lbl_diaNI->Text = L"label3";
            // 
            // ItemControlNI
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->lbl_diaNI);
            this->Controls->Add(this->lbl_TemaNI);
            this->Controls->Add(this->lbl_usernameNI);
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
            lbl_usernameNI->Text = username;
            lbl_TemaNI->Text = tema;
            lbl_diaNI->Text = dia;
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
