/*

BANK MANAGEMENT SYSTEM:

- Make a Sign Up/ Login Form 
- Sign Up Form fill name, email id, phone number, amount, address, password, confirm password and username
- Then Also Usename Automatic Generate
- Also check that email id already used or not
- Also After Sign Up Go To Login Page
- File Details If Username / Password wrong then show the message to the user
- and After Login Show the details of user
- We Change The Amount and Other Details Except Username
- and also in that all Try Again and Quit Press Key For Action

*/


#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

class Bank
{
private:
    string full_name, address, email_id, password, username, login_username, login_password;
    int phone_number = 0, amount = 0;

public:
    void set_data();
    void set_login_data();
    void update_amount(string);
    void update_info(string);
    void delete_account(string);
};

void Bank ::set_data()
{
    while (1)
    {
        string u, p, f, e, a, confirm_password;
        int ph, am, token = 0;
        system("cls");
        cout << "\n____________________BANK SIGN UP____________________\n";
        cout << "\n\nNOTE: PLEASE DON'T USE ANY SPACE IN ALL THE FIELDS\n";
        cout << "\n\tEnter Full Name:\t";
        cin >> full_name;
        cin.clear();
        fflush(stdin);

        cout << "\n";
        cout << "\tEnter Email:\t";
        cin >> email_id;
        cin.clear();
        fflush(stdin);
        username = email_id;

        cout << "\n";
        cout << "\tEnter Phone Number:\t";
        cin >> phone_number;
        cin.clear();
        fflush(stdin);

        cout << "\n";
        cout << "\tEnter Address:\t";
        cin >> address;
        cin.clear();
        fflush(stdin);

        cout << "\n";
        cout << "\tEnter Amount:\t";
        cin >> amount;
        cin.clear();
        fflush(stdin);

        cout << "\n";
        cout << "\tEnter Password:\t";
        cin >> password;
        cin.clear();
        fflush(stdin);

        cout << "\n";
        cout << "\tConfirm Your Password:\t";
        cin >> confirm_password;
        cin.clear();
        fflush(stdin);

        cout << "\n\n";
        if (password == confirm_password)
        {
            fstream file;

            file.open("login.txt", ios::in);
            if (file)
            {

                file >> u >> p >> f >> e >> ph >> a >> am;
                while (!file.eof())
                {
                    if (e == email_id)
                    {
                        token++;
                        break;
                    }
                    file >> u >> p >> f >> e >> ph >> a >> am;
                }
                file.close();
            }
            if (token == 1)
            {
                cout << "Email Id Already Used To Sign Up";
            }
            else
            {
                file.open("login.txt", ios::app | ios::out);
                file.seekg(0, ios::end);
                file << " " << username << " " << password << " " << full_name << " " << email_id << " " << phone_number << " " << address << " " << amount << " " << endl;
                file.close();

                cout << "\n\n\tCongratulation, You Complete The Sign Up Process\n";
                cout << "\n\tNOTE YOUR USENAME FOR FUTURE LOGIN:\t" << username << endl;
            }

            printf("\tPress Any Key For Login Page: \t");
            getchar();
            break;
        }
        else
        {
            cout << "\n\tSomething Went Wrong Check Your Details Please\n";
            printf("\tPress Any Key For Try Again: \t");
            getchar();
        }
        cin.clear();
        fflush(stdin);
    }
}

