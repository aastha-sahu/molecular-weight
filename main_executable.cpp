#include "MolecularWt.hpp"
int main()
{
	std::cout << "Hello Ador Engineering" << std::endl;
	try
	{
		std::shared_ptr<MolecularWt> mw = std::make_shared<MolecularWt>(MolecularWt("C2H5C5O3"));
		double a = mw->get_molecular_wt();
		std::cout << a << std::endl;
		MolecularWt mw1("C2H5C5O3");
		double b = mw1.get_molecular_wt();
		std::cout << b << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
		exit(1);

	}

	
	/*std::shared_ptr<CalJob> cal;
	std::shared_ptr<BuildCalJob_Manually> caljob_builder = std::make_shared<BuildCalJob_Manually>(BuildCalJob_Manually());
	try
	{
		caljob_builder->add_data();
		cal = caljob_builder->get_cal_job();
	}
	catch (const char* error)
	{
		std::cout << error << std::endl; 
		exit(1);
	}
	std::shared_ptr<RunCalJob> run = std::make_shared<RunCalJob>(RunCalJob(cal));
	std::shared_ptr<Output> outval = std::make_shared<Output>(Output());
	try
	{
		outval->T = run->run_cal_to_convert_temp();
	}
	catch (const char* error)
	{
		std::cout << error << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}
	std::cout << outval->T << std::endl;*/
}