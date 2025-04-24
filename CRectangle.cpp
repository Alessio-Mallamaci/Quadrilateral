/// \file CRectangle.cpp
///	\brief class Rectangle: implementation of the functions
///
///	Details.
///

#include<iostream>
#include "CRectangle.h"

/// @brief default constructor 
Rectangle::Rectangle() {

	cout << "Rectangle - constructor - default" << endl;

	Init();

}

/// @brief constructor 
/// @param w width of the rectangle
/// @param h height of the rectangle
Rectangle::Rectangle(float w, float h) {

	Init();

	cout << "Rectangle - constructor" << endl;

	if (w <= 0. || h <= 0.) {
		WarningMessage("Rectangle -- constructor: width and height should be > 0"); 
		SetDim(0,0);
	}
	else
		SetDim(w,h);

}

/// @brief destructor 
Rectangle::~Rectangle() {

	cout << "Rectangle - destructor" << endl;
	Reset();

}

/// @brief copy constructor 
/// @param o reference to the object that should be copied 
Rectangle::Rectangle(const Rectangle &r) { 

	cout << "Rectangle - copy constructor" << endl;

	Init(r);
	
}

/// @brief overload of operator = 
/// @param o reference to the object on the right side of the operator 
/// @return reference to the object on the left side of the operator 
Rectangle& Rectangle::operator=(const Rectangle &r) { 

	cout << "Rectangle - operator =" << endl;

	Init(r);
	
	return *this;
	
}

/// @brief overload of operator == 
/// @param r reference to the object on the right side of the operator 
/// @return true if the two objects have the same width and the same length  
bool Rectangle::operator==(const Rectangle &r) { 

	if (r.sides[0] == sides[0] && r.sides[1] == sides[1])
		return true;
		
	return false;
}

/// @brief default initialization of the object
void Rectangle::Init() {
	SetDim(2,1);
	SetAngles(90,90,90,90);
	
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
void Rectangle::Init(const Rectangle &r) {
	Init();
	SetDim(r.sides[0],r.sides[1]);
}

/// @brief total reset of the object  
void Rectangle::Reset() {
	
	SetDim(2,1);
	
}


/// @brief set width of the object
/// @param w width 
void Rectangle::SetWidth(float w) {

	if (w < 0.) {
		WarningMessage("Rectangle -- SetWidth: width should be > 0");
		return;
	}

	SetDim(w,sides[1]);

}

/// @brief set length of the object
/// @param h height 
void Rectangle::SetHeight(float h) {

	if (h < 0.) {
		WarningMessage("Rectangle -- SetHeight: height should be > 0");
		return;
	}

	SetDim(sides[0],h);

}



/// @brief get width of the object
/// @return width 
float Rectangle::GetWidth() {

	return sides[0];

}

/// @brief get length of the object
/// @return height
float Rectangle::GetHeight() {

	return sides[1];
}

/// @brief set width and length of the object
/// @param w width 
/// @param h height
void Rectangle::SetDim(float w, float h) {

	SetSides(w,h,w,h);
	
	return;
}

/// @brief get width and length of the object
/// @param w width 
/// @param h height
void Rectangle::GetDim(float &w, float &h) {

	w = sides[0];
	h = sides[1]; 
	
	return;
}

/// @brief computes the area of the object
/// @return the area 
float Rectangle::GetArea() {
	
	return (sides[0]*sides[1]);
}



/// @brief for debugging: all about the object
void Rectangle::Dump() {
	cout << endl;
	cout << "---Rectangle---" << endl; 
	cout << endl;
	
	cout << "Reference point on the grid: " << gridCoord.x << "," << gridCoord.y << endl; 
	cout << "Width = " << sides[0] << endl;
	cout << "Heigth = " << sides[1] << endl;
	cout << "Perimeter = " << GetPerimeter() << endl;
	cout << "Area = " << GetArea() << endl;
	
	Quadrilateral::Dump();
	
	cout << endl;

}






