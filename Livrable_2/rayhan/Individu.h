#pragma once
using namespace System;

typedef ref struct Struct_Adresse Struct_Adresse_Cli;
public ref struct Struct_Adresse {
	String^ ID;
	String^ Adresse;
	String^ Ville;
	String^ Type_adresse;
	Struct_Adresse_Cli^* Suivant;

};


public class MapIndi {
public:

	virtual String^ MapperIDtoAddr(String^ ID) {};
	virtual String^ MapperID(Struct_Adresse_Cli^ Adr, String^ PNom, String^ PPrenom, String^ PDate) {};
	virtual String^ MapperIdent(String^ ID) {};

};

public class MapCLi : public MapIndi {
public:
	String^ MapperIDtoAddr(String^ ID) {

		String^ Query = "SELECT ID_adresse_client FROM Client NATURAL JOIN Adresse_client WHERE ";
		if (ID != "") {
			Query += "ID_Client = '" + ID + "'";
		}
		Query += ";";
		return Query;
	}

	String^ MapperID(Struct_Adresse_Cli^ Adr, String^ PNom, String^ PPrenom, String^ PDate) {

		String^ Query = "SELECT ID_adresse_client FROM Client NATURAL JOIN Adresse_client WHERE 1";
		if (Adr == nullptr && PNom == "" && PPrenom == "" && PDate == "") {
			Query += "AND 0";
		}
		else {
			Struct_Adresse_Cli^* current = &Adr;
			while (current != nullptr) {
				Query = "AND ID_adresse_client = '" + (*current)->ID + "'";
				current =(*current)->Suivant;
			}
			if (PNom != "") {
				Query = "AND nom = '" + PNom + "'";
			}
			if (PPrenom != "") {
				Query = "AND prenom = '" + PPrenom + "'";
			}
		}
		Query += ";";
		return Query;
	}
};

public class MapPer :public MapIndi {
public:

	String^ MapperIDtoAddr(String^ ID) {

		String^ Query = "SELECT ID_adresse_personnel FROM Personnel NATURAL JOIN Adresse_personnel WHERE 0";
		if (ID != "") {
			Query += " OR ID_Personnel = '" + ID + "'";
		}
		Query += ";";
		return Query;
	}

	String^ MapperID(Struct_Adresse_Cli^ Adr, String^ PNom, String^ PPrenom, String^ PDate) {

		String^ Query = "SELECT ID_adresse_personnel FROM Personnel NATURAL JOIN Adresse_personnel WHERE 1";
		if (Adr == nullptr && PNom == "" && PPrenom == "" && PDate == "") {

			Query += "AND 0";

		}
		else {
			if (Adr != nullptr) {
				Query = "AND ID_adresse_personnel = '" + Adr->ID + "'";
			}
			if (PNom != "") {
				Query = "AND nom = '" + PNom + "'";
			}
			if (PPrenom != "") {
				Query = "AND prenom = '" + PPrenom + "'";
			}
		}
		Query += ";";
		return Query;
	}

	String^ MapperIdent(String^ ID) {

		String^ Query = "SELECT nom,prenom,date_naissance, FROM Personnel WHERE 0 ";
		if (ID != "") {

			Query += "OR ID_Personnel = '" + ID + "'";

		}
		Query += ";";
		return Query;
	}


};




public ref class Individu {

protected: 
	MapIndi* svc_Mappage;
	String^ ID;
	String^ Nom;
	String^ Prenom;
	String^ Date;
public:
	Individu(String^ PID) {
		ID = PID;
		Nom = "";
		Prenom = "";
		Date = "";
	}
	Individu(String^ PNom, String^ PPrenom, String^ PDate) {
		ID = "";
		Nom = PNom;
		Prenom = PPrenom;
		Date = PDate;
	}

};

public ref class Client : public Individu {
private :

	Struct_Adresse^ Adresse;

public :

	Client(Struct_Adresse_Cli^ Adr, String^ PNom, String^ PPrenom, String^ PDate) :Individu(PNom, PPrenom, PDate) { Adresse = Adr; }
	
	Client(String^ PID) :Individu(PID) {}

};


public ref class Personnel : public Individu {
private :
	Struct_Adresse^ Adresse;
public :
	Personnel(Struct_Adresse_Cli^ Adr, String^ PNom, String^ PPrenom, String^ PDate) :Individu(PNom, PPrenom, PDate) { Adresse = Adr; }
	Personnel(String^ PID):Individu(PID){}
};


