#include "maze.h"

void InitMaze(MazeType *maze,int M,int N, PosType *start, PosType *end) 
{												//迷宫规模为M×N 
	int i, j, tmp;
		
	srand((unsigned)time(NULL));				//用系统时间做随机数种子 
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			if(i==0 || j==0 || i==N-1 || j==M-1)
				(*maze).arr[i][j] = Wall;				//迷宫外墙
			else
			{
				tmp = rand()%X;					//生成随机数填充迷宫 		
				if(!tmp)
					(*maze).arr[i][j] = Obstacle;		//1/X的概率生成障碍 
				else
					(*maze).arr[i][j] = Way;			//其它地方加入路径 
			}
		}	
	}
	
	(*start).x = 1;								//迷宫入口
	(*start).y = 0;
	(*end).x = N-2;								//迷宫出口 
	(*end).y = M-1;	
	
	(*maze).arr[1][0] = (*maze).arr[N-2][M-1] = Way;			//开放入口和出口 
	(*maze).arr[1][1] = (*maze).arr[N-2][M-2] = Way;			//为了提高成功率，入口处和出口处临近的结点一直设为通路 
}

void PrintMaze(MazeType *maze,int M,int N)
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
		{
			if((*maze).arr[i][j]==Wall)				//外墙 
				printf("▇");
			else if((*maze).arr[i][j]==Obstacle)		//内部障碍 
				printf("▓");
			else								//未访问过的路径结点 
				printf("  ");

			if(j!=0 && j%(M-1)==0)				//每隔N个结点换行 
				printf("\n");
		}
}
int Mazepath(MazeType *maze, PosType start, PosType end)
{
	SqStack S;
	SElemType_Sq nodeInf;					//nodeInf存储当前通道块信息 
	PosType curPos;							//当前位置 
	int curStep;							//当前通道块序号 
	MazeType MAZE=*maze;
	InitStack_Sq(&S);
	curPos = start;							//设定当前位置为"入口位置" 
	curStep = 1;
	
	do{
		if(Pass(curPos, &MAZE))
		{
			FootPrint(curPos, &MAZE);		//留下足迹
			SetSElemType(&nodeInf, curStep, curPos, East);	//设置通道块信息
			Push_Sq(&S, nodeInf); 			//加入路径 
			
			if(curPos.x==end.x && curPos.y==end.y)	//到达终点
			{
				printf("\n寻路成功！！\n\n");
				printf("路径为：\n") ;
				MazeRoute(&S);
			    return TRUE;	
			}
			
			curPos = NextPos(curPos, East);	//下一位置是当前位置的东邻 
			curStep++;						//探索下一步 
		}
		else								//当前位置不能通过 
		{
			if(!StackEmpty_Sq(S))
			{
				Pop_Sq(&S, &nodeInf);		//修改结点指向
				 
				while(nodeInf.di==North && !StackEmpty_Sq(S))	//此通道块4个方向都遍历过 
				{
					MarkPrint(nodeInf.seat, maze);				//留下不能通过的标记，并退回一步 
				

					Pop_Sq(&S, &nodeInf);
				}

				if(nodeInf.di<North)
				{
					(*maze).arr[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;//改变探索方向，在迷宫数组中留下标记	

					Push_Sq(&S, nodeInf);

					curPos = NextPos(nodeInf.seat, nodeInf.di);
				}
			}
		}		
	}while(!StackEmpty_Sq(S));
	
    printf("\n寻路失败！！\n\n");
	
	return FALSE;
     
}





