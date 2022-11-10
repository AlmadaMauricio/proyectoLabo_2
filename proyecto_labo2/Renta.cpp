#include "Renta.h"
#include "User.h"
#include "Monopatin.h"
#include "PagoRenta.h"
#include "ValorRenta.h"

using namespace std;
using namespace rlutil;

Renta::Renta(int idRenta, int idAdmin, int idUser, bool estado, int idMonopatin, int a, bool editable) {

	_idRenta = idRenta;
	_idAdministrador = idAdmin;
	_idUser = idUser;
	Fecha _FechaRenta;
	_idMonopatin = idMonopatin;
	_aprobado = a;
	_estado = estado;
	_editable = editable;
};

void Renta::setIdRenta(int idRenta) {
	_idRenta = idRenta;
};
void Renta::setIdAdministrador(int idAdmin) {
	_idAdministrador = idAdmin;
};
void Renta::setIdUser(int idUser) {
	_idUser = idUser;
};
void Renta::setIdMonopatin(int idMonopatin) {
	_idMonopatin = idMonopatin;
};
void Renta::setFechaRenta(Fecha FechaRenta) {
	_FechaRenta = FechaRenta;
}
void Renta::setAprobado(int a)
{
	_aprobado = a;
};
void Renta::setEditable(bool e)
{
	_editable = e;
}
void Renta::setEstado(bool estado) {
	_estado = estado;
};

int Renta::getIdRenta() { return _idRenta; }
int Renta::getIdAdministrador() { return _idAdministrador; }
int Renta::getIdUser() { return _idUser; }
int Renta::getIdMonopatin() { return _idMonopatin; }
Fecha Renta::getFechaRenta() { return _FechaRenta; }
int Renta::getAprobado() { return _aprobado; }
bool Renta::getEditable() { return _editable; }
bool Renta::getEstado() { return _estado; }

void Renta::cargarRenta() {

	int aux;
	int pos = 0;
	int posUser = 0;
	Monopatin monopatinRegistro;
	Fecha fechaRenta;
	Administrador admin;
	User user;
	bool verifica = false;

	do {
		cout << "Ingrese el ID del Administrador (0 para volver al menu anterior): ";
		cin >> aux;

		if (aux == 0)
		{
			return;
		}

		pos = buscarAdministradorPorID(aux);

		if (aux < 0)
		{
			cout << "ID inválido. Reintente por favor";
			anykey();
			cls();
			verifica = false;
		}
		else if (pos <= -1)
		{
			cout << "El ID ingresado no esta registrado. Reintente por favor." << endl;
			anykey();
			cls();
			verifica = false;
		}
		else
		{
			verifica = true;
		}

	} while (verifica == false);

	admin.leerDeDisco(pos);
	this->setIdAdministrador(admin.getIdAdmin());
	verifica = false;

	do {
		cout << "Ingrese el ID del User: ";
		cin >> aux;

		//posUser = buscarUserPorID(aux);

		if (aux < 0)
		{
			cout << "ID inválido. Reintente por favor";
			anykey();
			cls();
			verifica = false;
		}
		//else if (posUser < 0)
		{
			cout << "El ID de user no esta registrado o es incorrecto. Ingrese de nuevo por favor." << endl;
		}


	} while (verifica == false);

	this->setIdUser(aux);

	monopatinRegistro.cargarMonopatin();
	monopatinRegistro.setIdMonopatin(aux);

	this->setIdMonopatin(monopatinRegistro.getIdMonopatin());

	this->setFechaRenta(fechaRenta);

	this->setEstado(true);
	this->setAprobado(0);
	this->setIdRenta(generarIdRenta() + 1);
	this->setEditable(true);

	float valorRenta = getUltimoPrecioRenta();

	cout << endl << "Valor de la renta: $" << valorRenta << endl;

	int idPago = generarIDPagoRenta() + 1;

	PagoRenta pago(aux, idPago, valorRenta, admin.getIdAdmin());
	pago.grabarEnDisco();

	monopatinRegistro.grabarEnDisco();

	if (this->grabarEnDisco()) {
		cout << "La Renta " << this->getIdRenta() << " fue Ingresada correctamente.";
		cout << endl;
	}
	else {
		cout << "Hubo un Error al crear la Renta." << endl;
	}
}
void Renta::mostrarRenta() {

	Monopatin monopatin;
	int posMonopatin;

	if (this->getEstado())
	{
		cout << endl;
		cout << "RENTA N° " << this->getIdRenta();
		cout << endl;
		cout << "Id de Renta: " << this->getIdRenta();
		cout << endl;
		cout << "Id del User: " << this->getIdUser();
		cout << endl;
		cout << "Id del Administrador: " << this->getIdAdministrador();
		cout << endl;
	}

	//Falta mostrar el monopatin de la Renta
	posMonopatin = buscarMonopatinPorId(this->getIdMonopatin());
	if (posMonopatin == -1) {
		cout << "Hubo un error. No se encontró el Monopatin de La Renta: " << this->getIdRenta();
		cout << endl;
	}
	else {
		monopatin.leerDeDisco(posMonopatin);
		monopatin.mostrarMonopatin();
	}

	cout << endl;
	cout << "Fecha en la que se Registró la Renta: ";
	this->_FechaRenta.mostrarFecha();
	cout << endl;

};

