/*! \file CRectangle.h
	\brief Declaration of the class Rectangle

	Details.
*/

// GUARDIA D’INCLUSIONE: evita inclusioni multiple dello stesso file
#ifndef RECTANGLE_H
#define RECTANGLE_H


#include <iostream>			// Libreria per input/output standard
#include "CQuadrilateral.h" // Inclusione della classe base Quadrilateral

using namespace std;

/// @class Rectangle
/// @brief to manage an object with the shape of a rectangle
// Classe Rectangle che eredita pubblicamente da Quadrilateral
class Rectangle : public Quadrilateral
{
protected:
	// Nessun membro protetto aggiuntivo

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rectangle(); //Costruttore di default
	Rectangle(float w, float l); //costruttore parametrico --> inizializza un oggetto di classe rectangle passando il valore dei parametri (larghezza e altezza)
	Rectangle(const Rectangle &r); // Costruttore di copia
	
	~Rectangle(); //distruttore
	/// @}
	
	/// @name OPERATORS
	/// @{
	Rectangle& operator=(const Rectangle &r); 	// Operatore di assegnazione
	bool operator==(const Rectangle &r); 		// Operatore di uguaglianza
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();                       // Inizializzazione standard
	void Init(const Rectangle &r);     // Inizializzazione tramite copia
	void Reset();                      // Reset ai valori di default											
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetHeight(float h);          // Imposta l'altezza
	void SetWidth(float w);           // Imposta la larghezza
	void SetDim(float w, float h);    // Imposta dimensioni (larghezza e altezza)
	
	void GetDim(float &w, float &h);  // Restituisce dimensioni (larghezza e altezza)
	float GetHeight();                // Restituisce altezza
	float GetWidth();                 // Restituisce larghezza
	
	float GetArea();                  // Calcola e restituisce l’area
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void Dump();					  // Stampa dettagliata dello stato dell'oggetto (debug)
	/// @}
		
};

#endif