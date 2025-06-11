#include <stdio.h>
#include <string.h>

int main()
{
	char haystack[] = "Was this the face that launch'd a thousand ships";
	char needle[] = "th";
	char *location;

	location = strstr(haystack,needle);
	if( location == NULL)
		puts("String not found");
	else
	{
		printf("String '%s' was found at position %ld\n",
				needle,
				location-haystack+1
			  );
		do
		{
			location = strstr(location+1,needle);
			if( location != NULL )
				printf("String '%s' was found at position %ld\n",
						needle,
						location-haystack+1
					  );
		}
		while( location != NULL );
	}

	return 0;
}
