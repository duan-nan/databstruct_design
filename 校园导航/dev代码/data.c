#include<stdlib.h>
#include<string.h>
#include<algorithm>

#include"data.h"
#define inf 99999999
//map二维数组存储权值，book数组用来标记是否经过，distance数组来存储两点之间的距离 
int map[110][110],book[110],distance[110];
//结构体 
struct data{
	char name[100];
	char information[800];
}d[100];

void initData(){
	//将数据信息存储在d结构体内 
	int i,j;
	strcpy(d[1].name,"南工北门");strcpy(d[1].information,"设有公交站，方便来回交通。");
	strcpy(d[2].name,"中关村领创空间");strcpy(d[2].information,"教育发展基金会，建筑设计院。");
	strcpy(d[3].name,"大学生就业创业服务指导中心");strcpy(d[3].information,"会议室，服务于学生。");
	strcpy(d[4].name,"下沉广场");strcpy(d[4].information,"篮球场，网球场。");
	strcpy(d[5].name,"学苑餐厅");strcpy(d[5].information,"一二楼提供就餐服务");
	strcpy(d[6].name,"先进制造技术实验室");strcpy(d[6].information,"实验室");
	strcpy(d[7].name,"国际学术交流中心");strcpy(d[7].information,"会议室");
	strcpy(d[8].name,"11号教学楼");strcpy(d[8].information,"张仲景国医国药学院");
	strcpy(d[9].name,"南阳理工大学科技园");strcpy(d[9].information,"大学生创新创业孵化园");
	strcpy(d[10].name,"后勤处");strcpy(d[10].information,"后勤关系与服务中心");
	strcpy(d[11].name,"图书馆");strcpy(d[11].information,"图书馆，心理健康教育中心");
	strcpy(d[12].name,"体育馆");strcpy(d[12].information,"体育教学部");
	strcpy(d[13].name,"南苑餐厅");strcpy(d[13].information,"一二层提供就餐服务");
	strcpy(d[14].name,"清真食堂");strcpy(d[14].information,"提供餐饮服务");
	strcpy(d[15].name,"风味餐厅");strcpy(d[15].information,"提供餐饮服务");
	strcpy(d[16].name,"11号公寓楼");strcpy(d[16].information,"宿舍楼");
	strcpy(d[17].name,"舒园洗浴中心");strcpy(d[17].information,"洗浴，头发洗剪吹");
	strcpy(d[18].name,"14号教学楼");strcpy(d[18].information,"教学楼");
	strcpy(d[19].name,"张仲景药用植物园");strcpy(d[19].information,"植物园");
	strcpy(d[20].name,"南湖");strcpy(d[20].information,"小湖");
	strcpy(d[21].name,"教工四村");strcpy(d[21].information,"教职工公寓");
	strcpy(d[22].name,"齐贤广场");strcpy(d[22].information,"广场连通南湖");
	strcpy(d[23].name,"琴房");strcpy(d[23].information,"钢琴室");
	strcpy(d[24].name,"网球场篮球场");strcpy(d[24].information,"运动场地");
	strcpy(d[25].name,"菜鸟驿站");strcpy(d[25].information,"菜鸟驿站");
	//赋值，如果两点为同一点则为0，否则为无穷大 
	for(i = 1;i <= 27;i++){
		for(j = 1;j <= 27;j++){
			if(i == j){
				map[i][j] = 0;
			}else{
				map[i][j] = inf;
			}
		}
	}
	//根据实际情况对两点之间进行权值的赋值 
	 map[1][2] = 50;
	 map[2][1] = 50;map[2][3] = 20;map[2][4] = 40;
	 map[3][2] = 20;map[3][4] = 30;
	 map[4][3] = 30;map[4][5] = 20;map[4][7] = 40;
	 map[5][4] = 20;map[5][6] = 50;
	 map[6][5] = 50;map[6][23] = 600;
	 map[7][4] = 40;map[7][8] = 200;
	 map[8][7] = 200;map[8][9] = 200;map[8][22]=100;map[8][11] = 300;map[8][18] = 300;map[8][19] = 50;
	 map[9][8] = 200;map[9][11] = 100;map[9][12] = 200;map[9][10] = 100;map[9][19] = 50;
	 map[10][9] = 100;map[10][11] = 100;
	 map[11][9] = 100;map[11][10] = 100;map[11][12] = 100;map[11][8] = 300;map[11][20] = 50;
	 map[12][11] = 100;map[12][9] = 200;map[12][13] = 150;map[12][14] = 250;map[12][15] = 300;
	 map[13][12] = 150;map[13][14] = 50;map[13][15] = 150;map[13][12] = 150;
	 map[14][13] = 50;map[14][15] = 100;map[14][12] = 250;
	 map[15][14] = 100;map[15][13] = 150;map[15][12] = 300;
	 map[16][13] = 50;map[16][21] = 300;map[16][17] = 250;map[16][24] = 100;
	 map[17][16] = 250;map[17][21] = 50;map[17][18] = 400;
	 map[18][17] = 400;map[18][8] = 300;map[18][20] = 200;
	 map[19][9] = 50;map[19][8] = 50;
	 map[20][11] = 50;map[20][22] = 150;
	 map[21][17] = 50;map[21][16] = 300;
	 map[22][20] = 150;map[22][18] = 200;
	 map[23][6] = 600;
	 map[24][16] = 100;
	 map[25][18] = 50;map[25][23] = 600;
	 //无向图保证两点来回的权值一样 
	 for(i=1;i<=26;i++){
	 	for(j=1;j<=26;j++){
	 		map[i][j] = map[j][i];
		 }
	 }
}


