#ifndef COMAMP_HPP
#define COMAMP_HPP
#include "clsEnsObj.hpp"

class clsComAMP : public clsEnsObj
{
public:
    clsComAMP();
    std::string GetName();
protected:
private:
    REGISTER_DEC_TYPE(clsComAMP);
};
#endif