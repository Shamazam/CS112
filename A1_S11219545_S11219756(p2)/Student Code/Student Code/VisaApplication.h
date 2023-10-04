#pragma once

#include <iostream>
#include "Data.h"
using namespace std;

class visa_application : public data {

	private:
		string visa_type;
		int invoice_no;
		string surname;
		string first_name;
		int contact;
		string status;
		string result;
	public:
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
