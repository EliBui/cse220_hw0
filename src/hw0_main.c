#include <stdio.h>

void printBoard(int game[]) {
    for(int i = 0; i < 5; i++) {
        if(i == 4) {
            printf("| %d\n", game[i]);
        } else {
            printf("%d ", game[i]);
        }
    }
}

int play(int *game, int index) {
    int counter = game[index];
    game[index] = 0;
    while(counter > 0) {
        index++;
        if(index > 4) {
            index = 0;
        }
        game[index]++;
        counter--;
    }
    return index;
}

int checkWin(int *game) {
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        sum += game[i];
    }

    if(sum == 0) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
    int game[] = {2, 2, 2, 2, 0};
    int index = 0;
    int gameState = 1; //0 = lost, 1 = continue, 2 = won
    
    do{
        printBoard(game);
        
        printf("Choose a section (1-4): ");
        scanf("%d", &index);
        index--;

        while(game[index] == 0 || index > 3 || index < 0) {
            printf("Invalid choice. Choose a section (1-4): ");
            scanf("%d", &index);
            index--;
        }
        

        index = play(game, index);

        if(index != 4) {
            while(index != 4 && game[index] != 1) {
                printBoard(game);
                printf("Last piece landed in section %d. Continue sowing seeds!\n", index+1);
                index = play(game, index);
            }
            
            if(game[index] == 1) {
                gameState = 0;
                //last counter landed on section with 0 game lost
            }
        } else {
            gameState = checkWin(game);
        }
    } while(gameState == 1);

    if(gameState == 0) {
        printBoard(game);
        printf("You lost because the last counter fell into section %d.\n", index+1);
    } else {
        printf("You won!\n");
    }

    return 0;
}
