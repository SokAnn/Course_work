#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
void main(void)
{
	int childpid1, childpid2, childpid3;
	FILE *fin, *fout;
	fin = fopen("in.txt", "rt");
	fout = fopen("out.txt", "rt");
	int n, k;
	int fact1 = 1, fact2 = 1, fact3 = 1;

	printf("Process 0, pid=%d\n",getpid());
	childpid1 = fork();
	if (childpid1 == 0)
	{
		printf("Process 1, pid=%d\n", getpid());
		childpid2 = fork();
		if (childpid2 == 0)
		{
			printf("Process 2, pid=%d\n", getpid());
			childpid3 = fork();
			if (childpid3 == 0)
			{
				printf("Process 3, pid=%d\n", getpid());
				fact3=1;
				if ((n - k) == 0)
					fact3 = 1;
				else if ((n - k) < 0)
					fact3 = -1;
				else if ((n - k) > 0)
					for (int i = 1; i <= (n - k); ++i)
						fact3 *= i;
				printf("Process end\n");
			}
			fact2 = 1;
			if (k == 0)
				fact2 = 1;
			else if (k < 0)
				fact2 = -1;
			else if (k > 0)
				for (int i = 1; i <= k; ++i)
					fact2 *= i;
			printf("Process end\n");
		}
		fact1 = 1;
		if (n == 0)
			fact1 = 1;
		else if (n < 0)
			fact1 = -1;
		else if (n > 0)
			for (int i = 1; i <= n; ++i)
				fact1 *= i;
		printf("Process end\n");
	}
	int fact = fact1 / (fact2*fact3);
	printf("Process end\n");
}
