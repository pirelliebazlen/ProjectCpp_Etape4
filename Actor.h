#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include <iostream>
using namespace std;
#include "Person.h"

//namespace carconfig {

	class Actor : public Person
	{
		protected:
			int id;


		public:
			void setId(const int Newid);
			int getId();
			Actor& operator=(const int newid);
			virtual void tuple();
			virtual void toString();
	};
//}
#endif