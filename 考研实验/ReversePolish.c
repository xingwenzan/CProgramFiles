//
// Created by 86159 on 2024/10/28.
//
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char *RePrint(char *string);

int main() {
    char *c = (char *) malloc(sizeof(char)), *ans;
    scanf("%s", c);
    printf("%s\n", c);

    ans = RePrint(c);
    printf("%s\n", ans);
}


char *RePrint(char *string) {
    char stack[100];
    int idx = 0;

    char *p = string;
    char *ans = (char *) malloc(sizeof(char)), *r = ans;

    for (int i = 0; i < strlen(string); ++i) {
        switch (*p) {
            case '(':
                stack[idx++] = *p;
                break;
            case '+':
            case '-': {
                if (idx == 0) {
                    stack[idx++] = *p;
                } else {
                    while (idx != 0) {
                        if (stack[idx - 1] == '(') {
                            idx--;
                            stack[idx++] = *p;
                            break;
                        } else {
                            *r = stack[--idx];
                            r++;
                        }
                    }
                    if (idx == 0)stack[idx++] = *p;
                }
                break;
            }
            case '*':
            case '/': {
                if (idx == 0) {
                    stack[idx++] = *p;
                } else {
                    while (idx != 0) {
                        if (stack[idx - 1] == '(') {
                            idx--;
                            stack[idx++] = *p;
                            break;
                        } else if (stack[idx - 1] == '+' || stack[idx - 1] == '-') {
                            stack[idx++] = *p;
                            break;
                        } else {
                            *r = stack[--idx];
                            r++;
                        }
                    }
                    if (idx == 0)stack[idx++] = *p;
                }
                break;
            }
            case ')': {
                while (idx != 0) {
                    if (stack[idx - 1] == '(') {
                        idx--;
                        break;
                    } else {
                        *r = stack[--idx];
                        r++;
                    }
                }
                break;
            }
            default: {
                *r = *p;
                r++;
            }
        }

        p++;
    }

    while (idx != 0) {
        *r = stack[idx-1];
        idx--;
        r++;
    }
    *r = '\0';

    return ans;
}