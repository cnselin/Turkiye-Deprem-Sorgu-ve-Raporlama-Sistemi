#include <stdio.h> //standart kutuphaneler 
#include <stdlib.h> //standart kutuphaneler 
#include <string.h> //standart kutuphaneler 
#include "arayuz.h" //arayuz ve menu icin olusturulmus kutuphane
#include "fonksiyon.h"

int main () {
    
    FILE *dosya;
    dosya=fopen("earthquake.txt","r");
    
    if(dosya==NULL) {
        printf("DOSYA BULUNAMADI!\n");
    }
basla:;
int secim=menu();    
//int verisayisi=sorgula();

switch(secim)
 {
    case 1:
    sorgula();
    break;
    
    case 2:
    //sirala(verisayisi);
    break;
    
    case 3:
    kaydet();
    break;
    
    case 4:
    ayristir();
    break;
    	
    case 5:

    break;
    
    case 6:
    break;
    
}
    int karar;
	printf("Menuye Tekrar Donmek Ister Misiniz? Evet ise (1), Hayir ise (0) Giriniz:");
	scanf("%d",&karar);
	switch(karar)
	{
	case 1:
		goto basla;
		break;
	case 0:
		break;
	default:
	    break;
	}
    
   fclose(dosya);
    return 0;
}
