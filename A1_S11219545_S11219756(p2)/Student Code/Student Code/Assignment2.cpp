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
void print(List *myList, visa_application *data);
void Print_success_list(List *myList, visa_application* data);
void print_failure_list(List myList, visa_application* data);
void remove_success_failure(List myList, visa_application* data);


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



    while (true) {

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
        if (in.eof()) break;
        //cout << data->get_visa_type() << "     " << data->get_invoice_no() << "       " << data->get_surname() << "       " << data->get_first_name() << "       " << data->get_contact() << "       " << data->get_status() << "        " << data->get_result() << endl;
        
        myList.appendNode(data);
        data = new visa_application;
        
    }

    /*Node* lastNode = myList.getpTail();
    myList.removeNode(lastNode);*/
    
    //for(int i = 0;i<8;i++)cout << data->get_visa_type() << "     " << data->get_invoice_no() << "       " << data->get_surname() << "       " << data->get_first_name() << "       " << data->get_contact() << "       " << data->get_status() << "        " << data->get_result() << endl;

    //print(&myList, data);
    
    //Print_success_list(&myList, data);

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

void print(List *myList, visa_application* data) {
    cout << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    myList->printList();

}
void Print_success_list(List *myList, visa_application* data) {
    cout << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    Node* temp = myList->getpHead();
    while (temp != NULL) {
        if (data->get_status() == "success") {
            temp->getData()->print();
        }
        temp = myList->nextNode(temp);
    }

}

void print_failure_list(List myList, visa_application* data) {
    cout << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    Node* temp = myList.getpHead();
    while (temp != NULL) {
        if (data->get_status() == "failure") {
            data->print();
        }
        temp = myList.nextNode(temp);
    }
}

void remove_success_failure(List myList, visa_application* data) {
    cout << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    Node* temp = myList.getpHead();
    while (temp != NULL) {
        if (data->get_status() == "failure" || data->get_status() == "success") {
            myList.removeNode(temp);
        }
        temp = myList.nextNode(temp);
    }
}
