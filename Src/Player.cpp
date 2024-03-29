#include "../Include/Player.hpp"

size_t Player::getAvailableSpace() const{ //Checking the whole vector Cargos from Ship. Add all values then substract with Capacity _return AvailableSpace_;
        size_t amountOfWholeCargos = 0;
        for (auto &v : ship_->getAllCargo())
        {
            amountOfWholeCargos+=v->getAmount();
        }
        return ship_->getCapacity()-amountOfWholeCargos;
    }

void Player::substractMoney(const double& moneyToSubstract)
{
     money_-=moneyToSubstract;
}

void Player::addMoney(const double& moneyToAdd){
    money_+=moneyToAdd;
}

void Player::nextDay(){
    this->substractMoney(ship_->getCrew());
    
}