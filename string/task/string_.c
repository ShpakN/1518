#include <corecrt.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#include "string_.h"

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

void removeAdjacentEqualLetters(char *s) {
    char *endSource = (char *) getEndOfString(s);
    char **destination = (char **) copyIf(s, endSource, s, isgraph);
    *destination = s;
}

void removeExtraSpaces(char *s) {
    for (int j = 0; j < strlen(s); j++) {
        if (s[j] == ' ') {
            while (s[j + 1] == ' ')
                memmove(&s[j + 1], &s[j + 2], strlen(s) - j);
        }
    }
    if (s[0] == ' ')
        memmove(s, s + 1, strlen(s));
    if (s[strlen(s) - 2] == ' ')
        s[strlen(s) - 2] = '\n';
}

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

char *beginString;

int getWord(char *beginSearch, WordDescriptor *word) {

    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;

}

void digitToStart(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);

    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartNotChangeable(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 (char *) -1);

    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartReverse(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 0);

    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartReverseOrder(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 0);

    char *recPosition = copyIfReverse(endStringBuffer,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findNonSpace(rbegin);
    while (*word->begin != *word->end) {
        *word->begin++;
    }
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}