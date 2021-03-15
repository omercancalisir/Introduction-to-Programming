/****************************************************************************
**					SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**				    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI    : 2
**				ÖÐRENCÝ ADI      : Ömer Can Çalýþýr
**				ÖÐRENCÝ NUMARASI :
**				DERS GRUBU       : D
****************************************************************************/



#include<iostream>
#include<string>
#include<locale.h>
#include<conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");


	char ch = 'a';
	int sayac_A = 0, sayac_E = 0, sayac_I = 0, sayac_Ý = 0, sayac_U = 0, sayac_Ü = 0, sayac_O = 0, sayac_Ö = 0;
	// enter tuþuna basýlana kadar çalýþan  while döngüsü
	while (ch != '\r') {

		ch = _getche();
		// küçük ve büyük a harfini klavyeden girilmesi halinde koþul kullanarak sayma iþlemi.
		if (ch == 'a' || ch == 'A') {
			sayac_A++;
		}
		// küçük ve büyük e harfini klavyeden girilmesi halinde koþul kullanrak sayma iþlemi.
		else if (ch == 'e' || ch == 'E') {
			sayac_E++;
		}
		//i harfinin sayýlmasý iþlemi. Büyük i ' yi ASCII kodlarýndan yararlanarak aldýk.
		else if (ch == 'i' || int(ch) == -104) {
			sayac_Ý++;
		}
		// küçük ve büyük o harfini klavyeden girilmesi halinde koþul  kullanýlarak sayma iþlemi.
		else if (ch == 'o' || ch == 'O') {  
			sayac_O++;
		}
		//  küçük ve büyük  u harfini klavyeden girilmesi halinde koþul  kullanýlarak sayma iþlemi.
		else if (ch == 'u' || ch == 'U') {   
			sayac_U++;
		}
		// küçük ve büyük  ö harfini ASCII kodlarýndan yararlanarak tespit etme ve koþul kullanarak sayma iþlemi.
		else if (int(ch) == -108 || int(ch) == -103) { 
			sayac_Ö++;
		}
		// küçük ve büyük  ü harfini ASCII kodlarýndan yararlanarak tespit etme ve koþul kullanarak sayma iþlemi.
		else if (int(ch) == -127 || int(ch) == -102) { 
			sayac_Ü++;
		}
		// küçük ý harfini ASCII kodlarýndan yararlanarak tespit etme ve koþul kullanarak sayma iþlemi.
		else if (int(ch) == -115 || ch == 'I') {  
			sayac_I++;
		}
	}

	cout << endl;
	cout << endl << "a nýn girilme sayisi :" << sayac_A << endl;
	cout << endl << "e nýn girilme sayisi :" << sayac_E << endl;
	cout << endl << "ý nýn girilme sayisi :" << sayac_I << endl;
	cout << endl << "i nýn girilme sayisi :" << sayac_Ý << endl;
	cout << endl << "u nýn girilme sayisi :" << sayac_U << endl;
	cout << endl << "ü nýn girilme sayisi :" << sayac_Ü << endl;
	cout << endl << "o nýn girilme sayisi :" << sayac_O << endl;
	cout << endl << "ö nýn girilme sayisi :" << sayac_Ö << endl;


	cout << "\n\n";


	cout << "------------   Grafik   ------------";
	cout << "\n\n";

	char harfler[8] = { 'a','e','ý','i','u','ü','o','ö' };
	int arraySayaclar[8] = { sayac_A,sayac_E,sayac_I,sayac_Ý,sayac_U,sayac_Ü,sayac_O,sayac_Ö };

	int yukseklik = arraySayaclar[0];
	// grafiðimizin yüksekliðini bulma iþlemi
	// arraySayaclar içinde dönmek için for kullanýmý
	for (int kontrol = 0; kontrol <= 7; kontrol++) {
		// her for döngüsünde , arraySayaclar deðerleri içerisinden daha büyüðünü tespit etme iþlemi
		if (arraySayaclar[kontrol] > yukseklik) {
			yukseklik = arraySayaclar[kontrol];
		}
	}
	// grafiði oluþturma iþlemi
	// for döngüsü kullarak ve yükseklikten yararlanarak , satýr sayýsý kadar dönme iþlemi
	for (int satirSayisi = yukseklik; satirSayisi >= 1; satirSayisi--) {
		// for döngüsü kullanarak sütunlarda dönme iþlemi
		for (int sutun = 0; sutun <= 7; sutun++) {
			// grafikteki X harflerini basma iþlemi
			if (arraySayaclar[sutun] >= satirSayisi) { // >= olacak
				cout << "X  ";
			}
			// grafikteki boþluklarý basma iþlemi
			else {
				cout << "   ";
			}
		}
		cout << endl;
	}
	// for döngüsü kullanarak grafik ile harfler arasýna sýnýr çizgisi oluþturma
	for (int sutun = 0; sutun <= 10; sutun++) {
		cout << "--";
	}
	cout << endl;
	// for döngüsü kullanarak grafiðin alt kýsmýna harfleri yerleþtirme iþlemi
	for (int sutun = 0; sutun <= 7; sutun++) {
		cout << harfler[sutun] << "  ";
	}
	cout << "\n\n";

	cout << "------------   Grafik   ------------";
	cout << "\n\n\n\n";

	system("pause");
	return 0;
}