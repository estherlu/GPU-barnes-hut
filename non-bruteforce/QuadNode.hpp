#ifndef QUADNODE_H
#define QUADNODE_H
#include "Body.hpp"

#include <string> 

class QuadNode{
private:
	long double xmin,xmax;
	long double ymin,ymax;
	long double theta;
	long double mx, my;//center of mass
	long double m; //total mass
	bool isactive; 
	bool isparent;
	Body* me;
	QuadNode** myChildren;  //Not sure 

public:
	//Create a quadtree with a certain space
	QuadNode(long double x1, long double x2, 
		long double y1, long double y2, long double x, long double y, long double mass, Body* mybody);

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

	//If the quadnode is a parent, return true
	bool isParent();

private:
    //create children for this node
	void createChildren();

};
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 9c19727cce6c8606e328fda6545088ea03727e6a
