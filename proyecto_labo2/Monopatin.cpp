#include "Monopatin.h"

using namespace std;
using namespace rlutil;

Monopatin::Monopatin(int idMonopatin, const char* modelo, int numSerie, bool estado, int _idPais) {
	_idMonopatin = idMonopatin;
	strcpy(_modelo, modelo);
	_idPaisFabricacion = _idPais;
	_numSerie = numSerie;
	_estado = estado;
};

void Monopatin::setIdMonopatin(int idMonopatin) {
	_idMonopatin = idMonopatin;
};

void Monopatin::setModelo(const char* modelo) {
	strcpy(_modelo, modelo);
};

void Monopatin::setidPaisFabricacion(int idPaisFabricacion) {
	_idPaisFabricacion = idPaisFabricacion;
};

void Monopatin::setNumSerie(int numSerie) {
	_numSerie = numSerie;
};

void Monopatin::setEstado(bool estado) {
	_estado = estado;
};

int Monopatin::getIdMonopatin() {
	return _idMonopatin;
};

const char* Monopatin::getModelo() {
	return _modelo;
};

int Monopatin::getidPaisFabricacion() {
	return _idPaisFabricacion;
};

int Monopatin::getNumSerie() {
	return _numSerie;
};

bool Monopatin::getEstado() {
	return _estado;
};


