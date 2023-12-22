#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Persona {
private:
  std::string nombre;
  int edad;
  std::string DNI;
public:
  Persona(const std::string& nombre, int edad, const std::string& DNI) : nombre(nombre), edad(edad), DNI(DNI) {}

  virtual void mostrarInformacion() {
    std::cout << "Persona: " << nombre << " de " << edad << " años (" << DNI << ")\n";
  }
};

class Jugador : public Persona {
private:
  double altura, peso;
  std::string position;
public:
  Jugador(const std::string& nombre, int edad, const std::string& DNI, double altura, double peso, const std::string& position) : 
    Persona(nombre, edad, DNI), altura(altura), peso(peso), position(position) {}

  void mostrarInformacion() override {
    Persona::mostrarInformacion();
    std::cout << "----- Jugador: " << std::endl;
    std::cout << "Altura: " << altura << " metros" << std::endl;
    std::cout << "Posición: " << position << std::endl;
    std::cout << "Peso: " << peso << " kg" << std::endl;
  }
};

class Entrenador : public Persona {
private:
  std::string licencia, fechaInicio, fechaFinal;
public:
  Entrenador(const std::string& nombre, int edad, const std::string& DNI, const std::string& licencia, const std::string& fechaInicio, const std::string& fechaFinal) :
    Persona(nombre, edad, DNI), licencia(licencia), fechaInicio(fechaInicio), fechaFinal(fechaFinal) {}

  void mostrarInformacion() override {
    Persona::mostrarInformacion();
    std::cout << "la licencia es: " << licencia << std::endl;
    std::cout << "Comenzó el " << fechaInicio << " y acabó el " << fechaFinal << std::endl;
  }
};

class Ayudante : public Persona {
private:
  std::string fechaInicio2, fechaFinal2;
public:
  Ayudante(const std::string& nombre, int edad, const std::string& DNI, const std::string& licencia, const std::string& fechaInicio, const std::string& fechaFinal) :
    Persona(nombre, edad, DNI), fechaInicio2(fechaInicio), fechaFinal2(fechaFinal) {}

  void mostrarInformacion() override {
        Persona::mostrarInformacion();
        std::cout << "Fecha de Inicio:\n";
        std::cout << "Fecha de inicio: " << fechaInicio2 << "\n";
        std::cout << "Fecha de despedida:" << fechaFinal2 << "\n";
    }   
};



int main() {
  std::string nombreJ, DNI, position;
  int edadJ;
  double altura, peso;

  Persona *persona = nullptr;

  std::cout << "Nombre, edad y DNI de nuestro jugador?: ";
  std::cin >> nombreJ >> edadJ >> DNI;
  std::cout << "Cuánto mide y pesa?: ";
  std::cin >> altura >> peso;
  std::cout << "En que posición jugará?: " ;
  std::cin >> position;
  persona = new Jugador(nombreJ, edadJ, DNI, altura, peso, position);

  if (persona != nullptr) {
    persona -> mostrarInformacion();
    delete persona;
  }

  return 0;
}
