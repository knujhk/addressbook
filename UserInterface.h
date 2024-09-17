#pragma once

//#include "MyList.h" 
//MyList& list; 참조를 멤버로 가질 땐
//forward declaration으로 클래스 존재만 알려도 된다.
class MyList;   

class UserInterface
{
public:
    UserInterface() = delete;   //데이터베이스가 없이 ui 인스턴스가 존재할 필요가 없다.
    UserInterface(MyList& param) : list(param){ //참조자는 선언과 동시에 초기화해야하기 때문
    }
    ~UserInterface(){};

    void run(); //ok

    int printUI();  //ok

    void addUser(); //ok

    void searchUser();  //ok

    void removeUser();  //ok

private:
    MyList& list;
    int menu = 0;
};