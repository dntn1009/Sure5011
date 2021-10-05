﻿#pragma warning(disable:4996)
#include <stdio.h>

#define ROAD 0
#define WALL 1
#define GEM	 2
// 맵 크기

#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4
// 플레이어의 위치 움직임

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
// 플레이어의 최대 움직임 컷
int main()
{
	int map[10][10] =
	{
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 2, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};//배열에 숫자를 이용하여 벽과, 로드지점 보석이 있는곳을 지정해둠

	int playerX = 0;
	int playerY = 0;
	//현재 플레이어의 위치는 [0],[0] 이 되어야함. 시작지점이 
	int select = 0; // 저장할수 있는 곳

	printf("◈ 보석 찾기 게임 ◈\n");

	while (true)
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++) {
				if (map[i][j] == ROAD)// 움직일수 있는 공간
				{
					if (playerX == j && playerY == i)// 여기서 플레이어의 X,Y좌표가 같은곳은 캐릭터를 표시해줌 
					{
						printf("♠");
					}
					else
					{
						printf("■");// 움직일수 있는 공간을 칠해놈
					}
				}
				else if (map[i][j] == WALL)
				{
					printf("▨");
				}
				else if (map[i][j] == GEM)
				{
					printf("◈");
				}
			}
			printf("\n");// [i][1~10] 까지 끝낸후 아래로 내려가기위해서 사각형 모양 만들기위해
		}

		printf("\n\n1. 왼쪽  2. 오른쪽 3. 위 4. 아래 0. 종료\n\n");
		printf("입력 : ");
		scanf("%d", &select);

		switch (select)
		{
		case LEFT:
			if (playerX - 1 >= 0)
			{
				if (map[playerY][playerX - 1] == ROAD)
				{
					playerX--;
				}
				else if (map[playerY][playerX - 1] == GEM)
				{
					printf("\n축하합니다. 보석을 발견하였습니다.\n\n");
					printf("◈ 보석 찾기 게임 ◈\n");
					playerX = 0;
					playerY = 0;
				}
			}
			break;
		case RIGHT:
			if (playerX + 1 < MAP_WIDTH)// Y좌표의 최대치를 설정해놈.
			{
				if (map[playerY][playerX + 1] == ROAD)// 최대치 안에서 움직인 좌표가 ROAD 움직일수 있는 공간이면
				{
					playerX++;// Y좌표를 +1 하여 움직여준다.
				}
				else if (map[playerY][playerX + 1] == GEM)
				{
					printf("\n축하합니다. 보석을 발견하였습니다.\n\n");
					printf("◈ 보석 찾기 게임 ◈\n");
					playerX = 0;
					playerY = 0;
				}
			}
			break;
		case UP:
			if (playerY - 1 >= 0)
			{
				if (map[playerY - 1][playerX] == ROAD)
				{
					playerY--;
				}
				else if (map[playerY - 1][playerX] == GEM)
				{
					printf("\n축하합니다. 보석을 발견하였습니다.\n\n");
					printf("◈ 보석 찾기 게임 ◈\n");
					playerX = 0;
					playerY = 0;
				}
			}
			break;
		case DOWN:
			if (playerY + 1 < MAP_HEIGHT)// Y좌표의 최대치를 설정해놈.
			{
				if (map[playerY + 1][playerX] == ROAD)// 최대치 안에서 움직인 좌표가 ROAD 움직일수 있는 공간이면
				{
					playerY++;// Y좌표를 +1 하여 움직여준다.
				}
				else if (map[playerY + 1][playerX] == GEM)
				{
					printf("\n축하합니다. 보석을 발견하였습니다.\n\n");
					printf("◈ 보석 찾기 게임 ◈\n");
					
					playerX = 0;
					playerY = 0;
				}
			}
			break;
		default:
			if (select == 0)
				return 0;
			else
			{
				printf("메뉴 안의 숫자를 입력해주세요.\n");
			}
		}
	}
}
