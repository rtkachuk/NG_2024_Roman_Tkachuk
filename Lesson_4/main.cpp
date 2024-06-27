#include <iostream>

using namespace std;

class date {
public:
    date(int day, int month, int year) {
        setDay(day);
        setMonth(month);
        setYear(year);
    }

    date() {
        setDay(1);
        setMonth(1);
        setYear(1970);
    }

    void setDay(int day) {
        if (day > 0 && day < 32) {
            m_day = day;
        }
    }

    void setMonth(int month) {
        if (month > 0 && month < 13) {
            m_month = month;
        }
    }

    void setYear(int year) {
        if (year >= 1970) {
            m_year = year;
        }
    }

    void showWtihSlash() {
        cout << m_day << "/" << m_month << "/" << m_year;
    }

    void showWithDash() {
        cout << m_day << "-" << m_month << "-" << m_year;
    }

private:
    int m_day = -1;
    int m_month = -1;
    int m_year = -1;
};

class Parent
{
public:
    int m_public;
private:
    int m_private;
protected:
    int m_protected;
};

class PublicChild: public Parent
{
public:
    PublicChild()
    {
        m_public = 1;
        //m_private = 1;
        m_protected = 1;
    }
};

class PrivateChild: private Parent
{
public:
    PrivateChild() {
        m_public = 1; // private
        //m_private = 1;
        m_protected = 1; // private
    }
};

class ProtectedChild: protected Parent
{
public:
    ProtectedChild() {
        m_public = 1; // protected
        //m_private = 1;
        m_protected = 1; // protected
    }
};

class AbstractClass {
public:
    static void showMessage() {
        cout << "Hello world!";
    }
};

int main()
{
    //date today;
    //today.showWithDash();
    Parent parent;
    parent.m_public = 1;
    //parent.m_private = 1;
    //parent.m_protected = 1;

    PublicChild publicTest;
    publicTest.m_public = 1; // public!

    PrivateChild test;
    //test.m_public = 1; // public -> private!

    AbstractClass::showMessage();
    return 0;
}
