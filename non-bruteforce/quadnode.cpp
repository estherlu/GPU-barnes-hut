/**
*this file defines the quadtree
**/

#include "QuadNode.hpp"

#include <iostream>
#include <cmath>

QuadNode::QuadNode(long double xmin, long double xmax, 
		long double ymin, long double ymax, Body* mybody)
 {  xmin(xmin),
    xmax(xmax),
    ymin(ymin),
    ymax(ymax),
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

}

QuadNode::addAllBody (BodySystem* bs){

}

QuadNode::clearNode (){

}

QuadNode::recalculate(){

}

QuadNode::calcForce(Body* body){

}

QuadNode::calAllForce(BodySystem* bs){

}

QuadNode::getQuadrant(Body* body){

}

QuadNode::getXmin(){

}
QuadNode::getXmax(){

}
QuadNode::getYmin(){

}
QuadNode::getYmax(){

}
QuadNode::setTheta(){

}
QuadNode::isParent(){

}
QuadNode::createChildren(){
	
}