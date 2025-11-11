#include "Model.h"
#include <cstring> 
#include <limits>
#define DEBUG
using namespace std;

namespace carconfig {
// ***************** Constructeurs du Modèle ****************
Model::Model()
{
  #ifdef DEBUG
    //std::cout << "On est dans le constructeur par défaut (Model)" << std::endl;
  #endif
  name=NULL;
  setName("Nom");
  setPower(0);
  setEngine(Engine::Petrol);
  setBasePrice(0.0);
}

Model::Model(const  char*n, int p, Engine e, float bp)
{
  #ifdef DEBUG
    //std::cout << "On est dans le constructeur d'initialisation (Model)" << std::endl;
  #endif
  name=NULL;
  setName(n);
  setPower(p);
  setEngine(e);
  setBasePrice(bp);

}

Model::Model(const Model &m){

    #ifdef DEBUG
      //std::cout << ">>> On est dans le constructeur de copie (Model)" << std::endl;
    #endif
    name=NULL;

    
    setName(m.getName());
    setPower(m.getPower());
    setEngine(m.getEngine());
    setBasePrice(m.getBasePrice());
    
}


// ***************** Destructeur du Modèle ****************
Model::~Model()
{
    #ifdef DEBUG
      //std::cout << "On est dans le destructeur (Model)" << std::endl;
    #endif
    
    //std::cout << "On est dans le destructeur (Model)" << &name << std::endl;    //pour afficher le pointeur de model
    if(name !=NULL) delete name;
}




// ***************** SETTLERS du Modèle****************
void Model::setName(const char *n){ 
  if (n==NULL)return;

  if (name==n)return;

  if (name!=NULL)
  {
    delete [] name; 
    name=new char[strlen(n)+1];
    strcpy(name, n);
  }
  else
  {
    name=new char[strlen(n)+1];
    strcpy(name, n);
  }
  
}

void Model::setPower(int p){
  if(p<0) return;
  power=p; 
}

void Model::setEngine(Engine e){

  engine=e; 
}

void Model::setBasePrice(float bp){
  if (bp<0.0) return;
  basePrice=bp;
}


// ***************** GETTERS du Modèle ****************
const char * Model::getName() const{
    return name;
}

int Model::getPower() const{
    return power;
}

Engine   Model::getEngine() const{
    return engine;
}

float Model::getBasePrice() const{
    return basePrice;
}



// ***************** Méthodes d'instance du Modèle ****************
void Model::display() const
{
  std::cout << "Model : ";
  if(name){
    std::cout << name;
  }
  else{
    std::cout << "Pas de nom ";
  }
    std::cout << "( " << power << " Ch, ";

  switch(engine)
  {
    case Engine::Petrol:
      std::cout << "Essence, " ;
      break;
    case Engine::Diesel:
      std::cout << "Diesel, ";
      break;
    case Engine::Electric:
      std::cout << "Electrique, ";
      break;
    case Engine::Hybrid:
      std::cout << "Hybride ";
      break;
  }

  std::cout << basePrice << " euro)" << std::endl;

}

istream& operator >>(istream& s, Model& m )
{
  char * name;
  int power;
  int eng;
  float baseP;

  name = new char[100];
l
  cout<<"Entrez le nom : ";
  s.getline(name, 100);
  cout << "Entrez la puissance : ";
  s >> power;
  cout << "Entrez le choix du type de moteur (0=Essence, 1=Diesel, 2=Electric, 3=Hybride) : "; 
  s >> eng;
  cout << "Enetrez le prix : ";
  s >> baseP;

  m.setName(name);
  m.setPower(power);
  m.setEngine((Engine) eng);
  m.setBasePrice(baseP); 

  return s;

}

ostream& operator<<(ostream& s, const Model& m)
{
  s << "Model: ";
  s <<m.getName() << endl << m.getPower() << endl;

  switch(m.getEngine())
  {
    case Engine::Petrol: s<< "Essence " << endl; break;
    case Engine::Diesel: s << "Diesel " << endl; break;
    case Engine:: Electric: s <<"Electrique "<< endl; break;
    case Engine::Hybrid: s << "Hybride: " << endl; break;
  }
  s << m.getBasePrice() <<endl;
  
  return s;

}


}
