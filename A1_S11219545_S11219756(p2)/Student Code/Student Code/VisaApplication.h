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
		


		void print();


};
