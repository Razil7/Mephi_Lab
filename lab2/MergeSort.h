#pragma once
#include <iostream>
#include "DynamicArrSequence.h"
#include "Isorters.h"


template <typename T>
class MergeSort :public Isorted<T> {
	void merge(DynamicArrSequence<T>& arr, int start, int finish, bool(*&F)(T&, T&)) {
		if (finish - start < 1) {
			return;
		}
		int mid = start + (finish - start) / 2;

		merge(arr, start, mid, F);
		merge(arr, mid + 1, finish, F);

		int first = start;
		int second = mid + 1;
		T* arr2 = new T[finish - start + 1];
		int a = 0;

		while (first <= mid and second <= finish) {

			if ( (*F)( arr[second],arr[first] ) ) {
				arr2[a] = arr[second];
				a++;
				second++;
			}
			else {
				arr2[a] = arr[first];
				first++;
				a++;
			}
		}
		while (first <= mid) {
			arr2[a] = arr[first];
			a++;
			first++;
		}
		while (second <= finish) {
			arr2[a] = arr[second];
			a++;
			second++;
		}

		for (int i = 0; i < finish - start + 1; i++) {
			arr[start + i] = arr2[i];
		}
		delete[] arr2;
	}
public:
	void Sort(DynamicArrSequence<T>& arr, bool(*&F)(T&, T&)) override
	{
		merge(arr, 0, arr.get_colElm() - 1, F);
	}
};


