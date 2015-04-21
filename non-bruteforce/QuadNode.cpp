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

    	this->calcMass();
    }

}

QuadNode::addAllBody (BodySystem* bs){

}

QuadNode::clearNode (){

}

QuadNode::calcMass(){
    if(this->isparent){
        //add up all the mass of children for quadnode mass
        //calculate mx and my separately
        //First set mx, my and m to zero
        this->mx = 0.0; this->my = 0.0; this->m = 0.0;
        for(int i = 0; i < 4; ++i){
            if(this->myChildren[i]!=NULL){
                //If there is a body in myChildren[i],add up the mass and mass*position
            this->mx += this->myChildren[i]->mx * this->myChildren[i]->m; 
            this->my += this->myChildren[i]->my * this->myChildren[i]->m;
            this->m += this->myChildren[i]->m; 
            }
        }
        this->mx = this->mx/this->m;
        this->my = this->my/this->m;
    }
    if(!this->isparent){
        return;
    }
}

QuadNode::calcForce(Body* body){
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

QuadNode::calAllForce(BodySystem* bs){

}

QuadNode::getQuadrant(Body* body){
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