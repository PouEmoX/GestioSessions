#include "pch.h"
#include "MevesSessions.h"
#include "ItemControlNI.h"
#include "TxVeureSessions.h"
#include "conversorString.h"

#include<vector>

using namespace GestioSessions;

void MevesSessions::LoadData() {
    try {
        TxVeureSessions tx;
        vector<SessioData> sessions = tx.Executa();

        int y = 10;

        conversorString cs;

        for (const auto& sessio : sessions) {
            String^ username = cs.convertirString(sessio.username.c_str());
            String^ tema = cs.convertirString(sessio.tema.c_str());
            String^ dia = cs.convertirString(sessio.dia.c_str());

            ItemControlNI^ item = gcnew ItemControlNI();
            item->SetData(username, tema, dia);

            item->Location = System::Drawing::Point(10, y);
            item->Size = System::Drawing::Size(315, 30); 
            list_items->Controls->Add(item);

            y += item->Height + 10;

            list_items->Invalidate();
            list_items->Update();
        }
    }
    catch (System::Exception^ ex) {
        MessageBox::Show("Error: " + ex->Message);
    }
}
