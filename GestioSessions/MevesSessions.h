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




        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->list_items = (gcnew System::Windows::Forms::Panel());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(104, 21);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(242, 45);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Meves Sessions";
            // 
            // list_items
            // 
            this->list_items->AutoScroll = true;
            this->list_items->Location = System::Drawing::Point(9, 68);
            this->list_items->Margin = System::Windows::Forms::Padding(2);
            this->list_items->Name = L"list_items";
            this->list_items->Size = System::Drawing::Size(582, 288);
            this->list_items->TabIndex = 1;
            // 
            // MevesSessions
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(600, 366);
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
