#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream fi;
	fi.open("textfile");
	if (!fi.good()){
		cout << "Couldn't open file!" << endl;
		return -1;
	}
	std::string text;
	while (fi.good()){
		getline(fi, text);
		cout << text << endl;
	}

	string asd[] = {"asd", "asd2", "asd3"};
	cout << asd[2];

	fi.close();

	ofstream fo;
	fo.open("textfile", ios::app);
	getline(cin, text);
	fo << text;
	fo.close();
}