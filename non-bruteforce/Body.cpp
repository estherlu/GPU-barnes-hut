#ifndef BODY_CPP
#define BODY_CPP

#include <iostream>
#include <string>
#include <stdio.h>

class Body
{
public:
	double mass
	double x,y
	double fx,fy
	double ax,ay
	double vx,vy

	Body() :
		mass=0,
		x=0,
		y=0,
		fx=0,
		fy=0,
		ax=0,
		ay=0,
		vx=0,
		vy=0,
		{}

	
	Body(double bMass,double bX,double bY) :
		mass=bMass,
		x=bX,
		y=bY,
		fx=0,
		fy=0,
		ax=0,
		ay=0,
		vx=0,
		vy=0,
		{}

};

#endif