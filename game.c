#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int n=120;
    int score=0;
    int x = 1;              // player position (0 to 2)
    int step = 0;           // obstacle vertical movement
    int obstaclePos = rand() % 3;   // 0,1,2 lane

    while (1) {

        // ---- INPUT ----
        if (_kbhit()) {
            char ch = getch();

            if (ch == 75 && x > 0)        // LEFT arrow
                x--;

            if (ch == 77 && x < 2)        // RIGHT arrow
                x++;
        }

        // ---- DRAW ----
        system("cls");
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++) {
            if (i == step) {

                if (obstaclePos == 0)
                    printf("| %d        |\n", 1);

                else if (obstaclePos == 1)
                    printf("|     %d    |\n", 1);

                else if (obstaclePos == 2)
                    printf("|        %d |\n", 1);

            } else {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %d        |\n", 6);
        else if (x == 1)
            printf("|     %d    |\n", 6);
        else if (x == 2)
            printf("|        %d |\n", 6);

        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos) {
            printf("\nGAME OVER!\n");
            printf("score: %d",score);
            break;
        }
        
        // scoreboard code

        if(step == 10 && x != obstaclePos){
            score = score + 10;
        }
            printf("score: %d  ",score);

        Sleep(n);
        
        // change of difficulty on the basis of score

        if(score<=40){
            n = 120;
        }else if(score==60){
            n = 100;
        }else if(score==80){
            n = 90;
        }else if(score==100){
            n = 80;
        }else if(score==120){
            n = 70;
        }else if(score==140){
            n = 50;
        }
        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3; // new lane
        }
    }

    return 0;
}
