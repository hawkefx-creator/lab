/* A-1 */
PART A – 1
   Library Book Management using Structures and Dynamic Memory Allocation
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE 80
#define NAME 60

typedef struct {
    int Book_ID;
    char Title[TITLE], Author[NAME];
    float Price;
    int available; /* 1 = Available, 0 = Issued */
} Book;

Book *books = NULL;
int n = 0;

void clearLine(void) {
    int c; while ((c = getchar()) != '\n' && c != EOF) {}
}

void readLine(char *s, int size) {
    if (fgets(s, size, stdin)) s[strcspn(s, "\n")] = '\0';
}

void create(void) {
    int i;
    printf("Number of books to add: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        n = 0;
        puts("Invalid number.");
        clearLine();
        return;
    }

    clearLine();
    free(books);

    books = (Book *)calloc((size_t)n, sizeof(Book));

    if (!books) {
        puts("Memory allocation failed.");
        n = 0;
        return;
    }

    for (i = 0; i < n; ++i) {
        printf("\nBook %d ID: ", i + 1);
        scanf("%d", &books[i].Book_ID);
        clearLine();

        printf("Title: ");
        readLine(books[i].Title, TITLE);

        printf("Author: ");
        readLine(books[i].Author, NAME);

        printf("Price: ");
        scanf("%f", &books[i].Price);
        clearLine();

        books[i].available = 1;
    }
}

int findBook(int id) {
    int i;
    for (i = 0; i < n; ++i)
        if (books[i].Book_ID == id)
            return i;

    return -1;
}

void showBook(Book b) {
    printf("%-8d %-24s %-18s %8.2f %s\n",
           b.Book_ID, b.Title, b.Author,
           b.Price, b.available ? "Available" : "Issued");
}

void display(void) {
    int i, count = 0;

    if (!books || n == 0) {
        puts("No book records. Add records first.");
        return;
    }

    puts("ID        Title               Author          Price Status");

    for (i = 0; i < n; ++i)
        if (books[i].available) {
            showBook(books[i]);
            count++;
        }

    if (!count)
        puts("No books are currently available.");
}

void search(void) {
    int id, i;

    printf("Enter Book ID: ");
    scanf("%d", &id);

    i = findBook(id);

    if (i < 0)
        puts("Book not found.");
    else {
        puts("ID        Title              Author          Price Status");
        showBook(books[i]);
    }
}

void issueBook(void) {
    int id, i;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    i = findBook(id);

    if (i < 0)
        puts("Book not found.");
    else if (!books[i].available)
        puts("Book is already issued.");
    else {
        books[i].available = 0;
        puts("Book issued successfully.");
    }
}

void returnBook(void) {
    int id, i;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    i = findBook(id);

    if (i < 0)
        puts("Book not found.");
    else if (books[i].available)
        puts("Book is already available.");
    else {
        books[i].available = 1;
        puts("Book returned successfully.");
    }
}

int main(void) {
    int ch;

    do {
        puts("\n1.Add Book Records 2.Display Available Books 3.Search by ID");
        puts("4.Issue a Book      5.Return a Book            6.Exit");
        printf("Choice: ");

        if (scanf("%d", &ch) != 1)
            break;

        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }

    } while (ch != 6);

    free(books);
    return 0;
}


/* ============================================================
