#include <stdio.h>
#include <string.h>

void showGameHeader(void) {
    printf("************************************\n");
    printf("           Jogo de Forca           *\n");
    printf("************************************\n\n");
}

void incTryedsOfUser(char *guessSecretKey, int *tryeds) {
    char guessLetter;

    printf("Try to find the next letter: ");
    scanf(" %c", &guessLetter); //Space before %c, because buffer of Key press...

    guessSecretKey[*tryeds] = guessLetter;
    (*tryeds)++;
}

int checkLettersUsed(char *secretKey, char *guessSecretKey, int i, int tryeds) {
    int foundLetter = 0;

    for (int j = 0; j < tryeds; j++) {

        if (guessSecretKey[j] == secretKey[i]) {
            return foundLetter = 1;
        }
    }

    return 0;
}

void drawStatusOfGame(char *secretKey, char *guessSecretKey, int tryeds) {
    for (int i = 0; i < strlen(secretKey); i++) {
        if (checkLettersUsed(secretKey, guessSecretKey, i, tryeds))
            printf("%c ", secretKey[i]);
        else
            printf("* ");
    }
    printf("\n");    
}

void selectSecretWordToGame(char *secretKey) {
    sprintf(secretKey, "MELANCIA");
}

int main() {
    char secretKey[20];

    int nailedIt = 0;
    int gameOver = 0;
    char guessSecretKey[26];
    int tryeds = 0;

    showGameHeader();
    selectSecretWordToGame(secretKey);
    
    do {
        drawStatusOfGame(secretKey, guessSecretKey, tryeds);
        incTryedsOfUser(guessSecretKey, &tryeds);
    } while (!nailedIt && !gameOver);

    return 0;
}