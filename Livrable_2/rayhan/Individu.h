#pragma once
using namespace System;
public ref class Individu {
private: 
	String^ ID;
	String^ Nom;
	String^ Prenom;
	String^ Date;
public:
	Individu(String^ PID) {
		ID = PID;
	}
	Individu(String^ PID, String^ PNom, String^ PPrenom, String^ PDate) {
		ID = PID;
		Nom = PNom;
		Prenom = PPrenom;
		Date = PDate;
	}
};

typedef ref struct Struct_Adresse_Cli Struct_Adresse_Cli;
public ref struct Struct_Adresse_Cli {

	String^ Adresse;
	String^ Ville;
	String^ Type_adresse;

};

public ref class Client : public Individu {
private :

	Struct_Adresse_Cli^ Adresse;

public :
	Client(Struct_Adresse_Cli^ Adr, String^ PID, String^ PNom, String^ PPrenom, String^ PDate) :Individu(PID, PNom, PPrenom, PDate) { Adresse = Adr; }
	
	Client(String^ PID) :Individu(PID) {}

};


public ref class Personnel : public Individu {
private :
	String^ Adresse;
	String^ Ville;
public :
	Personnel(String^ PAdresse, String^ PVille, String^ PID, String^ PNom, String^ PPrenom, String^ PDate) :Individu(PID, PNom, PPrenom, PDate) { Adresse = PAdresse; Ville = PVille; }
	Personnel(String^ PID):Individu(PID){}

};