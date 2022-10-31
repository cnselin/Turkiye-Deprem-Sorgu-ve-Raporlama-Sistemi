#include <stdio.h>
#include "ali.h"
#include "selin.h"
	
int main (){
	int i=0,j=0;
	
	
	printf("DEPREM SORGU VE RAPORLAMA SISTEMINE HOSGELDINIZ\n");
	
	for(;i<1||i>6;){
	
	printf("Lutfen yapmak isteginiz islemi seciniz \n"
	"[1]-Sorgulama\n"
	"[2]-Siralama\n"
	"[3]-Kaydetme\n"
	"[4]-Ayristirma\n"
	"[5]-Analiz\n"
	"[6]-Cikis\n"
	);
	
	scanf("%d",&i);
}
	for(;j==0;){
		
		switch (i){
			
			case 1:
				sorgula();
				
			case 2:
				sirala();
			case 3:	
			kaydet();
			case 4:
				ayristir();
			case 5:
				analiz();
			case 6:
			j=1;			
		}
			
	}

	return 0;
}
