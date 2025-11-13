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
			Actor();
			Actor(int id, string Lname, string Fname);
			Actor(const Actor& ac);
			~Actor();
			void setId(const int Newid);
			int getId() const;
			Actor& operator=(const int newid);
			void display() const override;
			virtual string tuple() const =0;
			virtual string toString() const=0;
	};
//}
#endif