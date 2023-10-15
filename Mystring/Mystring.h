#pragma once
#include <iostream>
using namespace std;

class Mystring {
    int length;
    char* str;
public:
    Mystring();
    Mystring(int size);
    Mystring(const char* a);
    Mystring(const Mystring& other);
    Mystring(Mystring&& other);
    ~Mystring();
    void set_length(int l);
    void set_string(const char* ns);
    char* get_string() const;
    void input();
    void display();
    Mystring& operator=(const Mystring& other);
    Mystring& operator=(Mystring&& other);
    char operator[](int index);
    void operator()();
    void my_strcpy(const Mystring& data);
    bool my_strstr(const char* str);
    int my_chr(char c);
    int my_strlen() const;
    void my_strcat(const Mystring& data);
    void my_del_chr(char c);
    int my_strcmp(const Mystring& data);
    Mystring(initializer_list<char> p);
    static int count;
};