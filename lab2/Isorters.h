#pragma once
template <typename T>
class Isorted {
public:
	virtual void Sort(DynamicArrSequence<T>& arr, bool(*&F)(T&, T&)) = 0;
};