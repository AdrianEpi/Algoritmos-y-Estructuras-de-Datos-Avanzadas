	
#include "BaseSortMethod.hpp"
#include "InsertionMethod.hpp"
#include "BubbleSortMethod.hpp"
#include "HeapSortMethod.hpp"
#include "QuickSortMethod.hpp"
#include "ShellSortMethod.hpp"
#include "DNI.hpp"
#include "ISBN.hpp"

#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cassert>
#include <chrono>
class Experiment {
	
	private: 
		BaseSortMethod<ISBN>* algorithm_;
		int tryNum_;
		int size_;
		std::vector<ISBN> bench_;
		int selector_;
		int algorithmSelector_;

	public:
		// Builder & Destoyer
		Experiment ();
		~Experiment ();

		// Getters & Setters
		BaseSortMethod<ISBN>* get_Algorithm (void) const;
		int get_TryNum (void) const;
		int get_Size (void) const;
		std::vector<ISBN> get_Bench (void) const;
		int get_Selector (void) const;
		int get_AlgorithmSelector (void) const;

		void set_Algorithm (BaseSortMethod<ISBN>* algorithm);
		void set_TryNum (int tryNum);
		void set_Size (int size);
		void set_Bench (std::vector<ISBN> bench);
		void set_Selector (int selector);
		void set_AlgorithmSelector (int algorithmSelector);

		// Functions
		void initialize (void);
		void generateISBN (void);
		void startExperiment (void);
		void testMode (void); 
		void statisticsMode (void);
};