void Bank ::set_login_data()
{
    while (1)
    {
        system("cls");
        cout << "\n____________________BANK LOGIN____________________\n";
        cout << "\n\nNOTE: PLEASE DON'T USE ANY SPACE IN ALL THE FIELDS\n";
        cout << "\n\tUserName:\t";
        cin >> login_username;
        cin.clear();
        fflush(stdin);
        cout << "\n";
        cout << "\tPassword:\t";
        cin >> login_password;
        cin.clear();
        fflush(stdin);
        cout << "\n";

        int user_datails = 0;
        string u, p, f, e, a;
        int ph, am;

        fstream file;
        file.open("login.txt", ios::in);
        file >> u >> p >> f >> e >> ph >> a >> am;
        while (!file.eof())
        {
            if (u == login_username)
            {
                if (p == login_password)
                {
                    user_datails = 2;
                    break;
                }
                else
                {
                    user_datails = 1;
                    break;
                }
            }
            file >> u >> p >> f >> e >> ph >> a >> am;
        }
        file.close();

        if (user_datails == 1)
        {
            fflush(stdin);
            cout << "\n\tPlease Enter Valid Password\n\n";
            cout << "\tPress Any Key Try Again otherwise Press q Key Exit: \t";
            char c = getch();
            if (c == 'q')
                break;
        }
        else if (user_datails == 0)
        {
            fflush(stdin);
            cout << "\n\tYour Username is Not Registered, Please Enter Valid Username\n\n";
            cout << "\tPress Any Key Try Again otherwise Press q Key Exit: \t";
            char c = getch();
            if (c == 'q')
                break;
        }
        else if (user_datails == 2)
        {
            system("cls");
            cout << "\n\n\tCongratulation, You Complete The Login Process\n";
            cout << "\n____________________YOUR BANK DETAILS____________________\n";
            cout << "\n\tName:\t";
            cout << f;
            cout << "\n\n";
            cout << "\tEmail:\t";
            cout << e;
            cout << "\n\n";
            cout << "\tPhone Number:\t";
            cout << ph;
            cout << "\n\n";
            cout << "\tAddress:\t";
            cout << a;
            cout << "\n\n";
            cout << "\tAmount:\t\t";
            cout << am;
            cout << "\n\n";
            cout << "\tUserName:\t";
            cout << u;

            cout << "\n\n\n";
            cout << "\tPress 1 For Update Amount\t\n\n";
            cout << "\tPress 2 For Update All Information Except Amount, username\t\n\n";
            cout << "\tPress 3 For Delete All The Information\t\n\n";
            cout << "\tPress Another Key For Exit\t\n\n";
            cout << "\tPress The Key:\t";
            char c = getch();
            switch (c)
            {
            case '1':
                update_amount(u);
            case '2':
                update_info(u);
            case '3':
                delete_account(u);
            default:
                exit(0);
            }
        }
    }
}

void Bank ::update_amount(string u)
{

    system("cls");
    fstream file, file1;
    int am = 0, token = 0;
    cout << "\n\n\t\t\t\tModify Amount Details\n";
    cout << "\n\nNOTE: PLEASE DON'T USE ANY SPACE IN ALL THE FIELDS\n";

    file.open("login.txt", ios::in);

    if (!file)
    {
        cout << "\n\n\t\t\t\tFile Does Not Exit";
        cout << "\n\n\t\t\t\tPress Any key For Go To Sign Up Page: \t";
        char k = getch();
        set_data();
    }
    else
    {

        file1.open("login-2.txt", ios::app | ios::out);

        file >> username >> password >> full_name >> email_id >> phone_number >> address >> amount;

        while (!file.eof())
        {
            if (u == username)
            {
                cout << "\n\n\t\t\t\tEnter The Amount Which You Add or Take(with negative sign): ";
                cin >> am;
                amount = amount + am;
                file1 << " " << username << " " << password << " " << full_name << " " << email_id << " " << phone_number << " " << address << " " << amount << " " << endl;
                cout << "\n\n\t\t\t\tRecord Successfully Modified";
                token++;
            }
            else
            {
                file1 << " " << username << " " << password << " " << full_name << " " << email_id << " " << phone_number << " " << address << " " << amount << " " << endl;
            }

            file >> username >> password >> full_name >> email_id >> phone_number >> address >> amount;
        }

        file.close();
        file1.close();

        remove("login.txt");
        rename("login-2.txt", "login.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t\t\tRecord Not Modified";
        }
    }

    cout << "\n\n\t\t\t\tPress Q For Exit and Press Another key For Login Page: \t";
    char k = getch();
    if (k == 'Q' || k == 'q')
        exit(0);
    getchar();
    set_login_data();
}

