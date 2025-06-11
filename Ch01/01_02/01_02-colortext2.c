#include <stdio.h>

#define FG_BLACK   "\e[30m"
#define FG_RED     "\e[31m"
#define FG_GREEN   "\e[32m"
#define FG_YELLOW  "\e[33m"
#define FG_BLUE    "\e[34m"
#define FG_MAGENTA "\e[35m"
#define FG_CYAN    "\e[36m"
#define FG_WHITE   "\e[37m"
#define FG_NORMAL  "\e[m"

int main()
{
    printf("Being color test:\n");
    printf("%sThis is colored text%s\n",FG_BLUE,FG_NORMAL);
    printf("End test\n");

    return 0;
}
