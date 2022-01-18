#include <iostream>
#include <fstream>
using namespace std;
int main()
{

	fstream zasz;
	fstream odsz;
	zasz.open("plik_zaszyfrowany.txt", ios::in | ios::out);
	odsz.open("plik_odszyfrowany.txt", ios::out | ios::in);
	unsigned char poprzedni_z, poprzedni_o, aktualny_o, aktualny_z;
	int klucz;
	do {
		cout << "Podaj klucz [0-255] :";
		cin >> klucz;
	} while (klucz > 255 or klucz < 0);
	int wybor;
	do {
		cout << "1 - SZYFROWANIE " << endl;
		cout << "2 - DESZYFROWANIE " << endl;
		cin >> wybor;
	} while (wybor > 2 or wybor < 1);

	switch (wybor) {
	case 1:
		odsz.read(reinterpret_cast<char*>(&aktualny_o), sizeof(aktualny_o));
		poprzedni_z = aktualny_o xor 0xAA xor klucz;
		zasz.write(reinterpret_cast<char*>(&poprzedni_z), sizeof(poprzedni_z));
		while (!odsz.eof()) {
			odsz.read(reinterpret_cast<char*>(&aktualny_o), sizeof(aktualny_o));
			if (odsz.eof())break;
			aktualny_z = aktualny_o xor poprzedni_z xor klucz;
			zasz.write(reinterpret_cast<char*>(&aktualny_z), sizeof(aktualny_z));
			poprzedni_z = aktualny_z;
		}
		break;
	case 2:
		zasz.read(reinterpret_cast<char*>(&aktualny_z), sizeof(aktualny_z));
		poprzedni_o = aktualny_z xor 0xAA xor klucz;
		odsz.write(reinterpret_cast<char*>(&poprzedni_o), sizeof(poprzedni_o));
		poprzedni_z = aktualny_z;
		while (!zasz.eof()) {
			zasz.read(reinterpret_cast<char*>(&aktualny_z), sizeof(aktualny_z));
			if (zasz.eof())break;
			aktualny_o = aktualny_z xor poprzedni_z xor klucz;
			odsz.write(reinterpret_cast<char*>(&aktualny_o), sizeof(aktualny_o));
			poprzedni_z = aktualny_z;
		}
		break;
	}
	zasz.close();
	odsz.close();
}