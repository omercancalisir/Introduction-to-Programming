/****************************************************************************
**								SAKARYA ÜNÝVERSÝTESÝ
**			          BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**						   BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				            PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI      : 3
**				ÖÐRENCÝ ADI        : Ömer Can Çalýþýr
**				ÖÐRENCÝ NUMARASI   :
**				DERS GRUBU         : D
****************************************************************************/

#include<iostream>
#include<string>
#include<locale.h> 
using namespace std;
// iþlemde kullanýlacak matrisler 
struct islem {
	int giris[5][5]{ {3,2,5,1,4},
					 {6,2,1,0,7},
					 {3,0,0,2,0},
					 {1,1,3,2,2},
					 {0,3,1,0,0} };
	int cekirdekMatrisi[10][10];
	int cikisMatrisi[100][100];
	int kaymaMiktari;
	int cekirdekBoyut;
	int cikisBoyut;
};

int toplamýBul(int matris1[10][10], int matris2[10][10], int boyut);
void yazdirMatrisi(int matris[100][100], int boyutCikis);

int main() {
	setlocale(LC_ALL, "Turkish");

	char cevap = 'e';
	// islemin devamlýlýðýný saðlamasi için do-while döngüsü
	do {

		islem islem;

		const int girisBoyut = sizeof(islem.giris) / sizeof(islem.giris[0]);

		cout << "cekirdek boyutunu giriniz :";
		cin >> islem.cekirdekBoyut;

		cout << "kayma miktarini giriniz :";
		cin >> islem.kaymaMiktari;

		// cekirdek matris ve kayma miktarýna göre iþlemin yapýlýp yapýlamayacaðýný kontrol eden koþul yapýsý.
		int kosul1 = (girisBoyut + islem.cekirdekBoyut) % islem.kaymaMiktari;
		int kosul2 = (girisBoyut - islem.cekirdekBoyut) % islem.kaymaMiktari;
		if (((girisBoyut % 2 == 0 && kosul1 == 0) || (girisBoyut % 2 != 0 && kosul2 == 0)) && girisBoyut > islem.cekirdekBoyut) {
			// cekirdek matrisinin giriþini saðlayan for döngüleri
			for (int i = 0; i < islem.cekirdekBoyut; i++) {
				for (int j = 0; j < islem.cekirdekBoyut; j++) {
					cout << "cekirdek[" << i << "][" << j << "] :";
					cin >> islem.cekirdekMatrisi[i][j];
				}
			}
			cout << endl;
			islem.cikisBoyut = ((girisBoyut - islem.cekirdekBoyut) / islem.kaymaMiktari) + 1;

			const int parcalanmisMatrisBoyut = islem.cekirdekBoyut;
			int parcalanmisMatris[10][10];

			// matris parçalama
			int x = 0, y = 0;
			int v = 0, w = 0;
			// çýkýþ matrisini oluþturmak için dönen for döngüleri
			for (int k = 0; k < islem.cikisBoyut; k++) {
				for (int h = 0; h < islem.cikisBoyut; h++) {
					x = w;
					// parçalanmýþ matrisi oluþturmak üzere giris matrisinde dönen for döngüleri
					for (int i = 0; i < parcalanmisMatrisBoyut; i++) {
						y = v;
						for (int j = 0; j < parcalanmisMatrisBoyut; j++) {
							parcalanmisMatris[i][j] = islem.giris[x][y];
							y += 1;
						}
						x += 1;
					}
					// parçalanmýþ matris oluþtu

					v += islem.kaymaMiktari;

					// cikis matrisini oluþturma
					int toplam = toplamýBul(parcalanmisMatris, islem.cekirdekMatrisi, islem.cekirdekBoyut);

					islem.cikisMatrisi[k][h] = toplam;

				}
				w += islem.kaymaMiktari;
				v = 0;
			}
			// cikis matrisi bastýrma
			yazdirMatrisi(islem.cikisMatrisi, islem.cikisBoyut);

		}
		else {
			cout << "bu islem yapýlamaz ..." << endl;
			cout << "isleme tekrar etmek istiyor musunuz ?(e/h) :";
			cin >> cevap;
		}
		cout << endl;
	} while (cevap != 'h');
	system("pause");
	return 0;
}
// yollanan matrisi yazdýran fonksiyon
void yazdirMatrisi(int matris[100][100], int boyutCikis) {
	for (int i = 0; i < boyutCikis; i++) {
		for (int j = 0; j < boyutCikis; j++) {
			cout << matris[i][j] << " ";
		}
		cout << endl;
	}
}
// matrislerin üst üste gelen elemanlarýný çarpýp , çarpýmlarý toplayarak toplamý dönen fonksiyon
int toplamýBul(int matris1[10][10], int matris2[10][10], int boyut) {
	int toplam = 0;
	for (int n = 0; n < boyut; n++) {
		for (int s = 0; s < boyut; s++) {
			toplam = toplam + matris1[n][s] * matris2[n][s];
		}
	}
	return toplam;
}