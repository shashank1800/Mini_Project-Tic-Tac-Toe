#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void board(char a[3][3]);
int player(int pl_no, char a[3][3]);
char checkStatus(char a[3][3]);

int l=0;

void main()
{
        int count=0,i,j,pl_no;
        char k;
        char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

        for(;;)
        {
            pl_no=count%2;
            board(a);
            player(pl_no,a);
            k=checkStatus(a);
            if(k =='X')
            {
                printf("Player 1 wins\n");
                break;
            }
            else if(k =='O')
            {
                printf("Player 2 wins\n");
                break;
            }
            else if(k =='D')
            {
                printf("Draw");
                break;
            }
            else
                count++;
            clrscr();
        }
        printf("\n\n\n--------------------------------!!Game Over!!--------------------------------\n\n\n");
}

int player(int pl_no, char a[3][3])
{
        int i,j;
        char no;

        for(;;)
        {
            printf("Player %d, enter a number:  ",(pl_no+1));
            scanf(" %c",&no);

            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(a[i][j]==no)
                    {
                        if(pl_no==0)
                            a[i][j]='X';
                        else
                            a[i][j]='O';

                        clrscr();
                        board(a);
                        return 0;
                    }
                }
            }
            printf("\t\t\t  Invalid move !!\n");
        }
}

void board(char a[3][3])
{
    printf("\n\n\n--------------------------------Tic Tac Toe--------------------------------\n\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", a[0][0],a[0][1],a[0][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", a[1][0], a[1][1],a[1][2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", a[2][0],a[2][1],a[2][2]);

    printf("     |     |     \n\n");
}

char checkStatus(char a[3][3])
{
    int i=0,j=0;
    l++;
    for(i=0;i<3;i++)
    {
        if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2])
            return a[i][j];
        if(a[j][i]==a[j+1][i]&&a[j][i]==a[j+2][i])
            return a[j][i];
    }
    if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
        return a[1][1];
    else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
        return a[1][1];
    else if(l==9)
        return 'D';
    else
        return 'N';
}



