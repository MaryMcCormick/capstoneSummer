ABOUT CHATFRIEND:

chatFriend is a programming project chatbot that I, Mary McCormick, created to test my ability to code in C++.
chatFriend is not abandoned, but simply on standby.

NOTES ABOUT USING CHATFRIEND:

STATES:
[INITIALIZE STATE]
	The first state. Whatever you type during this state, the first substring before a "space" or " " character will be your name for the session.
[STANDBY STATE]
	The second state. Being in standby state will allow access to SUGGEST STATE and CONVERSE STATE. Exiting those states will return you to standby state.
	chatFriend has a rudimentary profanity filter, and will not accept statements in standby state with profanity in them.
[CONVERSE STATE]
	Converse state is a loop, and will only be exited when "stop" is entered outside of a "change" request.
	A "change" request is the input given immediately after the "change" command is used.
	Exiting converse state returns you to standby state.
[SUGGEST STATE]
	Suggest state is a loop, and will only be exited when "done" is entered.
	Exiting suggest state returns you to standby state.
[QUERY STATE]
	Query state is triggered from standby state when a statement ends in a "?" character. Query state cannot be activated while converse state or suggest state are active.
	Query state is NOT a loop, and each answered question will return chatFriend to standby state.

EXITING:
	Please see chatFriend through to the end of your conversation by telling it "goodbye" in standby state. 
	Once the conversation is over, there will be two additional text files in this folder: 
	"suggestionbox.txt" contains all suggestions made.
	"aboutYou.txt" contains a record of user input in the conversation.




