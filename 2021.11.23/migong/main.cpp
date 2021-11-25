# include <iostream>
using namespace std;
#include"stack.h"

bool findPath(Stack& s, int M, int N);


int main()
{
    
    int M, N;
    bool res;
    cout << "请输入迷宫数组行数：";
    cin >> M;
    cout << "请输入迷宫数组列数：";
    cin >> N;
    //初始化栈
    Stack s;
    s.initStack(&s);
    res = findPath(s, M, N);
    cout << boolalpha << res << endl;	//将bool转换为true/false显示
    cout << endl;
    if(res)
        s.traverse(&s);
    else
        cout << "你被困在迷宫中了，等着受死吧！" << endl;
    return 0;

}

bool findPath(Stack& s, int M, int N)
{
    int **maze = new int*[M+2];		//动态构造二维数组
    for(int i = 0; i < 10; i++){
        maze[i] = new int[N+2];
    }

    for(int i = 0; i < M+2; i++){	//动态给定迷宫
        for(int j = 0; j < N+2; j++){
            if(i == 0 || i == M+1)
                maze[i][j] = 1;
            else if(j == 0 || j == N+1)
                maze[i][j] = 1;
            else
                cin >> maze[i][j];
        }
    }

    Direction direct[4];		//方向数组（文章上面有图有说到）
    direct[0].incX = 0; direct[0].incY = 1;
    direct[1].incX = 1; direct[1].incY = 0;
    direct[2].incX = 0; direct[2].incY = -1;
    direct[3].incX = -1; direct[3].incY = 0;

    Box temp;
    int x, y, di;      //当前正在处理的迷宫格子
    int line, col;    //迷宫格子预移方向后，下一格子的行坐标、列坐标
    maze[1][1] = -1;
    temp.x = 1;
    temp.y = 1;
    temp.di = -1;		//起始点直接设置为-1代表该格子已访问过了
    s.pushStack(&s, temp);
    while(!s.isEmpty(&s))
    {
        s.pop(&s, temp);	//这里对遇到走不通的格子进行回退时起到关键作用
        x = temp.x; y = temp.y; di = temp.di+1;
        while(di < 4){  //走不通时，四个方向都尝试一遍
            line = x + direct[di].incX;
            col = y + direct[di].incY;
            if(maze[line][col] == 0){	//代表 预走 的格子可以走
                temp.x = x; temp.y = y; temp.di = di;
                s.pushStack(&s, temp);
                x = line; y = col; maze[line][col] = -1;	//标为-1是为了表明该格子已经走过，回溯时不再处理
                if(x == M && y == N){
                        s.reverse(s, temp);
                        return true;   //迷宫有路
                    }
                else di = 0;
            }
            else di++;
        }
    }
    return false;       //迷宫无路
}