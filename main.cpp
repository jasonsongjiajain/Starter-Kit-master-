
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

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
#include <fstream>
#include <climits>
using namespace std;

class zombie
{
public:
    int zombielife;
    int zombieAttack;
    int zombierange;

    void init(string difficult)
    {
        int nozombielife[6] = {100, 150, 200, 250, 300, 350};
        int nozombieattack[7] = {10, 15, 20, 25, 30, 35, 40};
        int nozombierange[4] = {1, 2, 3, 4};

        if (difficult == "easy")
        {
            zombielife = nozombielife[rand() % 4];
            zombieAttack = nozombieattack[rand() % 5];
            zombierange = nozombierange[rand() % 3];
        }
        else if (difficult == "hard")
        {
            zombielife = nozombielife[rand() % 4 + 2];     // increase life by 50
            zombieAttack = nozombieattack[rand() % 5 + 2]; // increase attack by 5
            zombierange = nozombierange[rand() % 3 + 1];   // increase range by 1
        }
        else
        {
            cout << "Invalid difficulty level. Please enter 'easy' or 'hard'." << endl;
        }
    }

    int Ztakedamage()
    {
        zombielife -= zombieAttack;
        return zombielife;
    }
};

class alien
{
public:
    int alienlife;
    int alienattack;
    bool hasAttacked = false;
    void init()
    {
        alienlife = 100;
        alienattack = 0;
        return;
    }
    int takedamage(int inidamage)
    {
        alienlife -= inidamage;
        return alienlife;
    }

    int increaselife(int life)
    {
        alienlife += 20;
        return alienlife;
    }

    int increaseattack(int attack)
    {
        alienattack += attack;
        return alienattack;
    }
};

void difficulty(string &difficult)
{
    cout << "Level of Difficulty(easy/hard) =>";
    cin >> difficult;

    while (difficult != "easy" && difficult != "hard")
    {
        cout << "Please enter a valid answer!" << endl;
        cout << "Level of Difficulty(easy/hard) =>";
        cin >> difficult;
    }
    return;
}

void defgame(int &row, int &column, int &zcount, string &difficult)
{ // default settings
    cout << "Default Game Settings" << endl;
    cout << "----------------------" << endl;
    cout << "Board Rows           :" << row << endl;
    cout << "Board Columns        :" << column << endl;
    cout << "Zombie count         :" << zcount << endl;
    cout << "Level of Difficulty  :" << difficult << endl;
    return;
}

void boardsettings(int &row, int &column) // boardsettings
{
    bool tt = false;
    cout << "Board Game Settings" << endl;
    cout << "---------------------" << endl;
    cout << "Number of Board Rows          : ";
    cin >> row;
    while (row % 2 == 0)
    {
        cout << "Please enter an odd number: " << endl;
        cout << "Number of Board Rows          : ";
        cin >> row;
    }
    cout << "Number of Board Columns       : ";
    cin >> column;
    while (column % 2 == 0)
    {
        cout << "Please enter an odd number: " << endl;
        cout << "Number of Board Columns       : ";
        cin >> row;
    }

    return;
}

void zombiesettings(int &zcount) // for zombie count
{
    cout << "Zombie Count settings             " << endl;
    cout << "----------------------------------" << endl;
    cout << "Number of zombie count          : ";
    cin >> zcount;
    cout << endl;

    while (zcount > 9)
    {
        cout << "Invalid input, Please enter a value below 9!";
        cout << "Number of zombie count                     :";
        cin >> zcount;
        return;
    }
    return;
}

void settingsupdated()
{ // to see if the settings is updated or not
    cout << "Settings Updated.           " << endl;
    cout << endl;
    system("pause");
    return;
}

void gameselection(int &row, int &column, int &zcount, string &difficult)
{ // settings updated or not
    string y;
    bool valid_input = false;

    while (!valid_input)
    {
        cout << "Do you wish to change the game settings (y/n)? =>";
        cin >> y;
        cout << endl;

        if (y == "y")
        {
            system("cls");
            boardsettings(row, column);
            zombiesettings(zcount);
            difficulty(difficult);
            settingsupdated();
            system("cls");
            return;
        }
        else if (y == "n")
        {
            system("cls");
            return;
        }
        else
        {
            cout << "Please enter 'y' or 'n'." << endl;
        }
    }
}

