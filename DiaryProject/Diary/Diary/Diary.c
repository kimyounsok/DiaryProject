#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <direct.h>
#include<conio.h>
#include <io.h>
#include<Windows.h>
#define LSIZE 100
struct _finddata_t fd;
void gotoxy(int x, int y) {
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void DoProgress(char label[], int step, int total);
void DoSome();
void textcolor(int);
void opening();
void T_diary(struct tm *date, char(*diaryL)[LSIZE]);
void MT_diary(struct tm *date, char(*diaryL)[LSIZE]);
void S_diary();
void M_diary(struct tm *date, int *num);
void drawSquare(int x, int y);
void drawmainSquare(int x, int y);
void DA_diary(int);
int menu();
void setConSize(int row, int col) { char buf[256] = { 0 }; sprintf(buf, "mode con: lines=%d cols=%d", row, col); system(buf); }
int main() {
	//세로가 너무 길다 
	setConSize(800, 101);
	int menus, num = 0, count = 0;
	struct tm *date;
	const time_t t = time(NULL);
	system("mode con cols=150 lines=50");
	date = localtime(&t);
	char diaryL[LSIZE][30] = { 0 };
	char fpath[30][30] = { 0 };

	opening();




	while (1) {

		menus = menu(num);

		menus;
		switch (menus) {
		case 1: T_diary(date, diaryL); count++; break;
		case 2: S_diary(); break;
		case 3: M_diary(date, &num); {
			if (num == 1) {
				MT_diary(date, diaryL);
			}
			break;
		}
		case 4: DA_diary(count); break;
		case 5: return 0;
		default:;
		}
	}
	return 0;
}

void drawmainSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 20; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawTdiarySquare(int x, int y) {
	int i;
	//int x = 9;
	//int y = 10;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 9;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawTdiary_write_up_Square(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 9;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawTdiary_write_down_Square(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 9;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawTdiary_maked_Square(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawSdiary_SearchSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 9; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawSdiarySquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 20; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawSdiary_ListSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 15; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}

void drawSdiary_NotthingSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawdiary_WrongSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}

void drawMdiarySquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 6; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}

void drawMdiary_CheckSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 20; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawMdiary_NotthingSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}

void drawDiaryResultSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawDAdiary_ChooseSquare(int x, int y) {
	int i;
	//int x = 9;
	//int y = 10;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 8; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawDAdiary_KeepSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 30; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
void drawline() {
	int i;
	for (i = 1; i < 60; i++) {
		printf("=");
	}
}

void drawdiary_DAWrongSquare(int x, int y) {
	int i;
	//int x2;
	//int y2;
	gotoxy(x, y);
	printf("┎");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┒");
	//좌측 세로 그리기
	for (i = 1; i < 3; i++) {
		y++;
		gotoxy(x, y);
		printf("｜");
		//오른편 세로 그리기
		x += 80;
		gotoxy(x, y);
		printf("｜");
		x = 5;
	}

	//밑에 하단 그리기
	gotoxy(x, y);
	printf("┖");
	for (i = 1; i < 40; i++) {
		printf("―");
	}
	printf("┚");

	//_getch();
}
int menu() {
	int num = 0;
	char number[10] = { "10" };
	char num2[10] = { "10" };
	int i = 0;

	do {
		//사각형 그리기
		drawmainSquare(5, 7);
		//가운데에 메뉴 넣기
		gotoxy(25, 12);

		gotoxy(35, 12);
		printf("===================\n");
		gotoxy(35, 13);
		printf("1.오늘의 일기 작성\n");
		gotoxy(35, 14);
		printf("2.일기 조회\n");
		gotoxy(35, 15);
		printf("3.일기 재작성\n");
		gotoxy(35, 16);
		printf("4.전체 일기 삭제\n");
		gotoxy(35, 17);
		printf("5.종료\n");
		gotoxy(35, 18);
		printf("=====================\n");
		while (1) {
			strcpy(number, num2);
			gotoxy(35, 19);
			fgets(number, sizeof(number), stdin);
			if (strcmp(number, num2) != 0) break;
		}
		num = atoi(number);

		system("cls");
		i = strcmp(number, num2);

		if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) {
			drawdiary_WrongSquare(5, 30);
			gotoxy(25, 31);
			printf("==== 정확한 번호를 입력해 주세요 ====\n");
		}
	} while (num != 1 && num != 2 && num != 3 && num != 4 && num != 5);
	system("cls");

	return num;
}
void T_diary(struct tm *date, char(*diaryL)[LSIZE]) {
	gotoxy(44, 12);

	int i = 0;
	int line = 11;
	FILE *fp;
	long handle;

	sprintf(diaryL[i], "c:\\Mydiary\\%d%d%d.txt", 1900 + date->tm_year, 1 + date->tm_mon, date->tm_mday);  // 오늘날짜 입력
	handle = _findfirst(diaryL[i], &fd);
	if (handle == -1) {
		fp = fopen(diaryL[i], "w");
		if (fp == NULL) {
			printf("파일 에러..");
			return 1;
		}
		drawTdiary_write_up_Square(9, 7);
		drawTdiarySquare(9, 10);
		drawTdiary_write_down_Square(9, 40);
		gotoxy(21, 8);
		printf("========%d년%2d월%2d일 오늘의 일기(최대1000글자 작성=======\n", 1900 + date->tm_year, 1 + date->tm_mon, date->tm_mday);
		gotoxy(20, 36);
		gotoxy(21, 41);
		printf("=====일기 작성이 전부 끝났다면 end를 입력해주세요.=====\n");

		while (1) {
			gotoxy(11, line++);
			fgets(diaryL[i], sizeof(diaryL[i]), stdin);
			diaryL[i][strlen(diaryL[i]) - 1] = '\0';

			fprintf(fp, "%s\n", diaryL[i]);

			if (strcmp(diaryL[i], "end") == 0)break; // end 입력시 종료
		}
		fclose(fp);
		i++;
		system("cls");
	}
	else {
		drawTdiary_maked_Square(5, 28);
		gotoxy(7, 29);
		printf("이미 오늘 일기를 작성하셨습니다.\n");
	}
}

