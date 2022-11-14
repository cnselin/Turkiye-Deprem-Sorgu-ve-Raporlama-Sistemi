#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CS 2307685
#define ASS 17

int bul(char* dStr, char* kStr)
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
	
	FILE* dosya;
	FILE* kayit;

	dosya = fopen("earthquake.txt", "r+");
	kayit = fopen("kayitliveri.txt", "w");
	char key, key1[20];
	char key2[500];
	int i = 0, j = 0, verisay;

	printf("Lutfen Sorgulamak Istediginiz Il-Ilce, Zaman veya Richter Buyuklugunu Giriniz:");
	scanf("%s", key1); 
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

				}
				printf("\n");
				fprintf(kayit, "\n");
                


			}
			i = -1;
		}
		i++;
	}
	fclose(dosya);
	return verisay;
}

void sirala(int verisayisi) {

	int i = 0, j = verisayisi;
	char depremler[i][500], key, key1[20], key2[500];
	FILE* dosya;
	dosya = fopen("earthquake.txt", "r+");

	printf("Siralamak Istediginiz Olcutu (il-ilçe, zaman, richter buyuklugu) Giriniz:");
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

    FILE* dosya;
	FILE* kayit;
	char ad[25];
	char ch;
	
	dosya = fopen("kayitliveri.txt", "r"); 
	printf("Sorgulanan/Siralanan Verilerin Kaydolacagi Dosyanin Adini Giriniz:");
    scanf("%s",ad);
    char il[1000];
	sprintf(il, "%s.csv", ad);
	kayit=fopen(il,"w");
    while ((ch = fgetc(dosya)) != EOF)
	fputc(ch, kayit);

    fclose(dosya);
    fclose(kayit);
    
}
int ayristir()
{

	FILE* dosya;
	FILE* kayit;
	FILE* kayit2;
	char ch;

	dosya = fopen("earthquake.txt", "r+");
	kayit = fopen("ayristir.txt", "w");
	char key, key1[20];
	char key2[500];
	int i = 0, j = 0, verisay;
	
	printf("Lutfen Ayristirmak Istediginiz Ili Giriniz:");
	scanf("%s", key1);

    char il[1000];
	sprintf(il, "%s.csv", key1);
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

    fclose(dosya);
    fclose(kayit);
    fclose(kayit2);
	return verisay;
}





