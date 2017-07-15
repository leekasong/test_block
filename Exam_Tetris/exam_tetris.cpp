#include <cstdio>
#include <cstring>
#include <cstdlib>

#define BLK_AREA_WIDTH	4
using namespace std;


void gotoxy(int x, int y)
{
	printf("\033[%d;%df", y,x);
	fflush(stdout);	
}

int ** ClearBlocks(int **ap_block)
{
	gotoxy(1, 2);
	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		for (int j = 0; j < BLK_AREA_WIDTH; j++) {
			printf("  ");
		}
		printf("\n");
	}

	gotoxy(1, 2);

	return ap_block;
}

void PrintBlocks(int **ap_block)
{
	gotoxy(1, 2);
	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		for (int j = 0; j < BLK_AREA_WIDTH; j++) {
			if(ap_block[i][j]) printf("■ ");
			else printf("@@");
		}
		printf("\n");
	}
}

int ** rotate(int **ap_block)
{
	int **tmp = new int*[BLK_AREA_WIDTH];
	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		tmp[i] = new int[BLK_AREA_WIDTH];
		memcpy(tmp[i], ap_block[i], sizeof(int) * BLK_AREA_WIDTH);
	}

	for (int y = 0; y < BLK_AREA_WIDTH; y++) {
		for (int x = 0; x < BLK_AREA_WIDTH; x++) {
			ap_block[y][x] = tmp[x][3 - y];
		}
	}

	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		delete[] * (tmp + i);
	}
	delete[] tmp;

	return ap_block;

}

void MakeZ(int **ap_block)
{
	ap_block[1][1] = 1;
	ap_block[1][2] = 1;
	ap_block[2][2] = 1;
	ap_block[2][3] = 1;
}



int main()
{
	int **pBlock = new int*[BLK_AREA_WIDTH];
	int input = 0;
	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		pBlock[i] = new int[BLK_AREA_WIDTH];
		memset(pBlock[i], 0, sizeof(int) * BLK_AREA_WIDTH);
	}
	MakeZ(pBlock);
	system("clear");

	while (input != 999) {
		PrintBlocks(pBlock);
		scanf("%c", &input);
		if (input == 'r') {
			pBlock = ClearBlocks(pBlock);
			pBlock = rotate(pBlock);
		}
	}


	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		delete[] *(pBlock + i);
	}
	delete[] pBlock;
	printf("\n\n");


	return 0;
}
