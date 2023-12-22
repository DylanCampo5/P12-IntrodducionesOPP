#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class Persona {
 private:
  std::string nombre;
  int edad;

 public:
  Persona(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

  std::string obtenerNombre() const {
    return nombre;
  }

  int obtenerEdad() const {
    return edad;
  }
};

  // Clase interna Jugador
  class Jugador : public Persona{
   private:
    double altura;
    std::string posicion;
    double peso;

   public:
    Jugador(std::string nombre, int edad, double altura, const std::string& posicion, double peso)
        : Persona(nombre, edad), altura(altura), posicion(posicion), peso(peso) {}

    double obtenerAltura() const {
      return altura;
    }

    std::string obtenerPosicion() const {
      return posicion;
    }

    double obtenerPeso() const {
      return peso;
    }
  };

  // Clase interna Entrenador
  class Entrenador : public Persona{
   private:
    std::string licencia;
    std::string fechaInicio;
    std::string fechaFinal;

   public:
    Entrenador(std::string nombre, int edad, std::string licencia, const std::string& fechaInicio, const std::string& fechaFinal)
        : Persona(nombre, edad), licencia(licencia), fechaInicio(fechaInicio), fechaFinal(fechaFinal) {}

    std::string ObtenerLicencia() const {
      return licencia;
    }

    std::string ObtenerFechaInicio() const {
      return fechaInicio;
    }

    std::string ObtenerFechaFinal() const {
      return fechaFinal;
    }
  };

  // Clase interna Ayudante
  class Ayudante : public Persona{
   private:
    std::string fechaInicio2;
    std::string fechaFinal2;

   public:
    Ayudante(std::string nombre, int edad, const std::string& fechaInicio2, const std::string& fechaFinal2)
        : Persona(nombre, edad), fechaInicio2(fechaInicio2), fechaFinal2(fechaFinal2) {}

    std::string ObtenerFechaInicio() const {
      return fechaInicio2;
    }

    std::string ObtenerFechaFinal() const {
      return fechaFinal2;
    }
  };

int main() {
  // Crear una persona con jugador
  std::vector<Jugador> jugadores;
  char continuar;
  do {
    std::string nombreJ;
    int edad;
    double altura, peso;
    std::string position;

    std::cout << "Ingrese el nombre del jugador: ";
    std::cin >> nombreJ;

    std::cout << "Ingrese la edad del jugador: ";
    std::cin >> edad;

    std::cout << "Ingrese la altura del jugador: ";
    std::cin >> altura;

    std::cout << "Ingrese el peso del jugador: ";
    std::cin >> peso;

    std::cout << "Ingrese la posición del jugador: ";
    std::cin >> position;

    Jugador jugador1(nombreJ, edad, altura, position, peso);
    jugadores.push_back(jugador1);

    std::cout << "Deseas ingresar otro jugador? (Y/N)" << std::endl;
    std::cin >> continuar;
  } while (continuar == 'Y' || continuar == 'y');

  // Crear una persona con entrenador
  std::cout << "Dime el nombre y la edad del entrenador" << std::endl;
  std::string nombreE;
  int edadE;
  std::cin >> nombreE >> edadE;
  Persona personaE(nombreE, edadE);

  std::cout << "Que licencia tiene?" << std::endl;
  std::string licenciaE;
  std::cin >> licenciaE;

  std::string fechaInicio;
  std::string fechaFinal;
  std::cout << "Ingrese la fecha de ingreso (YYYY MM DD): " << std::endl;
  std::cin >> fechaInicio;
  std::cout << "Ingrese la fecha de salida (YYYY MM DD): " << std::endl;
  std::cin >> fechaFinal;

  Entrenador entrenador(nombreE, edadE, licenciaE, fechaInicio, fechaFinal);

  // Crear una persona con ayudante
  std::cout << "Dime el nombre y la edad del ayudante" << std::endl;
  std::string nombreA;
  int edadA;
  std::cin >> nombreA >> edadA;
  Persona personal(nombreA, edadA);

  std::string fechaInicio2;
  std::string fechaFinal2;
  std::cout << "Ingrese la fecha de ingreso (YYYY-MM-DD): " << std::endl;
  std::cin >> fechaInicio2;
  std::cout << "Ingrese la fecha de salida (YYYY-MM-DD): " << std::endl;
  std::cin >> fechaFinal2;
  Ayudante ayudante(nombreA, edadA, fechaInicio2, fechaFinal2);

  // Impresión de datos
  std::cout << "------------------------" << std::endl;
  std::cout << "JUGADOR/ES: " << std::endl;
  for (const auto& jugador : jugadores) {
    std::cout << "----- Jugador: " << std::endl;
    std::cout << "Altura: " << jugador.obtenerAltura() << " metros" << std::endl;
    std::cout << "Posición: " << jugador.obtenerPosicion() << std::endl;
    std::cout << "Peso: " << jugador.obtenerPeso() << " kg" << std::endl;
  }
  std::cout << "------------------------" << std::endl;

  std::cout << "ENTRENADOR:" << std::endl;
  std::cout << "Licencia: " << entrenador.ObtenerLicencia() << std::endl;
  std::cout << "Fecha de ingreso (YYYY MM DD): " << entrenador.ObtenerFechaInicio() << std::endl;
  std::cout << "Fecha de salida (YYYY MM DD): " << entrenador.ObtenerFechaFinal() << std::endl;

  std::cout << "------------------------" << std::endl;

  std::cout << "AYUDANTE: " << std::endl;
  std::cout << "Fecha de inicio del ayudante: " << ayudante.ObtenerFechaInicio() << std::endl;
  std::cout << "Fecha final del ayudante: " << ayudante.ObtenerFechaFinal() << std::endl;
  return 0;
}