void MT_diary(struct tm *date, char(*diaryL)[LSIZE]) {
	//사각형 그리기

	//가운데에 메뉴 넣기
	gotoxy(44, 12);

	int i = 0;
	int line = 11;
	FILE *fp;

	sprintf(diaryL[i], "c:\\Mydiary\\%d%d%d.txt", 1900 + date->tm_year, 1 + date->tm_mon, date->tm_mday);  // 오늘날짜 입력

	fp = fopen(diaryL[i], "w");
	if (fp == NULL) {
		printf("파일 에러..");
		return 1;
	}
	drawTdiary_write_up_Square(9, 7);
	drawTdiarySquare(9, 10);
	drawTdiary_write_down_Square(9, 40);
	gotoxy(21, 8);
	printf("========%d년%2d월%2d일 오늘의 일기(최대1000글자 작성=======\n", 1900 + date->tm_year, 1 + date->tm_mon, date->tm_mday);
	gotoxy(20, 36);
	gotoxy(21, 41);
	printf("=====일기 작성이 전부 끝났다면 end를 입력해주세요.=====\n");

	while (1) {
		gotoxy(11, line++);
		fgets(diaryL[i], sizeof(diaryL[i]), stdin);

		diaryL[i][strlen(diaryL[i]) - 1] = '\0';

		fprintf(fp, "%s\n", diaryL[i]);

		if (strcmp(diaryL[i], "end") == 0)break; // 이 뒤로 end 삭제하기.
	}
	fclose(fp);
	i++;
	system("cls");
}

