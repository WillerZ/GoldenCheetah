// Created by Philip Willoughby 2015-01-11

#include "OptionDouble.h"
#include <stdexcept>

std::ostream& operator<< (std::ostream& out, const OptionDouble& od) {
    if (od.some())
        return out << od.value();
    else
        return out;
}
QTextStream& operator<< (QTextStream& out, const OptionDouble& od) {
    if (od.some())
        return out << od.value();
    else
        return out;
}

bool OptionDouble::operator<(const OptionDouble& other) const {
    if (_some && other._some)
        return _value < other._value;
    return false;
}
bool OptionDouble::operator<=(const OptionDouble& other) const {
    if (_some && other._some)
        return _value <= other._value;
    return false;
}
bool OptionDouble::operator==(const OptionDouble& other) const {
    if (_some && other._some)
        return _value == other._value;
    return _some == other._some;
}
bool OptionDouble::operator>(const OptionDouble& other) const {
    return other < *this;
}
bool OptionDouble::operator>=(const OptionDouble& other) const {
    return other <= *this;
}
OptionDouble OptionDouble::operator-(const OptionDouble& other) const {
    if (_some && other._some)
        return OptionDouble(_value - other._value);
    if (_some)
        return OptionDouble(_value);
    return OptionDouble();
}
void OptionDouble::operator-=(const OptionDouble& other) {
    if (_some && other._some)
        _value -= other._value;
}
OptionDouble OptionDouble::operator+(const OptionDouble& other) const {
    if (_some && other._some)
        return OptionDouble(_value + other._value);
    if (_some)
        return OptionDouble(_value);
    return OptionDouble();
}
void OptionDouble::operator+=(const OptionDouble& other) {
    if (_some && other._some)
        _value += other._value;
}
OptionDouble OptionDouble::operator/(const OptionDouble& other) const {
    if (_some && other._some)
        return OptionDouble(_value / other._value);
    if (_some)
        return OptionDouble(_value);
    return OptionDouble();
}
void OptionDouble::operator/=(const OptionDouble& other) {
    if (_some && other._some)
        _value /= other._value;
}
OptionDouble OptionDouble::operator*(const OptionDouble& other) const {
    if (_some && other._some)
        return OptionDouble(_value * other._value);
    if (_some)
        return OptionDouble(_value);
    return OptionDouble();
}
void OptionDouble::operator*=(const OptionDouble& other) {
    if (_some && other._some)
        _value *= other._value;
}

OptionDouble OptionDouble::max(const OptionDouble& one, const OptionDouble& two) {
    if (one._some && two._some)
        return OptionDouble(max(one._value,two._value));
    if (one._some)
        return one;
    return two;
}
OptionDouble OptionDouble::min(const OptionDouble& one, const OptionDouble& two) {
    if (one._some && two._some)
        return OptionDouble(min(one._value,two._value));
    if (one._some)
        return one;
    return two;
}

#define implementCmp(numericType,theOperator) \
bool OptionDouble::operator theOperator(const numericType other) const { \
    if (_some) \
        return _value theOperator other; \
    return false; \
}

#define implementOp(numericType,theOperator) \
OptionDouble OptionDouble::operator theOperator(const numericType other) const { \
    if (_some) \
        return OptionDouble(_value theOperator other); \
    return OptionDouble(); \
}

#define implementMut(numericType,theOperator) \
void OptionDouble::operator theOperator(const numericType other) { \
    if (_some) \
        _value theOperator other; \
}

#define implementOps(numericType) \
implementCmp(numericType,<) \
implementCmp(numericType,<=) \
implementCmp(numericType,>) \
implementCmp(numericType,>=) \
implementCmp(numericType,==) \
implementOp(numericType,-) \
implementOp(numericType,+) \
implementOp(numericType,*) \
implementOp(numericType,/) \
implementMut(numericType,-=) \
implementMut(numericType,+=) \
implementMut(numericType,*=) \
implementMut(numericType,/=)

implementOps(double)
implementOps(float)
implementOps(char)
implementOps(short)
implementOps(int)
implementOps(long)
implementOps(long long)
implementOps(unsigned char)
implementOps(unsigned short)
implementOps(unsigned int)
implementOps(unsigned long)
implementOps(unsigned long long)

OptionDouble::OptionDouble (double const& value) {
    _value = value;
    _some = true;
}
OptionDouble::OptionDouble() {
    _some = false;
}
double OptionDouble::value() const {
    if (!_some)
        throw std::out_of_range("OptionDouble::value(): None");
    return _value;
}
double OptionDouble::valueOr(double alternative) const {
    if (!_some)
        return alternative;
    return _value;
}
bool OptionDouble::some() const {
    return _some;
}
bool OptionDouble::none() const {
    return !_some;
}
