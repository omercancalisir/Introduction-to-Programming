/****************************************************************************
**							SAKARYA ÜNÝVERSÝTESÝ
**			         BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**					    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**				          PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**				ÖDEV NUMARASI     : 4. ÖDEV
**				ÖÐRENCÝ ADI       : ÖMER CAN ÇALIÞIR
**				ÖÐRENCÝ NUMARASI  :
**				DERS GRUBU        : D
****************************************************************************/

#include<iostream>
#include<string>
using namespace std;


class Sifre
{
	private:


		int tutucuSifre[100];
		int tutucuSifrelenecekMetin[100];
		int desifreMetin[100];
		int tasimaci[100];

		char alfabe[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		char sifre[100];
		char sifrelenecekMetin[100];
		char sifrelenmisMetin[100];


		int uzunlukAlfabe			   = 26;
		int uzunlukSifre		       = 0;
		int uzunlukSifrelenecekMetin   = 0;


	public:

		void yazdirSifrelenmisMetin();
		void yazdirDesifreMetin();
	
		void tutucuSifreMatrisiOlustur();

		void tutucuSifrelenecekMetinMatrisiOlustur();
	
		void girilenAlfebeyiOku();

		void girilenSifreyiOku();

		void girilenSifrelenecekMetniOku();

		void sifrelenmisMetniOlustur();

		void sifreCoz();

	

};





// sifrelenmis metini bastýrýr.
void Sifre::yazdirSifrelenmisMetin()
{
	cout << "SIFRELENMIS METIN\t:";
	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		cout << sifrelenmisMetin[i];
	}
}


// desifre metini bastýrýr.
void Sifre::yazdirDesifreMetin()
{
	cout << "DESIFRE METIN\t\t:";
	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		cout << char(desifreMetin[i]);
	}
}


// sifre elemanlarýnýn alfabedeki sýrasýný tutan bir matris oluþturuyor.
void Sifre::tutucuSifreMatrisiOlustur()
{
	int tutucuDegiskeni = 0;
	// alfabe ve sifre içerisindeki ayný  harflerin tespiti için  sifre uzunlugu ve alfabe uzunlugu kadar donen forlar.
	for (int i = 1; i <= uzunlukSifre; i++)
	{
		for (int j = 1; j <= uzunlukAlfabe; j++)
		{
			//alfabe ve sifre içerisindeki ayný  harflerin  alfabedeki sýrasýnýn tespiti için if yapýsý.
			if (alfabe[j - 1] == sifre[i - 1])
			{
				tutucuSifre[tutucuDegiskeni] = j;
				tutucuDegiskeni++;
			}
		}
	}
}


// sifrelenecekMetin elemanlarýnýn alfabedeki sýrasýný tutan bir matris oluþturuyor.
void Sifre::tutucuSifrelenecekMetinMatrisiOlustur()
{
	int tutucuDegiskeni = 0;
	// alfabe ve sifrelenecekMetin içerisindeki ayný  harflerin tespiti için  sifrelenecekMetin uzunlugu ve alfabe uzunlugu kadar donen forlar.
	for (int i = 1; i <= uzunlukSifrelenecekMetin; i++)
	{
		for (int j = 1; j <= uzunlukAlfabe; j++)
		{
			//alfabe ve sifrelenecekMetin içerisindeki ayný  harflerin  alfabedeki sýrasýnýn tespiti için if yapýsý.
			if (alfabe[j - 1] == sifrelenecekMetin[i - 1])
			{
				tutucuSifrelenecekMetin[tutucuDegiskeni] = j;
				tutucuDegiskeni++;
			}
		}
	}
}


// kullanýcýnýn gireceði alfabeyi okumaya yarýyor.
void Sifre::girilenAlfebeyiOku()
{
	char okunanKarakter = 'z';
	int i = 0;
	cout << "ALFABE\t\t\t:";
	// enter tuþuna basýlana kadar dönen while yapýsý.
	while (okunanKarakter != '\r')
	{
		okunanKarakter = _getwche();
		if (okunanKarakter == '\r')
		{
			break;
		}
		alfabe[i] = okunanKarakter;
		i++;
	}
	if (i != 0)
	{
		uzunlukAlfabe = i;
	}
}


