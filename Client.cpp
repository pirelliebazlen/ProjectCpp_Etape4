#include "Client.h"
#include <string>
#define DEBUG
#include <iostream>
#include <sstream> 
using namespace std;


//namespace carconfig{

	/***************************************************************************/
	/*****************Constructeur par defaut***********************************/
	/***************************************************************************/
	Client:: Client() :Actor()
	{
		setGsm("");
	}

	/***************************************************************************/
	/*****************Constructeur d'initialisation*****************************/
	/***************************************************************************/
	Client:: Client( string lname, string fname, int id, string gsm) :Actor(id, lname, fname)
	{
		setGsm(gsm);
	}
	/***************************************************************************/
	/*****************Constructeur de Copie*************************************/
	/***************************************************************************/

	Client:: Client(const Client& client) :Actor(client)
	{
		setGsm(client.getGsm());
	}

	/***************************************************************************/
	/***************************Destructeur*************************************/
	/***************************************************************************/

	Client:: ~Client()
	{

	}
	/***************************************************************************/
	/***************************Setteur*****************************************/
	/***************************************************************************/

	void Client:: setGsm(const string phoneNumber)
	{
		gsm= phoneNumber;
	}
	
	/***************************************************************************/
	/***************************Getteur*****************************************/
	/***************************************************************************/
	string Client:: getGsm() const
	{
		return gsm;
	}

	/***************************************************************************/
	string Client:: toString() const
	{ 
		ostringstream  s;
			s << "<< [" << "C"<< getId()<< "]" << getLastName() << getFirstName() <<" >>"<< endl;

		return s.str();
	}
	string Client:: tuple() const
	{
		ostringstream s;
		
		s<< getId()<<";"<< getLastName() <<";"<< getFirstName()<<";"<< getGsm()<<" >>"<< endl;

		return s.str();
	}
	void Client:: display() const
	{
		cout<<"Client : ";
		Actor::display();
		cout << "Numero de telephone : " << gsm << endl;
	}


//}