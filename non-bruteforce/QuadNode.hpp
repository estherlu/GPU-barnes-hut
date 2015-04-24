#ifndef QUADNODE_H
#define QUADNODE_H

#include "Body.hpp"

#include <string> 


class Body;

class QuadNode{
public:
	long double xmin,xmax;
	long double ymin,ymax;
	long double theta;
	long double mx, my;//center of mass
	long double m; //total mass
	bool isactive; 
	bool isparent;
	Body* me;
	QuadNode** myChildren;  //Not sure 

	//Create a quadtree with a certain space
	QuadNode(long double x1, long double x2, 
		long double y1, long double y2, Body* mybody);

    //Create a quadtree using existing file
//	QuadNode( BodySystem* bs );

    // deletes all associated memory
	~QuadNode();
    
    //Add a single body to the quadnode
	void addBody (Body* body);

    //Add all bodies in the existing file to the quadnode
//	void addAllBody (BodySystem* bs);

	//Clear the contents of the node
	void clearNode ();

	//Recalculate center of mass and total mass
	void calcMass();

	//Calculate a single body's force
	void calcForce(Body* body);

	//Calculate all force
//	void calcAllForce(BodySystem* bs);

	//Get which quadrant the body is in 
	unsigned int getQuadrant(Body* body);

	//Get the left side of the quadnode
	long double getXmin();

    //Get the right side of the quadnode
	long double getXmax();
    
    //Get the botton of the quadnode
	long double getYmin();

	//Get the top of the quadnode
	long double getYmax();

	//Set the threshold of distance/r
	void setTheta(long double inTheta);

	//get the value of threshold theta
	long double getTheta();

	//If the quadnode is a parent, return true
	bool isParent();

private:
    //create children for this node
	void createChildren();

};



#endif

