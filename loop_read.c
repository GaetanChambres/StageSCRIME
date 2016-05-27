#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int NBR_STOP_EVENT = 7;		///// The ID of the event used to stoped the prgm
							///// according to aseba exemple file, event 7 = button.center pressed

int main(int argc, char** argv)
{

//~~~~~~~~~~ USAGE : error arg number ~~~~~~~~~~//	
		if(argc != 3 )
	{
		printf("usage :: ./read <file_in> <file_out>\n");
		exit(EXIT_FAILURE);
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//	

//~~~~~~~~~~~ Open INPUT file (arg1) ~~~~~~~~~~~//
	FILE* file_in = NULL;
	file_in = fopen(argv[1], "w+");
	if(file_in == NULL)
	{
		printf("fatal error :: cannot open input file\n");
		exit(EXIT_FAILURE);
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~ Open OUTPUT file (arg2) ~~~~~~~~~~~//
	FILE* file_out = NULL;
	file_out = fopen(argv[2], "w+");
	if(file_out == NULL)
	{
		printf("fatal error :: cannot open output file\n");
		return EXIT_FAILURE;
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~ Reading and treating ~~~~~~~~~~~~//
	
	double event_time = 0;	///// Timestamp of last treated event
	int cpt = 0;			///// Number of treated events
	double array[11] = {0};	///// creating the array with event description
	
//|----------------------------------------------------------------------------------------------------------------------------|//
//|	    0     |	    1 	  |	      2	 	 |	     3 	     |	  4	   |	 5 	 |	  6    |	7	 |	  8	   |    9    |	 10	   |//	
//|----------------------------------------------------------------------------------------------------------------------------|//
//| Timestamp | Thymio ID | Event Number | Size of Event | Sensor0 | Sensor1 | Sensor2 | Sensor3 | Sensor4 | Sensor5 | Sensor6 |// 
//|----------------------------------------------------------------------------------------------------------------------------|//


	while(array[2] != NBR_STOP_EVENT)		///// tab[2] refere to event nbr ;; according to aseba exemple file <=> while button center of Thymio not pressed
	{
		fscanf(file_in, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",		//// scan one line and stock each values in the array
				&array[0], &array[1], &array[2], &array[3], &array[4], &array[5], 
				&array[6], &array[7], &array[8], &array[9], &array[10]);
				
		if(array[0] != event_time)		///// if Timestamp of event currently scanned != Timestamp of previous event ;;	
										///// prevent from infinite loop treatment on the current event ;;
		{
			for(int i = 0; i <= 10; i++)
			{	
				printf("array[%d] = %lf ",i,array[i]);		//// debug help ;; disp the array for each new event treated
				printf("\n\n");
			}
			cpt++;		///// Updating number of events treated
			fprintf(file_out,"EVENT %d\nDate = %lf ; NbThymio = %lf ; NbEvent = %lf ; NbArgEvent = %lf\n",cpt,array[0],array[1],array[2],array[3]);		///// writing in the output file
			fprintf(file_out,"Sensor0 = %lf; Sensor1 = %lf; Sensor2 = %lf; Sensor3 = %lf; Sensor4 = %lf; Sensor5 = %lf; Sensor6 = %lf;\n",
					array[4],array[5],array[6],array[7],array[8],array[9],array[10]);		///// writing in the output file
			fprintf(file_out,"\n\n");
			event_time = array[0];		///// Update Timestamp ;; current event is treated so it will become the ancient one for next iteration
			
		}
		
	}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~ Closing files & Ending ~~~~~~~~~~~//	
	fclose(file_in);
	fclose(file_out);
	return EXIT_SUCCESS;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
}
