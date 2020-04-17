#ifndef _MAZE_H_
#define _MAZE_H_
 
#include <stdio.h>		
#include <stdlib.h> 					//�ṩsystem��rand��srandԭ�� 
#include <time.h>
#define X 4								//X���������ȡ�࣬�����ɵ��������Χ��0->x-1	XԽ�����ɿ�ͨ���Թ��ĸ��ʾ�Խ��
#define RANGE 100
#define STACK_INIT_SIZE	100				//˳��ջ�洢�ռ�ĳ�ʼ������
#define STACKINCREMENT	10 				//˳��ջ�洢�ռ�ķ�������
#define OK 1
#define OVERFLOW -2
#define TRUE 1
#define ERROR 0
#define FALSE 0

typedef int Status;


typedef enum{                          //�Թ�ͨ��������
	Wall,                              //��ǽ 
	East,                              //���ʷ���-�������� 
	South,
	West,
	North,
	Obstacle,							//�Թ��ϰ� 
	Way,								//·�� 
	DeadLock                            //·���ϵġ�����ͬ��
}MazeNode;

typedef struct							//�Թ�ͨ��������
{
	int x;								//ͨ����ĺᡢ�����궨�� 
	int y;
}PosType;

typedef struct							//ͨ������Ϣ 
{
	int		ord;						//ͨ����ġ���š� 
	PosType seat;						//ͨ����ġ�����λ�á� 
	int		di;							//��һ���÷��ʵġ����� 
}SElemType_Sq;

typedef struct NodeType
{
    SElemType_Sq data;   
	struct NodeType *next; 
}  NodeType,*LinkType; //������ͣ�ָ������

typedef struct
{
	SElemType_Sq *base;				//��ջ����֮ǰ������֮��base��ֵΪNULL 
	SElemType_Sq *top;				//ջ��ָ�� 
	int stacksize;					//��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ 
}SqStack;

typedef struct
{
    int N,M ;  //M���� N���� 
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
