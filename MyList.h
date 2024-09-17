#pragma once
#include "MyNode.h"

class MyList
{
public:
    MyList(MyNode& param):head(param){};
    ~MyList(); 
    
    int addNewNode(char* pName, char* pPhone); 
    int removeNode(char* name); 
    void printAll();
    MyNode* findNode (char* name);
    
private:
    MyNode &head;   //포인터로 참조해도됨
                    //참조자를 쓰면 객체 생성과 동시에 참조할 인스턴스를 꼭
                    //받아와야 한다는것이 차이
};