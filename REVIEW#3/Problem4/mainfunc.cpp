#include "ApplicationClass.h"

int main()
{
	ApplicationClass appManager("foodItem.txt", "officeItem.txt");
	appManager.run();

	return 0;
}