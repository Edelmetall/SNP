//
// Created by chime on 10/04/2022.
//

#ifndef SNP_LIST_H
#define SNP_LIST_H

#include "person.h"

typedef struct node {
    person_t content;
    struct node *next;

} node_t;

int insert_node(node_t *anchor, person_t *p);

int remove_node(node_t *anchor, person_t *p);

int clear_list(node_t *anchor);

// sollte eine liste anbieten
void forEach(node_t *anchor, void (*fun)(person_t*, unsigned int index));

#endif //SNP_LIST_H
