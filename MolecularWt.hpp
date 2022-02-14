#ifndef MOLECULARWT_HPP
#define MOLECULARWT_HPP
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
//***********************************************************************************************************************************
//								Calculated Mw from only the formula of the compound and returns it 
//***********************************************************************************************************************************
class MolecularWt
{
public:
	MolecularWt(std::string _compound_name) : compound_name(_compound_name) {}
	double get_molecular_wt();
private:
	void get_map();
	void parse_compound();
	int calculatemw();
	const std::string parse_input_string();
	std::string compound;
	const std::string compound_name;
	std::map<const std::string, double> mapmw;
	std::vector<std::string> elements, numbers;
	double molecular_wt;
};
#endif // !MOLECULARWT_HPP
