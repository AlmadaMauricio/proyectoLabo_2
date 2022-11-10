#include "PagoRenta.h"

using namespace std;

PagoRenta::PagoRenta(int id, int idPago, float importe, int idAdmin) {

	_idUser = id;
	_idAdmin = idAdmin;
	_idPagoRenta = idPago;
	_importe = importe;
}

void PagoRenta::setIdUser(int id) {
	_idUser = id;
}
void PagoRenta::setIdPagorenta(int idPago) {
	_idPagoRenta = idPago;
}
void PagoRenta::setIdAdmin(int idAdmin)
{
	_idAdmin = idAdmin;
}
void PagoRenta::setImporte(float importe) {
	_importe = importe;
}
void PagoRenta::setFechaPago(Fecha fechaPago) {
	_fechaPago = fechaPago;
}

int PagoRenta::getIdUser() {
	return _idUser;
}
int PagoRenta::getIdPago() {
	return _idPagoRenta;
}
int PagoRenta::getIdAdmin()
{
	return _idAdmin;
}
float PagoRenta::getImporte() {
	return _importe;
}
Fecha PagoRenta::getFechaPago() {
	return _fechaPago;
}

bool  PagoRenta::grabarEnDisco() {
	FILE* fReg = fopen("pagorentas.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(PagoRenta), 1, fReg);

	fclose(fReg);

	return escribio;
}
int  PagoRenta::leerEnDisco(int pos) {
	FILE* fReg = fopen("pagorentas.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(PagoRenta), SEEK_SET);

	int escribio = fread(this, sizeof(PagoRenta), 1, fReg);

	fclose(fReg);

	return escribio;
}
bool  PagoRenta::modificarEnDisco(int pos) {
	FILE* fReg = fopen("pagorentas.dat", "rb+");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(PagoRenta), SEEK_SET);

	bool escribio = fwrite(this, sizeof(PagoRenta), 1, fReg);

	fclose(fReg);

	return escribio;
}

int checkArchivoPagosRenta()
{
	FILE* rentaReg = fopen("pagorentas.dat", "rb");

	if (rentaReg == NULL)
	{
		rentaReg = fopen("pagorentas.dat", "wb");

		if (rentaReg == NULL)
		{
			cout << "Error al crear o leer archivo de pagos de Rentas." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(rentaReg);
			cout << "Archivo de pagos de Rentas creado correctamente" << endl;

			return 0;
		}
	}
	else
	{
		cout << "Pagos de Rentas: cargado OK" << endl;
	}

	fclose(rentaReg);
	return 1;
}

int generarIDPagoRenta()
{
	PagoRenta aux;
	int id = 0;
	int pos = 0;

	while (aux.leerEnDisco(pos++)) {
		id = aux.getIdPago();
	};

	return id;
}
