#pragma once
#include <iostream>
#include "DynamicArrSequence.h"
#include "Isorters.h"
template <typename T>
class  QuickSort :public Isorted<T> {
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	int PartitionHoare(DynamicArrSequence<T>& arr, int low, int high, bool(*&F)(T&, T&)) {
		T pivot = arr[(low + high) / 2];
		int i = low;
		int j = high; 
		while (true) {
			while ( (*F)(arr[i] , pivot) ) {
				i++;
			}
			while ((*F)(pivot, arr[j])) { 
				j--;
			}
			if (i >= j) {
				return j;
			}
			swap(arr[i++], arr[j--]);
		}
	}

	void QuickSortH(DynamicArrSequence<T>& arr, int low, int high, bool(*&F)(T&, T&)) {
		if (low >= high) {
			return;
		}
		int mid = PartitionHoare(arr, low, high, F);
		QuickSortH(arr, low, mid,F);
		QuickSortH(arr, mid + 1, high,F);
	}
public:
	void Sort(DynamicArrSequence<T>& arr, bool(*&F)(T&, T&)) {
		QuickSortH(arr, 0, arr.get_colElm() - 1,F);
	}
};
