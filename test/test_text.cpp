#include "Text.hpp"
#include <iostream>
using namespace std;

int main() {
    cout << "\x1b[4C";
    Text text = Text("Hello");
    text.setDim();
    text.setBold();
    text.setColor(Color::bright_blue);
    text.setBgColor(BackgroundColor::bright_white);
    cout << text;

    Text t2 = Text("World", Color::black, BackgroundColor::bright_blue, true);
    cout << cout.width(10) << t2;
    return 0;
}
