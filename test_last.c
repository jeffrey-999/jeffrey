#include <unistd.h>

int check(char b[4][4], int k, int i, int z)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (b[k][j] == z + 48)
			return 0;
		j++;
	}
	j = 0;
	while (j < 4)
	{
		if (b[j][i] == z + 48)
			return 0;
		j++;
	}
	return 1;
}

int checkskyup(char *a, char b[4][4], int i, int k, int count)
{
	char s;

	while (k < 4)
	{
		s = b[k][i];
		while (i < 4)
		{
			if (s < b[k][i])
			{
				count++;
				s = b[k][i];
			}
			i++;
		}
		if (count + 48 != *(a + k))
		{
			return 0;
		}
		k++;
		i = 0;
		count = 1;
	}
	return 1;
}

int checkskydown(char *a, char b[4][4], int i, int k, int count)
{
	char s;
	
	while (k < 4)
	{
		s = b[k][3 - i];
		while (3 - i > -1)
		{
			if (s < b[k][3 - i])
			{
				count++;
				s = b[k][3 - i];
			}
			i++;
		}
		if (count + 48 != *(a + k + 4))
		{
			return 0;
		}
		k++;
		i = 0;
		count = 1;
	}
	return 1;
}

int checkskyleft(char *a, char b[4][4], int i, int k, int count)
{
	char s;

	while (i < 4)
	{
		s = b[k][i];
		while (k < 4)
		{
			if (s < b[k][i])
			{
				count++;
				s = b[k][i];
			}
			k++;
		}
		if (count + 48 != *(a + i + 8))
			return 0;
		i++;
		k = 0;
		count = 1;
	}
	return 1;
}

int checkskyright(char *a, char b[4][4], int i, int k, int count)
{
	char s;

	while (i < 4)
	{
		s = b[3 - k][i];
		while (3 - k > -1)
		{
			if (s < b[3 - k][i])
			{
				count++;
				s = b[3 - k][i];
			}
			k++;
		}
		if (count + 48 != *(a + i + 12))
			return 0;
		i++;
		k = 0;
		count = 1;
	}
	return 1;
}

int checksky(char *a, char b[4][4])
{
	int i;
	int k;
	int count;

	i = 0;
	k = 0;
	count = 1;
	if (checkskyup(a, b, i, k, count) == 0)
		return 0;
	if (checkskydown(a, b, i, k, count) == 0)
		return 0;
	if (checkskyleft(a, b, i, k, count) == 0)
		return 0;
	if (checkskyright(a, b, i, k, count) == 0)
		return 0;
	return 1;
}

int sky(char *a, char b[4][4]);

int sky_2(char *a, char b[4][4], int i, int k)
{
	if (b[k][i] == 0)
	{
		int z = 4;
		while (z > 0)
		{
			if (check(b, k, i, z) == 1)
			{
				b[k][i] = z + 48;
				if (sky(a, b) == 1)
					return 1;
				b[k][i] = 0;
			}
			z--;
		}
		return 0;
	}
	return 2;
}

int sky(char *a, char b[4][4])
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			if (sky_2(a, b, i, k) == 0)
				return 0;
			if (sky_2(a, b, i, k) == 1)
				return 1;
			k++;
		}
		i++;
	}
	if (checksky(a, b) == 0)
		return 0;
	return 1;
}

void print(char *a, char b[4][4])
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < 4) // 답 출력
	{
		while (k < 4)
		{
			write(1, &b[k][i], 1);
			k++;
		}
		i++;
		k = 0;
		write(1, "\n", 1);
	}
}

int main(int argc, char* argv[])
{
	char A[16]={'1','2','3','2','3','2','1','2','1','3','2','3','4','1','2','2'};
	char B[4][4]; // 답을 넣을 칸
	int i;

	i = 0;
	/*
	while (i < 16)
	{
		A[i] = *argv[i];
		i++;
	}
	*/
	sky(A, B);
	print(A, B);
}

