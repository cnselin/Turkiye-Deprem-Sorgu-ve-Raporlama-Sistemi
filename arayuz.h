#include<stdio.h> //standart kutuphane

int menu ()  //menu fonksiyonu
{
    int secim=0;
   
    printf("\n");
    printf("     TURKIYE DEPREM RAPOR VE SORGULAMA SISTEMINE HOS GELDINIZ!     \n"); //uygulama girisi
    printf("\n");
    
    printf("(1) SORGULAMA ISLEMI\n");  //kullanıcının secebilecegi secimler
    printf("(2) SIRALAMA ISLEMI\n"); 
    printf("(3) KAYDETME ISLEMI\n");
    printf("(4) AYRISTIRMA ISLEMI\n");
    printf("(5) ANALIZ ISLEMI\n");
    printf("(6) CIKIS ISLEMI\n");
    printf("SECIMINIZ: "); //kullanici secim yapti
    scanf("%d",&secim);
    
    

    return secim;
}
