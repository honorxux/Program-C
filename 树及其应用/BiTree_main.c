#include "BinaryTree.h"

int main()
{
	BiTree T;
	int opt;
	CSTree Tree;
	printf("ѡ����,��������1��ʾ�Ѷ�A����������2��ʾ����ת���ɶ�����:");
	scanf("%d",&opt);
	getchar(); 
	printf("\n"); 
	switch (opt)
	{
	 case 1: 
	    InitBiTree(&T);
	    printf("������˳��������Ҫ�����Ķ��������ֵ,��'#'�����\n"); 
	    CreateBiTree(&T);
	    printf("ǰ����������� T = ");
	    PreOrderTraverse(T);
	    printf("\n\n"); 
	
	    printf("������������� T = ");
	    InOrderTraverse(T, PrintElem);
	    printf("\n\n");
	
	    printf("������������� T = ");
	    PostOrderTraverse(T, PrintElem);
	    printf("\n\n");
	    break; 
	case 2:
	    printf("����α���˳�������������еĽ�㣬���뷽ʽΪ 'parent''child' ��:AB,BΪ��� AΪB��˫�ף�\n");
		CreatTree(&Tree);
	    printf("ͨ����������������ת���ɵĶ�����BT=");
	    PreOrderTraverse_t(Tree);
        printf("\n");
	    break;
    }
	return 0;
}

