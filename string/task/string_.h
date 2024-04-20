
#ifndef INC_1517_STRING__H
#define INC_1517_STRING__H
#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
char _stringBuffer[MAX_STRING_SIZE + 1];
typedef struct str_ {
    int begin;
    int end;
    int ch;
} matrix;
typedef struct rstr_ {
    int rbegin;
    int rend;
} position;
#endif //INC_1517_STRING__H
