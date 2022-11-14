#include <stdio.h>
#include <string.h>


int bul(char* dStr, char* kStr)//strcmp
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
	FILE* dosya;//dosya tanımı
	FILE* kayit;

	dosya = fopen("earthquake.cvs", "r+");//dosya acma
	kayit = fopen("kayitliveri.cvs", "w");
	char key, key1[20];//degişkenler 
	char key2[500];
	int i = 0, j = 0, verisay;

	printf("lutfen aratmak istediginiz kelimeyi giriniz:");
	scanf("%s", key1);

	while (!feof(dosya))//eof ye kadar ilerleme 
	{
		fscanf(dosya, "%c", &key);
		key2[i] = key;//degişkene doldurma
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
	fclose(dosya);//dosya kapama 
	return verisay;
}



void sirala(int verisayisi) {//fail

	int i = 0, j = verisayisi;
	char depremler[i][500], key, key1[20], key2[500];
	FILE* dosya;
	dosya = fopen("earthquake.cvs", "r+");

	printf("lutfen aratmak istediginiz kelimeyi tekrar giriniz:");
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
