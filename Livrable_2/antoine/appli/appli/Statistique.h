// Compososant
// 1
public ref class Comp_Panier_moy {
public: void Panier() {

}
};

public ref class Comp_Total_achat_client {
public: void Achat_client() {

}
};

// 2
public ref class Comp_Chiffre {
public: void Chiffre() {

}
};

// 3
public ref class Comp_Plus_vendu {
public: void Plus() {

}
};

public ref class Comp_Moins_vendu {
public: void Moins() {

}
};

// 4
public ref class Comp_Achat_stock {
public: void Achat() {

}
};

public ref class Comp_Valeur_stock {
public: void Valeur() {

}
};

// 5
public ref class Comp_Estimation {
public: void Estimation() {

}
};


// SERVICE 
// 1
public ref class svc_Client {
private: 
	Comp_Panier_moy^ c1;
	Comp_Total_achat_client^ c2;

public: 
	void svc1_1() {
		c1 = gcnew Comp_Panier_moy;
		c1->Panier();
	}

	void svc1_2() {
		c2 = gcnew Comp_Total_achat_client;
		c2->Achat_client();
	}
};

// 2
public ref class svc_Chiffre_affaire {
private:
	Comp_Chiffre^ c1;

public:
	void svc2_1() {
		c1 = gcnew Comp_Chiffre;
		c1->Chiffre();
	}
};

// 3
public ref class svc_Vente {
private:
	Comp_Moins_vendu^ c1;
	Comp_Plus_vendu^ c2;

public:
	void svc3_1() {
		c1 = gcnew Comp_Moins_vendu;
		c1->Moins();
	}

	void svc3_2() {
		c2 = gcnew Comp_Plus_vendu;
		c2->Plus();
	}
};

// 4
public ref class svc_Stock {
private:
	Comp_Achat_stock^ c1;
	Comp_Valeur_stock^ c2;

public:
	void svc4_1() {
		c1 = gcnew Comp_Achat_stock;
		c1->Achat();
	}

	void svc4_2() {
		c2 = gcnew Comp_Valeur_stock;
		c2->Valeur();
	}

};

// 5
public ref class svc_Estimation {
private:
	Comp_Estimation^ c1;

public:
	void svc5_1() {
		c1 = gcnew Comp_Estimation;
		c1->Estimation();
	}
};