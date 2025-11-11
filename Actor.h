#ifndef ACTOR_H
#define ACTOR_H
#include <string>
#include <iostream>
using namespace std;
#include "Person.h"

namespace carconfig {

	class Actor : public Person
	{
		protected:
			int id;


		public:
			Actor();
			Actor(string lName, string fName, int id);
			Actor(const Actor& ac);
			~Actor();
			Actor& operator=(const Actor& ac);
			virtual void tuple();
			virtual void toString();
	};
}
#endif