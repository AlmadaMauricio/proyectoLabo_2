#pragma once
#include "User.h"
#include "rlutil.h"
#include "Monopatin.h"

using namespace std;
using namespace rlutil;

class MonopatinPorPais
{
private:
	int _idPais;
	int _cantidadMonopatines;
	bool _estado;

public:
	MonopatinPorPais();

	void setIdPais(int);
	void setCantidadMonopatines(int);
	void setEstado(bool);

	int getIdPais();
	int getCantidadMonopatines();
	bool getEstado();
};

int cantidadRegPaises();

void cantidad_de_monopatines_por_pais();

void inicializarVecPaises(MonopatinPorPais* vecPaises, int cantReg);
void ordenarVectorPaises(MonopatinPorPais* vecPaises, int cantReg);
int buscarPosPais(int idPais, MonopatinPorPais* vPaises, int cantReg);
void MostrarVectorPaises(MonopatinPorPais* vecPaises, int cantReg);
void buscarMonopatinPorPais(MonopatinPorPais* vecPaises, int cantReg);


