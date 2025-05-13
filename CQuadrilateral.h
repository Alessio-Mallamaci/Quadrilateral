/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral

	Details.
*/

//GUARDIA --> per evitare doppie inclusioni
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include<iostream> // Per input/output standard

using namespace std;

/// @struct coord_type
/// @brief a struct that defines x,y in a bidimensional grid 
// Struttura semplice per rappresentare un punto su assi cartesiani bidimensionali.
struct coord_type {
	int x;
	int y;
};


/// @class Quadrilateral
/// @brief an abstract base class for quadrilateral
//Classe quadrilatero
class Quadrilateral {

// Permette l'ereditarietà protetta, accessibile e modificabile solo dalla classe stessa e da quelle derivate
protected: 

	float sides[4]; // array contenente le lunghezze dei 4 lati
	float angles[4]; // array contenente i 4 angoli interni
	
	coord_type gridCoord; // punto di riferimento del quadrilatero sulla griglia
	
	void SetSides(float s0, float s1, float s2, float s3); // imposta i lati
	void SetAngles(float a0, float a1, float a2, float a3);	// imposta gli angoli
	void SetGridCoord(coord_type Coord); // imposta la posizione sulla griglia
	bool Check(); // verifica la validità del quadrilatero (es. somma angoli = 360)

// Interfaccia pubblica
public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Quadrilateral();  // costruttore di default
	~Quadrilateral(); // distruttore virtuale (dovrebbe esserlo)
	/// @}
	
	
	/// @name BASIC HANDLING
	/// @{
	void Init(); // inizializzazione standard										
	void Init(const Quadrilateral &o);	// inizializzazione tramite copia						
	void Reset(); // resetta l'oggetto allo stato iniziale									
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter(); 										// calcola e restituisce il perimetro
	void GetSides(float &s0, float &s1, float &s2, float &s3);  // restituisce i lati
	void GetAngles(float &a0, float &a1, float &a2, float &a3); // restituisce gli angoli
	void GetGridCoord(coord_type &Coord);						// restituisce le coordinate sulla griglia
	
	virtual float GetArea()=0;									// funzione astratta per il calcolo dell'area (restituisce il risultato) --> sono abbligato a specificarlo nelle classi derivate
	
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 		// stampa un messaggio di errore
	void WarningMessage(const char *string);	// stampa un messaggio di avviso
	
	/* 
	stampa lo stato interno dell'oggetto (debug/serializzazione) --> non sono obbligato a implementare 
	il codice cpp nelle classi derivate, è sufficiente anche solo il suo (perchè non è =0 !!!), ma nel caso, 
	il dump delle classi derivate hanno priorità
	*/
	virtual void Dump();						
	/// @}

};

#endif