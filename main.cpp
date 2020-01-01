#include <iostream>
#include <fstream>
 #include <iomanip> 
using namespace std;

void swap(int &a , int &b){
	int temp ;
	temp = a ;
	a = b ;
	b = temp ;
	
}
// bubble sort vb için   kitaptan yararlandým 

;
int main() {

	int i = 0;
	int boyut =5 ; // ögrenci sayýsýna göre boyutu degistirmeniz lazým 	
	int m = 0  ;
    int soruSayisi ;
    string dogruCevap;
    string numaraVeCevap[boyut];
    string ogrenciNo[boyut];
    string cevaplar[boyut];
    string dCevap ;
    int toplam = 0 ;
    int sonucc[boyut] ;
    int enKucukNot ;
    int enBuyukNot ;
    float ortalama = 0 ;
    float ortalamaSonuc;
    float medyan  ;
    int aciklik ;
   
ifstream cevap;
cevap.open("sinav.txt");
 cevap>>soruSayisi ;
 cevap>>dogruCevap ;
  
for(i =0 ;i<boyut;i++){


 cevap>>numaraVeCevap[i];

}
	
cevap.close();
dCevap[m]=dogruCevap[i];
for(i= -1;i<(soruSayisi*2)-1;i++){
	i++;
		m++;
 dCevap+=dogruCevap[i];

	
}
  	
   
 for(i =0 ;i<boyut;i++){
 	
 	for(m =0 ;m<9;m++){
 	ogrenciNo[i] += numaraVeCevap[i][m];

 	
 }
    for(m=9;m<28;m++){
    	
    if(numaraVeCevap[i][m] ==','&&numaraVeCevap[i][m+1]==','){
    	
    	cevaplar[i] += "0" ;
    	
	}

    else{
    	cevaplar[i] +=numaraVeCevap[i][m+1];
    	m++;
	}
	
		
    	
    	
	}
 	
 	if(cevaplar[i][soruSayisi-1]!='A' && cevaplar[i][soruSayisi-1]!='B' && cevaplar[i][soruSayisi-1]!='C' && cevaplar[i][soruSayisi-1]!='D'){
		
		
		cevaplar[i][soruSayisi-1] = '0' ;
		
	}
	
for(m =0 ;m<soruSayisi;m++){
	
   if(cevaplar[i][m]==dCevap[m]){
   	toplam = toplam + 4 ;
   
   } 
   else if(cevaplar[i][m] == '0'){
   	
   	
   	toplam = toplam +0;
   }
   else{
   	
   	toplam = toplam -1;
   }
  
	
}       
 		
		 sonucc[i] = toplam ;
 	     if(sonucc[i]<0){
 	     	sonucc[i]=0;
		  }
 		toplam = 0;
 	
 }
 
 
 
 for(i=boyut-1;i>=0;i--){
 	
 	 for(m=0;m<=i-1;m++){
 	 	
 	 	if(sonucc[m]<sonucc[m+1]){
 	 		swap(ogrenciNo[m],ogrenciNo[m+1]);
 	 		swap(sonucc[m],sonucc[m+1]);
 	 		
		  }
 	 	
 	 	
	  }
 	
 	
 }
  for(i =0 ;i<boyut;i++){
  ortalama =  ortalama  + sonucc[i];
  
}
ortalamaSonuc = (ortalama / boyut);
   
   if(boyut%2 == 0){
   	
   	cout<<(sonucc[boyut/2]+sonucc[(boyut/2)-1])/2<<endl ;
   }else
   {
   	cout<<sonucc[boyut/2]<<endl;
   }
  enBuyukNot = sonucc[0];
  enKucukNot  = sonucc[boyut-1];
  aciklik  = enBuyukNot - enKucukNot ;
  cout<<ortalamaSonuc<<endl;  
  cout<<enBuyukNot<<endl;
  cout<<enKucukNot<<endl;
  cout<< aciklik<<endl;
  
  
 
ofstream bitis;
bitis.open("output.txt");

for(i =0 ;i<boyut;i++){
 	bitis<<ogrenciNo[i]<<","<<sonucc[i]<<endl;
 	
}

bitis<<"En Kucuk Not :"<<enKucukNot<<endl;	
bitis<<"En Buyuk Not :"<<enBuyukNot<<endl;	
bitis<<"Ortalama : "<<ortalamaSonuc<<endl;	
 if(boyut%2 == 0){
   	
   	bitis<<"Medyan   :"<<(sonucc[boyut/2]+sonucc[(boyut/2)-1])/2<<endl ;
   }else
   {
   	bitis<<"Medyan   :"<<sonucc[boyut/2]<<endl;
   }
bitis<<"Aciklik :"<<aciklik<<endl;   
bitis.close();
}



