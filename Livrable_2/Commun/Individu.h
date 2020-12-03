#pragma once
using namespace System;
using namespace System::Collections;

typedef ref struct Struct_Adresse Struct_Adresse;

public ref struct Struct_Adresse {
	String^ ID;
	String^ Adresse;
	String^ Ville;
	String^ Pays;
	String^ Type_adresse;
};


public class MapIndi {
public:

	virtual String^ MapperIDtoAddr(String^ ID) { return nullptr; };
	virtual String^ MapperID( String^ PNom, String^ PPrenom, String^ PDate) { return nullptr; };
	virtual String^ MapperIdent(String^ ID) { return nullptr; };
	virtual String^ MapperIDSup(String^ ID) { return nullptr; };
};

public class MapCLi : public MapIndi {
public:
	String^ MapperIDtoAddr(String^ ID) {

		String^ Query = "SELECT ID_adresse_client FROM Client NATURAL JOIN Adresse_client WHERE ";
		if (ID != "") {
			Query += " ID_Client = '" + ID + "'";
		}
		Query += ";";
		return Query;
	}

	String^ MapperID(String^ PNom, String^ PPrenom, String^ PDate) {

		String^ Query = "SELECT ID_client FROM Client WHERE 1 ";
		if (PNom == "" || PPrenom == "" ) {
			Query += "AND 0";
		}
		else {
		
			if (PNom != "") {
				Query += " AND nom = '" + PNom + "'";
			}
			if (PPrenom != "") {
				Query += " AND prenom = '" + PPrenom + "'";
			}
			if (PDate != "NULL") {
				Query += " AND date_naissance = '" + PDate + "'";
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

	String^ MapperID(String^ PNom, String^ PPrenom, String^ PDate) {

		String^ Query = "SELECT ID_Personnel FROM Personnel WHERE 1 ";
		if (PNom == "" && PPrenom == "" && PDate == "") {

			Query += " AND 0 ";

		}
		else {
			
			if (PNom != "") {
				Query += " AND nom = '" + PNom + "'";
			}
			if (PPrenom != "") {
				Query += " AND prenom = '" + PPrenom + "'";
			}
			if (PDate != "") {
				Query += " AND date_embauche = '" + PDate + "'";
			}
		}
		Query += ";";
		return Query;
	}

	String^ MapperIdent(String^ ID) {

		String^ Query = "SELECT nom,prenom,date_naissance FROM Personnel WHERE 0 ";
		if (ID != "") {

			Query += " OR ID_Personnel = '" + ID + "'";

		}
		Query += ";";
		return Query;
	}

	String^ MapperIDSup(String^ ID) {

		String^ Query = "SELECT ID_superieur FROM Personnel WHERE 0 ";
		if (ID != "") {

			Query += "OR ID_Personnel = '" + ID + "'";

		}
		Query += ";";
		return Query;
	}


};




public ref class Individu abstract{

protected:
	MapIndi* svc_Mappage;
	String^ ID;
	String^ Nom;
	String^ Prenom;
	String^ Date;
	ArrayList ^ Adresse;
	
public:
	Individu(String^ PID) {
		ID = PID;
		Nom = "";
		Prenom = "";
		Date = "";
	}
	Individu(String^ PNom, String^ PPrenom, String^ PDate, ArrayList ^ Adr) {
		ID = "";
		Nom = PNom;
		Prenom = PPrenom;
		Date = PDate;
		Adresse = Adr;
	}
	~Individu() {
		delete svc_Mappage;
	}

	ArrayList^ GetAdresse(){ return Adresse; }
	virtual String^ GetDPA() { return nullptr; }
	virtual String^ GetIdSup() { return nullptr; }
	virtual String^ GetSup() { return nullptr; }
	String^ GetId() { return ID; }
	String^ GetNom() { return Nom; }
	String^ GetPrenom() { return Prenom; }
	String^ GetDate() { return Date; }

	void SetID(String^ PID) { ID = PID; }

	String^ MapId() { return svc_Mappage->MapperID(Nom , Prenom , Date);  }
	virtual String^ MapSup() { return nullptr; }
	String^ MapCredential() { return svc_Mappage->MapperIdent(ID) ; }
	String^ MapAdrese() { return svc_Mappage->MapperIDtoAddr(ID); }

	virtual bool IsClient() = 0;
};

public ref class CLClient : public Individu {
private:
	String^ Date_Premier_Achat;

public:
	String^ GetDPA() override { return Date_Premier_Achat; }
	CLClient(ArrayList^ Adr, String^ PNom, String^ PPrenom, String^ PDate) :Individu(PNom, PPrenom, PDate, Adr) {
		svc_Mappage = new MapCLi();
	}

	CLClient(String^ PID) :Individu(PID) {}

	bool IsClient() override { return true; }

};


public ref class Personnel : public Individu {
private:
	String^ ID_Sup;
public:
	String^ GetIdSup() override { return ID_Sup; }
	String^ GetSup() override { return svc_Mappage->MapperIdent(ID_Sup); }
	String^ MapSup() override { return svc_Mappage->MapperIDSup(ID); }
	Personnel(ArrayList^ Adr, String^ PNom, String^ PPrenom, String^ PDate) :Individu(PNom, PPrenom, PDate, Adr) { svc_Mappage = new MapPer(); }
	Personnel(String^ PID) :Individu(PID) {}
	bool IsClient() override { return false; }
};


