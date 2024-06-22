// 2024 SPRING - CS 204 HOMEWORK 1
// ALANUR ERSOY
// 31955
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// a function to display matrix
void printMatrix(vector<vector<char>> &gameTable)
{
    for (int i = 0 ; i < gameTable.size() ; i++) {
        for (int j = 0 ; j < gameTable[i].size() ; j++) {
            cout << gameTable[i][j] ;
        }
        cout << endl ;
    }
}

// checks if every row has same number of characters or not
bool checkConsistency(vector<vector<char>> gameTable)
{
    for (int i = 0 ; i < gameTable.size() ; i++) {

        if(gameTable[0].size() != gameTable[i].size())
        {
            return false ;
        }
    }
    return true ;
}

// checks if there exist a character other than 'u', 'd', 'l', 'r', '-'
bool checkIfOtherLettersExist(vector<vector<char>> gameTable)
{
    for (int i = 0 ; i < gameTable.size() ; i++) {
        for (int j = 0 ; j < gameTable[i].size() ; j++) {
            if(!(gameTable[i][j] == 'l' || gameTable[i][j] == 'r' || gameTable[i][j] == 'u' || gameTable[i][j] == 'd' || gameTable[i][j] == '-'))
            {
                return false ;
            }
        }
    }
    return true ;
}

// checks if the matrix is empty (all '-'s like "inp2.txt")
bool checkIfEmpty(vector<vector<char>> gameTable)
{
    for (int i = 0 ; i < gameTable.size() ; i++) {
        for (int j = 0 ; j < gameTable[i].size() ; j++) {
            if(gameTable[i][j] != '-')
            {
                return true ;
            }
        }
    }
    return false ;
}

// checks if user inputs for row and column is valid or not
bool checkIndices(vector<vector<char>> gameTable, int rowTile, int colTile)
{
    if(gameTable.size() <= rowTile || rowTile < 0)
    {
        return false ;
    }
    if(gameTable[0].size() <= colTile || colTile < 0)
    {
        return false ;
    }
    return true ;
}

// these caseLeft, caseRight, caseUp and caseDown functions are for the program flow. Each of them carries the letters to correct directions
// for instance in caseLeft, it initially checks whether 'l' is on the 0th index column or not, if it is on the 0th column it turns to a dash
// then it checks whether 'l's left is empty or not; if its empty it moves, if its not it does not.
// logic is the same for all four functions
void caseLeft(int rowTile, int colTile, vector<vector<char>> &gameTable)
{
    int i = colTile ;
    bool check = true ;
    for(; i >= 0 ; i--)
    {
        if(i == 0)
        {
            gameTable[rowTile][0] = '-' ;
            check = false ;
        }
        else if(gameTable[rowTile][i-1] == '-' && i != 0)
        {
            gameTable[rowTile][i] = '-' ;
            gameTable[rowTile][i-1] = 'l' ;
            check = false ;
        }
        else if(gameTable[rowTile][i-1] != '-' && i != 0)
        {
            if(check == true)
            {
                cout << "No tiles have been moved." << endl ;
                return;
            }
            cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
            return;
        }
    }
    cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
}

void caseRight(int rowTile, int colTile, vector<vector<char>> &gameTable)
{
    int i = colTile ;
    bool check = true ;
    for(; i < gameTable[0].size() ; i++)
    {
        if(i == (gameTable[0].size()-1))
        {
            gameTable[rowTile][gameTable[0].size()-1] = '-' ;
            check = false ;
        }
        else if(gameTable[rowTile][i+1] == '-' && i != gameTable[0].size()-1)
        {
            gameTable[rowTile][i] = '-' ;
            gameTable[rowTile][i+1] = 'r' ;
            check = false ;
        }
        else if(gameTable[rowTile][i+1] != '-' && i != gameTable[0].size()-1)
        {
            if(check == true)
            {
                cout << "No tiles have been moved." << endl ;
                return;
            }
            cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
            return;
        }
    }
    cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
}

void caseUp(int rowTile, int colTile, vector<vector<char>> &gameTable)
{
    int i = rowTile ;
    bool check = true ;
    for(; i >= 0 ; i--)
    {
        if(i == 0)
        {
            gameTable[0][colTile] = '-' ;
            check = false ;
        }
        else if(gameTable[i-1][colTile] == '-' && i != 0)
        {
            gameTable[i][colTile] = '-' ;
            gameTable[i-1][colTile] = 'u' ;
            check = false ;
        }
        else if(gameTable[i-1][colTile] != '-' && i != 0)
        {
            if(check == true)
            {
                cout << "No tiles have been moved." << endl ;
                return ;
            }
            cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
            return;
        }
    }
    cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
}

void caseDown(int rowTile, int colTile, vector<vector<char>> &gameTable)
{
    int i = rowTile ;
    bool check = true ;
    for(; i < gameTable.size() ; i++)
    {
        if(i == (gameTable.size()-1))
        {
            gameTable[gameTable.size()-1][colTile] = '-' ;
            check = false ;
        }
        else if(gameTable[i+1][colTile] == '-' && i != gameTable.size()-1)
        {
            gameTable[i][colTile] = '-' ;
            gameTable[i+1][colTile] = 'd' ;
            check = false ;
        }
        else if(gameTable[i+1][colTile] != '-' && i != gameTable.size()-1)
        {
            if(check == true)
            {
                cout << "No tiles have been moved." << endl ;
                return ;
            }
            cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
            return;
        }
    }
    cout << "Tile at (" << rowTile << "," << colTile << ") has been moved." << endl ;
}

