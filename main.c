#include <stdio.h>
#include <string.h>
#include <assert.h>
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

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;
// заголовок функции
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w){
    return FIRST_WORD_WITH_A;
}

void testAll_getWordBeforeFirstWordWithA() {
    WordDescriptor word;
    char s1[] = "";
    assert(
            getWordBeforeFirstWordWithA(s1, &word)
            == EMPTY_STRING
    );
    char s2[] = "ABC";
    assert(
            getWordBeforeFirstWordWithA(s2, &word)
            == FIRST_WORD_WITH_A
    );
    char s3[] = "BC A";
    assert(
            getWordBeforeFirstWordWithA(s3, &word)
            == WORD_FOUND
    );
    char got[MAX_WORD_SIZE];
    copy(beginWord, endWord, got);
    got[endWord - beginWord] = '\0';
    ASSERT_STRING("BC", got);
    char s4[] = "B Q WE YR OW IUWR";
    assert(getWordBeforeFirstWordWithA(s4, &word) == NOT_FOUND_A_WORD_WITH_A);
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
