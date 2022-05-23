#include "Ship.hpp"

Ship& Ship::operator+=(const uint16_t size){
    crew_ = ((crew_+size)<maxCrew_) ? crew_+size : -1;
    std::cout<<std::endl;
    if(crew_==-1)
            std::cout<<"Error, The amount of actuall crew is more than maxCrew (error code -1)"<<std::endl;
    return *this;
}

Ship& Ship::operator-=(const uint16_t size){
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

std::vector<std::shared_ptr<Cargo>>::iterator Ship::findMatchCargo(std::shared_ptr<Cargo> cargo) {
    auto findMatchCargo = std::find_if(cargos_.begin(), cargos_.end(),
                                       [cargo](const auto& el) {
                                           return cargo->getBasePrice() == el->getBasePrice() &&
                                                  cargo->getPrice() == el->getPrice() &&
                                                  cargo->getName() == el->getName();
                                       });
    return findMatchCargo;
}

void Ship::load(std::shared_ptr<Cargo> cargo) {
    uint16_t sumAmount{};

    for (const auto& el : cargos_) {
        sumAmount += el->getAmount();
    }

    if (sumAmount > getCapacity()) {
        std::cerr << "Our ship is to small to cary all the cargos, Captain!";
        return;
    }

    auto isCargoUnique = findMatchCargo(cargo);

    if (isCargoUnique == cargos_.end()) {
        cargos_.push_back(cargo);
        return;
    }

    **isCargoUnique += cargo->getAmount();
}

void Ship::removeFromStorage(std::shared_ptr<Cargo> cargo) {
    cargos_.erase(findMatchCargo(cargo));
}

void Ship::unload(std::shared_ptr<Cargo> cargo, uint16_t amount) {
    auto choosenCargo = findMatchCargo(cargo);

    if (choosenCargo == cargos_.end()) {
        return;
    }

    if ((*choosenCargo)->getAmount() <= cargo->getAmount()) {
        removeFromStorage(cargo);
        return;
    }
    **choosenCargo -= amount;
}
