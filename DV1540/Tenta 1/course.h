#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <string>

class Course {
private:
	std::string coursename;
	std::string studentname;
	float points;
	float pointsCompleted=0;
public:
	Course(std::string, std::string, float);

	void setCoursename(std::string);
	std::string getCoursename();

	void setStudentname(std::string);
	std::string getStudentname();

	void setPoints(std::string);
	void addPointsCompleted(float);
	void setPointsCompleted(float);
	bool isComplete();

	void pprint();

	bool operator==(Course);
	bool operator<(Course);
	bool operator>(Course);
};

extern std::vector<Course*> courses;

#endif