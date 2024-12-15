#include "pets.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Pet* Pet::cargarPets(int& cant){
  ifstream file("Datos/pets.csv");
  if (!file.is_open()){
    cout<<"Error al intentar acceder al archivo";
    return nullptr;
  }

  cant = 0;
  Pet* pets = new Pet[75];
  string linea;

  while (getline(file,linea)){
    stringstream pett(linea);
    getline(pett, pets[cant].nombre, ',');
    getline(pett, pets[cant].raza,',');
    getline(pett, pets[cant].nombreOwn, ',');

    cant++;
  }
  file.close();
  return pets;
}

void Pet::guardarPet(Pet* pets, int cant) {
    ofstream archivo("Datos/pets.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de pets.\n";
        return;
    }

    for (int i = 0; i < cant; i++) {
        archivo << pets[i].nombre << "," << pets[i].raza << "," << pets[i].nombreOwn<<"\n";
      }
    archivo.close();  
}

void Pet::agregarPet(Pet*& pets, int& cantidad, const Pet& nuevoPet) {

    ofstream file("Datos/pets.csv", ios::app);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo original.\n";
        return;
    }

  
    file << nuevoPet.getNombre() << ","
                    << nuevoPet.getRaza() << ","
                    << nuevoPet.getnombreOwn() << "\n";

    file.close();

        cout << "Pet agregado exitosamente.\n";

        Pet* temp = new Pet[cantidad + 1];
        for (int i = 0; i < cantidad; i++) {
            temp[i] = pets[i];
        }
        temp[cantidad] = nuevoPet;

        delete[] pets;
        pets = temp;
        cantidad++;

}

void Pet::borrarPet(Pet*& pets, int& cantidad, const string& nombre, const string& nombreOwn) {
    ofstream file("Datos/pets.csv", ios::trunc);
    if (!file.is_open()) {
        cout << "Error al abrir el archivo original.\n";
        return;
    }

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (pets[i].nombre == nombre && pets[i].nombreOwn == nombreOwn) {
            encontrado = true;
            continue; // Saltamos el cliente que se desea eliminar
        }
        file << pets[i].nombre<< ","
                        << pets[i].raza<< ","
                        << pets[i].nombreOwn<< "\n";
    }

    file.close();
      if (encontrado) {
            Pet* temp = new Pet[cantidad - 1];
            int index = 0;
            for (int i = 0; i < cantidad; i++) {
                if (pets[i].nombre != nombre && pets[i].nombreOwn != nombreOwn) {
                    temp[index++] = pets[i];
                }
            }

            delete[] pets;
            pets = temp;
            cantidad--;
            cout << "Mascota borrada.\n";
    } else {
        cout << "No se encontro una mascota.\n";
    }
}

void Pet::UpdatePet(Pet* pets, int cantidad, const string& nombre, const string& nombreOwn) {
    bool encontrado = false;

    ofstream archivoOriginal("Datos/pets.csv", ios::trunc);
    if (!archivoOriginal.is_open()) {
        cout << "Error al abrir el archivo original.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++) {
        // Verificar si el repuesto coincide con el nombre, modelo de carro y año del carro
        if (pets[i].nombre == nombre && pets[i].nombreOwn == nombreOwn) {
            // Pedir los nuevos datos
            cout<< "Ingrese los nuevos datos: \n";
            cout << "Ingrese el nombre: ";
            cin >> pets[i].nombre;
            cout << "Ingrese la raza: ";
            cin.ignore();
            getline(cin, pets[i].raza);
            cout << "Ingrese el nombre del owner: ";
            cin >> pets[i].nombreOwn;
            encontrado = true;
        }

        archivoOriginal << pets[i].nombre << "," << pets[i].raza << "," << pets[i].nombreOwn<< "\n";
    }

    archivoOriginal.close();

    // Confirmación del usuario para guardar los cambios
    if (encontrado) {
            cout << "Mascota modificada exitosamente.\n";
    } else {
        cout << "No se encontro una mascota con los criterios proporcionados.\n";
    }
}

void Pet::leerPets(Pet* pets, int cantidad) {
    cout << "Lista de pets:\n\n";
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". Nombre: " << pets[i].nombre << ", Raza: " << pets[i].raza <<", Nombre del owner: "<<pets[i].nombreOwn <<endl;
    }
}