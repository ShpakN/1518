#include <stdio.h>
#include <string.h>
#include "string/task/string_.c"

int test_strlen_() {
    char *str1 = "HELLO";

    strlen_(str1);
}

int test_find() {
    char *str1 = "HELLO";
    char *str2 = "O";
    int ch = 3;

    find(str1, str2, ch);
}

int test_findNonSpace() {
    char *str1 = "HELLO";

    findNonSpace(str1);
}

int test_findSpace() {
    char *str1 = "HELLO";

    findSpace(str1);
}

int test_findNonSpaceReverse() {
    char *str1 = "HELLO";
    char *str2 = "L";

    findNonSpaceReverse(str1, str2);
}

int test_findSpaceReverse() {
    char *str1 = "HELLO";
    char *str2 = "L";

    findSpaceReverse(str1, str2);
}

int test_strcmp() {
    char *str1 = "HELLO";
    char *str2 = "L";

    strcmp(str1, str2);
}

int test_copy() {
    char *str1 = "HELLO";
    char *str2 = "L";
    char *str3 = "H";

    copy(str1, str2, str3);
}

int test_copyIf() {
    char *str1 = "HELLO";
    char *str2 = "L";
    char *str3 = "H";
    int f = 1;

    copyIf(str1, str2, str3, (int (*)(int)) f);
}

int test_copyIfReverse() {
    char *str1 = "HELLO";
    char *str2 = "L";
    char *str3 = "H";
    int f = 1;

    copyIfReverse(str1, str2, str3, (int (*)(int)) f);
}

void tests() {
    test_strlen_();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

void assertString(const char *expected, char *got,

                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void test_digitToStartTransform_oneWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    assertString("321Hi", s,

                 "С:\Users\...\digitToStartTransform",
                 "test_digitToStartTransform_oneWord", 4);

}

int main() {
    tests();
}
