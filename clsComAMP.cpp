#include "clsComAMP.hpp"

REGISTER_DEF_TYPE(clsComAMP, 1);

//===================================================
clsComAMP::clsComAMP()
{
    m_etype = e_auth;
}

std::string clsComAMP::GetName(){
    return "clsComAMP";
}