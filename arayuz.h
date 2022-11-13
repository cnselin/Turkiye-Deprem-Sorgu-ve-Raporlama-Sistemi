#include<stdio.h>

int menu ()
{
    int secim=0;
   
    printf("\n");
    printf("     TURKIYE DEPREM RAPOR VE SORGULAMA SISTEMINE HOS GELDINIZ!     \n"); 
    printf("\n");
    
    printf("(1) SORGULAMA\n");
    printf("(2) SIRALAMA\n"); 
    printf("(3) KAYDETME\n");
    printf("(4) AYRISTIRMA\n");
    printf("(5) ANALIZ\n");
    printf("(6) CIKIS\n");
    printf("SECIMINIZ: ");
    scanf("%d",&secim);
    
    

    return secim;
}

