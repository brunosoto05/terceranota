#include "owners.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Owner* Owner::cargarOwn(int& cant){
  ifstream file("Datos/owners.csv");
  if (!file.is_open()){
    cout <<"Error al intentar acceder al archivo";
    return nullptr;
  }

  cant = 0;
  Owner* owners = new Owner[75];
  string linea;

  while (getline(file,linea)){
    stringstream owner(linea);
    getline(owner, owners[cant].cedula, ',');
    getline(owner, owners[cant].nombre,',');
    getline(owner, owners[cant].apellido, ',');
    getline(owner, owners[cant].direccion, ',');
    getline(owner, owners[cant].perros, ',');

    cant++;
  }
  file.close();
  return owners;
}

void Owner::guardarOwn(Owner* owners, int cant) {
    ofstream archivo("Datos/owners.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de pets.\n";
        return;
    }

    for (int i = 0; i < cant; i++) {
        archivo << owners[i].cedula<<","<<owners[i].nombre << "," << owners[i].apellido << "," << owners[i].direccion<<","<<owners[i].perros<<"\n";
      }
    archivo.close();  
}

void Owner::agregarOwn(Owner*& owners, int& cantidad, const Owner& nuevoOwn) {

    ofstream file("Datos/owners.csv", ios::app);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo original.\n";
        return;
    }

    file << nuevoOwn.getCedula() << ","<<nuevoOwn.getNombre()<<","<<nuevoOwn.getApell()<<","
                    << nuevoOwn.getDireccion() << ","
                    << nuevoOwn.getPerros() << "\n";

    file.close();

        cout << "Owner agregado exitosamente.\n";

        Owner* temp = new Owner[cantidad + 1];
        for (int i = 0; i < cantidad; i++) {
            temp[i] = owners[i];
        }
        temp[cantidad] = nuevoOwn;

        delete[] owners;
        owners = temp;
        cantidad++;

}

void Owner::borrarOwn(Owner*& owners, int& cantidad, const string& cedula) {
    ofstream file("Datos/owners.csv", ios::trunc);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo original.\n";
        return;
    }

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (owners[i].cedula == cedula) {
            encontrado = true;
            continue; 
        }
        file << owners[i].cedula<<","<<owners[i].nombre<<","<<owners[i].apellido<<","<<owners[i].direccion<<","<<owners[i].perros<<"\n";
    }

    file.close();
      if (encontrado) {
            Owner* temp = new Owner[cantidad - 1];
            int index = 0;
            for (int i = 0; i < cantidad; i++) {
                if (owners[i].cedula == cedula) {
                    temp[index++] = owners[i];
                }
            }

            delete[] owners;
            owners = temp;
            cantidad--;
            cout << "Owner borrado.\n";
    } else {
        cout << "No se encontro un Owner.\n";
    }
}

void Owner::UpdateOwn(Owner* owners, int cantidad, const string& cedula) {
    bool encontrado = false;

    ofstream archivoOriginal("Datos/owners.csv", ios::trunc);
    if (!archivoOriginal.is_open()) {
        cout << "Error al abrir el archivo original.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        // Verificar si el repuesto coincide con el nombre, modelo de carro y año del carro
        if (owners[i].cedula == cedula) {
            // Pedir los nuevos datos
            cout<< "Ingrese los nuevos datos: \n";
            cout << "Ingrese la cedula: ";
            cin >> owners[i].cedula;
            cout << "Ingrese el nombre: ";
            cin >> owners[i].nombre;
            cout << "Ingrese el apellido: ";
            cin >> owners[i].apellido;
            cout << "Ingrese la direccion: ";
            cin.ignore();
            getline(cin, owners[i].direccion);
            cout<< "Ingrese la cantidad de perros que tiene: ";
            cin>>owners[i].perros;
            encontrado = true;
        }

        archivoOriginal <<owners[i].cedula<<","<< owners[i].nombre << "," << owners[i].apellido << "," << owners[i].direccion<<","<<owners[i].perros<< "\n";
    }

    archivoOriginal.close();

    // Confirmación del usuario para guardar los cambios
    if (encontrado) {
            cout << "Mascota modificada exitosamente.\n";
    } else {
        cout << "No se encontro una mascota con los criterios proporcionados.\n";
    }
}

void Owner::leerOwn(Owner* owners, int cantidad){
    cout << "Lista de owners:\n\n";
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << "."<<" Cedula: "<<owners[i].cedula<< ", Nombre: " << owners[i].nombre << ", Apellido: " << owners[i].apellido <<
        ", Direccion: "<<owners[i].direccion <<", Perros que posee: "<<owners[i].perros<<"\n"<<endl;
    }
}