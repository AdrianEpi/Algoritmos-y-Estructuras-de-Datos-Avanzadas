/*
* @Author: Adrián Epifanio
* @Date:   2020-04-21 17:35:17
* @Last Modified by:   Adrián Epifanio
* @Last Modified time: 2020-04-30 08:39:21
*/
#include "../include/experiment.hpp"


/**
 * @brief      Constructs a new instance.
 */
Experiment::Experiment () {
	algorithm_ = NULL;
	set_TryNum(1);
	set_Size(0);
	initialize();
}

/**
 * @brief      Destroys the object.
 */
Experiment::~Experiment () {
	/*if (algorithm_ != NULL) {
		delete algorithm_;
	}
	if (bench_ != NULL) {
		for (int i = 0; i < get_TryNum(); i++) {
			if (bench_[i] != NULL) {
				delete bench_[i];
			}
		}
		delete bench_;
	}*/
}

/**
 * @brief      Gets the algorithm.
 *
 * @return     The algorithm.
 */
BaseSortMethod<ISBN>* Experiment::get_Algorithm (void) const {
	return algorithm_; 
}

/**
 * @brief      Gets the try number.
 *
 * @return     The try number.
 */
int Experiment::get_TryNum (void) const {
	return tryNum_; 
}

/**
 * @brief      Gets the size.
 *
 * @return     The size.
 */
int Experiment::get_Size (void) const {
	return size_; 
}

/**
 * @brief      Gets the bench.
 *
 * @return     The bench.
 */
std::vector<ISBN> Experiment::get_Bench (void) const {
	return bench_; 
}

/**
 * @brief      Gets the selector.
 *
 * @return     The selector.
 */
int Experiment::get_Selector (void) const {
	return selector_; 
}

/**
 * @brief      Gets the algorithm selector.
 *
 * @return     The algorithm selector.
 */
int Experiment::get_AlgorithmSelector (void) const {
	return algorithmSelector_;
}

/**
 * @brief      Sets the algorithm.
 *
 * @param      algorithm  The algorithm
 */
void Experiment::set_Algorithm (BaseSortMethod<ISBN>* algorithm) {
	algorithm_ = algorithm;
}

/**
 * @brief      Sets the try number.
 *
 * @param[in]  tryNum  The try number
 *
 */
void Experiment::set_TryNum (int tryNum) {
	tryNum_ = tryNum;
}

/**
 * @brief      Sets the size.
 *
 * @param[in]  size  The size
 */
void Experiment::set_Size (int size) {
	size_ = size;
}

/**
 * @brief      Sets the bench.
 *
 * @param      bench  The bench
 */
void Experiment::set_Bench (std::vector<ISBN> bench) {
	//bench_ = bench;
}

/**
 * @brief      Sets the selector.
 *
 * @param[in]  selector  The selector
 */
void Experiment::set_Selector (int selector) {
	selector_ = selector;
}

/**
 * @brief      Sets the algorithm selector.
 *
 * @param[in]  algorithmSelector  The algorithm selector
 */
void Experiment::set_AlgorithmSelector (int algorithmSelector) {
	algorithmSelector_ = algorithmSelector;
}

void Experiment::initialize (void) {
	//system("clear");
	std::cout << "\tChoose the program mode:";
	std::cout << std::endl << "\t\t1. Testing Mode";
	std::cout << std::endl << "\t\t2. Statistics Mode" << std::endl;
	std::cin >> selector_;
	assert(selector_ == 1 || selector_ == 2);
	//system("clear");
	std::cout << "\tIntroduce the size of the secuence: ";
	std::cin >> size_;
	assert(size_ >= 1);
	if (get_Selector() == 1) {
		assert(size_ <= 25);
		//system("clear");
		std::cout << std::endl << "\tChoose the sort method:";
		std::cout << std::endl << "\t\t1. Insertion";
		std::cout << std::endl << "\t\t2. BubbleSort";
		std::cout << std::endl << "\t\t3. HeapSort";
		std::cout << std::endl << "\t\t4. QuickSort";
		std::cout << std::endl << "\t\t5. ShellSort";
		std::cin >> algorithmSelector_;
	}
	else {
		//system("clear");
		std::cout << std::endl << "\tIntroduce the number of tests: ";
		std::cin >> tryNum_;
	}
	//system("clear");
	generateISBN();
}

