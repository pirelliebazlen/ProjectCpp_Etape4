#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Actor.h"
#include <string>
#include <iostream>
#include "Actor.h"
using namespace std;

enum role{Vendeur, Administracteur};
//namespace carconfig{
	class Employee : public Actor
	{
		private:
			string login;
			string * password;
			string role;
		public:
			Employee();
			Employee(string lname, string fname, int id, const string log, const string rol) ;
			Employee(const Employee& employe);
			~Employee();

			void setLogin(const string log);
			void setPassword(const string mdp);
			void setRole(const string rol);
			string getLogin() const;
			string* getPassword() const;
			string getRole() const;
			void display() const override ;
			void resetPassword();
			string tuple() const override;
			string toString() const override;
			
			Employee& operator=(const Employee& employe);
			friend ostream& operator<<(ostream& s, const Employee& employe);

	};
//}
#endif