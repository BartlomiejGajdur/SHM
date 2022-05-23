#pragma once
#include <string>
#include <iostream>


class Cargo{
    protected:
        std::string name_;
        size_t      amount_;
        size_t      basePrice_;
    public:
            Cargo(size_t amount, std::string name, size_t basePrice) 
            :   amount_(amount),
                name_(name),
                basePrice_(basePrice)
            {}
            Cargo() = default;
            virtual ~Cargo() =default;

            virtual size_t          getPrice()       const = 0;
            virtual std::string     getName()        const = 0;
            virtual size_t          getAmount()      const = 0;
            virtual size_t          getBasePrice()   const = 0;

            virtual Cargo& operator+=(const size_t) = 0;
            virtual Cargo& operator-=(const size_t) = 0;
};

class Fruit : public Cargo{
    public:
        Fruit(size_t amount, std::string& name, size_t basePrice, size_t expiry_date, size_t time_elapsed )
        : Cargo(amount,name,basePrice), 
          expiry_date_(expiry_date),
          time_elapsed_(time_elapsed)
          {}
             //Getters:
            std::string getName() const override    {return name_;}
            size_t getAmount()    const override    {return amount_;}
            size_t getBasePrice() const override    {return basePrice_;}
            size_t getPrice()     const override 
            {
                if(time_elapsed_>=expiry_date_)
                    return 0;
                return static_cast<size_t>(
                    basePrice_*((float)(expiry_date_-time_elapsed_))/expiry_date_);
            }


            Cargo& operator+=(const size_t value) override
            {
                amount_+=value;
                return *this;
            }

            Cargo& operator-=(const size_t value) override
            {
                amount_-=value;
                return *this;
            }

            Cargo& operator--()
            {
                --amount_;
                return *this;
            }
            
            size_t getTimeElapsed() const     {return time_elapsed_;}
            size_t getExpiryDate()  const     {return expiry_date_;}
    private:
        size_t time_elapsed_{0};
        size_t expiry_date_;


};

class Alcohol : public Cargo{
    public:
        Alcohol(size_t amount, std::string name, size_t basePrice, size_t percentageOfSpirit)
        : Cargo(amount,name,basePrice), 
        percentage_of_Spirit_(percentageOfSpirit)
        {}
        ~Alcohol() override = default;

        std::string getName() const override    {return name_;}
        size_t getAmount()    const override    {return amount_;}
        size_t getBasePrice() const override    {return basePrice_;}
        size_t getPrice()     const override    {return basePrice_ *percentage_of_Spirit_/96;}

        Cargo& operator+=(const size_t value) override
            {
                amount_+=value;
                return *this;
            }

            Cargo& operator-=(const size_t value) override
            {
                amount_-=value;
                return *this;
            }

        size_t getPercentage() const { return percentage_of_Spirit_;}


    private:
        size_t percentage_of_Spirit_;

};

class Item : public Cargo{
    public:
        enum class Rarity{
            common = 1,
            rare = 3,
            epic = 6,
            legendary = 10
        };
    Item(size_t amount, std::string name, size_t basePrice, Rarity rarity)
    : Cargo(amount,name,basePrice), 
      rarity_(rarity)
    {}
    ~Item() override = default;

    size_t getAmount() const override {return amount_;}
    std::string getName() const override {return name_;}
    size_t getBasePrice() const override {return basePrice_;}
    size_t getPrice() const override {return basePrice_*static_cast<int>(rarity_);}


    Cargo& operator+=(const size_t value) override
            {
                amount_+=value;
                return *this;
            }

    Cargo& operator-=(const size_t value) override
            {
                amount_-=value;
                return *this;
            }

    Rarity getRarity() const {return rarity_;}
    private:
        Rarity rarity_;
};