#include "average.hpp"

ifstream average::add_file(string& filename) {
	
	ifstream fin(filename, ifstream::in);
	
	try {
		if (!fin.good())
			throw fin.rdstate();
	}
	catch(ifstream::iostate r) {
		if (r == ifstream::badbit)
			cout <<	"Read/writng error on i/o operation, ";
		if (r == ifstream::failbit)
			cout << "Logical error on i/o operation, ";
		if (r == ifstream::eofbit)
			cout <<	"End-of-file reached on input, ";
		cout << "can't open file \"" <<
			filename << "\"" << endl;
		fin.close();
		throw r;
	}
	
	return fin;	
}

void average::count_from_file(ifstream& fin) {

	++all_files;
	string str;
	vector<string> vec;

	while (getline(fin, str)) {
		boost::split(vec, str,
					 boost::is_any_of("/?!:;., \t"),
					 boost::token_compress_on);
		all_words += count(vec.begin(), vec.end(), word);
	}
}

void average::operator()(string& filename) {

	ifstream fin;
	try {
		fin = add_file(filename);
	}
	catch(ifstream::iostate& r) {
		return;
	}

	count_from_file(fin);
	fin.close();
}

float average::get_average() {

	if (!all_files) {
		cout << "No input data" << endl;
		return all_files;
	}
	
	return ((float)all_words / all_files);

}

void average::clear() {

	all_words = 0;
	all_files = 0;
}