void Bank ::update_info(string u)
{

    system("cls");
    fstream file, file1;
    string p, f, e, a, cp;
    int ph, token = 0;
    cout << "\n\n\t\t\t\tModify Account Details\n";
    cout << "\n\nNOTE: PLEASE DON'T USE ANY SPACE IN ALL THE FIELDS\n";

    file.open("login.txt", ios::in);

    if (!file)
    {
        cout << "\n\n\t\t\t\tFile Does Not Exit";
        cout << "\n\n\t\t\t\tPress Any key For Go To Sign Up Page: \t";
        char k = getch();
        set_data();
    }
    else
    {

        file1.open("login-2.txt", ios::app | ios::out);

        file >> username >> password >> full_name >> email_id >> phone_number >> address >> amount;

        while (!file.eof())
        {

            if (u == username)
            {
                cout << "\n\tEnter New Full Name:\t";
                cin >> f;
                cin.clear();
                fflush(stdin);

                cout << "\n";
                cout << "\tEnter New Email:\t";
                cin >> e;
                cin.clear();
                fflush(stdin);

                cout << "\n";
                cout << "\tEnter New Phone Number:\t";
                cin >> ph;
                cin.clear();
                fflush(stdin);

                cout << "\n";
                cout << "\tEnter New Address:\t";
                cin >> a;
                cin.clear();
                fflush(stdin);

                cout << "\n";
                cout << "\tEnter New Password:\t";
                cin >> p;
                cin.clear();
                fflush(stdin);

                cout << "\n";
                cout << "\tConfirm Your New Password:\t";
                cin >> cp;
                cin.clear();
                fflush(stdin);

                cout << "\n\n";
                if (p == cp)
                {
                    file1 << " " << username << " " << p << " " << f << " " << e << " " << ph << " " << a << " " << amount << " " << endl;
                    cout << "\n\n\t\t\t\tRecord Successfully Modified";
                    token++;
                }
                else
                {   
                    file1 << " " << username << " " << password << " " << full_name << " " << email_id << " " << phone_number << " " << address << " " << amount << " " << endl;
                    cout << "\n\n\t\t\t\tPassword Not Matched";
                }
            }
            else
            {
                file1 << " " << username << " " << password << " " << full_name << " " << email_id << " " << phone_number << " " << address << " " << amount << " " << endl;
            }

            file >> username >> password >> full_name >> email_id >> phone_number >> address >> amount;
        }

        file.close();
        file1.close();

        remove("login.txt");
        rename("login-2.txt", "login.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t\t\tRecord Not Modified";
        }
    }

    cout << "\n\n\t\t\t\tPress Q For Exit and Press Another key For Login Page: \t";
    char k = getch();
    if (k == 'Q' || k == 'q')
        exit(0);
    set_login_data();
}

void Bank ::delete_account(string u)
{

    system("cls");
    fstream file, file1;
    int token = 0;
    cout << "\n\n\t\t\t\tDelete Amount Details\n";

    file.open("login.txt", ios::in);

    if (!file)
    {
        cout << "\n\n\t\t\t\tFile Does Not Exit";
        cout << "\n\n\t\t\t\tPress Any key For Go To Sign Up Page: \t";
        char k = getch();
        set_data();
    }
    else
    {

        file1.open("login-2.txt", ios::app | ios::out);

        file >> username >> password >> full_name >> email_id >> phone_number >> address >> amount;

        while (!file.eof())
        {
            if (u == username)
            {
                cout << "\n\n\t\t\t\tRecord Successfully Deleted";
                token++;
            }
            else
            {
                file1 << " " << username << " " << password << " " << full_name << " " << email_id << " " << phone_number << " " << address << " " << amount << " " << endl;
            }

            file >> username >> password >> full_name >> email_id >> phone_number >> address >> amount;
        }

        file.close();
        file1.close();

        remove("login.txt");
        rename("login-2.txt", "login.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t\t\tRecord Not Deleted";
        }
    }

    cout << "\n\n\t\t\t\tPress Any Key For Exit\t";
    getch();
    exit(0);
}

int main()
{

    int num;
    system("cls");
    cout << "\n____________________BANK SIGN UP / LOGIN PAGE____________________\n";
    cout << "\n\t\t1.\t\tSIGN UP PAGE\n\n";
    cout << "\t\t2.\t\tLOGIN PAGE\n\n";
    cout << "\t\t3.\t\tEXIT PAGE\n\n";

    cout << "\t\tENTER YOUR CHOICE:\t";
    cin >> num;
    fflush(stdin); // Also use fgetc(stdin); to remove buffer
    cout << "\n\n";

    Bank user;
    switch (num)
    {

    case 1:
        user.set_data();
        fflush(stdin);
    case 2:
        user.set_login_data();
        break;
    case 3:
        system("cls");
        cout << "\n\n____________________THANKS FOR EXPLORING____________________\n\n";
        cout << "\n\n____________________HAVE A GOOD DAY____________________\n\n";
        cout << "\t\tPress Any Key To Exit:\t";
        getch();
        break;
    default:
        cout << "\n\n____________________PLEASE ENTER VALID NUMBER____________________\n\n";
    }

    return 0;
}