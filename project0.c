#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>

struct BYTE
{
	unsigned char c;
	
	int count;
};
typedef struct BYTE BYTE;


int main()
{
       	int n;
	
	unsigned char *buf = (char *) malloc (1000000 *  sizeof(char));



	int i = 0;
	int g = 0;
	

        while((n = read(0, buf, 1)) > 0)
	{
		buf[i] = *buf;
		i++;
	}

	BYTE b[i];
	

	
	
        const unsigned char sevenpos = 0b10000000;
        const unsigned char sixpos = 0b01000000;
        const unsigned char fivepos = 0b00100000;
        const unsigned char fourpos = 0b00010000;




	unsigned int o;

	
	int yeet = 0;
	int k = 0;
	unsigned char y;

	for (int q = 0; q < i; q++)
	{
		int temp = q;
		unsigned char c = buf[q];
		
		if (c & sevenpos && c & sixpos && c & fivepos && c & fourpos)
		{
			//proceed to allocate next three bytes
			unsigned char p = buf[q+1];
			unsigned char u = buf[q+2];
			unsigned char w = buf[q+3];

		}
		else if (c & sevenpos && c & sixpos && c & fivepos)
		{

			
		}
		else if (c & sevenpos && c & sixpos)//if it is a two byte char
		{
			unsigned char p = buf[q+1];
			y = 256 * c + p;
			for (int d = 0; d < k; d++)
			{
				if (y == b[d].c)
				{
					q++;
					break;
				}
				else if (y != b[d].c && d == k - 1)
				{
					
					for (int t = 0; t < i; t++)
					{
						if (c == buf[t] && p == buf[t+1])
						{
							
							yeet++;
						}
					}
					
					b[k].c = y;
					b[k].count = yeet;
					yeet = 0;
					k++;
					q++;
					q++;
					break;
					
				}
			}
		}
		
		
		if (k < 1)
		{
			b[k].c = c;
			for (int p = 0; p < i; p++)
			{
				if (c == buf[p])
				{
					yeet++;
				}
			}
			b[k].count = yeet;
			k++;
			yeet = 0;
		}
		else if (temp == q)//if q hasnt changed
		{
			for (int d = 0; d < k; d++)
			{
			       	if (c == b[d].c)
				{
					
					break;
				}
				else if (c != b[d].c && d == k - 1)
				{
					
					for (int p = 0; p < i; p++)
					{
						if (c == buf[p])
						{
                                                	yeet++;
						}
					}
					
					b[k].c = c;
					b[k].count = yeet;//set count value
					yeet = 0;//reset count value
                                	k++;//increment
					break;
                        	}
                	}

		}
	}

	int comp (const void *left, const void *right)
	{
		if (((BYTE *)left)->count > ((BYTE *)right)->count)
		{
			return -1;
		}
		else if (((BYTE *)left)->count < ((BYTE *)right)->count)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	qsort(b, k, sizeof(BYTE), comp);
	
	
	for (int a = 0; a < k; a++)
	{
		printf("%c->%d\n", b[a].c, b[a].count);
	}

	

       	return 0;
}

