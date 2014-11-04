#include <iostream>

#include "course.h"

Course* registerCourse(){
	std::string studentname;
	std::string coursename;
	float points;
	
	std::cin.ignore();std::cin.clear();
	std::cout << "Studentname: ";
	std::getline(std::cin, studentname);
	std::cout << "Coursename: ";
	std::getline(std::cin, coursename);
	std::cout << "Points: ";
	std::cin >> points;

	return new Course(studentname, coursename, points);
}

void printCourses(){
	for (auto it = courses.begin(); it<courses.end(); it++){
		(*it)->pprint();
	}
}

Course* findCourse(std::string studentname, std::string coursename){
	Course* course;
	for (int coursei = 0; coursei<courses.size(); coursei++){
		course = courses[coursei];
		if (course->getStudentname() == studentname &&
			course->getCoursename() == coursename)
		{
			return course;
		}
	}
	return NULL;
}

void findUser(){
	
}

void findCoursePrompt(){
	std::string studentname;
	std::string coursename;

	std::cin.ignore(); std::cin.clear();
	std::cout << "Studentname: ";
	std::getline(std::cin, studentname);
	std::cout << "Coursename: ";
	std::getline(std::cin, coursename);

	Course* course = findCourse(studentname, coursename);
	if (course != NULL){
		std::cout << "Foud course: " << std::endl;
		course->pprint();
	}
	else {
		std::cout << "Could not find that course" << std::endl;
	}
}

int main()
{
	Course course1 = Course("Kalle Bra", "Programmering i C++", 7.5);
	Course course2 = Course("Kalle Bra2", "Programmering i C++", 7.5);
	Course course3 = Course("Kalle Kass", "Programmering i C++", 2.5);
	if (course1 == course2){
		std::cout << "asda" << std::endl;
	}
	if (course3 < course2){
		std::cout << "asdb" << std::endl;
	}

	bool running=true;
	char choice;

	while (running)
	{
		std::cout 	<< "1. Add course" << std::endl
					<< "2. List courses" << std::endl
					<< "3. Find course" << std::endl
					<< "q. Quit" << std::endl
					<< "Choice: ";
		std::cin >> choice;
		switch(choice){
			case '1':
				registerCourse();
				break;
			case '2':
				printCourses();
				break;
			case '3':
				findCoursePrompt();
				break;
			case 'q':
				running=false;
				break;
			default:
				std::cout << "invalid option" << std::endl;
				break;
		}
		std::cout << std::endl;
	}

}