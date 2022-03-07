#ifndef PRESSURE_HPP
#define PRESSURE_HPP

#include <string>
#include <stdexcept>
#include <iostream>
#include<cstdlib>

class pressure
{
  public:
	
	double tip(double, double, double, double);
	double riser(double, double, double, double);
	double molecularseal(double, double, double, double);
	double waterseal(double, double, double, double);
	double kod(double, double, double, double);
	double velocityseal(double, double, double, double);
	double total_pressure_drop(double,double,double ,double);
	double pressure_drop(double, double);
};
#endif;
