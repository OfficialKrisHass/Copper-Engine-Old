//Copyright(C) 2022 Chris Husky <chrishuskywolf@gmail.com>
//
//This file is part of the Copper Engine project.
//
//The Copper Engine project can not be copied and /or distributed without the express
//permission of Chris Husky <chrishuskywolf@gmail.com>.

//Source File for the File Utilities we might need.

#include "cupch.h"
#include "FileUtils.h"

#include <sstream>
#include <fstream>

namespace Copper {

	//Read File
	std::string ReadFile(const char* path) {

		//create our variables
		std::string ret;
		std::ifstream file;

		//Set the exceptions
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		//Try to read the file
		try {

			//Open the file
			file.open(path);

			//Create a string Stream and then read the file into this string stream
			std::stringstream stream;

			stream << file.rdbuf();
			file.close(); //Close the File so that we don't get any leaks

			//Get the String Stream data into our return string
			ret = stream.str();

		}
		catch (std::ifstream::failure e) {

			//Error with reading the file
			LogError("File not successfully read! path: {0}", path);

		}

		//return what we've read from the file
		return ret;

	}

}