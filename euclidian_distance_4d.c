/* BURAK UGAR 200104004100 HW5
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/
#include <stdio.h>
#include "hw5_lib.h"
#include <math.h>
#include <stdlib.h> //for exit function
/************************************** 	FOR 4D VECTORS ****************************************/

void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance){
	double value= sqrt((d0*d0)+(d1*d1)+(d2*d2)+(d3*d3)); //finds the euclidian distance between two points 
	*euclidian_distance=value;
}
/* NUMBER OF VECTORS 'N' WAS IN TEST FOUR_D_VECTOR FUNCTION SINCE I DONT NEED TO TAKE NUMBER OF VECTOR IN THE FUNCTION ITSELF BECAUSE IT HAS THAT ARGUMENT AS INPUT */
void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	double first,sec,third,fourth,euclidian_distance=0,d0,d1,d2,d3,first_1,sec_1,third_1,fourth_1,sum_0=0,sum_1=0,sum_2=0,sum_3=0,temp_0,temp_1,temp_2,temp_3;
	double temp_first_0,temp_first_1,temp_first_2,temp_first_3,euclidian_distance_1,euclidian_distance_2,euclidian_distance_3,d0_0,d0_1,d0_2,d0_3;
	int flag=0,counter=0,i;
	printf("\nEnter the first vector's components:"); 
	scanf("%lf %lf %lf %lf",&first,&sec,&third,&fourth);
	if(first==-1 && sec==-1 && third ==-1 && fourth==-1){
		printf("You are chosen to quit the program");
		exit(1);
		/*if user enter -1 -1 -1 -1 in the first iteration exit from the program */	
	}
	else{
		temp_first_0=first;	/* assing the values to temp values to hamper them to disappear */
		temp_first_1=sec;	/* getting the first vectors components and add them to sum to get the mean at the end */
		temp_first_2=third;
		temp_first_3=fourth;
		sum_0+=first;
		sum_1+=sec;
		sum_2+=third;
		sum_3+=fourth;
	}
	printf("Enter the second vector's components:"); 
	scanf("%lf %lf %lf %lf",&first_1,&sec_1,&third_1,&fourth_1);
	if(first_1==-1 && sec_1==-1 && third_1 ==-1 && fourth_1==-1){
		d0=0;
		d1=0;					
		d2=0;
		d3=0;
		*mean_a0=first;	
		*mean_a1=sec; /* if user enter -1 -1 -1 -1 then print the first vectors components */
		*mean_a2=third;
		*mean_a3=fourth;
		distance_between_4d_points(d0,d1,d2,d3,&euclidian_distance);
		*longest_distance=euclidian_distance;
		printf("There is no such thing as difference between 1 consecutive term\n");
	}
	else{ /* if the second entered value is not -1 then continue to take inputs */
		d0=fabs(first-first_1);
		d1=fabs(sec-sec_1);					/* if user does not enter -1 -1 -1 -1 then continue to get components and add them to sum also calculate the consecutive distances */
		d2=fabs(third-third_1);
		d3=fabs(fourth-fourth_1);
		distance_between_4d_points(d0,d1,d2,d3,&euclidian_distance);
		*longest_distance=euclidian_distance;
		sum_0+=first_1;
		sum_1+=sec_1; 
		sum_2+=third_1;
		sum_3+=fourth_1;
		i=3;
		counter=3;
		do{	/* adding the next vector's components */
		printf("Enter the %d'th vector's components:",i);
		scanf("%lf %lf %lf %lf",&first,&sec,&third,&fourth);
		if(first!=-1 && sec!=-1 && third !=-1 && fourth !=-1 && counter ==3){
				temp_0=first;
				temp_1=sec;
				temp_2=third; /* if user does not enter -1 and if we are in the 3.th iteration do the same thing */
				temp_3=fourth;
				sum_0+=first;
				sum_1+=sec;
				sum_2+=third;
				sum_3+=fourth;
				d0=fabs(first-first_1);
				d1=fabs(sec-sec_1);					
				d2=fabs(third-third_1);
				d3=fabs(fourth-fourth_1);
				distance_between_4d_points(d0,d1,d2,d3,&euclidian_distance);
				if(euclidian_distance>*longest_distance){
					*longest_distance=euclidian_distance;
				}
				counter++; /* at each it. count the number of steps */
				i++;
				}
		else if(first==-1 && sec==-1 && third ==-1 && fourth ==-1 && counter ==3){
					*mean_a0=sum_0/2;
					*mean_a1=sum_1/2;
					*mean_a2=sum_2/2; /* if user enter -1 at the third it. then find the mean up to that point and exit from the loop */
					*mean_a3=sum_3/2;
					d0=fabs(first-first_1);
					d1=fabs(sec-sec_1);					
					d2=fabs(third-third_1);
					d3=fabs(fourth-fourth_1);
					flag=1;
					goto z;
		}
		else if(first!=-1 && sec!=-1 && third !=-1 && fourth !=-1 && counter !=3){
				sum_0+=first; /* if user does not enter -1 and we are not in the third it. then do the same things mentioned above */
				sum_1+=sec;
				sum_2+=third;
				sum_3+=fourth;
				d0=fabs(first-temp_0); /* distance cannot be negative value */
				d1=fabs(sec-temp_1);					
				d2=fabs(third-temp_2);
				d3=fabs(fourth-temp_3);
				distance_between_4d_points(d0,d1,d2,d3,&euclidian_distance);
				if(euclidian_distance>*longest_distance){
					*longest_distance=euclidian_distance;
				}
				temp_0=first;
				temp_1=sec;
				temp_2=third;
				temp_3=fourth;
				counter++;
				i++;
			}
		else if(first==-1 && sec==-1 && third ==-1 && fourth ==-1 && counter !=3){
				counter--;
				goto t;
		}
		
	}
		while(i<=N&& flag !=1 ); /* go till the user enter -1 (flag==1) or the number of steps */
		t:	;				
		*mean_a0=sum_0/counter;
		*mean_a1=sum_1/counter; /*calculate the means */
		*mean_a2=sum_2/counter;
		*mean_a3=sum_3/counter;
		z:	;
		
	}
}