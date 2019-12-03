#include "clsComArduino.hpp"

REGISTER_DEF_TYPE(clsComArduino, 2);

//===================================================
clsComArduino::clsComArduino()
{
    m_etype = e_reg;
}

std::string clsComArduino::GetName(){
    return "clsComArduino";
}