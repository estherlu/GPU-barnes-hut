#ifndef QUADNODE_H
#define QUADNODE_H

#include <string> 

class QuadNode{
public:
	//Create a quadtree with a certain space
	QuadNode(long double xmin, long double xmax, 
		long double ymin, long double ymax, Body* body)
	//double xmin,xmax;
	//double ymin,ymax;
	//double* NE,NW,SE,SW;
	//double mass;  //Total mass
	//double x,y; //Center of mass

    //Create a quadtree using existing file
	Quadtree( ParticleSystem* ps );

    // deletes all associated memory
	~Quadtree();
    
    //Add a single body to the quadnode
	void addBody (Body* body);

    //Add all bodies in the existing file to the quadnode
	void addAllBody (ParticleSystem* ps);

	//Clear the contents of the node
	void clearNode ();

	//Recalculate center of mass and total mass
	void recalculate();

	//Calculate a single body's force
	void calcForce(Body* body);

	//Calculate all force
	void calcAllForce(ParticleSystem* ps);

	//Get which quadrant the body is in 
	void getQuadrant(Body* body);

	//Get the left side of the quadnode
	long double getXmin();

    //Get the right side of the quadnode
	long double getXmax();
    
    //Get the botton of the quadnode
	long double getYmin();

	//Get the top of the quadnode
	long double getYmax();

	//Set the threshold of distance/r
	long double setTheta(long double nTheta);

	//
    

};