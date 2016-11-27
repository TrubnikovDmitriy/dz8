#include "average.hpp"

int main(int argc, char* argv[]) {

	if (argc < 3) {
		cout << "Not enouth input files" << endl;
		return EXIT_FAILURE;
	}

	average av(argv[1]);
	vector<string> filenames(argv + 2, argv + argc);
	for_each(filenames.begin(), filenames.end(), av);

//	for (auto& i : filenames) av(i);
	
	cout << "Avearage: " << av.get_average() << endl;
	return EXIT_SUCCESS;
}
