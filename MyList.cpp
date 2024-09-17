#include "MyList.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

MyList::~MyList(){
    MyNode* pTmp = head.pNext;
	MyNode* pDelete = NULL;

	while (pTmp != NULL) {
		pDelete = pTmp;
		pTmp = pTmp->pNext; 

		delete(pDelete);
	}
	head.pNext = nullptr;
}
int MyList::addNewNode(char* pName, char* pPhone){
    MyNode* pNewNode = NULL;

	if (findNode(pName) != NULL)
		return 0;

	pNewNode = new UserData(pName,pPhone);
	pNewNode->pNext = NULL;

	pNewNode->pNext = this->head.pNext;
	this->head.pNext = pNewNode;

	return 1;
}
int MyList::removeNode(char* pName){
    MyNode* pPrevNode = &head;
	MyNode* pDelete = NULL;

	while (pPrevNode->pNext != NULL) {
		pDelete = pPrevNode->pNext;

		if (strcmp(pDelete->getKey(), pName) == 0) {
			pPrevNode->pNext = pDelete->pNext;
			delete(pDelete);

			return 1;
		}

		pPrevNode = pPrevNode->pNext;
	}

	return 0;
}
void MyList::printAll(){
	MyNode* pTmp = head.pNext;

	while (pTmp != NULL) {
		pTmp->printNode();
		pTmp = pTmp->pNext;
	}

	_getch();
}
MyNode* MyList::findNode (char* pName){
    MyNode* pTmp = head.pNext;
    
	while (pTmp != NULL) {
		if (strcmp(pTmp->getKey(), pName) == 0)
			return pTmp;

		pTmp = pTmp->pNext;
	}

	return NULL;
}