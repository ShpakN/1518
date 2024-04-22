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

char *getEndOfString(char *s);

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

void stringBuffer(char *s) {
    for (; *s; ++s) {
        if (isdigit(*s)) *s = ' ';
    }
}

char replace(char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);

    char *word1 = {w1, w1 + w1Size};
    const char *word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    copyIf(word1, word2, source, isalpha);
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    while (w1 != '/0' && w2 != '/0') {

        if (w1 < w2) {
            return 1;
        } else {
            return 0;
        }
    }
}


typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

void getBagOfWords(BagOfWords *bag, char *s) {
    char *_bag;
    const char *_bag2;

    copyIfReverse(_bag, _bag2, (char *) bag, (int (*)(int)) s);
}

int numberOfPalindrome(char *source, char w1, char w2) {
    int k = 0;

    char q = replace(source, &w1, &w2);

    if (w1 == q || w2 == q) {
        k++;
    }

    return k;
}

int alternatingOfPalindrome(char s1, char s2
) {
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = &s1, *beginSearch2 = &s2;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (beginSearch1 > beginSearch2) {
            int k = beginSearch1 - beginSearch2;

            return k;
        } else {
            int l = beginSearch2 - beginSearch1;

            return l;
        }
    }
}

void reverseWord(char *begin, char *end) {
    for (--end; begin < end; ++begin, --end) {
        char tmp = *begin;
        *begin = *end;
        *end = tmp;
    }
}

int is_separator(char c) {
    return c == ' ';
}

void reverseWords(char *s) {
    char *word = s;

    do {
        for (; is_separator(*word); ++word);
        if (*word == '\0')
            break;

        char *word_end = word;
        for (++word_end; *word_end != '\0' && !is_separator(*word_end); ++word_end);

        reverseWord(word, word_end);
        word = word_end;
    } while (1);

    reverseWord(s, word);
}

char * printWordBeforeFirstWordWithA(char *s) {
    size_t l = strlen(s);
    for (size_t i = 0; i < l; i++) {
        if (s[i] == 'a') {
            return s;
        } else{
            return 0;
        }
    }
}
