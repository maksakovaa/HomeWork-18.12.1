#include "navigation.h"

static void setConsLocale()
{
    setlocale(LC_ALL, "");
	#ifdef _MSC_VER
	system("chcp 65001");
	#endif
}

UserBase* Users = new UserBase();
Chat* mainChat = new Chat();
int choice{ 0 }, userId{ -1 };
bool auth{ false };

int main()
{
	setConsLocale();
	menu();

	delete mainChat;
	delete Users;
	return 0;
}
