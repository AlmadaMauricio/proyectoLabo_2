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

// Funciones globales Monopatin


int generarIdMonopatin();

int checkArchivoMonopatin();

int buscarMoopatinPorId(int);

void crear_nueva_Monopatin();
void eliminarMonopatin(int idMonopatin);
void modificar_monopatin();


void listadoGeneralMonopatin();

int buscarMonopatinPorId(int idMonopatin);
int buscarMonopatinPorNumSerie(int id);

void listadoDeMonopatinesPorNumDeSerie();
int buscarCantidadMonopatines();
void listados_Monopatines_Por_Modelo();
void copiarMonopatines(Monopatin* vMonopatin, int tam);
void ordernarVecPorNumSerie(Monopatin* vMonopatin, int tam);
void mostrarListadoMonopatines(Monopatin* vMonopatin, int tam);

int CantidadRegistroMonopatines();
void ordenarVector(Monopatin* vec, int tam);
void MostrarVector(Monopatin* vec, int tam);

void consultaMonopatinPorNumSerie();
void mostrarConsultaMonopatinPorNumSerie(Monopatin* vecMonopatin, int tamVec, int numSerie);

void consultaMonopatinPorIdMonopatin();
void mostrarConsultaMonopatinPorId(Monopatin* vecMonopatin, int tamVec, int numId);

void ModificarModelo(Monopatin aux, int pos);

void ModificarPais(Monopatin aux, int pos);

void ModificarNumSerie(Monopatin aux, int pos);

void consultaMonopatinesPorModelo();

void eliminar_monopatines_user(int id);
/*
//CANTIDAD DE MONOPATINES POR TIPO

void cantidad_monopatin_por_tipo();
void MostrarVectorCantMonopatines(int* vMonopatines, int tam);
*/



