#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
	ifstream list("list");
	char file[256];
	int counter = 0;
	int total = 257;
	while(list.getline(file,256)) {
		string cmd = "git add ";
		cmd += string(file) + string("\n");
		system(cmd.c_str());
		cout << cmd.c_str() << endl;
		string cmd1 = string("git commit -m \"add ") + string(file) + string("\"");
		system(cmd1.c_str());
		cout << cmd1.c_str() << endl;
		string cmd2 = string("git push github");
		system(cmd2.c_str());
		cout << cmd2.c_str() << endl;
		counter++;
		double pc = (double)counter / (double)total;
		short int Done = pc * 33;
		short int None = (double)(1 - pc) * 33;
		cout << "[";
		for(int i = 0; i < Done; i++)
			cout << "#";
		for(int i = 0; i < None; i++)
			cout << ".";
		cout << "]" << endl;
		fflush(stdout);
	}
	return 0;
}
