#include <iostream>
#include "Time.h"

Time::Time(int seconds){
    _seconds = seconds;
}

Time Time::operator+( const Time & rhs) const{
    return Time(_seconds + rhs._seconds);
}

Time Time::operator-( const Time & rhs) const{
    return Time(_seconds - rhs._seconds);
}

Time Time::operator*( int scalar ) const{
    return Time(_seconds * scalar);
}

Time::operator int() const {
    return _seconds;
}

void Time::Set(int seconds){
    _seconds = seconds;
}

std::istream& operator>>(std::istream& in, Time& t) {
    int hours, minutes, seconds;
    char separator1, separator2, separator3;

    // Oczekujemy formatu: 10h:12m:01s
    if (in >> hours >> separator1 >> minutes >> separator2 >> seconds >> separator3
        && separator1 == 'h' && separator2 == 'm' && separator3 == 's') {
        t.Set(hours * 3600 + minutes * 60 + seconds);
    } else {
        // Jeżeli format jest niepoprawny, ustawiamy domyślne 0
        t.Set(0);
    }

    return in;
}

std::string Time::ToString() const {
    int hours = _seconds / 3600;
    int minutes = (_seconds % 3600) / 60;
    int seconds = _seconds % 60;

    std::string str = std::to_string(hours) + "h:" + std::to_string(minutes) + "m:" + std::to_string(seconds) + "s";
    return str;
}

std::ostream& operator<<(std::ostream& out, const Time& rhs) {
    out << rhs.ToString();
    return out;
}
