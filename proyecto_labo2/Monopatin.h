#pragma once

#include <iomanip>
#include <iostream>
#include <cstring>
#include "funciones.h"
#include "Pais.h"
#include "rlutil.h"

class Monopatin
{
private:
	int _idMonopatin;
	char _modelo[30];
	int _idPaisFabricacion;
	int _numSerie;
	bool _estado;

public:

	Monopatin(int idMonopatin = 0, const char* modelo = "", int numSerie = 0, bool estado = 0, int _idPais = 0);

	void setIdMonopatin(int idMonopatin);
	void setModelo(const char* modelo);
	void setidPaisFabricacion(int _idPaisFabricacion);
	void setNumSerie(int numSerie);
	void setEstado(bool estado);


	int getIdMonopatin();
	const char* getModelo();
	int  getidPaisFabricacion();
	int getNumSerie();
	bool getEstado();

	void cargarMonopatin();

	void mostrarMonopatin();
	
	void listar();
	void listarPorNumSerie();
	void listarPorIdMonopatin();
	void listarPorModeloMonopatin();


	bool leerDeDisco(int pos);
	bool grabarEnDisco();
	bool modificarEnDisco(int pos);
	
};

