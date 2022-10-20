#include <ostream>

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
    Vector(std::initializer_list<int> v);
    // possibly more

// Public Member functions here
    void setValues(int* v);
    int getValue(int i);
    Vector operator+(const Vector& rhs);
    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(int n);
    Vector& operator-=(const Vector& rhs);
    int operator*(const Vector& rhs);
    Vector operator*(int k);
    Vector& operator*=(int k);
    value& operator[](int i);
    value operator[](int i) const;
    // More to go

private:
    // Private Member functions here
    int v_[NDIM];

    // Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& out, Vector v);
