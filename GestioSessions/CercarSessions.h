#include "ItemControl.h"
#include "CtrlApuntarSessio.h"
#include "conversorString.h"

namespace GestioSessions {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class CercarSessions : public System::Windows::Forms::Form
    {
    public:
        CercarSessions(void)
        {
            InitializeComponent();
            LoadData();
        }

    protected:
        ~CercarSessions()
        {
            if (components)
            {
                delete components;
            }
        }
    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Panel^ list_items;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->list_items = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // list_items
            // 
            this->list_items->AutoScroll = true;
            this->list_items->Location = System::Drawing::Point(11, 91);
            this->list_items->Margin = System::Windows::Forms::Padding(2);
            this->list_items->Name = L"list_items";
            this->list_items->Size = System::Drawing::Size(585, 365);
            this->list_items->TabIndex = 2;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(192, 9);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(240, 45);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Cercar Sessions";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(8, 76);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(577, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"_________________________________________________________________________________"
                L"______________";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Location = System::Drawing::Point(23, 73);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(44, 13);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Creador";
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Location = System::Drawing::Point(127, 73);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(34, 13);
            this->label4->TabIndex = 5;
            this->label4->Text = L"Tema";
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Location = System::Drawing::Point(248, 73);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(54, 13);
            this->label5->TabIndex = 6;
            this->label5->Text = L"Dia i Hora";
            // 
            // CercarSessions
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(600, 366);
            this->Controls->Add(this->label5);
            this->Controls->Add(this->label4);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->list_items);
            this->Controls->Add(this->label1);
            this->DoubleBuffered = true;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"CercarSessions";
            this->Text = L"CercarSessions";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private:
        void CercarSessions::LoadData() {
            try {
                list_items->Controls->Clear();

                CtrlApuntarSessio controlador;
                vector<SessioInfo> sessions = controlador.visualitza();

                int y = 10;

                conversorString cs;

                for (const auto& sessio : sessions) {
                    String^ username = cs.convertirString(sessio.username.c_str());
                    String^ tema = cs.convertirString(sessio.tema.c_str());
                    String^ dia = cs.convertirString(sessio.dia.c_str());

                    ItemControl^ item = gcnew ItemControl();
                    item->SetData(username, tema, dia);

                    item->ItemActionEvent += gcnew ItemControl::ItemActionEventHandler(this, &CercarSessions::OnItemAction);

                    item->Location = System::Drawing::Point(10, y);
                    item->Size = System::Drawing::Size(500, 50); 
                    list_items->Controls->Add(item);

                    y += item->Height + 10; 
                }
            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }


        void CercarSessions::OnItemAction(ItemControl^ sender, EventArgs^ e) {
            LoadData();
        }


};
}
