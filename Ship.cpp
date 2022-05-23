#include "Ship.hpp"

Ship& Ship::operator+=(const int size){
    crew_ = ((crew_+size)<maxCrew_) ? crew_+size : -1;
    std::cout<<std::endl;
    if(crew_==-1)
            std::cout<<"Error, The amount of actuall crew is more than maxCrew (error code -1)"<<std::endl;
    return *this;
}

Ship& Ship::operator-=(const int size){
    crew_ = ((crew_- size) > 0)? crew_-size : -1;
    std::cout<<std::endl;
    if(crew_==-1)
            std::cout<<"Error, The amount of actuall crew is lower than 0(error code -1)"<<std::endl;
    return *this;
}

Ship::Ship(long id,const std::string& name, size_t speed, size_t maxCrew,size_t capacity,int crew)
:   id_(id),
    name_(name),
    speed_(speed),
    maxCrew_(maxCrew),
    capacity_(capacity),
    crew_(crew)
{}
