#include <stdio.h>
#include <memory>
#define BLK_AREA_WIDTH	3

void PrintBlocks(int **ap_block)
{
	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		for (int j = 0; j < BLK_AREA_WIDTH; j++) {
			if(ap_block[i][j]) printf("бс");
			else printf(" ");
		}
		printf("\n");
	}
}

void MakeZ(int **ap_block)
{
	ap_block[0][0] = 1;
	ap_block[0][1] = 1;
	ap_block[1][1] = 1;
	ap_block[1][2] = 1;
}



int main()
{
	int **pBlock = new int*[BLK_AREA_WIDTH];
	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		pBlock[i] = new int[BLK_AREA_WIDTH];
		memset(pBlock[i], 0, sizeof(int) * BLK_AREA_WIDTH);
	}
	MakeZ(pBlock);
	PrintBlocks(pBlock);



	for (int i = 0; i < BLK_AREA_WIDTH; i++) {
		delete[] *(pBlock + i);
	}
	delete[] pBlock;



	return 0;
}