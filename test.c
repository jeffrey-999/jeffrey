#include <unistd.h>

void checkf(char *A, char B[4][4])
{
	//4를 찾고 그 줄에 1, 2, 3, 4 대입
	int i = 0;
	
	while(i < 16)
	{
		if(*(A + i) == '4')
		{
			if(i / 4 == 0)
			{
				B[i % 4][0] = '1';
				B[i % 4][1] = '2';
				B[i % 4][2]	= '3';
				B[i % 4][3] = '4';
			}
			if(i / 4 == 1)
			{
				B[i % 4][3] = '1';
				B[i % 4][2] = '2';
				B[i % 4][1] = '3';
				B[i % 4][0] = '4';
			}
			if(i / 4 == 2)
			{
				B[0][i % 4] = '1';
				B[1][i % 4] = '2';
				B[2][i % 4] = '3';
				B[3][i % 4] = '4';
			}
			if(i / 4 == 3)
			{
				B[3][i % 4] = '1';
				B[2][i % 4] = '2';
				B[1][i % 4] = '3';
				B[0][i % 4] = '4';
			}
		}
		i++;
	}
}

void checko(char *a, char B[4][4])
{
	//1을 착고 그 바로 앞 칸에 4 대입
	int i = 0;

	while(i < 16)
	{
		if(*(a + i) == '1')
		{
			if(i / 4 == 0)
				B[i % 4][0] = '4';
			if(i / 4 == 1)
				B[i % 4][3] = '4';
			if(i / 4 == 2)
				B[0][i % 4] = '4';
			if(i / 4 == 3)
				B[3][i % 4] = '4';
		}
		i++;
	}
}
void checktt(char *a, char b[4][4])
{
	//한 쪽이 2, 반대쪽이 3인 경우를 찾고 2인 쪽에서 두번째 칸에 4 대입
    int i = 0;
    while(i < 16)
    {
        if (i < 4 || (i > 7 && i < 12))
        {
            if (*(a + i) == '2' && *(a + i + 4) == '3')
            {
                if(i / 4 == 0)
                    b[i][1] = '4';
                if(i / 4 == 2)
                    b[1][i % 4] = '4';
            }
        }
        if ((i > 3 && i < 8) || (i >11 && i < 16))
        {
            if(*(a + i) == '2' && *(a + i - 4) == '3')
            {
                if(i / 4 == 1)
                    b[i % 4][2] = '4';
                if(i / 4 == 3)
                    b[2][i % 4] = '4';
            }
        }
        i++;
    }
}

void checkot(char *a, char b[4][4])
{
	//한 쪽이 1, 반대쪽이 2인 경우를 찾고 2인 쪽 바로 앞 칸에 3 대입
	int i = 0;
	while(i < 16)
	{
		if (i < 4 || (i > 7 && i < 12))
		{
			if (*(a + i) == '1' && *(a + i + 4) == '2')
			{
				if(i / 4 == 0)
					b[i][3] = '3';
				if(i / 4 == 2)
					b[3][i % 4] = '3';
			}
		}
		if ((i > 3 && i < 8) || (i >11 && i < 16))
		{
			if(*(a + i) == '1' && *(a + i - 4) == '2')
			{
				if(i / 4 == 1)
					b[i % 4][0] = '3';
				if(i / 4 == 3)
					b[0][i % 4] = '3';
			}
		}
		i++;
	}
}

int check (char b[4][4], int k, int i, int z)
{
	int j = 0;
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

int checksky(char *a, char b[4][4])
{
	int i = 0;
	int k = 0;
	int count = 1;
	char s;
	while (k < 4)
	{
		s = b[k][i];
		while (i < 4)
		{
			if(s < b[k][i])
			{
				count ++;
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
	k = 0;
	while (k < 4)
	{
		s = b[k][3 - i];
		while (3 - i > -1)
		{
			if(s < b[k][3 - i])
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
	k = 0;
	while (i < 4)
	{
		s = b[k][i];
		while (k < 4)
		{
			if(s < b[k][i])
			{
				count++;
				s = b[k][i];
			}
			k++;
		}
		if(count + 48 != *(a + i + 8))
			return 0;
		i++;
		k = 0;
		count = 1;
	}
	i = 0;
	while (i < 4)
	{
		s = b[3 - k][i];
		while (3 - k > -1)
		{
			if(s < b[3 - k][i])
			{
				count++;
				s = b[3 - k][i];
			}
			k++;
		}
		if(count + 48 != *(a + i + 12))
			return 0;
		i++;
		k = 0;
		count = 1;
	}
	return 1;

}

int sky(char *a, char b[4][4])
{
	int i = 0;
	int k = 0;
	while(i < 4)
	{
		k = 0;
		while(k < 4)
		{
			if(b[k][i] == 0)
			{
				int z = 4;
				while(z > 0)
				{
					if(check(b, k, i, z) == 1)
					{
						b[k][i] = z + 48;
						if(sky(a, b) == 1)
							return 1;
						b[k][i] = 0;
					}
					z--;
				}
				return 0;
			}
			k++;
		}
		i++;
	}
	if(checksky(a, b) == 0)
	{
		return 0;
	}
	return 1;
}


int main(int argc, char* argv[])
{
	char A[16] = {'1','2','3','2','3','1','2','3','1','2','3','2','3','1','2','3'}; // 문제 값 대입
	char B[4][4]; // 답을 넣을 칸
	int i = 0;
	int k = 0;
	//checkf(A, B);
	//checko(A, B);
	//checktt(A, B);
	//checkot(A, B);
	sky(A, B);
	while(i < 4) // 답 출력
	{
		while(k < 4)
		{
			if (B[k][i] == 0)// 아직 안들어간 칸은 0출력 테스트 버전이라 넣은 기능
				write(1, "0", 1);
			else 
				write(1, &B[k][i], 1);
			k++;
		}
		i++;
		k = 0;
		write(1, "\n", 1);
	}
	i = 0;
	while(i < 16) //문제 출력 
	{
		write(1, &A[i], 1);
		if(i % 4 == 3)
			write(1, "\n", 1);
		i++;
	}
}
