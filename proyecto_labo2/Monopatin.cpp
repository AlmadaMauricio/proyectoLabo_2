#include <iostream>
#include "Monopatin.h"
#include <cstring>
#include <cstdio>

using namespace std;

Monopatin::Monopatin() {
    _idMonopatin = 0;
    strcpy(_modelo, "Sin nombre");
    _idPaisFabricacion = 0;
    _numSerie = 0;
    _estado = true;
}

void Monopatin::setId(int id) {
    _idMonopatin = id;
}

void Monopatin::setModelo(char* modelo) {
    strcpy(_modelo, modelo);
}

void Monopatin::setPais(int idPais) {
    _idPaisFabricacion = idPais;
}

void Monopatin::setNSerie(int numSerie) {
    _numSerie = numSerie;
}

void Monopatin::setEstado(bool estado) {
    _estado = estado;
}

int  Monopatin::getIdMonopatin() {
    return _idMonopatin;
}

char* Monopatin::getModelo() {
    return _modelo;
}

int  Monopatin::getIdPais() {
    return _idPaisFabricacion;
}

int  Monopatin::getNumSerie() {
    return _numSerie;
}

bool Monopatin::getEstado() {
    return _estado;
}

void Monopatin::Cargar() {
    bool aux;

    do {
        aux = false;
        cout << "ID MONOPATIN: ";
        cin >> _idMonopatin;
        if (validaIdMonopatin(_idMonopatin)) {
            aux = true;
            cout << endl << "ID EXISTENTE." << endl << endl;
        }
        if (_idMonopatin <= 0) {
            aux = true;
            cout << endl << "ID INVALIDO." << endl << endl;
        }
    } while (aux);


    cout << "INGRESE MODELO: ";
    cin.ignore();
    cin.getline(_modelo, 30);
    while (validaModelo(_modelo)) {
        cout << endl << "MODELO EXISTENTE." << endl << endl;
        cout << "INGRESE MODELO: ";
        cin.getline(_modelo, 30);
    }

    cout << "PAIS DE FABRICACION: ";
    cin >> _idPaisFabricacion;
    while (_idPaisFabricacion < 1 || _idPaisFabricacion > 3) {
        cout << endl << "PAIS INVALIDO." << endl << endl;
        cout << "PAIS DE FABRICACION: ";
        cin >> _idPaisFabricacion;
    }

    do {
        aux = false;
        cout << "NUMERO DE SERIE: ";
        cin >> _numSerie;
        if (validaNumSerie(_numSerie)) {
            aux = true;
            cout << endl << "NUMERO DE SERIE EXISTENTE." << endl << endl;
        }
        if (_idMonopatin <= 0) {
            aux = true;
            cout << endl << "NUMERO DE SERIE INVALIDO." << endl << endl;
        }
    } while (aux);

    cout << endl << endl;
    system("pause");
    system("cls");
}

void Monopatin::Mostrar() {
    if (_estado == true) {
        cout << "ID MONOPATIN          : " << _idMonopatin << endl;
        cout << "MODELO                : " << _modelo << endl;
        cout << "PAIS DE FABRICACION   : " << _idPaisFabricacion << endl;
        cout << "NUMERO DE SERIE       : " << _numSerie << endl << endl;
    }
}


bool Monopatin::GrabarEnDisco() {
    FILE* p;
    p = fopen("Monopatin.dat", "ab");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo ";
        return false;
    }

    bool ok = fwrite(this, sizeof(Monopatin), 1, p);
    if (ok == true) {
        cout << "Registro guardado" << endl;
    }
    else {
        cout << "No se guardo el registro" << endl;
    }
    fclose(p);
    return ok;
}

bool Monopatin::LeerDeDisco(int pos) {
    FILE* p;
    p = fopen("Monopatin.dat", "rb");
    if (p == NULL) {
        cout << "No se pudo abrir el archivo";
        return false;
    }

    fseek(p, sizeof(Monopatin) * pos, 0);
    bool leyo = fread(this, sizeof(Monopatin), 1, p);
    fclose(p);
    return leyo;
}


bool validaIdMonopatin(int id) {
    Monopatin m;
    int pos = 0;
    while (m.LeerDeDisco(pos++)) {
        if (m.getIdMonopatin() == id) return true;
    }
    return false;
}

bool validaModelo(char* modelo) {
    Monopatin m;
    int pos = 0;
    while (m.LeerDeDisco(pos++)) {
        if (strcmp(m.getModelo(), modelo) == 0) return true;
    }
    return false;
}

bool validaNumSerie(int ns) {
    Monopatin m;
    int pos = 0;
    while (m.LeerDeDisco(pos++)) {
        if (m.getNumSerie() == ns) return true;
    }
    return false;
}
