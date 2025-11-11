#include "Car.h"
#include "Model.h"
#include "Option.h"
#include <cstring>
#define DEBUG
using namespace std;

namespace carconfig {
Car::Car()
{
	#ifdef DEBUG
		//cout<<">> Car : constructeur par defaut<<"<< endl;
	#endif
	name="";
	for(int i=0; i < 5; i++)
	{
		Car::options[i]= nullptr;
	}

}

Car:: Car(string n, Model m)
{
	#ifdef DEBUG
		//cout<< ">> Car : constructeur d'initialisation <<"<< endl;
	#endif
	setName(n);
	setModel(m);

	for(int i=0; i < 5; i++)
	{
		Car::options[i]= nullptr;
	}
	

}

Car:: Car(const Car &c)
{
	#ifdef DEBUG
		//cout<<">> Car : constructeur de copie<<"<< endl;
	#endif
	setName(c.getName());

	setModel(c.getModel());

	for(int i=0; i< 5; i++)
	{
		if(c.options[i] != nullptr)
		{
			options[i]= new Option(*(c.options[i]));
		}
		else
		{
			options[i]= nullptr;
		}
		

	}

}

//**************************************************************************
//******************** Destructeurs ***************************************
//**************************************************************************

Car:: ~Car()
{
	#ifdef DEBUG
		//cout<<">> Car destructeur <<" <<endl;
	#endif

	for(int i=0; i < 5; i++)
	{
		delete options[i];
		options[i]= nullptr;

	}
	
}


//*********************************************************************
//******************* Setters******************************************
//*********************************************************************
 
void Car::setName(string n)
{
	name=n;
	
}

void Car::setModel(const Model m)
{
	
	model.setName(m.getName());
	model.setPower(m.getPower());
	model.setEngine(m.getEngine());
	model.setBasePrice(m.getBasePrice());
}

//********************************************************************
//******************* Getters*****************************************
//********************************************************************

string Car::getName() const
{
	return name;
}
Model Car::getModel() const
{
	return model;
}


void Car::display() const
{
	cout<<"Nom : ";
	if(name.size()!=0) 
		cout << name << endl;
	else
		cout << "pas de nom" << endl;

	model.display();

	cout<< "Option:";

	int i=0;

	while(i < 5)
	{
		if(options[i]!=nullptr)
		{

			options[i]->display();
		}
		i++;
	}
	
}

void Car::addOption(const Option &option) 
{
	int i=0, verif=0;

	while(i < 5 && verif==0)
	{
		if(options[i]==nullptr){
			options[i] = new Option(option);
			verif=1;
		}
		i++;
	}
		
	
}
void Car::removeOption(string code)
{
	int i=0, verif=0;
	while(i < 5 && verif==0)
	{
		if(options[i]!= nullptr)
		{

			if(options[i]->getCode()==code)
			{
				delete options[i];
				options[i]= nullptr;
				verif=1;
			}
		}
		
		i++;
	}
	if(i==5)
	{
		cout << "Pas de Option correspondant trouver" << endl;
	}

}

float Car::getPrice()
{
	float prix;
	int OpPrice;

	for(int i=0; i <5; i++)
	{
		if(options[i]!= nullptr)
		{
			OpPrice += options[i]->getPrice();

		}
		
	}
	prix =model.getBasePrice();
	prix+=OpPrice;
	
	return prix;
}
Car& Car::operator=(const Car& c)
{

	setName(c.getName());
	setModel(c.getModel());

	for(int i=0; i < 5; i++)
	{

		if(c.options[i]!=nullptr)
		{
			options[i]= new Option(*(c.options[i]));
		}
		else
		{
			options[i]= nullptr;
		}
	}
	return (*this);
}

Car Car::operator+(const Option &option)
{
	Car newObject(*this); 

	newObject.addOption(option);

	return newObject;
}


Car Car::operator-(string option)
{
	removeOption(option);
	return (*this);
}

Car Car::operator-(const Option& op)
{
	Car newCar(*this);
	newCar.removeOption(op.getCode());

	return newCar;
}

Car operator+(const Option &op ,const Car &c)
{
	Car newObject(c);

	newObject.addOption(op);

	return newObject;
}

int Car::operator<(const Car& c)
{
	
	return verification(c)==-1;

}
int Car::operator>(const Car& c)
{
	
	return verification(c)==1;

}
int Car::operator==(const Car& c)
{
	
	return verification(c)==0;

}

int Car::verification(const Car& c)
{
	Car newObjt(*this);
	Car newObjt1(c);
	if(newObjt.getPrice()< newObjt1.getPrice()) return -1;
	if(newObjt.getPrice()> newObjt1.getPrice()) return 1;
	if(newObjt.getPrice()== newObjt1.getPrice()) return 0;
	return 2;
}

ostream& operator<<(ostream &s, const Car& c)
{
	s << c.getName() << endl << c.getModel() << endl;

	for(int i=0; i <5;i++)
	{
		if(c.options[i]!= nullptr)
		{
			s << c.options[i]->getCode() << endl;
			s << c.options[i]->getLabel() << endl;
			s << c.options[i]->getPrice() <<endl;
		}
		
	}

	return s;
}

Option* Car::operator[](int i)
{
	switch(i)
	{
		case 0: return options[0];
		case 1: return options[1];
		case 2: return options[2];
		case 3: return options[3];
		case 4: return options[4];
		default: return nullptr;
	}
}


}//carconfig




