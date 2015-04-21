/**
*This file defines the bodies in the system
**/


#include "Body.hpp"
#include <iostream>
#include <string>
#include <stdio.h>

Body::Body():
	x(0),
	y(0),
	fx(0),
	fy(0),
	ax(0),
	ay(0),
	vx(0),
	vy(0),
	mass(0)
{}


Body::Body(double bMass,double bX,double bY):
	x(bX),
	y(bY),
	fx(0),
	fy(0),
	ax(0),
	ay(0),
	vx(0),
	vy(0),
	mass(bMass)
{}



