#include <iostream>
#include <map>

class Access{
public:
	Access();
	void activate(unsigned int code, unsigned int level);
	void deactivate(unsigned int code);
	bool isactive(unsigned int code, unsigned int level) const;
private:
	std::map <unsigned int, unsigned int> AccessCodes;
};