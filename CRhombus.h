/*! \file CRhombus.h
	\brief Declaration of the class Rectangle

	Details.
*/


#ifndef RHOMBUS_H
#define RHOMBUS_H

#include<iostream>

#include "CQuadrilateral.h"

using namespace std;

/// @class Rhombus
/// @brief to manage an object with the shape of a rhombus
class Rhombus : public Quadrilateral
{
protected:
	
	float diagH;
	float diagV;

public:
	
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Rhombus();
	Rhombus(float dH, float dV);
	Rhombus(const Rhombus &r);
	
	~Rhombus();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Rhombus& operator=(const Rhombus &r); 
	bool operator==(const Rhombus &r);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Rhombus &r);							
	void Reset();												
	/// @}
	
	
	/// @name GETTERS / SETTERS
	/// @{
	void SetDiagH(float dh);
	void SetDiagV(float dw);
	void SetDiag(float dw, float dh);
	
	void GetDiag(float &dw, float &dh);
	float GetDiagH();
	float GetDiagV(); 
	float GetSide();
	
	float GetArea();
	/// @}
	
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void Dump();
	/// @}
		
};

#endif