void S_diary() {
	int num = 0;
	FILE *fp;
	int ch;
	int dnum = 0;
	char path[30];
	long handle;
	int w_line = 7;
	int h_line = 31;
	int result = 0;
	int y = 0;
	int y2 = 0;
	int m = 0;
	int d = 0;
	char number[10] = { "0" };
	char num2[10] = { "0" };

	do {
		if (num != 0) {
			drawdiary_WrongSquare(5, 15);
			gotoxy(27, 16);
			printf("==== 정확한 수를 입력해주세요. ====\n");
		}
		drawSdiary_SearchSquare(5, 5);
		gotoxy(8, 6);
		drawline();
		gotoxy(8, 7);
		printf("어떤 조회를 하시겠습니까?\n");
		gotoxy(8, 8);
		printf("1. 일기조회\n");
		gotoxy(8, 9);
		printf("2. 작성된 전체 날짜조회\n");
		gotoxy(8, 10);
		printf("3. 메인으로 가기\n");
		gotoxy(8, 11);
		drawline();
		gotoxy(8, 12);
		printf("선택 : ");
		while (1) {
			strcpy(number, num2);
			gotoxy(18, 12);
			fgets(number, sizeof(number), stdin);
			if (strcmp(number, num2) != 0) break;
		}
		num = atoi(number);

		system("cls");
	} while (num != 1 && num != 2 && num != 3);

	if (num == 1) {
		drawSdiary_SearchSquare(5, 5);
		gotoxy(8, 7);
		drawline();
		gotoxy(8, 8);
		printf("조회 할 일기의 날짜를 입력하세요.\n");
		gotoxy(8, 9);
		printf("ex) yyyymmdd\n");
		gotoxy(8, 10);
		drawline();
		gotoxy(8, 11);
		printf("날짜 : \n");
		while (1) {
			strcpy(number, num2);
			gotoxy(14, 11);
			fgets(number, sizeof(number), stdin);
			if (strcmp(number, num2) != 0) break;
		}
		dnum = atoi(number);
		system("cls");

		d = dnum % 100;
		m = dnum / 100;
		m = m % 100;
		y = dnum / 10000000;
		y2 = dnum % 40000;

		if (y > 0 && y < 10) {
			if (m > 0 && m < 13) {
				if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 0 && d < 32)
					|| ((m == 4 || m == 6 || m == 9 || m == 11) && d > 0 && d < 31)
					|| (m == 2 && y2 == 0 && d > 0 && d < 30)
					|| (m == 2 && y2 != 0 && d > 0 && d < 29)) {
					sprintf(path, "c:\\Mydiary\\%d.txt", dnum);
					handle = _findfirst(path, &fd);
					if (handle == -1) {
						drawSdiary_NotthingSquare(5, 30);
						gotoxy(7, 31);
						printf("해당된 날짜의 일기는 존재하지 않습니다.\n");
					}
					else {
						fp = fopen(path, "r");   // 입력한 날짜의 일기 불러옴.
						drawSdiarySquare(5, 30);
						gotoxy(7, 29);
						printf("<조회 결과>\n");
						gotoxy(w_line, h_line);
						while (1) {
							ch = fgetc(fp);

							if (ch == EOF) break;
							gotoxy(w_line++, h_line);
							if (ch == '\n') {
								h_line++;
								w_line = 7;
								gotoxy(w_line, h_line);
							}
							putchar(ch);
						}
						fclose(fp);
						printf("\n");
					}
				}
				else {
					drawdiary_WrongSquare(5, 30);
					gotoxy(25, 31);
					printf("==== 일(dd)값 입력이 잘못 되었습니다. ====");
				}
			}
			else {
				drawdiary_WrongSquare(5, 30);
				gotoxy(25, 31);
				printf(" ====월(mm)값 입력이 잘못 되었습니다. ====");
			}
		}
		else {
			drawdiary_WrongSquare(5, 30);
			gotoxy(25, 31);
			printf(" ====날짜 형식이 잘못 되었습니다. ====");
		}
	}
	else if (num == 2) {
		sprintf(path, "c:\\Mydiary\\*.txt");

		handle = _findfirst(path, &fd);
		if (handle == -1) {
			drawdiary_WrongSquare(5, 30);
			gotoxy(7, 31);
			printf("파일이 하나도 존재하지 않습니다.");
			return;
		}
		gotoxy(5, 29);
		printf("<조회 결과>\n");
		drawSdiary_ListSquare(5, 30);

		while (result != -1)
		{
			gotoxy(w_line, h_line);
			printf("날짜 : %s\n", fd.name);
			gotoxy(w_line, h_line++);
			result = _findnext(handle, &fd);
			if (h_line == 43) {
				w_line += 25;
				h_line = 31;
			}
		}
		_findclose(handle);
	}
	else if (num == 3) {
	}
	else {
		drawdiary_WrongSquare(5, 30);
		gotoxy(7, 31);
		printf("잘못된 값입니다.\n");
	}
}

