#include <stdio.h>

#define SIZE 8
#define COLOR_WHITE "\e[30;47m"
#define COLOR_CYAN "\e[30;46m"
#define COLOR_OFF "\e[0m"

void chess_board(void)
{
    int row,col;

    for( row=0; row<SIZE; row++ )
    {
        for( col=0; col<SIZE; col++ )
        {
            if( row%2 )
				printf("%s  ",col%2 ? COLOR_WHITE : COLOR_CYAN);
            else
				printf("%s  ",col%2 ? COLOR_CYAN : COLOR_WHITE);
        }
        printf("%s",COLOR_OFF);
        putchar('\n');
    }
}

int main()
{
    chess_board();

    return 0;
}
