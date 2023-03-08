#include <graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
typedef struct MyStruct {
    int x;
    int y;
}POS;


struct food {
    POS position;
    int flag = 0;//ʳ���Ƿ����
}food;

struct snake {
    POS position[100];
    int length;
    int direction;
}snake;

enum MyEnum {
    UP, DOWN, LEFT, RIGHT
};

//��ʼ���ߣ�ȷ����ʼ״̬��λ��
void InitSnake()
{
    snake.length = 3;
    snake.direction = RIGHT;
    int i = 0;

    for (i = 0; i < snake.length; i++) {
        snake.position[i].x = 200 - 10 * i;
        snake.position[i].y = 200;
    }
}

//��ʼ��ʳ�ȷ������
void InitFood()
{
    srand((unsigned int)time(NULL));
    food.position.x = rand() % 40 * 10;//����0-590
    food.position.y = rand() % 40 * 10;//����0-590
    food.flag = 0;
}

//����
void DrawSnake()
{
    cleardevice();
    int i = 0;
    for (i = 0; i < snake.length; i++)
    {

        setfillcolor(RED);
        fillrectangle(snake.position[i].x, snake.position[i].y, snake.position[i].x + 10, snake.position[i].y + 10);
    }
}



//��ʳ��
void DrawFood()
{
    if (food.flag == 0)
    {
        food.position.x = rand() % 40 * 10;//����0-390
        food.position.y = rand() % 40 * 10;//����0-390
    }
    setfillcolor(BLUE);
    fillrectangle(food.position.x, food.position.y, food.position.x + 10, food.position.y + 10);
    food.flag = 1;
}

//�ж��Ƿ��ʳ
void FoodConsume()
{

    if ((food.position.x == snake.position[0].x) && (food.position.y == snake.position[0].y))
    {
        snake.length++;
        food.flag = 0;
    }
}
//�˶�����
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

//����
void userKey()
{
    if (_kbhit())//����Ƿ��а�������
    {
        char ch = _getch();
        switch (ch)
        {
        case 'W':
        case 'w':
        case 72:
            if (snake.direction != DOWN)
            {
                snake.direction = UP;
            }
            break;
        case 'S':
        case 's':
        case 80:
            if (snake.direction != UP)
            {
                snake.direction = DOWN;
            }
            break;
        case 'D':
        case 'd':
        case 77:
            if (snake.direction != LEFT)
            {
                snake.direction = RIGHT;
            }
            break;
        case 'A':
        case 'a':
        case 75:
            if (snake.direction != RIGHT)
            {
                snake.direction = LEFT;
            }
            break;
        default:
            break;

        }
    }
}


//��ʼ��ʳ��
void StartGame()
{
    initgraph(400, 400);

    /*setfillcolor(RED);
    fillrectangle(300, 300, 600, 600);*/

}

//��������
void GameDraw()
{
    setbkcolor(RGB(210, 255, 200));
    cleardevice();
}
int Die()
{
    for (int i = 1; i < snake.length; i++)
    {
        if (snake.position[0].x == snake.position[i].x && snake.position[0].y == snake.position[i].y)
        {
            return 1;
        }
    }
    if (snake.position[0].x == -20 || snake.position[0].y == -20 || snake.position[0].x == 410 || snake.position[0].y == 410)
    {
        return 1;
    }
    return 0;
}

int main()
{
    srand((unsigned int)time(NULL));
    StartGame();
    InitSnake();

    InitFood();
    cleardevice();
    while (true)
    {
        BeginBatchDraw();
        cleardevice();
        GameDraw();//����Ҫ����ͼ���뺯����
        DrawSnake();
        Sleep(50);//�����ٶ�
        FoodConsume();
        RunSnake();
        userKey();
        DrawFood();
        int ret = Die();
        if (ret == 1)
        {
            break;
        }
        FlushBatchDraw();

    }
    printf("��Ϸ����");

    closegraph();
    return 0;
}