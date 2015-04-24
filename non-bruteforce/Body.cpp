/**
*This file defines the bodies in the system
**/


#include "Body.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

#define THETA 1
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

void Body::resetForce(){
	this->fx= 0;
	this->fy= 0;

}

void Body::calcForce(QuadNode* node){
    long double dx = node->mx - this->x;
    long double dy = node->my - this->y;
    long double d2 = dx * dx + dy * dy;
    long double d = sqrt(d2); //distance from quadnode's center to target body
    long double h = node->ymax - node->ymin; //height of the quadnode
    long double r = h/d;
    if(node->isparent){
       if(r >= THETA)
        {//We need to separate to four smaller nodes for this quadnode and calculate recursively
            for(int i = 0; i < 4; i++){
                if(node->myChildren[i]!=NULL){
                   this-> calcForce(node->myChildren[i]);
                }
            }
         return;
        }else{
            //The condition that we can consider the quadnode as a whole when calculating force
            this->fx += (dx/d)* (node->m * this->mass /d2);
            this->fy += (dy/d)* (node->m * this->mass /d2);
            return;
        }
    }else{ //The condition that we only have one body in the quadnode
        this->fx += (dx/d)* (node->m * this->mass /d2);
        this->fy += (dy/d)* (node->m * this->mass /d2);  
        return;      
    }
    
}


