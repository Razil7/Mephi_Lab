#pragma once
#include <functional>
template <typename T>
class Isorted {
public:
	virtual void Sort(MutableSequence<T>& arr, std::function<bool(const T&, const T&)> F) = 0;
};