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
			void setGsm(const string phoneNumber);
			string getGsm() const;
	};
//}
#endif