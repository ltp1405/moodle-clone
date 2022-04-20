#include <iostream>
using namespace std;

#ifdef __linux
const string ERASE_CMD = "clear";
#endif

int main() {
    cout << "Hello " << endl;
    cout << "\033[2J\033[1;1H";
}
