/*

MAINTAIN PARKING:

- Total Types Of Vehicle: 2, 3, 4, 6 wheelers vehicles
- 2 wheels 20rs, 3 wheels 30rs, 4 wheels 50rs, 6 wheelers 100rs charge
- Show The Status Of Number Of Vehicle
- Show The Amount Of Gain
- Delete Details For Whole Day Status and Store in File
- Show All Vehicle Info and Parking Info and Store In File and Read
- Also Delete Functionality Of File 

*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

const char* PERSON_FORMAT_IN = "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t\n";
const char* PERSON_FORMAT_OUT = "%s\t%s\t%s\t%s\t%s\t\n";

const char* VEHICLE_FORMAT_IN = "%d\t%d\t%d\t%d\t%d\t%d\n";
const char* VEHICLE_FORMAT_OUT = "%d\t%d\t%d\t%d\t%d\t%d\n";

void two_wv();
void three_wv();
void four_wv();
void six_wv();
void parkin_status(int *, int *, int *, int *);
void store_Vehicle_info();
void display_vehicle();
void store_Parking_info_file(int *, int *, int *, int *);
void display_parking();

int count = 0, amount = 0, *count_locate = &count, *amount_locate = &amount;



struct vehicle_info{
      char owner_name[40], vehicle_name[40], vehicle_number[40], date[20], time[20];
} person, person_read;


struct parking_info{
      int twv, thwv, fwv, swv, store_count, store_amount;
}vehicle, vehicle_read;



void main(){

    static int  count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0;
    int num, *a1 = &count_1, *a2 = &count_2, *a3 = &count_3, *a4 = &count_4;

    while(1){
    system("cls");
    printf("\nPress 1 For Two Wheelers Vehicle\n");
    printf("Press 2 For Three Wheelers Vehicle\n");
    printf("Press 3 For Four Wheelers Vehicle\n");
    printf("Press 4 For Six Wheelers Vehicle\n");
    printf("Press 5 For Show Status\n");    
    printf("Press 6 For Show All Parking Info\n");
    printf("Press 7 For Show All Vehicle Info\n");
    printf("Press 8 For Delete All Data\n");



    
    printf("\nEnter The Number: "); 
    scanf("%d", &num);
    fflush(stdin);
    switch(num){
        case 1:
         count_1++;
         two_wv();
         store_Vehicle_info();
         parkin_status(a1, a2, a3, a4);
         break;
        case 2:
         count_2++;
         three_wv();
         store_Vehicle_info();
         parkin_status(a1, a2, a3, a4);
         break;
        case 3:
         count_3++;
         four_wv();
         store_Vehicle_info();
         parkin_status(a1, a2, a3, a4);
         break;
        case 4:
         count_4++;
         six_wv();
         store_Vehicle_info();
         parkin_status(a1, a2, a3, a4);
         break;
        case 5:
          parkin_status(a1, a2, a3, a4);
          break;
        case 6:
          display_parking();
          break;
        case 7:
          display_vehicle();
          break;
        case 8:
          store_Parking_info_file(a1, a2, a3, a4);
          exit(0);
        break;
        case 1122:
          remove("parking_info.bin");
          printf("\nparking_info.bin File DELETE Successfully\n");
          printf("\nPress Any Key For Entry Page:\t");getch();
        break;
        case 2211:
          remove("vehicle_info.bin");
          printf("\nvehicle_info.bin File DELETE Successfully\n");
          printf("\nPress Any Key For Entry Page:\t");getch();
        break;
        default:
          printf("You Have Entered Wrong Number");
    }

    }

}  

void two_wv(){
    count = count + 1;
    amount = amount + 20;  
}

void three_wv(){
    count = count + 1;
    amount = amount + 30;
}

void four_wv(){
    count = count + 1;
    amount = amount + 50;
}

void six_wv(){
    count = count + 1;
    amount = amount + 100;
}

void parkin_status(int *a1, int *a2, int *a3, int *a4){
     system("cls");
     printf("\nTwo Wheelers Vehicles: %d\n", *a1);
     printf("Three Wheelers Vehicles: %d\n", *a2);
     printf("Four Wheelers Vehicles: %d\n", *a3);
     printf("Six Wheelers Vehicles: %d\n", *a4);
     printf("\nTotal Vehicles: %d\n", count);
     printf("Total Amount Of Gain: %d\n\n\n", amount); 
     printf("\nPress Any Key For Second Entry:\t");getch();
}

void store_Parking_info_file(int *a1, int *a2, int *a3, int *a4){
    vehicle.twv = *a1;
    vehicle.thwv = *a2;
    vehicle.fwv = *a3;
    vehicle.swv = *a4;
    vehicle.store_count = count;
    vehicle.store_amount = amount;

    FILE *file;
    file = fopen("parking_info.bin","ab");
    fprintf(file, VEHICLE_FORMAT_OUT, vehicle.twv, vehicle.thwv, vehicle.fwv, vehicle.swv, vehicle.store_count, vehicle.store_amount);
    fclose(file);

    *a1 = 0;*a2 = 0;*a3 = 0;*a4 = 0;*count_locate = 0;*amount_locate = 0;
}

void display_parking(){
    system("cls");
    FILE *file;
    file = fopen("parking_info.bin","rb");
    fseek(file, 0, SEEK_SET);
    while(fscanf(file, VEHICLE_FORMAT_IN, &vehicle_read.twv, &vehicle_read.thwv, &vehicle_read.fwv, &vehicle_read.swv, &vehicle_read.store_count, &vehicle_read.store_amount) != EOF){
    printf("Two Wheeler: %d\nThree Wheeler: %d\nFour Wheeler: %d\nSix Wheeler: %d\nTotal Vehicles: %d\nAmount Of Gain: %d\n\n", vehicle_read.twv, vehicle_read.thwv, vehicle_read.fwv, vehicle_read.swv, vehicle_read.store_count, vehicle_read.store_amount);
    } 
    fclose(file);
    printf("\nPress Any Key For Second Entry:\t");getch();
}

void store_Vehicle_info(){  
    printf("Enter Name: ");
    gets(person.owner_name);
    printf("Enter Vehicle Name: ");
    gets(person.vehicle_name);
    printf("Enter Vehicle Number: ");
    gets(person.vehicle_number);
    printf("Enter Date: ");
    gets(person.date);
    printf("Enter Time: ");
    gets(person.time);
    
    FILE *file;
    file = fopen("vehicle_info.bin","ab");
    fprintf(file, PERSON_FORMAT_OUT, person.owner_name, person.vehicle_name, person.vehicle_number, person.date, person.time);
    fclose(file);
}

void display_vehicle(){
    system("cls");
    FILE *file;
    file = fopen("vehicle_info.bin","rb");
    fseek(file, 0, SEEK_SET);
    int c;
    while(fscanf(file, PERSON_FORMAT_IN, person_read.owner_name, person_read.vehicle_name, person_read.vehicle_number, person_read.date, person_read.time) != EOF){
    printf("Owner Name: %s\nVehicle Name: %s\nVehicle Number: %s\nDate: %s\nTime: %s\n\n", person_read.owner_name, person_read.vehicle_name, person_read.vehicle_number, person_read.date, person_read.time);
    }
    fclose(file);
    printf("\nPress Any Key For Second Entry:\t");getch();
}
