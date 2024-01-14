#pragma once
#include "UserBase.h"
#include <ctime>

struct Message
{
	string msgTo;
	string msgFrom;
	string msgDate;
	string msg;
	Message(string msgTo_, string msgFrom_, string msg_) : msgTo(msgTo_), msgFrom(msgFrom_), msg(msg_)
	{
		time_t now = time(NULL);
		char str[26];
#ifdef _MSC_VER
		ctime_s(str, 26, &now);
#else
        ctime_r(&now, str);
#endif
		msgDate = str;
		msgDate.pop_back();
	}
	Message(string msgTo_, string msgFrom_, string msgDate_, string msg_) : msgTo(msgTo_), msgFrom(msgFrom_), msgDate(msgDate_), msg(msg_) {}
};

class Chat
{
public:
	Chat();
	~Chat();
	int getMsgCount();
	std::vector<int> getMsgToCount(string msgFrom, string msgTo);
	void emptyMsg();
	void printMsg(std::vector<int>& msgIndex);
	void showMain();
	void showPersonal(string user1, string user2);
	void sendMsg(string msgTo, string msgFrom, string& msg);
private:
	std::vector<Message>* msgBase;
#ifdef _MSC_VER
	string MBPath = "msg_base.dat";
#else
	string MBPath = "/var/lib/Chat/msg_base.dat";
#endif // _MSC_VER
};
