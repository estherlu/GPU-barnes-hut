#ifndef BODY_H
#define BODY_H

#include <string> 


class Body{

	private:
		 static const double G = 6.673e-11;

	public:
		double x,y;//location of the body
		double vx,vy;//velovity in the x and y direction
		double fx,fy;//force in x and y direction
		double ax,ay;//acceleration in x and y firection
		double mass;//mass of the body

		Body();// initialize the body as all zero values
		Body(double bMass,double bX,double bY);//initialize the body with position and mass

		void calcForce(QuadNode* node);//we moved calculation of force into body


};



#endif
