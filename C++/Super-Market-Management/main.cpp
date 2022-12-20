/*

SUPER MARKET MANAGEMENT SYSTEM:

- Administrator manage the products details from his/her account.
- Administator can add, edit or remove the products from the product details.
- Buyer can buy a product and also mention the quantity of products.
- Also We show the receipt of purchase

*/

#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class shopping{
      private:
      int pcode;
      float price;
      float dis;
      string pname;

      public:

      void menu();
      void administrator();
      void buyer();
      void add();
      void edit();
      void rem();
      void list();
      void receipt();
};

void shopping :: menu(){
    while(1){
    int choice;
    string username;
    string password;
    system("cls");
    cout << "\n\n\t\t\t\t***********************************\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t     SuperMarket Main Menu         \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t***********************************\n\n";
    cout << "\t\t\t\t 1. Administrator\n";
    cout << "\t\t\t\t 2. Buyer\n";
    cout << "\t\t\t\t 3. Exit\n";
    cout << "\n\t\t\t\t       Enter Your Choice: \t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\t\t\t\tEnter The Username: \t";
        cin >> username;
        cout << endl << "\n\t\t\t\tEnter The Password: \t";
        cin >> password;

        if(username == "supermarket24*7" && password == "password"){
            administrator();
            }
        else{
            cout << "\n\t\t\t\tEnter The Correct UserName and PassWord";
        }
        break;
    case 2:
       buyer();
    break;
    case 3:
    exit(0);
    default:
        cout << "\n\t\t\t\tEnter The Valid Number, Press any key for Try Again and Q For quit\t";
        char k = getch();
        if(k == 'Q' || k == 'q')exit(0);
    }
    }
}

void shopping :: administrator(){
    int choice;
    system("cls");
    cout << "\n\n\t\t\t\t***********************************\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t   SuperMarket Administrator Menu  \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t***********************************\n\n";
    cout << "\t\t\t\t 1. Add The Product\n";
    cout << "\t\t\t\t 2. Modify The Product\n";
    cout << "\t\t\t\t 3. Delete The Product\n";
    cout << "\t\t\t\t 4. Back To Main Menu\n";
    cout << "\n\t\t\t\t       Enter Your Choice: \t";
    cin >> choice;

    switch(choice){

        case 1:
        add();
        break;
        case 2 :
        edit();
        break;
        case 3:
        rem();
        case 4:
        menu();
        break;
        default :
        cout << "\n\t\t\t\tEnter The Valid Number, Press any key for Try Again and Q For quit\t";
        char k = getch();
        if(k == 'Q' || k == 'q')exit(0);
        administrator();
    }

}

void shopping :: buyer(){
    int choice;
    system("cls");
    cout << "\n\n\t\t\t\t***********************************\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t   SuperMarket Buyer Menu  \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t***********************************\n\n";
    cout << "\t\t\t\t 1. Buy A Product\n";
    cout << "\t\t\t\t 2. Back To Main Menu\n";
    cout << "\n\t\t\t\t       Enter Your Choice: \t";
    cin >> choice;
    switch(choice){

        case 1:
        receipt();
        break;
        case 2 :
        menu();
        break;
        default :
        cout << "\n\t\t\t\tEnter The Valid Number, Press any key for Try Again and Q For quit\t";
        char k = getch();
        if(k == 'Q' || k == 'q')exit(0);
        fflush(stdin);
        buyer();
    }
}

