#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "string/task/string_.c"
#include "string/task/digitToStartTransform.h"

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

assertString(s1, s2,
"digitToStartTransform.h",
"test_digitToStartTransform_oneWord", 30);


// заголовок функции
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, WordDescriptor *w) {
    return FIRST_WORD_WITH_A;
}


void test_digitToStartTransform_oneWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    assertString("321Hi", s,
                 "С:\Users\...\digitToStartTransform",
                 "test_digitToStartTransform_oneWord", 4);
}

void test_removeAdjacentEqualLetters() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    assertString("321Hi", s,
                 "С:\Users\...\digitToStartTransform",
                 "test_removeAdjacentEqualLetters", 4);
}

void test_removeExtraSpaces() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    removeExtraSpaces("321Hi", s,
                      "С:\Users\...\digitToStartTransform",
                      "test_removeExtraSpaces", 4);
}

void test_digitToStart() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    digitToStart("321Hi", s,
                 "С:\Users\...\digitToStartTransform",
                 "test_digitToStart", 4);
}

void test_digitToStartNotChangeable() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    digitToStartNotChangeable("321Hi", s,
                              "С:\Users\...\digitToStartTransform",
                              "test_digitToStartNotChangeable", 4);
}

void test_digitToStartReverse() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    digitToStartReverse("321Hi", s,
                        "С:\Users\...\digitToStartTransform",
                        "test_digitToStartReverse", 4);
}

void test_digitToStartReverseOrder() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    digitToStartReverseOrder("321Hi", s,
                             "С:\Users\...\digitToStartTransform",
                             "test_digitToStartReverseOrder", 4);
}

void test_areWordsEqual() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    areWordsEqual("321Hi", s,
                  "С:\Users\...\digitToStartTransform",
                  "test_areWordsEqual", 4);
}

void test_getBagOfWords() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    getBagOfWords("321Hi", s,
                  "С:\Users\...\digitToStartTransform",
                  "test_getBagOfWords", 4);
}

void test_numberOfPalindrome() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    numberOfPalindrome("321Hi", s,
                       "С:\Users\...\digitToStartTransform",
                       "test_numberOfPalindrome", 4);
}

void test_alternatingOfPalindrome() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    alternatingOfPalindrome("321Hi", s,
                            "С:\Users\...\digitToStartTransform",
                            "test_alternatingOfPalindrome", 4);
}

void test_reverseWords() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    getBagOfWords("321Hi", s,
                  "С:\Users\...\digitToStartTransform",
                  "test_reverseWords", 4);
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

void test_alternatingOfLastWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    alternatingOfLastWord("321Hi", s,
                          "С:\Users\...\digitToStartTransform",
                          "test_alternatingOfLastWord", 4);
}

void test_IsSimilarWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    IsSimilarWord("321Hi", s,
                  "С:\Users\...\digitToStartTransform",
                  "test_IsSimilarWord", 4);
}

void test_IsSimilarSetWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    IsSimilarSetWord("321Hi", s,
                     "С:\Users\...\digitToStartTransform",
                     "test_IsSimilarSetWord", 4);
}

void test_printDiverseLastWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    printDiverseLastWord("321Hi", s,
                         "С:\Users\...\digitToStartTransform",
                         "test_printDiverseLastWord", 4);
}

void test_printPrecedingFirstWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    printDiverseLastWord("321Hi", s,
                         "С:\Users\...\digitToStartTransform",
                         "test_printPrecedingFirstWord", 4);
}

void test_deleteDuplicateString() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    deleteDuplicateString("321Hi", s,
                          "С:\Users\...\digitToStartTransform",
                          "test_deleteDuplicateString", 4);
}

void test_SmallerNumberOfargerNumberOfWords() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    SmallerNumberOfargerNumberOfWords("321Hi", s,
                                      "С:\Users\...\digitToStartTransform",
                                      "test_SmallerNumberOfargerNumberOfWords", 4);
}

void test_IsStringeachLetterGivenWord() {
    char s[] = "Hi123 ";
    digitToStartTransform(s);
    IsStringeachLetterGivenWord("321Hi", s,
                                "С:\Users\...\digitToStartTransform",
                                "test_IsStringeachLetterGivenWord", 4);
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
    test_digitToStartTransform_oneWord();
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    test_digitToStart();
    test_digitToStartNotChangeable();
    test_digitToStartReverse();
    test_digitToStartReverseOrder();
    test_areWordsEqual();
    test_getBagOfWords();
    test_numberOfPalindrome();
    test_alternatingOfPalindrome();
    test_reverseWords();
    testAll_getWordBeforeFirstWordWithA();
    test_alternatingOfLastWord();
    test_IsSimilarWord();
    test_IsSimilarSetWord();
    test_printDiverseLastWord();
    test_printPrecedingFirstWord();
    test_deleteDuplicateString();
    test_SmallerNumberOfargerNumberOfWords();
    test_IsStringeachLetterGivenWord();
}

int main() {
    tests();
}
