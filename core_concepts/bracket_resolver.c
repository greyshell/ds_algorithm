#include <stdio.h>

char *minRemoveToMakeValid(char *s) {
    int i = 0, n = 0, count = 0, length = 0;
    int flag = 0, is_seen = 0;
    char test_char;
    // iterate the string and identify the invalid ')' char
    // if found then replace that with '-' char
    while (s[i] != '\0') {
        // if ) is seen before the (
        if (is_seen == 0 && s[i] == ')') {
            s[i] = '-';
        } else if (s[i] == ')') {
            flag--;
        } else if (s[i] == '(') {
            is_seen = 1;
            flag++;
        }

        if (flag < 0) {
            s[i] = '-';
            flag++;
        }
        i++;
    }
    length = i;

    if (flag < 0) {
        count = -flag;
        test_char = ')';
    } else {
        count = flag;
        test_char = '(';
    }

    n = 1;
    for (int k = length - 1; k >= 0; k--) {
        if (s[k] == test_char && n <= count) {
            s[k] = '-';
            n++;
        }
    }

    // remove the - and shift the valid characters
    n = i = 0;
    while (s[i] != '\0') {
        if (s[i] != '-') {
            s[n++] = s[i];
        }
        i++;
    }
    s[n] = '\0';

    return s;
}

int main(void) {
    char *r;
    char s[] = "())()(((";
    r = minRemoveToMakeValid(s);
    printf("\noutput: %s", r);
    return 0;
}
