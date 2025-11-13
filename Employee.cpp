#include "Employee.h"
#include <string>
#define DEBUG
#include <iostream>
#include <sstream>
using namespace std;


//namespace carconfig{

	/************************************************************************************/
	/******************************Constructeur par defaut*******************************/
	/************************************************************************************/

	Employee:: Employee() : Actor()
	{
		#ifdef DEBUG
		//cout<<">> Employee: constructeur par defaut<<"<< endl;
		#endif
		setPassword(nullptr);
	}
	/************************************************************************************/
	/******************************Constructeur d'unitialisation*************************/
	/************************************************************************************/

	Employee:: Employee(string lname, string fname, int id, const string log, const string rol) : Actor(id, lname, fname)
	{
		#ifdef DEBUG
		//cout<<">> Employee : Constructeur d'initialisation<<"<< endl;
		#endif
		setLogin(log);

	}
	/************************************************************************************/
	/******************************Constructeur de copie*********************************/
	/************************************************************************************/

	Employee:: Employee(const Employee& employe) : Actor(employe)
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
		if(password != nullptr)
		{
			delete password;
			password =nullptr;
		}
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
	void Employee:: display() const
	{
		Actor:: display();
		cout<< "Login : " << login<< endl;
		if(password!=nullptr)
		{
			cout<<"password : " << password<< endl;
		}
		else
		{
			cout<<"password : Pas de password" <<endl;
		}
		cout<<"Role : "<< role<< endl;
	}
	string Employee:: toString() const
	{
		ostringstream s;
		string rol;
		rol = getRole();
		if(rol== "Vendeur")
		{
			rol = "V";
		}
		else
		{
			rol = "A";
		}
		s << "<< [" << rol<< getId()<< "]" << getLastName() << getFirstName()<<" >>"<< endl;


		return s.str();
	}
	string Employee:: tuple() const
	{
		ostringstream s;
			
		s<< getId()<<";"<< getLastName() <<";"<< getFirstName()<<";"<<getRole()<<" >>"<< endl;

		return s.str();
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
		s << employe<< endl << employe<<endl;
		return s;
	}


//}