void randomposzombie(string **gameboard, int &zcount, int &row, int &column, int **Zombiearr)
{ // position of zombie

    for (int i = 1; i <= zcount; i++)
    {
        int randomrow = rand() % row;
        int randomcolumn = rand() % column;
        if (gameboard[randomrow][randomcolumn] != to_string(i - 1) && gameboard[randomrow][randomcolumn] != "A")
        {
            gameboard[randomrow][randomcolumn] = to_string(i); //"1"
            Zombiearr[i - 1][0] = randomrow;
            Zombiearr[i - 1][1] = randomcolumn;
        }
        else
        {
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

void generateobject(string **gameboard, int &row, int &column)
{

    string objects[10] = {" ", " ", " ", "^", "v", "<", ">", "h", "p", "$"}; // additional feature shield which will help to defend the attack once
    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < column; y++)
        {
            gameboard[x][y] = objects[rand() % 10];
        }
    }
}

void displaytitle(int &row, int &column)
{
    if (row > 9)
    {
        cout << " ";
    }
    if (column > 10)
    {
        cout << "     ";
    }
    else
    {
        cout << "   ";
    }
    cout << ".: Alien vs Zombie :." << endl;
    return;
}

void displayborder(int &row, int &column)
{
    int j = 0;
    int i = 0;
    cout << "   ";
    while (j < column)
    {
        cout << "+-";
        j = j + 1;
    }
    cout << "+";
    return;
}

void displaywallncharacter(string **gameboard, int &row, int &column)
{
    int j = 0;
    int i = 0;
    while (i < row)
    {
        int j = 0;
        cout << endl;
        cout << setw(2) << (i + 1) << setw(2);

        while (j < column)
        {
            cout << "|" << gameboard[i][j];
            j = j + 1;
        }
        cout << "|";
        cout << endl;
        displayborder(row, column);
        i = i + 1;
    }
    cout << endl;
    cout << "    ";
    while (j < column)
    {

        cout << (j + 1) << setw(2);
        j = j + 1;
    }

    cout << endl;
    return;
}

void displayboard(string **gameboard, int &row, int &column)
{
    displaytitle(row, column);
    displayborder(row, column);
    displaywallncharacter(gameboard, row, column);
}

string forcommand(string &command)
{
    cout << "Please enter your command -> ";
    cin >> command;
    if(command != "up"&& command != "down"&& command != "left"&& command != "right"&& command != "save"&& command != "load"&& command != "help"&& command != "arrow"&& command != "quit"){
        cout<<"Invalid command! Please enter a valid command !"<<endl;
        cout << "Please enter your command -> ";
        cin >> command;
    }
    
    return command;
}

string alienup(string **gameboard, string &hitnearbyobject, int &row, int &column, int &middlerow, int &middlecolumn, int &zcount)
{
    bool movement = true;
    for (int i = 1; i <= zcount; i++)
    {
        if (gameboard[middlerow - 1][middlecolumn] == to_string(i))
        {
            movement = false;
            hitnearbyobject = to_string(i);
        }
        else
        {
            continue;
        }
    }
    if (middlerow > 0 && movement == true)
    {
        gameboard[middlerow][middlecolumn] = ".";
        middlerow -= 1;
        hitnearbyobject = gameboard[middlerow][middlecolumn];
        gameboard[middlerow][middlecolumn] = "A";
    }
    return hitnearbyobject;
}

string aliendown(string **gameboard, string &hitnearbyobject, int &row, int &column, int &middlerow, int &middlecolumn, int &zcount)
{
    bool movement = true;
    for (int i = 1; i <= zcount; i++)
    {
        if (gameboard[middlerow + 1][middlecolumn] == to_string(i))
        {
            movement = false;
            hitnearbyobject = to_string(i);
        }
        else
        {
            continue;
        }
    }
    if (middlerow < row - 1 && movement == true)
    {
        gameboard[middlerow][middlecolumn] = ".";
        middlerow += 1;
        hitnearbyobject = gameboard[middlerow][middlecolumn];
        gameboard[middlerow][middlecolumn] = "A";
    }
    return hitnearbyobject;
}

string alienright(string **gameboard, string &hitnearbyobject, int &row, int &column, int &middlerow, int &middlecolumn, int &zcount)
{
    bool movement = true;
    for (int i = 1; i <= zcount; i++)
    {
        if (gameboard[middlerow][middlecolumn + 1] == to_string(i))
        {
            movement = false;
            hitnearbyobject = to_string(i);
        }
        else
        {
            continue;
        }
    }
    if (middlecolumn < column - 1 && movement == true) // gaiguo
    {
        gameboard[middlerow][middlecolumn] = ".";
        middlecolumn += 1;
        hitnearbyobject = gameboard[middlerow][middlecolumn];
        gameboard[middlerow][middlecolumn] = "A";
    }
    return hitnearbyobject;
}

string alienleft(string **gameboard, string &hitnearbyobject, int &row, int &column, int &middlerow, int &middlecolumn, int &zcount)
{
    bool movement = true;
    for (int i = 1; i <= zcount; i++)
    {
        if (gameboard[middlerow][middlecolumn - 1] == to_string(i))
        {
            movement = false;
            hitnearbyobject = to_string(i); // my hitnearobject is my string zombie number 1.
        }
        else
        {
            continue;
        }
    }
    if (middlecolumn > 0 && movement == true)
    {
        gameboard[middlerow][middlecolumn] = ".";
        middlecolumn -= 1;
        hitnearbyobject = gameboard[middlerow][middlecolumn]; // my hitnearobject is the object next to it, either "p", "r", " ", "h" or something else
        gameboard[middlerow][middlecolumn] = "A";
    }
    return hitnearbyobject;
}

void helpsettings()
{
    cout << "1. up   ->  Alien move up                        " << endl;
    cout << "2. down ->  Alien move down                      " << endl;
    cout << "3. left ->  Alien move left                      " << endl;
    cout << "4. right->  Alien move right                     " << endl;
    cout << "5. arrow->  Change the arrow object direction    " << endl;
    cout << "6. help ->  Show user manual                     " << endl;
    cout << "7. save ->  Save game                            " << endl;
    cout << "8. load ->  Load previous Game                   " << endl;
    cout << "9. quit ->  Quit the game                        " << endl;
    return;
}

void changearrowdirection(string command, string **gameboard, int &row, int &column, string &updatearrow)
{
    int arrowrow, arrowcolumn;

    string updatedarrow;
    string currentarrow;
    bool invalid = 0;
    do
    {
        invalid = 0;
        cout << "Enter row: ";
        cin >> arrowrow;
        if (arrowrow < 1 || arrowrow > row)
        {
            cout << endl;
            cout << "Invalid row. Row must be between 1 and " << row << ". Try again." << endl;
            invalid = 1;
            continue;
        }
        cout << "Enter column: ";
        cin >> arrowcolumn;
        if (arrowcolumn < 1 || arrowcolumn > column)
        {
            cout << endl;
            cout << "Invalid column. Column must be between 1 and " << column << ". Try again." << endl;
            invalid = 1;
            continue;
        }
        cout << "Enter Direction(up, down, left, right): ";
        cin >> updatearrow;
        if (updatearrow != "up" && updatearrow != "down" && updatearrow != "left" && updatearrow != "right")
        {
            cout << endl;
            cout << "Invalid direction. Direction must be either 'up', 'down', 'left', or 'right'. Try again." << endl;
            invalid = 1;
            continue;
        }
    } while (invalid);

    if (updatearrow == "up")
    {

        updatedarrow = "^";
    }
    else if (updatearrow == "down")
    {

        updatedarrow = "v";
    }
    else if (updatearrow == "left")
    {

        updatedarrow = "<";
    }
    else if (updatearrow == "right")
    {

        updatedarrow = ">";
    }

    // cout<<updatedarrow<<endl;
    // system("pause");

    currentarrow = gameboard[arrowrow - 1][arrowcolumn - 1];
    gameboard[arrowrow - 1][arrowcolumn - 1] = updatedarrow;
    cout << "Arrow " << currentarrow << " is updated to " << updatedarrow << "!" << endl;
    cout << endl;
}

double distance(int &x1, int &y1, int &x2, int &y2) // pythagorous theorum
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void findnearestzombie(string **gameboard, int &zcount, int &row, int &column, vector<zombie> &zombies, int &middlerow, int &middlecolumn, int &damage, int &closestZombieIndex, int **Zombiearr)
{
    double minDistance = INT_MAX;
    closestZombieIndex = 0;
    for (int i = 0; i < zcount; i++)
    {
        double d = distance(Zombiearr[i][0], Zombiearr[i][1], middlerow, middlecolumn);
        if (d < minDistance)
        {
            minDistance = d;
            closestZombieIndex = i;
        }
    }
    int damageRow = Zombiearr[closestZombieIndex][0];
    int damageColumn = Zombiearr[closestZombieIndex][1];
    // gameboard[damageRow][damageColumn] = to_string(damageRow * column + damageColumn);
    cout << "Zombie at (" << damageRow + 1 << ", " << damageColumn + 1 << ") now has " << damage << " damage.\n";
    zombies[closestZombieIndex].zombielife -= 10;

    return;
}

void randomZombieMove(string **gameboard, int zcount, int row, int column, int **Zombiearr, vector<zombie> &zombies)
{
    for (int i = 0; i < zcount; i++)
    {
        if (zombies[i].zombielife <= 0) // check if the zombie's life is 0 or less
        {
            continue; // skip to the next iteration of the loop
        }

        int move = rand() % 4; // generate a random number between 0 and 3
        int prev_row = Zombiearr[i][0];
        int prev_col = Zombiearr[i][1];

        if (move == 0) // move up
        {
            if (prev_row > 0 && gameboard[prev_row - 1][prev_col] != "A") // check if the zombie is not already at the top row and the space above is not occupied by an alien
            {
                Zombiearr[i][0] = prev_row - 1;
                gameboard[prev_row][prev_col] = ".";
                gameboard[prev_row - 1][prev_col] = to_string(i + 1);
                cout << "Zombie " << i + 1 << " moved up." << endl;
            }
            else
            {
                 cout << "Zombie " << i + 1 << " move up and hit the top border or there is alien above it, zombie did not move. "<<endl;
            }
            cout << endl;
            system("pause");
        }
        else if (move == 1) // move down
        {
            if (prev_row < row - 1 && gameboard[prev_row + 1][prev_col] != "A") // check if the zombie is not already at the bottom row and the space below is not occupied by an alien
            {
                Zombiearr[i][0] = prev_row + 1;
                gameboard[prev_row][prev_col] = ".";
                gameboard[prev_row + 1][prev_col] = to_string(i + 1);
                cout << "Zombie " << i + 1 << " moved down." << endl;
            }
            else
            {
                 cout << "Zombie " << i + 1 << " move down and hit the bottom border or there is alien below it, zombie did not move. "<<endl;
            }
            cout << endl;
            system("pause");
        }
        else if (move == 2) // move left
        {
            if (prev_col > 0 && gameboard[prev_row][prev_col - 1] != "A") // check if the zombie is not already at the leftmost column and the space to the left is not occupied by an alien
            {
                Zombiearr[i][1] = prev_col - 1;
                gameboard[prev_row][prev_col] = ".";
                gameboard[prev_row][prev_col - 1] = to_string(i + 1);
                cout << "Zombie " << i + 1 << " moved left." << endl;
            }
            else
            {
                 cout << "Zombie " << i + 1 << " move left and hit the left border or there is alien on the left, zombie did not move "<<endl;
            }
            cout << endl;
            system("pause");
        }
        else // move right
        {
            if (prev_col < column - 1 && gameboard[prev_row][prev_col + 1] != "A") // check if the zombie is not already at the rightmost column and the space to the right is not occupied by an alien
            {
                Zombiearr[i][1] = prev_col + 1;
                gameboard[prev_row][prev_col] = ".";
                gameboard[prev_row][prev_col + 1] = to_string(i + 1);
                cout << "Zombie " << i + 1 << " moved right." << endl;
            }
            else
            {
                cout << "Zombie " << i + 1 << " move right and hit the right border or there is alien on the right , zombie did not move "<<endl;
            }
            cout << endl;
            system("pause");
        }
    }
}
void save_game(string **gameboard, int row, int column, int middlerow, int middlecolumn, alien &Myalien, zombie &Myzombie, vector<zombie> zombies, int &zcount)
{
    ofstream saveFile("saved_game.txt");

    saveFile << "row: " << row << endl;
    saveFile << "column: " << column << endl;
    saveFile << "positionX: " << middlerow << endl;
    saveFile << "positionY: " << middlecolumn << endl;
    saveFile << "alien health: " << Myalien.alienlife << endl;
    saveFile << "alien attack: " << Myalien.alienattack << endl;
    saveFile << "zcount: " << zcount << endl;

    saveFile << "zombie health: ";
    for (int i = 0; i < zcount; i++)
    {
        saveFile << zombies[i].zombielife;
        if (i < zcount - 1)
        {
            saveFile << " ";
        }
    }
    saveFile << endl;

    saveFile << "zombie attack: ";
    for (int i = 0; i < zcount; i++)
    {
        saveFile << zombies[i].zombieAttack;
        if (i < zcount - 1)
        {
            saveFile << " ";
        }
    }
    saveFile << endl;

    saveFile << "zombie range: ";
    for (int i = 0; i < zcount; i++)
    {
        saveFile << zombies[i].zombierange;
        if (i < zcount - 1)
        {
            saveFile << " ";
        }
    }
    saveFile << endl;

    saveFile << "2D Array: " << row << " " << column << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            saveFile << gameboard[i][j];
        }
        saveFile << endl;
    }

    saveFile.close();
    cout << "Game saved successfully." << endl;
    cout<<endl;
    system("pause");
}

