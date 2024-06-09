#include<iostream>
#include<cstdlib>

using namespace std;

void board(char g[9])
{
    system("cls");
    for(int i=0; i<9;i++)
    {
        cout << g[i] << (i%3 == 2 ? "\n" : " ");
    }
}

bool checkWin(char g[9]){
    for(int i=0; i<9; i+=3){
        if(g[i]==g[i+1] && g[i+1]==g[i+2]){
            return true;
        }
    }
    for(int i=0;i<3;i++) {
        if(g[i]==g[i+3] && g[i+3] == g[i+6]){
        return true;
        }
    }
    if(g[0]==g[4] && g[4] == g[8]) {
        return true;
    }
    if(g[2]==g[4] && g[4] == g[6]) {
        return true;
    }
return false;
}


int main() {
    char g[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool h[9] = {0,0,0,0,0,0,0,0,0}, gameOver = 0;
    int turn;
    for(int i=0; i<9 && !gameOver; i++)
    {
        //draw the board
        board(g);
    cout<< "\n" << (i%2==0 ? "X" : "O") << "'s turn\n";
    while(1) {
    cin >> turn;
    if (turn<1 || turn > 9 || h[turn-1])
    {
        cout << "\n Invalid move \n";
    }
    else {
        h[turn - 1] = 1;
        g[turn - 1] = (i%2 == 0 ? 'X' : 'O');
        break;
    }
    }
//check if theres a winner
    if(checkWin(g)){
        board(g);
        cout << "\n " << (i%2==0 ? "X" : "O") << " wins\n";
        gameOver=1;
    }
    }
    if(!gameOver){
    cout<< "\n Draw \n";
    }
return 0;
}