#pragma once

#include <ostream>
#include <initializer_list>
#include "config.h"

class Vector
{
public:
    // DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
    //

    // Add suitable constructors
    Vector();
    Vector(std::initializer_list<int> values);
    // possibly more

// Public Member functions here
    Vector operator+(const Vector& rhs);
    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(int n);
    Vector& operator-=(const Vector& rhs);
    int operator*(const Vector& rhs);
    Vector operator*(int k);
    Vector& operator*=(int k);
    int& operator[](int i);
    void setValues(int* v);
    int getValue(int i);

private:
    // Private Member functions here
    // Member variables are ALWAYS private, and they go here
    int v_[NDIM];
};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& out, Vector v);