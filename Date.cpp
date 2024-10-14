# include "Date.h"
# include <iostream>
using namespace std;

// 验证输入的数据是否合法
bool Date::isValidData(const int yearNum, const int monthNum, const int dayNum) const{
    if(yearNum <= 0 || monthNum <= 0 || dayNum <= 0) {
        return false;
    } else if (monthNum == 2 && isLeapYear(yearNum) && dayNum < 30) {
        return true;
    } else if (monthNum == 2 && !isLeapYear(yearNum) && dayNum < 29) {
        return true;
    } else if ((monthNum == 4 || monthNum == 6 || monthNum == 9 || monthNum == 11) && dayNum < 31) {
        return true;
    } else if ((monthNum == 1 || monthNum == 3 || monthNum == 5 || monthNum == 7 || monthNum == 8 || monthNum == 10 || monthNum == 12) && dayNum < 32){
        return true;
    } else {
        return false;
    }
}

// 验证年份是否是闰年
bool Date::isLeapYear(const int yearNum) const {
    if (yearNum % 4 == 0 && yearNum % 100 != 0 || yearNum % 400 == 0)
        return true;
    else
        return false;
}

// 构造函数
Date:: Date(const int yearNum, const int monthNum, const int dayNum):year(yearNum), month(monthNum), day(dayNum) {
    if (!isValidData(yearNum, monthNum, dayNum)) {
        cout << "Invalid input!" << endl;
        exit(0);
        year = 1;
        month = 1;
        day = 1;
    }
}

// 设置日期
void Date::set(const int yearNum, const int monthNum, const int dayNum) {
    if (!isValidData(yearNum, monthNum, dayNum)) {
        cout << "Invalid input!" << endl;
        exit(0);
    } else {
        year = yearNum;
        month = monthNum;
        day = dayNum;
    }
}

// 获取年份
void Date::getYear() const {
    cout << year << endl;
}

// 获取月份
void Date::getMonth() const {
    cout << month << endl;
}

// 获取日期
void Date::getDay() const {
    cout << day << endl;
}

// 获取完整日期
void Date::showDate() const {
    cout << year << "-" << month << "-" << day << endl;
}

int Date :: getDays() const {
    int daysInYear = 0;
    if (!isLeapYear(year)) {
        for (int i = 1; i < month; i++) {
            daysInYear += commonYearMonthDays[i-1];
        }
        daysInYear += day;
        return daysInYear;
    } else {
        for (int i = 1; i < month; i++) {
            daysInYear += leapYearMonthDays[i-1];
        }
        daysInYear += day;
        return daysInYear;
    }
}

// 往后演算日期
void increment(Date &date, const int days) {
    // 假设一个正确日期
    int correctDay = date.getDays() + days;
    int correctMonth = 1;
    int correctYear = date.year;

    if (correctDay <= 31) // 如果总天数控制在1月份
    {
        date.set(correctYear, correctMonth, correctDay);
    }
    else // 如果总天数不能控制在1月份
    {
        do {
            if (correctMonth == 12) {
                correctMonth = 1;
                correctYear++;
                correctDay -= 31;
            } else if (!date.isLeapYear(correctYear)) {
                correctMonth++;
                correctDay -= date.commonYearMonthDays[correctMonth-1];
            } else {
                correctMonth++;
                correctDay -= date.leapYearMonthDays[correctMonth-1];
            }
        } while ((!date.isLeapYear(correctYear) && correctDay > date.commonYearMonthDays[correctMonth]) || 
                 (date.isLeapYear(correctYear) && correctDay > date.commonYearMonthDays[correctMonth]));
        
        date.set(correctYear, correctMonth, correctDay);
    }
}

// 往前演算日期
void decrement(Date &date, const int days) {
    // 假设一个正确日期
    int correctDay1 = date.getDays() - days;
    int correctMonth1 = 1;
    int correctYear1 = date.year;

    if (correctDay1 >= 0) {
        date.set(correctYear1-1, 12, 31);
        increment(date, correctDay1);
    } else {
        do {
            correctYear1--;
            if (date.isLeapYear(correctYear1))
                correctDay1 += 366;
            else
                correctDay1 += 365;
        } while ((abs(correctDay1) > 366 && date.isLeapYear(correctYear1)) || (abs(correctDay1) > 365 && !date.isLeapYear(correctYear1)));
        date.set(correctYear1-1, 12, 31);
        increment(date, correctDay1);
    }
}

// 判断两个日期的前后顺序
bool after(const Date &date1, const Date &date2) {
    if (date1.year > date2.year)
        return true;
    else if (date1.year == date2.year && (date1.getDays() > date2.getDays()))
        return true;
    else
        return false;
}
