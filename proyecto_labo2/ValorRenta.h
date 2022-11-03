#pragma once

#include <iomanip>
#include "rlutil.h"
#include "Fecha.h"

class ValorRenta
{
private:
	float _valorRenta;
	Fecha _fechaActualizacion;

public:
	void setValorRenta(int valor);
	void setFechaActualizacion(Fecha nuevaFecha);
	float getValorRenta();
	Fecha getFechaActualizacion();

	//Funciones de disco
	bool grabarEnDisco();
	int leerEnDisco(int pos);

	void mostrar();
	void mostrarSimplificado();
};

int cantidadRegistrosPreciosRenta();
float getUltimoPrecioRenta();

int checkArchivoPrecioRenta();

void modificar_precio_renta();

void modificar_importe_renta(float nuevoPrecio);

void listar_historial_precios_renta();

