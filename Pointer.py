#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void){
  int a ;       
  a = 10;
  int* p;            //pointer deklarieren          
  p = &a;            //pointer initialisieren    

  int x = 20;         //Adresse = 0x1 , wert = 20   
  int* px = &x;       //Adresse = 0x2 , wert = 0x1
  int** ppx = &px;    //Adresse = 0x3 , wert = 0x2
    
  printf("Wert von a = %d\n", a);
  printf("Wert von a = %d\n", *p);    //* : derefenziert p --> Wert von a
  //dereferenziert p: (geht zu der Adresse, die in p drinnen steht und nimmt den Wert davon)
  printf("Adresse von a = %p\n", p); 
  printf("Adresse von a = %p\n", &a);
  printf("Wert von x = %d\n", x);
  printf("Wert von x = %d\n", *px);
  printf("Wert von x = %d\n", **ppx);
  printf("Adresse von x = %p\n", &x);
  printf("Adresse von x = %p\n", px);
}
