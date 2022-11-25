#include <stdio.h>

#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    cout << endl
         << "You passed " << argc - 1 << " arguement"
         << (argc - 1 == 1 ? "" : "s") << "." << endl;
    cout << (argc - 1 == 1 ? "This" : "These") << "arguement"
         << (argc - 1 == 1 ? "" : "s") << " " << (argc - 1 == 1 ? "is" : "are")
         << ":" << endl
         << endl;
    for (int i = 1; i < argc; i++) cout << argv[i] << endl;
    return 0;
}