#include "Date.h"
#include <iostream>
using namespace std;

int main() {
    Date d1(14, 5, 2020);
    Date d2(13, 6, 2020);
    cout << (today() > d1 && today() < d2);
}
