#pragma once

class MyNode
{
    friend class MyList;
public:
    MyNode(){}
    virtual ~MyNode(){} //소멸자 가상화 하지 않으면 추상자료형으로 참조시 실체화된 클래스의 소멸자는 불리지 않을 것

    MyNode* getNext(void) const;
    
    virtual const char* getKey(void) = 0;
    virtual void printNode(void) = 0;

private:
    MyNode* pNext = nullptr;
};