// kullanýcýnýn gireceði sifreyi okumaya yarýyor.
void Sifre::girilenSifreyiOku()
{
	char okunanKarakter = 'z';
	int i = 0;
	cout << "SIFRE\t\t\t:";
	// enter tuþuna basýlana kadar dönen while yapýsý.
	while (okunanKarakter != '\r')
	{
		okunanKarakter = _getwche();
		sifre[i] = okunanKarakter;
		i++;
	}
	uzunlukSifre = i - 1;
}


// kullanýcýnýn gireceði sifrelenecekMetini okumaya yarýyor.
void Sifre::girilenSifrelenecekMetniOku()
{
	char okunanKarakter = 'z';
	int i = 0;
	cout << "SIFRELENECEK METIN\t:";
	// enter tuþuna basýlana kadar dönen while yapýsý.
	while (okunanKarakter != '\r')
	{
		okunanKarakter = _getwche();
		sifrelenecekMetin[i] = okunanKarakter;
		i++;
	}
	uzunlukSifrelenecekMetin = i - 1;
}


// girilen sifrelenecekMetin ve sifreyi kullanarak sifrelenmisMetin oluþturuyor.
void Sifre::sifrelenmisMetniOlustur()
{
	int a = 0;


	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		sifrelenmisMetin[i] = tutucuSifre[a] + tutucuSifrelenecekMetin[i];

		tasimaci[i] = tutucuSifre[a] + tutucuSifrelenecekMetin[i];

		a++;
		// sifrenin , sifreleme metodu gereði sürekli tekrarlanarak sifrelenecek metnin altýna yazdýrýlmasý için if yapýsý
		if (a == uzunlukSifre)
		{
			a = 0;
		}

		// sifre ve sifrelenecek metnin toplamý sonucu oluþan deðerin alfabe uzunlugundan büyük olup olmadýðý kontrol ediliyor.Büyükse alfabe uzunlugu çýkarýlýyor.
		if (sifrelenmisMetin[i] > uzunlukAlfabe)
		{
			int islem = sifrelenmisMetin[i] - uzunlukAlfabe;
			sifrelenmisMetin[i] = alfabe[islem - 1];
		}
		// 
		else
		{
			sifrelenmisMetin[i] = alfabe[sifrelenmisMetin[i] - 1];
		}
	}
}


// sifrelenmis metinden, sifreyi kullanarak yeniden sifrelenmesi için girilen metini oluþturuyor.
void Sifre::sifreCoz()
{

	int a = 0;


	for (int i = 0; i < uzunlukSifrelenecekMetin; i++)
	{
		desifreMetin[i] = tasimaci[i] - tutucuSifre[a];
		a++;
		if (a == uzunlukSifre)
		{
			a = 0;
		}
		if (desifreMetin[i] < 1)
		{
			int islem = desifreMetin[i] + uzunlukAlfabe;
			desifreMetin[i] = alfabe[islem - 1];
		}
		else
		{
			desifreMetin[i] = alfabe[desifreMetin[i] - 1];
		}

	}
}




int main() {


	Sifre sifre;


	cout << "Eger herhangibir alfabe girilmezse varsayilan olarak ingiliz alfabesi kullanilacaktir." << endl << endl;
	

	sifre.girilenAlfebeyiOku(); cout << endl;
	

	sifre.girilenSifreyiOku(); cout << endl;
	

	sifre.girilenSifrelenecekMetniOku(); cout << endl;
	

	sifre.tutucuSifreMatrisiOlustur();


	sifre.tutucuSifrelenecekMetinMatrisiOlustur();


	sifre.sifrelenmisMetniOlustur();


	sifre.yazdirSifrelenmisMetin(); cout << endl;
	


	sifre.sifreCoz();


	sifre.yazdirDesifreMetin(); cout << endl << endl;
	

	system("pause");
	return 0;
}