

#include <iostream>
#include <new> // required for std::nothrow and std::bad_alloc
#include <string>
#include <sstream>

class Instrument
{
  public:
	std::string _label;
	Instrument(void)
	{
		this->_label = "Unknown";
	}
	Instrument(std::string const &label) : _label(label)
	{
		std::cout << "[Instrument] '" << this->_label << "' created" << std::endl;
	}
	~Instrument(void)
	{
		std::cout << "[Instrument] '" << _label << "' destroyed." << std::endl;
	}
};

void	demoThrowingNew(void)
{
	std::cout << "\n--- Demo 1: Throwing new ---" << std::endl;
	try
	{
		Instrument	*sensor = new Instrument("Thermometer");
		std::cout << " Allocated :" << sensor->_label << std::endl;
		delete		sensor;
		sensor = NULL;
		std::cout << " Freed successfully" << std::endl;
	}
	catch (std::bad_alloc const &e)
	{
		std::cerr << "Failed malloc :" << e.what() << std ::endl;
	}

}
void	demoNothrowNew(void)
{
	std::cout << "\n--- Demo 2: Nothrow new ---" << std::endl;
	Instrument	*e = new (std::nothrow) Instrument("Barmeter");
	if (e == NULL)
	{
		std::cerr << "Allocation failed and returned NULL" << std::endl;
		return ;
	}
	std::cout << "  Allocated: " << e->_label << std::endl;
	delete		e;
	e = NULL;
	std::cout << "  Freed successfully." << std::endl;
}
void demoArray(void)
{
    std::cout << "\n--- Demo 3: new[] and delete[] ---" << std::endl;
	int const count =3 ;
	Instrument *readings = new Instrument[count];
	    for (int i = 0; i < count; i++) {
			std::stringstream ss;
			ss << i ;
        readings[i]._label += ss.str();
        std::cout << "  readings[" << i << "] = " << readings[i]._label << std::endl;
    }
	delete [] readings ;
	readings = NULL;
	std::cout << "Array freed ."<<std::endl;
}

void demoDeleteNull(void)
{
	Instrument *e = NULL;
	std::cout << "\n--- Demo 4: delete NULL (safe) ---" << std::endl;
	std::cout << "calling delete on NULL is totally safe"<<std::endl;
	delete e;
	std::cout << "see nothing happen  delete NULL is a guaranteed no-op."<<std::endl;

}

bool demoEarlyReturn(bool triggerEarlyExit)
{
	    std::cout << "\n--- Demo 5: Clean early return ---" << std::endl;
		Instrument *sensor = new (std::nothrow) Instrument("Hygrometer");
		if(sensor == NULL)
		return false;
		if (triggerEarlyExit)
		{
			std::cout << "Early exit triggered - cleaning up before return ."<<std::endl;
			delete sensor;
			sensor  =NULL;

			return false;

		}

		    std::cout << "  Normal path — cleaning up before return." << std::endl;
    delete sensor;
    sensor = NULL;
    return true;
}


int	main(void)
{
	demoThrowingNew();
	demoNothrowNew();
	demoArray();
	demoDeleteNull();
	demoEarlyReturn(true);
	demoEarlyReturn(false);

	std::cout << "\n--- All demos complete. No leaks. ---" << std::endl;
	return (0);
}