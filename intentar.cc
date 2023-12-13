#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <iomanip>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& nombre, int edad) : nombre (nombre), edad (edad) {}

    // Getter para obtener el nombre
    std::string obtenerNombre() const {
        return nombre;
    }

    // Getter para obtener la edad
    int obtenerEdad() const {
        return edad;
    }
//-------------------------------------------------------------------------------
    // Clase interna Jugador
    class Jugador {
    private:
        double altura;
        std::string posicion;
        double peso;

    public:
        Jugador(double altura, const std::string& posicion, double peso)
            : altura(altura), posicion(posicion), peso(peso) {}

        // Métodos para obtener información del jugador
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
//------------------------------------------------------------------------------------
    class Entrenador {
    private:
        std::string licencia;
        std::tm fechaInicio;
        std::tm fechaFinal;
    public:
        Entrenador(std::string licencia, const std::tm& fechaInicio, const std::tm& fechaFinal)
            : licencia(licencia), fechaInicio(fechaInicio), fechaFinal(fechaFinal) {}

        std::string ObtenerLicencia() const {
            return licencia;
        }

        std::string ObtenerFechaInicio () const {
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fechaInicio);
            return std::string(buffer);
        }

        std::string ObtenerFechaFinal () const {
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fechaFinal);
            return std::string(buffer);
        }
    };
//------------------------------------------------------------------------------------
    class Ayudante {
    private:
        std::tm fechaInicio2;
        std::tm fechaFinal2;
    public:
        Ayudante(const std::tm& fechaInicio2, const std::tm& fechaFinal2) 
            : fechaInicio2(fechaInicio2), fechaFinal2(fechaFinal2) {}

        std::string ObtenerFechaInicio () const {
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fechaInicio2);
            return std::string(buffer);
        }

        std::string ObtenerFechaFinal () const {
            char buffer[80];
            std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &fechaFinal2);
            return std::string(buffer);
        }
    };
};

int main() {

//------------------------------------------------------------------------------------------------------------
    // Crear una persona con jugador
    std::vector<Persona::Jugador> jugadores;
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

        Persona::Jugador jugador (altura, position, peso);
        jugadores.push_back(jugador);

        std::cout << "Deseas ingresar otro jugador? (Y/N)" << std::endl;
        std::cin >> continuar;
    }   while (continuar == 'Y' || continuar == 'y');
//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
    //Crear una persona con entrenador
    std::cout << "Dime el nombre y la edad del entrenador" << std::endl;
    std::string nombreE;
    int edadE;
    std::cin >> nombreE >> edadE;
    Persona personaE(nombreE, edadE);

    std::cout << "Que licencia tiene?" << std::endl;
    std::string licenciaE;
    std::cin >> licenciaE;

    std::tm fechaInicio;
    std::tm fechaFinal;
    std::cout << "Ingrese la fecha de ingreso (YYYY MM DD): " << std::endl;
    std::cin >> std::get_time(&fechaInicio, "%Y %m %d");
    std::cout << "Ingrese la fecha de salida (YYYY MM DD): " << std::endl;
    std::cin >> std::get_time(&fechaFinal, "%Y %m %d");

    Persona::Entrenador entrenador(licenciaE, fechaInicio, fechaFinal);
//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
    std::cout << "Dime el nombre y la edad del ayudante" << std::endl;
    std::string nombreA;
    int edadA;
    std::cin >> nombreA >> edadA;
    Persona personal(nombreA, edadA);

    std::tm fechaInicio2;
    std::tm fechaFinal2;
    std::cout << "Ingrese la fecha de ingreso (YYYY MM DD): " << std::endl;
    std::cin >> std::get_time(&fechaInicio2, "%Y %m %d");
    std::cout << "Ingrese la fecha de salida (YYYY MM DD): " << std::endl;
    std::cin >> std::get_time(&fechaFinal2, "%Y %m %d");
    Persona::Ayudante ayudante (fechaInicio2, fechaFinal2);
//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------
    //PUROS COUT
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
    std::cout << "Licencia: ";
    std::cout << entrenador.ObtenerLicencia() << std::endl;
    std::cout << "Fecha de ingreso (YYYY MM DD): ";
    std::cout << entrenador.ObtenerFechaInicio() << std::endl;
    std::cout << "Fecha de salida (YYYY MM DD): ";
    std::cout << entrenador.ObtenerFechaFinal() << std::endl;

    std::cout << "------------------------" << std::endl;

    std::cout << "AYUDANTE: " << std::endl;
    std::cout << "Fecha de inicio del ayudante: ";
    std::cout << ayudante.ObtenerFechaInicio() << std::endl;
    std::cout << "Fecha final del ayudante: ";
    std::cout << ayudante.ObtenerFechaFinal() << std::endl;
//------------------------------------------------------------------------------------------------------------
    return 0;
}
