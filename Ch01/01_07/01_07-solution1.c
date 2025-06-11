#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define clear() printf("\e[H\e[2J")

/* set a character at a specific cursor position */
void putat(col,row,ch)
{
	printf("\e[%d;%dH%c",row,col,ch);
}

/* delay execution for ? milliseconds */
void delay(int milliseconds)
{
	long pause;
	clock_t now,then;

	pause = milliseconds*(CLOCKS_PER_SEC/1000);
	now = then = clock();
	while( now-then < pause )
		now = clock();
}

/* check pending keyboard input */
int kbhit(void)
{
	int key;

	ioctl(STDIN_FILENO, FIONREAD, &key);

	return(key);
}

/* bounce an asterisk around the terminal screen */
int main()
{
	int row_max,col_max,x_pos,y_pos,v_direction,h_direction;
	struct winsize w;

	/* obtain terminal window's dimensions */
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	row_max = w.ws_row;
	col_max = w.ws_col;

	/* initialize the screen */
	clear();
	puts("Press Enter to end");
	x_pos = col_max/2;		/* screen center */
	y_pos = row_max/2;
	v_direction = 1;		/* positive vertical direction */
	h_direction = 1;		/* positive horizontal direction */
	/* remove line buffering */
	setvbuf(stdout,NULL,_IONBF,0);

	/* bounce the asterisk */
	while(1)
	{
		/* terminate on Enter key press */
		if( kbhit() )
		{
			getchar();		/* clear buffer */
			break;
		}

		/* show the asterisk */
		putat(x_pos,y_pos,'*');
		/* pause for 1/8 sec. */
		delay(125);
		/* hide the asterisk for movement */
		putat(x_pos,y_pos,' ');

		/* move the asterisk */
			/* check horizontal position */
		if( x_pos == col_max-1 || x_pos==1 )
			h_direction = -h_direction;
		x_pos += h_direction;
			/* check vertical position */
		if( y_pos == row_max-1 || y_pos==1 )
			v_direction = -v_direction;
		y_pos += v_direction;
	}

	/* clean-up upon exit */
	putat(1,row_max-1,'B');
	puts("ye");

	return 0;
}
