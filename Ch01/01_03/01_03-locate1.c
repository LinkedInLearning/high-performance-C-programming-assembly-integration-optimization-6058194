#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
	struct winsize w;
	int row,col;

	/* obtain terminal window's dimensions */
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	row = w.ws_row;
	col = w.ws_col;

	/* set the cursor in the center of the screen */
	printf("\e[%d;%dH",row/2,col/2);

	return 0;
}
