#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// 游戏参数默认值
#define DEFAULT_WIDTH 40
#define DEFAULT_HEIGHT 20
#define DEFAULT_SPEED 200

// 颜色定义
#define COLOR_WALL 12  // 红色
#define COLOR_SNAKE 10 // 绿色
#define COLOR_FOOD 14  // 黄色
#define COLOR_TEXT 7   // 白色

// 方向定义
typedef enum {
    UP, DOWN, LEFT, RIGHT
} Direction;

// 坐标结构
typedef struct {
    int x;
    int y;
} Position;

// 游戏全局变量
int width, height;           // 地图大小
int speed;                   // 游戏速度（毫秒）
Position snake[100];         // 蛇身体，最大长度100
int snakeLength;             // 蛇当前长度
Direction dir;             // 当前方向
Position food;               // 食物位置
int score;                   // 得分
int gameOver;                // 游戏结束标志

// 函数声明
void setup();                // 游戏初始化
void draw();                 // 绘制游戏界面
void input();                // 处理输入
void logic();                // 游戏逻辑
void setCursorPosition(int x, int y); // 设置光标位置
void setColor(int color);    // 设置颜色
void gameMenu();             // 游戏菜单
void resetGame();            // 重置游戏

// 设置光标位置
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

// 设置颜色
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// 游戏菜单
void gameMenu() {
    system("cls");
    setColor(COLOR_TEXT);

    printf("\n\t	===== 贪吃蛇游戏 =====\n\n");
    printf("\t	1. 开始游戏\n");
    printf("\t	2. 设置游戏参数\n");
    printf("\t	3. 退出游戏\n\n");
    printf("\t	请选择：");

    char choice = getch();

    switch (choice) {
        case '1':
            // 使用默认参数
            width = DEFAULT_WIDTH;
            height = DEFAULT_HEIGHT;
            speed = DEFAULT_SPEED;
            break;
        case '2':
            // 自定义参数
            system("cls");
            printf("\n\t	===== 游戏设置 =====\n\n");
            printf("\t	输入地图宽度 (10-80): ");
            scanf("%d", &width);
            printf("\t\t输入地图高度 (10-40): ");
            scanf("%d", &height);
            printf("\t\t输入游戏速度 (50-500毫秒): ");
            scanf("%d", &speed);

            // 限制参数范围
            width = (width < 10) ? 10 : (width > 80) ? 80 : width;
            height = (height < 10) ? 10 : (height > 40) ? 40 : height;
            speed = (speed < 50) ? 50 : (speed > 500) ? 500 : speed;
            break;
        case '3':
            exit(0);
        default:
            gameMenu();
    }
}

// 重置游戏
void resetGame() {
    snakeLength = 3;
    dir = RIGHT;
    score = 0;
    gameOver = 0;

    // 初始化蛇位置，从屏幕中间开始
    for (int i = 0; i < snakeLength; i++) {
        snake[i].x = width / 2 - i;
        snake[i].y = height / 2;
    }

    // 生成初始食物
    food.x = rand() % (width - 2) + 1;
    food.y = rand() % (height - 2) + 1;
}

// 处理键盘输入
void input() {
    if (_kbhit()) {  // 检查是否有按键按下
        int key = getch();  // 获取第一个字符

        // 处理方向键（方向键会返回两个字符：0或224，然后是具体方向码）
        if (key == 0 || key == 224) {
            key = getch();  // 获取方向键的第二个字符
            switch (key) {
                case 72:  // 上箭头
                    if (dir != DOWN) dir = UP;
                    break;
                case 80:  // 下箭头
                    if (dir != UP) dir = DOWN;
                    break;
                case 75:  // 左箭头
                    if (dir != RIGHT) dir = LEFT;
                    break;
                case 77:  // 右箭头
                    if (dir != LEFT) dir = RIGHT;
                    break;
            }
        } else {
            // 处理其他按键
            switch (key) {
                case 27:  // ESC键退出游戏
                    gameOver = 1;
                    break;
                case 'r':
                case 'R':  // R键重新开始
                    resetGame();
                    break;
            }
        }
    }
}

// 绘制游戏界面
void draw() {
    setCursorPosition(0, 0);  // 回到屏幕左上角

    // 绘制上边界
    setColor(COLOR_WALL);
    for (int i = 0; i < width; i++) {
        printf("□");
    }
    printf("\n");

    // 绘制左右边界和游戏区域
    for (int i = 0; i < height - 2; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                // 左右边界
                setColor(COLOR_WALL);
                printf("□");
            } else {
                // 游戏区域
                int isSnake = 0;
                int isFood = 0;

                // 检查是否是蛇身体
                for (int k = 0; k < snakeLength; k++) {
                    if (snake[k].x == j && snake[k].y == i + 1) {
                        isSnake = 1;
                        break;
                    }
                }

                // 检查是否是食物
                if (food.x == j && food.y == i + 1) {
                    isFood = 1;
                }

                if (isSnake) {
                    setColor(COLOR_SNAKE);
                    printf("●");
                } else if (isFood) {
                    setColor(COLOR_FOOD);
                    printf("★");
                } else {
                    // 空白区域
                    printf("  ");
                }
            }
        }
        printf("\n");
    }

    // 绘制下边界
    setColor(COLOR_WALL);
    for (int i = 0; i < width; i++) {
        printf("□");
    }
    printf("\n");

    // 显示游戏信息
    setColor(COLOR_TEXT);
    printf("\n得分: %d  ", score);
    printf("长度: %d  ", snakeLength);
    printf("速度: %dms  ", speed);
    printf("\n控制: 方向键移动  ");
    printf("ESC: 退出游戏  ");
    printf("R: 重新开始\n");
}

// 游戏逻辑
void logic() {
    // 保存蛇尾位置（用于吃到食物时长身体）
    Position tail = snake[snakeLength - 1];

    // 移动蛇身体，从后往前移动
    for (int i = snakeLength - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    // 移动蛇头
    switch (dir) {
        case UP:
            snake[0].y--;
            break;
        case DOWN:
            snake[0].y++;
            break;
        case LEFT:
            snake[0].x--;
            break;
        case RIGHT:
            snake[0].x++;
            break;
    }

    // 撞墙检测（重新开始游戏）
    if (snake[0].x <= 0 || snake[0].x >= width - 1 || snake[0].y <= 0 || snake[0].y >= height - 1) {
        resetGame();
        return;
    }

    // 碰自己检测
    for (int i = 1; i < snakeLength; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            resetGame();
            return;
        }
    }

    // 吃食物检测
    if (snake[0].x == food.x && snake[0].y == food.y) {
        score += 10;                // 增加得分
        snakeLength++;              // 增加蛇长度
        snake[snakeLength - 1] = tail;  // 身体变长

        // 重新生成食物，确保不在蛇身上
        int foodOnSnake;
        do {
            foodOnSnake = 0;
            food.x = rand() % (width - 2) + 1;
            food.y = rand() % (height - 2) + 1;

            for (int i = 0; i < snakeLength; i++) {
                if (food.x == snake[i].x && food.y == snake[i].y) {
                    foodOnSnake = 1;
                    break;
                }
            }
        } while (foodOnSnake);
    }
}

// 游戏初始化
void setup() {
    srand(time(0));  // 随机数种子
    resetGame();     // 重置游戏

    // 隐藏光标
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

int main() {
    gameMenu();              // 显示游戏菜单
    setup();                 // 初始化游戏

    while (!gameOver) {
        draw();             // 绘制界面
        input();            // 处理输入
        logic();            // 更新游戏逻辑
        Sleep(speed);       // 控制游戏速度
    }

    return 0;
}