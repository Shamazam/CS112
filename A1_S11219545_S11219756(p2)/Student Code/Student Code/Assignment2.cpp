// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"

using namespace std;

void discard_line(ifstream& in);


int main()
{
    List myList;

    ifstream in;
    ofstream out;
    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);

    discard_line(in);
    visa_application data;
    string dummy;
    int temp = 0;
    while (in) {
        in >> dummy;
        data.set_visa_type(dummy);
        in >> temp
            data.set_invoice_no(temp);
        in >>
            data.set_surname();
        in >> data.set_first_name();
        in >> data.set_contact();
        in >> data.set_status();
        in >> data.set_result();
        myList.appendNode(&data);

    }

    in.close();
    out.close();

    system("pause");
    return 0;
}

void discard_line(ifstream& in)
{
    char c;

    do
        in.get(c);
    while (c != '\n');
}