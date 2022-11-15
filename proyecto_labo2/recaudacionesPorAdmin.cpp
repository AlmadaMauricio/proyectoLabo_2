#include "RecaudacionesPorAdmin.h"
#include "User.h"

using namespace std;
using namespace rlutil;

RecaudacionesPorAdmin::RecaudacionesPorAdmin() {
	idAdmin = 0;
	recaudacionTotalRenta = 0;
}

void RecaudacionesPorAdmin::setIdAdmin(int _idAdmin) { idAdmin = _idAdmin; };
void  RecaudacionesPorAdmin::setRecaudacionTotalRentas(float _recaudacionRenta) {
	recaudacionTotalRenta = _recaudacionRenta;
};

int RecaudacionesPorAdmin::getIdAdmin() { return idAdmin; };
float RecaudacionesPorAdmin::getRecaudacionTotalRentas() { return recaudacionTotalRenta; };

void recaudacionPorAdmin() {

	int cantReg = buscarCantidadRegistrosAdmin();

	if (cantReg == 0) {
		cout << "No hay Administradores registrados";
		anykey();
		return;
	}

	RecaudacionesPorAdmin* vecRecaudacionAdmin;
	vecRecaudacionAdmin = new RecaudacionesPorAdmin[cantReg];
	if (vecRecaudacionAdmin == NULL) return;

	inicializarVecRecaudacionPorAdmin(vecRecaudacionAdmin, cantReg);
	buscarRecaudacionesPorAdmin(vecRecaudacionAdmin, cantReg);
	listarRecaudacionesPorAdmin(vecRecaudacionAdmin, cantReg);

	delete vecRecaudacionAdmin;

}

void inicializarVecRecaudacionPorAdmin(RecaudacionesPorAdmin* vecRecaudacion, int tam) {
	Administrador admin;

	for (int i = 0; i < tam; i++) {
		admin.leerDeDisco(i);

		vecRecaudacion[i].setIdAdmin(admin.getIdAdmin());
		vecRecaudacion[i].setRecaudacionTotalRentas(0);
	}
}

void buscarRecaudacionesPorAdmin(RecaudacionesPorAdmin* vecRecaudacion, int tam) {

	int pos = 0;
	int idAdmin;
	int posAdmin;
	float totalRecaudacion;

	PagoRenta renta;

	while (renta.leerEnDisco(pos++)) {
		idAdmin = renta.getIdAdmin();
		posAdmin = buscarPosAdmin(idAdmin, vecRecaudacion, tam);

		totalRecaudacion = vecRecaudacion[posAdmin].getRecaudacionTotalRentas() + renta.getImporte();
		vecRecaudacion[posAdmin].setRecaudacionTotalRentas(totalRecaudacion);
	}
}
int buscarPosAdmin(int idAdmin, RecaudacionesPorAdmin* vecRecaudacion, int tam) {
	for (int pos = 0; pos < tam; pos++) {
		if (vecRecaudacion[pos].getIdAdmin() == idAdmin) {
			return pos;
		}
	}
	return -1;
}
void listarRecaudacionesPorAdmin(RecaudacionesPorAdmin* vecRecaudacion, int tam) {
	cout << endl << "--------------------------------------";
	cout << endl << "   -- Recaudación Por Administrador --                " << endl;
	cout << "--------------------------------------" << endl;

	cout << left;
	cout << setw(11) << "ID ADMIN";
	cout << setw(1) << " ";
	cout << setw(15) << "RECAUDACION" << endl;
	cout << "--------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {

		if (vecRecaudacion[i].getIdAdmin() != 0)
		{
			cout << setw(12) << vecRecaudacion[i].getIdAdmin();
			cout << setw(1) << "$";
			cout << setw(15) << vecRecaudacion[i].getRecaudacionTotalRentas() << endl;
		}
	}
	cout << "--------------------------------------" << endl;

	anykey();


}