void load_game(string **&gameboard, int &row, int &column, int &middlerow, int &middlecolumn, alien &Myalien, zombie &Myzombie, vector<zombie> &zombies, int &zcount)
{
    ifstream saveFile("saved_game.txt");

    string line;

    getline(saveFile, line);
    sscanf(line.c_str(), "row: %d", &row);
    getline(saveFile, line);
    sscanf(line.c_str(), "column: %d", &column);
    getline(saveFile, line);
    sscanf(line.c_str(), "positionX: %d", &middlerow);
    getline(saveFile, line);
    sscanf(line.c_str(), "positionY: %d", &middlecolumn);
    getline(saveFile, line);
    sscanf(line.c_str(), "alien health: %d", &Myalien.alienlife);
    getline(saveFile, line);
    sscanf(line.c_str(), "alien attack: %d", &Myalien.alienattack);
    getline(saveFile, line);
    sscanf(line.c_str(), "zcount: %d", &zcount);

    zombies.clear();
    int zHealth, zAttack, zRange;
    getline(saveFile, line);
    istringstream healthStream(line.substr(14));
    for (int i = 0; i < zcount; i++)
    {
        healthStream >> zHealth;
        zombies.push_back(Myzombie);
        zombies[i].zombielife = zHealth;
    }

    getline(saveFile, line);
    istringstream attackStream(line.substr(14));
    for (int i = 0; i < zcount; i++)
    {
        attackStream >> zAttack;
        zombies[i].zombieAttack = zAttack;
    }

    getline(saveFile, line);
    istringstream rangeStream(line.substr(13));
    for (int i = 0; i < zcount; i++)
    {
        rangeStream >> zRange;
        zombies[i].zombierange = zRange;
    }

    getline(saveFile, line);
    int r, c;
    sscanf(line.c_str(), "2D Array: %d %d", &r, &c);

    gameboard = new string *[r];
    for (int i = 0; i < r; i++)
    {
        gameboard[i] = new string[c];
        getline(saveFile, line);
        for (int j = 0; j < c; j++)
        {
            gameboard[i][j] = line[j];
        }
    }

    row = r;
    column = c;

    saveFile.close();
    cout << "Game loaded successfully." << endl;
    cout<<endl;
    system("pause");

}

