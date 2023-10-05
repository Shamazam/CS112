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
void print(List myList, ofstream& out, visa_application *data);
void Print_success_list(List myList);
void print_failure_list(List myList);
void remove_success_failure(List myList);


int main()
{
    List myList;

    ifstream in;
    ofstream out;
    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);

    discard_line(in);
    visa_application *data = new visa_application;
    string temp_string;
    int temp_int = 0;

   
    

    while (in) {
        in >> temp_string;
        data->set_visa_type(temp_string);
        in >> temp_int;
        data->set_invoice_no(temp_int);
        in >> temp_string;
        data->set_surname(temp_string);
        in >> temp_string;
        data->set_first_name(temp_string);
        in >> temp_int;
        data->set_contact(temp_int);
        in >> temp_string;
        data->set_status(temp_string);
        in >> temp_string;
        data->set_result(temp_string);
       
        myList.appendNode(data);
        
        data = new visa_application;
    }
    Node* dummy = myList.getpTail();
    myList.removeNode(dummy);
    print(myList,out, data);
    


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

void print(List myList, ofstream& out, visa_application* data) {
    cout << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    myList.printList();

    out << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    out << "-------------------------------------------------------------------------------------------------------------" << endl;
   
    Node* temp = myList.getpHead();
    while (temp  != NULL) {
        
        out << data->get_visa_type()<<"     " <<data->get_invoice_no()<<"       "<<data->get_surname()<<"       " <<data->get_first_name()<<"       "<<data->get_contact()<<"       "<<data->get_status()<<"        "<<data->get_result()  << endl;
        temp = myList.nextNode(temp);
    }
}
void Print_success_list(List myList) {

}

void print_failure_list(List myList) {

}

void remove_success_failure(List myList) {

}