void shopping :: add(){
    while(1){
    fstream data;
    int c, token = 0;
    float p, d;
    string n;

    cout << "\n\n\t\t\t\tAdd A New Product\n";
    cout << "\n\n\t\t\t\tEnter The Product Code: ";
    cin >> pcode;
    cout << "\n\n\t\t\t\tEnter The Name Of Product: ";
    cin >> pname;
    cout << "\n\n\t\t\t\tEnter The Price Of Product: ";
    cin >> price;
    cout << "\n\n\t\t\t\tEnter The Discount Of Product: ";
    cin >> dis;

    data.open("products.txt", ios::in);

    if(!data){
        // If file not created
        data.open("products.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else{
        data >> c >> n >> p >> d;
        while(!data.eof()){
            if(c == pcode){
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if(token == 1){
            add();
        }
        else{
        data.open("products.txt", ios::app|ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
        }
        
    }

    cout << "\n\n\t\t\t\tRecord Successfully Inserted";
    cout << "\n\n\t\t\t\tPress Q For Go To Back and Press Another key For Add another Item: \t";
    char k = getch();
        if(k == 'Q' || k == 'q')administrator();
    
    }
}

void shopping :: edit(){    
    while(1){
    system("cls");
    fstream data, data1;
    int c, token = 0;
    float p, d;
    string n;
    cout << "\n\n\t\t\t\tModify Product Details\n";
    cout << "\n\n\t\t\t\tEnter The Product Code: ";
    cin >> c;
    
    data.open("products.txt", ios::in);

    if(!data){
        cout << "\n\n\t\t\t\tFile Does Not Exit";
        cout << "\n\n\t\t\t\tPress Any key For Go To Back: \t";
        char k = getch();
        administrator();
    }
    else{

        data1.open("products-2.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;

        while(!data.eof()){
              if(c == pcode){
                cout << "\n\n\t\t\t\tEnter The New Product Code: ";
                cin >> c;
                cout << "\n\n\t\t\t\tEnter The New Name Of Product: ";
                cin >> n;
                cout << "\n\n\t\t\t\tEnter The New Price Of Product: ";
                cin >> p;
                cout << "\n\n\t\t\t\tEnter The New Discount Of Product: ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
                cout << "\n\n\t\t\t\tRecord Successfully Modified";
                token++;
              }
              else{
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
              }
              data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("products.txt");
        rename("products-2.txt", "products.txt");

        if(token == 0){
            cout << "\n\n\t\t\t\tRecord Not Modified";
        }

    }

    cout << "\n\n\t\t\t\tPress Q For Go To Back and Press Another key For Modify another Item: \t";
    char k = getch();
        if(k == 'Q' || k == 'q')administrator();
    }
}

void shopping :: rem(){
    while(1){
    system("cls");
    fstream data, data1;
    int c, token = 0;
    float p, d;
    string n;
    cout << "\n\n\t\t\t\tDelete Product Details\n";
    cout << "\n\n\t\t\t\tEnter The Product Code: ";
    cin >> c;
    
    data.open("products.txt", ios::in);

    if(!data){
        cout << "\n\n\t\t\t\tFile Does Not Exit";
        cout << "\n\n\t\t\t\tPress Any key For Go To Back: \t";
        char k = getch();
        administrator();
    }
    else{

        data1.open("products-2.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;

        while(!data.eof()){
              if(c == pcode){
                cout << "\n\n\t\t\t\tRecord Successfully Deleted";
                token++;
              }
              else{
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
              }
              data>>pcode>>pname>>price>>dis;
        }

        data.close();
        data1.close();

        remove("products.txt");
        rename("products-2.txt", "products.txt");

        if(token == 0){
            cout << "\n\n\t\t\t\tRecord Not Deleted";
        }

    }
    
    cout << "\n\n\t\t\t\tPress Q For Go To Back and Press Another key For Delete another Item: \t";
    char k = getch();
    if(k == 'Q' || k == 'q')administrator();

    }
}

void shopping :: list(){
    fstream data;
    data.open("products.txt", ios::in);
    cout << "\n\n\t\t\t\tList Of Product Details\n";
    cout << endl << "Product Code \t\t Product Name \t\t Price \t\t Discount\n";
    data >> pcode >> pname >> price >> dis;
    while(!data.eof()){
        cout << pcode << "\t\t\t " << pname << "\t\t\t " << price << "\t\t " << dis << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();

}

void shopping :: receipt(){
    system("cls");
    int arrc[100], arrq[100], c = 0;
    char choice;
    float amount = 0, dis = 0, total = 0;


    cout << "\n\n\t\t\t\tReceipt Details\n";
    fstream data;
    data.open("products.txt", ios::in);

    if(!data){
        cout << "\n\n\t\t\t\tNo Any Record Found";
        cout << "\n\n\t\t\t\tPress Any key For Go TO Back: \t";
        char k = getch();
        buyer();

    }
    else{
        data.close();

        list();
        
    cout << "\n\n\t\t\t\t***********************************\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t       PLEASE PLACE YOUR ORDER     \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t***********************************\n\n";

        do{  
        cout << "\n\n\t\t\t\tEnter The Product Code: ";
        cin >> arrc[c];
        cout << "\n\n\t\t\t\tEnter The Quantity Of Product: ";
        cin >> arrq[c];
        for(int i = 0; i < c; i++){
            if(arrc[c] == arrc[i]){
                cout << "\n\n\t\t\t\tProduct Code is Already Taken";
            }
        }
        c++;
        cout << "\n\n\t\tDo You Want To By Another Product, If Yes The Press Y else Press Another Key\t";
        choice = getch();
        }while(choice == 'Y' || choice == 'y');

    cout << "\n\n\t\t\t\t***********************************\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t      YOUR RECEIPT, COME AGAIN     \n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\t***********************************\n\n";

    cout << "\tProduct Code\tProduct Name\tProduct Quality\tPrice\tAmount\tAmount After Discount\n";
    
    for(int i = 0; i < c; i++){
    data.open("products.txt", ios::in);
    data >> pcode >> pname >> price >> dis;
    
    while(!data.eof()){
        if(pcode == arrc[i]){
            amount = price * arrq[i];
            dis = amount - ((amount*dis)/100);
            total = total + dis;
            cout << "\t\t" << pcode << "\t" << pname << "\t\t\t" << arrq[i] << "\t" << price << "\t" << amount << "\t\t" << dis << endl;
        }
        data >> pcode >> pname >> price >> dis;
        
    }
       data.close();
    }
     
    }
    
    cout << "\n\n\t\t\t\t***********************************\n";
    cout << "\t\t\t\t                                   \n";
    cout << "\t\t\t\tTOTAL AMOUNT = " << total;

    cout << "\n\n\t\t\t\tPress Q For Go To Back and Press Another key For Order another Items: \t";
    char k = getch();
        if(k == 'Q' || k == 'q')buyer();
    receipt();
}

int main(){
    shopping person;
    person.menu();
    return 0;
}