// this function checks all matrix to determine if any possible moves left
// it determines the character in every indices and check if any possible moves left for that one
bool noMorePossibleMoves(vector<vector<char>> gameTable)
{
    for (int row = 0 ; row < gameTable.size() ; row++) {
        for (int col = 0; col < gameTable[row].size(); col++) {
            if(gameTable[row][col] == 'l' && (col != 0))
            {
                if(gameTable[row][col-1] == '-')
                {
                    return true;
                }
            }
            else if(gameTable[row][col] == 'l' && (col == 0))
            {
                return true ;
            }
            else if(gameTable[row][col] == 'r' && (col != gameTable[row].size()-1))
            {
                if(gameTable[row][col+1] == '-')
                {
                    return true;
                }
            }
            else if(gameTable[row][col] == 'r' && (col == gameTable[row].size()-1))
            {
                return true ;
            }
            else if(gameTable[row][col] == 'u' && (row != 0))
            {
                if(gameTable[row-1][col] == '-')
                {
                    return true;
                }
            }
            else if(gameTable[row][col] == 'u' && (row == 0))
            {
                return true ;
            }
            else if(gameTable[row][col] == 'd' && (row != gameTable.size()-1))
            {
                if(gameTable[row+1][col] == '-')
                {
                    return true ;
                }
            }
            else if(gameTable[row][col] == 'd' && (row == gameTable.size()-1))
            {
                return true ;
            }
        }
    }
    return false;
}


int main() {
    string fileName, lines;
    ifstream inputFile ;
    vector<vector<char>> gameTable ;
    int rowTile, colTile ;

    // in this part code is opening the file
    cout << "Please enter the file name:" << endl ;
    cin >> fileName ;
    inputFile.open(fileName.c_str()) ;

    while(inputFile.fail()) // asks for a valid file name until user writes it
    {
        cout << "Could not open the file. Please enter a valid file name:" << endl ;
        cin >> fileName ;
        inputFile.open(fileName.c_str()) ;
    }

    while (getline(inputFile, lines)) // reaading the file and put it in a matrix called "gameTable"
    {
        vector<char> temp ;
        for(int i = 0 ; i < lines.length() ; i++)
        {
            temp.push_back(lines[i]) ;
        }
        gameTable.push_back(temp) ;
    }

    // this part is for input checks, with using functions checking the consistency, valid characters and emptiness
    // if all checks are correct, it continues with row and column inputs (in the else part)
    bool check = true ;
    if(check && !(checkConsistency(gameTable))) {
        cout << "Erroneous file content. Program terminates." ;
        check = false ;
    }
    else if(check && !(checkIfOtherLettersExist(gameTable)))
    {
        cout << "Erroneous file content. Program terminates." ;
        check = false ;
    }
    else if(check && !(checkIfEmpty(gameTable)))
    {
        cout << "The matrix file contains:" << endl ;
        printMatrix(gameTable) ;
        cout << "The matrix is empty." ;
        check = false ;
    }
    else
    {
        cout << "The matrix file contains:" << endl ;
        printMatrix(gameTable) ;

        // while there are possible moves and the matrix is not empty, loop continues
        while(noMorePossibleMoves(gameTable) && checkIfEmpty(gameTable))
        {
            cout << "Please enter the row and column of the tile that you want to move: " << endl;
            cin >> rowTile >> colTile;

            // while incides are correct
            while(!(checkIndices(gameTable, rowTile, colTile)))
            {
                cout << "Invalid row or column index." << endl << "Please enter the row and column of the tile that you want to move: " << endl ;
                cin >> rowTile >> colTile ;
            }

            // determines which char the user inputs and reach the needed functions accordingly
            if(gameTable[rowTile][colTile] == 'l')
            {
                caseLeft(rowTile,colTile,gameTable) ;
                printMatrix(gameTable) ;
            }
            else if(gameTable[rowTile][colTile] == 'r')
            {
                caseRight(rowTile,colTile,gameTable) ;
                printMatrix(gameTable) ;
            }
            else if(gameTable[rowTile][colTile] == 'u')
            {
                caseUp(rowTile, colTile, gameTable);
                printMatrix(gameTable);
            }
            else if(gameTable[rowTile][colTile] == 'd')
            {
                caseDown(rowTile,colTile,gameTable) ;
                printMatrix(gameTable) ;
            }
            else if(gameTable[rowTile][colTile] == '-') {
                cout << "No tiles have been moved." << endl;
                printMatrix(gameTable);
            }
        }

        // if the matrix is empty the program will terminate
        if(!checkIfEmpty(gameTable))
        {
            cout << "The matrix is empty." ;
            return 0 ;
        }

        // if no possible moves left the program will terminate
        else if(!noMorePossibleMoves(gameTable))
        {
            cout << "No more moves are possible."  ;
            return 0 ;
        }

    }

    return 0;
}
