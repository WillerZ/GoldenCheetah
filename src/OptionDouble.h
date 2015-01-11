// Created by Philip Willoughby 2015-01-11

#include <QtCore>

class OptionDouble;
std::ostream& operator<< (std::ostream&, const OptionDouble&);
QTextStream& operator<< (QTextStream&, const OptionDouble&);

class OptionDouble {
private:
    double _value;
    bool _some;
public:
    OptionDouble (double const& value);
    OptionDouble();
    double value() const;
    double valueOr(double) const;
    bool some() const;
    bool none() const;
    
    OptionDouble max(const OptionDouble&, const OptionDouble&);
    OptionDouble min(const OptionDouble&, const OptionDouble&);

    operator const double*() const { return _some ? &_value : NULL; }
    operator double() const { return value(); }
    bool operator <(const OptionDouble& other) const;
    bool operator <=(const OptionDouble& other) const;
    bool operator ==(const OptionDouble& other) const;
    bool operator >(const OptionDouble& other) const;
    bool operator >=(const OptionDouble& other) const;

    OptionDouble operator -(const OptionDouble& other) const;
    void operator -=(const OptionDouble& other);
    OptionDouble operator +(const OptionDouble& other) const;
    void operator +=(const OptionDouble& other);
    OptionDouble operator *(const OptionDouble& other) const;
    void operator *=(const OptionDouble& other);
    OptionDouble operator /(const OptionDouble& other) const;
    void operator /=(const OptionDouble& other);
    
    friend std::ostream& operator<< (std::ostream&, const OptionDouble&);
    friend QTextStream& operator<< (QTextStream&, const OptionDouble&);

#define declOps(numericType) \
    bool operator <(const numericType other) const; \
    bool operator <=(const numericType other) const; \
    bool operator ==(const numericType other) const; \
    bool operator >(const numericType other) const; \
    bool operator >=(const numericType other) const; \
    OptionDouble operator -(const numericType other) const; \
    void operator -=(const numericType other); \
    OptionDouble operator +(const numericType other) const; \
    void operator +=(const numericType other); \
    OptionDouble operator *(const numericType other) const; \
    void operator *=(const numericType other); \
    OptionDouble operator /(const numericType other) const; \
    void operator /=(const numericType other);
    
    declOps(double)
    declOps(float)
    declOps(char)
    declOps(short)
    declOps(int)
    declOps(long)
    declOps(long long)
    declOps(unsigned char)
    declOps(unsigned short)
    declOps(unsigned int)
    declOps(unsigned long)
    declOps(unsigned long long)

#undef declOps
    
};
