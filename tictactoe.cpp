#include <iostream>
using namespace std;

class TicTacToe{
    private:
        char board[3][3];
        char p1 ;
        char p2 ;
    public:
        TicTacToe(){
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    board[i][j] = '-';
                }
            }
            p1 = 'O';
            p2 = 'X';
        }
        void showBoard(){
            for(int i = 0; i<3 ; i++){
                for(int j = 0; j<3; j++){
                    cout<<board[i][j];
                    if (j==2){
                        cout<<endl;
                    }
                    else cout<<"  |  ";
                }
                if(i != 2){
                    cout<<"---------------\n";
                }
            }
        }
        void updateBoard(int i, int j, char a){
            board[i][j] = a;
        }
        void getmove(char a){
            int i, j;
            if (a == 'O'){
                cout<<"Player1: ";
                cin>>i>>j;
                while(((i< 1 || i > 3) || (j<1 || j>3))  || (board[i-1][j-1] == 'X') || (board[i-1][j-1] == 'O')){
                    cout<<"Not a valid move try again.\nPlayer1: ";
                    cin>>i>>j;
                }
                updateBoard(i-1,j-1,p1);
            }
            else if (a == 'X'){
                cout<<"Player2: ";
                cin>>i>>j;
                while(((i< 1 || i > 3) || (j<1 || j>3))  || (board[i-1][j-1] == 'O') || (board[i-1][j-1] == 'X')){
                    cout<<"Not a valid move try again.\nPlayer2: "; 
                    cin>>i>>j;
                }
                updateBoard(i-1,j-1,p2);
            }
        }
        int gameEndCheck(){
            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if( board[i][j] == '-')
                    {   
                        return 0;
                    }
                }
            }
            return 1;
        }
        char checkWinner(){
            if ((board[0][0] == board[0][1]&& board[0][1] == board[0][2]&& board[0][2] == 'O') ||
                (board[1][0] == board[1][1]&& board[1][1] == board[1][2]&& board[1][2] == 'O') ||
                (board[2][0] == board[2][1]&& board[2][1] == board[2][2]&& board[2][2] == 'O') ||
                (board[0][0] == board[1][0]&& board[1][0] == board[2][0]&& board[2][0] == 'O') ||
                (board[0][1] == board[1][1]&& board[1][1] == board[2][1]&& board[2][1] == 'O') ||
                (board[0][2] == board[1][2]&& board[1][2] == board[2][2]&& board[2][2] == 'O') ||
                (board[0][0] == board[1][1]&& board[1][1] == board[2][2]&& board[2][2] == 'O') ||
                (board[0][2] == board[1][1]&& board[1][1] == board[2][0]&& board[2][0] == 'O')){
                    
                    return 'O';
            }
            else if ((board[0][0] == board[0][1]&& board[0][1] == board[0][2]&& board[0][2] == 'X') ||
                (board[1][0] == board[1][1]&& board[1][1] == board[1][2]&& board[1][2] == 'X') ||
                (board[2][0] == board[2][1]&& board[2][1] == board[2][2]&& board[2][2] == 'X') ||
                (board[0][0] == board[1][0]&& board[1][0] == board[2][0]&& board[2][0] == 'X') ||
                (board[0][1] == board[1][1]&& board[1][1] == board[2][1]&& board[2][1] == 'X') ||
                (board[0][2] == board[1][2]&& board[1][2] == board[2][2]&& board[2][2] == 'X') ||
                (board[0][0] == board[1][1]&& board[1][1] == board[2][2]&& board[2][2] == 'X') ||
                (board[0][2] == board[1][1]&& board[1][1] == board[2][0]&& board[2][0] == 'X')){
                    
                    return 'X';
            }
            return '-';
            
        }
};

void gameRunner(){
    TicTacToe b1;
    for (int s = 0; s <2; )
    {
        b1.showBoard();
        b1.getmove('O');
        b1.showBoard();
        if (b1.checkWinner() == 'O' || b1.checkWinner() == 'X' ){
            break;
        }
        if (b1.gameEndCheck() == 1){
            cout<<"game ended its a tie";
            break;
        }
        b1.getmove('X');
        if (b1.checkWinner() == 'O' || b1.checkWinner() == 'X' ){
            break;
        }
        if (b1.gameEndCheck() == 1){
            cout<<"game ended its a tie";
            break;
        }
    }
    if (b1.checkWinner() == 'O')
        cout<<"Game ended. Winner is player1.\n";
    else if(b1.checkWinner() == 'X')
        cout<<"Game ended. Winner is player2.\n";
    

}

int main(){
    int x =0;
    while (1){

        cout<<"To play game press 1.\n To exit press any key. \n:- ";
        cin>>x;
        if (x == 1){
            cout<<"Starting Game.\ninfo: starts with player 1 turns 'O'. enter only valid coordinates from 1-3\n";
            gameRunner();
        }
        else
            break;
    }
    return 0;
}