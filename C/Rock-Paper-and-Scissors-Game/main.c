/*

ROCK, PAPER, SCISSORS:

- we have two players. In our program, player 1 will be the user, and player 2 will be the computer. Player 1 selects either rock, paper, or scissor. The computer does not know about what player 1 has selected, so the computer randomly selects any item (rock, paper, or scissor).
- In this game, each player has 5 turns. The player who gets the point at least two times will win the game. The following are the rules of the game.

rock vs. scissors -> rock wins
paper vs. scissors -> scissors wins
paper vs. rock -> paper wins

- Allows the user to play this game five times with a computer. 
- Log the scores of the computer and the player.
- Display the name of the winner at the end
- Also Play Again Key
- Display the name of the player during the game. Take users name as an input from the user.

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    system("cls");
    int j, k = 0, l = 0, a = 1;
    char name[34];
    printf("\n\nEnter The Name Of The Player :-\t");
    gets(name);
    printf("\nHello %s, Welcome To My Rock, Paper, Scissors Game\n\n", name);
    
    printf("RULES :-\nPress 0 To Select Rock\nPress 1 To Select Paper\nPress 2 To Select Scissor\n5 Rounds In This Game\nThe One Who Has More Points Will Be Win The game\n\n");

    printf("_____PRESS ANY KEY TO START_____:\t");getchar();
    
    while(a == 1){
    for(int i = 1; i <= 5; i++){
        system("cls");
        int ptr[i];
        printf("\n\n%s, Enter The %d Round Number:\t", name, i);
        scanf("%d", &j);
        printf("%s Entered The %d Number\n", name, j);
        srand(time(NULL));
        ptr[i] = rand()%3;
        printf("Chitti, Enter The Number:\t%d\n\n", ptr[i]);
        
        
        if(j == 0 && ptr[i] == 0){
            printf("%s and Chitti Both selected Rock\n%d Round is Tie\n\n", name,i);
        }
        else if(j == 0 && ptr[i] == 1){
            printf("%s selected Rock and Chitti selected Paper\n%d Round is Chitti Win\n\n", name, i);
            k++;
        }
        else if(j == 0 && ptr[i] == 2){
            printf("%s selected Rock and Chitti selected Scissor\n%d Round is %s Win\n\n", name, i, name);
            l++;
        }
        else if(j == 1 && ptr[i] == 0){
            printf("%s selected Paper and Chitti selected Rock\n%d Round is %s Win\n\n", name, i, name);
            l++;
        }
        else if(j == 1 && ptr[i] == 1){
            printf("%s and Chitti Both selected Paper\n%d Round is Tie\n\n", name, i);
        }
        else if(j == 1 && ptr[i] == 2){
            printf("%s selected Paper and Chitti selected Scissor\n%d Round is Chitti Win\n\n", name, i);
            k++;
        }
        else if(j == 2 && ptr[i] == 0){
            printf("%s selected Scissor and Chitti selected Rock\n%d Round is Chitti Win\n\n", name, i);
            k++;
        }
        else if(j == 2 && ptr[i] == 1){
            printf("%s selected Scissor and Chitti selected Paper\n%d Round is %s Win\n\n", name, i, name);
            l++;   
        }
        else if(j == 2 && ptr[i] == 2){
            printf("%s and Chitti Both selected Scissor\n%d Round is Tie\n\n", name, i);
        }
        
        if(i != 5){
        printf("_____PRESS ANY KEY TO ANOTHER ROUND_____:\t");getch();
        }
        else{
        printf("_____PRESS ANY KEY FOR RESULT_____:\t");getch();
        }
    }
    
    system("cls");

    if(k < l){
        printf("\n\nCongratulation, %s Win The Game.\nYou Win %d Round\n", name, l);
    }
    else if(k > l){
        printf("\nSorry, %s Lost The Game.\nYou Win %d Round\n", name, l);
    }
    else{
        printf("\nThe Game is Tie\n");
    }
    
    printf("\nThanks For Playing, %s\n\n", name);

    a = 0;

    char ch;
    printf("_____PRESS Y TO PLAY AGAIN_____:\t");
    ch = getch();

    if(ch == 'y' || ch == 'Y')a =1;
    
    }

    return 0;
}
