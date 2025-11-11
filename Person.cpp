#include "Person.h"

#include <string>
#define DEBUG
using namespace std;

//namespace carconfig{

	Person:: Person()
	{
		#ifdef DEBUG
			cout << ">> Person : Constructeur par defaut <<" <<endl;
		#endif
		setLastName("");
		setFirstName("");
	}
	Person:: Person(string Lname, string Fname)
	{
		setLastName(Lname);
		setFirstName(Fname);
	}
	Person:: Person(const Person& per)
	{
		setLastName(per.getLastName());
		setFirstName(per.getFirstName());
	}
	//**************************************************************************
	//******************** Destructeurs ***************************************
	//**************************************************************************

	Person:: ~Person()
	{
		#ifdef DEBUG
			cout << ">> Person : Destructeur <<" <<endl;
		#endif
	}

	//**************************************************************************
	//******************** Setteurs ***************************************
	//**************************************************************************

	void Person:: setLastName(const string Lname)
	{
		lastName = Lname;
	}
	void Person:: setFirstName(const string Fname)
	{
		firstName = Fname;
	}

	//**************************************************************************
	//******************** Getteurs ***************************************
	//**************************************************************************


	string Person:: getLastName() const 
	{
		return lastName;
	}
	string Person:: getFirstName() const
	{
		return firstName;
	}

	void Person:: display() const
	{
		cout<<"Nom : " << lastName << endl;
		cout<<"PreNom : " << firstName << endl;
	}
	Person& Person:: operator=(const Person& per)
	{
		setLastName(per.getLastName());
		setFirstName(per.getFirstName());
		return (*this);
	}
	ostream& operator<<(ostream &s, const Person& per)
	{
		s<< "Nom: " << per.getLastName() << endl;
		s<< "Prenom: " << per.getFirstName() << endl;
		return s;
	}
	istream& operator>>(istream &s, Person& per)
	{
		string lName;
		string fName;
		cout<< "Entrez le nom : ";
		getline(s, lName, '\n');
		cout << "Entrez le PreNom : ";
		getline(s, fName, '\n');
		per.setLastName(lName);
		per.setFirstName(fName);

		return s;
	}
//}