bool Renta::grabarEnDisco() {

	FILE* rentaReg = fopen("rentas.dat", "ab");
	if (rentaReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}
	bool escribio = fwrite(this, sizeof(Renta), 1, rentaReg);
	fclose(rentaReg);

	return escribio;
}
bool Renta::leerDeDisco(int pos) {
	FILE* rentaReg = fopen("rentas.dat", "rb");
	if (rentaReg == NULL) {
		cout << "No se puede abrir el archivo.";
		return false;
	}
	fseek(rentaReg, pos * sizeof(Renta), SEEK_SET);
	bool leyo = fread(this, sizeof(Renta), 1, rentaReg);
	fclose(rentaReg);

	return leyo;
}
bool Renta::modificarEnDisco(int pos) {
	FILE* rentaReg = fopen("rentas.dat", "rb+");
	if (rentaReg == NULL) {
		cout << "No se puede abrir el archivo.";
		return false;
	}
	fseek(rentaReg, pos * sizeof(Renta), SEEK_SET);
	bool leyo = fwrite(this, sizeof(Renta), 1, rentaReg);
	fclose(rentaReg);
	return leyo;
}

bool Renta::grabarBackupRentas() {
	FILE* fReg = fopen("backupRentas.dat", "ab");

	if (fReg == NULL)
	{
		cout << "No se puede abrir el archivo.";
		system("PAUSE < null");
		return false;
	}

	int escribio = fwrite(this, sizeof(Renta), 1, fReg);

	fclose(fReg);

	return escribio;
}

int checkArchivoRenta() {

	FILE* rentaReg = fopen("rentas.dat", "rb");

	if (rentaReg == NULL)
	{
		rentaReg = fopen("rentas.dat", "wb");

		if (rentaReg == NULL)
		{
			cout << "Error al crear o leer archivo de Rentas." << endl;
			system("PAUSE > null");

			return -1;
		}
		else
		{
			fclose(rentaReg);
			cout << "Archivo de Rentas creado correctamente" << endl;

			return 0;
		}
	}
	else
	{
		cout << "Rentas: cargado OK" << endl;
	}

	fclose(rentaReg);
	return 1;
}

int generarIdRenta() {

	return buscarCantidadRentas();
}

void listadoRentas() {

	Renta renta;
	int p = 0;

	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(12) << "ID USER";
	cout << setw(12) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "------------------------------------------------------------------------------------------";
	cout << endl;

	while (renta.leerDeDisco(p++))
	{
		renta.listarRenta();
	}
}



void Renta::listarRenta() {

	if (this->getEstado()) {
		cout << left;
		cout << setw(15) << this->getIdRenta();
		cout << setw(20) << this->getIdAdministrador();
		cout << setw(10) << this->getIdUser();
		cout << setw(10) << this->getIdMonopatin();
		cout << setw(15);
		mostrarEstadoApRenta(this->getAprobado());
		this->getFechaRenta().mostrarFecha();

		cout << endl;
	}
}

void mostrarEstadoApRenta(int estadoAprobacion) {
	switch (estadoAprobacion)
	{
	case -1:
		cout << "DESAPROBADA";
		break;
	case 0:
		cout << "PENDIENTE";
		break;
	case 1:
		cout << "APROBADA";
		break;
	default:
		break;
	}
};

void cargarNuevaRenta() {

	Renta renta;

	renta.cargarRenta();

}

