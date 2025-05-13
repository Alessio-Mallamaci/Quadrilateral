/// \file CRhombus.cpp
///	\brief class Rhombus: implementation of the functions
///
///	Details.
///

#include<iostream>          // Per output su console
#include<cmath>             // Per funzioni matematiche come sqrt e atan
#include "CRhombus.h"       // Inclusione del file header della classe Rhombus

/// @brief default constructor 
//Implementazione del costruttore di default
Rhombus::Rhombus() {

	cout << "Rhombus - constructor - default" << endl;

	Init(); // Inizializzazione standard
}

/// @brief constructor 
/// @param dh horizontal diagonal
/// @param dv vertical diagonal
//Implementazione costruttore parametrico --> inizializzo un oggetto passando il valore dei parametri
Rhombus::Rhombus(float dh, float dv) {

	Init(); // Inizializza con valori di default

	cout << "Rhombus - constructor" << endl;

	// Controllo di validità dei parametri che passo
	if (dh <= 0. || dv <= 0.) {
		WarningMessage("Rhombus - constructor: diagonals should be > 0"); 
		SetDiag(0,0); // Se valori non sono validi, imposta a 0
	}
	else
		SetDiag(dh,dv); // Altrimenti imposta le diagonali
}

/// @brief destructor 
//Implementazione distruttori
Rhombus::~Rhombus() {

	cout << "Rhombus - destructor" << endl;
	Reset(); // Reset dell’oggetto prima della distruzione
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
//Implementazione del costruttore di copia
Rhombus::Rhombus(const Rhombus &r) { 

	cout << "Rhombus - copy constructor" << endl;

	Init(r); // Inizializzazione tramite copia
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
// Implementazioni dell'operatore d'associazione (=)
Rhombus& Rhombus::operator=(const Rhombus &r) { 

	cout << "Rhombus - operator =" << endl;

	Init(r); // Copia i valori

	return *this; // Restituisce l’oggetto corrente
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same diagonals
// Implementazioni dell'operatore di comparazione (==)
bool Rhombus::operator==(const Rhombus &r) { 

	// Confronto tra diagonali
	if (r.diagH == diagH && r.diagV == diagV)
		return true;
		
	return false;
}

/// @brief default initialization of the object
//Implementazione inizializzazione standard
void Rhombus::Init() {
	
	SetDiag(1,2); // Valori di default per le diagonali
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
//Implementazione inizializzazione di copia
void Rhombus::Init(const Rhombus &r) {
	Init(); // Prima inizializza con valori standard
	SetDiag(r.diagH,r.diagV); // Poi copia le diagonali da r
}

/// @brief total reset of the object  
//Implementazione di reset 
void Rhombus::Reset() {
	
	SetDiag(1,2); // Resetta alle diagonali di default
}


/// @brief set horizontal diagonal of the object
/// @param dh diagonal 
//Implementazione setter diagonale orizzontale
void Rhombus::SetDiagH(float dh) {

	// Verifica validità parametro
	if (dh < 0.) {
		WarningMessage("Rhombus - SetDiagH: diagonal should be > 0");
		return;
	}

	SetDiag(dh,diagV); // Cambia solo la diagonale verticale
} 

/// @brief set vertical diagonal of the object
/// @param dv diagonal 
//Implementazione setter diagonale verticale
void Rhombus::SetDiagV(float dv) {

	// Verifica validità parametro
	if (dv < 0.) {
		WarningMessage("Rhombus - SetDiagV: diagonal should be > 0");
		return;
	}

	SetDiag(diagH,dv); // Cambia solo la diagonale verticale
}


/// @brief get horizontal diagonal of the object
/// @return horizontal diagonal 
//Implementazoine getter diagonale orizzontale
float Rhombus::GetDiagH() {

	return diagH; // Restituisce la diagonale orizzontale
}

/// @brief get vertical diagonal of the object
/// @return vertical diagonal 
//Implementazoine getter diagonale verticale
float Rhombus::GetDiagV() {

	return diagV; // Restituisce la diagonale verticale
}

/// @brief get side of the object
/// @return side 
//Implementazione getter dei lati
float Rhombus::GetSide() {

	return sides[0]; // I lati del rombo sono tutti uguali
}



/// @brief set the diagonals of the object
/// @param dh horizonatal diagonal  
/// @param dv vertical diagonal
//Implementazione setter di entrambe le diagonali 
void Rhombus::SetDiag(float dh, float dv) {

	// Controllo sui valori
	if (dh < 0. || dv < 0.) {
		WarningMessage("Rhombus - SetDiag: diagonals should be > 0");
		return;
	}

	diagH = dh; // Assegna diagonale orizzontale
	diagV = dv; // Assegna diagonale verticale
	
	// Calcola la lunghezza del lato usando Pitagora
	float side= sqrt(diagH*diagH/4. + diagV*diagV/4.);
	// Calcola uno degli angoli interni in gradi
	float angle=(float) round( atan(diagV/diagH)*180./3.1415);
	
	// Imposta i lati (tutti uguali in un rombo)
	SetSides(side,side,side,side);
	
	// Imposta gli angoli del rombo (2 angoli acuti, 2 ottusi)
	SetAngles(2*angle,(360.-4.*angle)/2.,2*angle,(360.-4.*angle)/2.);
	
	return;
}

/// @brief get the diagonals of the object
/// @param dh horizontal diagonal 
/// @param dv vertical diagonal
//Implementazione getter di entrambe le diagonali
void Rhombus::GetDiag(float &dh, float &dv) {

	dh = diagH; // Passaggio per riferimento
	dv = diagV; // Passaggio per riferimento
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
//Calcola area e restituisce il valore
float Rhombus::GetArea() {
	
	return (diagH*diagV/2.); // Formula area = (d1*d2)/2
}


/// @brief for debugging: all about the object
// Stampa dettagliata per il debug
void Rhombus::Dump() {
	
	cout << endl;
	cout << "---Rhombus---" << endl; 
	cout << endl;
	
	cout << "Horizontal diagonal = " << diagH << endl; // Mostra diagonale orizzontale
	cout << "Vertical diagonal = " << diagV << endl;   // Mostra diagonale verticale
	cout << "Perimeter = " << GetPerimeter() << endl;  // Mostra perimetro calcolato
	cout << "Area = " << GetArea() << endl;            // Mostra area calcolata
	
	Quadrilateral::Dump(); // Chiama il metodo della classe base
	
	cout << endl;
}
