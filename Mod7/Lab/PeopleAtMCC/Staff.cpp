/* Staff.cpp - Function definition file for Staff, child of PersonAtMCC
 * Author:     Ben Foltz
 * Module:     7
 * Project:    Lab, Part 1
 */

#include "Staff.h"
#include <iostream>
using namespace std ;

Staff::Staff(long id, string name, string address, string phone, string extension, string hire_date, double pay_rate) {
    setId(id);
    setName(name);
    setAddress(address);
    setPhone(phone);
    Staff::extension = extension;
    Staff::hire_date = hire_date;
    Staff::pay_rate = pay_rate;
}

// Getters for this class only
string Staff::getExtension() {
    return extension ;
}

string Staff::getHireDate() {
    return hire_date ;
}

double Staff::getPayRate() {
    return pay_rate ;
}

// Setters for this class only
void Staff::setExtension(string new_extension) {
    extension = new_extension ;
}

void Staff::setHireDate(string new_hire_date) {
    hire_date = new_hire_date ;
}

void Staff::setPayRate(double new_pay_rate) {
    pay_rate = new_pay_rate ;
}

void Staff::showInfo() {
    cout << "ID: " << getId()
         << "  Name: " << getName()
         << "  Address: " << getAddress() << endl
         << "      Phone: " << getPhone() << endl
         << "  Extension: " << getExtension() << endl
         << "  Hire Date: " << getHireDate() << endl
         << "   Pay Rate: " << getPayRate() << endl << endl;
}