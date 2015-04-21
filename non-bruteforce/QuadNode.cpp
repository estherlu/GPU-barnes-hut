/**
*this file defines the quadtree
**/

#include "QuadNode.hpp"

#include <iostream>
#include <cmath>

QuadNode::QuadNode(long double x1, long double x2, 
		long double y1, long double y2, Body* mybody):
	xmin(xmin),
	xmax(xmax),
	ymin(ymin),
	ymax(ymax),
	mx(0),
	my(0),
	m(0),
	theta(1.0),
	isactive(true),
	isparent(false),
	me(mybody),
	myChildren(NULL)
{}

/*
QuadNode::QuadNode(BodySystem* ps)
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
		//this->myChildren[getQuadrant(me)] = addBody(me);

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
			this->m += this->myChildren[i]->m;
			this->mx += (this->myChildren[i]->m) * (this->myChildren[i]->mx);
			this->my += (this->myChildren[i]->m) * (this->myChildren[i]->my);			
		}
	}

	this->mx /= this->m;
	this->my /= this->m;
}


void QuadNode::calcForce(Body* body){

}

/*
QuadNode::calAllForce(BodySystem* bs){

}
*/

unsigned int QuadNode::getQuadrant(Body* body){
    //0,1,2,3 means the four quadrant, 5 means that this body does not fit in this quadnode
	if(body->x >= xmin && body->x <= (xmin+xmax)/2){
		if(body->y >= ymin && body->y <= (ymin+ymax)/2){
			return 2;
		}else if(body->y > (ymin+ymax)/2 && body->y <= ymax){
			return 0;
		}else return 5;
	}else if(body->x > (xmin+xmax)/2 && body->x <= xmax){
		if(body->y >= ymin && body->y <= (ymin+ymax)/2){
			return 3;
		}else if(body->y > (ymin+ymax)/2 && body->y <= ymax){
			return 1;
		}else return 5;
	}else return 5;
}


void QuadNode::createChildren(){
	if(!this->isactive)
		return;

	if(this->isparent){
		for(unsigned int i=0;i<4;i++){
			delete this->myChildren[i];
			this->myChildren[i]=NULL;
		}
	}

	this->myChildren=new QuadNode*[4];
	long double xmid = (this->xmin + this->xmax)/2;
	long double ymid = (this->ymin + this->ymax)/2;

	this->myChildren[0]= new QuadNode(this->xmin, xmid, ymid, this->ymax, NULL);
	this->myChildren[0]->setTheta(this->theta);

	this->myChildren[1]= new QuadNode(xmid, this->xmax, ymid, this->ymax, NULL);
	this->myChildren[1]->setTheta(this->theta);

	this->myChildren[2]= new QuadNode(xmid, this->xmax, this->ymin, ymid, NULL);
	this->myChildren[2]->setTheta(this->theta);

	this->myChildren[3]= new QuadNode(this->xmin, xmid, this->ymin, ymid, NULL);
	this->myChildren[3]->setTheta(this->theta);

	this->isparent=true; 
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
