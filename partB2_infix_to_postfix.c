/* B-2 */
PART B – 2
   Infix to Postfix Expression Conversion using Stack
   ============================================================ */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 300

char st[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        st[++top] = c;
}

char pop(void) {
    return top >= 0 ? st[top--] : '\0';
}

int precedence(char c) {
    switch (c) {
        case '^':
            return 3;

        case '*':
        case '/':
        case '%':
            return 2;

        case '+':
        case '-':
            return 1;

        default:
            return 0;
    }
}

int rightAssoc(char c) {
    return c == '^';
}

int main(void) {
    char in[MAX], out[MAX];
    int i, k = 0, valid = 1;

    printf("Enter infix expression (single-character operands): ");

    if (!fgets(in, sizeof in, stdin))
        return 1;

    in[strcspn(in, "\n")] = '\0';

    for (i = 0; in[i]; ++i) {
        char c = in[i];

        if (isspace((unsigned char)c))
            continue;

        if (isalnum((unsigned char)c))
            out[k++] = c;

        else if (c == '(')
            push(c);

        else if (c == ')') {
            while (top >= 0 && st[top] != '(')
                out[k++] = pop();

            if (top < 0) {
                valid = 0;
                break;
            }
            else
                pop();
        }

        else if (strchr("+-*/%^", c)) {
            while (top >= 0 &&
                   st[top] != '(' &&
                   (precedence(st[top]) > precedence(c) ||
                   (precedence(st[top]) == precedence(c) &&
                    !rightAssoc(c))))
                out[k++] = pop();

            push(c);
        }

        else {
            valid = 0;
            break;
        }
    }

    while (valid && top >= 0) {
        if (st[top] == '(') {
            valid = 0;
            break;
        }

        out[k++] = pop();
    }

    out[k] = '\0';

    if (valid)
        printf("Postfix expression: %s\n", out);
    else
        puts("Invalid expression or unsupported character.");

    return 0;
}


/* ============================================================