void listadoRentasAprobadas()
{
	Renta renta;
	int p = 0;

	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(12) << "ID USER";
	cout << setw(12) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "------------------------------------------------------------------------------------------";
	cout << endl;

	while (renta.leerDeDisco(p))
	{
		if (renta.getAprobado() == 1)
		{
			renta.listarRenta();
		}
		p++;
	}
}
void listadoRentasPendientes() {

	Renta renta;
	int p = 0;

	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(12) << "ID USER";
	cout << setw(12) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "------------------------------------------------------------------------------------------";
	cout << endl;

	while (renta.leerDeDisco(p++))
	{
		if (renta.getAprobado() == 0)
		{
			renta.listarRenta();
		}

	}
}
void listadoRentasDesaprobadas() {
	Renta renta;
	int p = 0;

	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(12) << "ID USER";
	cout << setw(12) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "------------------------------------------------------------------------------------------";
	cout << endl;

	while (renta.leerDeDisco(p))
	{
		if (renta.getAprobado() == -1)
		{
			renta.listarRenta();
		}
		p++;
	}
}

void listarRentasPorIdDesc() {
	/*
	int cantRentas = buscarCantidadRentas();

	if (cantRentas == 0) {
		cout << "No hay rentas registradas.";
		return;
	}

	Renta* Rentas = new Renta[cantRentas];

	if (rentas == NULL) { return; }

	copiarRentas(rentas, cantRentas);
	ordernarVecRentaPorIdDesc(rentas, cantRentas);
	mostrarRentas(rentas, cantRentas);

	delete rentas;
	*/
}

void ordernarVecRentaPorIdDesc(Renta* vRentas, int tam) {
	Renta aux;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vRentas[i].getIdRenta() < vRentas[j].getIdRenta()) {
				aux = vRentas[i];
				vRentas[i] = vRentas[j];
				vRentas[j] = aux;
			}
		}
	}
}
/*
void listarRentaPorFechaDesc() {
	int cantReg = buscarCantidadRentas();

	if (cantReg == 0) {
		cout << "No hay Rentas registradas";
		return;
	}

	Renta* vRentas;
	vRentas = new Renta[cantReg];
	if (vRentas == NULL) return;

	copiarRentas(vRentas, cantReg);
	ordernarVectorRentaPorFechaDesc(vRentas, cantReg);
	mostrarRentas(vRentas, cantReg);

	delete vRentas;

}
*/

