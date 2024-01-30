#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funcions
void inicialitzarBaralla(int baralla[], int numCartes);
void barrejarBaralla(int baralla[], int numCartes);
void repartirCartes(int baralla[], int numCartes, int numCartesToDeal);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int NUM_CARTES = 52;
    int baralla[NUM_CARTES];

    // Inicialitza la baralla
    inicialitzarBaralla(baralla, NUM_CARTES);

    // Barreja les cartes
    barrejarBaralla(baralla, NUM_CARTES);

    // Reparteix una mà de pòquer (5 cartes)
    repartirCartes(baralla, NUM_CARTES, 5);

    return 0;
}

// Funció per inicialitzar la baralla
void inicialitzarBaralla(int baralla[], int numCartes) {
    for (int i = 0; i < numCartes; ++i) {
        baralla[i] = i + 1; // Assigna valors de 1 a 52 a la baralla
    }
}

// Funció per barrejar la baralla
void barrejarBaralla(int baralla[], int numCartes) {
    for (int i = 0; i < numCartes; ++i) {
        int randomIndex = rand() % numCartes;
        // Intercanvia els valors entre la posició actual i la posició aleatòria
        swap(baralla[i], baralla[randomIndex]);
    }
}

// Funció per repartir un nombre específic de cartes
void repartirCartes(int baralla[], int numCartes, int numCartesToDeal) {
    cout << "Cartes repartides: ";
    for (int i = 0; i < numCartesToDeal; ++i) {
        // Calcula el valor i el pal de la carta
        int valor = baralla[i] % 13 + 1;
        char pal = "CDHS"[baralla[i] / 13];

        // Mostra la carta m           
        if (valor == 1) {
            cout << "A ";
        }
        else if (valor <= 10) {
            cout << valor << " ";
        }
        else {
            cout << "JQK"[valor - 11] << " ";
        }

        cout << pal << " ";
    }
    cout << endl;
}
