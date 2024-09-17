#include "UserInterface.h"
#include "MyList.h"
#include "MyNode.h"
#include "UserData.h"

int main()
{
	UserData head;
	MyList DB(head);
	UserInterface UI(DB);
	UI.run();	//이전까지는 관계 규정만 하다가 run으로 이벤트루프 실행

	return 0;
}
