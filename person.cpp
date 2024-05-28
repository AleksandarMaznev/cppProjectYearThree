#pragma once
#include "iostream"
#include "cstring"
#include "person.h"


PersonBase::PersonBase() {
    set_name("");
    set_egn("");
    set_address("");
}

PersonBase::~PersonBase() {
    delete[] name;
    delete[] egn;
    delete[] address;
}

void PersonBase::set_name(const char* name_new) {
    delete[] name;
    name = new char[strlen(name_new) + 1];
    strcpy(name, name_new);
}

void PersonBase::set_egn(const char* egn_new) {
    delete[] egn;
    egn = new char[strlen(egn_new) + 1];
    strcpy(egn, egn_new);
}

void PersonBase::set_address(const char* address_new) {
    delete[] address;
    address = new char[strlen(address_new) + 1];
    strcpy(address, address_new);
}

const char* PersonBase::get_name() const {
    return name;
}

const char* PersonBase::get_egn() const {
    return egn;
}

const char* PersonBase::get_address() const {
    return address;
}

void PersonBase::printAll() {
}
