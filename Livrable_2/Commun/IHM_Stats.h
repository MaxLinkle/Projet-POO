#pragma once
#include <mysql.h>
#include <iostream>
#include <vcclr.h>

MYSQL* con;
MYSQL_RES* res;
MYSQL_ROW row;

void finish_with_error(MYSQL* con)
{
	//std::cout << "Error: " << mysql_error(con);
	mysql_close(con);
	exit(1);
}

void ConnectDatabase() {
	con = mysql_init(NULL);
	if (con == NULL) {
		//Label_Nom->Text = "Base inexistante";
	}
	else {
		//Label_Nom->Text = "Base existante";
	}

	if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "projet", 3315, NULL, CLIENT_MULTI_STATEMENTS) == NULL) {
		//if (mysql_real_connect(con, "poo.cokj0wfmdhfw.eu-west-3.rds.amazonaws.com", "admin", "ATCSMMRM", "Testnul", 3315, NULL, 0) == NULL) {
			//label2->Text = "Erreur de connection a la base";
	}
	else {
		//label2->Text = "Connection a la base";
	}
}

bool ConvertQuery(System::String^ query) {
	ConnectDatabase();

	pin_ptr<const wchar_t> wch = PtrToStringChars(query);
	size_t convertedChars = 0;
	size_t  sizeInBytes = ((query->Length + 1) * 2);
	errno_t err = 0;

	char* ch = (char*)malloc(sizeInBytes);
	err = wcstombs_s(&convertedChars,
		ch, sizeInBytes,
		wch, sizeInBytes);

	bool qstate;

	return qstate = mysql_query(con, ch);
}

// Compososant
	// 1
public ref class Comp_Panier_moy {
public: MYSQL_RES* Panier(System::String^ nom, System::String^ prenom) {
	System::String^ query;
	query = "CALL Stat_Panier_moy('";
	query += nom;
	query += "', '";
	query += prenom;
	query += "');";
	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

public ref class Comp_Total_achat_client {
public: MYSQL_RES* Achat_client(System::String^ nom, System::String^ prenom) {
	System::String^ query;
	query = "CALL Stat_Total_achat_client('";
	query += nom;
	query += "', '";
	query += prenom;
	query += "');";
	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

// 2
public ref class Comp_Chiffre {
public: MYSQL_RES* Chiffre(System::String^ date) {
	System::String^ query;
	query = "CALL Stat_Chiffre('";
	query += date;
	query += "');";
	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

// 3
public ref class Comp_Plus_vendu {
public: MYSQL_RES* Plus() {
	System::String^ query;

	query = "CALL Stat_Plus_vendu();";

	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

public ref class Comp_Moins_vendu {
public: MYSQL_RES* Moins() {
	System::String^ query;

	query = "CALL Stat_Moins_vendu();";

	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

// 4
public ref class Comp_Achat_stock {
public: MYSQL_RES* Achat() {
	System::String^ query;

	query = "CALL Stat_Achat_stock();";

	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

public ref class Comp_Valeur_stock {
public: MYSQL_RES* Valeur() {
	System::String^ query;

	query = "CALL Stat_Valeur_stock();";

	bool qstate = ConvertQuery(query);
	if (!qstate) {
		return res = mysql_store_result(con);
	}
	return NULL;
}
};

// 5
public ref class Comp_Estimation {
public: String^ Estimation(String^ TVA, String^ Remise, String^ Marge) {


	return "CALL SIMULATION(" + TVA + "," + Remise + "," + Marge + ");";

}
};


// SERVICE 
// 1
public ref class svc_Client {
private:
	Comp_Panier_moy^ c1;
	Comp_Total_achat_client^ c2;

public:
	MYSQL_RES* svc1_1(System::String^ nom, System::String^ prenom) {
		c1 = gcnew Comp_Panier_moy;
		return c1->Panier(nom, prenom);
	}

	MYSQL_RES* svc1_2(System::String^ nom, System::String^ prenom) {
		c2 = gcnew Comp_Total_achat_client;
		return c2->Achat_client(nom, prenom);
	}
};

// 2
public ref class svc_Chiffre_affaire {
private:
	Comp_Chiffre^ c1;

public:
	MYSQL_RES* svc2_1(System::String^ date) {
		c1 = gcnew Comp_Chiffre;
		return c1->Chiffre(date);
	}
};

// 3
public ref class svc_Vente {
private:
	Comp_Moins_vendu^ c1;
	Comp_Plus_vendu^ c2;

public:
	MYSQL_RES* svc3_1() {
		c1 = gcnew Comp_Moins_vendu;
		return c1->Moins();
	}

	MYSQL_RES* svc3_2() {
		c2 = gcnew Comp_Plus_vendu;
		return c2->Plus();
	}
};

// 4
public ref class svc_Stock {
private:
	Comp_Achat_stock^ c1;
	Comp_Valeur_stock^ c2;

public:
	MYSQL_RES* svc4_1() {
		c1 = gcnew Comp_Achat_stock;
		return c1->Achat();
	}

	MYSQL_RES* svc4_2() {
		c2 = gcnew Comp_Valeur_stock;
		return c2->Valeur();
	}

};

// 5
public ref class svc_Estimation {
private:
	Comp_Estimation^ c1;

public:

	MYSQL_RES* svc5_1(String^ TVA, String^ Remise, String^ Marge ) {
		c1 = gcnew Comp_Estimation;
		
		int qstate = ConvertQuery(c1->Estimation(TVA, Remise, Marge));
		if (!qstate) {

		return	res = mysql_store_result(con);

		}
		else {
			return nullptr;

		}
	}
};