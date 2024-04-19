#include <corecrt.h>
#include <ctype.h>
#include <memory.h>

size_t strlen_(const char *begin) {
    char *end = begin;

    while (*end != '\0')
        end++;

    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while ((int) begin != '/0') {
        begin++;
    }

    int e = isspace((int) begin);

    if (e) {
        return (char *) '/0';
    }

    return begin;
}

char *findSpace(char *begin) {
    while ((int) begin != '/0') {
        begin++;
    }\
    int e = isspace((int) begin);

    if (e) {
        return begin;
    } else {
        return (char *) '/0';

    }
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    int k = 0;

    rend = rbegin;

    while ((rbegin != '/0')) {
        rbegin++;
    }

    int e = isspace((int) rbegin);
    if ((int) rbegin != '/0') {
        k = 1;
    }

    if (k && !e) {
        return rbegin;
    } else {
        return rend;
    }

}

char *findSpaceReverse(char *rbegin, const char *rend) {
    int k = 0;

    rend = rbegin;

    while (((int) rbegin != '/0')) {

        rbegin++;
    }

    int e = isspace((int) rbegin);

    if ((int) rbegin == '/0') {
        k = 1;
    }

    if (k && e) {
        return rbegin;
    } else {
        return rend;
    }
}

int strcmp(const char *lhs, const char *rhs) {
    while (((int) lhs != '/0')) {
        lhs++;

        if (lhs == rhs) {
            return 1;
        } else {
            return 0;
        }
    }
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    while (((int) beginSource != endSource)) {
        beginSource++;

        char *destination = memcpy(beginSource, endSource, (unsigned long long int) beginDestination);

        return destination;
    }
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (((int) beginSource != endSource)) {
        beginSource++;
        if (f) {
            char *destination = memcpy(beginSource, endSource, (unsigned long long int) beginDestination);

            return destination;
        }
    }
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (((int) rbeginSource != rendSource)) {
        rbeginSource++;

        char *destination = memcpy(rbeginSource, rendSource, (unsigned long long int) beginDestination);

        if (f) {
            return beginDestination;
        } else {
            return destination;
        }
    }
}

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}