#include <stdio.h>
#include <stdlib.h>

int is_O_line(char a,char b,char c);
int is_X_line(char a,char b,char c);

int main()
{

    char player;
    scanf("%c",&player);
    do
    {
        char board[3][3];
        for(int i=0; i<3; i++)
        {
            scanf("\n%c%c%c",&board[i][0],&board[i][1],&board[i][2]);
        }

        int O_line=0,X_line=0;

        O_line+=is_O_line(board[0][0],board[0][1],board[0][2]);
        X_line+=is_X_line(board[0][0],board[0][1],board[0][2]);

        O_line+=is_O_line(board[1][0],board[1][1],board[1][2]);
        X_line+=is_X_line(board[1][0],board[1][1],board[1][2]);

        O_line+=is_O_line(board[2][0],board[2][1],board[2][2]);
        X_line+=is_X_line(board[2][0],board[2][1],board[2][2]);

        O_line+=is_O_line(board[0][0],board[1][1],board[2][2]);
        X_line+=is_X_line(board[0][0],board[1][1],board[2][2]);

        O_line+=is_O_line(board[0][2],board[1][1],board[2][0]);
        X_line+=is_X_line(board[0][2],board[1][1],board[2][0]);

        O_line+=is_O_line(board[0][0],board[1][0],board[2][0]);
        X_line+=is_X_line(board[0][0],board[1][0],board[2][0]);

        O_line+=is_O_line(board[0][1],board[1][1],board[2][1]);
        X_line+=is_X_line(board[0][1],board[1][1],board[2][1]);

        O_line+=is_O_line(board[0][2],board[1][2],board[2][2]);
        X_line+=is_X_line(board[0][2],board[1][2],board[2][2]);

        if( (O_line == 0) && (X_line == 0))
        {
            printf("Undetermined\n");
        }
        else if( (O_line == 0) || (X_line == 0) )
        {
            if(O_line == 0)
            {
                if(player=='X')
                    printf("Win\n");
                else
                    printf("Lost\n");
            }
            else if(X_line == 0)
            {
                if(player=='O')
                    printf("Win\n");
                else
                    printf("Lost\n");
            }
        }
        else
        {
            printf("Error\n");
        }
    }while( scanf("\n%c",&player)!=EOF );

        return 0;
}

int is_O_line(char a,char b,char c)
{
    if(a==b&&b==c&&a=='O')
        return 1;
    else
        return 0;
}
int is_X_line(char a,char b,char c)
{
    if(a==b&&b==c&&a=='X')
        return 1;
    else
        return 0;
}
