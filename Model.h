#ifndef MODEL_H  //commande de precompilation
#define MODEL_H //macro
//#include <cstring>
#include <iostream>
using namespace std;  //std est l’abréviation de standard.
                      //C’est le namespace (espace de noms) où se trouvent toutes les fonctions, classes et objets de la bibliothèque standard C++

enum Engine{Petrol, Diesel, Electric, Hybrid};

namespace carconfig {
  class Model
  {
    friend istream& operator>>(istream& s, Model& m);
    friend ostream& operator<<(ostream& s, const Model& m);
    private:

      char * name;       //methode get= pour recuperer le donnee de la variable et set 
      int power;
      Engine engine;      //c'est de variable membre
      float basePrice;

    public:
      Model();  //constructeur par defaut
      Model(const char *n, int p, Engine e, float bp); //constructeur avec parametre
      Model(const Model &m);    //constructeur de copie
      ~Model(); //destructeur    

      void setName(const char *n); // const pour pas modifier la variable name dans le parametre par defaut
      void setPower(int p);
      void setEngine(Engine e);
      void setBasePrice(float bp);


      const char *getName() const;   //const apres les parenthese sert a pas modifier les valeurs des variable membre
      int 		getPower() const;
      Engine 		getEngine() const;
      float 		getBasePrice() const;


    	void display() const;   //const derriere le parenthése signifie que la fonction display ne modifie pas le valeur des variables 
                            //display est une methode de l'object Model
      //void copie(const Model model, const Model &m);
  };
}

#endif
