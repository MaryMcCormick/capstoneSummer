#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class tester
{


private:
	
public:
	double rate;
	double cap;
	double low;
	double num;
	double sym;
	string password;
	double runTest(string password);
	double checkCap(string password);
	double checkLow(string password);
	double checkNum(string password);
	double checkSym(string password);
	bool checkRep(string password);
	tester(string upass);
};

