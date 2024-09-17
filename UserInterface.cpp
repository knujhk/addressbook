#include "UserInterface.h"
#include "MyList.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

void UserInterface::run(){
    while ((menu = printUI()) != 0) {
		switch (menu) {
		case 1:		  // Add
			addUser();
			break;

		case 2:		  // Search
			searchUser();
			break;

		case 3:		 // Print all
			list.printAll();
			break;

		case 4:		  // Remove
			removeUser();
			break;
		}
	}
}
int UserInterface::printUI(){
    int nInput = 0;

	system("cls");
	printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

	// 사용자가 선택한 메뉴의 값을 반환한다.
	scanf_s("%d%*c", &nInput);

	return nInput;
}
void UserInterface::addUser(){

	char name[32] = { 0 };
	char phone[32] = { 0 };

	printf("Input name : ");
	fgets(name,32,stdin);
	name[strlen(name)-1] = '\0';
	//flushInputBuffer();

	printf("Input phone number : ");
	fgets(phone,32,stdin);
	phone[strlen(phone)-1] = '\0';
	//flushInputBuffer();

	// 실제로 리스트에 추가한다.
	this->list.addNewNode(name, phone);
}
void UserInterface::searchUser(){
	char name[32] = { 0 };
	MyNode* pNode = NULL;

	printf("Input name : ");
	gets_s(name, sizeof(name));

	pNode = this->list.findNode(name);

	if (pNode != NULL) {
		pNode->printNode();
	}

	else {
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	}

	_getch();
}
void UserInterface::removeUser(){
	char name[32] = { 0 };

	printf("Input name : ");
	gets_s(name, sizeof(name));

	if (this->list.removeNode(name))
		puts("삭제완료.");
	else
		puts("ERROR: 해당 자료를 찾을 수 없습니다.");
	_getch();
}