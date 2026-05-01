#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lenerror(int a, int b) //key와 plaintext의 값 검사
{
	if (a == 1) //fgets는 개행('\n')을 문자 1개로 포함하기 때문에 a == 1이다
	{
		if (b == 0)
		{
			printf("[ERROR] 유효한 키가 입력되지 않았습니다. \n");
		}
		else if (b == 1)
		{
			printf("[ERROR] 유효한 평문이 입력되지 않았습니다. \n");
		}
		exit(1);
	}
}

int main()
{
	int ASCII_1, ASCII_2; //아스키값을 저장하는 정수값
	char vigenere[26][26]; //비즈네르 표값을 저장하기 위한 2차원 배열
	int countASC;
	for (ASCII_1 = 65; ASCII_1 <= 90; ASCII_1++)
	{
		countASC = ASCII_1;
		for (ASCII_2 = 65; ASCII_2 <= 90; ASCII_2++)
		{
			vigenere[ASCII_1 - 65][ASCII_2 - 65] = countASC;
			countASC++;

			if (countASC > 90)
			{
				countASC = 65; //Z 범위 초과 시 A로 복귀
			}

		}
	}	//배열 내 비즈네르 표 저장 완료

	char key[100], plaintext[1000];
	printf("KEY를 입력하시오 (알파벳과 공백만 가능합니다) : \n");
	fgets(key, sizeof(key), stdin);
	//한줄 단위로 입력받으며, 버퍼 오버플로우 위험이 없는 fgets 사용
	lenerror(strlen(key), 0);

	for (int i = 0; i < sizeof(key) && key[i] != '\0'; i++) //입력받은 key 정제하기
	{
		if (key[i] == ' ' || key[i] == '\n')
		{
			int j = i;
			while (key[j] != '\0' && j < sizeof(key) - 1) //key의 스페이스 공백(' ') 또는 개행('\n') 제거
			{
				key[j] = key[j + 1];
				j++;
			}
			i--; //연속으로 공백이 나올 수 있어 key[i] 재점검
			continue;
		}

		if (key[i] <= 90 && key[i] >= 65) //대문자 입력 시 소문자로 통일
		{
			key[i] += 32;
		}

		if (key[i] < 97 || key[i] > 122) //key에 특수문자 포함 시 에러코드와 함께 종료
		{
			printf("[ERROR] 키에는 영문자만 포함될 수 있습니다. (잘못된 문자: '%c')\n", key[i]);
			return 1;
		}
	}

	printf("암호화할 평문을 입력하시오 :\n");
	fgets(plaintext, sizeof(plaintext), stdin);
	lenerror(strlen(plaintext),1);

	for (int i = 0; i < sizeof(plaintext) && plaintext[i] != '\0'; i++)
	{
		if (plaintext[i] <= 90 && plaintext[i] >= 65) //대문자 입력 시 소문자로 통일
		{
			plaintext[i] += 32;
		}
	}

	int keycount = 0; //keycount를 왜쓰나? : 평문에 공백이나 특수문자가 존재하면
					  //키를 사용하지 않기 때문에 카운트를 건너뛸 새로운 keycount 변수가 필요하다
	for (int i = 0; i < sizeof(plaintext) && plaintext[i] != '\0'; i++)
	{
		keycount %= strlen(key); //키가 평문보다 짧을 경우 처음부터 다시 사용
		if (plaintext[i] >= 97 && plaintext[i] <= 122) //비즈네르 암호화식 : 비즈네르 표[키][평문]
		{
			printf("%c", vigenere[key[keycount] - 97][plaintext[i] - 97]);
			keycount++;
		}
		else //공백, 특수문자 등은 그대로 내보냄 (에니그마였으면 삭제)
		{
			printf("%c", plaintext[i]);
		}
	}

	return 0;
}