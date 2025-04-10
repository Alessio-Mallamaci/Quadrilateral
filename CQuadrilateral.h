/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral

	Details.
*/


#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include<iostream>

using namespace std;

/// @struct coord_type
/// @brief a struct that defines x,y in a bidimensional grid 
struct coord_type {
	int x;
	int y;
};

/// @class Quadrilateral
/// @brief an abstract base class for quadrilateral
class Quadrilateral {
protected:

	float sides[4];
	float angles[4];
	
	coord_type gridCoord;
	
	void SetSides(float s0, float s1, float s2, float s3);
	void SetAngles(float a0, float a1, float a2, float a3);	
	bool Check();


public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Quadrilateral();
	Quadrilateral(const Quadrilateral &o);
	~Quadrilateral();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Quadrilateral& operator=(const Quadrilateral &o); 
	bool operator==(const Quadrilateral &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Quadrilateral &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2, float &s3);
	void GetAngles(float &a0, float &a1, float &a2, float &a3);
	void GetGridCoord(coord_type &Coord);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif