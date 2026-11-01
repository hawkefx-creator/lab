/* A-3 */
PART A – 3
   Printer Queue using Queue Data Structure
   ============================================================ */

#include <stdio.h>
#include <string.h>

#define MAX 5
#define LEN 80

char q[MAX][LEN];
int front = 0, rear = -1, count = 0;

void addJob(void) {
    if (count == MAX) {
        puts("Queue Overflow! Printer queue is full.");
        return;
    }

    printf("Enter print job name: ");
    scanf(" %79[^\n]", q[(rear + 1) % MAX]);

    rear = (rear + 1) % MAX;
    count++;

    puts("Print job added.");
}

void processJob(void) {
    if (!count) {
        puts("Queue Underflow! No jobs to process.");
        return;
    }

    printf("Processing job: %s\n", q[front]);

    front = (front + 1) % MAX;
    count--;

    if (!count) {
        front = 0;
        rear = -1;
    }
}

void display(void) {
    int i, idx;

    if (!count) {
        puts("No pending print jobs.");
        return;
    }

    puts("Pending print jobs:");

    for (i = 0; i < count; ++i) {
        idx = (front + i) % MAX;
        printf("%d. %s\n", i + 1, q[idx]);
    }
}

int main(void) {
    int ch;

    do {
        puts("\n1.Add Job 2.Process Job 3.Display Jobs 4.Count Jobs 5.Test Underflow 6.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1: addJob(); break;
            case 2: processJob(); break;
            case 3: display(); break;
            case 4: printf("Jobs waiting: %d\n", count); break;
            case 5:
                if (!count)
                    processJob();
                else
                    puts("Queue is not empty; process jobs to test underflow.");
                break;
            case 6: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }

    } while (ch != 6);

    return 0;
}


/* ============================================================
