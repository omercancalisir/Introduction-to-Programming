/****************************************************************************
**							SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**						BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI     : 1
**				ÖÐRENCÝ ADI       : Ömer Can Çalýþýr
**				ÖÐRENCÝ NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/

#include<iostream>
#include<string>
#include<locale.h> 
using namespace std;


int main() {
	setlocale(LC_ALL, "Turkish");

	int boslukSiniri1 = 6, boslukSiniri2 = 7;
	// satýr sayýsý kadar dönme iþlemi
	for (int i = 1; i <= 5; i++) {
		// sütun sayýsý kadar dönme iþlemi
		for (int j = 1; j <= 12; j++) {
			// koþul saðlandýðý durumda boþluk basýlarak þeklin orta kýsmýný oluþturma iþlemi
			if ((j >= boslukSiniri1 && j < 7) || (j >= 7 && j <= boslukSiniri2)) {
				cout << "  ";
			}
			// if koþulu saðlanmadýðý durumda yýldýz basma iþlemi
			else {
				cout << "* ";
			}
		}
		boslukSiniri1 -= 1;
		boslukSiniri2 += 1;
		cout << endl;
	}

	cout << "\n";

	int boslukSiniri3 = 2, boslukSiniri4 = 11;
	// satýr sayýsý kadar dönme iþlemi
	for (int i = 1; i <= 5; i++) {
		// sütun sayýsý kadar dönme iþlemi
		for (int j = 1; j <= 12; j++) {
			// koþul saðlandýðý durumda boþluk basýlarak þeklin orta kýsmýný oluþturma iþlemi
			if ((j >= boslukSiniri3 && j < 7) || (j >= 7 && j <= boslukSiniri4)) {
				cout << "  ";
			}
			// if koþulu saðlanmadýðý durumda yýldýz basma iþlemi
			else {
				cout << "* ";
			}
		}
		boslukSiniri3 += 1;
		boslukSiniri4 -= 1;
		cout << endl;
	}


	system("pause");
	return 0;
}