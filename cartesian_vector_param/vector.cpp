#include "vector.hh"
#include <initializer_list>

Vector::Vector(std::initializer_list<int> v){
	const int* tab = std::data(v);
	for (int i = 0; i < NDIM; i++) {
		v_[i] = tab[i];
	}
}

Vector::Vector(){
	for (int i = 0; i < NDIM; i++) {
		v_[i] = 0;
	}
}

void Vector::setValues(value* v) {
	for (int i = 0; i < NDIM; i++) {
		v_[i] = v[i];
	}
}

value Vector::getValue(int i) {
	return this->v_[i];
}

Vector Vector::operator+(const Vector& rhs){
	Vector v = Vector{};
	value tab[NDIM];
	for (int i = 0; i < NDIM; i++) {
		tab[i] = rhs.v_[i] + this->v_[i];
	}
	v.setValues(tab);
	return v;
}

Vector& Vector::operator+=(const Vector& rhs) {
	value tab[NDIM];
	for (int i = 0; i < NDIM; i++) {
		tab[i] = rhs.v_[i] + this->v_[i];
	}
	this->setValues(tab);
	return *this;
}

Vector& Vector::operator+=(value n) {
	value tab[NDIM];
	for (int i = 0; i < NDIM; i++) {
		tab[i] = n + this->v_[i];
	}
	this->setValues(tab);
	return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
	value tab[NDIM];
	for (int i = 0; i < NDIM; i++) {
		tab[i] = this->v_[i] - rhs.v_[i];
	}
	this->setValues(tab);
	return *this;
}

value Vector::operator*(const Vector& rhs) {
	value res = 0;
	for (int i = 0; i < NDIM; i++) {
		res += this->v_[i] * rhs.v_[i];
	}
	return res;
}

Vector Vector::operator*(value k) {
	Vector v = Vector{};
	value tab[NDIM];
	for (int i = 0; i < NDIM; i++) {
		tab[i] = this->v_[i] * k;
	}
	v.setValues(tab);
	return v;
}

Vector& Vector::operator*=(value k) {
	value tab[NDIM];
	for (int i = 0; i < NDIM; i++) {
		tab[i] = this->v_[i] * k;
	}
	this->setValues(tab);
	return *this;
}

value& Vector::operator[](value i) {
	value& a = this->v_[i];
	return a;
}

std::ostream& operator<<(std::ostream& out, Vector v)
{
	out << "{";
	for (int i = 0; i < NDIM - 1; i++) {
		out << v.getValue(i) << ", ";
	}
	out << v.getValue(NDIM - 1) << "}";
	return out;
}
