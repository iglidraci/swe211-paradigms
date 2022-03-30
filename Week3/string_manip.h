#include <cctype>

void to_upper_case(char *);
void copy_string(char*, char*);
void format_string(char *, char (char));

void to_upper_case(char *str) {
    while (*str != '\0') {
        *str = toupper(*str);
        str++;
    }
}

void copy_string(char *from, char *to) {
    while (*from != '\0') {
        *to = *from;
        from++;
        to++;
    }
    *to = '\0';
}

void format_string (char *str, char(*map_func)(char)) {
    while (*str != '\0') {
        *str = map_func(*str);
        str++;
    }
}
