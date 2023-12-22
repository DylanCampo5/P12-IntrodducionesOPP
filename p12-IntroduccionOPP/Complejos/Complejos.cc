#include <iostream>

class Complejo {
private:
    double real;
    double imaginario;

public:
    Complejo(double r = 0, double i = 0) : real(r), imaginario(i) {}

    // Sobrecarga del operador de suma
    Complejo operator+(const Complejo& otro) const {
        return Complejo(real + otro.real, imaginario + otro.imaginario);
    }

    // Sobrecarga del operador de resta
    Complejo operator-(const Complejo& otro) const {
        return Complejo(real - otro.real, imaginario - otro.imaginario);
    }

    // Sobrecarga del operador de inserción en flujo
    friend std::ostream& operator<<(std::ostream& os, const Complejo& complejo) {
        os << "(" << complejo.real << " + " << complejo.imaginario << "i)";
        return os;
    }

    // Sobrecarga del operador de extracción de flujo
    friend std::istream& operator>>(std::istream& is, Complejo& complejo) {
        std::cout << "Parte real: ";
        is >> complejo.real;
        std::cout << "Parte imaginaria: ";
        is >> complejo.imaginario;
        return is;
    }
};

int main() {
    int RC1, RC2, IC1, IC2;
    //Las C vienen de la palabra "Complejo", las R vienen de la palabra "Real" y las I de "Imaginario".
    //Los nº 1 y 2 vienen de a que complejo nos estemos refiriendo.    
    std::cout << "Dime el complejo nº1, su parte real y su parte imaginaria: " << std::endl;
    std::cin >> RC1 >> IC1;
    std::cout << "Dime el complejo nº2, su parte real y su parte imaginaria: " << std::endl;
    std::cin >> RC2 >> IC2;
    Complejo complejo1(RC1, IC1), complejo2(RC2, IC2);
    Complejo resultado;

    resultado = complejo1 + complejo2;
    std::cout << "Suma: " << resultado << std::endl;

    resultado = complejo1 - complejo2;
    std::cout << "Resta: " << resultado << std::endl;

    // Permitir al usuario ingresar un nuevo número complejo
    std::cout << "Ingrese un nuevo número complejo:" << std::endl;
    Complejo nuevoComplejo;
    std::cin >> nuevoComplejo;
    std::cout << "Número complejo ingresado: " << nuevoComplejo << std::endl;

    return 0;
}
