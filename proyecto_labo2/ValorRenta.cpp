#include "ValorRenta.h"


using namespace rlutil;

void ValorRenta::setValorRenta(int valor) {
	_valorRenta = valor;
}

void  ValorRenta::setFechaActualizacion(Fecha nuevaFecha) {
	_fechaActualizacion = nuevaFecha;
}

float ValorRenta::getValorRenta() {
	return _valorRenta;
}

Fecha ValorRenta::getFechaActualizacion() {
	return _fechaActualizacion;
}

//Funciones de disco
bool ValorRenta::grabarEnDisco() {

	FILE* fReg = fopen("preciosrenta.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(ValorRenta), 1, fReg);

	fclose(fReg);

	return escribio;
}

int ValorRenta::leerEnDisco(int pos) {

	FILE* fReg = fopen("preciosrenta.dat", "rb");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	fseek(fReg, pos * sizeof(ValorRenta), SEEK_SET);

	int escribio = fread(this, sizeof(ValorRenta), 1, fReg);

	fclose(fReg);

	return escribio;
}
void ValorRenta::mostrar()
{
	cout << left;
	cout << setw(1) << "$";
	cout << setw(10) << this->getValorRenta();
	this->getFechaActualizacion().mostrarFecha();
	cout << endl;

}
void ValorRenta::mostrarSimplificado()
{
	Fecha fechaActualizacion = this->getFechaActualizacion();

	cout << this->getValorRenta();
	fechaActualizacion.mostrarFecha();
}
int cantidadRegistrosPreciosRenta() {
	FILE* p = fopen("preciosrenta.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(ValorRenta);
	return cant_reg;
}

float getUltimoPrecioRenta()
{
	ValorRenta aux;

	int pos = cantidadRegistrosPreciosRenta() - 1;

	aux.leerEnDisco(pos);

	return aux.getValorRenta();

}
int checkArchivoPrecioRenta()
{
	FILE* fReg = fopen("preciosrenta.dat", "rb");

	if (fReg == NULL)
	{
		fReg = fopen("preciosrenta.dat", "wb");

		if (fReg == NULL)
		{
			cout << "Error al crear o leer archivo de precio de renta." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			float aux;
			cout << " -- Ingrese precio inicial de la renta: ";
			cin >> aux;

			modificar_importe_renta(aux);

			cout << "Archivo de valor de rentas creado correctamente con precio inicial: " << aux << endl << endl;

			fclose(fReg);
			return 0;
		}
	}
	else
	{
		cout << "Precio de renta: cargado OK" << endl;
	}

	fclose(fReg);

	return 1;

}

void modificar_precio_renta()
{
	float aux = 0;
	Fecha fechaActual;

	cls();
	cout << "Ingrese el precio nuevo: $";
	cin >> aux;

	modificar_importe_renta(aux);

	cls();
	cout << "\t -- Precio modificado correctamente --" << endl << endl;
	cout << "Precio: $" << aux << endl;
	cout << "Fecha: ";
	fechaActual.mostrarFecha();

	anykey();
}
void modificar_importe_renta(float nuevoPrecio) {
	ValorRenta aux;
	Fecha fechaActual;

	aux.setValorRenta(nuevoPrecio);
	aux.setFechaActualizacion(fechaActual);

	aux.grabarEnDisco();
}

void listar_historial_precios_renta()
{
	ValorRenta aux;
	int pos = 0;

	cout << left;
	cout << " -- Precios históricos de renta -- " << endl << endl;
	cout << setw(10) << "IMPORTE";
	cout << setw(1) << " ";
	cout << setw(10) << "FECHA ACTUALIZACION" << endl;
	cout << "-------------------------------" << endl;

	while (aux.leerEnDisco(pos++))
	{
		aux.mostrar();
	}
	anykey();
}
