# ifndef _DATE_H_
# define _DATE_H_

class Date {
private:
    int year;
    int month;
    int day;
    int commonYearMonthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leapYearMonthDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

public:
    Date (int y=0, int m=1, int d=1);
    void set(const int yearNum, const int monthNum, const int dayNum);
    void getYear() const;
    void getMonth() const;
    void getDay() const;
    void showDate() const;
    int getDays() const;
    friend void decrement(Date& date, const int days);
    friend void increment(Date& date, const int days);
    friend bool after(const Date& date1, const Date& date2);

private:
    bool isValidData(const int yearNum, const int monthNum, const int dayNum) const;
    bool isLeapYear(const int yearNum) const;
};

# endif