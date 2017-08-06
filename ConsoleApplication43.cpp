#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Enter the file directory with name: ";
	char *st = new char[1024];
	int i = 0;
	string name;
	cin >> name;
	name += ".txt";
	int n = 0;
	while (n < name.length()) {
		if (name.at(n) == '\\') name.insert(n++, 1, '\\');
		n++;
	}
	ifstream file(name);
	if (file.is_open()) {
		cout << "Number of lines: ";
		while (!file.eof())
		{
			file.getline(st, 1024, '\n');
			i++;
		}
		file.close();
		cout << i << '\n';
	}
	else cout << "This file does not exist in this directory" << '\n';
	delete st;
	system("pause");
}