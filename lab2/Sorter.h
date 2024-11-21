#pragma once
#include "Isorters.h"
#include "QuickSort.h"
#include "MergeSort.h"
template <typename T>
class Sorter {
	Isorted<T>* sorter;
	bool(*comporator)(T&, T&);
	static bool sravn(T& a, T& b) {
		return a < b;
	};
public:
	Sorter(): sorter(nullptr), comporator(nullptr){}
	enum class sorts{ MergeSort, QuickSort };
	void init(sorts sort, bool(*F)(T&, T&) ) {
		comporator = F;
		if (sort == sorts::MergeSort) {
			sorter = new MergeSort<T>;
		}
		if (sort == sorts::QuickSort) {
			sorter = new QuickSort<T>;
		}
	}
	void init(sorts sort) {
		if (sort == sorts::MergeSort) {
			sorter = new MergeSort<T>;
		}
		if (sort == sorts::QuickSort) {
			sorter = new QuickSort<T>;
		}
	}

	void sort(DynamicArrSequence<T>& arr) {
		if(!sorter)  sorter = new QuickSort<T>;
		if (!comporator) comporator = &sravn;
		sorter->Sort(arr,comporator);
	}
};