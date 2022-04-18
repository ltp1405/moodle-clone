#include "../App.h"

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
}
