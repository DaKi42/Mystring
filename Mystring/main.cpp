#include <iostream>
#include "MyString.h"
using namespace std;

int Mystring::count = 0;

Mystring operator+(const Mystring& other, const int value) {
    Mystring result;
    result.set_length(other.my_strlen() + value);

    const char* str = other.get_string();
    char* new_str = new char[result.my_strlen() + 1];
    strcpy_s(new_str, result.my_strlen() + 1, str);

    for (int i = other.my_strlen(); i < result.my_strlen(); i++) {
        new_str[i] = ' ';
    }

    new_str[result.my_strlen()] = '\0';
    result.set_string(new_str);
    delete[] new_str;
    return result;
}

Mystring operator+(const int value, const Mystring& other) {
    Mystring result;
    const char* str = other.get_string();
    int new_length = other.my_strlen() + value;
    char* new_str = new char[new_length + 1];

    strcpy_s(new_str, new_length + 1, str);
    for (int i = other.my_strlen(); i < new_length; i++) {
        new_str[i] = 'a';
    }

    new_str[new_length] = '\0';
    result.set_string(new_str);
    result.set_length(new_length);
    delete[] new_str;
    return result;
}

Mystring& operator+=(Mystring& left, int value) {
    left.set_length(left.my_strlen() + value);
    return left;
}

Mystring& operator++(Mystring& other) {
    int old_length = other.my_strlen();
    char* old_str = other.get_string();
    other.set_length(other.my_strlen() + 10);
    int new_length = other.my_strlen();
    char* str = new char[new_length + 1];

    for (int i = 0; i < old_length; i++) {
        str[i] = old_str[i];
    }

    for (int i = old_length; i < new_length; i++) {
        str[i] = ' ';
    }
    str[new_length] = '\0';
    other.set_string(str);

    return other;
}

Mystring operator++(Mystring& other, int) {
    Mystring temp(other);
    int current_length = other.my_strlen();
    int new_length = current_length + 10;
    char* new_str = new char[new_length + 1];

    for (int i = 0; i < current_length; i++) {
        new_str[i] = other.get_string()[i];
    }

    for (int i = current_length; i < new_length; i++) {
        new_str[i] = ' ';
    }

    new_str[new_length] = '\0';

    delete[] other.get_string();

    other.set_string(new_str);
    other.set_length(new_length);

    return temp;
}

ostream& operator<<(ostream& os, const Mystring& other) {
    cout << "\n" << other.get_string() << endl;
    cout << "Length: " << other.my_strlen() << endl;
    return os;
}

istream& operator>>(istream& is, Mystring& other) {
    char* new_str = new char[255];
    int new_length;

    is >> new_str;
    other.set_string(new_str);

    is >> new_length;
    other.set_length(new_length);

    return is;
}


int main()
{
    Mystring str1;
    Mystring str2("ITSTEP University");
    Mystring str3("My name is Illia");

    cout << "str1: " << str1.get_string() << endl;
    cout << "str2: " << str2.get_string() << endl;

    str1.set_string("New String");
    cout << "str1 after set_string: " << str1.get_string() << endl;

    str1.my_strcat(str2);
    cout << "str1 after my_strcat: " << str1.get_string() << endl;

    str2.my_del_chr('l');
    cout << "str2 after my_del_chr: " << str2.get_string() << endl;

    str1 = str2;
    str1.display();

    str3 = str3 + 20;
    str3.display();

    Mystring str4{ 'A', 'L', 'O', 'H', 'A' };
    str4.display();

    system("pause");
}
