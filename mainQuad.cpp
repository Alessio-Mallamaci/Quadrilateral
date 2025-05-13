#include <iostream>             // Inclusione della libreria per input/output da console

#include "CRectangle.h"         // Inclusione della definizione della classe Rectangle (e Quadrilateral)

int main () {                   // Funzione principale

    float area;                 // Variabile per memorizzare l’area (non usata direttamente nel codice)
    float a0, a1, a2, a3;       // Variabili per angoli (non usate nel codice)

    Quadrilateral* A;           // Puntatore a oggetto di tipo base Quadrilateral
                                //Non può essere inizializzata direttamente perchè è una classe astratta 

    Rectangle r1;               // Creazione oggetto r1 (costruttore di default: larghezza = 2, altezza = 1)
    Rectangle r2 (1,7);         // Creazione oggetto r2 con larghezza 1 e altezza 7

    A = &r2;                    // Assegna al puntatore A l’indirizzo dell’oggetto r2 
                                //OK Polimorfismo, perchè chiama metodi override di Rectangle

    cout <<endl;
    cout << "Area = " << A->GetArea() <<endl;  // Chiama GetArea() tramite puntatore alla classe base

    A->Dump();                  // Chiama Dump() virtuale tramite il puntatore (stampa dettagli di r2)

    r2 = r1;                    // Assegna r1 a r2: operator= viene chiamato, r2 ora ha dimensioni di r1

    cout <<endl;
    cout << "Area = " << A->GetArea() <<endl;  // Ristampa area, che ora è quella di r1 (2x1 = 2)

    A->Dump();                  // Ristampa i dettagli aggiornati dopo l'assegnazione

    return 0;                   // Termina il programma
}