/**
 * @brief      Generates a random ISBN
 */
void Experiment::generateISBN (void) {
	bench_.resize(0);
	for (int i = 0; i < get_Size(); i++) {
		ISBN newISBN((rand() % 5000000000) + 30000000);
		bench_.push_back(newISBN);
	}
}

/**
 * @brief      Starts an experiment.
 */
void Experiment::startExperiment (void) {
	if (get_Selector() == 1) {
		testMode();
	}
	else {
		statisticsMode();
	}
}

void Experiment::testMode (void) {
	switch (get_AlgorithmSelector()) {
		case 1:
			algorithm_ = new InsertionMethod<ISBN>();
			break;

		case 2:
			algorithm_ = new BubbleSortMethod<ISBN>();
			break;

		case 3:
			algorithm_ = new HeapSortMethod<ISBN>();
			break;

		case 4:
			algorithm_ = new QuickSortMethod<ISBN>();
			break;

		case 5:
			algorithm_ = new ShellSortMethod<ISBN>();
			break;

		case 0:
			std::cout << std::endl << "Aborting program . . ." << std::endl;
			exit(0);
			break;

		default:
			std::cout << std::endl << "ERROR, invalid option" << std::endl;
			exit(0);
			break;
	}
	for (int i = 0; i < get_Size(); i++) {
		std::cout << bench_[i] << " ";
	}
	std::cout << std::endl;
	
	algorithm_->sort(bench_, get_Size());
	
	for (int i = 0; i < get_Size(); i++) {
		std::cout << bench_[i] << " ";
	}
	std::cout << std::endl;
}

void Experiment::statisticsMode (void) {
	std::cout << std::endl << "\t\tComparations Number";
	std::cout << std::endl << "\t\t\t Minimum\tMedium\t\tMaximum" << std::endl;
	algorithm_ = new InsertionMethod<ISBN>;
	algorithm_ -> set_StatisticMode(true);
	//algorithm_ -> get_Counter().reset();
	for (int i = 0; i < get_TryNum(); i++) {
		algorithm_ -> get_Counter().start();
		generateISBN();
		algorithm_ -> sort(bench_, get_Size());
		algorithm_ -> stopCounter();
	}
	algorithm_ -> write(std::cout, "Insertion: ", get_TryNum());
	delete algorithm_;

	algorithm_ = new BubbleSortMethod<ISBN>;
	algorithm_ -> set_StatisticMode(true);
	for(int i = 0; i < get_TryNum(); i++) {
		algorithm_ -> get_Counter().start();
		generateISBN();
		algorithm_ -> sort(bench_, get_Size());
		algorithm_ -> stopCounter();
	}
	algorithm_ -> write(std::cout, "BubbleSort: ", get_TryNum());
	delete algorithm_;

	algorithm_ = new HeapSortMethod<ISBN>;
	algorithm_ -> set_StatisticMode(true);
	for(int i = 0; i < get_TryNum(); i++) {
		algorithm_ -> get_Counter().start();
		generateISBN();
		algorithm_ -> sort(bench_, get_Size());
		algorithm_ -> stopCounter();
	}
	algorithm_ -> write(std::cout, "HeapSort:", get_TryNum());
	delete algorithm_;

	algorithm_ = new QuickSortMethod<ISBN>;
	algorithm_ -> set_StatisticMode(true);
	for(int i = 0; i < get_TryNum(); i++) {
		algorithm_ -> get_Counter().start();
		generateISBN();
		algorithm_ -> sort(bench_, get_Size());
		algorithm_ -> stopCounter();
	}
	algorithm_ -> write(std::cout, "QuickSort:", get_TryNum());
	delete algorithm_;

	algorithm_ = new ShellSortMethod<ISBN>;
	algorithm_ -> set_StatisticMode(true);
	for(int i = 0; i < get_TryNum(); i++) {
		algorithm_ -> get_Counter().start();
		generateISBN();
		algorithm_ -> sort(bench_, get_Size());
		algorithm_ -> stopCounter();
	}
	algorithm_ -> write(std::cout, "ShellSort", get_TryNum());
	delete algorithm_;
	std::cout << std::endl;
}
