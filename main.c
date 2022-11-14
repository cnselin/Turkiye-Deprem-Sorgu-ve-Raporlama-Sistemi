#include <stdio.h> //standart kutuphaneler 
#include <stdlib.h> 
#include <string.h> 
#include "arayuz.h" //arayuz ve menu icin olusturulmus kutuphane
#include "fonksiyon.h" //fonskiyonların olduğu header dosyası

int main () {  //main fonksiyonu
    
    FILE *dosya;  //dosya tanımı
    dosya=fopen("earthquake.txt","r");   //verilerin olduğu dosyayı açma
    
    if(dosya==NULL) {
        printf("DOSYA BULUNAMADI!\n");  //eger dosyaya erisilemiyorsa ekrana yazma
    }
basla:;  
int secim=menu();     //fonksiyon cagirma
//int verisayisi=sorgula();

switch(secim)  //menü secim
 {
    case 1:
    sorgula();  //her secimde istenilen fonksiyonu cagirdik
    break;
    
    case 2:
    //sirala(verisayisi);
    break;
    
    case 3:
    sorgula();
    kaydet();
    break;
    
    case 4:
    ayristir();
    break;
    	
    case 5:
    //analiz();
    break;
    
    case 6:
    printf("Gorusmek Uzere :)\n"); //kullnıcı cikis yapti
    break;
    
}
    int karar;
	printf("Menuye Tekrar Donmek Ister Misiniz? Evet ise (1), Hayir ise (0) Giriniz:"); //herhangi bir secim yapıldıktan sonra kullaniciya tekrardan secim yapacagi soruldu
	scanf("%d",&karar);
	switch(karar)
	{
	case 1:
		goto basla; // evet ise basla kısmına goto il gönderildi
		break;
	case 0:           //hayır ise uygulama sona ercek
		break;
	default:          //hatalı giriste uygulama sona erecek
	    break;
	}
    
   fclose(dosya);  //dosya kapama
    return 0;
}
