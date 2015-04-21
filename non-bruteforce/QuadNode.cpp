/**
*this file defines the quadtree
**/

#include "QuadNode.hpp"

#include <iostream>
#include <cmath>

QuadNode::QuadNode(long double x1, long double x2, 
		long double y1, long double y2, long double x, long double y, long double mass, Body* mybody)
 {  xmin(xmin),
    xmax(xmax),
    ymin(ymin),
    ymax(ymax),
    mx(x),
    my(y),
    m(mass),
    theta(1.0),
    isparent(false),
    me(mybody),
    myChildren(NULL)
}

QuadNode::QuadNode(BodySystem* ps)
{
	//Some setups with the body system
}

QuadNode::~QuadNode();
{
	this->clear();
}

QuadNode::addBody(Body* body){
	//If this quadnode does not have a body in it, just add new body and return.
    if(me==NULL){
    	this->me = body;
    	this->mx = body->x;
    	this->my = body->y;
    	this->m = body->mass;
    	return;
    }
    if(!this->isparent){
    	this->createChildren();

    	this->myChildren[this->getQuadrant(body)] = addBody(body);
    	this->myChildren[getQuadrant(me)] = addBody(me);

    	this->calcMass();
    }else{
    	this->myChildren[this->getQuadrant(body)] = addBody(body);
    	this->myChildren[getQuadrant(me)] = addBody(me);

    	this->calcMass();
    }

}

QuadNode::addAllBody (BodySystem* bs){

}

QuadNode::clearNode (){

}

QuadNode::calcMass(){

}

QuadNode::calcForce(Body* body){

}

QuadNode::calAllForce(BodySystem* bs){

}

QuadNode::getQuadrant(Body* body){
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

QuadNode::getXmin(){
	return this->xmin;
}
QuadNode::getXmax(){
	return this->xmax;
}
QuadNode::getYmin(){
	return this->ymin;
}
QuadNode::getYmax(){
	return this->ymax;
}
QuadNode::setTheta(){
	return this->theta;
}
QuadNode::isParent(){
	return this->isparent;
}
QuadNode::createChildren(){

}