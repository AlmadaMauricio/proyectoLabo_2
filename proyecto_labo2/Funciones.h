#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void instalacionArchivos();

bool login();
void todoAMayus(char*);


/// Menu
bool menuPrincipal();

//Estetica
void mostrarLogo();
void animacion();
void mostrarIntegrantes();
void mostrarLeyenda();

// Funciones
void menuUsers();
void menuListadosUsers();
void menuConsultasUsers();

void menuAdmins();
void menuListadosAdmin();

void menuRentas();
void menuListadosRentas();
void menuConsultasRentas();

void menuMonopatines();
void menuListadosMonopatines();
void menuConsultasMonopatines();

void menuInformes();

void menuConfiguracion();

bool exportarCSVUsers();
bool exportarCSVRentas();
bool exportarCSVMonopatines();



#endif // FUNCIONES_H_INCLUDED


