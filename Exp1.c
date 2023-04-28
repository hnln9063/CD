hnln@DESKTOP-2JC785T:~/CD$ cat kar.c
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
