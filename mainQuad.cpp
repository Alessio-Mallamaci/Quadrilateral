#include <iostream>

#include "CRectangle.h"

int main (){

    float area;
    float ao,a1,a2,a3;

    Quadrilateral* A;
    Rectangle r1;
    Rectangle r2 (1,7);
    //Rhombus q1;
    //Rhombus q2;

    A = &r1;

    A->Dump();
    r1.Dump();

    area = r1.GetArea();
    cout <<"rettangolo - 1 area: " << area <<endl;

    r1=r2;

    area = r1.GetArea();
    cout <<"rettangolo - 1 area: " << area <<endl;

    A->Dump();
    
    r1.SetWidth(12);

    A->Dump();

    area = r1.GetArea();
    cout <<"rettangolo - 1 area: " << area <<endl;
    
    return 0;
}
