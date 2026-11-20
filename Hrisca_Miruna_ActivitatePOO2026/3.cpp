
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

using namespace std;

class Calatorie {
private:
    char* numeDestinatie;
    const int idCalatorie;

public:

    // Constructor cu un parametru
    Calatorie(int id) : idCalatorie(id) {
        this->numeDestinatie = new char[strlen("Nespecificata") + 1];
        strcpy(this->numeDestinatie, "Nespecificata");
    }

    // Getter pentru atributul constant
    int getIdCalatorie() const {
        return this->idCalatorie;
    }

    // Setter pentru atributul alocat dinamic
    void setNumeDestinatie(const char* numeNou) {
        if (numeNou != nullptr) {
            char* copie = new char[strlen(numeNou) + 1];
            strcpy(copie, numeNou);

            delete[] this->numeDestinatie;
            this->numeDestinatie = copie;
        }
    }

    // Operatorul =
    void operator=(const Calatorie& copie) {
        if (this != &copie) {
            this->setNumeDestinatie(copie.numeDestinatie);
        }
    }

    // Metoda de afisare
    void afisare() {
        cout << endl << "ID calatorie: "
            << this->idCalatorie;

        cout << endl << "Nume destinatie: "
            << this->numeDestinatie;
    }

    // Supraincarcarea operatorului functie ()
    void operator()(const char* destinatieNoua) {
        this->setNumeDestinatie(destinatieNoua);
    }

    // Destructor
    ~Calatorie() {
        if (this->numeDestinatie != nullptr) {
            delete[] this->numeDestinatie;
            this->numeDestinatie = nullptr;
        }
    }
};

void main() {

    // Testare constructor
    Calatorie calatorie1(101);
    calatorie1.afisare();

    // Testare getter
    cout << endl << "ID-ul este: "
        << calatorie1.getIdCalatorie();

    // Testare setter
    calatorie1.setNumeDestinatie("Paris");
    calatorie1.afisare();

    // Testare operator functie
    calatorie1("Roma");
    calatorie1.afisare();

    // Testare operator =
    Calatorie calatorie2(202);
    calatorie2.afisare();

    calatorie2 = calatorie1;
    calatorie2.afisare();

    // Verificam ca ID-ul nu se modifica
    cout << endl << "ID calatorie 2: "
        << calatorie2.getIdCalatorie();

}