void recaudacionPorUser() {

	int cantReg = CantidadRegistrosUser();

	if (cantReg == 0) {
		cout << "No hay users registrados";
		anykey();
		return;
	}

	float* vecRecaudacionUser = new float[cantReg];
	if (vecRecaudacionUser == NULL) return;

	ponerCeroVectorRecaudacion(vecRecaudacionUser, cantReg);
	buscarRecaudacionesPorUser(vecRecaudacionUser);
	listarRecaudacionesPorUser(vecRecaudacionUser, cantReg);

	delete vecRecaudacionUser;
}
void ponerCeroVectorRecaudacion(float* vecRecaudacion, int tam) {

	for (int i = 0; i < tam; i++) {
		vecRecaudacion[i] = 0;
	}
}

void buscarRecaudacionesPorUser(float* vecRecaudacion) {

	int pos = 0;
	PagoRenta renta;

	while (renta.leerEnDisco(pos++)) {
		int idUser = renta.getIdUser();
		float recaudacion = renta.getImporte();
		vecRecaudacion[idUser - 1] += recaudacion;
	}

}
void listarRecaudacionesPorUser(float* vecRecaudacion, int tam) {

	cout << endl << "-----------------------------------";
	cout << endl << "   -- Recaudación Por User --                " << endl;
	cout << "-----------------------------------" << endl;

	cout << left;
	cout << setw(11) << "ID USER";
	cout << setw(1) << " ";
	cout << setw(15) << "RECAUDACION" << endl;
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < tam; i++) {

		cout << setw(12) << i + 1;
		cout << setw(1) << "$";
		cout << setw(15) << vecRecaudacion[i] << endl;
	}

	cout << "-----------------------------------" << endl;

	anykey();
}

void Informe_Recaudacion_Anual() {

	int anio = 0;
	const int Meses = 12;
	
	float* vDinamicoRentas;
	vDinamicoRentas = new float[Meses];
	if (vDinamicoRentas == NULL) return;

	
	PonerEnCeroVector(vDinamicoRentas, Meses);

	do {

		cout << "Ingrese el año para consultar su recaudacion (0 para volver al menú anterior): ";
		cin >> anio;

		if (anio == 0)
		{
			return;
		}

		if (anio < 0)
		{
			cout << "Año inválido. Reintente por favor.";
			anykey();
			cls();
		}

	} while (anio < 0);

	
	RecaudacionAnualRentas(anio, vDinamicoRentas, Meses);
	MostrarDetalleRecaudacionAnual(vDinamicoRentas, Meses);
	anykey();

}

void RecaudacionAnualRentas(int anio, float* vec, int tam) {
	PagoRenta aux;
	int pos = 0;

	while (aux.leerEnDisco(pos++)) {
		if (aux.getFechaPago().getAnio() == anio) {
			vec[aux.getFechaPago().getMes() - 1] += aux.getImporte();
		}
	}
}
void PonerEnCeroVector(float* vec, int tam) {
	for (int i = 0; i < tam; i++)
	{
		vec[i] = 0;
	}
}
void MostrarDetalleRecaudacionAnual(float* vec, int tam) {
	string meses[12] = { "Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre" };
	float totalAnio = 0;
	

	cls();
	cout << "------------------------------------------------";
	cout << endl << "\t  -- Recaudación Anual --                " << endl;
	cout << "------------------------------------------------" << endl << endl;
	cout << left;
	cout << setw(11) << "MES";
	cout << setw(1) << " ";
	cout << setw(15) << "REC POR RENTAS" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < tam; i++) {

		cout << setw(12) << meses[i];
		cout << setw(1) << "$";
		cout << setw(10) << (long)vec[i] << endl;
		totalAnio += vec[i];
		
	}

	cout << "-------------------------------------------------" << endl;
	cout << setw(12) << "Total año";
	cout << setw(1) << "$";
	cout << setw(15) << (long)totalAnio << endl;
	cout << "-------------------------------------------------" << endl;
	cout << setw(21) << "Total recaudado";
	cout << setw(1) << "$";
	cout << setw(7) << (long)totalAnio << endl;
	cout << "-------------------------------------------------" << endl;


}
