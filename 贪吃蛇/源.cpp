#include <graphics.h>
#include<stdio.h>
#include<conio.h>
typedef struct MyStruct {
    int x;
    int y;
}POS;

struct snake {
    POS position[100];
    int length;
    int direction;
}snake;

struct food {
    POS position;
    int flag;//食物是否存在
};

enum MyEnum {
    UP, DOWN, LEFT, RIGHT
};

//初始化蛇
void InitSnake()
{
    snake.length = 3;
    snake.direction = RIGHT;
    snake.position[0].x = 20;
    snake.position[0].y = 0;

    snake.position[1].x = 10;
    snake.position[1].y = 0;

    snake.position[2].x = 0;
    snake.position[2].y = 0;

}
//画蛇
void DrawSnake()
{
    cleardevice();
    for (int i = 0; i < snake.length; i++)
    {
        setfillcolor(RED);
        fillrectangle(snake.position[i].x, snake.position[i].y, snake.position[i].x + 10, snake.position[i].y + 10);
    }
}

//运动起来
void RunSnake()
{
    for (int i = snake.length - 1; i > 0; i--)
    {
        snake.position[i].x = snake.position[i - 1].x;
        snake.position[i].y = snake.position[i - 1].y;

    }
    switch (snake.direction)
    {
    case UP:
        snake.position[0].y -= 10;
        break;
    case DOWN:
        snake.position[0].y += 10;
        break;
    case RIGHT:
        snake.position[0].x += 10;
        break;
    case LEFT:
        snake.position[0].x -= 10;
        break;
    default:break;
    }
}

//按键
void userKey()
{
    if (_kbhit())//检测是否有按键按下
    {
        char ch = _getch();
        switch (ch)
        {
        case 'W':
        case 'w':
        case 72:
                snake.direction = UP;
            break;
        case 'S':
        case 's':
        case 80:
            snake.direction = DOWN;

            break;
        case 'D':
        case 'd':
        case 77:
            snake.direction = RIGHT;

            break;
        case 'A':
        case 'a':
        case 75:
            snake.direction = LEFT;

            break;
        default:
            break;

        }
    }
}

void StartGame()
{
    initgraph(600, 600);
    setbkcolor(RGB(210, 255, 200));
    cleardevice();
    /*setfillcolor(RED);
    fillrectangle(300, 300, 600, 600);*/
   
}

int main()
{
    StartGame();
    InitSnake();
    
    while (1)
    {
        DrawSnake();
        RunSnake();
        userKey();

        Sleep(50);//降慢速度
    }
    closegraph();
    return 0;
}