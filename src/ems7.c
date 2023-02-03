/*
 ============================================================================
 Name        : cprojectdiploma.c
 Author      : youssef
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void turn_the_vehicle_off();
void turn_the_vehicle_on();
void set_temp();
void set_engine_temp();
void temp30 ();
void state();
void light();
float temp=0.0;
unsigned int speed=0, ac=0;
float temp_engine=0.0 ;
int temp_control=0;
int engine_swich=0;
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	printf("\n\t\t please select \t\t\n");
	printf("a-turn the vehicle on\n");
	printf("b-turn the vehicle off\n");
	printf("c-Qiut the system\n");
	char choise;
	scanf(" %c",&choise);
	if (choise =='c')
	{return 0;}
	else
	{
	switch (choise)
	{
	case 'a':
		turn_the_vehicle_on() ;
	            break;
	        case 'b':
	        	turn_the_vehicle_off()  ;
	            break;

	        default:
	                   printf( "error input\n");
	                   main();
	}
	}
printf("\n\t******************************************************************************************************\t\n");
     main();
}
void turn_the_vehicle_off()
 {

	engine_swich=0;
	state();
       main();
}
void turn_the_vehicle_on()
  {
	{
	 temp30 ();
	printf("\n\t\t please select \t\t\n");
	printf("a-Turn off the engine\n");
	printf("b-Set the traffic light color.\n");
	printf("c-Set the room temperature\n");
	printf("d-Set the engine temperature\n");
	printf("e-back to main menu\n");
	char choise ;

	scanf(" %c",&choise);
	switch (choise)
	{
	       case 'a':
		engine_swich=0 ;
		state();
	            break;
	        case 'b':
	        	light();
	        	break;
	        case 'c':
	        	set_temp();
	            break;
	        case 'd':
	        	set_engine_temp();

	        	break ;
	        case 'e':
	        	main();
	        	break;
	        default:
	                   printf("error input\n");
	}
	}

printf("\n\t******************************************************************************************************\t\n");
       turn_the_vehicle_on();

}
void set_temp()
{
	engine_swich=1;
	int i;
	printf("enter temperature\n");
	scanf("%f",&temp);

		        		if(temp <=10)
		        			{
		        			ac=1;
		        			for(i=temp;i<=20;i++)
		        			{
		        			printf ("temperature controller is on,engine temperature is equal:%d degree\n",i);temp =i;
		        			}
		        			}
		        		if(temp >=30)
		        			  {
		        			temp_control=1;
		        			for(i=temp;i>=20;--i)
		        			{
		        			printf ("temperature controller is on,engine temperature is equal:%d degree\n",i);
		        			temp=i;
		        		     }
		        			  }


		        		else
		      {
		   		temp_control=0;
		        		printf("AC is off\n");
		      }
		        		state();
}
void set_engine_temp()
{engine_swich=1;
int i;
printf("enter engine temperature\n");
scanf("%f",&temp_engine);

	        		if(temp_engine <=100)
	        			{
	        			temp_control=1;
	        			for(i=temp_engine;i<=100;i++)
	        			{
	        			printf ("temperature controller is on,engine temperature is equal:%d degree\n",i);temp_engine =i;
	        			}
	        			}
	        		if(temp_engine >=150)
	        			  {
	        			temp_control=1;
	        			for(i=temp_engine;i>=150;--i)
	        			{
	        			printf ("temperature controller is on,engine temperature is equal:%d degree\n",i);
	        			temp_engine=i;
	        		     }
	        			  }


	   	if (temp_engine ==125)
	      {
	   		temp_control=0;
	        		printf("AC is off\n");
	      }
	   	state();
}

void temp30 ()
{engine_swich=1;
	printf("\t\t enter vehicle speed and temperature and engine temperature\n");
		scanf("%d %f %f",&speed,&temp,&temp_engine);
		if (speed ==30)
		{
			ac=1;
			temp = temp*(5/4)+1;
			temp_control =1;
			temp_engine = temp_engine*(5/4)+1;
		}
		state();
}

void state()
{
	if (engine_swich==1)
			{printf("car engine is on\n");}
		else
		{printf("car engine is off\n");}

	if (ac==1)
		{printf("the AC is on\n");}
	else
	{printf("the AC is off\n");}
	printf("car speed equal:%d\n",speed);
	printf("room temperature equal:%f\n",temp);
	if(temp_control==1){
	printf("Engine Temperature Controller State is on\n");
	}
	else
	{printf("Engine Temperature Controller State off\n");}
	printf("Engine temperature equal:%f\n",temp_engine);
	printf("\t\t****************************************************\t\t\n");
}
void light()
{
	char color ;
	engine_swich=1;
		        	printf("enter the traffic light data \n");
		        	scanf(" %c",&color);

		        	if(color == 'G')
		        	{speed =100;}
		        	else if(color == 'O')
		        	{speed =30;}
		        	else if(color  == 'R')
		        	{speed=0;}
		        	printf("motor speed:%d km/h\n",speed);
		        	state();

}



