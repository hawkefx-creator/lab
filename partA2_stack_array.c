/* A-2 */
PART A – 2
   Stack Operations using Array Implementation
   ============================================================ */

#include <stdio.h>

#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) {
        puts("Stack Overflow!");
        return;
    }

    stack[++top] = x;
    printf("%d pushed.\n", x);
}

void pop(void) {
    if (top == -1) {
        puts("Stack Underflow!");
        return;
    }

    printf("Popped: %d\n", stack[top--]);
}

void display(void) {
    int i;

    if (top == -1) {
        puts("Stack is empty.");
        return;
    }

    printf("Stack (top to bottom): ");

    for (i = top; i >= 0; --i)
        printf("%d ", stack[i]);

    putchar('\n');
}

void palindrome(void) {
    char s[200];
    int i, len, ok = 1;

    printf("Enter a word/string (no spaces): ");
    scanf("%199s", s);

    for (len = 0; s[len] != '\0'; ++len) {}

    for (i = 0; i < len / 2; ++i)
        if (s[i] != s[len - 1 - i]) {
            ok = 0;
            break;
        }

    puts(ok ? "Palindrome." : "Not a palindrome.");
}

int main(void) {
    int ch, x;

    do {
        puts("\n1.Push 2.Pop 3.Check Palindrome 4.Demonstrate Overflow/Underflow 5.Display 6.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1:
                printf("Element: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                palindrome();
                break;

            case 4:
                pop();
                while (top < MAX - 1)
                    push(10 + top + 1);
                push(99);
                break;

            case 5:
                display();
                break;

            case 6:
                puts("Exiting.");
                break;

            default:
                puts("Invalid choice.");
        }

    } while (ch != 6);

    return 0;
}


/* ============================================================
