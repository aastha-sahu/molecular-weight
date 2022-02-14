
#include "MolecularWt.hpp"

void MolecularWt::get_map()
{
	mapmw["C"] = 12;
	mapmw["N"] = 14;
	mapmw["O"] = 16;
	mapmw["H"] = 1;
	mapmw["S"] = 32;
	mapmw["F"] = 19;
	mapmw["Cl"] = 35;





}
const std::string MolecularWt::parse_input_string()

{
	std::string s = compound_name;
	std::string delimiter = "-";
	std::size_t found = s.find(delimiter);
	if (found)
	{
		std::string token = s.substr(s.find(delimiter) + 1, s.size()); 
		return token;
	}
	else
	{
		return s;
	}
}
void MolecularWt::parse_compound()
{
	compound.assign(parse_input_string());
	const char* comp = compound.c_str();
	for (int i = 0; i < compound.length(); i++)
	{
		if (i != 0)
		{
			if (isdigit(comp[i]))
			{
				if (isdigit(comp[i - 1]))
				{
					numbers.back().append(std::string(1, comp[i]));
					std::cout << numbers.back() << std::endl;
				}
				else
				{
					if (comp[i] >= 'a' && comp[i] <= 'z')
					{
						throw std::invalid_argument("Invalid compound: Check formula element name doesn't start with small case");
					}
					else
					{
						numbers.push_back(std::string(1, comp[i]));
					}
				}
			}
			else
			{
				if (!isdigit(comp[i - 1]))
				{
					if (comp[i - 1] >= 'A' && comp[i - 1] <= 'Z')
					{
						if (comp[i] >= 'A' && comp[i] <= 'Z')
						{
							numbers.push_back("1");
							elements.push_back(std::string(1, comp[i]));
						}
						else if (comp[i] >= 'a' && comp[i] <= 'z')
						{
							elements.back().append(std::string(1, comp[i]));
						}
						else
						{
							throw std::invalid_argument( "Invalid character: No special character");
						}
					}
					else if (comp[i - 1] >= 'a' && comp[i - 1] <= 'z')
					{
						if (comp[i] >= 'A' && comp[i] <= 'Z')
						{
							numbers.push_back("1");
							elements.push_back(std::string(1, comp[i]));
						}
						else if (comp[i] >= 'a' && comp[i] <= 'z')
						{
							elements.back().append(std::string(1, comp[i]));
						}
						else
						{
							throw std::invalid_argument("Invalid character: No special character");
						}
					}
				}
				else
				{
					if (comp[i] >= 'a' && comp[i] <= 'z')
					{
						throw std::invalid_argument("Invalid formula: Check formula element name doesn't start with small case");
					}
					else if (comp[i] >= 'A' && comp[i] <= 'Z')
					{
						elements.push_back(std::string(1, comp[i]));
					}
					else
					{
						throw std::invalid_argument("Invalid character: No special character");
					}
				}
			}
		}
		else
		{
			if (isdigit(comp[i]))
			{
				throw std::invalid_argument("Invalid formula: Doesnt start with Numeric");
			}
			else
			{
				if (comp[i] >= 'a' && comp[i] <= 'z')
				{
					throw std::invalid_argument("Invalid compound: Check formula element name doesn't start with small case");
				}
				else if (comp[i]>='A'&&comp[i]<='Z')
				{
					elements.push_back(std::string(1, comp[i]));
				}
				else
				{
					throw std::invalid_argument("Invalid character: No special character");
				}
			}
		}
		if (i == compound.length() - 1)
		{
			if (!isdigit(comp[i]))
			{
				numbers.push_back("1");
			}
		}
	}
}
int MolecularWt::calculatemw()
{
	molecular_wt = 0;
	std::vector<std::string>::iterator it_num;
	std::vector<std::string>::iterator it;
	for (it = elements.begin(), it_num = numbers.begin(); it != elements.end(), it != numbers.end(); it++, it_num++)
	{
		std::string a = *it_num;
		molecular_wt += mapmw.at(*it) * atoi(a.c_str());
	}
    return 0;
}
double MolecularWt::get_molecular_wt()
{
	try

	{
	
		parse_compound();
		get_map();
		if (elements.size() != numbers.size())
		{
			throw std::runtime_error("Fatal Error: Elements and Stoichiometry did not match");
		}
		int retval = calculatemw();
	}
	catch (const std::exception&  e)
	{
		std::cerr<< e.what() << std::endl;
		throw std::exception(e.what());
	}
	return molecular_wt;
}




