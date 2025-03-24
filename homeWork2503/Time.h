#ifndef TIME_H
#define TIME_H

#include <iostream>

class Time{
    int _seconds;
public:
    Time(int seconds = 0);
    void Set(int seconds);
    std::string ToString() const;
    Time operator+(const Time & rhs) const;
    Time operator-(const Time & rhs) const;
    Time operator*(int scalar) const;
    operator int() const;
    friend std::istream& operator>>(std::istream& in, Time& t);
    friend std::ostream& operator<<(std::ostream& out, const Time& rhs);

};

#endif // TIME_H
