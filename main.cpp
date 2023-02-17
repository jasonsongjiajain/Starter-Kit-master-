// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT9L 
// Names: Song Jia Jian | Brett Yap V-Ron 
// IDs: 1211104312 | 1211104475 
// Emails: 1211104312@student.mmu.edu.my | 1211104475@student.mmu.edu.my  
// Phones: 010-463 8847 | 016-383 6659 
// ********************************************************* 

// TODO: Fill in the missing information above and delete this line.

#include "pf/helper.h"
#include <iostream>
using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime> // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

void defgame(int &row,int &column, int &zcount ){      //default settings
    cout<<"Default Game Setttings"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Board Rows           :"<<row<<endl;
    cout<<"Board Columns        :"<<column<<endl;
    cout<<"Zombie count         :"<<zcount<<endl;
    return ;
}


void boardsettings(int &row, int &column)     //boardsettings
{
    bool tt=false;
    cout<<"Board Game settings"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Number of Board Rows          : ";
    cin>>row;
     while(row%2==0){
        cout<<"Please enter an odd number: "<<endl;
        cout<<"Number of Board Rows          : ";
        cin>>row;
        
    }
    cout<<"Number of Board Columns       : ";
    cin>>column;
    while(column%2==0){
        cout<<"Please enter an odd number: "<<endl;
        cout<<"Number of Board Columns       : ";
        cin>>column;
        
    }
   
    return ;
   

}

void zombiesettings(int &zcount)       //for zombie count 
{
    cout<<"Zombie Count settings             "<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"Number of zombie count          : ";
    cin>>zcount;
    cout<<endl;

    while(zcount>9){
        cout<<"Invalid input, Please enter a value below 9!";
        cout<<"Number of zombie count                     :";
        cin>>zcount;
        return;
    }
    return ;
}

void settingsupdated(){                              //to see if the settings is updated or not
    cout<<"Settings Updated.           "<<endl;
    system("pause");
    return;
}

void gameselection(int &row, int &column, int &zcount){   //settings updated or not
    char y;
    cout<<"Do you wish to change the game settings(y/n)? =>";
    cin>>y;

    while(y!='y' && y!='n'){
        cout<<"Please enter a valid number !"<<endl;
        cout<<"Do you wish to change the game settings (y/n) =>";
        cin>>y;

    }

    if(y=='y'){
        system("cls");
        boardsettings(row,column);
        zombiesettings(zcount);
        settingsupdated();
        system("cls");
        return;

    }else if(y=='n'){
        system("cls");
        return;
    }
}

void randomposzombie(string **gameboard,int &zcount, int &row, int&column, int **Zombiearr){  //position of zombie 
    
    for(int i=1; i<=zcount; i++){
        int randomrow=rand()%row;
        int randomcolumn=rand()%column;
        if ( gameboard[randomrow][randomcolumn] != to_string(i-1) &&  gameboard[randomrow][randomcolumn] != "A"){
            gameboard[randomrow][randomcolumn]=to_string(i);  //"1"
            Zombiearr[i-1][0]=randomrow;
            Zombiearr[i-1][1]=randomcolumn;
        }else {
            i--;
        }
    }

}
string **generate2DArr(int &row, int &column) 
{
    string **gameboard = new string *[row];
    for (int i = 0; i < row; i++)
    {
        gameboard[i] = new string[column];
    }
    return gameboard;
}

int **zombiearray(int &zcount) 
{
    int **zombiearray = new int *[zcount];
    for (int i = 0; i < zcount; i++)
    {
        zombiearray[i] = new int[2];
    }
    return zombiearray;
}

void generateobject(string **gameboard, int &row, int &column ){
    
    string objects[10] = { " "," "," ","^", "v", "<", ">", "h", "p", "r"};
    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < column; y++)
        {
            gameboard[x][y] = objects[rand()%10];
        }
    }
}


void displaytitle(int &row, int &column){
    if(row>9){
        cout<<" ";
    }
    if(column>10){
        cout<<"     ";
    }else{
        cout<<"   ";
    }
    cout << ".: Alien vs Zombie :." << endl;
    return;
}

void displayborder(int &row, int &column){
    int j=0;
    int i = 0 ;
  cout<<"   ";
  while (j < column)
  {
    cout << "+-" ;
    j = j + 1;
    }
    cout<<"+";
    return;
}

