#ifndef _MAZE_H_
#define _MAZE_H_
 
#include <stdio.h>		
#include <stdlib.h> 					//提供system、rand、srand原型 
#include <time.h>
#define X 4								//X用于随机数取余，其生成的随机数范围是0->x-1	X越大，生成可通行迷宫的概率就越大
#define RANGE 100
#define STACK_INIT_SIZE	100				//顺序栈存储空间的初始分配量
#define STACKINCREMENT	10 				//顺序栈存储空间的分配增量
#define OK 1
#define OVERFLOW -2
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;


typedef enum{                          //迷宫通道块类型
	Wall,                              //外墙 
	East,                              //访问方向-东南西北 
	South,
	West,
	North,
	Obstacle,							//迷宫障碍 
	Way,								//路径 
	DeadLock                            //路径上的“死胡同”
}MazeNode;

typedef struct							//迷宫通道块坐标
{
	int x;								//通道块的横、纵坐标定义 
	int y;
}PosType;

typedef struct							//通道块信息 
{
	int		ord;						//通道块的“序号” 
	PosType seat;						//通道块的“坐标位置” 
	int		di;							//下一个该访问的“方向” 
}SElemType_Sq;

typedef struct NodeType
{
    SElemType_Sq data;   
	struct NodeType *next; 
}  NodeType,*LinkType; //结点类型，指针类型

typedef struct
{
	SElemType_Sq *base;				//在栈构造之前和销毁之后，base的值为NULL 
	SElemType_Sq *top;				//栈顶指针 
	int stacksize;					//当前已分配的存储空间，以元素为单位 
}SqStack;

typedef struct
{
    int N,M ;  //M行数 N列数 
	char  arr[RANGE] [RANGE];       
} MazeType;

void InitMaze(MazeType *,int ,int ,PosType *start, PosType *end);
void PrintMaze(MazeType *,int ,int );
int Mazepath(MazeType *, PosType , PosType );
int InitStack_Sq(SqStack *S);
int Pass(PosType seat, MazeType *);
int IsCross(PosType seat,MazeType *maze);
void FootPrint(PosType seat, MazeType *maze);
void SetSElemType(SElemType_Sq *e, int ord, PosType seat, int di);
int Push_Sq(SqStack *S, SElemType_Sq e);
int Pop_Sq(SqStack *S, SElemType_Sq *e);
int StackEmpty_Sq(SqStack S);
int EqualPosType(PosType a, PosType b);
PosType NextPos(PosType seat, int di); 
void MazeRoute(SqStack *S);
#endif
