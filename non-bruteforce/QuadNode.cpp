/**
*this file defines the quadtree
**/

#include "QuadNode.hpp"

#include <iostream>
#include <cmath>

QuadNode::QuadNode(long double x1, long double x2, 
		long double y1, long double y2, long double x, long double y, long double mass, Body* mybody):
	xmin(xmin),
	xmax(xmax),
	ymin(ymin),
	ymax(ymax),
	mx(x),
	my(y),
	m(mass),
	theta(1.0),
	isactive(false), //should be false, because we'll have empty quadnode initially
	isparent(false),
	me(mybody),
	myChildren(NULL)
{}

/*
QuadNode::QuadNode(BodySystem* bs)
{
	//Some setups with the body system
}
*/

QuadNode::~QuadNode()
{
	this->clearNode();
}

void QuadNode::addBody(Body* body)
{
	//If this quadnode does not have a body in it, just add new body and return.
	if(!isactive){
		this->me = body;
		this->mx = body->x;
		this->my = body->y;
		this->m = body->mass;
		this->isactive= true;
		return;
	}
	if(!this->isparent){
		this->createChildren();

		this->myChildren[this->getQuadrant(body)] = addBody(body);
		this->myChildren[getQuadrant(me)] = addBody(me);
		this->me = NULL;

		this->calcMass();
	}else{
		this->myChildren[this->getQuadrant(body)] = addBody(body);

		this->calcMass();
	}

}

/*
QuadNode::addAllBody (BodySystem* bs){

}
*/

void QuadNode::clearNode (){

}

void QuadNode::calcMass(){
	if(!this->isparent)
		return;
	//reset the center of mass and total mass to 0
	this->mx=0;
	this->my=0;
	this->m=0;

	for(unsigned int i=0;i<4;i++){
		if(this->myChildren[i]->isactive){
			//If there is a body in myChildren[i],add up the mass and mass*position
			this->m += this->myChildren[i]->m;
			this->mx += (this->myChildren[i]->m) * (this->myChildren[i]->mx);
			this->my += (this->myChildren[i]->m) * (this->myChildren[i]->my);			
		}
	}

	this->mx /= this->m;
	this->my /= this->m;
}


void QuadNode::calcForce(Body* body){
	/*    long double dx = this->mx - body->x;
    long double dy = this->my - body->y;
    long double d2 = dx * dx + dy * dy;
    long double d = sqrt(d2);
    if(this->isparent){
       if(d/r >= theta)//I forgot what is d and what is r
        {//We need to separate to four smaller nodes for this quadnode and calculate recursively
            for(int i = 0; i < 4; i++){
                if(this->myChildren[i] != NULL){
                   this->myChildren[i] -> calcForce(body);
                }
                return;
            }

        }else{//means that we need to add fx and fy variables into the function
            //The condition that we can consider the quadnode as a whole calculating force
            body->fx = (dx/d)* this->m * body->mass /d2;
            body->fy = (dy/d)* this->m * body->mass /d2;
            return;
        }
    }else{ //The condition that we only have one body in the quadnode
        body->fx = (dx/d)* this->m * body->mass /d2;
        body->fy = (dy/d)* this->m * body->mass /d2;  
        return;      
    }
    */
}

/*
QuadNode::calAllForce(BodySystem* bs){

}
*/

unsigned int QuadNode::getQuadrant(Body* body){
    //0,1,2,3 means the four quadrant, 5 means that this body does not fit in this quadnode
	
	if((body->x >= this->xmin) && (body->x <= (this->xmin + this->xmax)/2)){
		if((body->y >= this->ymin) && (body->y <= (this->ymin + this->ymax)/2){
			return 2;
		}else if((body->y > (this->ymin + this->ymax)/2) && (body->y <= this->ymax)){
			return 0;
		}else return 5;
	}else if((body->x > (this->xmin + this->xmax)/2) && (body->x <= this->xmax)){
		if((body->y >= this->ymin) && (body->y <= (this->ymin + this->ymax)/2)){
			return 3;
		}else if((body->y > (this->ymin + this->ymax)/2) && (body->y <= this->ymax){
			return 1;
		}else return 5;
	}else return 5;
}


void QuadNode::createChildren(){

}

long double QuadNode::getXmin(){
	return this->xmin;
}
long double QuadNode::getXmax(){
	return this->xmax;
}
long double QuadNode::getYmin(){
	return this->ymin;
}
long double QuadNode::getYmax(){
	return this->ymax;
}
void QuadNode::setTheta(long double inTheta){
	this->theta=inTheta;
	if(!this->isparent)
		return;
	for(unsigned int i=0;i<4;i++)
		this->myChildren[i]->setTheta(this->theta);
}
bool QuadNode::isParent(){
	return this->isparent;
}
