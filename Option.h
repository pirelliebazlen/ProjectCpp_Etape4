#ifndef OPTION_H
#define OPTION_H
#include <iostream>
#include <string>

using namespace std;

namespace carconfig {
	class Option
	{
		friend istream& operator>>(istream& s, Option& op);
		friend ostream& operator<<(ostream& s, const Option& op);
		private:
			string code;
			string label;
			float price;
		public:
			Option();
			Option(string c, string l, float p);
			Option(const Option &o);
			~Option();
			void setCode(string c);
			void setLabel(string l);
			void setPrice(float p);

			string getCode() const;
			string getLabel() const;
			float getPrice() const;
			void display() const;

			Option operator--(int); // poste incrementation
			Option& operator--();
			
	};
}
#endif