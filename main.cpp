#include "average.hpp"

int main(int argc, char* argv[]) {

	if (argc < 3) {
		cout << "Not enouth input files" << endl;
		return EXIT_FAILURE;
	}

	average av(argv[1]);
	vector<string> filenames;
	for (int i = 2; i < argc; ++i)
		filenames.push_back(argv[i]);

	for (auto& i : filenames) av(i);
	
	cout << "Avearage: " << av.get_average() << endl;
	return EXIT_SUCCESS;
}
