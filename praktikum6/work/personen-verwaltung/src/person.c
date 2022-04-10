#include "person.h"
#include <string.h>

int person_compare(const person_t *a, const person_t *b) {

    // Die string sollten nicht laenger als NAME_LEN sein.
    // Hier arbeiten wir mit dem arrow operator : (pointer_name)->(variable_name)
    int cmp = strncmp(a->name, b->name, NAME_LEN);
    if (cmp == 0) {
        cmp = strncmp(a->first_name, b->first_name, NAME_LEN);
        if (cmp == 0) {
            return a->age - b->age;
        } else {
            return cmp;
        }
    } else {
        return cmp;
    }
}