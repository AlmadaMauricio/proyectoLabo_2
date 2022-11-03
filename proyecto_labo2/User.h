#pragma once
#include "Persona.h"


class User : public Persona
{
protected:
	Fecha _fechaIngreso;
	int _iduser;
	bool _estado;

public:
	User();
	///Setters
	void setIduser(int iduser);
	void setEstado(bool estado);
	void setFechaIngreso(Fecha fechaIng);


	///Getters
	Fecha getFechaIngreso();
	int getIduser();
	bool getEstado();


	// METODOS DE DISCO
	bool grabarEnDisco();
	bool grabarBackupUsers();
	bool leerDeDisco(int pos);
	bool leerBackupUsers(int pos);
	bool modificarEnDisco(int pos);

	void cargar();
	void mostrar();
	void mostrarSimplificado();

	void listar();

};



// Funciones globales User


int generarIDUser();
int buscarUserPorID(int);
bool buscarUserPorDNI(int dni);

int checkArchivoUsers();

void listado_general_users();

void cargar_nuevo_user();
void modificar_user();
void baja_user();

void ModificarDNIUser(User aux, int pos);
void ModificarNombreUser(User aux, int pos);
void ModificarApellidoUser(User aux, int pos);
void ModificarFechaNac(User aux, int pos);
void ModificarDomicilio(User aux, int pos);
void ModificarEmail(User aux, int pos);
void ModificarTelefono(User aux, int pos);

void listarUserAlfabeticamente();
void copiarUsers(User* vec, int tam);
void ordenarVector(User* vec, int tam);
void MostrarVector(User* vec, int tam);
int CantidadRegistrosUser();

void listarUserPorFecha();
void ordenarVectorPorFecha(User* vec, int tam);

void listadoSolicitudesPendientesPorUser();

void consulta_Por_Id();
int BuscarIdArchivo(int Id);

void consultaPorDni();
int BuscarDniArchivo(int dniconsulta);

void consulta_Por_Apellido();
int BuscarApellidoArchivo(const char* nombreconsulta);

void backup_users();

