#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include "Bot.h"


//Bot::Bot()
//{
//}

bool Bot::profanity(std::string swear)
{
	std::string Profanity[]{
		"fuck",
		"shit",
		"bitch",
	};
	bool swore = false;
	for (int i = 0; i < 3; i++) {
		if (swear.find(Profanity[i]) != std::string::npos) {
			swore = true;
		}
	}
	return swore;

}

void Bot::initialize()
{
	state = "INITIALIZE";
	std::cout << "[" + state + " STATE]\n";
	std::cout << "Hello, I am Thoth.  What is your name?\n";
	std::cin >> userName;
	setName(userName);
	std::cout << "[" + state + " STATE]\n";
	std::cout << "Hi, " << userName << "! I am a chatbot. Would you like to know more?\n";
}

void Bot::setName(std::string s)
{
	userName = s;
}

void Bot::info()
{
	std::cout << this->infoString;
}

std::string Bot::suggestBox()
{
	state = "SUGGESTION";
	std::ofstream file{ "suggestionbox.txt" };
	std::string list;
	bool isSuggest = true;
	std::cout << "[" + state + " STATE]\n";
	std::cout << "Okay, go ahead! Type DONE when you're done.\n";
	while (isSuggest) {
		std::getline(std::cin, input);
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		if (input == "done") {
			file << list;
			file.close();
			isSuggest = false;
			std::cout << "[" + state + " STATE]\n";
			std::cout << "Thank you! This information will be passed along to be reviewed. What now?\n";
		}
		else {
			list.append(input);
			list.append("\n");
		}
	}
	return list;
}

void Bot::farewell()
{
	std::string Farewell[]{
		"See you soon!\n",
		"Bye!\n",
		"See you later!\n",
		"Goodbye!\n",
		"Farewell!\n",
	};
	std::cout << "Check my files for aboutYou.txt to review our latest interaction. \n";
	int n = rand() % 5;
	std::string sFarewell = Farewell[n];
	std::cout << sFarewell;
	active = false;
}

void Bot::greeting()
{
	std::string Greeting[] = {
		"Hi!\n",
		"Hello!\n",
		"Good to see you!\n",
	};
	int n = rand() % 3;
	std::string sGreet = Greeting[n];
	std::cout << sGreet;
}

std::string Bot::respond()
{
	state = "CONVERSE";
	std::string topic;
	std::string conversation;
	bool converse = true;
	std::cout << "[" + state + " STATE]\n";
	std::cout << "What would you like to talk about?\n";
	std::getline(std::cin, input);
	topic = input;
	conversation = topic;
	conversation.append("\n");
	std::cout << "[" + state + " STATE]\n";
	std::cout << "Okay, let's talk about " << topic << ". If you want to stop, say STOP.\n" <<
		"If you want to talk about something else, say CHANGE.\n" <<
		"Tell me about " << topic << "!\n";
	while (converse) {
		std::getline(std::cin, input);
		
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);
		std::string Response[] = {
			"Okay",
			"I see",
			"Tell me more",
			"Uh-huh",
			"Yeah",
			"Of course",
		};
		std::string punct[]{
			"!\n",
			"?\n",
			".\n",
		};
		if (input == "stop") {
			std::cout << "[" + state + " STATE]\n";
			std::cout << "Okay, we'll stop talking about it now.\n";
			converse = false;
		}
		else if (input == "change") {
			std::cout << "[" + state + " STATE]\n";
			std::cout << "What else would you like to talk about?\n";
			std::getline(std::cin, input);
			topic = input;
			std::cout << "[" + state + " STATE]\n";
			std::cout << "Tell me about " << topic << "!\n";
			conversation.append(topic);
			conversation.append("\n");
		}
		else {
			int n = rand() % 6;
			int m = rand() % 3;
			std::string sPunct = punct[m];
			std::string sResponse = Response[n];
			std::cout << "[" + state + " STATE]\n";
			std::cout << sResponse << sPunct;
			conversation.append(input);
			conversation.append("\n");
		}
		
	}
	return conversation;
}

void Bot::errorMessage()
{
	std::cout << "I'm sorry, I can't understand what you said.\n";
}

std::string Bot::query(std::string q)
{
	state = "QUERY";
	//bool answered = false;
	//while (!answered) {
		if ((q.find("what") != std::string::npos)) {
			if ((q.find("name") != std::string::npos)) {
				if ((q.find("my") != std::string::npos)) {
					std::cout << "[" + state + " STATE]\n";
					std::cout << "I think you asked me what your name is. You're " << userName << "!\n";
					//answered = true;
				}
				else if ((q.find("your") != std::string::npos)) {
					std::cout << "[" + state + " STATE]\n";
					std::cout << "I think you asked me what my name is. I'm " << name << "!\n";
					//answered = true;
				}
				
			}
			else if ((q.find("you") != std::string::npos)) {
				std::cout << "You've asked me something about myself. \n";
				info();
			}
			else {
				int length = q.size(); //TODO FIX
				int pos = q.find_last_of(" ");
				std::string subject = q.substr(pos + 1, length - 2);
				std::cout << "[" + state + " STATE]\n";
				std::cout << "It looks like you asked me about " << subject << " What is it? I just don't know.\n";
				//answered = true;
			}
		}
		else if ((q.find("who") != std::string::npos)) {
			if ((q.find(" i?") != std::string::npos)) {
				std::cout << "[" + state + " STATE]\n";
				std::cout << "I think you asked me who you are. You're " << userName << "!\n";
				//answered = true;
			}
			else if ((q.find("you") != std::string::npos)) {
				std::cout << "[" + state + " STATE]\n";
				std::cout << "I think you asked me who I am. I'm " << name << "!\n";
				//answered = true;
			}
		}
		else {//TODO CHANGE SUBJECT
			std::cout << "[" + state + " STATE]\n";
			std::cout << "You asked me a question, but I can't answer it. Sorry!\n";
			//answered = true;
		}
		std::string qs = q + "\n";
		return qs;
	//}
}
