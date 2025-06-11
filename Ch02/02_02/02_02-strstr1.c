#include <stdio.h>
#include <string.h>

int main()
{
	char haystack[] = "Was this the face that launch'd a thousand ships";
	char needle[] = "face";
	char *location;

	location = strstr(haystack,needle);
	if( location == NULL)
		puts("String not found");
	else
	{
		printf("String '%s' was found at position %ld in string \"%s\"\n",
				needle,
				location-haystack+1,
				haystack
			  );
	}

	return 0;
}
