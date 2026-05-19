#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_ARTIST_LENGTH 100
#define MAX_TITLE_LENGTH 100


typedef struct playlist_node_s {
    uint32_t id;
    char artist[MAX_ARTIST_LENGTH];
    char title[MAX_TITLE_LENGTH];
    struct playlist_node_s *next;
} node_t;

/**
 * @brief Adds a node add the end of the list
 *
 * @param head The head node of the list
 * @param new_node The node to be added
 * @return error code: 0 if successfull, -1 otherwise
 */
int insert_at_end(node_t *head, node_t *new_node);

/**
 * @brief Add a note at (after) a specific position in the list
 *
 * @param head The head node of the list
 * @param new_node The node to be added
 * @param pos The position in the list after which the new node is inserted
 * @return error code: 0 if successfull, -1 otherwise
 */
int insert_after_pos(node_t *head, node_t *new_node, size_t pos);

/**
 * @brief Get the number of elements of the list
 *
 * @param head The head node of the list
 * @return The number of nodes in the list, -1 if there was an error
 */
int count_elements(node_t *head);

/**
 * @brief Get a node at a specific position
 *
 * @param head The head node of the list
 *
 * @return A pointer to the node at the requested position. 0 if this element
 *         could not be retrieved (e.g. pos greater than the size of the list)
 */
node_t *get_element(node_t *head, size_t pos);

/**
 * @brief Print the playlist on the standard ouput
 *
 * @param head The head node of the list
 */
void print_playlist(node_t *head);

/**
 * @brief Removes the song with a specific ID from the list
 *
 * Note that it is not possible to remove the head node.
 * This function frees the memory of the removed node
 *
 * @param head The head node of the list
 * @param id The ID of the song to be removed
 *
 * @return error code: 0 if successfull, -1 otherwise
 */
int remove_by_id(node_t *head, uint32_t id);

/**
 * @brief Removes the song at the given position from the list
 *
 * Note that it is not possible to remove the head node.
 * This function frees the memory of the removed node
 *
 * @param head The head node of the list
 * @param pos The position of the song in the list to be removed
 *
 * @return error code: 0 if successfull, -1 otherwise
 */
int remove_by_pos(node_t *head, size_t pos);

/**
 * @brief Move the song with the given ID up one position
 *
 * Note that it is not possible to modify the head node, hence, the list has
 * to have at least 3 nodes, such that something can be moved.
 *
 * @param head The head node of the list
 * @param pos The position of the song to be moved up
 *
 * @return error code: 0 if successfull, -1 otherwise
 */
int move_up(node_t *head, size_t pos);

/**
 * @brief Move the song at the given position down one position
 *
 * Note that it is not possible to modify the head node, hence, the list has
 * to have at least 3 nodes, such that something can be moved.
 *
 * @param head The head node of the list
 * @param pos The position of the song to be moved down
 *
 * @return error code: 0 if successfull, -1 otherwise
 */
int move_down(node_t *head, size_t pos);