#include <iostream>
#include <cmath>
#include <iomanip>

#include "point.h"

void createPoints(Point points[], int pointCount){
	/*
		A functions that prompts the user to input coordinates for a number of points
	*/
	for (int pointn=0; pointn<pointCount; pointn++){
		float x, y;
		std::cout << "Punkt " << pointn+1 << std::endl;
		std::cout << "X: ";
		std::cin >> x;
		std::cout << "Y: ";
		std::cin >> y;
		points[pointn] = Point(x,y);
	}
}

int getInputWithinInterval(std::string text, int min, int max){
	/*
		A helper function, which prints a message and asks for a number within a interval
	*/
	int n;
	std::cout << text;
	std::cin >> n;
	if (n>max || n<min){
		return getInputWithinInterval(text, min, max);
	}
	return n;
}

Point* getFarawayPoint(Point points[], int nrOfPoints, int pointIndex){
	/*
		A function which finds the farthest away point in an array from a selected point in the array
	*/
	int longestDistance = 0;
	Point* farawayPoint;

	for (int pointComprareIndex=0; pointComprareIndex<nrOfPoints; pointComprareIndex++){

		float distance = points[pointIndex].distance(&points[pointComprareIndex]);

		if (distance > longestDistance){
			longestDistance = distance;
			farawayPoint = &points[pointComprareIndex];
		}
	}
	return farawayPoint;
}

void printFarawayPoint(Point* selectedPoint, Point* farawayPoint){
	// Print out result
	std::cout 	<< "Längst bort från " << selectedPoint->info()
				<< " hittade du " << farawayPoint->info()
				<< std::endl
				<< "Avståndet är " << std::fixed << std::setprecision(2) 
				<< selectedPoint->distance(farawayPoint) << std::endl;
}



int main(){
	// Amount of points prompt
	int pointCount = getInputWithinInterval("Hur många punkter vill du placera ut? (2-10) ", 2, 10);

	Point points[10];

	// Prompts the user for point coordinates
	createPoints(points, pointCount);

	int choice;
	Point* selectedPoint;
	Point* farawayPoint;

	do {
		// Ask for reference point
		choice = getInputWithinInterval("\nFör vilken punkt vill du hitta den mest avlägsna punkten? (avaluta med 0) ", 0, pointCount);
		
		if (choice > 0){ // if choice is not exit
			// Get selected point
			selectedPoint = &points[choice-1];
			// Get faraway point
			Point* farawayPoint = getFarawayPoint(points, pointCount, selectedPoint->getIndex());
			// Find and print faraway point
			printFarawayPoint(selectedPoint, farawayPoint);
		}
	}
	while (choice != 0);

	return 0;
}