void commandalienmovement(string &command, string **gameboard, string &hitnearbyobject, string &pastobject, int &middlerow, int &middlecolumn, int &row, int &column, int &zcount, alien &Myalien, vector<zombie> &zombies, bool quit, zombie &Myzombie)
{
    if (command == "up" && middlerow > 0)
    {
        // Check if the alien is above the zombie
        if (middlerow > 0 && gameboard[middlerow - 1][middlecolumn] == "A")
        {
            // If the alien is present, attack it
            hitnearbyobject = "A";
        }
        else
        {
            // Otherwise, move the alien up
            pastobject = "^";
            hitnearbyobject = alienup(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
        }
    }
    else if (command == "down" && middlerow < row - 1)
    {
        // Check if the alien is below the zombie
        if (middlerow < row - 1 && gameboard[middlerow + 1][middlecolumn] == "A")
        {
            // If the alien is present, attack it
            hitnearbyobject = "A";
        }
        else
        {
            // Otherwise, move the alien down
            pastobject = "v";
            hitnearbyobject = aliendown(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
        }
    }
    else if (command == "left" && middlecolumn > 0)
    {
        // Check if the alien is to the left of the zombie
        if (middlecolumn > 0 && gameboard[middlerow][middlecolumn - 1] == "A")
        {
            // If the alien is present, attack it
            hitnearbyobject = "A";
        }
        else
        {
            // Otherwise, move the zombie to the left
            pastobject = "<";
            hitnearbyobject = alienleft(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
        }
    }
    else if (command == "right" && middlecolumn < column - 1)
    {
        // Check if the alien is to the right of the zombie
        if (middlecolumn < column - 1 && gameboard[middlerow][middlecolumn + 1] == "A")
        {
            // If the alien is present, attack it
            hitnearbyobject = "A";
        }
        else
        {
            // Otherwise, move the zombie to the right
            pastobject = ">";
            hitnearbyobject = alienright(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
        }
    }
    else if (command == "save")
    {
        save_game(gameboard, row, column, middlerow, middlecolumn, Myalien, Myzombie, zombies, zcount);
    }
    else if (command == "load")
    {
        load_game(gameboard, row, column, middlerow, middlecolumn, Myalien, Myzombie, zombies, zcount);
    }
    else if (command == "help")
    {
        helpsettings();
    }
    else if (command == "save")
    {
        save_game(gameboard, row, column, middlerow, middlecolumn, Myalien, Myzombie, zombies, zcount);
    }
    else if (command == "load")
    {
        load_game(gameboard, row, column, middlerow, middlecolumn, Myalien, Myzombie, zombies, zcount);
    }
    
    return;
}

string hitobjectmove(string **gameboard, string &hitnearbyobject, string &pastobject, int &row, int &column, int &middlerow, int &middlecolumn, int &zcount)
{ // if hit arrow object will move the direction of the object

    if (pastobject == "^")
    {
        hitnearbyobject = alienup(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
    }
    else if (pastobject == "v")
    {

        hitnearbyobject = aliendown(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
    }
    else if (pastobject == "<")
    {

        hitnearbyobject = alienleft(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
    }
    else if (pastobject == ">")
    {

        hitnearbyobject = alienright(gameboard, hitnearbyobject, row, column, middlerow, middlecolumn, zcount);
    }
    return hitnearbyobject;
}

void alienAttack(alien &alien, vector<zombie> &zombies, string &hitzombie, int **Zombiearr, string **gameboard, int &row, int &column, string &pastobject, int &middlerow, int &middlecolumn, string &hitnearbyobject)
{
    int nozombie = stoi(hitzombie);
    int zombiehp = zombies[nozombie - 1].zombielife;
    int attack = alien.alienattack;

    int zombierow = Zombiearr[nozombie - 1][0];
    int zombiecolumn = Zombiearr[nozombie - 1][1];

    zombiehp -= attack;
    cout << "Zombie " << nozombie << " faced " << attack << " damage!" << endl;

    if (zombiehp <= 0)
    {
        zombiehp = 0;
        cout << "Zombie " << nozombie << " has been defeated !" << endl;
        gameboard[zombierow][zombiecolumn] = " ";
    }
    else
    {
        pastobject = hitzombie;
    }
    zombies[nozombie - 1].zombielife = zombiehp;
}

string refreshobjectforstone(string &hitnearbyobejct)
{
    srand(time(NULL));
    string object[11] = {" ", " ", " ", "^", "v", "<", ">", "h", "p", "$", "r"};
    string finalobject;
    if (hitnearbyobejct == "r")
    {
        finalobject = object[rand() % 10];
    }
    else
    {
        finalobject = object[rand() % 11];
    }
    return finalobject;
}

string refreshobjectforsurprise(string &hitnearbyobject)
{
    srand(time(NULL));
    string object[2] = {"#", "@"};
    string finalobject;
    if (hitnearbyobject == "$")
    {
        finalobject = object[rand() % 2];
    }
    return finalobject;
}

void functionofobject(string **gameboard, alien &alien, string &pastobject, string &hitnearbyobject, int &zcount, int &row, int &column, int **Zombiearr, int &middlerow, int &middlecolumn, int &damage, int &closestZombieIndex, vector<zombie> &zombies)
{

    string hitZombie;
    for (int i = 1; i <= zcount; i++)
    {
        if (hitnearbyobject == to_string(i))
        {
            hitZombie = to_string(i);
        }
    }

    if (hitnearbyobject == "^")
    {
        cout << "Alien found out a moveup arrow !" << endl;
        cout << "Alien will gain 20 attack points" << endl;
        alien.alienattack += 20; /// plus alien attack
        // keep moving up
        pastobject = "^";
    }
    else if (hitnearbyobject == "v")
    {
        cout << "Alien found out a movedown arrow !" << endl;
        cout << "Alien will gain 20 attack points" << endl;
        alien.alienattack += 20; // plus alien attack
        // keep moving down
        pastobject = "v";
    }
    else if (hitnearbyobject == "<")
    {
        cout << "Alien found out a moveleft arrow !" << endl;
        cout << "Alien will gain 20 attack points" << endl;
        alien.alienattack += 20; // plus alien attack
        // keep moving left
        pastobject = "<";
    }
    else if (hitnearbyobject == ">")
    {
        cout << "Alien found out a moveright arrow !" << endl;
        cout << "Alien will gain 20 attack points" << endl;
        alien.alienattack += 20; // plus alien attack
        // keep moving right
        pastobject = ">";
    }
    else if (hitnearbyobject == "r")
    {
        cout << "Alien hit a rock and stop!" << endl;
        string newobject = refreshobjectforstone(hitnearbyobject);
        gameboard[middlerow][middlecolumn] = newobject;
        cout << "Alien discovers " << newobject << " beneath the rock." << endl;
        if (pastobject == "^")
        {
            middlerow += 1;
        }
        if (pastobject == "v")
        {
            middlerow -= 1;
        }
        if (pastobject == "<")
        {
            middlecolumn += 1;
        }
        if (pastobject == ">")
        {
            middlecolumn -= 1;
        }
        gameboard[middlerow][middlecolumn] = "A";
        // Alien will stop at the rock
    }
    else if (hitnearbyobject == "h")
    {
        cout << "Alien finds a health pack." << endl;
        cout << "Alien's life is increased by 20." << endl;
        if (alien.alienlife + 20 <= 100)
        {
            alien.alienlife += 20;
        }
        else
        {
            alien.alienlife = 100;
        }
    }
    else if (hitnearbyobject == "p")
    {
        cout << "Alien has found a pod!" << endl;
        findnearestzombie(gameboard, zcount, row, column, zombies, middlerow, middlecolumn, damage, closestZombieIndex, Zombiearr);
        cout << "Alien will give " << damage << " damage to the nearest zombie." << endl;
        // Alien will give attack to the nearest zombie
    }
    else if (hitnearbyobject == ".")
    {
        cout << "Alien hit a trail!" << endl;
    }
    else if (hitnearbyobject == hitZombie)
    {
        alienAttack(alien, zombies, hitZombie, Zombiearr, gameboard, row, column, pastobject, middlerow, middlecolumn, hitnearbyobject);
    }
    else if (hitnearbyobject == "$")
    {
        cout << "Alien found a mystery box!" << endl;
        string newmysteryobject = refreshobjectforsurprise(hitnearbyobject);
        cout << "Alien have obtain " << newmysteryobject << " from the mystery box. " << endl;
        if (newmysteryobject == "#")
        {
            alien.alienlife -= 30;
            cout << "Oh no! You receive a damage of 30 :(" << endl;
        }
        else if (newmysteryobject == "@")
        {
            alien.alienlife += 20;
            cout << "Congratulations! You received a health points of 20!" << endl;
            if (alien.alienlife >= 100)
            {
                alien.alienlife = 100;
            }
        }
    }
}

void displaystatus(int &zcount)
{
    for (int i = 0; i < zcount; i++)
    {
        cout << "Zombie " << i << "-> Life: "
             << "Attack: ";
    }
}

void refreshobjectfordot(string **gameBoard, int &row, int &column)
{
    string objects[10] = {" ", " ", "p", "h", ">", "<", "^", "v", "r", "$"};
    int numObjects = sizeof(objects) / sizeof(objects[0]);

    // iterate through all cells on the game board
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (gameBoard[i][j] == ".")
            {
                // generate a random object for this cell
                int randIndex = rand() % numObjects;
                string newObject = objects[randIndex];

                // update the game board with the new object
                gameBoard[i][j] = newObject;
            }
        }
    }
    return;
}

int main()
{
    int row = 5, column = 9, zcount = 1;
    bool quit = false;
    int damage = 10;
    string difficult = "easy";
    srand(time(NULL));

    defgame(row, column, zcount, difficult); // for default game settings
    gameselection(row, column, zcount, difficult);

    int **Zombiearr = zombiearray(zcount); // initialize zombie array

    string **gameboard = generate2DArr(row, column); // initialize gameboard array

    int middlecolumn = column / 2;
    int middlerow = row / 2; // for position "A" use

    generateobject(gameboard, row, column); //...ramdom object

    gameboard[middlerow][middlecolumn] = "A";                   // assign alien
    randomposzombie(gameboard, zcount, row, column, Zombiearr); //...assign zombie

    vector<zombie> zombies(zcount);

    for (int i = 0; i < zcount; i++)
    {
        zombies[i].init(difficult);
    }

    zombie Myzombie;
    alien Myalien;  //
    Myalien.init(); //
                    // int life =20 ;
                    // int attack = 20;
                    // int inidamage = 10;

    bool flag = false;
    string hitnearbyobject;
    string pastobject;
    string updatearrow; // for changing arrow)(string)
    while (quit != true && Myalien.alienlife > 0)
    {
        int life = 20;
        int attack = 20;
        int inidamage = 10;
        int closestZombieIndex = 0;

        system("CLS");
        displayboard(gameboard, row, column);
        cout << "Alien Life: " << Myalien.alienlife << " Attack: " << Myalien.alienattack << endl;
        for (int i = 0; i < zcount; i++)
        {
            cout << "Zombie " << i + 1 << " Life: " << zombies[i].zombielife << " , attack: " << zombies[i].zombieAttack << " , range: " << zombies[i].zombierange << endl;
        }

        string command;
        forcommand(command);
        bool contmove = true;
        if (command == "up" || command == "down" || command == "left" || command == "right")
        {
            commandalienmovement(command, gameboard, hitnearbyobject, pastobject, middlerow, middlecolumn, row, column, zcount, Myalien, zombies, quit, Myzombie);
            functionofobject(gameboard, Myalien, pastobject, hitnearbyobject, zcount, row, column, Zombiearr, middlerow, middlecolumn, damage, closestZombieIndex, zombies);

            cout << endl;
            system("pause");
            system("CLS");
            displayboard(gameboard, row, column);

            while (contmove != false)
            {
                bool allZombiesDead = true;
                for (int i = 0; i < zombies.size(); i++)
                {
                    if (zombies[i].zombielife > 0)
                    {
                        allZombiesDead = false;
                        break;
                    }
                }
                if (hitnearbyobject == "r" || (middlerow == 0 && pastobject == "^") || ((middlerow == row - 1) && pastobject == "v") || (middlecolumn == 0 && pastobject == "<") || (middlecolumn == column - 1 && pastobject == ">") || pastobject <= to_string(zcount) || allZombiesDead)
                {
                    contmove = false;
                    break;
                }
                system("CLS");
                displayboard(gameboard, row, column); // refresh the board before continuous move.
                cout << "Alien Life: " << Myalien.alienlife << " Attack: " << Myalien.alienattack << endl;
                for (int i = 0; i < zcount; i++)
                {
                    cout << "Zombie " << i + 1 << " Life: " << zombies[i].zombielife << " , attack: " << zombies[i].zombieAttack << " , range: " << zombies[i].zombierange << endl;
                }
                cout << endl;
                hitobjectmove(gameboard, hitnearbyobject, pastobject, row, column, middlerow, middlecolumn, zcount);
                functionofobject(gameboard, Myalien, pastobject, hitnearbyobject, zcount, row, column, Zombiearr, middlerow, middlecolumn, damage, closestZombieIndex, zombies);
                cout << endl;
                system("PAUSE");
                system("CLS");
                displayboard(gameboard, row, column);
            }
            system("CLS");
            displayboard(gameboard, row, column); // refresh the board before continuous move.
            cout << "Alien Life: " << Myalien.alienlife << " Attack: " << Myalien.alienattack << endl;
            for (int i = 0; i < zcount; i++)
            {
                cout << "Zombie " << i + 1 << " Life: " << zombies[i].zombielife << " , attack: " << zombies[i].zombieAttack << " , range: " << zombies[i].zombierange << endl;
            }
            Myalien.alienattack = 0;
            randomZombieMove(gameboard, zcount, row, column, Zombiearr, zombies);
            cout << endl;
            system("CLS");
            displayboard(gameboard, row, column);
            bool zombiesAlive = false;
            for (int i = 0; i < zcount; i++)
            {
                if (zombies[i].zombielife > 0)
                {
                    zombiesAlive = true;
                    break;
                }
            }

            if (!zombiesAlive)
            {
                // All zombies are dead, end the game
                cout << "Congratulations, you have defeated all the zombies!\n";
                cout << endl;
                system("pause");
                quit = true;
            }

            for (int i = 0; i < zcount; i++)
            {
                if (zombies[i].zombielife <= 0) // check if the zombie's life is 0 or less
                {
                    continue; // skip to the next iteration of the loop
                }
                int zombierow = Zombiearr[i][0];
                int zombiecolumn = Zombiearr[i][1];
                int range = zombies[i].zombierange;
                if ((middlerow >= zombierow - range) && (middlerow <= zombierow + range) && (middlecolumn >= zombiecolumn - range) && (middlecolumn <= zombiecolumn + range))
                {
                    // Determine which zombie is attacking the alien
                    string zombieName = "Zombie " + to_string(i + 1);

                    // Print message that the alien is in zombie attack range
                    cout << "Alien is in " << zombieName << " attack range! \n";

                    // Attack the alien
                    Myalien.alienlife -= zombies[i].zombieAttack;

                    // Print message that the zombie is attacking the alien
                    cout << zombieName << " attack the alien !\n";

                    // shield(gameboard, Zombiearr, Myalien, zombies, zcount);
                    // Check if the alien is still alive
                    cout << endl;
                    if (Myalien.alienlife <= 0)
                    {
                        cout << "You have been defeated by zombie! You lost the game!\n";
                        cout << endl;
                        system("pause");
                        quit = true;
                        break;
                    }
                    cout << endl;
                    system("pause");
                    system("CLS");
                    displayboard(gameboard, row, column);
                }
            }
        }
        else if (command == "arrow")
        {
            changearrowdirection(command, gameboard, row, column, updatearrow);
            cout << endl;
            system("pause");
        }
        else if (command == "save")
        {
            save_game(gameboard, row, column, middlerow, middlecolumn, Myalien, Myzombie, zombies, zcount);
        }
        else if (command == "load")
        {
            load_game(gameboard, row, column, middlerow, middlecolumn, Myalien, Myzombie, zombies, zcount);
            cout << "row: " << row << "column: " << column;
        }
        else if (command == "quit")
        {
            exit(0);
        }
        else if(command == "help"){
            helpsettings();
            system("Pause");
        }
        refreshobjectfordot(gameboard, row, column);
    }
}