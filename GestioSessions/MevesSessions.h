#pragma once
#include "ItemControl.h"
#include "Database.h"

namespace GestioSessions {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Resumen de MevesSessions
    /// </summary>
    public ref class MevesSessions : public System::Windows::Forms::Form
    {
    public:
        MevesSessions(void)
        {
            InitializeComponent();
            LoadData();
        }

    protected:
        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        ~MevesSessions()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Panel^ list_items;

    protected:

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
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->list_items = (gcnew System::Windows::Forms::Panel());
            this->panel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(183, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(297, 54);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Meves Sessions";
            // 
            // panel1
            // 
            this->panel1->Controls->Add(this->label1);
            this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(652, 78);
            this->panel1->TabIndex = 1;
            // 
            // list_items
            // 
            this->list_items->Dock = System::Windows::Forms::DockStyle::Fill;
            this->list_items->Location = System::Drawing::Point(0, 78);
            this->list_items->Name = L"list_items";
            this->list_items->Size = System::Drawing::Size(652, 369);
            this->list_items->TabIndex = 2;
            // 
            // MevesSessions
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(652, 447);
            this->Controls->Add(this->list_items);
            this->Controls->Add(this->panel1);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"MevesSessions";
            this->Text = L"MevesSessions";
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

    public:
        void LoadData();
    };
}
