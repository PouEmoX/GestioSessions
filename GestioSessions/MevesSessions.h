#pragma once
#include "ItemControl.h"

namespace GestioSessions {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MevesSessions : public System::Windows::Forms::Form
    {
    public:
        MevesSessions(void)
        {
            InitializeComponent();
            LoadData();
        }

    protected:
        ~MevesSessions()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Panel^ list_items;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label2;




        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->list_items = (gcnew System::Windows::Forms::Panel());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(188, 9);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(242, 45);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Meves Sessions";
            // 
            // list_items
            // 
            this->list_items->AutoScroll = true;
            this->list_items->Location = System::Drawing::Point(9, 82);
            this->list_items->Margin = System::Windows::Forms::Padding(2);
            this->list_items->Name = L"list_items";
            this->list_items->Size = System::Drawing::Size(625, 332);
            this->list_items->TabIndex = 1;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(361, 67);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(54, 13);
            this->label5->TabIndex = 10;
            this->label5->Text = L"Dia i Hora";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(180, 67);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(34, 13);
            this->label4->TabIndex = 9;
            this->label4->Text = L"Tema";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(26, 67);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(44, 13);
            this->label3->TabIndex = 8;
            this->label3->Text = L"Creador";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(11, 70);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(577, 13);
            this->label2->TabIndex = 7;
            this->label2->Text = L"_________________________________________________________________________________"
                L"______________";
            // 
            // MevesSessions
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(600, 366);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->list_items);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"MevesSessions";
            this->Text = L"MevesSessions";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

    private:
        void LoadData();
#pragma endregion
};
}
