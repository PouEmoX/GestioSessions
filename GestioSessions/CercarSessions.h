#include "ItemControl.h"
#include "CtrlApuntarSessio.h"
#include "Aux.h"

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

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->list_items = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            // 
            // list_items
            // 
            this->list_items->AutoScroll = true;
            this->list_items->Location = System::Drawing::Point(11, 67);
            this->list_items->Margin = System::Windows::Forms::Padding(2);
            this->list_items->Name = L"list_items";
            this->list_items->Size = System::Drawing::Size(600, 288);
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
            // CercarSessions
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->ClientSize = System::Drawing::Size(600, 366);
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
        void LoadData() {
            try {
                // Limpiar los controles actuales en el panel
                list_items->Controls->Clear();

                CtrlApuntarSessio controlador;
                vector<PassarelaSessio> sessions = controlador.visualitza();

                // Inicializar la posición Y para los controles
                int y = 10;

                conversorString cs;

                // Recorrer los resultados de la transacción
                for (PassarelaSessio session : sessions) {
                    // Convertir los datos a System::String^
                    String^ username = cs.convertirString(session.obteEstudiant());
                    String^ tema = cs.convertirString(session.obteTema());
                    String^ dia = cs.convertirString(session.obteDia());

                    // Crear un nuevo control ItemControl y establecer sus datos
                    ItemControl^ item = gcnew ItemControl();
                    item->SetData(username, tema, dia);

                    // Suscribirse al evento ItemActionEvent
                    item->ItemActionEvent += gcnew ItemControl::ItemActionEventHandler(this, &CercarSessions::OnItemAction);

                    // Configurar la ubicación del control y agregarlo al panel
                    item->Location = System::Drawing::Point(10, y);
                    item->Size = System::Drawing::Size(315, 30); // Ajustar el tamaño del control
                    item->Margin = System::Windows::Forms::Padding(0); // Eliminar el margen
                    list_items->Controls->Add(item);

                    // Incrementar la posición Y para el próximo control
                    y += item->Height + 10;
                }

                // No ajustar la altura del panel
                // Forzar el redibujo del panel
                list_items->Invalidate();
                list_items->Update();
            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Error: " + ex->Message);
            }
        }

        void OnItemAction(ItemControl^ sender, EventArgs^ e) {
            // Recargar los datos en el panel
            LoadData();
        }
    };
}
