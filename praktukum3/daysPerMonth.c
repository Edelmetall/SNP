#include <stdio.h>
#include <stdlib.h>
enum month_t { JAN=1, FEB=2, MAR=3, APR=4, MAI=5, JUN=6, JUL=6,
    AUG=8, SEP=9, OKT=10, NOV=11, DEZ=12 };

void clear_stdin (void) /* simple helper-function to empty stdin */
{
    int c = getchar();

    while (c != '\n' && c != EOF)
        c = getchar();
}

int gibIntWert(char *name, int min, int max){
    int input;
    do{
        (void)printf("%s:",name);
        scanf("%d",&input);
        clear_stdin();
    }while(input < min || input > max);

}
int istSchaltjahr(int jahr){
    if (jahr % 100 == 0 && jahr % 400 == 0){
        return 1;
    }else if(jahr % 100 > 0 && jahr % 4 == 0 ){
        return 1;
    }else{
        return 0;
    }
}
int tageProMonat(int jahr, int monat){
    if(monat == FEB){
        return 28 + istSchaltjahr(jahr);
    }else{
        switch(monat){
            case JAN: case MAR: case MAI: case JUL:
            case AUG: case OKT: case DEZ: return 31;
            default: return 30;
        }

    }
}

int main(void){

    int monat, jahr;

    //  Monat einlesen und Bereich ueberpruefen
    monat = gibIntWert("Monat", 1, 12);
    jahr  = gibIntWert("Jahr", 1600, 9999);

    //  Ausgabe zum Test
    printf("Monat: %d, Jahr: %d \n", monat, jahr);

    //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
    printf("%d ist %s Schaltjahr\n", jahr, istSchaltjahr(jahr) ? "ein" : "kein");

    // Ausgabe
    printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr, tageProMonat(jahr, monat));

    return 0;
}