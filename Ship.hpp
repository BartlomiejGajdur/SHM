#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
#include "Cargo.hpp"

class Cargo;

class Ship{
    long id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    int crew_;
    //Cargo cargo_;

    public:
        Ship(long id, const std::string& name, size_t speed, size_t maxCrew,size_t capacity,int crew); //Whole data
        //Ship(long id, size_t speed, size_t maxCrew) : Ship(id,"", speed, maxCrew,0,0) {}
        //Ship() : id_(-1) {}
        //Setters:
        void setId(long id) {id_ = id;}
        void setName(const std::string& name) {name_ = name;}
        void setSpeed(size_t speed) {speed_ = speed;}
        void setMaxCrew(size_t maxCrew) {maxCrew_ = maxCrew;}
        void setCapacity(size_t capacity) {capacity_ = capacity;}
        void setCrew(int crew) {crew_ = crew;}

        //Getters:
        long getId() const {return id_;}  
        std::string getName() const {return name_;}
        size_t getSpeed() const{return speed_;}
        size_t getMaxCrew() const{return maxCrew_;}
        size_t getCapacity() const {return capacity_;}
        size_t getCrew() const {return crew_;}

        //Functions:
            Ship& operator+=(const int);  
            Ship& operator-=(const int); 
        
         
};