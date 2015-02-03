#include <iostream>
#include <fstream>
#include <cstring>

class Person {
	int age;
	char name[20];
public:
	int getAge(){
		return this->age;
	}
	char* getName(){
		return this->name;
	}
	Person(int age, std::string name){
		this->age = age;
		int i;
		for (i=0; i<name.size() || i>=19; i++){
			this->name[i] = name[i];
		}
		this->name[i] = '\0';
	}
	Person(Person& otherPerson){
		this->age = otherPerson.getAge();
		strcpy(this->name, otherPerson.getName());
	}
	void save(std::ostream& ostream){
		ostream.write((char*)this, sizeof(*this));
		if (ostream.fail())
			std::cout << "Output fail" << std::endl;
	}
	void load(std::istream& istream){
		istream.read((char*)this, sizeof(*this));
		if (istream.fail())
			std::cout << "Input fail" << std::endl;
	}

	void pprint(){
		std::cout << name << "\t" << age << std::endl;
	}
};

class Student : public Person {
	int employeeid;
public:
	static int next_employeeid;
	Student (int age, std::string name) : Person(age, name){
		employeeid = next_employeeid;
		next_employeeid++;
	}
};

int Student::next_employeeid = 0;


int main(){
	Person guy (10,"guy unloaded");
	Person gal (14,"gal unloaded");

	// Save
	std::ofstream ofile;
	ofile.open("guysave.bin", std::ios::binary );
	guy.save(ofile);
	ofile.close();

	guy.pprint();

	// Load
	std::ifstream ifile;
	ifile.open("galsave.bin", std::ios::binary );
	gal.load(ifile);
	ifile.close();

	gal.pprint();

	return 0;
}