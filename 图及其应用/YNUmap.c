#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define Max 10000
#define NUM 27
typedef struct ArcCell{
int adj;          //���ڽӵľ���֮��ľ���
}ArcCell;         //����ߵ�����
typedef struct VertexType{
int number;      //������
char* sight;    //��������
char* info;    //��������
}VertexType;  //���嶥�������
typedef struct{
VertexType vex[NUM];    //ͼ�еĶ��㣬��Ϊ����
ArcCell arc[NUM][NUM]; //ͼ�еıߣ���Ϊ�����ľ���
int vexnum,arcnum;    //������������
}MGraph;              //����ͼ������
MGraph G;          //��ͼ����Ϊȫ�ֱ���
int P[NUM][NUM];
long int D[NUM];  //���������洢���·������
int  x[26]={0};
void Create(int v,int a); //��ͼ����
void List();    //�б���
void Path(int num); //���·������
void Output(int sight1,int sight2); //�������
char Menu();  //���˵�
void HaMiTonian(int);  //���ܶ���ͼ�ı���
void NextValue(int);
void display(); //��ʾ�������
void main() //������                                                                      ��1��
{
int v0,v1;
int i,num;
char flag;
Create(NUM,11);
do
{
flag=Menu();
switch(flag)
{
case '1':
system("cls");  //ִ��ϵͳ��������ǰ��Ļ��ʾ������
List();      //��������б�
printf("\n\n\t��ѡ����㾰�㣨0��26����");
scanf("%d",&v0);
printf("\t��ѡ���յ㾰�㣨0��26����");
scanf("%d",&v1);
Path(v0);  //������������֮������·��
Output(v0,v1);    //������
printf("\n\n\t�밴���������...\n");
getchar();  //����getchar()�����ó������е���һ��ʱ���ȴ�������һ�����ŷ���
getchar();
break;
case '2':
system("cls");
List();      //��������б�
printf("\n\n\t��������Ҫ���ҵľ����ţ�");
scanf("%d",&num);
for(i=0;i<NUM;i++)
{
if(num==G.vex[i].number)
{
printf("\n\n\t��Ҫ���Ҿ�����Ϣ����:");
printf("\n\n\t%s:",G.vex[i].sight);
printf("\t%s\n\n",G.vex[i].info);
printf("\n\t�����������...");
getchar();
getchar();
break;
}
}
if(i==NUM)
{
printf("\n\n\tû���ҵ���");
printf("\n\n\t�����������...");
getchar();
getchar();
}
break;
}
}while(flag!='0');
}
char Menu()  // ���˵�
{
char c;
int flag;
do{
flag=1;
system("cls");
List();                // ��������б�
printf("\n\t\t\t\t����������������������������������\n");
printf("\t\t\t                                  \n");
printf("\t\t\t          1����ѯ����·��            \n");
printf("\t\t\t          2����ѯ������Ϣ            \n");
printf("\t\t\t          0���˳�                    \n");
printf("\t\t\t                                  \n");
printf("\t\t\t\t����������������������������������\n");
printf("\t����������ѡ��");
scanf("%c",&c);
if(c=='1'||c=='2'||c=='0')
flag=0;
}while(flag);
return c;
}                                                                                      
void Create(int v,int a) //����ͼ����                                                   
{
int i,j;
G.vexnum=v;  //��ʼ���ṹ�еľ������ͱ���
G.arcnum=a;
for(i=0;i<G.vexnum;++i)
G.vex[i].number=i; //��ʼ��ÿһ������ı��
//��ʼ��ûһ�����������侰������
G.vex[0].sight="�ƴ�������";
G.vex[0].info="���ϴ�ѧ��������Ŀǰ���ϴ�ѧ��Ҫ�Ľ�����";
G.vex[1].sight="�ټҵ�";
G.vex[1].info="���������ŵ�һ�������ֱ��ͨ��У԰�����ط�";
G.vex[2].sight="�ĵ�㳡";
G.vex[2].info="ѧУ�����ش��Ĺ㳡�����⻹�����������������ʽ";
G.vex[3].sight="�ƴ����";
G.vex[3].info="������ѧУ������Ҫ�������ʽ�����ڳ����Լ�ѧ�������";
G.vex[4].sight="��ɽ�¥";
G.vex[4].info="��ѧ¥��һ¥����ѧ���������ģ���ѧ�����ͽ��񴦵İ칫���ڵ�";
G.vex[5].sight="��ֹ¥";
G.vex[5].info="���ϴ�ѧͼ���";
G.vex[6].sight="��Է";
G.vex[6].info="�о�������������";
G.vex[7].sight="�Է";
G.vex[7].info="����ѧԺ����ϢѧԺ������ѧԺ������ѧԺ���ǽ�ѧԺ����ͳѧԺ���мӺ�����Ŀ��ѧԺ��ѧ������������";
G.vex[8].sight="����¥";
G.vex[8].info="�ۺϽ�ѧ¥����ϰ�ң�һ��������ѧԺ��ѧ���Ϲ����κ���ϰ";
G.vex[9].sight="�Է������";
G.vex[9].info="ѧ���������κͽ������������ĵط���Ŀǰ�������򳡡����򳡡����򳡺��ﾶ��";
G.vex[10].sight="֪ζ��";
G.vex[10].info="ѧ�����������ж���һ��ʳ�á�һ����ζʳ�ú�һ������ʳ��";
G.vex[11].sight="�Է����";
G.vex[11].info="���ϴ�ѧ���ڽ�������֮һ��Ϊѧ���ṩ��������ѧϰ��Ʒ";
G.vex[12].sight="�ۺϷ���¥";
G.vex[12].info="�ۺϷ������ģ�һ¥���г��С�ҩ�ꡢ�۾��ꡢ��Ʒ�ꡢũ��ATM���Ͳ��ң���¥��ѧУѧ���ᡢ����ί�������ȸ�У���İ칫��";
G.vex[13].sight="�Է";
G.vex[13].info="���ѧԺ�����ѧԺ������ѧԺ������ѧԺ���ʻ�ѧԺ��ѧԺ��ѧ������������";
G.vex[14].sight="����¥";
G.vex[14].info="������ѧ¥��һ¥���й�������";
G.vex[15].sight="���¥";
G.vex[15].info="���ѧԺ�����칫¥��ʵ��¥";
G.vex[16].sight="УҽԺ";
G.vex[16].info="ѧ��ҽ�Ƴ���";
G.vex[17].sight="��Զ¥";
G.vex[17].info="��ѧ¥�����ڽ��赱��";
G.vex[18].sight="�������";
G.vex[18].info="����ѧУ�����ŵĵ�·";
G.vex[19].sight="�����칫¥";
G.vex[19].info="ѧУ�����칫�������ڵ�";
G.vex[20].sight="�ƴ���";
G.vex[20].info="ѧУ������";
G.vex[21].sight="�Ļ�¥";
G.vex[21].info="�Ŀ�ѧԺ��ѧ¥";
G.vex[22].sight="��ζ��";
G.vex[22].info="ѧ���Է��ĵط������ж���һ��ʳ�ú�һ������ʳ��";
G.vex[23].sight="��Է����";
G.vex[23].info="���У�Ϊѧ���ṩ��������ѧϰ��Ʒ";
G.vex[24].sight="��Է";
G.vex[24].info="����ѧԺ������ѧԺ������ѧԺ�������ѧԺ�ͷ�ѧԺ��ѧ��������";
G.vex[25].sight="��¥";
G.vex[25].info="�ƴ��־�Խ���֮һ��ÿ���Ͽε���������������";
G.vex[26].sight="У���˳���";
G.vex[26].info="�����ڴ˳���У����У����";
//��������еı߼ٶ�Ϊ10000������������������֮���ǲ��ɵ���
for(i=0;i<G.vexnum;++i)
for(j=0;j<G.vexnum;++j)
G.arc[i][j].adj=Max;
//�±��ǿ�ֱ�ӵ���ľ����ľ��룬�����������������ǻ���ģ�����Ҫ��ͼ�жԳƵı�ͬʱ��ֵ
G.arc[0][1].adj=G.arc[1][0].adj=10;
G.arc[1][2].adj=G.arc[2][1].adj=20;
G.arc[2][3].adj=G.arc[3][2].adj=20;
G.arc[1][4].adj=G.arc[4][1].adj=50;
G.arc[4][5].adj=G.arc[5][4].adj=200;
G.arc[4][6].adj=G.arc[6][4].adj=130;
G.arc[5][7].adj=G.arc[7][5].adj=600;
G.arc[5][8].adj=G.arc[8][5].adj=800;
G.arc[5][9].adj=G.arc[9][5].adj=600;
G.arc[7][8].adj=G.arc[8][7].adj=100;
G.arc[7][9].adj=G.arc[9][7].adj=600;
G.arc[7][10].adj=G.arc[10][7].adj=150;
G.arc[7][11].adj=G.arc[11][7].adj=110;
G.arc[7][12].adj=G.arc[12][7].adj=100;
G.arc[8][12].adj=G.arc[12][8].adj=80;
G.arc[9][11].adj=G.arc[11][9].adj=700;
G.arc[10][11].adj=G.arc[11][10].adj=5;
G.arc[10][12].adj=G.arc[12][10].adj=50;
G.arc[10][13].adj=G.arc[13][10].adj=150;
G.arc[12][13].adj=G.arc[13][12].adj=100;
G.arc[12][26].adj=G.arc[26][12].adj=20;
G.arc[13][14].adj=G.arc[14][13].adj=200;
G.arc[13][15].adj=G.arc[15][13].adj=250;
G.arc[13][16].adj=G.arc[16][13].adj=700;
G.arc[13][26].adj=G.arc[26][13].adj=100;
G.arc[14][15].adj=G.arc[15][14].adj=20;
G.arc[14][16].adj=G.arc[16][14].adj=500;
G.arc[14][17].adj=G.arc[17][14].adj=1500;
G.arc[16][17].adj=G.arc[17][16].adj=1300;
G.arc[17][18].adj=G.arc[18][17].adj=50;
G.arc[17][25].adj=G.arc[25][17].adj=300;
G.arc[18][19].adj=G.arc[19][18].adj=30;
G.arc[19][20].adj=G.arc[20][19].adj=100;
G.arc[20][21].adj=G.arc[21][20].adj=950;
G.arc[20][22].adj=G.arc[22][20].adj=900;
G.arc[21][22].adj=G.arc[22][21].adj=150;
G.arc[21][24].adj=G.arc[24][21].adj=110;
G.arc[21][25].adj=G.arc[25][21].adj=750;
G.arc[22][23].adj=G.arc[23][22].adj=40;
G.arc[22][24].adj=G.arc[24][22].adj=120;
G.arc[23][24].adj=G.arc[24][23].adj=60;
G.arc[24][1].adj=G.arc[1][24].adj=300;
}
void List() //�����б���
{
int i,k=0;
printf("\n\t\t********************��ӭʹ��У԰���γ���******************\n");
printf("\n\t\t**********************************************************\n");
printf("\t\t\t\t        ��������  \t\t\t");
printf("\n\t\t__________________________________________________________\n");
for(i=0;i<NUM;i++)
{
printf("\t\t��  \t\t(%2d)%-10s\t\t\t\t��\n",i,G.vex[i].sight); //��������б�
k=k+1;
}
printf("\t\t__________________________________________________________\n");
}
void Path(int num) //�Ͻ�˹�����㷨���·������ numΪ��ڵ�ı��                     ��2��
{
int v,w,i,t;  //i��w��vΪ��������
int final[NUM];
int min;
for(v=0;v<NUM;v++)
{
final[v]=0;  //����Ӷ���num������vû�����·��
D[v]=G.arc[num][v].adj;//����֮��ص�Ȩֵ����D�д��
for(w=0;w<NUM;w++) //����Ϊ��·��
P[v][w]=0;
if(D[v]<20000)  //����·��
{
P[v][num]=1; // ���ڱ�־��Ϊһ
P[v][v]=1; // ��������
}
}
D[num]=0;
final[num]=1;      //��ʼ��num��������S����
//��ʼ��ѭ����ÿһ�����num��ĳ����������·������������뵽S����
for(i=0;i<NUM;++i)    //����G.vexnum-1������
{
min=Max;    //��ǰ��֪�붥��num���������
for(w=0;w<NUM;++w)
if(!final[w])    //w������v-s��
if(D[w]<min)  //w������num�������
{
v=w;
min=D[w];
}
final[v]=1;  //��num���������v���뵽s����
for(w=0;w<NUM;++w)  //���µ�ǰ���·���������
if(!final[w]&&((min+G.arc[v][w].adj)<D[w]))//����s���ϣ����ұ���ǰ���ҵ���·�����̾͸��µ�ǰ·��
{
D[w]=min+G.arc[v][w].adj;
for(t=0;t<NUM;t++)
P[w][t]=P[v][t];
P[w][w]=1;
}
}
}                                                                                      
void Output(int sight1,int sight2)    // �������
{
int a,b,c,d,q=0;
a=sight2;    //���������ֵ��a
if(a!=sight1)    //�����������;���һ�����غϣ������...
{
printf("\n\t��*%s*��*%s*�����·����",G.vex[sight1].sight,G.vex[sight2].sight);//�����ʾ��Ϣ
printf("\t(��̾���Ϊ:%dm.)\n\n\t",D[a]);  // ���sight1��sight2�����·�����ȣ������D[]������
printf("\t%s",G.vex[sight1].sight);  //�������һ������
d=sight1;      //������һ�ı�Ÿ�ֵ��d
for(c=0;c<NUM;++c)
{
gate:;        //��ţ�������Ϊgoto�����ת��λ��
P[a][sight1]=0;
for(b=0;b<NUM;b++)
{
if(G.arc[d][b].adj<20000&&P[a][b])  //�������һ������һ���ٽ��֮�����·�������·��
{
printf("-->%s",G.vex[b].sight);  //����˽ڵ������
q=q+1;    //����������һ����8�������ʱ�Ļ���
P[a][b]=0;
d=b;    // ��b��Ϊ�����������һ��ѭ���������˷���
if(q%9==0) printf("\n");
goto gate;  //ʹ��goto���ı�������� תȥִ�������gate����ʶ�����
}//if(G.arcs[d][b].adj<20000&&P[a][b])
}//for(b=0;b<NUM;b++)
} //for(c=0;c<NUM;++c)
}//if(a!=sight1)
}
void HaMiTonian(int m)  // ���ܶ���ͼ�ı���                                              
{
if(m>26)
return;
L: NextValue(m);  //��ţ�������Ϊgoto�����ת��λ��
if(x[m]==0)
return;
if(m==26&&G.arc[0][x[26]-1].adj!=0000)
display();
else
HaMiTonian(m+1);
goto  L;    //ʹ��goto���ı�������� תȥִ�������L����ʶ�����
}
void NextValue(int k)
{
int j;
l:x[k]=(x[k]+1)%10;  //��ţ�������Ϊgoto�����ת��λ��
if(x[k]==0)
return;
if(G.arc[x[k-1]-1][x[k]-1].adj!=10000)
{
for(j=0;j<k;j++)
if(x[j]==x[k])
goto l;
return;
}
else
goto l;    //ʹ��goto���ı�������� תȥִ�������l����ʶ�����
}
void display()
{
int i=0;
for(i=0;i<26;i++)
printf("%s->",G.vex[x[i]-1].sight);                                                      
}                                             

