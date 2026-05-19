#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "song_src.h"
#include "playlist.h"       //Für Aufgabe 2

int main() {

    //1.AUFGABE
    /*Die Funktion get_song() kann nicht alle 3 Werte per return zurückgeben.
    C erlaubt nur einen Rückgabewert.
    Deshalb müssen wir vorher den Speicher bereitstellen

    2 Möglichkeiten für den Speicher:
    //1. Heap (mit malloc, muss manuell freigegeben werden)
    uint32_t *id = malloc(sizeof(uint32_t));
    char *title = malloc(MAX_TITLE_LENGTH * sizeof(char));
    char *artist = malloc(MAX_ARTIST_LENGTH * sizeof(char));

    get_song(id, title, artist);
    free(id);
    free(title);
    free(artist);


    //2. Stack (einfacher, automatisch freigegeben)
    uint32_t id;
    char title[MAX_TITLE_LENGTH];       //aus song_src.h
    char artist[MAX_ARTIST_LENGTH];     //aus song_src.h
    

    //get_song() aufrufen, bis alle Songs gelesen sind
    while(get_song(&id, title, artist) >= 0){
        printf("ID: %u | Artist: %s | Title: %s\n", id, artist, title);
    }
    */

    //2. AUFGABE
    node_t *head = NULL;        //Kopf der Liste, erstmal leer

    while(1){
        node_t *new_node = malloc(sizeof(node_t));
        new_node->next = NULL;    

        //get_song() aufrufen
        int result = get_song(&new_node->id, new_node->title, new_node->artist);

        //wenn keine Songs mehr
        if(result < 0){
            free(new_node);
            break;
        }

        //Node an das Ende der Liste hängen
        if(head == NULL){
            head = new_node;
        } else {
            //durch Liste laufen bis zum letzten Element
            node_t *current = head;
            while(current->next != NULL){
                current = current->next;
            }
            current->next = new_node;
        }
    }

    //Liste ausgeben
    print_playlist(head);

    return 0;
}
