PasTGen is a password tester/generator that takes a string for input and rates it, suggesting a new password should it fail to meet expectations.


PasTGen is written by Mary McCormick.

TO RUN:

	I built this using Visual Studio 2019, and if you have that program, you can download the .sln file. Don't use the .sln without a program that can open it.

	The following files are required to run the main file:

		generator.h
		generator.cpp
		tester.h
		tester.cpp
		main.cpp

	Download the files all to the same folder. In your code environment, you'll want to run "main.cpp".

SPECIFICATIONS:

	PasTGen will take any string as input. However, your input will be given a "0" rating if:
		
		The string is less than 8 or greater than 16 characters.
		The string contains the following strings: "pass", "word", "qwer", or "1234".
		The string repeats the same character immediately.
		The string has more than 3 of the same character.

	These will result in an immediate rating of 0.

	Other passwords will result in a decimal rating between 1 and 5, with the failing bar being 2.5.
	
	Should the password succeed, the generator will display your password and the hashed password.

	Otherwise, the generator will generate a new password to test. It will continue doing this until either a successful password is reached or 10 attempts have occurred.
	
	To exit the program, when prompted, press any character key, followed by ENTER.

I hope you enjoy using PasTGen.
