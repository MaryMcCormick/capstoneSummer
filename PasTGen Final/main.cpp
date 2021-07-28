#include "tester.h"
#include "generator.h"

int main() {
	cout << "This is a password tester. Please input password:\n";
	string p;
	cin >> p;
	tester test = tester(p);
	double score = test.rate;
	int counter = 0;
	while (counter < 10) {
		if (score <= 2.5) {
			string nextTry;
			generator passGen = generator();
			nextTry = passGen.generate();
			cout << "\nTesting " + nextTry + "\n";
			test.runTest(nextTry);
			score = test.rate;
		}
		break;
	}
	cout << "\nPress Any Key To Exit...";
	string in;
	cin >> in;
}
