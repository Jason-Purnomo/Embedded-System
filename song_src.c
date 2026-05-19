#include "song_src.h"

FILE *file = 0;

int get_song(uint32_t *id, char *title, char *artist) {
    if (file == 0) {
        file = fopen(SONG_FILE, "r");
        if (file == 0) {
            perror("Error opening file");
            return -1;
        }
    }

    char id_str[12]; // 32-bit hex + null terminator
    while(1) {
        if (fgets(id_str, sizeof(id_str), file) == 0) {
            fclose(file);
            file = 0;
            return -1; // End of file
        }
        if (id_str[0] != '\n') break;
    }

    if (fgets(artist, MAX_ARTIST_LENGTH, file) == 0) {
        fclose(file);
        file = 0;
        return -1; // End of file
    }

    if (fgets(title, MAX_TITLE_LENGTH, file) == 0) {
        fclose(file);
        file = 0;
        return -1; // End of file
    }

    // Remove newline characters
    artist[strcspn(artist, "\n")] = '\0';
    title[strcspn(title, "\n")] = '\0';

    // Convert hex string to unsigned int
    *id = strtoul(id_str, 0, 16);

    return 0;
}