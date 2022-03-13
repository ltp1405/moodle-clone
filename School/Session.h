enum Day {
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
};

// S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)
enum Time {
    S1,
    S2,
    S3,
    S4,
};

struct Session {
    Time time;
    Day day;
};
