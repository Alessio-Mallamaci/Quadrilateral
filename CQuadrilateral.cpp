#include "CQuadrilateral.h"

/// @brief default constructor 
Quadrilateral::Quadrilateral() {

	cout << "Quadrilateral - constructor - default" << endl;

	Init();

}

/// @brief destructor
Quadrilateral::~Quadrilateral() {

	cout << "Quadrilateral - destructor" << endl;
	Reset();

}  


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
/// @param s4 side 4 
void Quadrilateral::SetSides(float s1, float s2, float s3, float s4) {
	
	sides[0] = s1;
	sides[1] = s2;
	sides[2] = s3;
	sides[3] = s4; 
	
	return;

} 

/// @brief sets the value of the four angles 
/// @param a0 side 1 
/// @param a1 side 2 
/// @param a2 side 3
/// @param a3 side 4 
void Quadrilateral::SetAngles(float a0, float a1, float a2, float a3) {
	
	angles[0] = a0;
	angles[1] = a1;
	angles[2] = a2;
	angles[3] = a3;

	if (!Check())
		WarningMessage("Quadrilateral - the sum of angles should be 360");	
	
	return;

} 

void Quadrilateral::SetGridCoord(coord_type Coord) {
	
	if (Coord.x < 0 || Coord.y < 0) {
		WarningMessage("SetGridCoord - the coordinates cannot be negative");
		gridCoord.x = 0;
		gridCoord.y = 0;
		return;
	}
	
	gridCoord.x = Coord.x;
	gridCoord.y = Coord.y;
}


/// @brief default initialization of the object
void Quadrilateral::Init() {
	gridCoord.x=0;
	gridCoord.y=0;
	sides[0]= sides[1]= sides[2]= sides[3] = 1.;
	angles[0]= angles[1]= angles[2]= angles[3] = 90.;
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Quadrilateral::Init(const Quadrilateral &o) {
	Init();
	
	gridCoord.x=o.gridCoord.x;
	gridCoord.y=o.gridCoord.y;
	
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
	sides[3] = o.sides[3];
	
	angles[0] = o.angles[0]; 
	angles[1] = o.angles[1]; 
	angles[2] = o.angles[2]; 
	angles[3] = o.angles[3];
	
	if (!Check())
		Reset();
	
}

/// @brief total reset of the object  
void Quadrilateral::Reset() {
	Init();
	
}

/// @brief check if the quadrilater is actually a quadrilateral 
bool Quadrilateral::Check() {
	if ((angles[0] + angles[1] + angles[2] + angles[3]) != 360.0) {
	 WarningMessage("Check - the sum of the angles is not 360");
	 return false;
	}
	return true;	
}


/// @brief get the perimeter of the object
/// @return perimeter 
float Quadrilateral::GetPerimeter() {

	return (sides[0]+sides[1]+sides[2]+sides[3]);

} 

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
/// @param s3 side 3 
void Quadrilateral::GetSides(float &s0, float &s1, float &s2, float &s3) {

	s0 = sides[0]; 
	s1 = sides[1];
	s2 = sides[2];
	s3 = sides[3];

}

/// @brief get the angles of the object 
/// @param a0 angle 0 
/// @param a1 angle 1
/// @param a2 angle 2
/// @param a3 angle 3 
void Quadrilateral::GetAngles(float &a0, float &a1, float &a2, float &a3) {

	a0 = angles[0]; 
	a1 = angles[1];
	a2 = angles[2];
	a3 = angles[3];

}

/// @brief get the coordinates of the object on the grid 
/// @param coord reference to an object of type coord_type 
void Quadrilateral::GetGridCoord(coord_type &coord) {
	coord.x = gridCoord.x;
	coord.y = gridCoord.y;
}

/// @brief write an error message 
/// @param string message to be printed
void Quadrilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Quadrilateral --";
	cout << string << endl;

}

/// @brief write a warning message 
/// @param string message to be printed
void Quadrilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Quadrilateral --";
	cout << string << endl;

}


/// @brief for debugging: all about the object
void Quadrilateral::Dump() {
	
	cout << endl;
	cout << "--- Quadrilateral ---" <<endl;
	cout << endl;
	cout << "Reference point on the grid: " << gridCoord.x << "," << gridCoord.y << endl; 
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << sides[3] << "; " << endl;
	cout << "Angles = " << angles[0] << "; " << angles[1] << "; " << angles[2] << "; " << angles[3] << "; " << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << endl;

}

