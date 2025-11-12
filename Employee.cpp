#include "Employee.h"
#include <string>
#define DEBUG
#include <iostream>
using namespace std;


//namespace carconfig{

	/************************************************************************************/
	/******************************Constructeur par defaut*******************************/
	/************************************************************************************/

	Employee:: Employee()
	{
		#ifdef DEBUG
		//cout<<">> Employee: constructeur par defaut<<"<< endl;
		#endif
		password = nullptr;
	}
	/************************************************************************************/
	/******************************Constructeur d'unitialisation*************************/
	/************************************************************************************/

	Employee:: Employee(const string log, const string passwrd)
	{
		#ifdef DEBUG
		//cout<<">> Employee : Constructeur d'initialisation<<"<< endl;
		#endif
		setLogin(log);
		setPassword(passwrd);

	}
	/************************************************************************************/
	/******************************Constructeur de copie*********************************/
	/************************************************************************************/

	Employee:: Employee(const Employee& employe)
	{
		#ifdef DEBUG
		//cout<<">> Employee: constructeur de copie<<"<< endl;
		#endif
		setLogin(employe.getLogin());
		//setPassword(employe.getPassword());
		setPassword(*(employe.password));

	}
	/************************************************************************************/
	/******************************Destructeur*******************************************/
	/************************************************************************************/

	Employee:: ~Employee()
	{
		//if(password != nullptr)
		//{
			delete password;
			password =nullptr;
		//}
	}

	/************************************************************************************/
	/******************************Setteur***********************************************/
	/************************************************************************************/
	void Employee:: setLogin(const string log)
	{
		login = log;
	}
	void Employee:: setPassword(const string mdp)
	{
		password = new string(mdp);
	}
	void Employee:: setRole(const string rol)
	{
		role = rol;
	}

	/************************************************************************************/
	/******************************Getteur***********************************************/
	/************************************************************************************/

	string Employee:: getLogin() const
	{
		return login;
	}
	string* Employee:: getPassword() const
	{
		return password;
	}
	string Employee:: getRole() const
	{
		return role;
	}

	/*******************************************************************/

	void Employee:: resetPassword()
	{
		password = nullptr;
	}

	void Employee:: fonction(string rol)
	{
		role = rol;
	}

	Employee& Employee:: operator=(const Employee& employe)
	{
		setLogin(employe.getLogin());
		//setPassword(employe.getPassword());
		setPassword(*(employe.password));
		return (*this);
	}
	ostream& operator<<(ostream& s, const Employee& employe)
	{
		s << employe.getLogin() << endl << employe.getPassword() <<endl;
		return s;
	}


//}