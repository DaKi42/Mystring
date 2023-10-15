#include "Mystring.h"
#include <iostream>
using namespace std;

Mystring::Mystring()
{
    length = 80;
    str = new char[length + 1];
    for (int i = 0; i < length; i++) 
    {
        str[i] = ' ';
    }
    str[length] = '\0';

    count++;
}

Mystring::Mystring(int size)
{
    length = size;
    str = new char[length + 1];
    for (int i = 0; i < length; i++) 
    {
        str[i] = ' ';
    }
    str[length] = '\0';

    count++;
}

Mystring::Mystring(const char* a)
{
    str = new char[strlen(a) + 1];
    strcpy_s(str, strlen(a) + 1, a);
    length = strlen(a);

    count++;
}

Mystring::Mystring(const Mystring& other)
{
    str = new char[other.length + 1];
    length = other.length + 1;

    for (int i = 0; i < length + 1; ++i)
    {
        str[i] = other.str[i];
    }
    str[length] = '\0';
}

Mystring::~Mystring()
{
    delete[] str;
}

void Mystring::set_length(int l)
{
    if (l >= 0) {
        length = l;
    }
}

void Mystring::set_string(const char* ns)
{
    if (str != nullptr) 
    {
        delete[] str;
    }
    length = strlen(ns);
    str = new char[length + 1];
    strcpy_s(str, length + 1, ns);
}

char* Mystring::get_string() const
{
    return str;
}

void Mystring::input()
{
    char buff[56];
    cout << "Enter anything: ";
    cin >> buff;

    delete[] str;

    str = new char[strlen(buff) + 1];
    strcpy_s(str, strlen(buff) + 1, buff);
    length = strlen(buff);

    count++;
}

void Mystring::display()
{
    cout << "\n" << str << endl;
    cout << "Length: " << this->length << endl;
}

Mystring::Mystring(Mystring&& other)
{
    length = other.length;
    other.length = 0;
    str = other.str;
    other.str = nullptr;
    cout << "Move constructor\n";
}

Mystring& Mystring::operator=(Mystring&& other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] str;

    length = other.length;
    other.length = 0;
    str = other.str;
    other.str = nullptr;
    cout << "MOVE = \n";
    return *this;
}

void Mystring::my_strcpy(const Mystring& data)
{
    if (str != nullptr)
    {
        delete[] str;
    }

    str = new char[data.length + 1];
    strcpy_s(str, strlen(data.str) + 1, data.str);

    count++;
}

bool Mystring::my_strstr(const char* new_str)
{
    int strLength = 0;

    while (new_str[strLength] != '\0')
    {
        strLength++;
    }

    if (length < strLength) 
    {
        return false;
    }

    for (int i = 0; i <= length - strLength; i++) 
    {
        int j;

        for (j = 0; j < strLength; ++j) {
            if (str[i + j] != new_str[j]) {
                break;
            }
        }

        count++;

        if (j == strLength) return true;
    }

    return false;
}

int Mystring::my_chr(char c)
{
    count++;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c) return i;
    }

    return -1;
}

int Mystring::my_strlen() const
{
    return length;
}

void Mystring::my_strcat(const Mystring& data)
{
    int newLength = length + data.length + 1;
    char* cuttedStr = new char[newLength];

    strcpy_s(cuttedStr, newLength, str);
    strcat_s(cuttedStr, newLength, data.str);

    delete[] str;
    str = cuttedStr;

    length = length + data.length;

    count++;
}

void Mystring::my_del_chr(char c)
{
    int newLength = 0;

    for (int i = 0; i < length; i++) 
    {
        if (str[i] != c) {
            str[newLength++] = str[i];
        }
    }

    str[newLength] = '\0';
    length = newLength;

    count++;
}

int Mystring::my_strcmp(const Mystring& data)
{
    int first = strlen(str);
    int second = strlen(data.str);

    if (first > second) 
    {
        return 1;
    }
    if (first < second) 
    {
        return -1;
    }
    else 
    {
        return 0;
    }
}

char Mystring::operator[](int index)
{
    if (index >= 0)
    {
        return str[index];
    }
    else {
        return '\0';
    }
}

void Mystring::operator()()
{
    char buff[255];

    cout << "Enter string: ";
    cin >> buff;

    str = new char[strlen(buff) - 1];
    strcpy_s(str, strlen(buff) - 1, buff);

    length = strlen(buff) - 1;

    count++;

}

Mystring& Mystring::operator=(const Mystring& other)
{
    if (this != &other)
    {
        delete[] str;

        str = new char[other.length + 1];
        length = other.length;

        for (int i = 0; i < length; ++i)
        {
            str[i] = other.str[i];
        }

        str[length] = '\0';
    }

    return *this;
}

Mystring::Mystring(initializer_list<char> p) {
    length = p.size();
    str = new char[length + 1];
    int i = 0;

    for (auto pt = p.begin(); pt != p.end(); pt++) {
        str[i++] = *pt;
    }

    str[length] = '\0';
}
