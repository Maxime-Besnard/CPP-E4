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
    Vector& operator+=(value n);
    Vector& operator-=(const Vector& rhs);
    value operator*(const Vector& rhs);
    Vector operator*(value k);
    Vector& operator*=(value k);
    value operator[](value i) const;
    value& operator[](value i);
    void setValues(value* v);
    value getValue(int i);

private:
    // Private Member functions here
    // Member variables are ALWAYS private, and they go here
    value v_[NDIM];
};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& out, Vector v);
