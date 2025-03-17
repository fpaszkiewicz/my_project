#include <iostream>
#include <vector>
#include <numeric>

class Student{
    std::vector<float> grades;
    std::string _name;
    std::string _surname;
    std::string _index;
public:

    Student(std::string name, std::string surname, std::string index){
        if(index.length() != 5 || index.length() != 6){
            _index = index;
        }
        else{
            _index = "000000";
            std::cout << "wrong index format" << std::endl;
        }
        _name = name;
        _surname = surname;
    }
    Student(){
        _index = "000000";
        _name = "name";
        _surname = "surname";
    }
    ~ Student(){
        std::cout << "See you" << std::endl;
    }

    float calculate_grade(){
        float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
        return sum / grades.size();
    }

    bool add_grade(float grade){
        if(grade >= 2 && grade <= 5){
            grades.emplace_back(grade);
            return true;
        }
        return false;
    }

    void set_index(std::string index){
        if(index.length() != 5 || index.length() != 6){
            _index = index;
        }
        else{
            std::cout << "wrong index format" << std::endl;
        }
    }

    std::string get_index(){
        return _index;
    }

    void set_name(std::string name, std::string surname){
        _name = name;
        _surname = surname;
    }

    std::string get_name(){
        return _name + " " + _surname;
    }

    bool passed(){
        int two = 0;
        for(int i = 0; i < grades.size(); i++){
            if(grades[i] == 2){
                two++;
                if(two > 1) return false;
            }
        }
        return true;
    }

    void display_student(){
        std::cout << "Students info: " + _name + " " + _surname + " " + _index << std::endl;
        std::string str = "";
        if(passed())
        {
            str = "Did pass with mean grade: " + std::to_string(calculate_grade());
        }
        else{
            str = "Did not pass";
        }
        std::cout << str << std::endl;
        std::cout << "Grades: " << std::endl;
        for(int i = 0; i < grades.size(); i++){
            std::cout << grades[i] << "; ";
        }
    }
};

class Complex{
    float _realPart, _imaginaryPart;
public:
    Complex(){
        _realPart = 0;
        _imaginaryPart = 0;
    }

    Complex(float real){
        _realPart = real;
        _imaginaryPart = 0;
    }

    Complex(float real, float im){
        _realPart = real;
        _imaginaryPart = im;
    }

    void set_real(float real){
        _realPart = real;
    }

    void set_im(float im){
        _imaginaryPart = im;
    }

    void print(){
        std::cout << _realPart << " " << _imaginaryPart << "i" << std::endl;
    }

    Complex add(Complex number){
        Complex summaryNumber(_realPart + number._realPart, _imaginaryPart + number._imaginaryPart);
        return summaryNumber;
    }
};



int main()
{
    // Student st{"Franek", "Paszkiewicz", "123456"};
    // st.add_grade(5);
    // st.add_grade(4);
    // st.add_grade(2);
    // //st.add_grade(2);
    // st.display_student();
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.set_im(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i
    return 0;
}