void M_diary(struct tm *date, int *num) {

	FILE *fp;
	int ch;
	int dnum;
	int result = 0;
	int w_line = 7;
	int h_line = 14;
	char path[30];
	long handle;
	int y = 0;
	int y2 = 0;
	int year = 0;
	int m = 0;
	int d = 0;
	char number[10] = { "0" };
	char num2[10] = { "0" };

	drawMdiarySquare(5, 5);
	gotoxy(7, 6);
	drawline();
	gotoxy(7, 7);
	printf("재작성 할 일기의 날짜를 입력하세요.\n");
	gotoxy(7, 8);
	printf("ex) yyyymmdd\n");
	gotoxy(7, 9);
	printf("재작성 할 날짜 : ");
	while (1) {
		strcpy(number, num2);
		gotoxy(23, 9);
		fgets(number, sizeof(number), stdin);
		if (strcmp(number, num2) != 0) break;
	}
	dnum = atoi(number);
	system("cls");
	system("cls");

	sprintf(path, "c:\\Mydiary\\%d.txt", dnum);
	d = dnum % 100;
	m = dnum / 100;
	m = m % 100;
	y = dnum / 10000000;
	y2 = dnum % 40000;
	year = dnum / 10000;

	if (y > 0 && y < 10) {
		if (m > 0 && m < 13) {
			if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 0 && d < 32)
				|| ((m == 4 || m == 6 || m == 9 || m == 11) && d > 0 && d < 31)
				|| (m == 2 && y2 == 0 && d > 0 && d < 30)
				|| (m == 2 && y2 != 0 && d > 0 && d < 29)) {
				handle = _findfirst(path, &fd);

				if (handle == -1) {
					drawMdiary_NotthingSquare(5, 30);
					gotoxy(24, 31);
					printf("=====해당된 날짜의 일기는 존재하지 않습니다.=====\n");
				}
				else {

					if ((d - date->tm_mday) == 0 && (m - date->tm_mon - 1) == 0 && (year - date->tm_year - 1900) == 0) {
						do {
							w_line = 7;
							h_line = 14;
							fp = fopen(path, "r");

							gotoxy(5, 12);
							printf("<재작성 전 체크 결과>\n");
							drawMdiary_CheckSquare(5, 13);
							while (1) {
								ch = fgetc(fp);

								if (ch == EOF) break;
								gotoxy(w_line++, h_line);
								if (ch == '\n') {
									h_line++;
									w_line = 7;
									gotoxy(w_line, h_line);
								}putchar(ch);
							}fclose(fp);


							if (result != 1 || result != 2) {
								drawdiary_WrongSquare(5, 30);
								gotoxy(7, 31);
								printf("정확한 수를 입력해주세요.\n");
							}
							printf("\n");
							drawMdiarySquare(5, 5);
							gotoxy(7, 6);
							printf("정말로 재작성하시겠습니까?");
							gotoxy(7, 7);
							printf("재작성을 원하시면 1을 취소하신다면 2를 입력해주세요");
							gotoxy(7, 8);
							printf("1.재작성\t   2.취소\n");
							while (1) {
								strcpy(number, num2);
								gotoxy(7, 9);
								fgets(number, sizeof(number), stdin);
								if (strcmp(number, num2) != 0) break;
							}
							result = atoi(number);
							system("cls");

							if (result == 1) {
								remove(path);
								*num = 1;
							}
							else if (result == 2) {
								*num = 0;
							}
							fclose(fp);
							system("cls");

						} while (result != 1 && result != 2);
					}
					else {
						drawdiary_WrongSquare(5, 30);
						gotoxy(7, 31);
						printf("일기를 작성한 날짜가 하루 이상 지나서 더 이상 수정이 불가능합니다.\n");
						return 0;
					}
				}
			}
			else {
				drawdiary_WrongSquare(5, 30);
				gotoxy(28, 31);
				printf("==== 일(dd)값 입력이 잘못 되었습니다. ====");
			}
		}
		else {
			drawdiary_WrongSquare(5, 30);
			gotoxy(28, 31);
			printf("==== 월(mm)값 입력이 잘못 되었습니다. ====");
		}
	}
	else {
		drawdiary_WrongSquare(5, 30);
		gotoxy(28, 31);
		printf("==== 날짜 형식이 잘못 되었습니다. ====");
	}
}

