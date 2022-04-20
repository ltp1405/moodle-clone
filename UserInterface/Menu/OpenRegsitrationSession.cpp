#include <fstream>

#include "../App.h"

void saveRegistrationSession(Date start, Date end) {
    std::ofstream fout("data/RegistrationSession.txt");
    fout << start.day << ' ' << start.month << ' ' << start.year << endl
        << end.day << ' ' << end.month << ' ' << end.year;
    fout.close();
}

void App::promptOpenRegistrationSession() {
    if (!currentSemester)
        return;
    int sday, smonth, syear;
    int eday, emonth, eyear;

    cout << "Enter start day (dd mm yyyy): ";
    cin >> sday >> smonth >> syear;
    cout << "Enter end day (dd mm yyyy): ";
    cin >> eday >> emonth >> eyear;
    currentSemester->rgs.from = Date(sday, smonth, syear);
    currentSemester->rgs.to = Date(eday, emonth, eyear);

    saveRegistrationSession(currentSemester->rgs.from, currentSemester->rgs.to);
    cout << "Registration Session opened from "
         << currentSemester->rgs.from.toString() << " "
         << "to " << currentSemester->rgs.to.toString()
         << endl;
    cout << "Press any key to continue..." << endl;
    cin.ignore(100, '\n');
    cin.get();
}
