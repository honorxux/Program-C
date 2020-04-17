#include "BinaryTree.h"

int main()
{
	BiTree T;
	int opt;
	CSTree Tree;
	printf("选择功能,键入数字1演示难度A，键入数字2演示由树转换成二叉树:");
	scanf("%d",&opt);
	getchar(); 
	printf("\n"); 
	switch (opt)
	{
	 case 1: 
	    InitBiTree(&T);
	    printf("按先序顺序输入你要建立的二叉树结点值,用'#'代表空\n"); 
	    CreateBiTree(&T);
	    printf("前序遍历二叉树 T = ");
	    PreOrderTraverse(T);
	    printf("\n\n"); 
	
	    printf("中序遍历二叉树 T = ");
	    InOrderTraverse(T, PrintElem);
	    printf("\n\n");
	
	    printf("后序遍历二叉树 T = ");
	    PostOrderTraverse(T, PrintElem);
	    printf("\n\n");
	    break; 
	case 2:
	    printf("按层次遍历顺序依次输入树中的结点，输入方式为 'parent''child' 如:AB,B为结点 A为B的双亲：\n");
		CreatTree(&Tree);
	    printf("通过先序遍历输出由树转换成的二叉树BT=");
	    PreOrderTraverse_t(Tree);
        printf("\n");
	    break;
    }
	return 0;
}

