/// \file CRhombus.cpp
///	\brief class Rhombus: implementation of the functions
///
///	Details.
///

#include<iostream> 
#include<cmath>
#include "CRhombus.h"

/// @brief default constructor 
Rhombus::Rhombus() {

	cout << "Rhombus - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param dh horizontal diagonal
/// @param dv vertical diagonal
Rhombus::Rhombus(float dh, float dv) {

	Init();

	cout << "Rhombus - constructor" << endl;

	if (dh <= 0. || dv <= 0.) {
		WarningMessage("Rhombus - constructor: diagonals should be > 0"); 
		SetDiag(0,0);
	}
	else
		SetDiag(dh,dv);

}

/// @brief destructor 
Rhombus::~Rhombus() {

	cout << "Rhombus - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Rhombus::Rhombus(const Rhombus &r) { 

	cout << "Rhombus - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rhombus& Rhombus::operator=(const Rhombus &r) { 

	cout << "Rhombus - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same diagonals
bool Rhombus::operator==(const Rhombus &r) { 

	if (r.diagH == diagH && r.diagV == diagV)
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Rhombus::Init() {
	SetDiag(1,2);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rhombus::Init(const Rhombus &r) {
	Init();
	SetDiag(r.diagH,r.diagV);
}

/// @brief total reset of the object  
void Rhombus::Reset() {
	
	SetDiag(1,2);
	
}


/// @brief set horizontal diagonal of the object
/// @param dh diagonal 
void Rhombus::SetDiagH(float dh) {

	if (dh < 0.) {
		WarningMessage("Rhombus - SetDiagH: diagonal should be > 0");
		return;
	}

	SetDiag(dh,diagV);

} 

/// @brief set vertical diagonal of the object
/// @param dv diagonal 
void Rhombus::SetDiagV(float dv) {

	if (dv < 0.) {
		WarningMessage("Rhombus - SetDiagV: diagonal should be > 0");
		return;
	}

	SetDiag(diagH,dv);

}


/// @brief get horizontal diagonal of the object
/// @return horizontal diagonal 
float Rhombus::GetDiagH() {

	return diagH;

}

/// @brief get vertical diagonal of the object
/// @return vertical diagonal 
float Rhombus::GetDiagV() {

	return diagV;

}

/// @brief get side of the object
/// @return side 
float Rhombus::GetSide() {

	return sides[0];

}



/// @brief set the diagonals of the object
/// @param dh horizonatal diagonal  
/// @param dv vertical diagonal
void Rhombus::SetDiag(float dh, float dv) {

	if (dh < 0. || dv < 0.) {
		WarningMessage("Rhombus - SetDiag: diagonals should be > 0");
		return;
	}

	diagH = dh;
	diagV = dv;  
	
	float side= sqrt(diagH*diagH/4. + diagV*diagV/4.);
	float angle=(float) round( atan(diagV/diagH)*180./3.1415);
	SetSides(side,side,side,side);
	SetAngles(2*angle,(360.-4.*angle)/2.,2*angle,(360.-4.*angle)/2.);
	return;
}

/// @brief get the diagonals of the object
/// @param dh horizontal diagonal 
/// @param dv vertical diagonal
void Rhombus::GetDiag(float &dh, float &dv) {

	dh = diagH;
	dv = diagV; 
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
float Rhombus::GetArea() {
	
	return (diagH*diagV/2.);
}


/// @brief for debugging: all about the object
void Rhombus::Dump() {
	cout << endl;
	cout << "---Rhombus---" << endl; 
	cout << endl;
	
	cout << "Horizontal diagonal = " << diagH << endl;
	cout << "Vertical diagonal = " << diagV << endl; 
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	
	Quadrilateral::Dump();
	
	cout << endl;

}
