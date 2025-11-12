#include "Client.h"
#include <string>
#define DEBUG
#include <iostream>
using namespace std;


//namespace carconfig{

	void Client:: setGsm(const string phoneNumber)
	{
		gsm= phoneNumber;
	}
	
	string Client:: getGsm() const
	{
		return gsm;
	}


//}