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

int main()
{
    date today(64,6,2024);
    cout << "Today is " << today.getDay() << endl;
    today.showDate();
    return 0;
}
