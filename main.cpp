#include "pressure.hpp"
#include <iostream>
int main()
{
    double t,temp,wt,den,f;
    
    std::cout << "enter temperature: " << std::endl;
	std::cin >> temp;
	std::cout << "enter molecular weight" << std::endl;
	std::cin >> wt;
	std::cout << "enter density" << std::endl;
	std::cin >> den;
	std::cout << "enter flow" << std::endl;
	std::cin >> f;
    std::shared_ptr<pressure> p = std::make_shared<pressure>(pressure());
    t = p->total_pressure_drop(temp,wt,den,f);
    std::cout << "Total pressure drop is = " << t << "mmWC";
    return 0;
}