void cloList(){
	system("cls");			//清屏 
	printf("\n\n\n");
	printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t * *                     *景点列表*                     * *\n");
	printf("\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <1>学校大门               <2>中关村领创空间       * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <3>大学生就业创业服务指导中心   <4>下沉广场       * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <5>学苑餐厅         <6>先进制造技术实验室         * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <7>国际学术交流中心      <8>11号教学楼            * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <9>南阳理工大学科技园   <10>后勤处    <11>图书馆  * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <12>体育馆     <13>南苑餐厅     <14>清真食堂      * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <15>风味餐厅   <16>11号公寓楼   <17>舒园洗浴中心  * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <18>14号教学楼    <19>张仲景药用植物园   <20>南湖 * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <21>教工四村   <22>齐贤广场   <23>网球场篮球场    * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <24>菜鸟驿站                                      * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
} 

int changeToId(char s[]){
	//当输入景点名称时查询是否存在，存在的话返回对应的编号 
	int f=0,i;
	for(i=1;i<=25;i++){
		if(strcmp(d[i].name,s) == 0){
			return i;
		}
	}
	return -1;
}

void dijkstra(int v0,int v1){//vo是起始位置，v1是终止位置 
	int min,i,j,u,v; 
	int postion[100],l[100];//postion是当前位置的标记， 
	memset(postion,-1,sizeof(postion));//数组的初始化赋值 
	memset(l,0,sizeof(l));//数组的初始化赋值 
	memset(book,0,sizeof(book));//数组的初始化赋值 
	//for循环遍历 
	for(i=1;i<=25;i++){
		distance[i] = map[v0][i];
			if(distance[i]<inf){
				postion[i] = v0; //当前位置更新为i 
			}
		}
		book[v0] = 1;//vo为已经路过 
		for(i=1;i<=25;i++){
			min = inf;
			for(j=1;j<=25;j++){
				if(book[j] == 0 && distance[j] < min){//for循环遍历找出周围路径中的最短路径 
						min = distance[j];
						u = j;
					}
				}
		
			book[u] = 1;
			for(v=1;v<=25;v++){
				if(book[v] == 0 && distance[v] > distance[u] + map[u][v]){
					postion[v] = u;
					distance[v] = distance[u] + map[u][v];
				}
			}
		}	
		v = v1;
		i = 1;
		while(postion[v] != v0){
			l[i++] = postion[v];
			v = postion[v];
		}
	printf("\n");
	u=i-1;
	printf("路线为：\n");
	printf("%s--->",d[v0].name);
	for(i=u;i>=1;i--)
		printf("%s--->",d[l[i]].name); 
	printf("%s\n",d[v1].name);
	printf("最短路径长度为：%d 米\n",distance[v1]*15);

}


void showInformation(int Id){
	printf("\n\n景点名称:%s\n\n景点详细信息:%s\n\n",d[Id].name,d[Id].information);
}
