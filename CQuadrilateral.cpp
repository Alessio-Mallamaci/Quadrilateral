
// Inclusione del file header associato, che contiene la dichiarazione della classe Quadrilateral
#include "CQuadrilateral.h" 

/// @brief default constructor 
//Implementazione costruttore di deafault
Quadrilateral::Quadrilateral() {

	cout << "Quadrilateral - constructor - default" << endl;

	Init(); // Inizializza l’oggetto con valori di default
} 


/// @brief destructor
//Implementazione distruttore
Quadrilateral::~Quadrilateral() {

	cout << "Quadrilateral - destructor" << endl;
	
	Reset(); // Resetta i dati dell’oggetto
}  


/// @brief sets the value of the four sides 
/// @param s1 side 1 
/// @param s2 side 2 
/// @param s3 side 3
/// @param s4 side 4 
//Implementazoine setter dei lati del quadrilatero
void Quadrilateral::SetSides(float s1, float s2, float s3, float s4) {
	
	sides[0] = s1; // lato 0
	sides[1] = s2; // lato 1
	sides[2] = s3; // lato 2
	sides[3] = s4; // lato 3
	
	return;
} 

/// @brief sets the value of the four angles 
/// @param a0 side 1 
/// @param a1 side 2 
/// @param a2 side 3
/// @param a3 side 4 
//Implementazoine setter degli angoli del quadrilatero
void Quadrilateral::SetAngles(float a0, float a1, float a2, float a3) {
	
	angles[0] = a0; // angolo 0
	angles[1] = a1; // angolo 1
	angles[2] = a2; // angolo 2
	angles[3] = a3; // angolo 3

	// Verifica che la somma degli angoli sia 360 gradi, altrimenti stampa messaggio di errore
	if (!Check())
		WarningMessage("Quadrilateral - the sum of angles should be 360");	
	
	return;
} 

//Implementazione setter delle coordinate del quadrilatero
void Quadrilateral::SetGridCoord(coord_type Coord) {
	
	// Controllo validità coordinate (non possono essere negative)
	//altrimenti stampa messaggio di warning,impostale entrambe nulle e termina la funzione
	if (Coord.x < 0 || Coord.y < 0) {
		WarningMessage("SetGridCoord - the coordinates cannot be negative");
		gridCoord.x = 0;
		gridCoord.y = 0;
		return;
	}
	
	// assegnazione coordinate valide
	gridCoord.x = Coord.x; 
	gridCoord.y = Coord.y;
}


/// @brief default initialization of the object
// Implementazoine inizializzazione standard dell’oggetto 
void Quadrilateral::Init() {
	//coordinate nulle
	gridCoord.x=0;
	gridCoord.y=0;
	
	
	sides[0] = sides[1] = sides[2] = sides[3] = 1.; // tutti i lati = 1
	angles[0] = angles[1] = angles[2] = angles[3] = 90.; // tutti gli angoli = 90°
}


/// @brief initialization of the object as a copy of an object 
/// @param r reference to the object that should be copied 
//Implementazione inizializzazione come copia di un altro oggetto
void Quadrilateral::Init(const Quadrilateral &o) {
	Init(); //Inizializzazione standard
	
	// copia delle coordinate 
	gridCoord.x=o.gridCoord.x;
	gridCoord.y=o.gridCoord.y;
	
	// copia dei lati
	sides[0] = o.sides[0]; 
	sides[1] = o.sides[1]; 
	sides[2] = o.sides[2]; 
	sides[3] = o.sides[3];
	
	// copia degli angoli
	angles[0] = o.angles[0]; 
	angles[1] = o.angles[1]; 
	angles[2] = o.angles[2]; 
	angles[3] = o.angles[3];
	
	// se la copia non è valida (es. somma angoli ≠ 360), si resetta
	if (!Check())
		Reset();
	
}

/// @brief total reset of the object 
// resetta completamente l'oggetto (riporta ai valori iniziali --> standard)
void Quadrilateral::Reset() {

	Init(); //Inizializzazione standard
}

/// @brief check if the quadrilater is actually a quadrilateral
//Implementazione di funzione di per verificare se i dati attuali rappresentano un quadrilatero valido  
bool Quadrilateral::Check() {

	//Verifica se la somma degli angoli è 360° altrimenti stampa messaggio di warning
	if ((angles[0] + angles[1] + angles[2] + angles[3]) != 360.0) {
	 WarningMessage("Check - the sum of the angles is not 360"); 
	 return false;
	}

	//se tutto va bene, restituisci vero
	return true;	
}


/// @brief get the perimeter of the object
/// @return perimeter 
//Implementazione getter del perimetro (calcola e restituisce il perimetro di un quadriatero generico)
float Quadrilateral::GetPerimeter() {

	return (sides[0]+sides[1]+sides[2]+sides[3]);

} 

/// @brief get the sides of the object 
/// @param s0 side 0 
/// @param s1 side 1
/// @param s2 side 2
/// @param s3 side 3 
// Implementazione della funzione getter che resituisce il valore dei lati dell'oggetto
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
// Implementazione della funzione getter che resituisce il valore degli angoli dell'oggetto
void Quadrilateral::GetAngles(float &a0, float &a1, float &a2, float &a3) {

	a0 = angles[0]; 
	a1 = angles[1];
	a2 = angles[2];
	a3 = angles[3];
}

/// @brief get the coordinates of the object on the grid 
/// @param coord reference to an object of type coord_type 
//Implementazione della funzione getter che restituisce la posizione sulla griglia
void Quadrilateral::GetGridCoord(coord_type &coord) {
	coord.x = gridCoord.x;
	coord.y = gridCoord.y;
}

/// @brief write an error message 
/// @param string message to be printed
// Stampa un messaggio di errore
void Quadrilateral::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Quadrilateral --";
	cout << string << endl;
}

/// @brief write a warning message 
/// @param string message to be printed
//stampa un messaggio di avviso
void Quadrilateral::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Quadrilateral --";
	cout << string << endl;
}


/// @brief for debugging: all about the object
//Stampa tutti i dati interni dell’oggetto (per debug)
void Quadrilateral::Dump() {
	
	cout << endl;
	cout << "---Quadrilateral---" << endl; 
	cout << endl;
	
	cout << endl;
	//Stampa punto di riferimento sulla griglia
	cout << "Reference point on the grid: " << gridCoord.x << "," << gridCoord.y << endl; 
	//stampa lati del quadrilatero
	cout << "Sides = " << sides[0] << "; " << sides[1] << "; " << sides[2] << "; " << sides[3] << "; " << endl;
	//Stampa angoli del quadrilatero
	cout << "Angles = " << angles[0] << "; " << angles[1] << "; " << angles[2] << "; " << angles[3] << "; " << endl;
	cout << endl;
}

