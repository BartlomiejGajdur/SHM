#include <numeric>
#include <algorithm>

#include "../Include/Ship.hpp"

Ship& Ship::operator+=(const int num)
    {
        if(crew_+num>maxCrew_)
            {
                std::cerr<<"Too many papays!";
                return *this;
            }else{
                crew_+=num;
                return *this;
            }
    }

Ship& Ship::operator-=(const size_t num)
    {
        if(num>crew_)
            {
                std::cerr<<"Number of papays is lower than 0\n";
                return *this;
            }else{
                crew_-=num;
                return *this;
            }
    }

size_t Ship::getAvailableSpace() { //returns Available space 

    return getCapacity() - std::accumulate(cargo_.begin(), cargo_.end(),0,[](size_t amountOfWholeCargos, std::shared_ptr<Cargo> v){
                                                                          return amountOfWholeCargos+v->getAmount();}); 
}

void Ship::load(const std::shared_ptr<Cargo> &cargo)
{
    //Sprawdzenie czy towar ktory ma byc dodany nie bedzie zajmowal wicej niż dostępne miejsce na statku 
    if (getAvailableSpace()>=cargo->getAmount()) {
        //Przeszukanie czy na statku jest już taki sam towar
        for (auto &v : getAllCargo())
        {
            if(*cargo == *v){
                *v+=cargo->getAmount();
                return;
            }  
        }
        cargo_.push_back(cargo);
        
    }else{
        std::cout<<"No available space for: "<<cargo->getName()<<" | Amount: "<<cargo->getAmount()<<"\n";
    } 
    
    
}

void Ship::unload(const std::shared_ptr<Cargo> &cargo){ 
        
    for (auto &v : cargo_)
        {
            if(*cargo == *v)
            {
                if(cargo->getAmount()>= v->getAmount())
                {   
                    cargo_.erase(std::remove_if(cargo_.begin(), cargo_.end(), [&cargo](auto &x){return *cargo==*x;}), cargo_.end()); // Nie usuwa z vectora cargo
                    return;
                }else{
                    *v-=cargo->getAmount();
                    return;
                }
            }
        }
        std::cout<<"There is no such Cargo on ship!\n";    
}

void Ship::printCargo() const{
    for (auto &v: cargo_){
        std::cout<<*v<<std::endl;
     }
}