#include <iostream>
#include <cmath>

// Enumeración para representar el color del círculo
enum Color {
    ROJO,
    VERDE,
    AZUL
};

class Circulo {
private:
    double centroX;
    double centroY;
    double radio;
    Color color;

public:
    // Constructor
    Circulo(double x, double y, double r, Color c) : centroX(x), centroY(y), radio(r), color(c) {}

    // Métodos para calcular el área y el perímetro
    double Area() const {
        return 3.141592653589793 * pow(radio, 2);  // Pi * r^2
    }

    double Perimetro() const {
        return 2 * 3.141592653589793 * radio;  // 2 * Pi * r
    }

    // Método para imprimir información sobre el círculo
    void Print() const {
        std::cout << "Centro: (" << centroX << ", " << centroY << ")" << std::endl;
        std::cout << "Radio: " << radio << std::endl;
        std::cout << "Color: " << color << std::endl;
    }

    // Método para verificar si un punto (x, y) está dentro del círculo
    bool EsInterior(double x, double y) const {
        double distanciaAlCentro = sqrt(pow(x - centroX, 2) + pow(y - centroY, 2));
        return distanciaAlCentro <= radio;
    }
};

int main() {
    // Crear un círculo
    double xposition, yposition, radio;
    std::cin >> xposition >> yposition >> radio;
    Circulo miCirculo(xposition, yposition, radio, ROJO);

    // Calcular y mostrar el área y el perímetro
    std::cout << "Área del círculo: " << miCirculo.Area() << std::endl;
    std::cout << "Perímetro del círculo: " << miCirculo.Perimetro() << std::endl;

    // Imprimir información sobre el círculo
    miCirculo.Print();

    // Verificar si un punto está dentro del círculo
    double x, y;
    std::cout << "Ingrese las coordenadas (x y) para verificar si están dentro del círculo: ";
    std::cin >> x >> y;

    if (miCirculo.EsInterior(x, y)) {
        std::cout << "El punto está dentro del círculo." << std::endl;
    } else {
        std::cout << "El punto está fuera del círculo." << std::endl;
    }

    return 0;
}
