
#include <ctime>
#include <iostream>
using namespace std;
int main() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    cout << "当前日期是: " << ltm->tm_year + 1900 << "-" << 1 + ltm->tm_mon
         << "-" << ltm->tm_mday << endl;
    return 0;
}