#pragma once


#include "PagoRenta.h"
#include "Administrador.h"
#include "rlutil.h"

class RecaudacionesPorAdmin
{
private:
	int idAdmin;
	float recaudacionTotalRenta;

public:
	RecaudacionesPorAdmin();

	void setIdAdmin(int _idAdmin);
	void  setRecaudacionTotalRentas(float _recaudacionRenta);

	int getIdAdmin();
	float getRecaudacionTotalRentas();

};

void recaudacionPorAdmin();
void inicializarVecRecaudacionPorAdmin(RecaudacionesPorAdmin* vecRecaudacion, int tam);
void buscarRecaudacionesPorAdmin(RecaudacionesPorAdmin* vecRecaudacion, int tam);
int buscarPosAdmin(int idAdmin, RecaudacionesPorAdmin* vecRecaudacion, int tam);
void listarRecaudacionesPorAdmin(RecaudacionesPorAdmin* vecRecaudacion, int tam);

void recaudacionPorUser();
void ponerCeroVectorRecaudacion(float* vecRecaudacion, int tam);
void buscarRecaudacionesPorUser(float* vecRecaudacion);
void listarRecaudacionesPorUser(float* vecRecaudacion, int tam);

void PonerEnCeroVector(float* vec, int tam);
void Informe_Recaudacion_Anual();
void RecaudacionAnualRentas(int anio, float* vec, int tam);
void MostrarDetalleRecaudacionAnual(float* vec, int tam);


