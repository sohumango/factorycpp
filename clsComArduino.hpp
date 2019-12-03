#ifndef COMARDUINO_HPP
#define COMARDUINO_HPP
#include "clsEnsObj.hpp"

class clsComArduino : public clsEnsObj
{
public:
    clsComArduino();
    std::string GetName();
protected:
private:
    REGISTER_DEC_TYPE(clsComArduino);
};
#endif