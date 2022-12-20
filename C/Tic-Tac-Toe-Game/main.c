/*

TIC TAC TOE GAME:

- Take Which Characters Players Choose For Playing
- Take Input From playes one by one and also change the value in the structure
- If some give input position which already taken or invalid then player have to give input again
- When One Player Make the 3 characters in line and diagonal
- Use 2D array in this Game
- Add Play Again and Exit at Last

*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void structure();
void take_input(char *, char *);
void fill_details(char *, char *);
void result_checker();

char ticTacToe[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int k = 0;

int main(){
    
    label:
    k = 0;
    char l = 49;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          ticTacToe[i][j] = l;
          l++;
        }
    }

    structure();
    
    // Take character
    char p1, p2, p;
    printf("\n\n\t\tPlayer 1 Choose Your Character To Play:\t\t");
    scanf("%c", &p1);
    fflush(stdin);

    printf("\n\t\tPlayer 2 Choose Your Character To Play:\t\t");
    scanf("%c", &p2);
    fflush(stdin);

    if(p1 < 33 || p1 > 126 || p2 < 33|| p2 >126)goto label;

    structure();

    take_input(&p1, &p2);
    
    if(k == 0)printf("\n\t\tTHE GAME IS TIE\t\n");
    printf("\n\t\tPRESS Y FOR PLAY AGAIN OR ANOTHER FOR EXIT:\t");
    p = getch();
    fflush(stdin);
    if(p == 'y'||p == 'Y')goto label;
    printf("\n\n");
    return 0;
}

void structure(){
    
    system("cls");
    printf("\n\n\t\t_________________TIC TAC TOE GAME_________________\n\n");

    printf("\t\t|---------------|---------------|---------------|\n");
    for(int i = 0; i < 3; i++){
        if(i!=1)printf("\t\t|\t\t|\t\t|\t\t|\n");
        else printf("\t\t|\t%c\t|\t%c\t|\t%c\t|\n", ticTacToe[0][0], ticTacToe[0][1], ticTacToe[0][2]);
    }
    printf("\t\t|---------------|---------------|---------------|\n");
    for(int i = 0; i < 3; i++){
        if(i!=1)printf("\t\t|\t\t|\t\t|\t\t|\n");
        else printf("\t\t|\t%c\t|\t%c\t|\t%c\t|\n", ticTacToe[1][0], ticTacToe[1][1], ticTacToe[1][2]);
    }
    printf("\t\t|---------------|---------------|---------------|\n");
    for(int i = 0; i < 3; i++){
        if(i!=1)printf("\t\t|\t\t|\t\t|\t\t|\n");
        else printf("\t\t|\t%c\t|\t%c\t|\t%c\t|\n", ticTacToe[2][0], ticTacToe[2][1], ticTacToe[2][2]);
    }
    printf("\t\t|---------------|---------------|---------------|\n");

}

void take_input(char *player1, char *player2){
    
    char c, check[9] = {0};
    for(int i = 0; i < 9; i++){
    if(i == 0 || i == 2 || i == 4 || i == 6 || i == 8){
        label1:
        printf("\n\n\t\tPlayer 1: Enter The Position:\t");scanf("%c", &c);
        fflush(stdin);
        for(int j = 0; j < i; j++){if(c==check[j]){printf("\n\t\tThe Position is already filled");goto label1;}}
        if(c > 48 && c <58)fill_details(player1, &c);
        else {printf("\n\t\tThe Position is Not Valid");goto label1;}
        if(k == 1){
            structure();
            printf("\n\t\tCongratulation, Player 1: You Won The Game\n\n");
            break;
        }
    }
    else{
        label2:
        printf("\n\n\t\tPlayer 2: Enter The Position:\t");scanf("%c", &c);
        fflush(stdin);
        for(int j = 0; j < i; j++){if(c==check[j]){printf("\n\t\tThe Position is already filled");goto label2;}}
        if(c > 48 && c <58)fill_details(player2, &c);
        else {printf("\n\t\tThe Position is Not Valid");goto label2;}
        if(k == 1){
            structure();
            printf("\n\t\tCongratulation, Player 2: You Won The Game\n\n");
            break;
        }
    }
    check[i] = c;
    if(k==1)break;
    }

}

// Position value change
void fill_details(char *player, char *c){
    switch(*c){
        case '1':
        ticTacToe[0][0] = *player;
        structure();
        break;
        case '2':
        ticTacToe[0][1] = *player;
        structure();
        break;
        case '3':
        ticTacToe[0][2] = *player;
        structure();
        break;
        case '4':
        ticTacToe[1][0] = *player;
        structure();
        break;
        case '5':
        ticTacToe[1][1] = *player;
        structure();
        break;
        case '6':
        ticTacToe[1][2] = *player;
        structure();
        break;
        case '7':
        ticTacToe[2][0] = *player;
        structure();
        break;
        case '8':
        ticTacToe[2][1] = *player;
        structure();
        break;
        case '9':
        ticTacToe[2][2] = *player;
        structure();
        break;
    }

    result_checker();
}

// For Result
void result_checker(){

    if(ticTacToe[0][0] == ticTacToe[1][1]){if(ticTacToe[1][1] == ticTacToe[2][2])k = 1;}
    else if(ticTacToe[0][2] == ticTacToe[1][1]){if(ticTacToe[1][1] == ticTacToe[2][0])k = 1;}
    else if(ticTacToe[0][0] == ticTacToe[0][1]){if(ticTacToe[0][1] == ticTacToe[0][2])k = 1;}
    else if(ticTacToe[1][0] == ticTacToe[1][1]){if(ticTacToe[1][1] == ticTacToe[1][2])k = 1;}
    else if(ticTacToe[2][0] == ticTacToe[2][1]){if(ticTacToe[2][1] == ticTacToe[2][2])k = 1;}
    else if(ticTacToe[0][0] == ticTacToe[1][0]){if(ticTacToe[1][0] == ticTacToe[2][0])k = 1;}
    else if(ticTacToe[0][1] == ticTacToe[1][1]){if(ticTacToe[1][1] == ticTacToe[2][1])k = 1;}
    else if(ticTacToe[0][2] == ticTacToe[1][2]){if(ticTacToe[1][1] == ticTacToe[2][2])k = 1;}

}
