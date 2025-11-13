#ifndef CLIENT_H
#define CLIENT_H
#include "Actor.h"
#include <string>
#include <iostream>
using namespace std;


//namespace carconfig{
	class Client : public Actor
	{
		private:
			string gsm;
		public:
			Client();
			Client( string lname, string fname, int id, string gsm);
			Client(const Client& client);
			~Client();
			void setGsm(const string phoneNumber);
			string getGsm() const;
			string tuple() const override;
			string toString() const override;
			void display() const override;
	};
//}
#endif