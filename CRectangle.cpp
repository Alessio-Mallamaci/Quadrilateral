/// \file CRectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include<iostream>             // Per output su console
#include "CRectangle.h"        // Inclusione del file header Rectangle

/// @brief default constructor 
//Implementazione costruttore di default
Rectangle::Rectangle() {

	cout << "Rectangle - constructor - default" << endl;

	Init(); //Inizializzazione standard
}

/// @brief constructor 
/// @param w width of the rectangle
/// @param h height of the rectangle
//Implementazione costruttore di copia
Rectangle::Rectangle(float w, float h) {

	Init(); //Inizializzazione standard

	cout << "Rectangle - constructor" << endl;

	// Verifica validità dimensioni, altrimenti stampa messaggio di avviso e imposta imparametri come da default
	if (w <= 0. || h <= 0.) {
		WarningMessage("Rectangle -- constructor: width and height should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(w,h); // Imposta le dimensioni se valid

}

/// @brief destructor 
//Implementazione distruttore
Rectangle::~Rectangle() {

	cout << "Rectangle - destructor" << endl;
	Reset(); // Reset dell’oggetto prima della distruzione
}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
//Inizializzazione costruttore di copia
Rectangle::Rectangle(const Rectangle &r) { 

	cout << "Rectangle - copy constructor" << endl;

	Init(r); // Inizializzazione tramite copia
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
// Implementazione operatore di assegnazione (=)
Rectangle& Rectangle::operator=(const Rectangle &r) { 

	cout << "Rectangle - operator =" << endl;

	Init(r); // Copia i dati da r
	
	return *this; //restituisci l’oggetto corrente
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
//Implementazione operatore di uguaglianza (==)
bool Rectangle::operator==(const Rectangle &r) { 

	//Verifico l'ugualianza dei parametri che caraterizzano l'oggetto
	if (r.sides[0] == sides[0] && r.sides[1] == sides[1])
		return true;
		
	return false;
}

/// @brief default initialization of the object
//Inizializzazione standard
void Rectangle::Init() {

	SetDim(2,1); // Larghezza = 2, altezza = 1
	SetAngles(90,90,90,90); // Tutti gli angoli = 90°
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
//Inizializzazione di copia
void Rectangle::Init(const Rectangle &r) {
	
	Init(); // Prima inizializza con valori di default
	SetDim(r.sides[0], r.sides[1]); // Poi imposta le dimensioni dalla copia
}

/// @brief total reset of the object  
//Reset completo dell’oggetto
void Rectangle::Reset() {
	
	SetDim(2,1); // Ripristina le dimensioni standard
}


/// @brief set width of the object
/// @param w width 
// Implementazione setter larghezza
void Rectangle::SetWidth(float w) {

	//Verifico validità del parametro (non può essere negativo), altrimenti stampa messaggio di avviso
	if (w < 0.) {
		WarningMessage("Rectangle -- SetWidth: width should be > 0");
		return;
	}

	SetDim(w,sides[1]); //Cambia larghezza e mantiene altezza attuale
}

/// @brief set length of the object
/// @param h height 
// Implementazione setter altezza
void Rectangle::SetHeight(float h) {
	//Verifico validità del parametro (non può essere negativo), altrimenti stampa messaggio di avviso
	if (h < 0.) {
		WarningMessage("Rectangle -- SetHeight: height should be > 0");
		return;
	}

	SetDim(sides[0],h); //Cambia altezza e mantiene larghezza attuale
}


/// @brief get width of the object
/// @return width 
//Implementazione getter larghezza
float Rectangle::GetWidth() {

	return sides[0]; //Restituisce la larghezza
}

/// @brief get length of the object
/// @return height
//Implementazione getter altezza
float Rectangle::GetHeight() {

	return sides[1]; //Restituisce altezza
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
// Implementazione setter dimensioni complete (altezza e larghezza)
void Rectangle::SetDim(float w, float h) {

	SetSides(w,h,w,h); // Lati opposti uguali: (w, h, w, h)
	
	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
//Implementazione getter dimensioni complete (altezza e larghezza)
void Rectangle::GetDim(float &w, float &h) {

	w = sides[0];
	h = sides[1]; 
	
	return; //Restituisce larghezza e altezza perchè le variabili sono state passate by reference
}


/// @brief computes the area of the object
/// @return the area 
// Calcolo dell'area del rettangolo
float Rectangle::GetArea() {
	
	// area = larghezza * altezza
	return (sides[0]*sides[1]);
}



/// @brief for debugging: all about the object
// Stampa dettagliata per il debug
void Rectangle::Dump() {
	cout << endl;
	cout << "---Rectangle---" << endl; 
	cout << endl;
	
	// Punto di riferimento
	cout << "Reference point on the grid: " << gridCoord.x << "," << gridCoord.y << endl; 
	// Stampa larghezza
	cout << "Width = " << sides[0] << endl;
	// Stampa altezza
	cout << "Heigth = " << sides[1] << endl;
	// Stampa perimetro
	cout << "Perimeter = " << GetPerimeter() << endl;
	// Stampa area
	cout << "Area = " << GetArea() << endl;
	
	// Chiama il metodo della classe base per ulteriori dettagli
	Quadrilateral::Dump(); 
	
	cout << endl;

}






