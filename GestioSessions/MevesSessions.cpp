#include "pch.h"
#include "MevesSessions.h"
#include "ItemControlNI.h"
#include "TxVeureSessions.h"
#include "conversorString.h"

#include<vector>

using namespace GestioSessions;

void MevesSessions::LoadData() {
    try {
        // Crear una instancia de la transacci�n TxVeureSessions
        TxVeureSessions tx;
        vector<SessioData> sessions = tx.Executa();

        // Inicializar la posici�n Y para los controles
        int y = 10;

        conversorString cs;

        // Recorrer los resultados de la transacci�n
        for (const auto& sessio : sessions) {
            // Convertir los datos a System::String^
            String^ username = cs.convertirString(sessio.username.c_str());
            String^ tema = cs.convertirString(sessio.tema.c_str());
            String^ dia = cs.convertirString(sessio.dia.c_str());

            // Crear un nuevo control ItemControl y establecer sus datos
            ItemControlNI^ item = gcnew ItemControlNI();
            item->SetData(username, tema, dia);

            // Configurar la ubicaci�n del control y agregarlo al panel
            item->Location = System::Drawing::Point(10, y);
            item->Size = System::Drawing::Size(315, 30); // Asegurarse de que el tama�o sea adecuado
            list_items->Controls->Add(item);

            // Incrementar la posici�n Y para el pr�ximo control
            y += item->Height + 10;

            list_items->Invalidate();
            list_items->Update();
        }
    }
    catch (System::Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
}
