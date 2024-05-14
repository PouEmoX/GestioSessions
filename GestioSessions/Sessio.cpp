#include "pch.h"
#include "Sessio.h"

Sessio::Sessio(string estudiant, string tema, string dia)
	:estudiant_creador(estudiant), tema(tema), dia(dia) {}

Sessio::Sessio()
	: estudiant_creador(""), tema(""), dia("") {}

string Sessio::get_estudiant() {
	return estudiant_creador;
}
string Sessio::get_tema() {
	return tema;
}
string Sessio::get_dia() {
	return dia;
}