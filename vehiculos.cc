#include <iostream>
#include <string>

class Vehiculo {
protected:
    std::string modelo;
    std::string marca;
    int anioFabricacion;

public:
    Vehiculo(std::string modelo, std::string marca, int anio) : modelo(modelo), marca(marca), anioFabricacion(anio) {}

    virtual void mostrarInformacion() {
        std::cout << "Vehiculo: " << marca << " " << modelo << " (" << anioFabricacion << ")\n";
    }

    virtual float calcularCostoAlquiler() = 0; // Método virtual puro
};

class Coche : public Vehiculo {
private:
    float costoDiario;
    std::string fechaInicio;
    int numeroDiasAlquiler;

public:
    Coche(std::string modelo, std::string marca, int anio, float costoDiario, std::string fechaInicio, int numDias)
        : Vehiculo(modelo, marca, anio), costoDiario(costoDiario), fechaInicio(fechaInicio), numeroDiasAlquiler(numDias) {}

    void mostrarInformacion() override {
        Vehiculo::mostrarInformacion();
        std::cout << "Alquiler: Por día\n";
        std::cout << "Fecha de inicio: " << fechaInicio << ", Número de días: " << numeroDiasAlquiler << "\n";
        std::cout << "Costo total de alquiler: $" << calcularCostoAlquiler() << "\n";
    }

    float calcularCostoAlquiler() override {
        return costoDiario * static_cast<float>(numeroDiasAlquiler);
    }
};

class Motocicleta : public Vehiculo {
private:
    float costoPorH;
    std::string fechaInicio;
    int numeroHorasAlquiler;

public:
    Motocicleta(std::string modelo, std::string marca, int anio, float costoPorH, std::string fechaInicio, int numHoras)
        : Vehiculo(modelo, marca, anio), costoPorH(costoPorH), fechaInicio(fechaInicio), numeroHorasAlquiler(numHoras) {}

    void mostrarInformacion() override {
        Vehiculo::mostrarInformacion();
        std::cout << "Alquiler: Por día\n";
        std::cout << "Fecha de inicio: " << fechaInicio << ", Número de días: " << numeroHorasAlquiler << "\n";
        std::cout << "Costo total de alquiler: $" << calcularCostoAlquiler() << "\n";
    }

    float calcularCostoAlquiler() override {
        return costoPorH * static_cast<float>(numeroHorasAlquiler);
    }
};

class Bicicleta : public Vehiculo {
private:
    float costoPorH;
    std::string fechaInicio;
    int numeroHorasAlquiler;

public:
    Bicicleta(std::string modelo, std::string marca, int anio, float costoPorH, std::string fechaInicio, int numHoras)
        : Vehiculo(modelo, marca, anio), costoPorH(costoPorH), fechaInicio(fechaInicio), numeroHorasAlquiler(numHoras) {}

    void mostrarInformacion() override {
        Vehiculo::mostrarInformacion();
        std::cout << "Alquiler: Por día\n";
        std::cout << "Fecha de inicio: " << fechaInicio << ", Número de días: " << numeroHorasAlquiler << "\n";
        std::cout << "Costo total de alquiler: $" << calcularCostoAlquiler() << "\n";
    }

    float calcularCostoAlquiler() override {
        return costoPorH * static_cast<float>(numeroHorasAlquiler);
    }
};

int main() {
    std::string eleccion;
    std::cout << "Ingrese el tipo de vehículo (coche, motocicleta, bicicleta): ";
    std::cin >> eleccion;

    Vehiculo *vehiculo = nullptr;
    float costoPorH{3}, costoDiario{35.6};

    if (eleccion == "coche" || eleccion == "Coche") {
        std::string modelo, marca, fechaInicio;
        int anio, numDias;

        std::cout << "Ingrese el modelo del coche: ";
        std::cin >> modelo;
        std::cout << "Ingrese la marca del coche: ";
        std::cin >> marca;
        std::cout << "Ingrese el año de fabricación del coche: ";
        std::cin >> anio;
        std::cout << "Ingrese la fecha de inicio del alquiler (ponlo: MM-DD): ";
        std::cin >> fechaInicio;
        std::cout << "Ingrese el número de días de alquiler del coche: ";
        std::cin >> numDias;

        vehiculo = new Coche(modelo, marca, anio, costoDiario, fechaInicio, numDias);
    }

    if (eleccion == "motocicleta" || eleccion == "Motocicleta") {
        std::string modelo, marca, fechaInicio;
        int anio, numHoras;

        std::cout << "Ingrese el modelo de la motocicleta: ";
        std::cin >> modelo;
        std::cout << "Ingrese la marca de la motocicleta: ";
        std::cin >> marca;
        std::cout << "Ingrese el año de fabricación de la motocicleta: ";
        std::cin >> anio;
        std::cout << "Ingrese la fecha de inicio del alquiler (ponlo: MM-DD): ";
        std::cin >> fechaInicio;
        std::cout << "Ingrese el número de horas de alquiler de la motocicleta: ";
        std::cin >> numHoras;

        vehiculo = new Motocicleta(modelo, marca, anio, costoPorH, fechaInicio, numHoras);
    }

    if (eleccion == "bicicleta" || eleccion == "Bicicleta") {
        std::string modelo, marca, fechaInicio;
        int anio, numHoras;

        std::cout << "Ingrese el modelo la bicicleta: ";
        std::cin >> modelo;
        std::cout << "Ingrese la marca la bicicleta: ";
        std::cin >> marca;
        std::cout << "Ingrese el año de fabricación la bicicleta: ";
        std::cin >> anio;
        std::cout << "Ingrese la fecha de inicio la bicicleta (ponlo: MM-DD): ";
        std::cin >> fechaInicio;
        std::cout << "Ingrese el número de días de alquiler la bicicleta: ";
        std::cin >> numHoras;

        vehiculo = new Bicicleta(modelo, marca, anio, costoPorH, fechaInicio, numHoras);
    }

    std::cout << "\n------------------------------ \n Están correctos los datos?: \n------------------------------ \n \n";

    if (vehiculo != nullptr) {
        vehiculo->mostrarInformacion();
        delete vehiculo;
    } else {
        std::cout << "Tipo de vehículo no válido.\n";
    }
}