//
// Created by Alex on 20.12.2023 г..
//
#include "person.h"

#ifndef UNTITLED_PERSONESTATES_H
#define UNTITLED_PERSONESTATES_H
class PersonEstates: public PersonBase{
private:
    char** addresses;
    int numAddresses;

public:
    PersonEstates(const char* name, const char* egn, const char* address, int numAddresses, const char** estateAddresses);
    ~PersonEstates();

    void set_numAddresses(int num);
    int get_numAddresses() const;

    void set_estateAddresses(char** estateAddresses);
    char** get_estateAddresses() const;

    friend std::ostream& operator<<(std::ostream& os, const PersonEstates& person);

    void printAll();
};
#endif //UNTITLED_PERSONESTATES_H
