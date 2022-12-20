/*

SCIENTIFIC CALCULATOR:

- BUild A Scientific Calculator
- Many Functions in this Calculator
- At top answer show and also it change when we perform the other mathematical function
- Also Previous and Pre Answer Chech Button Add
- Clear and Exit Button
- If we some function has to take two numbers, if we performed another function in past then it use that answer as one number and take only one number from the user

*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define PI 3.14

void switch_case(double *, int *);
double sum(double *, double *);
double substraction(double *, double *);
double multiplication(double *, double *);
double division(double *, double *);
double reminder(double *, double *);
double powers(double *, double *);
double factorial(double *);
double square(double *);
double cube(double *);
double squareroot(double *);
double rTd(double *);
double dTr(double *);
double logarithm(double *, double *);

int main(){
    double answer_c = 0, *answer = &answer_c;
    int i_c = 1, *i = &i_c;

    while(1){
    system("cls");
    printf("\n\n\t____________________********************SCIENTIFIC CALCULATOR****************____________________\n\n");
    printf("\n\t____________________********************CHOOSE YOUR CHOICE********************____________________\n\n");
    printf("\n\tAnswer: %lf\n\n", *answer);
    printf("\t1.\tAddition\t\t\t2.\tSubstraction\t\t\t3.\tMultiplication\n");
    printf("\t4.\tDivision\t\t\t5.\tReminder\t\t\t6.\tPower\n");
    printf("\t7.\tFactorial\t\t\t8.\tSquare\t\t\t\t9.\tCube\n");
    printf("\t10.\tSquareRoot\t\t\t11.\tRadian and Degree Conversion\n");
    printf("\t12.\tAbsolute Value\t\t\t13.\tInverse\t\t\t\t14.\tPercentage\n");
    printf("\t15.\tSin\t\t\t\t16.\tCos\t\t\t\t17.\tTan\n");
    printf("\t18.\tSin Inverse\t\t\t19.\tCos Inverse\t\t\t20.\tTan Inverse\n");
    printf("\t21.\tLog Base Of 10\t\t\t22.\tLog Base Of e\t\t\t23.\tLog Base Of x\n");
    printf("\t24.\tAntilog Base Of 10\t\t25.\tAntilog Base Of e\t\t26.\tAntilog Base Of x\n");
    printf("\t27.\tExpontial\t\t\t28.\tPrevious Check\t\t\t29.\tPre Check\n");
    printf("\t30.\tClear\t\t\t\t31.\tExit\n");

    switch_case(answer, i);
    
}
    return 0;
}

void switch_case(double *answer, int*i){

    int no;
    static double checker[20] = {0};
    static int k = 3;
    double a, b, c;
    double *num = &a, *num1 = &b, *num2 = &c;
    printf("\n\tEnter Your Choice:\t");scanf("%d", &no);printf("\n\n");

    switch(no){

        case 1:
        if(*i == 1){
            printf("\tEnter The First Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Second Number: \t");
            scanf("%lf", num2);
            *answer = sum(num1, num2);
        }
        else{
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = sum(answer, num);
        }
        (*i)++;
        break;

        case 2:
        if(*i == 1){
            printf("\tEnter The First Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Second Number: \t");
            scanf("%lf", num2);
            *answer = substraction(num1, num2);
        }
        else{
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = substraction(answer, num);
        }
        (*i)++;
        break;

        case 3:
        if(*i == 1){
            printf("\tEnter The First Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Second Number: \t");
            scanf("%lf", num2);
            *answer = multiplication(num1, num2);
        }
        else{
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = multiplication(answer, num);
        }
        (*i)++;
        break;

        case 4:
        if(*i == 1){
            printf("\tEnter The First Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Second Number: \t");
            scanf("%lf", num2);
            *answer = division(num1, num2);
        }
        else{
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = division(answer, num);
        }
        (*i)++;
        break;
        
        case 5:
        if(*i == 1){
            printf("\tEnter The First Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Second Number: \t");
            scanf("%lf", num2);
            *answer = reminder(num1, num2);
        }
        else{
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = reminder(answer, num);
        }
        (*i)++;
        break;

        case 6:
        if(*i == 1){
            printf("\tEnter The First Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Second Number: \t");
            scanf("%lf", num2);
            *answer = powers(num1, num2);
        }
        else{
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = powers(answer, num);
        }
        (*i)++;
        break;

        case 7:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = factorial(num);
        }
        else{
            *answer = factorial(answer);
            printf("\tIf Number is Big Then It Shows Zero\n");
            printf("\tPress Any Key For Answer:\t");getch();
        }
        (*i)++;
        break;

        case 8:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = square(num);
        }
        else{
            *answer = square(answer);
        }
        (*i)++;
        break;

        case 9:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = cube(num);
        }
        else{
            *answer = cube(answer);
        }
        (*i)++;
        break;

        case 10:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = squareroot(num);
        }
        else{
            *answer = squareroot(answer);
        }
        (*i)++;
        break;

        case 11:
        if(*i == 1){
            int m;
            printf("\t1.\tRadian To Degree\n\t2.\tDegree To Radian\n");
            printf("\n");
            printf("\tEnter The Choice: \t");scanf("%d", &m);
            printf("\n");
            if(m == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = rTd(num);
            }
            else if(m == 2){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = dTr(num);
            }
        }
        else{
            int m;
            printf("\t1.\tRadian To Degree\n\t2.\tDegree To Radian\n");
            printf("\n");
            printf("\tEnter The Choice: ");scanf("%d", &m);
            printf("\n");
            if(m == 1){
            *answer = rTd(answer);
            }
            else if(m == 2){
            *answer = dTr(answer); 
            }
        }
        (*i)++;
        break;

        case 12:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            if((*num)<0){(*num) = ((-1)*(*num));}
            *answer = *num;
        }
        else{
            if((*answer)<0){(*answer) = ((-1)*(*answer));}
        }
        (*i)++;
        break;

        case 13:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = (1 / (*num));
        }
        else{
            *answer = (1 / (*answer));
        }
        (*i)++;
        break;

        case 14:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = (*num)/100;
        }
        else{
            *answer = (*answer)/100;
        }
        (*i)++;
        break;

        case 15:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = sin(*num);
        }
        else{
            *answer = sin(*answer);
        }
        (*i)++;
        break;

        case 16:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = cos(*num);
        }
        else{
            *answer = cos(*answer);
        }
        (*i)++;
        break;

        case 17:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = tan(*num);
        }
        else{
            *answer = tan(*answer);
        }
        (*i)++;
        break;
        
        case 18:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = asin(*num);
        }
        else{
            *answer = asin(*answer);
        }
        (*i)++;
        break;

        case 19:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = acos(*num);
        }
        else{
            *answer = acos(*answer);
        }
        (*i)++;
        break;

        case 20:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = atan(*num);
        }
        else{
            *answer = atan(*answer);
        }
        (*i)++;
        break;
        
        case 21:
        if(*i == 1){
            printf("\tEnter Your Argument Number: \t");
            scanf("%lf", num);
            *answer = log10(*num);
        }
        else{
            *answer = log10(*answer);
        }
        (*i)++;
        break;

        case 22:
        if(*i == 1){
            printf("\tEnter Your Argument Number: \t");
            scanf("%lf", num);
            *answer = log(*num);
        }
        else{
            *answer = log(*answer);
        }
        (*i)++;
        break;

        case 23:
        if(*i == 1){
            printf("\tEnter The Argument Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Base Number: \t");
            scanf("%lf", num2);
            *answer = logarithm(num1, num2);
        }
        else{
            printf("\tEnter Your Base Number: \t");
            scanf("%lf", num);
            *answer = logarithm(answer, num);
        }
        (*i)++;
        break;

        case 24:
        if(*i == 1){
            printf("\tEnter Your Exponent Number: \t");
            scanf("%lf", num);
            *answer = pow(10, *num);
        }
        else{
            *answer = pow(10, *answer);
        }
        (*i)++;
        break;
        
        case 25:
        if(*i == 1){
            printf("\tEnter Your Exponent Number: \t");
            scanf("%lf", num);
            *answer = pow(2.718281828, *num);
        }
        else{
            *answer = pow(2.718281828, *answer);
        }
        (*i)++;
        break;

        case 26:
        if(*i == 1){
            printf("\tEnter The Base Number: \t");
            scanf("%lf", num1);
            printf("\n");
            printf("\tEnter The Exponent Number: \t");
            scanf("%lf", num2);
            *answer = pow(*num2, *num1);
        }
        else{
            printf("\tEnter Your Base Number: \t");
            scanf("%lf", num);
            *answer = pow(*num, *answer);
        }
        (*i)++;
        break;
        
        case 27:
        if(*i == 1){
            printf("\tEnter Your Number: \t");
            scanf("%lf", num);
            *answer = exp(*num);
        }
        else{
            *answer = exp(*answer);
        }
        (*i)++;
        break;
        
        case 28:
        printf("\tPreveous Answer = \t%lf\n", *(checker + (*i) - k));
        printf("\tPress Any Key For Again:\t");getch();
        k++;
        break;

        case 29:
        printf("\tPre Answer = \t%lf\n", *(checker + (*i) - k + 1));
        printf("\tPress Any Key For Again:\t");getch();
        k--;
        break;
        
        case 30:
        *answer = 0;*i = 1;
        break;

        case 31:
        exit(0);

        default:
        printf("\tEnter The Valid Choice\n");
        printf("\tPress Any Key For Try Again:\t");getch();
    }

    if((*i) != 1){
        *(checker + (*i) - 2) = *answer;
    }
    else if((*i) == 1){
        k = 3;
        for(int j = 0; j < 20; j++)checker[j] = 0;
    }

}



double sum(double *n1, double *n2){
    return ((*n1) + (*n2));
}

double substraction(double *n1, double *n2){
    return ((*n1) - (*n2));
}

double multiplication(double *n1, double *n2){
    return ((*n1) * (*n2));
}

double division(double *n1, double *n2){
    return ((*n1) / (*n2));
}

double reminder(double *n1, double *n2){
    return ((int)(*n1) % (int)(*n2));
}

double powers(double *n1, double *n2){
    double m;
    if((*n2) < 0){
        (*n2) = ((-1) * (*n2));
        m = 1 / (pow((*n1), (*n2)));
    }
    else {
        m = pow((*n1), (*n2));
    }
    return (m);
}

double factorial(double *n){
    int m = 1;
    for(int i = 1; i <= (int)(*n); i++){m = m * i;}
    return (m);
}

double square(double *n){
    return ((*n) * (*n));
}

double cube(double *n){
    return ((*n) * (*n) * (*n));
}

double squareroot(double *n){
    if((*n) < 0){
        (*n) = (-1) * (*n);
        printf("\tError! ==>  Its Shows Modulus Number Answer, You Have To Add Iota at Last To Covert in Complex Number\n");
        printf("\tEnter Any Key To See Answer: \t");getch();
    }
    return sqrt(*n);
}

double rTd(double *n){
    return ((*n) * (180 / PI));
}

double dTr(double *n){
    return ((*n) * (PI / 180));
}

double logarithm(double *n1, double *n2){
    double c;
    c = (log10(*n1)) / (log10(*n2));
    return c;
}