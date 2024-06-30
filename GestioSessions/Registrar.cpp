#include "pch.h"
#include "Registrar.h"

#include "Login.h" 

namespace GestioSessions {

	System::Void Registrar::LoadLogin(System::Object^ sender, System::EventArgs^ e) {
		CppCLRWinFormsProject::Login^ login = gcnew CppCLRWinFormsProject::Login();

		login->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
		login->TopLevel = false;
		login->AutoScroll = true;
		login->Dock = DockStyle::Fill;

		this->Controls->Clear();
		this->Controls->Add(login);

		login->Show();  
	}
}
