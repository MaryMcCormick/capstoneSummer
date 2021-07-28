#include "tester.h"

tester::tester(string upass) {
	runTest(upass);
}

double tester::runTest(string pass) {
	string CommonBank[]{
		"pass",
		"1234",
		"qwer",
		"word",
	};
	bool common = false;
	for (int i = 0; i < 4; i++) {
		if (pass.find(CommonBank[i]) != std::string::npos) {
			common = true;
		}
	}
	

	int pLength = pass.length();

	rate = 0;
	if (pLength < 8 || pLength > 16) {
		rate = 0;
		cout << "Password is out of the 8-16 character range. We will generate a password that is within character length limits.\n";
	}
	else if (common) {
		rate = 0;
		cout << "Common string detected. We will generate a password that is less easy to guess.\n";
	}
	else if (checkRep(pass) == false) {
		rate = 0;
		cout << "Repetitive string detected. We will generate a more random password.\n";
	}


	else {
		double C=checkCap(pass);

		double L=checkLow(pass);

		double N=checkNum(pass);

		double S=checkSym(pass);

		cout << '\n';

		rate = ((C / pLength) * 1.5 )+ ((L / pLength)*1) + ((N / pLength)*2) + ((S / pLength)*2.5) + 1;
	}
	cout << "SCORE: "<< rate;
	if (rate <= 2.5) {
		cout << ": Failed check. Passwords must be between 8 and 16 characters long, and include a non-repeating combination of Capital letters, lowercase letters, numbers, and/or symbols.\n";
	}
	else {
		cout << ": Success. Password is: " + pass + " and hashed password is: " << std::hash<std::string>{}(pass) << '\n';;
	}
	return rate;
}

double tester::checkCap(string pass) {
	double count = 0;
	for (char c : pass) {
		if (isupper(c)) {
			count++;
		}
		
	}
	cap = count;

	return count;
}

double tester::checkLow(string pass) {
	double count = 0;
	for (char c : pass) {
		if (islower(c)) {
			count++;
		}
		
	}
	low = count;

	return count;
}

double tester::checkNum(string pass) {
	double count = 0;
	for (char c : pass) {
		if (isdigit(c)) {
			count++;
		}
		
	}
	num = count;

	return count;
}

double tester::checkSym(string pass) {
	double count = 0;
	char syms[8] = { '!', '@', '#', '$', '%', '^', '&', '*' };
	for (char c : pass) {
		for (int i = 0; i < 8; i++) {
			if (c == syms[i]) {
				count++;
			}
		}
		
	}
	sym = count;

	return count;
}

bool tester::checkRep(string pass) {
	int l = pass.length();
	int c = 0;
	for (int i = 1; i < l; i++) {
		if (pass[i] == pass[i - 1]) {
			return false;
		}
		else {
			for (int j = 0; j < l; j++) {
				int n = std::count(pass.begin(), pass.end(), pass[i]);
				if (n > 3) {
					return false;
				}
			}
		}
		
	}
	return true;
}

