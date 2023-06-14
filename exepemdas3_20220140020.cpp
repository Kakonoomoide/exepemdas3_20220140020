#include <iostream>
#include <vector>
using namespace std;

class Pengarang;
class Penerbit {
public:
	string nama;
	vector<Pengarang*> daftar_Pengarang;

	Penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}

	~Penerbit() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}

	void tambahPengarang(Pengarang*);
	void cetakPengarang();
};

class Buku;
class Pengarang {
public:
	string nama;
	vector<Penerbit*> daftar_Penerbit;
	vector<Buku*> daftar_Buku;

	Pengarang(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}

	~Pengarang() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}

	void tambahPenerbit(Penerbit*);
	void cetakPenerbit();
	void tambahBuku(Buku*);
	void cetakBuku();
};

class Buku {
public:
	string nama;
	vector<Buku*> daftar_Pengarang;

	Buku(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}

	~Buku() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}
};

void Penerbit::tambahPengarang(Pengarang* pPengarang) {
	daftar_Pengarang.push_back(pPengarang);
}

void Penerbit::cetakPengarang() {
	cout << "Daftar pengarang pada penerbit Gama Press \"" << this->nama << "\":\n";
	for (auto& a : daftar_Pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void Pengarang::tambahPenerbit(Penerbit* pPenerbit) {
	daftar_Penerbit.push_back(pPenerbit);
}

void Pengarang::cetakPenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_Penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}


void Pengarang::tambahBuku(Buku* pPengarang) {
	daftar_Buku.push_back(pPengarang);
}

void Pengarang::cetakBuku() {
	cout << "Daftar buku yang dikarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_Buku) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main(){
	//create class && input data

	Penerbit* varPenerbit1 = new Penerbit("Gama Press");
	Penerbit* varPenerbit2 = new Penerbit("Intan Pariwara");

	Pengarang* varPengarang1 = new Pengarang("Giga");
	Pengarang* varPengarang2 = new Pengarang("Joko");
	Pengarang* varPengarang3 = new Pengarang("Lia");
	Pengarang* varPengarang4 = new Pengarang("Asroni");

	Buku* varBuku1 = new Buku("Fisika");
	Buku* varBuku2 = new Buku("Algoritma");
	Buku* varBuku3 = new Buku("Basisdata");
	Buku* varBuku4 = new Buku("Dasar Pemrograman");
	Buku* varBuku5 = new Buku("Matematika");
	Buku* varBuku6 = new Buku("Multimedia 1");

	//add data
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);
	varPenerbit1->tambahPengarang(varPengarang1);

	varPenerbit2->tambahPengarang(varPengarang4);
	varPenerbit2->tambahPengarang(varPengarang1);

	varPengarang1->tambahPenerbit(varPenerbit1);
	varPengarang1->tambahPenerbit(varPenerbit2);

	varPengarang2->tambahBuku(varBuku1);
	varPengarang2->tambahBuku(varBuku2);
	varPengarang3->tambahBuku(varBuku3);
	varPengarang4->tambahBuku(varBuku4);
	varPengarang1->tambahBuku(varBuku5);
	varPengarang1->tambahBuku(varBuku6);

	//print the data
	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();

	varPengarang1->cetakPenerbit();

	varPengarang2->cetakBuku();
	varPengarang3->cetakBuku();
	varPengarang4->cetakBuku();
	varPengarang1->cetakBuku();

	//delete class
	delete varPenerbit1;
	delete varPenerbit2;
	delete varPengarang1;
	delete varPengarang2;
	delete varPengarang3;
	delete varPengarang4;
	delete varBuku1;
	delete varBuku2;
	delete varBuku3;
	delete varBuku4;
	delete varBuku5;
	delete varBuku6;

	return 0;
}