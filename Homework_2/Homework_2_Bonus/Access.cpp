#include "Access.h"

Access::Access(){
	std::cout << "Key Set Created" << std::endl;
}

void Access::activate(unsigned int code){
	AccessCodes.insert(code);
}

void Access::deactivate(unsigned int code){
	AccessCodes.erase(code);
}

bool Access::isactive(unsigned int code) const{
	if(AccessCodes.find(code) == AccessCodes.end()){
		return false;
	}else{
		return true;
	}
}
