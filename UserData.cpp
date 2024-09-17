#include "UserData.h"
#include <cstdio>
#include <cstring>


int UserData::count = 0;
    
UserData::UserData(const char* pName, const char* pPhone){
    strcpy(name,pName);
    strcpy(phone,pPhone);
    count++;
}

const char* UserData::getKey(void){
    return name;
}

void UserData::printNode(void){
    printf("[%p] %s\t%s [%p]\n",
			this,
			this->getName(), this->getPhone(),
			this->getNext());

}