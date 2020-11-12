#include <boost/program_options.hpp>
#include <iostream>
#include <fstream>
#include <string>

namespace opt = boost::program_options;

int main(int argc, char *argv[])
{
    // Constructing an options describing variable and giving it a
    // textual description "All options".
    opt::options_description desc("All options");

    // When we are adding options, first parameter is a name
    // to be used in command line. Second parameter is a type
    // of that option, wrapped in value<> class. Third parameter
    // must be a short description of that option.
    desc.add_options()
        ("start", opt::value<std::string>(), "Create a file with a specific name")
        ("help", "Produce help message");

    // Variable to store our command line arguments.
    opt::variables_map vm;

    // Parsing and storing arguments.
    opt::store(opt::parse_command_line(argc, argv, desc), vm);

    // Must be called after all the parsing and storing.
    opt::notify(vm);

    // help - returns description of options
    if (vm.count("help")) {
        std::cout << desc << "\n";
        return 1;
    }

    // start - creates a text file
    if (vm.count("start")){
    	std::cout << "Creating file ...";
    	try {
			std::string fileName = vm["start"].as<std::string>() + ".txt";
			std::ofstream newFile (fileName);
			newFile << "\nThis is some text...";
			newFile.close();
			std::cout <<"\n... Success!\n";
    	}
		catch (...){
			std::cout << "\nError creating file! :(\n";
		}
    }

    else
    {
    	std::cout << "Use note_app --help to view options"<< std::endl;
    }
    return 0;
} // end of `main`
