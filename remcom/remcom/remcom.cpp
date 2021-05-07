// REMCOM
// Jimmy James
// This program strips all comments from SAS Programs

#include "pch.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool is_ws(char);
static void show_usage(const string&);

int main(int argc, char** argv)
{
	string source, dest;

	if (argc < 5)
	{
		show_usage(argv[0]);
		return 1;
	}

	for (auto i = 1; i < argc; ++i)
	{
		string arg = argv[i];
		if ((arg == "-h") || (arg == "--help"))
		{
			show_usage(argv[0]);
			return 0;
		}
		if ((arg == "-i") || (arg == "--input"))
		{
			if (i + 1 < argc)
			{ // Make sure we aren't at the end of argv!
				source = argv[++i]; // Increment 'i' so we don't get the argument as the next argv[i].
			}
			else
			{ // Uh-oh, there was no argument to the destination option.
				std::cerr << "--input option requires one argument." << std::endl;
				return 1;
			}
		}

		if (arg == "-o" || (arg == "--output"))
		{
			if (i + 1 < argc)
			{
				dest = argv[++i];
			}
			else
			{
				cerr << "--output option requires one argument." << std::endl;
				return 1;
			}
		}
	}

	// File related stuff
	// Input file
	ifstream myfile(source);
	if (!myfile)
	{
		cerr << "\033[31mError file not found:\033[0m " << source;
		return 1;
	}

	// Output file
	ofstream out_file;
	out_file.open(dest);

	enum class state { init, star, intxt, ss };
	char c;
	auto st = state::init;


	while (myfile.get(c)) //!myfile.eof()
	{
		// init
		if (st == state::init)
		{
			if (is_ws(c) || c == ';')
			{
				out_file << c;
				continue;
			}

			if (c == '*')
			{
				st = state::star;
				continue;
			}

			if (c == '/')
			{
				if (myfile.peek() == '*')
				{
					myfile.get(c);
					st = state::ss;
					continue;
				}
				else
				{
					out_file << c;
					continue;
				}
			}

			// macro comment
			if (c == '%')
			{
				if (myfile.peek() == '*')
				{
					myfile.get(c);
					st = state::star;
					continue;
				}
				else
				{
					out_file << c;
					continue;
				}
			}

			if (!is_ws(c))
			{
				st = state::intxt;
				out_file << c;
				continue;
			}
		}

		// intxt
		if (st == state::intxt)
		{
			if (c == ';')
			{
				out_file << c;
				st = state::init;
				continue;
			}

			if (c != '/')
			{
				out_file << c;
				continue;
			}

			if (c == '/')
			{
				if (myfile.peek() == '*')
				{
					myfile.get(c);
					st = state::ss;
					continue;
				}
				else
				{
					out_file << c;
					continue;
				}
			}
		}

		// ss (Slash Star)
		if (st == state::ss)
		{
			if (c == '*')
			{
				if (myfile.peek() == '/')
				{
					myfile.get(c);
					st = state::intxt;
					continue;
				}
				else continue;
			}
			else continue;
		}

		// star
		if (st == state::star)
		{
			if (c == ';')
			{
				st = state::init;
				continue;
			}
		}
	}

	myfile.close();
	out_file.close();
	return 0;
}

bool is_ws(const char c) { return(c == ' ' || c == '\n' || c == '\t'); }

static void show_usage(const string& name)
{
	std::cerr << "\033[32m(c)2020 Data Centric Systems LLC\033[0m\n"
		<< "\033[35mComment Stripper for SAS Source Files\033[0m\n"
		<< "Usage: " << name << " -i file -o file\n"
		<< "Options:\n"
		<< "\t-h,--help\t\tShow this help message\n"
		<< "\t-i <input file>\t\tSpecify the input file\n"
		<< "\t-o <output file>\tSpecify the output file"
		<< endl;
}
