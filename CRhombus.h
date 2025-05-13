/*! \file CRhombus.h
	\brief Declaration of the class Rectangle

	Details.
*/

//GUARDIA --> Evita inclusioni multiple del file
#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream> // Libreria per input/output standard

#include "CQuadrilateral.h" // Inclusione della classe base Quadrilateral

using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
// Definizione della classe Rhombus (eredita da Quadrilateral)
class Rhombus : public Quadrilateral
{
//Defizione delle variabili e delle funzioni membro accessibili solo alla classe base e alle classi derivate
protected:
	float diagH;   // Diagonale orizzontale del rombo
	float diagV;   // Diagonale verticale del rombo

public: 
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	//Costruttori e distruttori
	Rhombus();                            // Costruttore di default
	Rhombus(float dH, float dV);          // Costruttore con parametri (diagonali)
	Rhombus(const Rhombus &r);            // Costruttore di copia
	~Rhombus();                           // Distruttore
	/// @}
	
	/// @name OPERATORS
	/// @{
	//Overload operatori
	Rhombus& operator=(const Rhombus &r); 	// Operatore di assegnazione
	bool operator==(const Rhombus &r);		// Operatore di uguaglianza
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();                          // Inizializzazione standard
	void Init(const Rhombus &r);          // Inizializzazione tramite copia
	void Reset();                         // Reset dello stato dell'oggetto											
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDiagH(float dh);              // Imposta la diagonale orizzontale
	void SetDiagV(float dw);              // Imposta la diagonale verticale
	void SetDiag(float dw, float dh);     // Imposta entrambe le diagonali
	
	void GetDiag(float &dw, float &dh);   // Restituisce le diagonali
	float GetDiagH();                     // Restituisce la diagonale orizzontale
	float GetDiagV();                     // Restituisce la diagonale verticale
	float GetSide();                      // Restituisce la lunghezza del lato
	
	float GetArea();                      // Calcola l’area del rombo
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void Dump();                          // Stampa lo stato dell’oggetto per debug
	/// @}	
};

#endif // Fine del blocco include guard