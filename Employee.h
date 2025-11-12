#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Actor.h"
#include <string>
#include <iostream>
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
			Employee(const string log, const string passwrd);
			Employee(const Employee& employe);
			~Employee();

			void setLogin(const string log);
			void setPassword(const string mdp);
			void setRole(const string rol);
			string getRole() const;
			string getGsm() const;
			string getLogin() const;
			string* getPassword() const;

			
			void resetPassword();
			Employee& operator=(const Employee& employe);
			friend ostream& operator<<(ostream& s, const Employee& employe);

	};
//}
#endif