#include "BeelzebubLang.h"

int main()
{
	int i=0,cnt; 
	SqStack ChStack; //����һ���ַ�ջ����ChStack 
	SqQueue ChQueue; //����һ���ַ����б���ChQueue 
	SqStack TransLang; //��������ת������ַ� 
	char string[100];
	printf("������ħ�����Դ�\n"); 
    gets(string);
//    scanf("%s",string);
	
	InitStack(&ChStack); //��ʼ��ջ
	InitQueue(&ChQueue); //��ʼ������
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
		
		switch(e) //�����¼��������ħ�����Դ����ղ���ʽ���з���
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
						Push(&TransLang,'Q');     //Q������ʾ��ջ����һ������ 
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
		
		switch(e) //�����¼��������ħ�����Դ����ղ���ʽ���з���
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
