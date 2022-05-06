#include "cupch.h"
#include "FileUtils.h"

#include <sstream>
#include <fstream>

namespace Copper {

	std::string ReadFile(const char* path) {

		std::string ret;
		std::ifstream file;

		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try {

			file.open(path);

			std::stringstream stream;

			stream << file.rdbuf();
			file.close();

			ret = stream.str();

		}
		catch (std::ifstream::failure e) {

			LogError("File not successfully read! path: {0}", path);

		}

		return ret;

	}

}