#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main()
{
	int key;

	while(1)
	{
		/* check for a key press */
		ioctl(STDIN_FILENO, FIONREAD, &key);
		if( key )
			break;
	}

	while( key )
	{
		getchar();
		key--;
	}

	return 0;
}
