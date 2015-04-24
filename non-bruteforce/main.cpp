//g++ -O2 -o main main.cpp
#include <iostream>
#include <string>
#include <time.h> 
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */      

#include "Body.h"
#include "QuadNode.h"

//#include "StartSimulation.h"

#define GRIDSIDES 1000
#define NUMBODY 10
#define MAXMASS 20


void run();


int main(int argc, char const *argv[])
{
	double ina,inb,inc;
	int count;
	if (argc > 1)
    {   
    	count = atoi( argv[1] );
	}

	Body *myList [count];
	for(i = 0; i < count; i++){
		ina = rand()%1000;//x
		inb = rand()%1000;//y
		inc = rand()%1000;//mass

		myList[i] = new Body(ina,inb,inc);
		
		printf("%d) ",i + 1);
		myList[i]->toString();
	}

	printf("\nInitialize Bodies done!\n");

	QuadNode *mytree = new QuadNode(0,1000,0,1000,NULL);

	
	return 0;
}

