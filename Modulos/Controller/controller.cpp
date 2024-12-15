#include "../Owners/owners.h"
#include "../Pets/pets.h"
#include "controller.h"
#include <iostream>
#include <sstream>
#include <fstream>

namespace Controller {
void main(){
  int op;
  int cantPets, cantOwn;
  Owner* owners = Owner::cargarOwn(cantOwn);
  Pet* pets = Pet::cargarPets(cantPets);

    //var
    string cedula, name, apellido, direccion, perros;
    string raza, nombreOwn;

  Pet Nuevopets;
  Owner Nuevowners;
  do{
  cout<<"1. Agregar Mascota\n";
  cout<<"2. Eliminar Mascota\n";
  cout<<"3. Actualizar Mascota\n";
  cout<<"4. Agregar Owner\n";
  cout<<"5. Eliminar Owner\n";
  cout<<"6. Actualizar Owner\n";
  cout<<"7. Leer mascotas\n";
  cout<<"8. Leer Owners\n";
  cout<<"0. Salir\n";
  cin>>op;
  switch(op){
    case 1:{
      cout<<"Ingrese el nombre de la mascota: ";
      cin>>name;
      cout<<"Ingrese la raza de la mascota: ";
      cin.ignore();
      getline(cin, raza);
      cout<<"Ingrese el nombre del owner: ";
      getline(cin, nombreOwn);

      Nuevopets.setNombre(name);
      Nuevopets.setraza(raza);
      Nuevopets.setnombreOwn(nombreOwn);
      Pet::agregarPet(pets, cantPets, Nuevopets);
break;
    }
    

    case 2:{
      cout<<"Ingrese el nombre de la mascota que desea borrar: ";
      cin>>name;
      cout<<"Ingrese el nombre del owner de la mascota: ";
      cin.ignore();
      getline(cin, nombreOwn);
      Pet::borrarPet(pets, cantPets, name, nombreOwn);
break;
    }
 

    case 3:{
      cout<<"Ingrese el nombre de la mascota que desea modificar: ";
      cin>>name;
      cout<<"Ingrese el nombre del owner de la mascota: ";
      cin.ignore();
      getline(cin, nombreOwn);
      Pet::UpdatePet(pets, cantPets, name, nombreOwn);
break;
    }
    

    case 4:{
      cout<<"Ingrese la cedula del owner: ";
      cin>>cedula;
      cout<<"Ingrese el nombre: ";
      cin>>name;
      cout<<"Ingrese el apellido: ";
      cin>>apellido;
      cout<<"Ingrese la direccion: ";
      cin.ignore();
      getline(cin, direccion);
      cout<<"Ingrese la cantidad de perros: ";
      cin>>perros;

      Nuevowners.setCedula(cedula);
      Nuevowners.setNombre(name);
      Nuevowners.setApell(apellido);
      Nuevowners.setAddr(direccion);
      Nuevowners.setPerros(perros);

      Owner::agregarOwn(owners, cantOwn, Nuevowners);
break;
    }

    case 5:{
      cout<<"Ingrese la cedula del owner que desea borrar: ";
      cin>>cedula;
      Owner::borrarOwn(owners, cantOwn, cedula);
     break;
    }


    case 6:{
      cout<<"Ingrese la cedula del owner que desea actualizar: ";
      cin>>cedula;
      Owner::UpdateOwn(owners, cantOwn, cedula);
      break;
    }

    case 7:{
      Pet* pets = Pet::cargarPets(cantPets);
      Pet::leerPets(pets,cantPets);
break;
    }

    case 8:{
      Owner* owners = Owner::cargarOwn(cantOwn);
      Owner::leerOwn(owners,cantOwn);
      break;
    }

    case 0:{
      cout<<"Saliendo\n";
      break;
    }


  }

  }while(op!= 0);
}

}