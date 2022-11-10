#pragma once
#include "Fecha.h"

class PagoRenta
{
private:
	int _idUser;
	int _idPagoRenta;
	int _idAdmin;
	float _importe;
	Fecha _fechaPago;

public:

	PagoRenta(int id = 0, int idPago = 0, float importe = 0, int idAdmin = 0);

	//seters
	void setIdUser(int id);
	void setIdAdmin(int idAdmin);
	void setIdPagorenta(int idPago);
	void setImporte(float importe);
	void setFechaPago(Fecha fechaPago);

	//getters
	int getIdUser();
	int getIdAdmin();
	int getIdPago();
	float getImporte();
	Fecha getFechaPago();



	//Funciones de disco
	bool  grabarEnDisco();
	int   leerEnDisco(int pos);
	bool  modificarEnDisco(int pos);
};

int generarIDPagoRenta();

int checkArchivoPagosRenta();

