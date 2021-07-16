#pragma once
#include <string>
#include <iostream>

class Bot
{
public:
	std::string input;
	std::string userName;
	std::string state;
	bool active = true;
	bool profanity(std::string swear);
	void initialize();
	void setName(std::string s);
	void info();
	std::string suggestBox();
	void farewell();
	void greeting();
	std::string respond();
	void errorMessage();
	std::string query(std::string q);

private:
	std::string infoString = "I am in my baby stages right now, so I can't do much.\n"
		"I don't mind capitalization, but I'd like it if when we talked you used proper spelling.\n"
		"Otherwise I can't understand you!\n Also, if you have a question, please use a '?'.\n"
		"You can type SUGGEST to indicate that you are making a suggestion for something I should implement.\n"
		"I'll save your suggestions until you type DONE to show that you are finished.\n"
		"Also, if you just want to chat, say so!\n"
		"So what would you like to do?\n";
	std::string name = "Thoth";
	std::string faveAnimal = "ibis";
};

