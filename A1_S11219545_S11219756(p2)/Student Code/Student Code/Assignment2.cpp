// Assignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "List.h"
#include "VisaApplication.h"
#include <iomanip>

using namespace std;

void discard_line(ifstream& in);
void print_header();
void print(List *myList, visa_application *data);
void Print_success_list(List *myList, visa_application* data);
void print_failure_list(List *myList, visa_application* data);
void remove_success_failure(List *myList, visa_application* data);


int main()
{
    List myList;

    ifstream in;
    ofstream out;
    in.open("applications.txt", ios::in);
    out.open("applications_outcome.txt", ios::out);

    discard_line(in);
    visa_application *visa_info = new visa_application;
    string temp_string;
    int temp_int = 0;
    
    

    while (true) {
       
        in >> temp_string;
        visa_info->set_visa_type(temp_string);
        in >> temp_int;
        visa_info->set_invoice_no(temp_int);
        in >> temp_string;
        visa_info->set_surname(temp_string);
        in >> temp_string;
        visa_info->set_first_name(temp_string);
        in >> temp_int;
        visa_info->set_contact(temp_int);
        in >> temp_string;
        visa_info->set_status(temp_string);
        in >> temp_string;
        visa_info->set_result(temp_string);
        if (in.eof()) break;
        
        myList.appendNode(visa_info);
        
        visa_info = new visa_application;
        
    }
    string choice;
  
    do {
        cout << "***Visa Application Process Menu***" << endl << endl;
        cout << "1. Print all the information for every visa applicant" << endl;
        cout << "2. Print all successful visa applications" << endl;
        cout << "3. Print all unsuccessful visa applications" << endl;
        cout << "4. Remove all successful and unsuccesful visa applications from the list" << endl << endl;
        cout << "Please select an option by entering its corresponding number and enter '0' to exit" << endl;
        cin >> choice;

        if (choice == "1") {
            print(&myList, visa_info);
            cout << endl;
        }
        else if (choice == "2") {
            Print_success_list(&myList, visa_info);
            cout << endl;
        }
        else if (choice == "3") {
            print_failure_list(&myList, visa_info);
            cout << endl;
        }
        else if (choice == "4") {
            remove_success_failure(&myList, visa_info);
            cout << endl;
        }
        else if (choice != "0") {
            cout << "Invalid input. Please try entering a valid number to proceed with the program or to exit" << endl;
            cin >> choice;
        }
    } while (choice != "0");

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

void print_header() {
    cout << "Visa Type" << "        " << "InvoiceNO" << "       " << "Surname" << "     " << "First Name" << "      " << "Contact" << "         " << "Status" << "         " << "Result" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
}

void print(List *myList, visa_application* data) {
    print_header();
    myList->printList();

}

void Print_success_list(List *myList, visa_application* data) {
    print_header();
    
    for (Node* temp = myList->getpHead(); temp != NULL; temp = myList->nextNode(temp)) {
        Data* d;
        d = temp->getData();
        data = (visa_application*)d;
        if (data->get_result() == "success")
             data->print();
        
        
    }

}

void print_failure_list(List *myList, visa_application* data) {
    print_header();

    for (Node* temp = myList->getpHead(); temp != NULL; temp = myList->nextNode(temp)) {
        Data* d;
        d = temp->getData();
        data = (visa_application*)d;
        if (data->get_result() == "failure")
            data->print();


    }
}

void remove_success_failure(List *myList, visa_application* data) {
     
    print_header();

    Node *temp = myList->getpHead();
    Node* temp2 = temp;
    for (temp = myList->getpHead(); temp != NULL; temp = myList->nextNode(temp)) {
        Data* d;
        d = temp->getData();
        data = (visa_application*)d;
        if (data->get_result() == "failure" || data->get_result() == "success") {
            myList->removeNode(temp);
            temp = temp2;
        }
          
    }
   
    myList->printList();
    cout << "PRINTING AFTER DELETING SUCCESS AND FAILURE NODE(RECORDS)" << endl;
}
