/* B-6 */
PART B – 6
   Employee Record Management using Hashing and Linear Probing
   ============================================================ */

#include <stdio.h>

#define M 10

typedef struct {
    int id;
    char name[40], dept[40];
    float salary;
    int used;
} Employee;

Employee h[M];

int hash(int key) {
    return key % M;
}

void insert(void) {
    Employee e;
    int i, start;

    printf("Employee ID: ");
    scanf("%d", &e.id);

    printf("Name: ");
    scanf("%39s", e.name);

    printf("Department: ");
    scanf("%39s", e.dept);

    printf("Salary: ");
    scanf("%f", &e.salary);

    start = hash(e.id);

    for (i = 0; i < M; ++i) {
        int p = (start + i) % M;

        if (h[p].used && h[p].id == e.id) {
            puts("Employee ID already exists.");
            return;
        }

        if (!h[p].used) {
            h[p] = e;
            h[p].used = 1;

            printf("Inserted at location %d.\n", p);
            return;
        }
    }

    puts("Hash table is full.");
}

void search(void) {
    int key, i, start;

    printf("Employee ID to search: ");
    scanf("%d", &key);

    start = hash(key);

    for (i = 0; i < M; ++i) {
        int p = (start + i) % M;

        if (!h[p].used)
            break;

        if (h[p].id == key) {
            printf("Found at location %d: ID=%d Name=%s Dept=%s Salary=%.2f\n",
                   p,
                   h[p].id,
                   h[p].name,
                   h[p].dept,
                   h[p].salary);
            return;
        }
    }

    puts("Employee not found.");
}

void display(void) {
    int i;

    puts("Location ID       Name      Department Salary");

    for (i = 0; i < M; ++i)
        if (h[i].used)
            printf("%8d %-8d %-10s %-11s %.2f\n",
                   i,
                   h[i].id,
                   h[i].name,
                   h[i].dept,
                   h[i].salary);
        else
            printf("%8d -- empty --\n", i);
}

int main(void) {
    int ch;

    do {
        puts("\n1.Insert Employee 2.Search Employee 3.Display Hash Table 4.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                puts("Exiting.");
                break;

            default:
                puts("Invalid choice.");
        }

    } while (ch != 4);

    return 0;
}
