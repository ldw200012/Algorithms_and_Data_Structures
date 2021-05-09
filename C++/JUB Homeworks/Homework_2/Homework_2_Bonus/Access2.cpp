#include "Access2.h"

Access::Access(){
	std::cout << "Key Map Created" << std::endl;
}

void Access::activate(unsigned int code, unsigned int level){
	AccessCodes[code] = level;
}

void Access::deactivate(unsigned int code){
	AccessCodes.erase(code);
}

bool Access::isactive(unsigned int code, unsigned int level) const{

	if(AccessCodes.find(code)->second >= level){
		return true;
	}else{
		return false;
	}
}
