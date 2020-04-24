#include <iostream>
#include <set>

class Access{
public:
	Access();
	void activate(unsigned int code);
	void deactivate(unsigned int code);
	bool isactive(unsigned int code) const;
private:
	std::set <unsigned int> AccessCodes;
};