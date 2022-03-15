#include "UserInterface/App.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main() {
    App app;
    app.init();
    app.run();

    return 0;
}
