#include <stdio.h>

#define FG_BLACK   "\e[30m"
#define FG_RED     "\e[31m"
#define FG_GREEN   "\e[32m"
#define FG_YELLOW  "\e[33m"
#define FG_BLUE    "\e[34m"
#define FG_MAGENTA "\e[35m"
#define FG_CYAN    "\e[36m"
#define FG_WHITE   "\e[37m"
#define BG_BLACK   "\e[40m"
#define BG_RED     "\e[41m"
#define BG_GREEN   "\e[42m"
#define BG_YELLOW  "\e[43m"
#define BG_BLUE    "\e[44m"
#define BG_MAGENTA "\e[45m"
#define BG_CYAN    "\e[46m"
#define BG_WHITE   "\e[47m"
#define FG_NORMAL  "\e[m"

int main()
{
    printf("Begin color test:\n");
    printf("%s%sThis is colored text%s\n",FG_RED,BG_YELLOW,FG_NORMAL);
    printf("End test\n");

    return 0;
}
