#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Ship.hpp"
#include "Cargo.hpp"


void printCargo(const Cargo& t);
void printShip (const Ship& s);
void printShip (const Ship& s, const Cargo& t);


int main(){ 

    // Cargo chleb("Chleb",10,2.2);
    // std::vector<Ship> statki;

    // Ship Statek1(1,"axatek z chlebem",20,100,2,50,chleb);
    // Ship Statek2(1,"aaatek z chlebem",20,100,2,50,chleb);
    // Ship Statek3(1,"acatek z chlebem",20,100,2,50,chleb);

    // statki.push_back(Statek1);
    // statki.push_back(Statek2);
    // statki.push_back(Statek3);


    // sort(statki.begin(),statki.end(),[](auto l, auto r)
    // {return l.getName() < r.getName(); });

    // for(auto s : statki)
    // {
    //      std::cout<<"ID: "<<s.getId()<<std::endl;
    //     std::cout<<"Name: "<<s.getName()<<std::endl;
    //     std::cout<<"Speed: "<<s.getSpeed()<<std::endl;
    //     std::cout<<"ActualCrew: "<<s.getCrew()<<"   MaxCrew: "<<s.getMaxCrew()<<std::endl;
    //     std::cout<<"Capacity: "<<s.getCapacity()<<std::endl<<std::endl;
    // }
    
   Alcohol alko(10,"wodka",50,40);
   std::cout<<alko.getPrice()<<std::endl;

   Item itemik(10,"Pokemon",100,Item::Rarity::legendary);
   std::cout<<itemik.getPrice()<<std::endl;
   
   Fruit jabko(10,"jablek",1,40,16);
   std::cout<<jabko.getExpiryDate()<<std::endl;
   std::cout<<jabko.getTimeElapsed()<<std::endl;
   std::cout<<jabko.getPrice()<<std::endl;
    --jabko;
      std::cout<<jabko.getTimeElapsed()<<std::endl;
   std::cout<<static_cast<int>(1 * float(16 / 40));


  


    return 0;
}


void printCargo(const Cargo& t)
            {
                std::cout<<"Nazwa towaru: "<<t.getName()<< " || Ilosc towaru: "<<t.getAmount()<<"  || Cena: "<<t.getBasePrice()<<std::endl;
            }

void printShip (const Ship& s)
{       
        std::cout<<std::endl;
        if(s.getCrew()>0 && s.getCrew()<s.getMaxCrew())
        {
        std::cout<<"ID: "<<s.getId()<<std::endl;
        std::cout<<"Name: "<<s.getName()<<std::endl;
        std::cout<<"Speed: "<<s.getSpeed()<<std::endl;
        std::cout<<"ActualCrew: "<<s.getCrew()<<"   MaxCrew: "<<s.getMaxCrew()<<std::endl;
        std::cout<<"Capacity: "<<s.getCapacity()<<std::endl;
        
        }      
}

void printShip (const Ship& s, const Cargo& t)
{       
        std::cout<<std::endl;
        if(s.getCrew()>0 && s.getCrew()<s.getMaxCrew())
        {
        std::cout<<"ID: "<<s.getId()<<std::endl;
        std::cout<<"Name: "<<s.getName()<<std::endl;
        std::cout<<"Speed: "<<s.getSpeed()<<std::endl;
        std::cout<<"ActualCrew: "<<s.getCrew()<<"   MaxCrew: "<<s.getMaxCrew()<<std::endl;
        std::cout<<"Capacity: "<<s.getCapacity()<<std::endl;
        std::cout<<"Nazwa towaru: "<<t.getName()<< " || Ilosc towaru: "<<t.getAmount()<<"  || Cena: "<<t.getBasePrice()<<std::endl;
        }      
}






