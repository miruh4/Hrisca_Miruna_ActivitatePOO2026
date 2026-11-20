
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Produs {
private:
    char* denumireProdus;
    const int codProdus;
    float pret;

public:

    // Constructor cu doi parametri
    Produs(int cod, const char* denumire) :
        codProdus(cod), pret(0) {

        this->denumireProdus =
            new char[strlen(denumire) + 1];

        strcpy(this->denumireProdus, denumire);
    }

    // Getter
    int getCodProdus() const {
        return this->codProdus;
    }

    // Setter
    void setDenumireProdus(const char* denumireNoua) {

        if (denumireNoua != nullptr) {

            char* copie =
                new char[strlen(denumireNoua) + 1];

            strcpy(copie, denumireNoua);

            delete[] this->denumireProdus;

            this->denumireProdus = copie;
        }
    }

    // Operator =
    void operator=(const Produs& copie) {

        if (this != &copie) {

            this->setDenumireProdus(copie.denumireProdus);

            this->pret = copie.pret;
        }
    }

    // Metoda de afisare
    void afisare() {

        cout << endl << "Cod produs: "
            << this->codProdus;

        cout << endl << "Denumire produs: "
            << this->denumireProdus;

        cout << endl << "Pret produs: "
            << this->pret;
    }

    // Operator +=
    void operator+=(float valoare) {
        this->pret += valoare;
    }

    // Destructor
    ~Produs() {

        if (this->denumireProdus != nullptr) {
            delete[] this->denumireProdus;
            this->denumireProdus = nullptr;
        }
    }
};

void main() {

    // Testare constructor
    Produs produs1(101, "Laptop");
    produs1.afisare();

    // Testare getter
    cout << endl << "Codul este: "
        << produs1.getCodProdus();

    // Testare setter
    produs1.setDenumireProdus("Telefon");
    produs1.afisare();

    // Testare operator +=
    produs1 += 500;
    produs1.afisare();

    // Cream al doilea produs
    Produs produs2(202, "Tableta");
    produs2.afisare();

    // Testare operator =
    produs2 = produs1;
    produs2.afisare();

}
