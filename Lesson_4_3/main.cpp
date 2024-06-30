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

    void setDay(int newDay) {
        if (newDay > 0 && newDay < 32)
            m_day = newDay;
        else
            m_day = 1;
    }

    int getDay() { return m_day; }

    void setMonth(int newMonth) {
        if (newMonth > 0 && newMonth < 13)
            m_month = newMonth;
        else
            m_month = 1;
    }

    int getMonth() { return m_month; }

    void setYear(int newYear) {
        if (newYear > 1970 && newYear < 9000)
            m_year = newYear;
        else
            m_year = 1970;
    }

    int getYear() { return m_year; }

    void showDate() {
        cout << m_day << "/" << m_month << "/" << m_year << endl;
    }

private:
    int m_day;
    int m_month;
    int m_year;
};

class Parent {
public:
    int m_public = 1;
protected:
    int m_protected = 1;
private:
    int m_private = 1;
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
    date today(64,6,2024);
    cout << "Today is " << today.getDay() << endl;
    today.showDate();

    PublicChild test1;
    test1.m_public = 1;
    //test1.m_protected = 1;
    //test1.m_private = 1;

    PrivateChild test2;
    //test2.m_public = 1;
    //test2.m_protected = 1;
    //test2.m_private = 1;

    ProtectedChild test3;
    //test3.m_public = 1;
    //test3.m_protected = 1;
    //test3.m_private = 1;
    return 0;
}
