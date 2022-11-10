#pragma once

#include <cstring>
#include <iostream>
#include <iomanip>
#include <iostream>
#include "rlutil.h"
#include "Fecha.h"
//#include "Monopatin.h"
//#include "User.h"
#include "administrador.h"
//#include "PagoRenta.h"
//#include "ValorRenta.h"


class Renta
{
private:
	int _idRenta, _idAdministrador, _idUser, _idMonopatin;
	int _aprobado;
	Fecha _FechaRenta;
	bool _editable;
	bool _estado;

public:

	//CONSTRUCTOR
	Renta(int idRenta = 0, int idAdmin = 0, int idUser = 0, bool estado = 0, int idMonopatin = 0, int aprobado = 0, bool editable = true);

	//SETTERS
	void setIdRenta(int idRenta);
	void setIdAdministrador(int idAdmin);
	void setIdUser(int idUser);
	void setIdMonopatin(int idMonopatin);
	void setFechaRenta(Fecha FechaRenta);
	void setAprobado(int a);
	void setEditable(bool e);
	void setEstado(bool estado);

	//GETTERS
	int getIdRenta();
	int getIdAdministrador();
	int getIdUser();
	int getIdMonopatin();
	Fecha getFechaRenta();
	int getAprobado();
	bool getEditable();
	bool getEstado();

	void cargarRenta();
	void mostrarRenta();

	bool grabarEnDisco();
	bool grabarBackupRentas();
	bool leerDeDisco(int pos);
	bool modificarEnDisco(int pos);

	void listarRenta();
};

int checkArchivoRenta();

void cargarNuevaRenta();
void modificar_renta();
void bajaRenta(Renta, int);
void aprobarRenta(Renta, int);
void desaprobarRenta(Renta, int);

int generarIdRenta();

void listadoRentas();
void mostrarEstadoApRenta(int estadoAprobacion);

void listadoRentasAprobadas();
void listadoRentasPendientes();
void listadoRentasDesaprobadas();

void RentasPendientesPorUser(int idUser);

void listarRentasPorIdDesc();
void ordernarVecRentaPorIdDesc(Renta* vRentas, int tam);

int buscarCantidadRentas();

void listarRentaPorFechaDesc();
void mostrarRentas(Renta* vRentas, int tam);

void ordernarVectorRentaPorFechaDesc(Renta* vec, int tam);

void consultaRentasPorAnio();
void mostrarConsultasPorAnio(Renta* vecRentas, int tam, int anioConsulta);

void consultaRentasPorFecha();
void mostrarConsultasPorFecha(Renta* vecRentas, int tam, Fecha fechaConsulta);

void consultaRentasPorId();
int buscarRentaPorId(int id);
void copiarRentas(Renta* vecRenta, int tam);

void cantidad_rentas_desap_por_anio();
int rentasDesaprobadasPorAnio(int anio);

void backup_rentas();

void promedio_rentas_aprobadas();
void promedio_rentas_desaprobadas();
void promedio_rentas_pendientes();

void eliminar_rentas_pendientes(int id);

void listadoRentaPorIdUser();

void mostrarRentasPorUser(int id);

//NUEVO REPORTE APROBADAS POR ANIO
void cantidad_rentas_aprobadas_por_anio();
int rentasAprobadasPorAnio(int anio);




