#include "maze.h"

void InitMaze(MazeType *maze,int M,int N, PosType *start, PosType *end) 
{												//�Թ���ģΪM��N 
	int i, j, tmp;
		
	srand((unsigned)time(NULL));				//��ϵͳʱ������������� 
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<M; j++)
		{
			if(i==0 || j==0 || i==N-1 || j==M-1)
				(*maze).arr[i][j] = Wall;				//�Թ���ǽ
			else
			{
				tmp = rand()%X;					//�������������Թ� 		
				if(!tmp)
					(*maze).arr[i][j] = Obstacle;		//1/X�ĸ��������ϰ� 
				else
					(*maze).arr[i][j] = Way;			//�����ط�����·�� 
			}
		}	
	}
	
	(*start).x = 1;								//�Թ����
	(*start).y = 0;
	(*end).x = N-2;								//�Թ����� 
	(*end).y = M-1;	
	
	(*maze).arr[1][0] = (*maze).arr[N-2][M-1] = Way;			//������ںͳ��� 
	(*maze).arr[1][1] = (*maze).arr[N-2][M-2] = Way;			//Ϊ����߳ɹ��ʣ���ڴ��ͳ��ڴ��ٽ��Ľ��һֱ��Ϊͨ· 
}

void PrintMaze(MazeType *maze,int M,int N)
{
	int i, j;
	
	for(i=0; i<N; i++)
		for(j=0; j<M; j++)
		{
			if((*maze).arr[i][j]==Wall)				//��ǽ 
				printf("�~");
			else if((*maze).arr[i][j]==Obstacle)		//�ڲ��ϰ� 
				printf("��");
			else								//δ���ʹ���·����� 
				printf("  ");

			if(j!=0 && j%(M-1)==0)				//ÿ��N����㻻�� 
				printf("\n");
		}
}
int Mazepath(MazeType *maze, PosType start, PosType end)
{
	SqStack S;
	SElemType_Sq nodeInf;					//nodeInf�洢��ǰͨ������Ϣ 
	PosType curPos;							//��ǰλ�� 
	int curStep;							//��ǰͨ������� 
	MazeType MAZE=*maze;
	InitStack_Sq(&S);
	curPos = start;							//�趨��ǰλ��Ϊ"���λ��" 
	curStep = 1;
	
	do{
		if(Pass(curPos, &MAZE))
		{
			FootPrint(curPos, &MAZE);		//�����㼣
			SetSElemType(&nodeInf, curStep, curPos, East);	//����ͨ������Ϣ
			Push_Sq(&S, nodeInf); 			//����·�� 
			
			if(curPos.x==end.x && curPos.y==end.y)	//�����յ�
			{
				printf("\nѰ·�ɹ�����\n\n");
				printf("·��Ϊ��\n") ;
				MazeRoute(&S);
			    return TRUE;	
			}
			
			curPos = NextPos(curPos, East);	//��һλ���ǵ�ǰλ�õĶ��� 
			curStep++;						//̽����һ�� 
		}
		else								//��ǰλ�ò���ͨ�� 
		{
			if(!StackEmpty_Sq(S))
			{
				Pop_Sq(&S, &nodeInf);		//�޸Ľ��ָ��
				 
				while(nodeInf.di==North && !StackEmpty_Sq(S))	//��ͨ����4�����򶼱����� 
				{
					MarkPrint(nodeInf.seat, maze);				//���²���ͨ���ı�ǣ����˻�һ�� 
				

					Pop_Sq(&S, &nodeInf);
				}

				if(nodeInf.di<North)
				{
					(*maze).arr[nodeInf.seat.x][nodeInf.seat.y] = ++nodeInf.di;//�ı�̽���������Թ����������±��	

					Push_Sq(&S, nodeInf);

					curPos = NextPos(nodeInf.seat, nodeInf.di);
				}
			}
		}		
	}while(!StackEmpty_Sq(S));
	
    printf("\nѰ·ʧ�ܣ���\n\n");
	
	return FALSE;
     
}





