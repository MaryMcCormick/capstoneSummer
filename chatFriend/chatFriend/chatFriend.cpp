// chatFriend.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Bot.h"


int main()
{
	Bot cf;
	cf.initialize();
	std::ofstream uFile{ "aboutYou.txt" };
	std::string convo;
	convo = "Your name is " + cf.userName + ". Today, this is what we did:\n";
	std::getline(std::cin, cf.input);
	while (cf.active == true) {
		std::getline(std::cin, cf.input);
		std::transform(cf.input.begin(), cf.input.end(), cf.input.begin(), ::tolower);
		if (cf.profanity(cf.input) == true) {
			convo.append("Swearing is not allowed.\n");
			std::cout << "Let's try that again, without the bad words.\n";
		}
		else if ((cf.input.find("yes") != std::string::npos || cf.input.find("help") != std::string::npos ||
			cf.input.find("info") != std::string::npos || cf.input.find("about") != std::string::npos)) {
			convo.append("You asked me about myself.\n");
			cf.info();
		}
		else if ((cf.input.find("chat") != std::string::npos || cf.input.find("talk") != std::string::npos)) {
			convo.append("We talked about: \n");
			std::string topics=cf.respond();
			convo.append(topics);
		}
		else if ((cf.input.find("hi") != std::string::npos)) {
			cf.greeting();
		}
		else if ((cf.input.find("bye") != std::string::npos)) {
			cf.farewell();
		}
		else if ((cf.input.find("suggest") != std::string::npos)) {
			convo.append("You suggested: \n");
			std::string suggs=cf.suggestBox();
			convo.append(suggs);
		}
		else if ((cf.input.find("no") != std::string::npos || cf.input.find("exit state") != std::string::npos)) {
			cf.state = "STANDBY";
			std::cout << "[" + cf.state + " STATE]\n";
			std::cout << "Ok, what now?\n";
		}
		else if ((cf.input.find("?") != std::string::npos)) {
			convo.append("You asked: \n");
			cf.query(cf.input);
			convo.append(cf.input);
			convo.append("\n");
		}
		else {
			cf.errorMessage();
		}
		convo.append("\n");
	}
	uFile << convo;
	uFile.close();
	exit(0);
}


