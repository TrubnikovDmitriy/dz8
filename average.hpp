#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

using namespace std;


class average {

	public:
		average(string& word_): word(word_),
								all_words(0.0f),
								all_files(0) {}
		average(char* word_): 	word(word_), 
								all_words(0.0f),
								all_files(0) {}

		void operator()(string& filename);
		float get_average();
		void clear();

	private:
		string word;
		float all_words;
		int all_files;

		void count_from_file(ifstream& fin);
		ifstream add_file(string& filename);
};
