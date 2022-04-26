#include <stdlib.h>

#include "list.h"
#include "person.h"

int insert_node(node_t *anchor, person_t *p) {
    node_t *next = anchor->next;
    node_t *prev = anchor;
    while (next != anchor && person_compare(next->content, p) < 0) {
        prev = next;
        next = next->next;
    }

    if (next != anchor) {
        if (person_compare(next->content, p) == 0) {
            return 0;
        }
    }

    node_t *node = malloc(sizeof(node_t));
    if (node) {
        node->content = p;
        node->next = next;
        prev->next = node;
        return 1;
    }
    return 0;
}

void forEach(node_t *anchor, void (*fun)(person_t *, unsigned int index)) {
    node_t *next = anchor->next;
    unsigned int index = 0;
    while (next != anchor) {
        fun(next->content, index++);
        next = next->next;
    }
}

int remove_node(node_t *anchor, person_t *p) {
    node_t *last = anchor;
    node_t *curr = anchor->next;
    while (curr != anchor) {
        if (person_compare(p, curr->content) == 0) {
            last->next = curr->next;
            free(curr->content);
            free(curr);
            return 1;
        }
        last = curr;
        curr = curr->next;
    }
    return 0;
}

int clear_list(node_t *anchor) {
    node_t *next = anchor->next;
    while (next != anchor) {
        node_t *curr = next;
        next = curr->next;
        free(curr->content);
        free(curr);
    }
    anchor->next = anchor;
    return 1;
}