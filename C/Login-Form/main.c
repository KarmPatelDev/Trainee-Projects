/*

LOGIN FORM:

- Make a Sign Up/ Login Form 
- Sign Up Form fill name, email id, phone number, password, confirm password and username
- Then Also Usename Automatic Generate removing by .com
- Also check that email id already used or not
- Password take input [A-Z], [a-z], [0-9], @, #, $, &
- Also After Sign Up Go To Login Page
- File Details If Username / Password wrong then show the message to the user
- and After Login Show the details of user
- and also in that all Try Again and Quit Press Key For Action

*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define ENTER 13
#define TAB 9
#define BCKSPC 8

struct signup
{
    char full_name[50], email_id[50], phone_number[50], password[50], username[50];
} s_user;

struct login
{
    char login_username[50], login_password[50];
} l_user;

// For Remove The \n From The String
void take_input(char ch[50])
{
    fgets(ch, 50, stdin);
    ch[strlen(ch) - 1] = 0;
}

// Generate The Username
char generate_username(char email_id[50], char username[50])
{
    int result = 0;
    for(int i = 0; i < strlen(email_id); i++){
    if(email_id[i] == '.' && email_id[i] != strlen(email_id) - 4){if(email_id[i+1] == 'c'){if(email_id[i+2] == 'o'){if(email_id[i+3] == 'm'){result=1;break;}}}}
    else {username[i] = email_id[i];}
    }
    if(result == 0){
        printf("\tThe email ID is Not Valid Please Check Your Email-ID\n");
        printf("\tPress Any Key To Exit:\t");
        getch();
        exit(0);
    }
}

// Password Convert in ***** Formate
void covert_password(char password[50])
{
    int i = 0;
    char ch;
    while (1)
    {
        ch = getch();

        if (ch == ENTER || ch == TAB)
        {
            password[i] = '\0';
            break;
        }
        else if (ch == BCKSPC)
        { // For Not Include Backspace
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if(ch == 35 || ch == 36 || ch == 38)
        {
            password[i++] = ch; // i++ post increment
            printf("* \b");     // conver in ***
        }
        else if(ch >= 48 && ch <= 57)
        {
            password[i++] = ch; // i++ post increment
            printf("* \b");     // conver in ***
        }
        else if(ch >= 64 && ch <= 90)
        {
            password[i++] = ch; // i++ post increment
            printf("* \b");     // conver in ***
        }
        else if(ch >= 97 && ch <= 122)
        {
            password[i++] = ch; // i++ post increment
            printf("* \b");     // conver in ***
        }
    }
}

//Check email id has been used or not
void details_checker(struct signup s_user){

            char emailID[50];
            strcpy(emailID, s_user.email_id);
            FILE *file;
            file = fopen("login.bin", "rb+");
            while (fread(&s_user, sizeof(struct signup), 1, file))
            {
                if (strcmp(emailID, s_user.email_id) == 0)
                {
                    printf("\tThe email ID is already has been used Please Go to Login Page\n");
                    printf("\tPress Any Key To Exit:\t");
                    getch();
                    exit(0);
                }
            }
            fclose(file);
}

int main()
{

    int num;
    char confirm_password[50];
    system("cls");
    printf("\n____________________SIGN UP / LOGIN PAGE____________________\n");
    printf("\n\t\t1.\t\tSIGN UP PAGE\n\n");
    printf("\t\t2.\t\tLOGIN PAGE\n\n");
    printf("\t\t3.\t\tEXIT PAGE\n\n");

    printf("\t\tENTER YOUR CHOICE:\t");
    scanf("%d", &num);
    fflush(stdin); // Also use fgetc(stdin); to remove buffer
    printf("\n\n");

    switch (num)
    {

    case 1:
        while (1)
        {
            system("cls");
            printf("\n____________________SIGN UP____________________\n");
            printf("\n\tEnter Full Name:\t");
            take_input(s_user.full_name);
            printf("\n");
            printf("\tEnter Email:\t");
            take_input(s_user.email_id);
            printf("\n");
            printf("\tEnter Phone Number:\t");
            take_input(s_user.phone_number);
            printf("\n");
            printf("\tEnter Password:\t");
            covert_password(s_user.password);
            printf("\n\n");
            printf("\tConfirm Your Password:\t");
            covert_password(confirm_password);
            printf("\n\n");

            if (strcmp(s_user.password, confirm_password) == 0)
            {
             generate_username(s_user.email_id, s_user.username);
             details_checker(s_user);
           
            FILE *file;
            file = fopen("login.bin", "ab+");
            if (file == NULL)
            {
                printf("\n\tSomething Went Wrong Check Your Details Please\n");
            }
            else
            {
                printf("\n\tCongratulation, You Complete The Sign Up Process\n");
                printf("\n\tNOTE YOUR USENAME FOR FUTURE LOGIN:\t%s\n\n", s_user.username);
            }
    
            fwrite(&s_user, sizeof(struct signup), 1, file);
            fclose(file);
                printf("\tPress Any Key For Login Page: \t");
                getchar();
                break;
            }
            else
            {
                printf("\n\tSomething Went Wrong Check Your Details Please\n\n");
                printf("\tPress Any Key For Try Again: \t");
                getchar();
            }
        }
        fflush(stdin);

    case 2:
        while (1)
        {
            system("cls");
            printf("\n____________________LOGIN____________________\n");
            printf("\n\tUserName:\t");
            take_input(l_user.login_username);
            printf("\n");
            printf("\tPassword:\t");
            covert_password(l_user.login_password);
            printf("\n");
            int user_datails = 0;
            FILE *file;
            file = fopen("login.bin", "rb+");
            fseek(file, 0, SEEK_SET);
            while (fread(&s_user, sizeof(struct signup), 1, file))
            {

                if (strcmp(s_user.username, l_user.login_username) == 0)
                {

                    if (strcmp(s_user.password, l_user.login_password) == 0)
                    {
                        system("cls");
                        printf("\n\tCongratulation, You Complete The Login Process\n");
                        printf("\n____________________YOUR DETAILS____________________\n");
                        printf("\n\tName:\t");
                        printf("%s", s_user.full_name);
                        printf("\n\n");
                        printf("\tEmail:\t");
                        printf("%s", s_user.email_id);
                        printf("\n\n");
                        printf("\tPhone Number:\t");
                        printf("%s", s_user.phone_number);
                        printf("\n\n");
                        printf("\tUserName:\t");
                        printf("%s", s_user.username);
                        printf("\n\n");
                        printf("\tPress Any Key To Exit: \t");
                        getch();
                        user_datails = 2;
                        break;
                    }
                    else
                    {
                        user_datails = 1;
                    }
                }
            }
            fclose(file);

            if (user_datails == 1)
            {
                printf("\n\tPlease Enter Valid Password\n\n");
                printf("\tPress Any Key Try Again otherwise Press q Key Exit: \t");
                char c = getch();
                if (c == 'q')
                    break;
            }
            else if (user_datails == 0)
            {
                printf("\n\tYour Username is Not Registered, Please Enter Valid Username\n\n");
                printf("\tPress Any Key Try Again otherwise Press q Key Exit: \t");
                char c = getch();
                if (c == 'q')
                    break;
            }
            else if (user_datails == 2)
            {
                exit(0);
            }
        }
        
        break;
    case 3:
        system("cls");
        printf("\n\n____________________THANKS FOR EXPLORING____________________\n\n");
        printf("\n\n____________________HAVE A GOOD DAY____________________\n\n");
        printf("\t\tPress Any Key To Exit:\t");
        getch();
        break;

    default:
        printf("\n\n____________________PLEASE ENTER VALID NUMBER____________________\n\n");
    }

    return 0;
}
