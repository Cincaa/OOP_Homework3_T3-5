#include <iostream>
#include<string>
#include<cstring>
using namespace std;
//---------------MASINA-------------
class Masina {
protected:
	double pret;
	string nume;
public:
	Masina();
	Masina(double pret, string nume);
	~Masina();
	virtual void afisare() = 0;
	
};
Masina::Masina() {
	cout << "Exsit!\n";
}
Masina::Masina(double pret, string nume) {
	this->pret = pret;
	this->nume = nume;
}
Masina::~Masina() {
	pret = -1;
	nume.clear();
}
//----------------COUPE-------------
class Coupe :public Masina {
private:
	int nr_usi;
public:
	Coupe() :Masina() {};
	Coupe(int nr_usi,double pret, string nume);
	~Coupe() {
		nr_usi = -1;
	};
	friend istream& operator >>(istream& in, Coupe &obj);
	Coupe operator =(const Coupe &obj);
	void afisare();
	double get_pret(){ return pret; }

};
Coupe Coupe:: operator =(const Coupe &obj) {
	pret = obj.pret;
	nume = obj.nume;
	nr_usi = obj.nr_usi;

	return *this;
}
istream& operator >>(istream& in, Coupe &obj) {
	double pret;
	string nume;
	int nr_usi;
	cout << "Pret, nume, nr usi\n";
	in >> pret >> nume >> nr_usi;
	obj.pret = pret;
	obj.nume = nume;
	obj.nr_usi = nr_usi;
	return in;
}
Coupe::Coupe(int nr_usi, double pret, string nume):Masina(pret, nume) {
	this->nr_usi = nr_usi;
}
void Coupe:: afisare() {
	cout << "Nr. usi: " << nr_usi << endl << "Pret: " << pret << endl << "Nume: " << nume << endl;
}
//--------------HOT-HATCH-----------
class Hot_hatch:public Masina{
private:
	string tip_motor;
public:
	Hot_hatch() :Masina() {  };
	Hot_hatch(string tip_motor, double pret, string nume);
	~Hot_hatch() {
		tip_motor.clear();
	}
	friend istream& operator >>(istream& in, Hot_hatch &obj);
	Hot_hatch operator =(const Hot_hatch &obj);
	void afisare();
};
Hot_hatch Hot_hatch:: operator =(const Hot_hatch &obj) {
	pret = obj.pret;
	nume = obj.nume;
	tip_motor = obj.tip_motor;

	return *this;
}
istream& operator >>(istream& in, Hot_hatch &obj) {
	double pret;
	string nume;
	string tip_motor;
	cout << "Pret, nume, tip motor\n";
	in >> pret >> nume >> tip_motor;
	obj.pret = pret;
	obj.nume = nume;
	obj.tip_motor = tip_motor;
	return in;
}
Hot_hatch ::Hot_hatch(string tip_motor, double pret, string nume) :Masina(pret, nume) {
	this->tip_motor = tip_motor;
}
void Hot_hatch::afisare() {
	cout << "Tip Motor: " << tip_motor << endl << "Pret: " << pret << endl << "Nume: " << nume << endl;
}
//------------CABRIO----------------
class Cabrio :public Masina {
private:
	string tip_acoperis;
public:
	Cabrio() :Masina() {  };
	Cabrio(string tip_acoperis, double pret, string nume);
	~Cabrio() {
		tip_acoperis.clear();
	}
	friend istream& operator >>(istream& in, Cabrio &obj);
	Cabrio operator =(const Cabrio &obj);
	void afisare();
};
Cabrio Cabrio:: operator =(const Cabrio &obj) {
	pret = obj.pret;
	nume = obj.nume;
	tip_acoperis = obj.tip_acoperis;

	return *this;
}
istream& operator >>(istream& in, Cabrio &obj) {
	double pret;
	string nume;
	string tip_acoperis;
	cout << "Pret, nume, tip acoperis\n";
	in >> pret >> nume >> tip_acoperis;
	obj.pret = pret;
	obj.nume = nume;
	obj.tip_acoperis = tip_acoperis;
	return in;
}
Cabrio::Cabrio(string tip_acoperis, double pret, string nume) :Masina(pret, nume) {
	this->tip_acoperis = tip_acoperis;
}
void Cabrio::afisare() {
	cout << "Tip acoperis: " << tip_acoperis << endl << "Pret: " << pret << endl << "Nume: " << nume << endl;
}
//-------------------SPUPER-SPORT------------
class Sport :public Masina {
private:
	string tip_plata;
public:
	Sport() :Masina() {  };
	Sport(string tip_plata, double pret, string nume);
	~Sport() {
		tip_plata.clear();
	}
	friend istream& operator >>(istream& in, Sport &obj);
	Sport operator =(const Sport &obj);
	void afisare();
	string get_nume() {
		return nume;
	}
};
Sport Sport:: operator =(const Sport &obj) {
	pret = obj.pret;
	nume = obj.nume;
	tip_plata = obj.tip_plata;

	return *this;
}
istream& operator >>(istream& in, Sport &obj) {
	double pret;
	string nume;
	string tip_plata;
	cout << "Pret, nume, tip plata\n";
	in >> pret >> nume >> tip_plata;
	obj.pret = pret;
	obj.nume = nume;
	obj.tip_plata = tip_plata;
	return in;
}
Sport::Sport(string tip_plata, double pret, string nume) :Masina(pret, nume) {
	this->tip_plata = tip_plata;
}
void Sport::afisare() {
	cout << "Tip plata: " << tip_plata << endl << "Pret: " << pret << endl << "Nume: " << nume << endl;
}
//----------------EXPOZITIE-----------------
template <typename T>
class Expozitie {
	 static int nr_total_masini;
	T *m;
public:
	Expozitie(int nr_total_mas) {
		this->nr_total_masini = nr_total_mas;
		m = new T[nr_total_mas];
		for (int i = 0; i < nr_total_mas; i++)
			cin >> m[i];
	}
	void insert(const T &obj) {
		nr_total_masini++;
		T *mm = m;
		m = new T[nr_total_masini];
		for (int i = 0; i < nr_total_masini - 1; i++)
			m[i] = mm[i];
		m[nr_total_masini-1] = obj;
	}
	void afis() {
		for (int i = 0; i < nr_total_masini; i++) {
			cout << "Masina: " << i+1 << endl;
			m[i].afisare();
		}
	}
};
template<>
class Expozitie<string> {
private:
	 int nr_masini_sport;
	 int nr_masini_vandute;
	Sport *stoc, *vandute;
public:
	Expozitie() {
		nr_masini_sport = nr_masini_vandute = 0;
	}
	Expozitie(int nr_masini_sport, int nr_masini_vandute) {
		this->nr_masini_sport = nr_masini_sport;
		this->nr_masini_vandute = nr_masini_vandute;
		stoc = new Sport[nr_masini_sport];
		vandute = new Sport[nr_masini_vandute];
	}
	void insert(const Sport &obj) {
		nr_masini_sport++;
		Sport *mm = stoc;
		stoc = new Sport[nr_masini_sport];
		for (int i = 0; i < nr_masini_sport - 1; i++)
			stoc[i] = mm[i];
		stoc[nr_masini_sport - 1] = obj;

	}
	void afis_stoc() {
		try {
			if (nr_masini_sport == 0)							///EXCEPTIE AICI
				throw 1;
			else
				for (int i = 0; i < nr_masini_sport; i++) {
					cout << "Masina: " << i + 1 << endl;
					stoc[i].afisare();
				}
		}
		catch (int x) {
			cout << "Nu exista masini in stoc\n";
		}
	}
	void afis_vandute() {
		try {														///TRATAREA EXCEPTIILOR SI AICI
			if (nr_masini_vandute == 0)
				throw 2;
			else
				for (int i = 0; i < nr_masini_vandute; i++) {
					cout << "Masina: " << i + 1 << endl;
					vandute[i].afisare();
				}
		}
		catch (int x) {
			cout << "NU exista masini vandute\n";
		}
	}
	Expozitie& operator -=(Sport &B) {
		string name=B.get_nume();
		for (int i = 0; i < nr_masini_sport; i++)
			if (stoc[i].get_nume() == name) {
				vandute = new Sport[nr_masini_vandute + 1];
				vandute[nr_masini_vandute++] = stoc[i];
				stoc[i] = stoc[nr_masini_sport - 1];
				stoc = new Sport [nr_masini_sport--];
			}
		return *this;
	}
};
int main()
{	
	//Coupe Q(4,3000.1,"da");
	/*Coupe A, B;
	cin >> A;
	B = A;
	//cout << A.get_pret();
	B.afisare();
	*/
	/*Hot_hatch A, B;
	cin >> A;
	B = A;
	B.afisare();
	*/
	/*Cabrio A, B;
	cin >> A;
	B = A;
	B.afisare();
	*/
	/*Sport A, B;
	cin >> A;
	B = A;
	B.afisare();
	*/
	/*Expozitie<Coupe> A(1);
	A.insert(Q);
	A.afis();
	*/
	/*Expozitie<string> A;
	Sport B;
	cin >> B;
	A.insert(B);
	A.afis_stoc();
	A -= B;
	A.afis_stoc();
	A.afis_vandute();
	*/
	//Masina M;
	/*Coupe C;
	cin >> C;
	Masina *M = dynamic_cast<Masina*>(&C);						///Dynamic_cast aici
	M->afisare();
	*/
	return 0;
}
