#include <iostream>

using namespace std;

class date {
public:
    date() {
        m_day = 1;
        m_month = 1;
        m_year = 1970;
    }

    date(int day, int month, int year) {
        setDay(day);
        setMonth(month);
        setYear(year);
    }

    void setDay(int day) {
        if (day > 0 && day < 32)
            m_day = day;
        else
            m_day = 1;
    }
    void setMonth(int month) {
        if (month > 0 && month < 13)
            m_month = month;
        else
            m_month = 1;
    }
    void setYear(int year) {
        if (year > 1970 && year < 9000)
            m_year = year;
        else
            m_year = 1970;
    }

    void showDateSlash() {
        cout << m_day << "/" << m_month << "/" << m_year << endl;
    }
private:
    int m_day;
    int m_month;
    int m_year;
};

class Parent {
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

class PublicChild : public Parent {
public:
    PublicChild() {
        m_public = 1;
        m_protected = 1;
        //m_private = 1;
    }
};

class PrivateChild : private Parent {
public:
    PrivateChild() {
        m_public = 1;
        m_protected = 1;
        //m_private = 1;
    }
};

class ProtectedChild : protected Parent {
public:
    ProtectedChild() {
        m_public = 1;
        m_protected = 1;
        //m_private = 1;
    }
};

int main()
{
    date today(27,6,2024);
    today.showDateSlash();

    Parent test;
    test.m_public = 0;
    //test.m_protected = 0;
    //test.m_private = 0;

    PublicChild test2;
    test2.m_public = 0;
    //test2.m_protected = 0;
    //test2.m_private = 0;

    PrivateChild test3;
    //test3.m_public = 0;
    //test3.m_protected = 0;
    //test3.m_private = 0;

    ProtectedChild test4;
    //test4.m_public = 0;
    //test4.m_protected = 0;
    //test4.m_private = 0;


    return 0;
}
