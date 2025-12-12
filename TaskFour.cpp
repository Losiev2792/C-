#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_ATTEMPTS 6

static const char *WORDS[] = {
    "hello",
    "world",
    "game",
    "code",
    "win"
};
static const int NUM_WORDS = 5;

int main() {
    srand((unsigned int)time(NULL));
    const char *targetWord = WORDS[rand() % NUM_WORDS];
    int length = (int)strlen(targetWord);

    char *guessedWord = (char *)calloc(length + 1, sizeof(char));
    if (guessedWord == NULL) return 1;
    memset(guessedWord, '*', length);
    guessedWord[length] = '\0';
    
    int attempts = MAX_ATTEMPTS;
    int guessedCount = 0;
    char guess;
    int position;

    printf("вгадай слово\n");
    printf("слово з %d літер. спроб: %d\n", length, MAX_ATTEMPTS);
    
    while (attempts > 0 && guessedCount < length) {
        printf("\nслово: %s (залишилось: %d)\n", guessedWord, attempts);

        printf("літера: ");
        if (scanf(" %c", &guess) != 1) {
            while (getchar() != '\n'); 
            continue;
        }
        guess = tolower(guess);

        printf("позиція букви (0-%d): ", length - 1);
        if (scanf("%d", &position) != 1) {
             while (getchar() != '\n');
             continue;
        }

        while (getchar() != '\n');

        
        if (position >= 0 && position < length) {
            if (targetWord[position] == guess) {
                if (guessedWord[position] == '*') {
                    guessedWord[position] = guess;
                    guessedCount++;
                    printf(" правильно\n");
                } else {
                    printf("ℹ️ вже вгадано\n");
                }
            } else {
                attempts--;
                printf(" не вірно. спроб осталось: %d\n", attempts);
            }
        } else {
            printf("не правильно введено.\n");
        }
    }

    printf("\nгра завершена\n");
    if (guessedCount == length) {
        printf("перемога! Слово: %s\n", targetWord);
    } else {
        printf("поразка. слово було: %s\n", targetWord);
    }
    
    free(guessedWord);
    return 0;
}