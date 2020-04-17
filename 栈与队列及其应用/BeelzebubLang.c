#include "BeelzebubLang.h"

int main()
{
	int i=0,cnt; 
	SqStack ChStack; //定义一个字符栈变量ChStack 
	SqQueue ChQueue; //定义一个字符队列变量ChQueue 
	SqStack TransLang; //用来保存转换后的字符 
	char string[100];
	printf("请输入魔王语言串\n"); 
    gets(string);
//    scanf("%s",string);
	
	InitStack(&ChStack); //初始化栈
	InitQueue(&ChQueue); //初始化队列
	InitStack(&TransLang); 
	
	char e,ReverseFirstElem; 
	
	while(string[i])
	{
		Push(&ChStack,string[i]);
		i++;                             
	}
	
	while(!StackEmpty(&ChStack))
	{
		Pop(&ChStack,&e);
		
		switch(e) //分以下几种情况对魔王语言串按照产生式进行翻译
		{
			case'B':{
				        Push(&TransLang,e);
			        	break;
			    }
			case'A':{
				        Push(&TransLang,e);
				        break;
		        }
		    case')':{
		    	        Pop(&ChStack,&e);
						do{
		    	        	EnQueue(&ChQueue,e);
		    	        	Pop(&ChStack,&e);
						}while(e!='(');
						Push(&TransLang,'Q');     //Q用来表示进栈的是一个队列 
				        break;
			    }
			case'(':   break;
			default:{
				        Push(&TransLang,e);
				        break;
		        }
           }
       }


	while(!StackEmpty(&TransLang))
	{
		Pop(&TransLang,&e);
		
		switch(e) //分以下几种情况对魔王语言串按照产生式进行翻译
		{
			case'B':{
				
				        printf("tsaedsae"); 
			        	break;
			    }
			case'A':{
				        printf("sae");
				        break;
		        }
		    case'Q':{
		    	        for(cnt=1;cnt<QueueLength(&ChQueue);)
		    	        {
		    	        	printf("%c%c",ChQueue.base[ChQueue.rear-1],ChQueue.base[ChQueue.front]);
						    DeQueue(&ChQueue);
						}
						printf("%c",ChQueue.base[ChQueue.front]);
						DeQueue(&ChQueue);
				        break;
			    }
			
			    
			default:{
				        printf("%c",e);
				        break;
		        }
       	}
          }
	return 0;
}
