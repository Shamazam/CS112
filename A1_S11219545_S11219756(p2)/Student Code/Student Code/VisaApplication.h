#pragma once

#include <iostream>
#include "Data.h"
using namespace std;

class visa_application : public Data {

	private:
		string visa_type;
		int invoice_no;
		string surname;
		string first_name;
		int contact;
		string status;
		string result;
	public:
		visa_application() {
			invoice_no = 0;
			contact = 0;
		}
		~visa_application() {
			
		};
		void set_visa_type(string visa_type);
		string get_visa_type();
		void set_invoice_no(int invoice_no);
		int get_invoice_no();
		void set_surname(string surname);
		string get_surname();
		void set_first_name(string first_name);
		string get_first_name();
		void set_contact(int contact);
		int get_contact();
		void set_status(string status);
		string get_status();
		void set_result(string result);
		string get_result();
		void print();


};

void visa_application::set_visa_type(string visa_type) {
	this->visa_type = visa_type;
}
string visa_application::get_visa_type() {
	return this->visa_type;
}

void visa_application::set_invoice_no(int invoice_no) {
	this->invoice_no = invoice_no;
}
int visa_application::get_invoice_no() {
	return this->invoice_no;
}
void visa_application::set_surname(string surname) {
	this->surname = surname;
}
string visa_application::get_surname(){
	return this->surname;
}
void visa_application::set_first_name(string first_name){
	this->first_name = first_name;
}
string visa_application::get_first_name(){
	return this->first_name;
}
void visa_application::set_contact(int contact){
	this->contact = contact;
}
int visa_application::get_contact(){
	return this-> contact;
}
void visa_application::set_status(string status){
	this->status = status;
}
string visa_application::get_status(){
	return this->status;
}
void visa_application::set_result(string result){
	this->result = result;
}
string visa_application::get_result(){
	return this-> result;
}
void visa_application::print() {
	cout << visa_type << "		" << invoice_no << "		" << surname << "		" << first_name << "		" << contact << "		" << status << "		" << result << endl;
}