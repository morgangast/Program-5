#include <stdio.h>

#define XPLAYER 0
#define OPLAYER 1
#define OPEN 32
#define TIEGAME 2
#define LIVEGAME 3


char board[3][3];

//function to display the tic tac toe board
void display()
{

    printf("------------\n");

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {

            printf("| %c ",board[i][j]);

        }

        printf("|\n");

        printf("-------------\n");

    }

}


void initializeBoard()

{

    for(int i=0; i< 3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]= ((48 + i*3 + j )) ;
        }
    }
    display();

}

//instructions for the game 
int instruct()
{
    int choice;
    //print instructions and get choice
    printf("You know the rules. Three in a row, you win. \n May the best wizard win. \n To play, press 1. \n To Exit, press 0. \n Pick your poison : ");

    scanf("%d",&choice);

    if(choice==0)

        return 1;

    else
        initializeBoard();

    return 0;
}

int start()
{
    return instruct();
    //do nothing else
}




int getMove()
{

    int move;
    //get the players move
    scanf("%d",&move);

    return move;

}

int valid(int move)

{
    //is the input valid? let's check and see
    if(move > 8 || move < 0)

        return 0;

    int y = move%3;

    int x=move/3;

    if((board[x][y]=='O') || (board[x][y]=='X'))

        return 0;

    return 1;

}

int checkWin(char choice)

{
    //figure out if anyone has won or not by checking spots on board
    if(board[0][0] == choice && board[0][1] ==choice && board[0][2] == choice)

        return 1;

    if(board[0][0] == choice && board[1][1] ==choice && board[2][2] == choice)

        return 1;

    if(board[1][0] == choice && board[1][1] ==choice && board[1][2] == choice)

        return 1;

    if(board[2][0] == choice && board[2][1] ==choice && board[2][2] == choice)

        return 1;

    if(board[0][1] == choice && board[1][1] ==choice && board[2][1] == choice)

        return 1;

    if(board[0][2] == choice && board[1][2] ==choice && board[2][2] == choice)

        return 1;

    if(board[0][0] == choice && board[1][0] ==choice && board[2][0] == choice)

        return 1;

    if(board[0][2] == choice && board[1][1] ==choice && board[2][0] == choice)

        return 1;

    return 0;

}


//did these hooligans tie?
int checkTie()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j]!='X' || board[i][j]!='O')

                return 0;
        }
    }
    return 1;
}


int checkWinner()
{

    if(checkWin('X')== 1)
        return XPLAYER;

    if(checkWin('O')== 1)
        return OPLAYER;

    if(checkTie() == 1)
        return TIEGAME;

    return LIVEGAME;

}




int main()
{   
    while(1)
    {
        if(start()==1)

            break;
        //whose turn is it anyways? ask for input and get all that jazz
        for(int i=0;i<9; i++)
        {
            if(i%2==0)
            {

                printf("\n\n");

                printf("Player X Turn ");

                int move = getMove();
                //if there move is invalid, let em have it
                while(!valid(move))
                {printf("ERRRRRR. Try a different move, big dog. \n");
                 move=getMove();
                }

                int y=move%3;

                int x=move/3;

                board[x][y]='X';

                display();
            }
            else
            {
                printf("\n\n");

                printf("Player O Turn ");

                int move = getMove();

                while(!valid(move))
                {
                    printf("ERRRRRR. Try a different move, big dog. \n");
                    move=getMove();
                }

                int y=move%3;

                int x=move/3;

                board[x][y]='O';

                display();
            }
            //if x won, give them a nice lil message
            if(checkWinner()== XPLAYER)
            {
                printf("Player X Won...Proud of YOU \n ");
                break;
            }
            //if o won, give them a nice lil message too. we don't discriminate here
            if(checkWinner()== OPLAYER)

            {
                printf("Player O Won...Proud of YOU \n ");
                break;
            }
            //if they tied, destroy them. just kidding. just let them know about it.
            if(checkWinner()== TIEGAME)
            {
                printf("Tie GAME!! Maybe one of you will come out on top next time. ");
                break;
            }

            if(checkWinner()== LIVEGAME)
            {
                printf("Game ON, NERD. \n");
            }
        }
    }
}