void DA_diary(int count) {
	int path[8] = { 0 };
	char rmname[50] = { 0 };
	char pathres[50] = { 0 };
	char choice[5] = { 0 };
	int num = 0;
	int rs = 0;
	char number[10] = { "0" };
	char num2[10] = { "0" };

	strcat(pathres, "c:\\Mydiary\\");
	do {
		if (num != 0) {
			drawdiary_WrongSquare(5, 15);
			gotoxy(28, 16);
			printf("==== 정확한 수를 입력해주세요. ====\n");
		}
		drawDAdiary_ChooseSquare(5, 5);
		gotoxy(8, 6);
		drawline();
		gotoxy(8, 7);
		printf("전체 삭제를 하시겠습니까? 전체 삭제를 원하신다면");
		gotoxy(8, 8);
		printf("전체삭제를 원하시면 1을 취소를 원하시면 2를 입력해주세요");
		gotoxy(8, 9);
		printf("1.전체삭제\t   2.취소\n");
		gotoxy(8, 10);
		drawline();
		gotoxy(8, 11);
		printf("선택할 기능 :  \n");
		while (1) {
			strcpy(number, num2);
			gotoxy(22, 11);
			fgets(number, sizeof(number), stdin);
			if (strcmp(number, num2) != 0) break;
		}
		num = atoi(number);
		system("cls");
	} while (num != 1 && num != 2);

	while (1) {
		if (num == 1) {
			long handle;
			int result = 1;
			strcpy(pathres, "c:\\Mydiary\\");
			handle = _findfirst("c:\\Mydiary\\*.txt", &fd);  //현재 폴더 내 모든 파일을 찾는다.

			if (handle == -1 && rs == 1)
			{
				drawDiaryResultSquare(5, 30);
				gotoxy(7, 31);
				printf("폴더 내의 파일을 전부 삭제하였습니다.\n");
				break;
			}
			else if (handle == -1) {
				drawdiary_DAWrongSquare(5, 30);
				gotoxy(7, 31);
				printf("폴더 내의 파일이 존재하지 않습니다.");
				break;
			}

			while (result != -1)
			{
				strcat(pathres, fd.name);
				remove(pathres);
				result = _findnext(handle, &fd);
				rs = 1;
			}
			_findclose(handle);
		}
		else break;
	}
}
void DoProgress(char label[], int step, int total)
{
	//progress width
	const int pwidth = 92;

	//minus label len
	int width = pwidth - strlen(label);
	int pos = (step * width) / total;


	int percent = (step * 100) / total;

	textcolor(7), printf("%s[", label);

	for (int i = 0; i < pos; i++)  printf("%c", '*');

	//fill progress bar with spaces
	printf("% *c", width - pos + 1, ']');
	printf(" %3d%%\r", percent);

	//reset text color, only on Windows
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x08);
}
void DoSome()
{

	int total = 800;
	int step = 0;

	while (step < total)
	{
		//do some action
		Sleep(50);

		step += 10;

		DoProgress("로딩중.........: ", step, total);


	}
	printf("\n");

}
void opening() {


	textcolor(238), printf("############"); textcolor(0), printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	textcolor(238), printf("##############"); textcolor(0), printf("++++++++++++++++++*+"); textcolor(85), printf("++"); textcolor(0), printf("+++++++++++++++++++++++++*++++++++"); textcolor(34), printf("++++++++++++++++++++++++++++*+\n");
	textcolor(238), printf("##############"); textcolor(0), printf("++++++++++++++++++++++++++++++"); textcolor(255), printf("@@@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@@"); textcolor(0), printf("++++++++++++++++"); textcolor(34), printf("++++++++++++++++++++++++++++++\n");
	textcolor(238), printf("###############"); textcolor(0), printf("+++++++++++++++++++++++++++++"); textcolor(255), printf("@@@@"); textcolor(0), printf("+="); textcolor(255), printf("@@@@"); textcolor(0), printf("+"); textcolor(255), printf("@@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@"); textcolor(0), printf("+++++++++"); textcolor(34), printf("++++++++++++++++++++++++++*+\n");
	textcolor(238), printf("##############"); textcolor(0), printf("+++++++++++"); textcolor(85), printf("++"); textcolor(0), printf("+++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+"); textcolor(255), printf("@@@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("++"); textcolor(255), printf("@@"); textcolor(0), printf("+"); textcolor(255), printf("@@@"); textcolor(0), printf("=*"); textcolor(0), printf("@@++++++++"); textcolor(34), printf("++++++++++++++++++++++++*+\n");
	textcolor(238), printf("#################"); textcolor(0), printf("+++++++++++++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("++"); textcolor(255), printf("@@"); textcolor(0), printf("+*"); textcolor(255), printf("@@"); textcolor(0), printf("+="); textcolor(255), printf("@@@@@"); textcolor(0), printf("++++++++++++++"); textcolor(34), printf("++++++++++++++++++++*++++\n");
	textcolor(238), printf("##################"); textcolor(0), printf("++++++++++++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+="); textcolor(255), printf("@@"); textcolor(0), printf("=+"); textcolor(255), printf("@@"); textcolor(0), printf("+++"); textcolor(255), printf("@@@"); textcolor(0), printf("+++++++++++++++++"); textcolor(34), printf("+++++++++++++++++*+++++\n");
	textcolor(238), printf("###################"); textcolor(0), printf("+++++++++++++++++++++++++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+++++++++++"); textcolor(85), printf("++"); textcolor(0), printf("+++++++"); textcolor(34), printf("+++++++++++++++++*++\n");
	textcolor(238), printf("####################"); textcolor(0), printf("++++++++++++++++++++++**++++++++++++++++++++++++++++*+++++++"); textcolor(34), printf("++++++++++++++++*+++\n");
	textcolor(238), printf("##@#################"); textcolor(0), printf("*++++++++++"); textcolor(85), printf("++"); textcolor(0), printf("++++++++++++++++++++++++++++++++++++*++++++++++++++"); textcolor(34), printf("++++++++++++++*+\n");
	textcolor(238), printf("#@@@#################"); textcolor(0), printf("++++++++++++++++++++++++++++++++++++++++++++++*++++++++++++++++"); textcolor(34), printf("++++++++++++*+*+\n");
	textcolor(238), printf("#@@@##################"); textcolor(0), printf("+++++++++++++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@@@@"); textcolor(0), printf("++++++++++++++++++++++++"); textcolor(34), printf("++++*++++++*++\n");
	textcolor(238), printf("##@####################"); textcolor(0), printf("++++++++++++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@@@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@@"); textcolor(0), printf("*"); textcolor(255), printf("@@"); textcolor(0), printf("++="); textcolor(255), printf("@@@"); textcolor(0), printf("+++++++++++"); textcolor(34), printf("++++*+++++*+\n");
	textcolor(238), printf("#@@@@###################"); textcolor(0), printf("++++++++++++++++++++"); textcolor(255), printf("@@@@@@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+"); textcolor(255), printf("@@@"); textcolor(0), printf("++="); textcolor(255), printf("@@@"); textcolor(0), printf("=+"); textcolor(255), printf("@@"); textcolor(0), printf("+++++++++++++"); textcolor(34), printf("++++++*++*+\n");
	textcolor(238), printf("#@@@@####################"); textcolor(0), printf("+++++++++++++++++++"); textcolor(255), printf("@@"); textcolor(0), printf("+=+"); textcolor(255), printf("@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@@@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("+=++="); textcolor(255), printf("@@@@@"); textcolor(0), printf("+++++++++++"); textcolor(34), printf("++++*+++++++*+\n");
	textcolor(238), printf("#@@#######################"); textcolor(0), printf("++++++++++++++++++"); textcolor(255), printf("@@@@@@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("++"); textcolor(255), printf("@@@@@@"); textcolor(0), printf("+"); textcolor(255), printf("@@"); textcolor(0), printf("+++++="); textcolor(255), printf("@@@"); textcolor(0), printf("++++++++"); textcolor(34), printf("*++*++++++++++++++\n");
	textcolor(238), printf("@@@#########################"); textcolor(0), printf("++======+++++++++++++++++=++===+==++=++++++"); textcolor(255), printf("@@"); textcolor(0), printf("++++++"); textcolor(34), printf("+++++++++++++++++++*+\n");
	textcolor(238), printf("@@@@@########################"); textcolor(0), printf(" += +++++++"); textcolor(85), printf("++"); textcolor(0), printf("+++++++++++++++++++++++++++++++++*++"); textcolor(34), printf("++++++++++++++++++++*+\n");
	textcolor(238), printf("#@@#@##########################"); textcolor(0), printf("++++++++++++++++++++++++++++++++++++++++*++++"); textcolor(34), printf("+++++++++++++++++++++++ \n");
	textcolor(238), printf("@@@@@########################"); textcolor(0), printf("*+++++++++++++++++++++++++++++++++++++++++++++"); textcolor(34), printf("++*++++++++++++++++++++++\n");
	textcolor(238), printf("#@@#@@#@####################"); textcolor(0), printf("+++★☆★☆★☆★☆★☆★+++++++++++++++++++++"); textcolor(34), printf("+++++++++++*++++++++++++++\n");
	textcolor(238), printf("@@@@######################"); textcolor(0), printf("+++++★"); textcolor(0), printf("★+++++++++++++++++++++++++++######+*+"); textcolor(34), printf("+++++++++++++++++++++++++++++\n");
	textcolor(238), printf("#@@######################"); textcolor(0), printf("##########################"); textcolor(204), printf("++++"); textcolor(0), printf("########################"); textcolor(34), printf("+++++*+++++++++++++++\n");
	textcolor(238), printf("#@#####################"); textcolor(0), printf("##########################"); textcolor(204), printf("++++++"); textcolor(0), printf("######################");  textcolor(34), printf("++++++*++++++++++++++++\n");
	textcolor(238), printf("##@###################"); textcolor(0), printf("##########################"); textcolor(204), printf("++++++++"); textcolor(0), printf("####################"); textcolor(34), printf("+++++++*++++++++++++++++\n");
	textcolor(238), printf("#####################"); textcolor(0), printf("#################"); textcolor(238), printf("++======="); textcolor(204), printf("+++++++"); textcolor(0), printf("#################"); textcolor(34), printf("*++++++++++++++++++++++++++++\n");
	textcolor(238), printf("#@##################"); textcolor(0), printf("###############"); textcolor(238), printf("+==+++++++="); textcolor(204), printf("===++***########"); textcolor(0), printf("#################"); textcolor(34), printf("+++++++++++++++++++++\n");
	textcolor(238), printf("####################"); textcolor(0), printf("#############"); textcolor(238), printf("+========+++="); textcolor(204), printf("=+:****+*#######");  textcolor(0), printf("#################"); textcolor(34), printf("+++++++++++++++++++++\n");
	textcolor(238), printf("#####################"); textcolor(0), printf("#############"); textcolor(238), printf("+*****++++="); textcolor(255), printf("++++"); textcolor(204), printf("+++++++++++++#");  textcolor(0), printf("#######################");  textcolor(34), printf("++++++++++++++\n");
	textcolor(238), printf("#@##################"); textcolor(0), printf("##################"); textcolor(170), printf("***+*+"); textcolor(255), printf("++++"); textcolor(153), printf("++========++#");   textcolor(0), printf("#######################"); textcolor(34), printf("++++++++++++++++\n");
	textcolor(238), printf("####################"); textcolor(0), printf("##################"); textcolor(170), printf("****++++"); textcolor(153), printf("++++======+####");  textcolor(0), printf("#######################"); textcolor(34), printf("++++++++++++++++\n");
	textcolor(238), printf("#####################"); textcolor(0), printf("##################"); textcolor(170), printf("**++++++"); textcolor(153), printf("++++++==*######"); textcolor(0), printf("#######################");  textcolor(34), printf("+++++++++++++++\n");
	textcolor(238), printf("#@#################"); textcolor(0), printf("##################"); textcolor(170), printf("+==++++*"); textcolor(0), printf("###############"); textcolor(0), printf("#################");  textcolor(34), printf("+++++++++++++++++++++++\n");
	textcolor(238), printf("#@##################");    textcolor(0), printf("##################"); textcolor(170), printf("+==++++*"); textcolor(0), printf("###############");  textcolor(0), printf("#######################");  textcolor(34), printf("++++++++++++++++\n");
	textcolor(238), printf("####################"); textcolor(0), printf("####################"); textcolor(170), printf("+==++*"); textcolor(0), printf("###############");  textcolor(0), printf("#######################"); textcolor(34), printf("++++++++++++++++\n");
	textcolor(238), printf("#####################"); textcolor(0), printf("######################"); textcolor(170), printf("++=*"); textcolor(0), printf("###############"); textcolor(0), printf("#######################");  textcolor(34), printf("+++++++++++++++\n");
	textcolor(238), printf("#@##################"); textcolor(0), printf("########################"); textcolor(170), printf("++"); textcolor(0), printf("###############");  textcolor(0), printf("#######################"); textcolor(34), printf("++++++++++++++++\n");



	textcolor(7);
	DoSome();
	system("cls");
	textcolor(7);
}
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
	return;
}