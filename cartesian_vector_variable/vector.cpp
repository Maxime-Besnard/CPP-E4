#include "vector.hh"
#include <initializer_list>

Vector::Vector(std::initializer_list<int> l){
	const int* tab = std::data(l);
	taille = l.size();
	v_ = std::make_unique<int[]>(taille);
	for (int i = 0; i < l.size(); i++) {
		v_[i] = tab[i];
	}
}

Vector::Vector(size_t N) {
	v_ = std::make_unique<int[]>(N);
	for (int i = 0; i < N; i++) {
		v_[i] = 0;
	}
	taille = N;
}

Vector::Vector(const Vector& v) {
	taille = v.taille;
	v_ = std::make_unique<int[]>(taille);
	for (int i = 0; i < taille; i++) {
		v_[i] = v[i];
	}
}

Vector& Vector::operator=(const Vector& v) {
	taille = v.taille;
	v_ = std::make_unique<int[]>(taille);
	for (int i = 0; i < taille; i++) {
		v_[i] = v[i];
	}

	return *this;
}

size_t Vector::size() const {
	return taille;
}

Vector& Vector::operator+=(const Vector& rhs) {
	if (rhs.taille != taille) {
		throw std::runtime_error("Incompatible size");
	}

	for (int i = 0; i < taille; i++) {
		v_[i] += rhs[i];
	}
}

Vector& Vector::operator+=(value v) {
	for (int i = 0; i < taille; i++) {
		v_[i] += v;
	}
	return *this;
}

Vector Vector::operator+(const Vector& rhs) const {
	if (rhs.taille != taille) {
		throw std::runtime_error("Incompatible size");
	}

	Vector v = Vector(rhs.taille);
	for (int i = 0; i < taille; i++) {
		v.v_[i] = rhs.v_[i] + v_[i];
	}
	return v;
}

Vector Vector::operator+(value v) const {
	Vector rhs = Vector(taille);
	rhs += v;
	return rhs;
}

Vector& Vector::operator-=(const Vector& rhs) {
	if (rhs.taille != taille) {
		throw std::runtime_error("Incompatible size");
	}

	for (int i = 0; i < taille; i++) {
		v_[i] -= rhs[i];
	}
}

Vector& Vector::operator*=(value v) {
	for (int i = 0; i < taille; i++) {
		v_[i] *= v;
	}
	return *this;
}

Vector operator+(const value& s, const Vector& v) {
	Vector rhs = Vector(v.size());
	rhs += v;
	return rhs;
}

value Vector::operator*(const Vector& rhs) const {
	if (rhs.taille != taille) {
		throw std::runtime_error("Incompatible size");
	}

	int result = 0;
	for (int i = 0; i < taille; i++) {
		result += v_[i] * rhs.v_[i];
	}
	return result;
}

Vector Vector::operator*(value v) const {
	Vector rhs = Vector(taille);
	rhs *= v;
	return rhs;
}

Vector operator*(const value& s, const Vector& v) {
	Vector rhs = Vector(v.size());
	rhs *= s;
	return rhs;
}

value& Vector::operator[](size_t idx) {
	return v_[idx];
}

value Vector::operator[](size_t idx) const {
	return v_[idx];
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
	o << "{";
	for (int i = 0; i < v.size()-1; i++) {
		o << v[i] << ", ";
	}

	o << v[v.size() - 1] << "}";
	return o;
}