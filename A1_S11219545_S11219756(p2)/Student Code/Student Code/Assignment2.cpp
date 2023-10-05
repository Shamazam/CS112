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
    string temp_string;
    int temp_int = 0;
    while (in) {
        in >> temp_string;
        data.set_visa_type(temp_string);
        in >> temp_int;
        data.set_invoice_no(temp_int);
        in >> temp_string;
        data.set_surname(temp_string);
        in >> temp_string;
        data.set_first_name(temp_string);
        in >> temp_int;
        data.set_contact(temp_int);
        in >> temp_string;
        data.set_status(temp_string);
        in >> temp_string;
        data.set_result(temp_string);

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
