#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 100

#define SONG_FILE "songs.txt"

/**
 * @brief Returns the meta informations of the next song on the storage device
 * 
 * @param id memory address where the ID of the song will be placed
 * @param title memory address of the start of a buffer of at least 
 *              MAX_TITLE_LENGTH characters, where the string with the song
 *              title will be placed
 * @param artist memory address of the start of a buffer of at least
 *               MAX_ARTIST_LENGTH characters, where the string with the
 *               artist name will be placed
 * 
 * @return error code: 0 if successfull, negative number otherwise
 */
int get_song(uint32_t *id, char *title, char *artist);