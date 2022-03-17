// Code idea from https://gist.github.com/zyvitski/fb12f2ce6bc9d3b141f3bd4410a6f7cf
#include <iostream>
#include <sstream>
#include <string>

enum class Color : int {
    black = 30,
    red = 31,
    green = 32,
    yellow = 33,
    blue = 34,
    magenta = 35,
    cyan = 36,
    white = 37,
    bright_black = 90,
    bright_red = 91,
    bright_green = 92,
    bright_yellow = 93,
    bright_blue = 94,
    bright_magenta = 95,
    bright_cyan = 96,
    bright_white = 97,
};

enum class BackgroundColor : int {
    black = 40,
    red = 41,
    green = 42,
    yellow = 43,
    blue = 44,
    magenta = 45,
    cyan = 46,
    white = 47,
    bright_black = 100,
    bright_red = 101,
    bright_green = 102,
    bright_yellow = 103,
    bright_blue = 104,
    bright_magenta = 105,
    bright_cyan = 106,
    bright_white = 107,
};

template<class Printable>
class Text {
private:
    bool bold;
    bool dim;
    Color fg;
    BackgroundColor bg;
public:
    Printable text;

    Text();
    Text(Printable text, Color fg = Color::white,
         BackgroundColor bg = BackgroundColor::black, bool bold = false,
         bool dim = false) {
        this->text = text;
        setColor(fg);
        setBgColor(bg);
        if (bold)
            setBold();
        if (dim)
            setDim();
    }

    std::string display() const {
        std::stringstream sstr;
        sstr << "\x1b[1;" << static_cast<int>(fg) << "m";
        sstr << "\x1b[1;" << static_cast<int>(bg) << "m";
        if (bold)
            sstr << "\x1b[1m";
        if (dim)
            sstr << "\x1b[3m";
        sstr << text << "\x1b[0m";

        return sstr.str();
    }

    void setColor(Color color) {
        fg = color;
    }

    void setBgColor(BackgroundColor bgcolor) {
        bg = bgcolor;
    }

    void setBold(bool on=true) {
        if (on)
            bold = true;
        else 
            bold = false;
    }

    void setDim(bool on=true) {
        if (on)
            bold = true;
        else 
            bold = false;
    }
};

template<class Printable>
std::ostream &operator<<(std::ostream &os, Text<Printable> const &t) {
    return os << t.display();
}

// int main(int agrc,char** argv){
//
//   //print a colored progress bar using ANSI escape codes
//   float progress = 0.0;
//   while (progress <= 1.0) {
//       int barWidth = 70;
//
//       std::cout << "[";
//       int pos = barWidth * progress;
//       for (int i = 0; i < barWidth; ++i) {
//           if (i < pos) std::cout <<
//           print_as_color<ansi_color_code::red>("="); else if (i == pos)
//           std::cout << print_as_color<ansi_color_code::red>(">"); else
//           std::cout << " ";
//       }
//       std::cout << "] " << print_as_color<ansi_color_code::blue>(int(progress
//       * 100.0))<< " %\r"; std::cout.flush();
//
//       progress += 0.01; // for demonstration only
//       std::this_thread::sleep_for(std::chrono::milliseconds(125));
//     }
//     std::cout << std::endl;
//     return 0;
// }
