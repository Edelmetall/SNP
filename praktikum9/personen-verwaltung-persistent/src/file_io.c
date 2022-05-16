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

#include "file_io.h"
#include "person.h"
#include "list.h"

void perror_and_exit(const char *context) { perror(context); exit(EXIT_FAILURE); } // das muss noch an einen anderen Ort, scia

// May divide your code in further functions
// BEGIN-STUDENTS-TO-ADD-CODE
	   FILE *fp;
// END-STUDENTS-TO-ADD-CODE

void store_person_list(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	person_t* person = list_getFirst();
	char *buff ;

	fp = fopen("person_list.csv", "w");

	while(person!= NULL){
	   buff = malloc(sizeof(char)*255);
	   person_to_csv_string(person,buff);
	   fputs(buff, fp);
	   fputs("\n",fp);
	   person = list_getNext();
	}

	   fclose(fp);
	// END-STUDENTS-TO-ADD-CODE
}

void load_person_list(void)
{
	// BEGIN-STUDENTS-TO-ADD-CODE
	char buff[255] ;

	fp = fopen("person_list.csv", "r");

	while(fgets(buff, 255, fp)!=NULL){
		person_t *person = malloc(sizeof(person_t));
		person_from_csv_string(person, buff);
		list_insert(person);
	}
	fclose(fp);
	// END-STUDENTS-TO-ADD-CODE
}
