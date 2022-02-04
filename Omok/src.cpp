#define _CRT_SECURE_NO_WARNINGS
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

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

void gotoxy(int x, int y) {
    COORD Pos = { x  , y };
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

void searcBoard(int x, int y) {
    gotoxy(x, y);

    switch (board[y][x]) {
    case 0:
        printf("��");
        break;
    case 1:
        printf("��");
        break;
    case 2:
        printf("��");
        break;
    case 3:
        printf("��");
        break;
    case 4:
        printf("��");
        break;
    case 5:
        printf("��");
        break;
    case 6:
        printf("��");
        break;
    case 7:
        printf("��");
        break;
    case 8:
        printf("��");
        break;
    case 10:
        printf("o");
        break;
    case 11:
        printf("x");
        break;
    }
}
//�ش� ��ġ�� �´� �� �׸��� �Լ�

void drawBoard() {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            searcBoard(i, j);           
        }
    }
}
//�ʹ� ���� �� �׸��� �Լ�

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
//������ ���� ��Ʈ�� �ϴ� �Լ�

int check(int x, int y, int user) {
    int count = 0;
    int a = 0;

    if (user == 0) {
        a = 10;
    }
    else {
        a = 11;
    }

    //���� Ȯ��
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

    //���� Ȯ��
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
    
    //������ �밢�� Ȯ��
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

    //���� �밢�� Ȯ��
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
//������ ���и� Ȯ���ϴ� �Լ�

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
//������ ���� �θ� �����ϴ� �Լ�

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
    printf("Player%d�� �¸��߽��ϴ�.", user + 2);   
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






