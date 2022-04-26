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
 * @brief Test suite for the given package.
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <assert.h>
#include <CUnit/Basic.h>
#include "test_utils.h"

#ifndef TARGET // must be given by the make file --> see test target
#error missing TARGET define
#endif

/// @brief alias for EXIT_SUCCESS
#define OK   EXIT_SUCCESS
/// @brief alias for EXIT_FAILURE
#define FAIL EXIT_FAILURE

/// @brief The name of the STDOUT text file.
#define OUTFILE "stdout.txt"
/// @brief The name of the STDERR text file.
#define ERRFILE "stderr.txt"

#define TRACE_INDENT "\n                " ///< allow for better stdout formatting in case of error

#include "../src/person.h"
#include "../src/list.h"

node_t *anchor;

person_t *seb;
person_t *seb2;
person_t *olivia;
person_t *fabia;

// setup & cleanup
static int setup(void) {
    // do nothing
    return 0; // success
}

static int teardown(void) {
    // Do nothing.
    // Especially: do not remove result files - they are removed in int setup(void) *before* running a test.
    return 0; // success
}

static void beforeEach(void) {
    anchor = malloc(sizeof(node_t));
    anchor->next = anchor;

    seb = malloc(sizeof(person_t));
    strcpy(seb->name, "Brunner");
    strcpy(seb->first_name, "Sebastian");
    seb->age = 22;

    seb2 = malloc(sizeof(person_t));
    strcpy(seb2->name, "Brunner");
    strcpy(seb2->first_name, "Sebastian");
    seb2->age = 23;

    olivia = malloc(sizeof(person_t));
    strcpy(olivia->name, "Brunner");
    strcpy(olivia->first_name, "Olivia");
    olivia->age = 19;

    fabia = malloc(sizeof(person_t));
    strcpy(fabia->name, "Müller");
    strcpy(fabia->first_name, "Fabia");
    fabia->age = 27; // almost 30, jeez

}

// tests
static void test_person_compare(void) {
    // BEGIN-STUDENTS-TO-ADD-CODE
    // arrange
    beforeEach();

    // act & assert
    CU_ASSERT_EQUAL(person_compare(seb, seb), 0);

    CU_ASSERT_TRUE(person_compare(seb, seb2) < 0);
    CU_ASSERT_TRUE(person_compare(seb2, seb) > 0);

    CU_ASSERT_TRUE(person_compare(seb, olivia) > 0);
    CU_ASSERT_TRUE(person_compare(olivia, seb) < 0);

    CU_ASSERT_TRUE(person_compare(seb, fabia) < 0);
    CU_ASSERT_TRUE(person_compare(fabia, seb) > 0);

    // END-STUDENTS-TO-ADD-CODE
}

static void test_list_insert(void) {
    // BEGIN-STUDENTS-TO-ADD-CODE
    // arrange
    beforeEach();

    // act
    int result = insert_node(anchor, seb);

    // assert
    CU_ASSERT_EQUAL(result, 1);
    CU_ASSERT_EQUAL(anchor->next->content, seb);

    // END-STUDENTS-TO-ADD-CODE
}

static void test_list_remove(void) {
    // BEGIN-STUDENTS-TO-ADD-CODE
    // arrange
    beforeEach();
    insert_node(anchor, seb);
    insert_node(anchor, olivia);

    // act
    int result = remove_node(anchor, seb);
    int result2 = remove_node(anchor, fabia);

    // assert
    CU_ASSERT_EQUAL(result, 1);
    CU_ASSERT_EQUAL(result2, 0);
    CU_ASSERT_EQUAL(anchor->next->content, olivia);

    // END-STUDENTS-TO-ADD-CODE
}

static void test_list_clear(void) {
    // BEGIN-STUDENTS-TO-ADD-CODE
    // arrange
    beforeEach();
    insert_node(anchor, seb);
    insert_node(anchor, olivia);
    insert_node(anchor, fabia);

    // act
    int result = clear_list(anchor);

    // assert
    CU_ASSERT_EQUAL(result, 1);
    CU_ASSERT_EQUAL(anchor->next, anchor);

    // END-STUDENTS-TO-ADD-CODE
}

/**
 * @brief Registers and runs the tests.
 * @returns success (0) or one of the CU_ErrorCode (>0)
 */
int main(void) {
    // setup, run, teardown
    TestMainBasic("lab test", setup, teardown, test_person_compare, test_list_insert, test_list_remove,
                  test_list_clear);
}