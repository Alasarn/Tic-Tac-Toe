#include <iostream>
#include <array>
#include <cstring>
using namespace std;

class Cell
{
private:
    int inside;

public:

    void setValue(int value)
    {
        if(value == 1 || value == 2)
            inside = value;
    }
    int getInside() { return inside;}

    Cell()
    {
        inside = 0;
    }

};

void resetGame()
{
}

bool gameEnd(array<array<Cell,3>,3> &grid)
{

    //line check
    for(int column = 0; column < 3; column++)
        if((grid[0][column].getInside() == grid[1][column].getInside()) &&  (grid[1][column].getInside() == grid[2][column].getInside()))
        {
            if(grid[0][column].getInside() != 0)
                 return true;
        }


    //column check
    for(int line = 0; line < 3; line++)
        if((grid[line][0].getInside() == grid[line][1].getInside())&&(grid[line][1].getInside() == grid[line][2].getInside()))
        {
            if(grid[line][0].getInside() != 0)
                return true;
        }

    //1st diagonal
    if((grid[0][0].getInside() == grid[1][1].getInside())&&(grid[1][1].getInside() == grid[2][2].getInside()))
    {
        if(grid[0][0].getInside() != 0)
            return true;
    }


    //2nd diagonal
    if((grid[2][0].getInside() == grid[1][1].getInside())&&(grid[1][1].getInside() == grid[0][2].getInside()))
    {
        if(grid[2][0].getInside() != 0)
            return true;
    }
}

void displayGrid(array<array<Cell,3>,3> &grid, array<array<char,3>,3> &gridCell )
{
    for(int line = 0; line < 3; line++)
    {
        cout << " -------------           -------------" << endl;
        for(int column = 0; column < 3; column++)
        {
            if(column == 2)
                cout << " | " << grid[line][column].getInside()<< " |";
            else
                cout << " | " << grid[line][column].getInside();
        }

        cout << "          ";

        for(int column = 0; column < 3; column++)
        {


            if(column == 2)
                cout << " | " << gridCell[line][column]<< " |";
            else
                cout << " | " << gridCell[line][column];
        }
        cout << endl;
    }
    cout << " -------------           -------------" << endl;
}



bool validPick(int cellPick, array<array<Cell,3>,3> &grid, array<array<char,3>,3> &gridCell, bool player)
{
    //conversion from cell number to coordinates and it assigns value

    switch(cellPick){
        case 1:
            if(gridCell[0][0] != ' ')
            {
                grid[0][0].setValue(player+1);
                gridCell[0][0] = ' ';
                return true;
            }
            else
                return false;
        case 2:
                   if(gridCell[0][1] != ' ')
            {
                grid[0][1].setValue(player+1);
                gridCell[0][1] = ' ';
                return true;
            }
            else
                return false;
        case 3:
            if(gridCell[0][2] != ' ')
            {
                grid[0][2].setValue(player+1);
                gridCell[0][2] = ' ';
                return true;
            }
            else
                return false;
        case 4:
            if(gridCell[1][0] != ' ')
            {
                grid[1][0].setValue(player+1);
                gridCell[1][0] = ' ';
                return true;
            }
            else
                return false;
        case 5:
            if(gridCell[1][1] != ' ')
            {
                grid[1][1].setValue(player+1);
                gridCell[1][1] = ' ';
                return true;
            }
            else
                return false;
        case 6:
            if(gridCell[1][2] != ' ')
            {
                grid[1][2].setValue(player+1);
                gridCell[1][2] = ' ';
                return true;
            }
            else
                return false;
        case 7:
            if(gridCell[2][0] != ' ')
            {
                grid[2][0].setValue(player+1);
                gridCell[2][0] = ' ';
                return true;
            }
            else
                return false;
        case 8:
            if(gridCell[2][1] != ' ')
            {
                grid[2][1].setValue(player+1);
                gridCell[2][1] = ' ';
                return true;
            }
            else
                return false;
        case 9:
            if(gridCell[2][2] != ' ')
            {
                grid[2][2].setValue(player+1);
                gridCell[2][2] = ' ';
                return true;
            }
            else
                return false;
        }
}

void startGame()
{
    array<array<Cell,3>,3> grid;
    array<array<char,3>,3> gridCell {'1', '2', '3', '4', '5', '6', '7', '8', '9'};



    int iterations = 0;
    //first display grid
    displayGrid(grid, gridCell);

    while(true)
    {

        //1st player
        int cellPick;
        cout << "Player 1... Insert which cell you want to pick: ";
        do{
            cin >> cellPick;

        }while(!validPick(cellPick, grid, gridCell, 0));

        displayGrid(grid, gridCell);
        iterations++;
        //end condition
        if(gameEnd(grid) == true)
        {
            cout << "\n\n\n\n\n";
            cout << "\t GAME OVER \t GAME OVER \t GAME OVER" << endl;
            cout << "\t PLAYER 1 WINS \t PLAYER 1 WINS \t PLAYER 1 WINS" << endl;

            break;
        }

        if(iterations == 9)
        {
            cout << "\n\n\n\n\n";
            cout << "\t GAME OVER \t GAME OVER \t GAME OVER" << endl;
            cout << "\t STALL \t STALL \t STALL" << endl;

            break;
        }


        //2nd player
        cout << "Player 2... Insert which cell you want to pick: ";
        do{
            cin >> cellPick;

        }while(!validPick(cellPick, grid, gridCell, 1));

        displayGrid(grid, gridCell);
        iterations++;
         //end condition
        if(gameEnd(grid) == true)
        {
            cout << "\n\n\n\n\n";
            cout << "\t GAME OVER \t GAME OVER \t GAME OVER" << endl;
            cout << "\t PLAYER 2 WINS \t PLAYER 2 WINS \t PLAYER 2 WINS" << endl;

            break;
        }

        if(iterations == 9)
        {
            cout << "\n\n\n\n\n";
            cout << "\t GAME OVER \t GAME OVER \t GAME OVER" << endl;
            cout << "\t STALL \t STALL \t STALL" << endl;

            break;
        }
    }
}

int main()
{
    bool endPlay = true;
    while(endPlay)
    {

        startGame();

        cout << "\n Do you want to play again ? (yes/no): ";
        string choice;
        cin >> choice;

        if((choice == "no")||(choice == "No")||(choice == "nO")||(choice == "NO")||(choice == "n")||(choice == "N"))
            endPlay = false;

        for(int i = 0; i < 50; i++)
            cout << endl;
    }

    return 0;
}
