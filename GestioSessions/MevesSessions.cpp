#include "pch.h"
#include "MevesSessions.h"
#include "ItemControl.h"
#include "TxVeureSessions.h"
#include "Aux.h"

#include<vector>

using namespace GestioSessions;

void MevesSessions::LoadData() {
    try {
        // Crear una instancia de la transacci�n TxVeureSessions
        TxVeureSessions tx;
        vector<PassarelaSessio> sessions = tx.Executa();

        // Inicializar la posici�n Y para los controles
        int y = 10;

        conversorString cs;

        // Recorrer los resultados de la transacci�n
        for (PassarelaSessio session : sessions) {
            // Convertir los datos a System::String^
            String^ username = cs.convertirString(session.obteEstudiant());
            String^ tema = cs.convertirString(session.obteTema());
            String^ dia = cs.convertirString(session.obteDia());

            // Crear un nuevo control ItemControl y establecer sus datos
            ItemControl^ item = gcnew ItemControl();
            item->SetData(username, tema, dia);

            // Configurar la ubicaci�n del control y agregarlo al panel
            item->Location = System::Drawing::Point(10, y);
            item->Size = System::Drawing::Size(322, 20); // Asegurarse de que el tama�o sea adecuado
            list_items->Controls->Add(item);

            // Incrementar la posici�n Y para el pr�ximo control
            y += item->Height;
        }
    }
    catch (System::Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
}
