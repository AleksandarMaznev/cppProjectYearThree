#pragma once
#include "person.cpp"
#include "personEstates.h"

PersonEstates::PersonEstates(const char* name, const char* egn, const char* address, int numAddresses,const  char** estateAddresses){
    set_name(name);
    set_egn(egn);
    set_address(address);

    this->numAddresses = numAddresses;
    this->addresses = new char*[numAddresses];

    for (int i = 0; i < numAddresses; ++i) {
        this->addresses[i] = new char[strlen(estateAddresses[i]) + 1];
        strcpy(this->addresses[i], estateAddresses[i]);
    }
}

PersonEstates::~PersonEstates() {
    for (int i = 0; i < numAddresses; ++i) {
        delete[] addresses[i];
    }
    delete[] addresses;
}

void PersonEstates::set_numAddresses(int num) {
    numAddresses = num;
}

int PersonEstates::get_numAddresses() const {
    return numAddresses;
}

void PersonEstates::set_estateAddresses(char** estateAddresses) {
    for (int i = 0; i < numAddresses; ++i) {
        delete[] addresses[i];
    }
    delete[] addresses;

    addresses = new char*[numAddresses];

    for (int i = 0; i < numAddresses; ++i) {
        addresses[i] = new char[strlen(estateAddresses[i]) + 1];
        strcpy(addresses[i], estateAddresses[i]);
    }
}

char** PersonEstates::get_estateAddresses() const {
    return addresses;
}

void PersonEstates::printAll(){
    std::cout<<"\n"<<get_name()<< " " << get_egn() << " " << get_address() <<std::endl;
}

std::ostream &operator<<(std::ostream &os, const PersonEstates &person) {
    os << "EGN: " << person.get_egn() << "\n";
    os << "Name: " << person.get_name() << "\n";
    os << "Number of Estates Owned: " << person.get_numAddresses() << "\n";
    os << "Address primary: " << person.get_address() << "\n";

    for (int i = 1; i < person.get_numAddresses(); ++i) {
        os << "Address of estate number " << (i + 1) << ": " << person.get_estateAddresses()[i] << "\n";
    }

    return os;}
