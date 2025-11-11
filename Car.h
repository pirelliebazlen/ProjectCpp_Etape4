#ifndef CAR_H
#define CAR_H
#include "Model.h"
#include "Option.h"
#include <iostream>
#include<string>
using namespace std;

namespace carconfig {
	class Car{

		friend Car operator+(const Option &op, const Car &c);
		friend ostream& operator<<(ostream &s, const Car& c);
		private:
			string name;
			Model model;
			Option *options[5];
			int verification(const Car& c);

		public:
			Car ();
			Car(string n, Model m);
			Car(const Car &c);
			~Car();

			void setName(string n);
			void setModel(const Model m);
			string getName() const;
			Model getModel() const;
			

			void display() const;
			void addOption(const Option &option);
			void removeOption(string code);
			float getPrice();

			Car& operator=(const Car& c);
			Car operator+(const Option& op);
			Car operator-(const Option& op);
			Car operator-(string option);
			int operator<(const Car& c);
			int operator>(const Car& c);
			int operator==(const Car& c);
			Option* operator[](int i);

		

	};
}
#endif