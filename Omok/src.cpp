#define _CRT_SECURE_NO_WARNINGS
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
    COORD Pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//��ǥ �̵� �Լ�

void setConsoleScreen(int r, int c) {
    char str[50];
    sprintf(str, "mode con cols=%d lines=%d", r * 2, c);
    system(str);
} 
//�ܼ�â ũ�� ���� �Լ�

void cursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
//Ŀ�� ����� �Լ�

int getKey() {
    int key = _getch();

    if (key == SPACE) {
        return key;
    }
    else if (key == UP) {
        return key;
    }
    else if (key == DOWN) {
        return key;
    }
    else if (key == LEFT) {
        return key;
    }
    else if (key == RIGHT) {
        return key;
    }
    else {
        return 0;
    }
}
//Ű �� �޾ƿ��� �Լ�

void menu() {
    gotoxy(40, 10);
    puts("Omok Game");
    gotoxy(40, 20);
    puts("Start");
    gotoxy(40, 22);
    puts("Exit");

    int x = 35, y = 20; //�ʱ� Ŀ�� ��ġ
    gotoxy(x, y);
    printf(">");

    while (1) {
        int key = getKey();
        switch (key) {
        case UP:
            gotoxy(x, y);
            printf(" ");
            y = 20;
            gotoxy(x, y);
            printf(">");
            break;
        case DOWN:
            gotoxy(x, y);
            printf(" ");
            y = 22;
            gotoxy(x, y);
            printf(">");
            break;
        case SPACE:
            if (y == 20) {
                system("cls");
                return;
            }
            if (y == 22) {
                exit(0);
            }
            break;
        default:
            break;
        }
    }
}
//�޴� ���� �Լ�

void drawBoard() {
    //�� = 0, �� = 1, �� = 2, �� = 3, �� = 4, �� = 5, �� = 6, �� = 7, �� = 8
    int board[15][15]{
        {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5},
        {6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8},
    };

    gotoxy(0, 0);

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            switch (board[i][j]) {
            case 0:
                printf("��"); 
                break;
            case 1:
                printf("��");
                break;
            case 2:
                printf("��\n");
                break;
            case 3:
                printf("��");
                break;
            case 4:
                printf("��");
                break;
            case 5:
                printf("��\n");
                break;
            case 6:
                printf("��");
                break;
            case 7:
                printf("��");
                break;
            case 8:
                printf("��\n");
                break;
            }
        }
    }
}

void userChoice() {

}

void startGame() {
    while (1) {
        drawBoard();
        userChoice();
    }
}

int main() {
    setConsoleScreen(50, 40);
    cursorView();
    
    
    menu();

    startGame();       
   

	return 0;
}