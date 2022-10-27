#include "Pais.h"
#include "rlutil.h"
using namespace rlutil;

using std::setprecision;
using namespace std;

///Setters

void Pais::setId(int idpais) {
	_IdPais = idpais;
}

void Pais::setNombre(const char* nombre) {
	strcpy(_Nombre, nombre);
}
void Pais::setEstado(bool estado) {
	_Estado = estado;
}


int Pais::getIdPais()
{
	return 0;
}

///Getters
const char* Pais::getNombre() {
	return _Nombre;
}

bool Pais::getEstado() {
	return _Estado;
}

void Pais::CargarPais()
{
}

void Pais::MostrarPais()
{
}

bool Pais::grabarEnDisco()
{
	return false;
}

bool Pais::leerDeDisco(int)
{
	return false;
}

void mostrarPais(int pais)
{
}
