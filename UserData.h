#pragma once
#include "MyNode.h"

class UserData : public MyNode
{
public:
    UserData(){count++;}
    UserData(const char*, const char*);
    ~UserData(){count--;}
    const char* getName(void) const {
        return name;
    }
    const char* getPhone(void) const {
        return phone;
    }
    static int getCount(void) {
        return count;
    }
    
    const char* getKey(void);
    void printNode(void);

private:
    char name[32] = {0};
    char phone[32] = {0};
    static int count;
};

