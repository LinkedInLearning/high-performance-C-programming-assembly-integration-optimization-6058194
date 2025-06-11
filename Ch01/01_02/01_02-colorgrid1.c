#include <stdio.h>

int main()
{
    int fg,bg;


    for( fg=30; fg<38; fg++ )
    {
        for( bg=40; bg<48; bg++ )
        {
            printf("\e[%d;%dm %d:%d ",fg,bg,fg,bg);
        }
        printf("\e[m\n");
    }

    return 0;
}
