#include "generator.h"
#include <random>

generator::generator() {
	generate();
}

string generator::generate() {
	int c = 0;
	string nP = "";
	std::random_device rd;
	while (c < 12) {
		std::uniform_int_distribution<int> dist(0, 69);
		int r = dist(rd);
		char ch = chars[r];
		string s(1, ch);
		nP.append(s);
		c++;
	}
	newPassword = nP;
	return nP;
}


