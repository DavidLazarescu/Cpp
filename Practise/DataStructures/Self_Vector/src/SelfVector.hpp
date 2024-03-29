// Notes:
// Intentionally implemented with raw pointers for practise purposes

#pragma once

#include <array>
#include <initializer_list>
#include <string>
#include <functional>
#include <algorithm>


template<class T>
class Self_Vector final
{
private:
	std::size_t m_size{};
	std::size_t m_capacity{};
	T* m_array{};

	bool search(T* arr, std::size_t first, std::size_t last, T element) const;

public:
	// Constructors
	Self_Vector() = default;
	Self_Vector(const std::initializer_list<T> list);
	explicit Self_Vector(const std::size_t cap);

	Self_Vector(const Self_Vector& toCopy);
	Self_Vector(Self_Vector&& toCopy) noexcept;


	// Destructor
	~Self_Vector();



	// Member-Functions
	void pushback(const T& elem);
	bool contains(const T& elem) const;
	void popback();
	void clear();
	void removeAt(std::size_t index);
	void sort(bool (*func)(const T& first, const T& second) = [](const T& a, const T& b) { return a < b; });
	void reverse();
	void insertAt(std::size_t index, const T& elem);
	void swap(std::size_t first, std::size_t second);


	T* begin() const;
	T* end() const;

	std::size_t size() const;
	std::size_t capacity() const;


		
	// Operator-Overloads
	T& operator[](std::size_t index);

	Self_Vector<T>& operator=(const Self_Vector<T>& toCopy);
	Self_Vector<T>& operator=(Self_Vector<T>&& toCopy) noexcept;
};


// Class definition
#include "SelfVector.txx"
