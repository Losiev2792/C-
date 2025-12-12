#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 50
#define FILENAME "students.csv"

// strckt
typedef struct {
    char firstName[MAX_LEN];
    char lastName[MAX_LEN];
    int age;
    bool isStudent; // true або false
} User;

void save_student(const User *user) {
    if (!user->isStudent) {
        printf("користувач не студент\n");
        return;
    }

    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Помилка");
        return;
    }

    fprintf(file, "%s,%s,%d\n", user->firstName, user->lastName, user->age);
    fclose(file);
    printf("💾 дані  збережено '%s'.\n", FILENAME);
}


void display_info(const User *user) {
    printf("\ninfo\n");
    printf("Ім'я: %s\n", user->firstName);
    printf("Прізвище: %s\n", user->lastName);
    printf("Вік: %d\n", user->age);
    printf("Статус: %s\n", user->isStudent ? "Студент" : "Не студент");
    printf("--------------------------\n");
}

int main() {
    User currentUser;
    char status_input[10];

    printf("Info\n");

    printf("ваше ім'я: ");
    scanf("%49s", currentUser.firstName);

    printf("ваше прізвище: ");
    scanf("%49s", currentUser.lastName);

    printf("ваш вік: ");
    if (scanf("%d", &currentUser.age) != 1) {
        printf("помилка віку.\n");
        return 1;
    }

    // cln buf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Студент(ка)? (y/n): ");
    if (fgets(status_input, sizeof(status_input), stdin) != NULL) {
        currentUser.isStudent = (status_input[0] == 'y' || status_input[0] == 'Y');
    } else {
        currentUser.isStudent = false;
    }

    display_info(&currentUser);

    save_student(&currentUser);

    return 0;
}