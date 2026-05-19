#include "playlist.h"


int insert_at_end(node_t *head, node_t *new_node) {
    if (!head) return -1;
    node_t *current = head;
    while(current->next != 0) {
        current = current->next;
    }
    current->next = new_node;
    return 0;
}


int insert_after_pos(node_t *head, node_t *new_node, size_t pos) {
    if (!head) return -1;

    node_t *current = head;

    size_t cnt = 0;
    while (current != 0) {
        if (pos == cnt++) {
            new_node->next = current->next;
            current->next = new_node;
            return 0;
        }
        current = current->next;
    }
    return -1;
}


int count_elements(node_t *head) {
    if (!head) return -1;

    int count = 0;
    node_t *current = head;
    while(current != 0){
        count++;
        current = current->next;
    }
    return count;
}


node_t *get_element(node_t *head, size_t pos) {
    if (!head) return 0;

    node_t *current = head;
    size_t cnt = 0;
    while (current != 0) {
        if (pos == cnt++) {
            return current;
        }
        current = current->next;
    }
    return 0;
}

void print_playlist(node_t *head) {
    node_t *current = head;
    while (current != 0) {
        printf("ID: 0x%X\n", current->id);
        printf("Artist: %s\n", current->artist);
        printf("Song: %s\n\n", current->title);
        current = current->next;
    }
}


int remove_by_id(node_t *head, uint32_t id) {
    if (!head) return -1;

    node_t *current = head;
    node_t *previous = 0;

    while (current != 0) {
        if (current->id == id) {
            if (previous == 0) {
                // The node to be removed is the head
                return -1;
            } else {
                // The node to be removed is not the head
                previous->next = current->next;
            }
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    // Song with the given ID not found in the playlist
    return -1;
}


int remove_by_pos(node_t *head, size_t pos) {
    if (!head) return -1;
    if (pos == 0) return -1;    //Head darf nicht entfernt werden

    node_t *current = head;
    node_t *previous = NULL;
    size_t cnt = 0;

    while (current != NULL) {
        if (cnt == pos) {
            previous->next = current->next;
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
        cnt++;
    }
    return -1;  //Position nicht gefunden
}


int move_up(node_t *head, size_t pos) {
    if (!head) return -1;
    if (pos <= 1) return -1;    //Position 0 und 1 können nicht nach oben

    node_t *prev = get_element(head, pos-1);
    node_t *curr = get_element(head, pos);

    if(!prev || !curr) return -1;

    //Daten tauschen
    uint32_t tmp_id = prev->id;
    char tmp_title[MAX_TITLE_LENGTH];
    char tmp_artist[MAX_ARTIST_LENGTH];

    strcpy(tmp_title, prev->title);
    strcpy(tmp_artist, prev->artist);

    prev->id = curr->id;
    strcpy(prev->title, curr->title);
    strcpy(prev->artist, curr->artist);

    curr->id = tmp_id;
    strcpy(curr->title, tmp_title);
    strcpy(curr->artist, tmp_artist);

    return 0;
}


int move_down(node_t *head, size_t pos) {
    if (!head) return -1;
    
    node_t *curr = get_element(head, pos);
    node_t *next = get_element(head, pos+1);

    if(!curr || !next) return -1;
    if (pos == 0) return -1;        //Head darf nicht verschoben werden

    //Daten tauschen
    uint32_t tmp_id = curr->id;
    char tmp_title[MAX_TITLE_LENGTH];
    char tmp_artist[MAX_ARTIST_LENGTH];

    strcpy(tmp_title, curr->title);
    strcpy(tmp_artist, curr->artist);

    curr->id = next->id;
    strcpy(curr->title, next->title);
    strcpy(curr->artist, next->artist);

    next->id = tmp_id;
    strcpy(next->title, tmp_title);
    strcpy(next->artist, tmp_artist);

    return 0;
}