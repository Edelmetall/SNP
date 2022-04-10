/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 */
/**
 * @file
 * @brief Lab implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "list.h"

static node_t anchor;

/**
 * @brief Main entry point.
 * @param[in] argc  The size of the argv array.
 * @param[in] argv  The command line arguments...
 * @returns Returns EXIT_SUCCESS (=0) on success, EXIT_FAILURE (=1) there is an expression syntax error.
 */
void readLine(char *prompt, char *ref, size_t size) {
    printf("%s", prompt);
    char *buffer = malloc(sizeof(char) * size);
    char *index = buffer;
    int c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (index <= buffer + size - 1) {
            *(index++) = c;
        }
    }
    memcpy(ref, buffer, size - 1);
    free(buffer);
}

person_t *readPerson() {
    person_t *person = malloc(sizeof(person_t));

    if (person) {
        readLine("Name: ", person->name, NAME_LEN);
        readLine("Firstname: ", person->first_name, NAME_LEN);

        char input[10];
        readLine("Age: ", input, 10);
        sscanf(input, "%u", &person->age);
    }

    return person;
}

void printPerson(person_t *person, unsigned int index) {
    printf("%u: %s %s, %u\n", index + 1, person->name, person->first_name, person->age);
}

int main(int argc, char *argv[]) {
    // BEGIN-STUDENTS-TO-ADD-CODE

    // Am anfang ist die liste leer -> anchor zeigt auf sich selber
    anchor.next = &anchor;

    int input;
    person_t *person;


    do {
        char line[2];
        readLine("Type: I(nsert), R(emove), S(how), C(lear), E(nd)", line, 2);
        input = line[0];
        switch (input) {
            case 'I':
                person = readPerson();
                if (person) {
                    printf("Insert %s %s (Age %u)\n", person->first_name, person->name, person->age);
                    insert_node(&anchor, person);
                } else {
                    fprintf(stderr, "No memory to read person.\n");
                }
                break;
            case 'R':
                person = readPerson();
                if (person) {
                    printf("Remove %s %s (Age %u)\n", person->first_name, person->name, person->age);
                    remove_node(&anchor, person);
                } else {
                    fprintf(stderr, "No memory to read person.\n");
                }
                break;
            case 'S':
                printf("All entries:\n");
                forEach(&anchor, printPerson);
                break;
            case 'C':
            case EOF:
            case 'E':
                clear_list(&anchor);
                break;

            default:
                // do nothing
                break;
        }
    } while (input != EOF && input != 'E');


    // END-STUDENTS-TO-ADD-CODE
    return EXIT_SUCCESS;
}
