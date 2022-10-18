/* Instructor.cpp - Definition of functions for the Instructor subclass to PersonAtMCC
 * Author:     <your name>
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Instructor.h"
#include <iostream>
using namespace std ;

Instructor::Instructor(long id, string name, string address, string phone, string department, bool is_permanent, double pay_rate, double hours) {
    setId(id);
    setName(name);
    setAddress(address);
    setPhone(phone);
    setDepartment(department);
    setIsPermanent(is_permanent);
    setPayRate(pay_rate);
    setHours(hours);
}


// Getters for this class only
string Instructor::getDepartment() {
    return department ;
}

bool Instructor::getIsPermanent() {
    return is_permanent ;
}

double Instructor::getPayRate() {
    return pay_rate ;
}

double Instructor::getHours() {
    return hours ;
}

// Setters for this class only
void Instructor::setDepartment(string new_department) {
    department = new_department ;
}

void Instructor::setIsPermanent(bool new_is_permanent) {
    is_permanent = new_is_permanent ;
}

void Instructor::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

void Instructor::setHours(double new_hours) {
    hours = new_hours ;
}

void Instructor::showInfo() {
    cout << "ID: " << getId()
         << "  Name: " << getName()
         << "  Address: " << getAddress() << endl
         << "     Phone: " << getPhone() << endl
         << "Department: " << getDepartment() << endl
         << " Permanent: " << getIsPermanent() << endl
         << "  Pay Rate: " << getPayRate() << endl
         << "     Hours: " << getHours() << endl << endl;
}