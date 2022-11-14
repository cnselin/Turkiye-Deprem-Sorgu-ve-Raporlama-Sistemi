#include <stdio.h> //standart kutuphaneler
#include <string.h>
#include <stdlib.h>
#define CS 2307685
#define ASS 17

int bul(char* dStr, char* kStr)   //strcmp
{
	int b1 = (int)strlen(dStr);
	int b2 = (int)strlen(kStr);
	int i = 0, j = 0, k = 0;

	for (; i < b1; i++) {

		if (dStr[i] == kStr[j]) {
			for (k = i, j = 0; j < b2; k++, j++) {
				if (dStr[k] != kStr[j])
					break;
				if (j == b2 - 1)
					return 0;
			}
		}
	}
	return 1;
}



int sorgula() {
	
	FILE* dosya;   //dosya tanımı
	FILE* kayit;

	dosya = fopen("earthquake.txt", "r+");   //dosya acma
	kayit = fopen("kayitliveri.txt", "w");
	char key, key1[20];   //degiskenler
	char key2[500];
	int i = 0, j = 0, verisay;

	printf("Lutfen Sorgulamak Istediginiz Il-Ilce, Zaman veya Richter Buyuklugunu Giriniz:"); //kullanicidan sorgulamak istedigi kelime istenildi
	scanf("%s", key1); 
	while (!feof(dosya))  //eofye kadar ilerleme
	{
		fscanf(dosya, "%c", &key);
		key2[i] = key;   //değişken doldurma
		if (key2[i] == '\n') {
			if (bul(key2, key1) == 0) {
				verisay++;
				int k = 0;
				for (k = 0; key2[k] != '\n'; k++) {
					printf("%c", key2[k]);
					fprintf(kayit, "%c", key2[k]);

				}
				printf("\n");
				fprintf(kayit, "\n");
                


			}
			i = -1;
		}
		i++;
	}
	fclose(dosya); //dosya kapama
	return verisay;
}

void sirala(int verisayisi) {  //fail

	int i = 0, j = verisayisi;
	char depremler[i][500], key, key1[20], key2[500];
	FILE* dosya;
	dosya = fopen("earthquake.txt", "r+");

	printf("Siralamak Istediginiz Olcutu (il-ilçe, zaman, richter buyuklugu) Giriniz:");  //kullanicidan siralamak istedigi kelime istenildi
	scanf("%s", key1);
	while (!feof(dosya))
	{
		fscanf(dosya, "%c", &key);
		key2[i] = key;
		if (key2[i] == '\n') {
			if (bul(key2, key1) == 0) {

				int k = 0;
				for (k = 0; key2[k] != '\n'; k++) {

					depremler[j][k] = key2[k];
				}
				j--;
			}
			i = -1;
		}
		i++;
	}


	for (; j < verisayisi; j++) {

		printf("%s\n", depremler[j]);
	}

}

void kaydet()
{

    FILE* dosya; //dosya tanımı 
	FILE* kayit;
	char ad[25];
	char ch;
	
	dosya = fopen("kayitliveri.txt", "r");   //dosya acma
	printf("Sorgulanan/Siralanan Verilerin Kaydolacagi Dosyanin Adini Giriniz:"); //kullanıcıdan dosya adi isteme
    scanf("%s",ad);
    char il[1000];
	sprintf(il, "%s.csv", ad);   //kullancıdan alınan ad ile csv formatında dosyayı kaydetme
	kayit=fopen(il,"w");  //dosyayı açma
    while ((ch = fgetc(dosya)) != EOF)
	fputc(ch, kayit);

    fclose(dosya);  //dosya kapama
    fclose(kayit);
    
}
int ayristir()
{

	FILE* dosya;  //dosya tanımı
	FILE* kayit;
	FILE* kayit2;
	char ch; //degisken

	dosya = fopen("earthquake.txt", "r+");   //dosya acma
	kayit = fopen("ayristir.txt", "w");
	char key, key1[20];   //degiskenler
	char key2[500];
	int i = 0, j = 0, verisay;
	
	printf("Lutfen Ayristirmak Istediginiz Ili Giriniz:");   //kullanıcıdan ili isteme
	scanf("%s", key1);

    char il[1000];
	sprintf(il, "%s.csv", key1);  //alınan ili csv formatında kayetme
	kayit2=fopen(il,"w");
	while (!feof(dosya))
	{
		fscanf(dosya, "%c", &key);
		key2[i] = key;
		if (key2[i] == '\n') {
			if (bul(key2, key1) == 0) {
				verisay++;
				int k = 0;
				for (k = 0; key2[k] != '\n'; k++) {
					printf("%c", key2[k]);
					fprintf(kayit, "%c", key2[k]);
					fprintf(kayit2, "%c", key2[k]);

				}
				printf("\n");
				fprintf(kayit, "\n");
				fprintf(kayit2, "\n");



			}
			i = -1;
		}
		i++;

	}

    fclose(dosya); //dosya kapama
    fclose(kayit);
    fclose(kayit2);
	return verisay;
}
int analiz() //fail
{
	
}




