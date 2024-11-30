#include <stdio.h>
#include <string.h>
#define max 100
#define size 100

int bookCount = 0;
int memberCount = 0;

struct book {
    int bookID;
    char title[size];
    char author[size];
    char phone[11];
    int year;
    int memberID;
};

struct Member {
    int id;
    char name[size];
    char phone[11];
};

void addbook(struct book thebooks[], struct Member themembers[]);

int printOption(int i) {
    printf("Choose one of the following options\n");
    printf("1. To add a new member\n");
    printf("2. To add a new book\n");
    printf("3. To print all members information\n");
    printf("4. To print all books information\n");
    printf("5. To quit\n");
    return i;
}

int main() {
    int option = 0;
    struct book thebooks[max];
    struct Member themembers[max];
    do {
        printOption(option);
        printf("Enter your choice: ");
        scanf_s("%d", &option);
        switch (option) {
        case 1:
            printf("*\n");
            break;
        case 2:
            addbook(thebooks, themembers);
            printf("*\n");
            break;
        case 3:
          
            break;
        case 4:
            printf("*\n");
            break;
        case 5:
            break;
        default:
            printf("Error, wrong number!\n");
            break;
        }
    } while (option != 5);
    return 0;
}

void addbook(struct book thebooks[], struct Member themembers[]) {
    if (bookCount >= max) {
        puts("The library is full. Cannot add more books");
        return;
    }

    int bookid, flag, memberid;
    do {
        printf("ENTER THE BOOK ID: ");
        scanf_s("%d", &bookid);
        flag = 1;
        for (int i = 0; i < bookCount; i++) {
            if (thebooks[i].bookID == bookid) {
                puts("BOOK ID ALREADY EXISTS, TRY AGAIN");
                flag = 0;
                break;
            }
        }
    } while (flag != 1);

    thebooks[bookCount].bookID = bookid;
    printf("ENTER TITLE: ");
    getchar();
    fgets(thebooks[bookCount].title, size, stdin);
    char* current_pos = strchr(thebooks[bookCount].title, '\n');
    if (current_pos) *current_pos = '\0';

    printf("Enter author: ");
    fgets(thebooks[bookCount].author, size, stdin);
    current_pos = strchr(thebooks[bookCount].author, '\n');
    if (current_pos) *current_pos = '\0';

    printf("Enter Year of Publication: ");
    scanf_s("%d", &thebooks[bookCount].year);

    printf("Enter member ID who borrowed or 0 if not borrowed: ");
    scanf_s("%d", &memberid);
    while (memberid != 0) {
        flag = 1;
        for (int i = 0; i < memberCount; i++) {
            if (themembers[i].id == memberid) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) {
            break;
        }
        else {
            printf("Member ID does not exist. Try again or enter 0: ");
            scanf_s("%d", &memberid);
        }
    }
    thebooks[bookCount].memberID = memberid;
    bookCount++;
}
