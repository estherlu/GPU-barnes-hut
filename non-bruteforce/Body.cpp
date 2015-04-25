/**
*This file defines the bodies in the system
**/


#include "Body.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>

#define THETA 1
Body::Body()
{
    this->x=0;
    this->y=0;
    this->fx=0;
    this->fy=0;
    this->vx=0;
    this->vy=0;
    this->mass=0;
}


Body::Body(double bX,double bY,double bMass)
{
    this->x=bX;
    this->y=bY;
    this->fx=0;
    this->fy=0;
    this->vx=0;
    this->vy=0;
    this->mass=bMass;
}

void Body::resetForce(){
	this->fx= 0;
	this->fy= 0;

}

void Body::calcForce(QuadNode* node){
    double dx = node->mx - this->x;
    double dy = node->my - this->y;
    double d2 = dx * dx + dy * dy;
    double d = sqrt(d2); //distance from quadnode's center to target body
    double h = node->ymax - node->ymin; //height of the quadnode
    double r = h/d;
    
    if(d2==0){
        return;
    }
    if(!node->isactive){
        return;
    }
    if(node->isparent){
        //printf("here\n");
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
        //printf("fx: %lf\n",this->fx);
        this->fx =this->fx + (dx/d)* (node->m * this->mass /d2);
        this->fy += (dy/d)* (node->m * this->mass /d2);  
        return;      
    }
    
}

void Body::calcPosition(double time){
        this->vx = this->fx * time / this->mass;
        this->vy = this->fy * time / this->mass;

        this->x += vx * time;
        this->y += vy * time;
}

void Body::toString(){

	printf("Mass:%.1f\tPosition:%.1f,%.1f\tVelocity:%.1f,%.1f Force::%.1f,%.1f\n",this->mass, this->x,this->y,this->vx,this->vy,this->fx,this->fy);
	
}


