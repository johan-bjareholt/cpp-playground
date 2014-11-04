#include "course.h"

std::vector<Course*> courses;

Course::Course( std::string studentname, std::string coursename, float points)
{
	this->coursename = coursename;
	this->studentname = studentname;
	this->points = points;
	courses.push_back(this);
}

/*
	Coursename
*/

void Course::setCoursename(std::string coursename){
	this->coursename = coursename;
}

std::string Course::getCoursename(){
	return this->coursename;
}

/*
	Studentname
*/

void Course::setStudentname(std::string studentname){
	this->studentname = studentname;
}

std::string Course::getStudentname(){
	return this->studentname;
}

/*
	Points
*/

void Course::setPoints(std::string){

}

void Course::addPointsCompleted(float points){
	this->pointsCompleted += points;
}

void Course::setPointsCompleted(float points){
	this->pointsCompleted = points;
}

bool Course::isComplete(){
	if (this->points == this->pointsCompleted){
		return true;
	}
	else {
		return false;
	}
}

/*
	Print
*/

void Course::pprint(){
	std::cout 	<< "Studentname: " << this->studentname << std::endl
				<< "Coursename: " << this->coursename << std::endl
				<< "Points: " << this->pointsCompleted << "/" << this->points << std::endl;
}

/*
	Comparisons
*/


bool Course::operator==(Course otherCourse){
	if (this->pointsCompleted == otherCourse.pointsCompleted)
		return true;
	else
		return false;
}

bool Course::operator<(Course otherCourse){
	if (this->pointsCompleted < otherCourse.pointsCompleted)
		return true;
	else
		return false;
}

bool Course::operator>(Course otherCourse){
	if (this->pointsCompleted > otherCourse.pointsCompleted)
		return true;
	else
		return false;
}