#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>	

int main (int argc, char** argv)
{
	if(argc != 3 )
	{
		printf("usage :: ./read <file_in> <file_out>\n");
		exit(EXIT_FAILURE);
	}
		
//~~~~~~~~~~ ouverture fichier entree ~~~~~~~~~~//
	FILE* file_in = NULL;
	file_in = fopen(argv[1], "r+");
	if(file_in == NULL)
	{
		printf("fatal error :: cannot open input file\n");
		exit(EXIT_FAILURE);
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//


//~~~~~~~~~~ ouverture fichier sortie ~~~~~~~~~~//
	FILE* file_out = NULL;
	file_out = fopen(argv[2], "w+");
	if(file_out == NULL)
	{
		printf("fatal error :: cannot open output file\n");
		exit(EXIT_FAILURE);
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
	double tab[11] = {0};
	int cpt = 0;
	
	//while (!feof(file_in))
	do
	{
		fscanf(file_in, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &tab[0], &tab[1], &tab[2], &tab[3], &tab[4], &tab[5], &tab[6], &tab[7], &tab[8], &tab[9], &tab[10]);
		for(int i = 0; i <= 10; i++)
		{	
			printf("tab[%d] = %lf ",i,tab[i]);
			printf("\n");
		}
		cpt++;
		fprintf(file_out,"EVENT %d\nDate = %lf ; NbThymio = %lf ; NbEvent = %lf ; NbArgEvent = %lf\n",cpt,tab[0],tab[1],tab[2],tab[3]);
		fprintf(file_out,"Sensor0 = %lf; Sensor1 = %lf; Sensor2 = %lf; Sensor3 = %lf; Sensor4 = %lf; Sensor5 = %lf; Sensor6 = %lf;\n",tab[4],tab[5],tab[6],tab[7],tab[8],tab[9],tab[10]);
		fprintf(file_out,"\n\n");
		
	}while (!feof(file_in));
	
	fclose(file_in);
	fclose(file_out);
	return EXIT_SUCCESS;

}
	
	
	
		
		
