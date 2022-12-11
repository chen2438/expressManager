#include <bits/stdc++.h>
using namespace std;
bool compare_date(const string &date1, const string &date2) {
    int year1, month1, day1;
    int year2, month2, day2;
    std::sscanf(date1.c_str(), "%d-%d-%d", &year1, &month1, &day1);
    std::sscanf(date2.c_str(), "%d-%d-%d", &year2, &month2, &day2);
    if (year1 == year2) {
        if (month1 == month2) {
            return day1 < day2;
        }
        return month1 < month2;
    }
    return year1 < year2;
}
int main() {
    vector<string> dates;
    dates.push_back("2022-10-3");
    dates.push_back("2022-9-10");
    std::sort(dates.begin(), dates.end(), compare_date);
    for (auto i : dates) {
        cout << i << endl;
    }
}
