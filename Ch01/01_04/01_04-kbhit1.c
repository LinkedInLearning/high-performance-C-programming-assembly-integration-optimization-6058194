#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

/* check pending keyboard input */
int kbhit(void)
{
	int key;

	ioctl(STDIN_FILENO, FIONREAD, &key);

	return(key);
}

int main()
{
	char a = 'A';

	/* busy loop */
	while(1)
	{
		/* output A through Z */
		putchar(a);
		a++;
		if( a>'Z' )		/* reset */
			a = 'A';

		if( kbhit() )	/* check for key press */
		{
			getchar();	/* clear the buffer */
			break;		/* end the loop */
		}
	}

	return 0;
}
