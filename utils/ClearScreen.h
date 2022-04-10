#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define CLS_COMMAND "cls"
#elif __linux__
    #define CLS_COMMAND "clear"
#elif __unix__ // all unices not caught above
#else
#   error "Unknown compiler"
#endif

void clearScreen();
