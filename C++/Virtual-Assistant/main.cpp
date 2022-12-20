/*

VIRTUAL ASSISTANT:

- The main thing of this assistant is it can interact with us.
- I create the program with some if/else statements proper use.
- Virtual Assistant, We can access by only password.
- We can ask the question to it and it speaks the answer.
- Virtual Assistant speaks with the use of software - espeak.
- It can also open the softwares and also open the browser sites.

Question Like: 

hello
who are you?
how are you?
what is time?
open notepad
open chrome
open linkedin
open twitter

NOTE: PassWord is Chitti

*/


#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <ctime>
using namespace std;

void greeting();
void datetime();

int main(){
    
    system("cls");
    string phrase, command;
    const char* charCommand;
    char password[20], ch[100];

    STARTUPINFO startInfo = {0};
    PROCESS_INFORMATION processInfo = {0};

    cout<<"\t<============================================= W E L C O M E ==========================================>"<<endl;
        phrase = "wellcome";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);
    cout<<"\t<============================================= I'M A VIRTUAL ASSISTANT ==========================================>"<<endl;
        phrase = "i am a virtual assistant";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);
    cout<<"\t<============================================= MY NAME IS CHITTI ==========================================>"<<endl;
        phrase = "my name is chitti";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);
    cout<<"\t<============================================= I'M HERE TO HELP YOU ==========================================>"<<endl<<endl;
        phrase = "i am here to help you";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);

    do{

        
        cout << "\n\t ENTER YOUR PASSWORD :- \t";
        phrase = "enter your password";
        command = "espeak \"" + phrase + "\"";
        charCommand = command.c_str();
        system(charCommand);
        gets(password);
        cout << endl;
        

        if(strcmp(password, "chitti") == 0 || strcmp(password, "CHITTI") == 0 || strcmp(password, "Chitti") == 0){
            cout << "\t******************************************************************************************\n";
            cout << "\t CORRECT PASSWORD \t\n";
            cout << "\t******************************************************************************************\n\n";
            phrase = "your password is correct";
            command = "espeak \"" + phrase + "\"";
            charCommand = command.c_str();
            system(charCommand);
            cout << "******************************************************************************************\n\n";

            greeting();
            cout << endl;

            do{        
               cout << "\n******************************************************************************************\n\n";
               cout << "How Can I Help You Sir........\n\n";
               phrase = "how can i help you sir";
               command = "espeak \"" + phrase + "\"";
               charCommand = command.c_str();
               system(charCommand);
               cout << "Enter Your Query :- \t";
               phrase = "enter your query";
               command = "espeak \"" + phrase + "\"";
               charCommand = command.c_str();
               system(charCommand);
               gets(ch);
               cout << "\nHere Is The Result For Your Query >>>>\t";
               
               if(strcmp(ch, "hy") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0 || strcmp(ch, "Hy") == 0 || strcmp(ch, "Hey") == 0){
                cout << "Hello Sir, I am with you, Please Tell Your Problem";
                phrase = "hello sir i am with you please tell your problem";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
               }
               else if(strcmp(ch, "who are you?") == 0 || strcmp(ch, "tell me about yourself") == 0 || strcmp(ch, "about") == 0 || strcmp(ch, "what is your name?") == 0 || strcmp(ch, "What is your name?") == 0 || strcmp(ch, "Who Are You") == 0 || strcmp(ch, "What Is Your Name") == 0 || strcmp(ch, "who are you") == 0 || strcmp(ch, "what is your name") == 0){
                cout << "Hello Sir, I am Your Virtual Assistant, My Name is Chitti";
                phrase = "hello sir i am your virtual assistant my name is chitti";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
               }
               else if(strcmp(ch, "how are you?") == 0 || strcmp(ch, "whatsup") == 0 || strcmp(ch, "whatsup bro") == 0 || strcmp(ch, "what's up") == 0 || strcmp(ch, "How Are You") == 0 || strcmp(ch, "how are you") == 0 ){
                cout << "Hello Sir, I'm Fine, I hope You Are Also Very Well";
                phrase = "hello sir i am fine i hope you are also very well";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
               }
               else if(strcmp(ch, "what is time?") == 0 || strcmp(ch, "what is date?") == 0 || strcmp(ch, "time") == 0 || strcmp(ch, "date") == 0 || strcmp(ch, "What is time?") == 0 || strcmp(ch, "What is date?") == 0 || strcmp(ch, "What Is Time") == 0 || strcmp(ch, "What Is Date") == 0 || strcmp(ch, "what is time") == 0 || strcmp(ch, "what  is date") == 0){
                datetime();
                phrase = "here is your time and date";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
               }
               else if(strcmp(ch, "open notepad") == 0 || strcmp(ch, "Open Notepad") == 0 || strcmp(ch, "Notepad") == 0 || strcmp(ch, "notepad") == 0){
                cout << "Opening NotePad......";
                phrase = "opening notepad";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                CreateProcess(TEXT("c:\\windows\\notepad.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
               }
               else if(strcmp(ch, "open chrome") == 0 || strcmp(ch, "Open Chrome") == 0 || strcmp(ch, "Chrome") == 0 || strcmp(ch, "chrome") == 0){
                cout << "Opening Chrome......";
                phrase = "opening chrome";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                CreateProcess(TEXT("c:\\Program Files\\Google\\Chrome\\Application\\chrome.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
               }
               else if(strcmp(ch, "open microsoft edge") == 0 || strcmp(ch, "Open Microsoft Edge") == 0 || strcmp(ch, "Microsoft Edge") == 0 || strcmp(ch, "microsoft edge") == 0 || strcmp(ch, "open edge") == 0 || strcmp(ch, "Open Edge") == 0 || strcmp(ch, "Edge") == 0 || strcmp(ch, "edge") == 0){
                cout << "Opening Microsoft Edge......";
                phrase = "opening microsoft edge";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                CreateProcess(TEXT("c:\\Program Files (x86)\\Microsoft\\Edge\\Application\\msedge.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
               }
               else if(strcmp(ch, "open firefox") == 0 || strcmp(ch, "Open Firefox") == 0 || strcmp(ch, "Firefox") == 0 || strcmp(ch, "firefox") == 0){
                cout << "Opening FireFox......";
                phrase = "opening firefox";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                CreateProcess(TEXT("c:\\Program Files\\Mozilla Firefox\\firefox.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
               }
               else if(strcmp(ch, "open vscode") == 0 || strcmp(ch, "Open VsCode") == 0 || strcmp(ch, "VsCode") == 0 || strcmp(ch, "vscode") == 0){
                cout << "Opening Visual Studio Code......";
                phrase = "opening virtual studio code";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                CreateProcess(TEXT("c:\\Users\\Patel Karm\\AppData\\Local\\Programs\\Microsoft VS Code\\code.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
               }
               else if(strcmp(ch, "open youtube") == 0 || strcmp(ch, "Open Youtube") == 0 || strcmp(ch, "Youtube") == 0 || strcmp(ch, "youtube") == 0 || strcmp(ch, "open YouTube") == 0 || strcmp(ch, "YouTube") == 0){
                cout << "Opening Youtube......";
                phrase = "opening youtube";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                system("start https:\\\\www.youtube.com\\");
               }
               else if(strcmp(ch, "open instagram") == 0 || strcmp(ch, "Open Instagram") == 0 || strcmp(ch, "Instagram") == 0 || strcmp(ch, "instagram") == 0 || strcmp(ch, "Insta") == 0 || strcmp(ch, "insta") == 0){
                cout << "Opening Instagram......";
                phrase = "opening instagram";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                system("start https:\\\\www.instagram.com\\");
               }
               else if(strcmp(ch, "open twitter") == 0 || strcmp(ch, "Open Twitter") == 0 || strcmp(ch, "Twitter") == 0 || strcmp(ch, "twitter") == 0){
                cout << "Opening Twitter......";
                phrase = "opening twitter";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                system("start https:\\\\www.twitter.com\\");
               }
               else if(strcmp(ch, "open linkedin") == 0 || strcmp(ch, "Open Linkedin") == 0 || strcmp(ch, "Linkedin") == 0 || strcmp(ch, "linkedin") == 0 || strcmp(ch, "open LinkedIn") == 0 || strcmp(ch, "LinkedIn") == 0){
                cout << "Opening LinkedIn......";
                phrase = "opening linked in";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                system("start https:\\\\www.linkedin.com\\");
               }
               else if(strcmp(ch, "bye") == 0 || strcmp(ch, "by") == 0 || strcmp(ch, "exit") == 0 || strcmp(ch, "Exit") == 0 || strcmp(ch, "Bye") == 0 || strcmp(ch, "By") == 0){
                cout << "Good Bye Sir, I Wish My Information Help You, Have A Nice Day";
                phrase = "good bye sir i wish my information help you have a nce day";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
                exit(0);
               }
               else{
                cout<<"Sorry Sir, I could not understand your query please try again !!!";
                phrase = "sorry sir i could not understand your query please try again";
                command = "espeak \"" + phrase + "\"";
                charCommand = command.c_str();
                system(charCommand);
               }
               
               cout << "\n\nPress Any Key For Other Query: \t";
               phrase = "press any key for other query";
               command = "espeak \"" + phrase + "\"";
               charCommand = command.c_str();
               system(charCommand);
               getch();

               cout << "\n";
            }while(1);
        }
        else{
            cout << "\t******************************************************************************************\n";
            cout << "\t INCORRECT PASSWORD \t\n";
            cout << "\t******************************************************************************************\n";
            phrase = "your password is incorrect please enter correct password to talk with me";
            command = "espeak \"" + phrase + "\"";
            charCommand = command.c_str();
            system(charCommand);
        }

        

    }while(1);
    return 0;
}

// To wish user according to time
void greeting(){
// current date and time based on system timeline
time_t now = time(0);
tm * time = localtime(&now);
string phrase, command;
const char* charCommand;
if(time-> tm_hour < 12){
    cout << "\t GOOD MORNING SIR";
    phrase = "good morning sir";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
}
else if(time-> tm_hour > 12 && time-> tm_hour < 16){
    cout << "\t GOOD AFTERNOON SIR";
    phrase = "good afternoon sir";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
}
else if(time-> tm_hour > 16 && time-> tm_hour < 24){
    cout << "\t GOOD EVENING SIR";
    phrase = "good evening sir";
    command = "espeak \"" + phrase + "\"";
    charCommand = command.c_str();
    system(charCommand);
}
}

void datetime(){
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << dt;
}
