/* B-4 */
PART B – 4
   Doubly Linked List of Employee Records and Double-Ended Queue
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>

#define S 40

typedef struct Node {
    int ssn;
    char name[S], dept[S], designation[S];
    float sal;
    char phone[S];
    struct Node *prev, *next;
} Node;

Node *head = NULL, *tail = NULL;

Node *readEmp(void) {
    Node *p = (Node *)malloc(sizeof(Node));

    if (!p) {
        puts("Memory allocation failed.");
        exit(1);
    }

    printf("SSN: ");
    scanf("%d", &p->ssn);

    printf("Name: ");
    scanf("%39s", p->name);

    printf("Department: ");
    scanf("%39s", p->dept);

    printf("Designation: ");
    scanf("%39s", p->designation);

    printf("Salary: ");
    scanf("%f", &p->sal);

    printf("Phone: ");
    scanf("%39s", p->phone);

    p->prev = p->next = NULL;

    return p;
}

void insertFront(void) {
    Node *p = readEmp();

    if (!head)
        head = tail = p;
    else {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

void insertEnd(void) {
    Node *p = readEmp();

    if (!tail)
        head = tail = p;
    else {
        p->prev = tail;
        tail->next = p;
        tail = p;
    }
}

void deleteFront(void) {
    Node *p;

    if (!head) {
        puts("DLL is empty.");
        return;
    }

    p = head;
    head = head->next;

    if (head)
        head->prev = NULL;
    else
        tail = NULL;

    free(p);

    puts("Front employee deleted.");
}

void deleteEnd(void) {
    Node *p;

    if (!tail) {
        puts("DLL is empty.");
        return;
    }

    p = tail;
    tail = tail->prev;

    if (tail)
        tail->next = NULL;
    else
        head = NULL;

    free(p);

    puts("End employee deleted.");
}

void display(void) {
    Node *p = head;
    int n = 0;

    if (!p)
        puts("DLL is empty.");

    while (p) {
        printf("%d %-12s %-10s %-12s %.2f %s\n",
               p->ssn,
               p->name,
               p->dept,
               p->designation,
               p->sal,
               p->phone);

        p = p->next;
        n++;
    }

    printf("Number of employees: %d\n", n);
}

int main(void) {
    int ch, n, i;

    do {
        puts("\n1.Create N (end insertion) 2.Display/Count 3.Insert End 4.Delete End");
        puts("5.Insert Front 6.Delete Front 7.Demonstrate Deque (insert both ends) 8.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1:
                printf("Number of employees: ");
                scanf("%d", &n);

                for (i = 0; i < n; ++i)
                    insertEnd();

                break;

            case 2:
                display();
                break;

            case 3:
                insertEnd();
                break;

            case 4:
                deleteEnd();
                break;

            case 5:
                insertFront();
                break;

            case 6:
                deleteFront();
                break;

            case 7:
                puts("Deque: choose insertion/deletion at either end using options 3–6.");
                break;

            case 8:
                puts("Exiting.");
                break;

            default:
                puts("Invalid choice.");
        }

    } while (ch != 8);

    while (head)
        deleteFront();

    return 0;
}


/* ============================================================
