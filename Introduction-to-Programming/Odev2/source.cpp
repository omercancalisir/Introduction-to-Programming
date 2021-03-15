/****************************************************************************
**							SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**					    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI     : 2. ÖDEV
**				ÖÐRENCÝ ADI       : ÖMER CAN ÇALIÞIR
**				ÖÐRENCÝ NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/

#include<iostream>
#include<string>
#include<locale.h>
#include<time.h>
#include<Windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;

// random gelen deðerin tekrar edip etmediðini bulma.Tekrar ediyor mu ?   Evet(1) / Hayýr(0)
int tekrarEdiyorMu(int rastgeleSayi, char harf[5][10]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			// harf matrisinin içerisinde, random oluþan sayýnýn olup olmadýðýný kontrol etme iþlemi.
			if (harf[i][j] == char(rastgeleSayi)) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "Turkish");
	
	// rastgele ve tekrarsýz matris oluþturma iþlemi.
	srand(time(NULL));
	char harf[5][10];
	int a, b;
	// 2 boyutlu 5 e 10 luk bir matrisi oluþturmak için iç içe 2 for kullanýmý.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10;) {
			// random deðer üretme iþlemi.
			int rastgeleSayi1 = (rand() % 26) + 65;
			// üretilen random deðerin tekrar edip etmediðini sorgulama iþlemi.
			a = tekrarEdiyorMu(rastgeleSayi1, harf);

			int rastgeleSayi2 = (rand() % 26) + 97;
			b = tekrarEdiyorMu(rastgeleSayi2, harf);
			// tekrar yoksa ve çift sutünlardan birindeyse , elemaný alma iþlemi. 
			if (a == 0 && (j % 2 == 0)) {
				harf[i][j] = char(rastgeleSayi1);
				j++;
			}
			// tekrar yoksa ve tek sutünlardan birindeyse , elemaný alma iþlemi. 
			else if (b == 0 && (j % 2 == 1)) {
				harf[i][j] = char(rastgeleSayi2);
				j++;
			}
		}
	}
	cout << "Tekrarsiz ve  Rastgele Dizi" << endl;

	// rastgele matrisi bastýrma iþlemi.	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << harf[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "Sýralanmýþ Dizi" << endl;

	
	int tutucu;
	// sýralanmýþ matrisi oluþturma iþlemi.
	for (int m = 0; m < 5; m++) {
		for (int n = 0; n < 10; n++) {
			int s = n;
			// harf[m][n] elemaný ve bu elemandan sonraki elemanlarda dönme iþlemi.
			for (int i = m; i < 5; i++) {
				for (int j = s; j < 10; j++) {
					// küçük olan elemaný tespit edip , döngünün baþýndaki elemanla yer deðiþtirme iþlemi.
					if (harf[m][n] > harf[i][j]) {
						tutucu = harf[m][n];
						harf[m][n] = harf[i][j];
						harf[i][j] = tutucu;
					}
				}
				s = 0;
			}
		}
	}

	// sýralanmýþ matrisi bastýrma iþlemi.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << harf[i][j] << "\t";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}
