#define _CRT_SECURE_NO_WARNINGS
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

//┌ = 0, ┬ = 1, ┐ = 2, ├ = 3, ┼ = 4, ┤ = 5, └ = 6, ┴ = 7, ┘ = 8
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

void gotoxy(int x, int y) {
    COORD Pos = { x  , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
//좌표 이동 함수

void setConsoleScreen(int r, int c) {
    char str[50];
    sprintf(str, "mode con cols=%d lines=%d", r * 2, c);
    system(str);
} 
//콘솔창 크기 설정 함수

void cursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
//커서 숨기는 함수

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
//키 값 받아오는 함수

void menu() {
    gotoxy(40, 10);
    puts("Omok Game");
    gotoxy(40, 20);
    puts("Start");
    gotoxy(40, 22);
    puts("Exit");

    int x = 35, y = 20; //초기 커서 위치
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
//메뉴 고르기 함수

void searcBoard(int x, int y) {
    gotoxy(x, y);

    switch (board[y][x]) {
    case 0:
        printf("┌");
        break;
    case 1:
        printf("┬");
        break;
    case 2:
        printf("┐");
        break;
    case 3:
        printf("├");
        break;
    case 4:
        printf("┼");
        break;
    case 5:
        printf("┤");
        break;
    case 6:
        printf("└");
        break;
    case 7:
        printf("┴");
        break;
    case 8:
        printf("┘");
        break;
    case 10:
        printf("o");
        break;
    case 11:
        printf("x");
        break;
    }
}
//해당 위치에 맞는 판 그리는 함수

void drawBoard() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            searcBoard(i, j);           
        }
    }
}
//초반 게임 판 그리는 함수

void control(int x, int y, int user) {
    if(!user) {
        gotoxy(x, y);
        printf("o");
    }
    else {
        gotoxy(x, y);
        printf("x");
    }    
}
//유저가 돌을 컨트롤 하는 함수

int check(int x, int y, int user) {
    int count = 0;
    int a = 0;

    if (user == 0) {
        a = 10;
    }
    else {
        a = 11;
    }

    //가로 확인
    for (int i = 0; i < 15; i++) {
        if (board[y][i] == a) {
            count++;
            if (count == 5) {
                return 1;
            }
        }
        else {
            count = 0;
        }
    }

    //세로 확인
    count = 0;
    for (int i = 0; i < 15; i++) {
        if (board[i][x] == a) {
            count++;
            if (count == 5) {
                return 1;
            }
        }
        else {
            count = 0;
        }
    }
    
    //오른쪽 대각선 확인
    count = 0;
    while (1) {    
        int x1 = x, y1 = y;
        while (x1 != 0 && y1 != 0) {
            x1--;
            y1--;
        }       
        while (x1 != 15 && y1 != 15) {
            if (board[y1][x1] == a) {
                count++;
                if (count == 5) {
                    return 1;
                }
            }
            else {
                count = 0;
            }
            x1++; 
            y1++;
        }        
        break;
    }

    //왼쪽 대각선 확인
    count = 0;
    while (1) {
        int x1 = x, y1 = y;
        while (x1 != 0 && y1 != 15) {
            x1--;
            y1++;
        }
        while (x1 != 15 && y1 >= 0) {
            if (board[y1][x1] == a) {
                count++;
                if (count == 5) {
                    return 1;
                }
            }
            else {
                count = 0;
            }
            x1++;
            y1--;
        }
        break;
    }
    return 0;
}
//게임의 승패를 확인하는 함수

int choice(int x, int y, int user) {
    if (board[y][x] == 10 || board[y][x] == 11) {
        return 1;
    }
    if (!user) {            
        board[y][x] = 10;
        gotoxy(x, y);
        printf("o");
    }
    else {
        board[y][x] = 11;
        gotoxy(x, y);
        printf("x");
    }

    if (check(x, y, user)) {
        return 2;
    }
    return 0;
}
//유저가 돌을 두면 저장하는 함수

int userChoice() {
    int user = 0;
    int x1 = 0, y1 = 0;
    int x = 0, y = 0;

    control(x, y, user);

    while (1) {
        int key = getKey(); 

        switch (key) {
        case UP:
            if (y == 0) {
                y = 0;
            }
            else {
                x1 = x, y1 = y;
                y -= 1;
            }
            break;
        case DOWN:
            if (y == 14) {
                y = 14;
            }
            else {
                x1 = x, y1 = y;
                y += 1;
            }
            break;
        case LEFT:
            if (x == 0) { 
                x = 0;
            }
            else {
                x1 = x, y1 = y;
                x -= 1;
            }       
            break;
        case RIGHT:
            if (x == 14) {
                x = 14;
            } else
            {
                x1 = x, y1 = y;
                x += 1;
            }       
            break;
        case SPACE:        
            int c = choice(x, y, user);
            if (c == 2) {
                return user;
            }
            if (c) {
                break;
            }
            
            if (!user) {
                user -= 1;
            }
            else {
                user += 1;
            }
            break;
        }
        searcBoard(x1, y1);
        control(x, y, user);
    }
}

void winner(int user) {
    gotoxy(30, 20);
    printf("Player%d이 승리했습니다.", user + 2);   
}

void startGame() {

     drawBoard();

     int user = userChoice();  
     
     winner(user);
}

int main() {
    setConsoleScreen(50, 40);

    cursorView();
    
    menu();

    startGame();
    
	return 0;
}






