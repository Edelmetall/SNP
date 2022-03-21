#include <stdio.h>
#define NUM_ROWS 8
int main()
{
	int v;			// Nächster CHF-Wert
	double bitcoin;	 	// BITCOIN Umrechnungs-Faktor
	int i; 			// Zähler
	int rows = NUM_ROWS; 	// Maximale Anzah an Rows
	double u;		// Wert in Bitcoin umgerechnet

	printf("Enter conversion rate (1.00 BTC -> CHF): \n");
	scanf("%lf", &bitcoin);

	printf("\n");
	for (i = 0; i < rows; ++i)
	{
		v = 200 + i * 200;
		u = v / bitcoin;
		
		printf("%5d %s %.5f %s",v,"CHF    <-->   ", u, " BTC \n");
	}
	return 0;
}

