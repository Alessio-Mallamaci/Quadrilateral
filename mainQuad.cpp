#include <iostream>

#include "CRectangle.h"

int main (){

    float area;
    float ao,a1,a2,a3;

    Quadrilateral* A;
    Rectangle r1;
    Rectangle r2 (1,7);

    A = &r2;
    cout <<endl;
    cout << "Area = " << A->GetArea() <<endl;

    A->Dump();
    r2=r1;

    cout <<endl;
    cout << "Area = " << A->GetArea() <<endl;
   
    A-> Dump();

    return 0;
}
