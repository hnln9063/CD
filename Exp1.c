/*Implementation of DFA to accept Strings ending with abc */

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    printf("Enter the string over the alphabets (a, b, c): ");
    scanf("%s", str);
    int q = 0, prev_q;
    for (int i = 0; i < strlen(str); i++) {
        if(str[i]!='a' && str[i]!='b' && str[i]!='c'){
            printf("Invalid string!!\nString is not accepted.\n");
            return 0;
        }
        prev_q = q;
        switch(q) {
            case 0 : q = (str[i] == 'a') ? 1 : 0;
                     break;
            case 1 : q = (str[i] == 'b') ? 2 : (str[i] == 'a') ? 1 : 0;
                     break;
            case 2 : q = (str[i] == 'c') ? 3 : (str[i] == 'a') ? 1 : 0;
                     break;
            case 3 : q = (str[i] == 'a') ? 1 : 0;
                     break;
        }
        printf("%c : q%d-->q%d\n", str[i], prev_q, q);
    }
    if (q == 3)
        printf("Given string reached final state q3, so it is Accepted.\n");
    else
        printf("Given string is in state q%d, so it is not accepted.\n",q);
    return 0;
}
/*
Test Case 1:
Enter the string over the alphabets (a, b, c): abcaabc
a : q0-->q1
b : q1-->q2
c : q2-->q3
a : q3-->q1
a : q1-->q1
b : q1-->q2
c : q2-->q3
Given string reached final state q3, so it is Accepted.
    
Test Case 2:
Enter the string over the alphabets (a, b, c): abababac
a : q0-->q1
b : q1-->q2
a : q2-->q1
b : q1-->q2
a : q2-->q1
b : q1-->q2
a : q2-->q1
c : q1-->q0
Given string is in state q0, so it is not accepted.*/
