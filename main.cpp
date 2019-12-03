#include "clsEnsObj.hpp"
#include <iostream>
#include <string>

int main() {
    BaseFactory fact;

    // clsEnsObjPtr objptr( EnsFacotry.createInstance("clsComAMP") );
    clsEnsObjPtr objptr(fact.createInstance(clsEnsObj::e_reg));
    std::cout << objptr->GetName() << std::endl;
    // clsEnsObjPtr objptr2( EnsFacotry.createInstance("clsComArduino") );
    clsEnsObjPtr objptr2(fact.createInstance(clsEnsObj::e_auth));
    std::cout << objptr2->GetName() << std::endl;
    return 0;
}