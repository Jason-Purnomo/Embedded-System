#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct Person{
  uint8_t alter;
  char* name;      // oder char name[20];
  char* nachname;  // oder char nachname[20];
  char geschlecht;  
  struct Person* Geschwister;
};

int main(void){
  struct Person Jason;
    Jason.alter = 22;
    Jason.name = "Jason";
    Jason.nachname = "Purnomo";
    Jason.geschlecht = 'm';

  struct Person Elaine = {21, "Elaine", "Purnomo", 'f', &Jason};
  printf("Name: %s, Nachname: %s, Alter: %d, Geschlecht: %c\n", Elaine.name, Elaine.nachname, Elaine.alter, Elaine.geschlecht);
  
  printf("Alter von Jason: %d\n", Elaine.Geschwister->alter);
  //oder printf("Alter von Jason: %d\n", (*Elaine.Geschwister).alter);
  
  return 0;
}
