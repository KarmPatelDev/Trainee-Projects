/*

SNAKE GAME:

- a key for left side turn
- d key for right side turn
- w key for up side turn
- s key for down side turn

- Also If snake eat fruit length is increase
- Game is over if snake head touch the walls and also itself
- Score increase by 10 and Also y key for play again

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void setup(int *, int *);
int input(int *);
void snake_mover(int *, int *, int *);

int gameOver = 0, score = 0;

int main(){
    int a = 20, b = 20, *height = &a, *width = &b;
    
    setup(height, width);

    return 0;
}

void setup(int *height, int *width){

    int snakeX, snakeY, fruitX, fruitY, *x = &snakeX, *y = &snakeY, *z = &fruitX, *w = &fruitY, direction = 0, *k = &direction, snake_tailX[100], snake_tailY[100], tail_counter = 0;
    snakeX = (*height) / 2;
    snakeY = (*width) / 2;

    label1:
    fruitX = rand()%20;
    if(fruitX == 0)goto label1;

    label2:
    fruitY = rand()%20;
    if(fruitY == 0)goto label2;

    if(snakeX == fruitX && snakeY == fruitY)goto label1;

    while(!gameOver){
    system("cls");

    printf("\n\n_____YOUR SCORE_____:\t%d\n\n", score);
    int i, j;
    for(i = 0; i < (*height); i++){
        for(j = 0; j < (*width); j++){
            if(i == 0 || i == ((*height)-1) || j == 0 || j == ((*width)-1)){
                printf("#");
            }
            else{
                if(i == snakeX && j == snakeY)printf("O");
                else if(i == fruitX && j == fruitY)printf("F");
                else {
                        int m = 0;
                        for(int n = 0;n < tail_counter; n++){
                            if(i == snake_tailX[n] && j == snake_tailY[n]){m = 1;printf("o");}
                        }
                        if(m == 0)printf(" ");
                    }

            }
        }
        printf("\n");
    }
    
    // For Tails moving
    int prevX1, prevY1, prevX2, prevY2;
    prevX1 = snake_tailX[0];
    prevY1 = snake_tailY[0];
    snake_tailX[0] = snakeX;
    snake_tailY[0] = snakeY;
    for(int l = 1; l < tail_counter; l++){
        prevX2 = snake_tailX[l];
        prevY2 = snake_tailY[l];
        snake_tailX[l] = prevX1;
        snake_tailY[l] = prevY1;
        prevX1 = prevX2;
        prevY1 = prevY2;
    }
    
    // For Snake Moving When Key Press
    *k = input(k);
 
    snake_mover(x, y, k);

    if(snakeX == fruitX && snakeY == fruitY){
        label3:
        fruitX = rand()%20;
        if(fruitX == 0)goto label3;

        label4:
        fruitY = rand()%20;
        if(fruitY == 0)goto label4;

        tail_counter++;
        score+=10;
        }
    
    for(int o = 0; o < tail_counter; o++){
         if(snakeX == snake_tailX[o] && snakeY == snake_tailY[o]){gameOver = 1;}
     }

    if(snakeX == 0 || snakeX == ((*height)-1) || snakeY == 0 || snakeY == ((*width)-1))gameOver=1;

    }
    
    char ch;
    printf("\n\n_____PRESS Y FOR PLAY AGAIN_____:\t");scanf("%c", &ch);
    if(ch == 'Y' || ch == 'y'){gameOver = 0;score = 0;main();}
    
}


int input(int *k){
    if(kbhit()){
    switch(getch()){
        case 'a':
                *k = 1;
                break;
        case 'd':
                *k = 2;
                break;
        case 'w':
                *k = 3;
                break;
        case 's':
                *k = 4;
                break;
        case 'x':
                 gameOver = 1;
                 break;
    }
    }   
   return (*k);
}


void snake_mover(int *x, int *y, int *k){
    if(!gameOver){
    switch(*k){
        case 1:
                (*y)--;
                break;
        case 2:
                (*y)++;
                break;
        case 3:
                (*x)--;
                break;
        case 4:
                (*x)++;
                break;
        }
    }
}

