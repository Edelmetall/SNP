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
 * @brief Lab P02 weekday
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


// *** TASK1: typedef enum types for month_t (Jan=1,...Dec} ***
// BEGIN-STUDENTS-TO-ADD-CODE
enum month_t { Jan=1, Feb=2, Mar=3, Apr=4, Mai=5, Jun=6, Jul=7,
    Aug=8, Sep=9, Oct=10, Nov=11, Dec=12 };

// END-STUDENTS-TO-ADD-CODE



// *** TASK1: typedef struct for date_t ***
// BEGIN-STUDENTS-TO-ADD-CODE
struct date_t{
    int year; int month; int day;
};

typedef struct date_t date_t;
// END-STUDENTS-TO-ADD-CODE



// *** TASK2: typedef enum weekday_t (Sun=0, Mon, ...Sat) ***
// BEGIN-STUDENTS-TO-ADD-CODE
typedef enum weekday_t { Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thu = 4, Fri = 5, Sat = 6}weekday_t;

// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is a leap year.
 * @returns 0 = is not leap year, 1 = is leap year
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_leap_year(date_t date){
    if (date.year % 100 == 0 && date.year % 400 == 0){
        return 1;
    }else if(date.year % 100 > 0 && date.year % 4 == 0 ){
        return 1;
    }else{
        return 0;
    }
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Calculates the length of the month given by the data parameter
 * @returns 28, 29, 30, 31 if a valid month, else 0
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int get_month_length(date_t date){
    if(date.month == Feb){
        return 28 + is_leap_year(date);
    }else{
        switch(date.month){
            case Jan: case Mar: case Mai: case Jul:
            case Aug: case Oct: case Dec: return 31;

            case Apr: case Jun: case Sep: case Nov: return 30;
            default: return 0;
        }

    }
}
// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   TASK1: Checks if the given date is in the gregorian date range
 * @returns 0 = no, 1 = yes
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_gregorian_date(date_t date){
    if(date.year < 1582 || date.year > 9999 ) return 0;

    if( (1582 + Oct + 15) > (date.year + date.month+ date.day)){
        return 0;

    }else{ return 1; }
}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK1: Checks if the given date is a valid date.
 * @returns 0 = is not valid date, 1 = is valid date
 */
// BEGIN-STUDENTS-TO-ADD-CODE
int is_valid_date(date_t date){
    if (date.year > 9999) return 0;
    if (is_gregorian_date(date) == 0) return 0;
    if (date.month < Jan || date.month > Dec)return 0;
    if (date.day < 1 || date.day > 31) return 0;
    if (date.day > get_month_length(date) )return 0;

    return 1;

}

// END-STUDENTS-TO-ADD-CODE


/**
 * @brief   TASK2: calculated from a valid date the weekday
 * @returns returns a weekday in the range Sun...Sat
 */
// BEGIN-STUDENTS-TO-ADD-CODE
weekday_t calculate_weekday(date_t date){
    assert(is_valid_date(date));

    int m = 1 + (date.month + 9) % 12;
    int a = date.year < Mar ? date.year - 1 : date.year ;
    int y = a % 100;
    int c = a / 100;

    return ((date.day + (13 * m - 1) / 5 + y + y / 4 + c / 4 - 2 * c) % 7 + 7) % 7;
}

// END-STUDENTS-TO-ADD-CODE



/**
 * @brief   TASK2: print weekday as 3-letter abreviated English day name
 */
// BEGIN-STUDENTS-TO-ADD-CODE
static const char* days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
void print_weekday(weekday_t day){
    fprintf( stdout, "%s\n",days[day] );
}
// END-STUDENTS-TO-ADD-CODE

/**
 * @brief   main function
 * @param   argc [in] number of entries in argv
 * @param   argv [in] program name plus command line arguments
 * @returns returns success if valid date is given, failure otherwise
 */
int main(int argc, const char *argv[])
{
    // TASK1: parse the mandatory argument into a date_t variable and check if the date is valid
    // BEGIN-STUDENTS-TO-ADD-CODE
    date_t input;
    int res = sscanf(argv[1]
            , "%d-%d-%d"
            , &input.year, &input.month, &input.day
    );
    if (res != 3) {
        return EXIT_FAILURE;
    }
    if(is_valid_date(input) == 0){
        return EXIT_FAILURE;
    }
    // END-STUDENTS-TO-ADD-CODE


    // TASK2: calculate the weekday and print it in this format: "%04d-%02d-%02d is a %s\n"
    // BEGIN-STUDENTS-TO-ADD-CODE
    printf("%04d-%02d-%02d is a ", input.year,input.month,input.day);
    print_weekday(calculate_weekday(input));

    // END-STUDENTS-TO-ADD-CODE

    return EXIT_SUCCESS;
}