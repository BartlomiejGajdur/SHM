#pragma once
#include <memory>

#include "Cargo.hpp"

const size_t maxPercentage_{96};

class Alcohol : public Cargo{
    public:
    Alcohol(const std::string& name, 
                       size_t amount, 
                       double basePrice):                                    
                                        Cargo(name,amount,basePrice){}

    Alcohol(const std::string& name, 
                       size_t amount, 
                       double basePrice,
                       size_t percentage):
                                        Cargo(name,amount,basePrice),
                                             percentage_(percentage){}
    Alcohol(const Cargo& other){
        name_     = other.getName();
        amount_   = other.getAmount();
        basePrice_= other.getBasePrice();
    }
     Alcohol() = default;
    ~Alcohol() override = default;
   

    //GETTERS
    std::string getName()   const override {return name_;}
    size_t getAmount()      const override {return amount_;}
    double getBasePrice()   const override {return basePrice_;}
    size_t getPercentage()  const {return percentage_;}
    double getPrice() const override {return (basePrice_*(static_cast<double>(percentage_)/maxPercentage_));}
    Alcohol& operator--() override {return *this;}
    void print(std::ostream& os) const override;
    std::shared_ptr<Cargo> clone() const override{
       return std::make_shared<Alcohol>(*this);
    }

    //OPERATORS
    inline friend std::ostream& operator<<(std::ostream &os, const Alcohol& alcohol) {   
        alcohol.print(os);
        return os;
    }
    
    bool operator==(const Cargo& otherAlcohol) override;
    Alcohol& operator+=(const size_t amount)   override;                                                      
    Alcohol& operator-=(const size_t amount)   override;


    private:
    const size_t percentage_{40};

};