void displaywallncharacter(string **gameboard,int &row, int &column ){
    int j= 0;
    int i=0;
    while (i < row)
    {
        int j=0;
        cout<<endl;
        cout<<setw(2)<<(i+1)<<setw(2);
        
    while (j < column)
        {
            cout << "|"<< gameboard[i][j];
            j = j + 1;
        }
        cout<<"|";
        cout<<endl;
        displayborder(row, column);
        i = i + 1;

    }  
    cout<<endl;
    cout<<"    ";
    while (j < column)
        {
            
            cout<<(j+1)<<setw(2);
            j = j + 1;
        }
        
cout<<endl;
    
return; 
}
int alife(){
    int alienlife= 100 ;
    return alienlife;
}

int aattack(){
    int alienattack = 0;
    return alienattack;
}

int zombieLife(){
    int nozombielife[4]={100, 150, 200, 250};
    int zombielife= nozombielife[rand()%4];
    return zombielife; 
}

int zombieattack(){
    int nozombieattack[5]={10, 15, 20, 25, 30};
    int zombieAttack = nozombieattack[rand()%5];
    return zombieAttack;
}


int zombierange(){
    int nozombierange[5]={1, 2, 3, 4, 5};
    int zombieRange = nozombierange[rand()%5];
    return zombieRange;
}

void displaystatus(int &zcount){
    cout<<" -> Alien   "<<": Life: "<<alife()<<" Attack : "<<aattack()<<endl;
    cout<<endl;
    for(int i=1; i<=zcount; i++){
        cout<<" -> Zombie "<<i<<": Life "<<zombieLife()<< " Attack: "<<zombieattack()<<" Range: "<<zombierange()<<endl;
        cout<<endl;
    }
    
}
void displayboard(string **gameboard, int &row, int &column, int &zcount){
    
    displaytitle(row, column);
    displayborder(row, column);
    displaywallncharacter(gameboard, row, column);
    displaystatus(zcount);
}


void alienup(string **gameboard, int &row, int &column, int &x, int&y ){
        if (x > 0)
        {
            gameboard[x][y]=".";
            x -= 1; 
            gameboard[x][y]="A";
            return ;
        
        
        }
        
    }



void aliendown(string **gameboard, int &row, int &column, int &x, int&y){
  
        if (x < row - 1)
        {
            gameboard[x][y]=".";
            x += 1; 
            gameboard[x][y]="A";
            return ;
        }
}



void alienright(string **gameboard, int &row, int &column, int &x, int&y){
    if (y < column - 1)
        {
            gameboard[x][y]=".";
            y += 1; 
            gameboard[x][y]="A";
            return ;
        }
}

void alienleft(string **gameboard, int &row, int &column, int &x, int&y){
    if (y < column - 1)
        {
            gameboard[x][y]=".";
            y -= 1;
            gameboard[x][y]="A";
            return ;
        }
}

void allcommand(string &command,string **gameboard, int &x, int &y, int &row, int &column){
    cout << "Please enter your command: " ;
    cin >> command;
    if (command == "up")
    {
        alienup(gameboard, row, column, x, y);
        
    }else if (command == "down")
    {
        aliendown(gameboard, row, column, x, y);
        
    }else if (command == "left")
    {
        alienleft(gameboard, row, column, x, y);
        
    }else if (command == "right")
    {
        alienright(gameboard, row, column, x, y);
       
    } 

}



int main(){
    cout << "Assignment (Part 1)" << endl;
    cout << "Let's Get Started!" << endl;
    int row = 5, column = 9, zcount = 1;
    bool quit = false; 
    
    defgame(row,column,zcount);// for default game settings
    gameselection(row,column,zcount);
    int **Zombiearr=zombiearray(zcount);  //initialize zombie array 
    string **gameboard=generate2DArr(row, column);  //initialize gameboard array
    int middlecolumn = column / 2;
    int middlerow = row / 2; //for position "A" use
    generateobject(gameboard, row, column);     //...ramdom object
    gameboard[middlerow][middlecolumn] = "A";
    randomposzombie(gameboard, zcount, row, column, Zombiearr);     //...assign zombie
    
    while(quit!=true){
    system("CLS");
    displayboard(gameboard, row, column, zcount);
    string command;
    allcommand(command, gameboard, middlerow, middlecolumn, row, column);

}
}

   
    