void ordernarVectorRentaPorFechaDesc(Renta* vec, int tam) {
	Renta aux;

	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			if (vec[i].getFechaRenta() > vec[j].getFechaRenta()) {
				aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
}
void mostrarRentas(Renta* vRentas, int tam) {
	cout << " -- Listado de Rentas --" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(15) << "ID USER";
	cout << setw(15) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {
		vRentas[i].listarRenta();
	}
};

int buscarCantidadRentas() {

	FILE* p = fopen("rentas.dat", "rb");
	if (p == NULL) {
		return 0;
	}

	size_t bytes;
	int cant_reg;

	fseek(p, 0, SEEK_END);
	bytes = ftell(p);
	fclose(p);
	cant_reg = bytes / sizeof(Renta);
	return cant_reg;
}

void consultaRentasPorAnio() {

	int cantidadRentas = buscarCantidadRentas();
	if (cantidadRentas <= 0) {
		cout << "No hay Rentas Registradas.";
		return;
	}

	Renta* vecRentas;

	vecRentas = new Renta[cantidadRentas];

	if (vecRentas == NULL) { return; }

	for (int i = 0; i < cantidadRentas; i++) {
		vecRentas[i].leerDeDisco(i);
	}

	int anioConsulta = 0;

	cout << " - Listado de Rentas por Año - ";
	cout << endl;

	do {
		cout << "Año: ";
		cin >> anioConsulta;

		if (anioConsulta < 0 || anioConsulta < 1980)
		{
			cout << " El año ingresado es incorrecto, intente nuevamente" << endl;
		}

	} while (anioConsulta < 0 || anioConsulta < 1980);

	mostrarConsultasPorAnio(vecRentas, cantidadRentas, anioConsulta);

	delete vecRentas;
}

void mostrarConsultasPorAnio(Renta* vecRentas, int tam, int anioConsulta) {

	cls();
	cout << "   -- Rentas creadas en el año " << anioConsulta << " --" << endl << endl;
	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(10) << "ID USER";
	cout << setw(10) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {
		if (vecRentas[i].getFechaRenta().getAnio() == anioConsulta) {
			vecRentas[i].listarRenta();
		}
	}
}

void consultaRentasPorId() {

	Renta renta;
	int idRenta;

	cout << " - Consulta de Rentas por Id - ";
	cout << endl;
	cout << "Ingrese el Id: ";

	cin >> idRenta;
	cls();

	int posReg = buscarRentaPorId(idRenta) - 1;
	if (posReg >= 0) {

		cout << left;
		cout << setw(15) << "ID RENTA";
		cout << setw(20) << "ID ADMINISTRADOR";
		cout << setw(10) << "ID USER";
		cout << setw(10) << "ID MONOPATIN";
		cout << setw(15) << "ESTADO";
		cout << setw(15) << "FECHA CREACION" << endl;
		cout << "-------------------------------------------------------------------------------------" << endl;

		renta.leerDeDisco(posReg);
		renta.listarRenta();
	}
	else {
		cout << "No se encontró una Renta Registrada con ese Id.";
	}

}

int buscarRentaPorId(int id) {

	Renta renta;
	int pos = 0;

	while (renta.leerDeDisco(pos++))
	{
		if (renta.getIdRenta() == id)
		{
			if (renta.getEstado())
			{
				return pos;
			}
			else
			{
				return -1;
			}
		}
	}
	return -1;
}

void copiarRentas(Renta* vecRenta, int tam) {

	for (int i = 0; i < tam; i++) { vecRenta[i].leerDeDisco(i); }
}
/*
void consultaRentasPorFecha() {

	int cantidadRentas = buscarCantidadRentas();
	if (cantidadRentas <= 0) {
		cout << "No hay Rentas Registradas.";
		return;
	}

	Renta* vecRentas;

	vecRentas = new Renta[cantidadRentas];

	if (vecRentas == NULL) { return; }

	copiarRentas(vecRentas, cantidadRentas);

	Fecha fechaConsulta;

	cout << " - Consulta de Rentas por Fecha de Creación- ";
	cout << endl;
	cout << "Ingrese la Fecha: ";
	cout << endl;

	fechaConsulta.cargarFechaConsultas();
	cls();

	cout << "   -- Rentas creadas el ";
	fechaConsulta.mostrarFecha();
	cout << " --" << endl << endl;

	mostrarConsultasPorFecha(vecRentas, cantidadRentas, fechaConsulta);

	delete vecRentas;
}
*/

void mostrarConsultasPorFecha(Renta* vecRentas, int tam, Fecha fechaConsulta) {

	Fecha fechaRenta;
	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(10) << "ID USER";
	cout << setw(10) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {
		fechaRenta = vecRentas[i].getFechaRenta();
		if (fechaRenta == fechaConsulta) {
			vecRentas[i].listarRenta();
		}
	}
}

void bajaRenta(Renta aux, int pos)
{
	bool flag = false;
	char confirm;

	cout << "¿Desea dar de baja la Renta  N°" << aux.getIdRenta() << "? (S/N): ";
	cin >> confirm;

	confirm = (tolower(confirm));

	if (confirm == 's')
	{
		/// Elimina la renta en archivo monopatines
		eliminarMonopatin(aux.getIdMonopatin());
		aux.setEstado(false);
		aux.modificarEnDisco(pos);
		cout << endl << " -- La renta ha sido eliminada -- " << endl;
		anykey();
	}
	cls();
}

void modificar_renta()
{
	int opcion;
	char confirmarSalida;
	bool salir = false;
	bool flag = false;
	int idaux;
	int pos = 0;

	while (!salir) {

		Renta aux;

		do
		{
			cout << "Ingrese ID de renta a modificar (0 para volver al menu Solicitud): ";
			cin >> idaux;

			if (idaux == 0)
			{
				return;
			}

			pos = buscarRentaPorId(idaux) - 1;

			if (pos <= -1)
			{
				cout << "La Renta no se encuentra. Reintente por favor." << endl << endl;
				anykey();
				cls();
				flag = false;
			}
			else
			{
				aux.leerDeDisco(pos);

				if (aux.getEditable())
				{
					flag = true;
				}
				else
				{
					cout << endl << " -- La renta ya ha sido aprobada o desaprobada. No se puede editar --" << endl;
					anykey();
					cls();
					flag = false;
				}
			}

		} while (!flag);

		cls();

		aux.mostrarRenta();
		cout << endl;

		cout << "\tSeleccione opción" << endl;
		cout << "--------------------------" << endl;
		cout << "1 - Aprobar Renta " << endl;
		cout << "2 - Desaprobar Renta " << endl;
		cout << "3 - Eliminar registro de Renta" << endl;
		cout << "--------------------------" << endl;
		cout << "0 - Volver al menú Rentas" << endl << endl;

		cout << "Opción: ";
		cin >> opcion;

		cls();

		switch (opcion) {
		case 1:
			aprobarRenta(aux, pos);
			break;
		case 2:
			desaprobarRenta(aux, pos);
			break;
		case 3:
			bajaRenta(aux, pos);
			break;
		case 0:
			cout << "¿Volver al menu anterior? (S/N) ";
			cin >> confirmarSalida;

			salir = (tolower(confirmarSalida) == 's');
			break;
		}
	}
}

void aprobarRenta(Renta aux, int pos)
{
	bool flag = false;
	char confirm;

	cout << "¿Desea aprobar la Renta  N°" << aux.getIdRenta() << "? (S/N): ";
	cin >> confirm;

	confirm = (tolower(confirm));

	if (confirm == 's')
	{
		aux.setAprobado(1);
		aux.setEditable(false);
		aux.modificarEnDisco(pos);
		cout << endl << " -- La Renta ha sido aprobada -- " << endl;
		anykey();
	}
	cls();
}

void desaprobarRenta(Renta aux, int pos)
{
	bool flag = false;
	char confirm;

	cout << "¿Desea desaprobar la Renta  N°" << aux.getIdRenta() << "? (S/N): ";
	cin >> confirm;

	confirm = (tolower(confirm));

	if (confirm == 's')
	{
		aux.setAprobado(-1);
		aux.setEditable(false);
		aux.modificarEnDisco(pos);
		cout << endl << " -- La Renta ha sido desaprobada -- " << endl;
		anykey();
	}
	cls();
}

void cantidad_rentas_desap_por_anio()
{
	int anio;
	bool flag = false;

	do
	{
		cout << "Ingrese el año (0 para volver al menu anterior): ";
		cin >> anio;

		if (anio == 0)
		{
			return;
		}

		if (anio < 0)
		{
			cout << "Año invalido. Reingrese de nuevo por favor" << endl;
			anykey();
			cls();
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	int aux = rentasDesaprobadasPorAnio(anio);

	if (aux == 0)
	{
		cout << " -- No se desaprobaron rentas en el año " << anio << " --" << endl;
	}
	else if (aux == 1)
	{
		cout << " -- Se desaprobó " << aux << " renta en el año " << anio << " --" << endl;
	}
	else
	{
		cout << " -- Se desaprobaron " << aux << " rentas en el año " << anio << " --" << endl;
	}

}

int rentasDesaprobadasPorAnio(int anio)
{
	Renta renta;
	int p = 0;
	int cant = 0;

	while (renta.leerDeDisco(p++))
	{
		if (renta.getEstado())
		{
			if (renta.getAprobado() == -1 && renta.getFechaRenta().getAnio() == anio)
			{
				cant++;
			}
		}

	}

	return cant;

}

void cantidad_rentas_aprobadas_por_anio()
{
	int anio;
	bool flag = false;

	do
	{
		cout << "Ingrese el año (0 para volver al menu anterior): ";
		cin >> anio;

		if (anio == 0)
		{
			return;
		}

		if (anio < 0)
		{
			cout << "Año invalido. Reingrese de nuevo por favor" << endl;
			anykey();
			cls();
		}
		else
		{
			flag = true;
		}

	} while (!flag);

	int aux = rentasAprobadasPorAnio(anio);

	if (aux == 0)
	{
		cout << " -- No se aprobaron rentas en el año " << anio << " --" << endl;
	}
	else if (aux == 1)
	{
		cout << " -- Se aprobó " << aux << " renta en el año " << anio << " --" << endl;
	}
	else
	{
		cout << " -- Se aprobaron " << aux << " rentas en el año " << anio << " --" << endl;
	}

}

int rentasAprobadasPorAnio(int anio)
{
	Renta renta;
	int p = 0;
	int cant = 0;

	while (renta.leerDeDisco(p++))
	{
		if (renta.getEstado())
		{
			if (renta.getAprobado() == 1 && renta.getFechaRenta().getAnio() == anio)
			{
				cant++;
			}
		}

	}

	return cant;

}

void backup_rentas()
{
	Renta aux;
	int pos = 0;

	while (aux.leerDeDisco(pos++))
	{
		aux.grabarBackupRentas();
	}

	cout << "Archivo de backup de rentas 'backupRentas.dat' grabado correctamente" << endl;
}

void promedio_rentas_aprobadas()
{
	int cantRentas = buscarCantidadRentas();

	if (cantRentas == 0) {
		cout << "No se registran rentas al dia de la fecha" << endl;
		return;
	}

	Renta renta;
	int pos = 0;
	int cont = 0;
	int anio = 0;
	int totalRentas = 0;
	bool flag = false;

	while (renta.leerDeDisco(pos))
	{
		if (renta.getEstado())
		{
			totalRentas++;

			if (renta.getAprobado() == 1)
			{
				cont++;
			}
		}
		pos++;
	}

	double prom = (double)cont / cantRentas;

	cout << " -- El promedio de rentas aprobadas es de: " << setprecision(2) << prom << endl;

}

void promedio_rentas_desaprobadas()
{
	int cantRentas = buscarCantidadRentas();

	if (cantRentas == 0) {
		cout << "No se registran rentas al dia de la fecha" << endl;
		return;
	}

	Renta renta;
	int pos = 0;
	int cont = 0;
	int anio = 0;
	int totalRentas = 0;
	bool flag = false;

	while (renta.leerDeDisco(pos))
	{
		if (renta.getEstado())
		{
			totalRentas++;

			if (renta.getAprobado() == -1)
			{
				cont++;
			}
		}
		pos++;
	}

	double prom = (double)cont / cantRentas;

	cout << " -- El promedio de rentas desaprobadas es de: " << setprecision(2) << prom << endl;

}

void promedio_rentas_pendientes()
{
	int cantRentas = buscarCantidadRentas();

	if (cantRentas == 0) {
		cout << "No se registran rentas al dia de la fecha" << endl;
		return;
	}

	Renta renta;
	int pos = 0;
	int cont = 0;
	int anio = 0;
	int totalRentas = 0;
	bool flag = false;

	while (renta.leerDeDisco(pos))
	{
		if (renta.getEstado())
		{
			totalRentas++;

			if (renta.getAprobado() == 0)
			{
				cont++;
			}
		}
		pos++;
	}

	double prom = (double)cont / cantRentas;

	cout << " -- El promedio de rentas pendientes es de: " << setprecision(2) << prom << endl;

}

void eliminar_rentas_pendientes(int id)
{
	Renta renta;
	int pos = 0;

	while (renta.leerDeDisco(pos))
	{
		if (renta.getAprobado() == 0 && renta.getIdUser() == id)
		{
			renta.setEstado(false);
			renta.modificarEnDisco(pos);
		}
		pos++;
	}

}

void listadoRentasPorIdUSer()
{
	int ID = 0;
	int pos = 0;
	bool flag = false;
	User user;
	Renta renta;

	do {

		cls();
		cout << "Ingrese el ID de user a consultar (0 para volver al menu anterior): ";
		cin >> ID;


		if (ID == 0)
		{
			return;
		}

		if (ID < 1)
		{
			cout << endl << "ID invalido. Reintente por favor." << endl;
			flag = false;
			anykey();
		}
		else
		{
			//pos = BuscarIdArchivo(ID);

			if (pos < 0)
			{
				cout << endl << "El ID no fue encontrado en el archivo de users" << endl;
				flag = false;
				anykey();
			}

			else
			{
				flag = true;
			}
		}
	} while (!flag);

	mostrarRentasPorUser(ID);
}

void mostrarRentasPorUSer(int id)
{
	Renta renta;
	int p = 0;

	cout << left;
	cout << setw(15) << "ID RENTA";
	cout << setw(20) << "ID ADMINISTRADOR";
	cout << setw(12) << "ID USER";
	cout << setw(12) << "ID MONOPATIN";
	cout << setw(15) << "ESTADO";
	cout << setw(15) << "FECHA CREACION" << endl;
	cout << "------------------------------------------------------------------------------------------";
	cout << endl;

	while (renta.leerDeDisco(p))
	{
		if (renta.getIdUser() == id)
		{
			renta.listarRenta();
		}
		p++;
	}
}


