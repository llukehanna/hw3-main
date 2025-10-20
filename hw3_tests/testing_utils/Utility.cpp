#include "Utility.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <fstream>
// trim from start
std::string &ltrim(std::string &s) 
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) 
{
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) 
{
    return ltrim(rtrim(s));
}

void RemoveWhiteSpace(std::string& s)
{
	size_t placement = 0;
	bool encounter = false;
	for (size_t reading = 0; reading < s.size(); ++reading)
	{
		if (!isspace(s[reading]))
		{
			s[placement] = s[reading];
			++placement;
		}
		else if (!encounter)
		{
			s[placement] = ' ';
			++placement;
		}
		encounter = isspace(s[reading]);
	}
	if (placement < s.size())
	{
		s.resize(placement);
	}
}

void RemoveEmptyLines(std::istream& is, std::ostream& os)
{
	std::string line;
	while (getline(is, line))
	{
		RemoveWhiteSpace(line);
		if (!line.empty())
		{
			os << line << "\n";
		}
	}
}

bool Approximately(double a, double b, double eps)
{
	return std::abs(a - b) <= eps;
}

std::string readFileContents(const char* filename)
{
  // https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
  std::ifstream ifile(filename);
  if(ifile.fail()){
    throw std::invalid_argument("Bad filename");
  }
  std::string str;
  
  ifile.seekg(0, std::ios::end);
  str.reserve(ifile.tellg());
  ifile.seekg(0, std::ios::beg);
  
  str.assign((std::istreambuf_iterator<char>(ifile)),
	     std::istreambuf_iterator<char>());
  ifile.close();
  return str;
}
