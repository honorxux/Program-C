#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#define Max 10000
#define NUM 27
typedef struct ArcCell{
int adj;          //相邻接的景点之间的距离
}ArcCell;         //定义边的类型
typedef struct VertexType{
int number;      //景点编号
char* sight;    //景点名称
char* info;    //景点描述
}VertexType;  //定义顶点的类型
typedef struct{
VertexType vex[NUM];    //图中的顶点，即为景点
ArcCell arc[NUM][NUM]; //图中的边，即为景点间的距离
int vexnum,arcnum;    //顶点数，边数
}MGraph;              //定义图的类型
MGraph G;          //把图定义为全局变量
int P[NUM][NUM];
long int D[NUM];  //辅助变量存储最短路径长度
int  x[26]={0};
void Create(int v,int a); //造图函数
void List();    //列表函数
void Path(int num); //最短路径函数
void Output(int sight1,int sight2); //输出函数
char Menu();  //主菜单
void HaMiTonian(int);  //哈密尔顿图的遍历
void NextValue(int);
void display(); //显示遍历结果
void main() //主函数                                                                      （1）
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
system("cls");  //执行系统命令，清楚先前屏幕显示的内容
List();      //输出景点列表
printf("\n\n\t请选择起点景点（0～26）：");
scanf("%d",&v0);
printf("\t请选择终点景点（0～26）：");
scanf("%d",&v1);
Path(v0);  //计算两个景点之间的最短路径
Output(v0,v1);    //输出结果
printf("\n\n\t请按任意键继续...\n");
getchar();  //利用getchar()函数让程序运行到上一行时，等待按下下一个键才返回
getchar();
break;
case '2':
system("cls");
List();      //输出景点列表
printf("\n\n\t请输入您要查找的景点编号：");
scanf("%d",&num);
for(i=0;i<NUM;i++)
{
if(num==G.vex[i].number)
{
printf("\n\n\t您要查找景点信息如下:");
printf("\n\n\t%s:",G.vex[i].sight);
printf("\t%s\n\n",G.vex[i].info);
printf("\n\t按任意键返回...");
getchar();
getchar();
break;
}
}
if(i==NUM)
{
printf("\n\n\t没有找到！");
printf("\n\n\t按任意键返回...");
getchar();
getchar();
}
break;
}
}while(flag!='0');
}
char Menu()  // 主菜单
{
char c;
int flag;
do{
flag=1;
system("cls");
List();                // 输出景点列表
printf("\n\t\t\t\t┏━━━━━━━━━━━━━━━┑\n");
printf("\t\t\t                                  \n");
printf("\t\t\t          1、查询景点路径            \n");
printf("\t\t\t          2、查询景点信息            \n");
printf("\t\t\t          0、退出                    \n");
printf("\t\t\t                                  \n");
printf("\t\t\t\t┗━━━━━━━━━━━━━━━┛\n");
printf("\t请输入您的选择：");
scanf("%c",&c);
if(c=='1'||c=='2'||c=='0')
flag=0;
}while(flag);
return c;
}                                                                                      
void Create(int v,int a) //创建图函数                                                   
{
int i,j;
G.vexnum=v;  //初始化结构中的景点数和边数
G.arcnum=a;
for(i=0;i<G.vexnum;++i)
G.vex[i].number=i; //初始化每一个景点的编号
//初始化没一个景点名及其景点描述
G.vex[0].sight="云大西二门";
G.vex[0].info="云南大学西二门是目前云南大学主要的进出口";
G.vex[1].sight="百家道";
G.vex[1].info="正对西二门的一条大道，直接通向校园各个地方";
G.vex[2].sight="文典广场";
G.vex[2].info="学校举行重大活动的广场，另外还在这里举行升国旗仪式";
G.vex[3].sight="云大会堂";
G.vex[3].info="这里是学校举行重要典礼和仪式的室内场所以及学生活动中心";
G.vex[4].sight="中山邦翰楼";
G.vex[4].info="教学楼，一楼设有学生事务中心，是学生处和教务处的办公所在地";
G.vex[5].sight="仰止楼";
G.vex[5].info="云南大学图书馆";
G.vex[6].sight="桦苑";
G.vex[6].info="研究生宿舍生活区";
G.vex[7].sight="楠苑";
G.vex[7].info="经济学院、信息学院、体育学院、商旅学院、城建学院、数统学院和中加合作项目等学院的学生宿舍生活区";
G.vex[8].sight="格物楼";
G.vex[8].info="综合教学楼和自习室，一般是理工科学院的学生上公共课和自习";
G.vex[9].sight="楠苑体育场";
G.vex[9].info="学生上体育课和进行体育锻炼的地方，目前设有篮球场、网球场、排球场和田径场";
G.vex[10].sight="知味堂";
G.vex[10].info="学生餐厅，设有二个一般食堂、一个风味食堂和一个清真食堂";
G.vex[11].sight="楠苑超市";
G.vex[11].info="云南大学后勤教育超市之一，为学生提供各种生活学习用品";
G.vex[12].sight="综合服务楼";
G.vex[12].info="综合服务中心，一楼设有超市、药店、眼镜店、饰品店、农行ATM机和茶室，三楼是学校学生会、自律委、社联等各校级的办公室";
G.vex[13].sight="楸苑";
G.vex[13].info="软件学院、物科学院、化工学院、生科学院和资环学院等学院的学生宿舍生活区";
G.vex[14].sight="力行楼";
G.vex[14].info="公共教学楼，一楼设有公共机房";
G.vex[15].sight="软件楼";
G.vex[15].info="软件学院行政办公楼和实验楼";
G.vex[16].sight="校医院";
G.vex[16].info="学生医疗场所";
G.vex[17].sight="明远楼";
G.vex[17].info="教学楼，尚在建设当中";
G.vex[18].sight="至公大道";
G.vex[18].info="正对学校正大门的道路";
G.vex[19].sight="行政办公楼";
G.vex[19].info="学校行政办公部门所在地";
G.vex[20].sight="云大北门";
G.vex[20].info="学校正大门";
G.vex[21].sight="文汇楼";
G.vex[21].info="文科学院教学楼";
G.vex[22].sight="余味堂";
G.vex[22].info="学生吃饭的地方，设有二个一般食堂和一个清真食堂";
G.vex[23].sight="梓苑超市";
G.vex[23].info="超市，为学生提供各种生活学习用品";
G.vex[24].sight="梓苑";
G.vex[24].info="公管学院、人文学院、艺术学院、外国语学院和法学院的学生生活区";
G.vex[25].sight="钟楼";
G.vex[25].info="云大标志性建筑之一，每天上课的钟声从这里响起";
G.vex[26].sight="校车乘车点";
G.vex[26].info="可以在此乘坐校车至校本部";
//这里把所有的边假定为10000，含义是这两个景点之间是不可到达
for(i=0;i<G.vexnum;++i)
for(j=0;j<G.vexnum;++j)
G.arc[i][j].adj=Max;
//下边是可直接到达的景点间的距离，由于两个景点间距离是互相的，所以要对图中对称的边同时赋值
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
void List() //景点列表函数
{
int i,k=0;
printf("\n\t\t********************欢迎使用校园导游程序******************\n");
printf("\n\t\t**********************************************************\n");
printf("\t\t\t\t        景点名称  \t\t\t");
printf("\n\t\t__________________________________________________________\n");
for(i=0;i<NUM;i++)
{
printf("\t\t┃  \t\t(%2d)%-10s\t\t\t\t┃\n",i,G.vex[i].sight); //输出景点列表
k=k+1;
}
printf("\t\t__________________________________________________________\n");
}
void Path(int num) //迪杰斯特拉算法最短路径函数 num为入口点的编号                     （2）
{
int v,w,i,t;  //i、w和v为计数变量
int final[NUM];
int min;
for(v=0;v<NUM;v++)
{
final[v]=0;  //假设从顶点num到顶点v没有最短路径
D[v]=G.arc[num][v].adj;//将与之相关的权值放入D中存放
for(w=0;w<NUM;w++) //设置为空路径
P[v][w]=0;
if(D[v]<20000)  //存在路径
{
P[v][num]=1; // 存在标志置为一
P[v][v]=1; // 自身到自身
}
}
D[num]=0;
final[num]=1;      //初始化num顶点属于S集合
//开始主循环，每一次求得num到某个顶点的最短路径，并将其加入到S集合
for(i=0;i<NUM;++i)    //其余G.vexnum-1个顶点
{
min=Max;    //当前所知离顶点num的最近距离
for(w=0;w<NUM;++w)
if(!final[w])    //w顶点在v-s中
if(D[w]<min)  //w顶点离num顶点更近
{
v=w;
min=D[w];
}
final[v]=1;  //离num顶点更近的v加入到s集合
for(w=0;w<NUM;++w)  //更新当前最短路径极其距离
if(!final[w]&&((min+G.arc[v][w].adj)<D[w]))//不在s集合，并且比以前所找到的路径都短就更新当前路径
{
D[w]=min+G.arc[v][w].adj;
for(t=0;t<NUM;t++)
P[w][t]=P[v][t];
P[w][w]=1;
}
}
}                                                                                      
void Output(int sight1,int sight2)    // 输出函数
{
int a,b,c,d,q=0;
a=sight2;    //将景点二赋值给a
if(a!=sight1)    //如果景点二不和景点一输入重合，则进行...
{
printf("\n\t从*%s*到*%s*的最短路径是",G.vex[sight1].sight,G.vex[sight2].sight);//输出提示信息
printf("\t(最短距离为:%dm.)\n\n\t",D[a]);  // 输出sight1到sight2的最短路径长度，存放在D[]数组中
printf("\t%s",G.vex[sight1].sight);  //输出景点一的名称
d=sight1;      //将景点一的编号赋值给d
for(c=0;c<NUM;++c)
{
gate:;        //标号，可以作为goto语句跳转的位置
P[a][sight1]=0;
for(b=0;b<NUM;b++)
{
if(G.arc[d][b].adj<20000&&P[a][b])  //如果景点一和它的一个临界点之间存在路径且最短路径
{
printf("-->%s",G.vex[b].sight);  //输出此节点的名称
q=q+1;    //计数变量加一，满8控制输出时的换行
P[a][b]=0;
d=b;    // 将b作为出发点进行下一次循环输出，如此反复
if(q%9==0) printf("\n");
goto gate;  //使用goto语句改变程序流向， 转去执行语句标号gate所标识的语句
}//if(G.arcs[d][b].adj<20000&&P[a][b])
}//for(b=0;b<NUM;b++)
} //for(c=0;c<NUM;++c)
}//if(a!=sight1)
}
void HaMiTonian(int m)  // 哈密尔顿图的遍历                                              
{
if(m>26)
return;
L: NextValue(m);  //标号，可以作为goto语句跳转的位置
if(x[m]==0)
return;
if(m==26&&G.arc[0][x[26]-1].adj!=0000)
display();
else
HaMiTonian(m+1);
goto  L;    //使用goto语句改变程序流向， 转去执行语句标号L所标识的语句
}
void NextValue(int k)
{
int j;
l:x[k]=(x[k]+1)%10;  //标号，可以作为goto语句跳转的位置
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
goto l;    //使用goto语句改变程序流向， 转去执行语句标号l所标识的语句
}
void display()
{
int i=0;
for(i=0;i<26;i++)
printf("%s->",G.vex[x[i]-1].sight);                                                      
}                                             

