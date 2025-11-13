#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

//namespace carconfig{

	class Person{

		friend ostream& operator<<(ostream &s, const Person& per);
		friend istream& operator>>(istream &s,  Person& per);

		protected:
			string lastName;
			string firstName;

		public:
			Person();
			Person(string Lname, string Fname);
			Person(const Person &per);
			~Person();
			void setLastName(const string Lname);
			void setFirstName(const string Fname);
			string getLastName()const;
			string getFirstName()const;
			virtual void display() const;

			Person& operator=(const Person& per);

	};
//}
#endif