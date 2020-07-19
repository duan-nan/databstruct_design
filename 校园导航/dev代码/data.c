#include<stdlib.h>
#include<string.h>
#include<algorithm>

#include"data.h"
#define inf 99999999
//map��ά����洢Ȩֵ��book������������Ƿ񾭹���distance�������洢����֮��ľ��� 
int map[110][110],book[110],distance[110];
//�ṹ�� 
struct data{
	char name[100];
	char information[800];
}d[100];

void initData(){
	//��������Ϣ�洢��d�ṹ���� 
	int i,j;
	strcpy(d[1].name,"�Ϲ�����");strcpy(d[1].information,"���й���վ���������ؽ�ͨ��");
	strcpy(d[2].name,"�йش��촴�ռ�");strcpy(d[2].information,"������չ����ᣬ�������Ժ��");
	strcpy(d[3].name,"��ѧ����ҵ��ҵ����ָ������");strcpy(d[3].information,"�����ң�������ѧ����");
	strcpy(d[4].name,"�³��㳡");strcpy(d[4].information,"���򳡣����򳡡�");
	strcpy(d[5].name,"ѧԷ����");strcpy(d[5].information,"һ��¥�ṩ�Ͳͷ���");
	strcpy(d[6].name,"�Ƚ����켼��ʵ����");strcpy(d[6].information,"ʵ����");
	strcpy(d[7].name,"����ѧ����������");strcpy(d[7].information,"������");
	strcpy(d[8].name,"11�Ž�ѧ¥");strcpy(d[8].information,"���پ���ҽ��ҩѧԺ");
	strcpy(d[9].name,"��������ѧ�Ƽ�԰");strcpy(d[9].information,"��ѧ�����´�ҵ����԰");
	strcpy(d[10].name,"���ڴ�");strcpy(d[10].information,"���ڹ�ϵ���������");
	strcpy(d[11].name,"ͼ���");strcpy(d[11].information,"ͼ��ݣ���������������");
	strcpy(d[12].name,"������");strcpy(d[12].information,"������ѧ��");
	strcpy(d[13].name,"��Է����");strcpy(d[13].information,"һ�����ṩ�Ͳͷ���");
	strcpy(d[14].name,"����ʳ��");strcpy(d[14].information,"�ṩ��������");
	strcpy(d[15].name,"��ζ����");strcpy(d[15].information,"�ṩ��������");
	strcpy(d[16].name,"11�Ź�Ԣ¥");strcpy(d[16].information,"����¥");
	strcpy(d[17].name,"��԰ϴԡ����");strcpy(d[17].information,"ϴԡ��ͷ��ϴ����");
	strcpy(d[18].name,"14�Ž�ѧ¥");strcpy(d[18].information,"��ѧ¥");
	strcpy(d[19].name,"���پ�ҩ��ֲ��԰");strcpy(d[19].information,"ֲ��԰");
	strcpy(d[20].name,"�Ϻ�");strcpy(d[20].information,"С��");
	strcpy(d[21].name,"�̹��Ĵ�");strcpy(d[21].information,"��ְ����Ԣ");
	strcpy(d[22].name,"���͹㳡");strcpy(d[22].information,"�㳡��ͨ�Ϻ�");
	strcpy(d[23].name,"�ٷ�");strcpy(d[23].information,"������");
	strcpy(d[24].name,"��������");strcpy(d[24].information,"�˶�����");
	strcpy(d[25].name,"������վ");strcpy(d[25].information,"������վ");
	//��ֵ���������Ϊͬһ����Ϊ0������Ϊ����� 
	for(i = 1;i <= 27;i++){
		for(j = 1;j <= 27;j++){
			if(i == j){
				map[i][j] = 0;
			}else{
				map[i][j] = inf;
			}
		}
	}
	//����ʵ�����������֮�����Ȩֵ�ĸ�ֵ 
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
	 //����ͼ��֤�������ص�Ȩֵһ�� 
	 for(i=1;i<=26;i++){
	 	for(j=1;j<=26;j++){
	 		map[i][j] = map[j][i];
		 }
	 }
}


void cloList(){
	system("cls");			//���� 
	printf("\n\n\n");
	printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\t\t\t\t * *                     *�����б�*                     * *\n");
	printf("\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <1>ѧУ����               <2>�йش��촴�ռ�       * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <3>��ѧ����ҵ��ҵ����ָ������   <4>�³��㳡       * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <5>ѧԷ����         <6>�Ƚ����켼��ʵ����         * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <7>����ѧ����������      <8>11�Ž�ѧ¥            * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <9>��������ѧ�Ƽ�԰   <10>���ڴ�    <11>ͼ���  * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <12>������     <13>��Է����     <14>����ʳ��      * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <15>��ζ����   <16>11�Ź�Ԣ¥   <17>��԰ϴԡ����  * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <18>14�Ž�ѧ¥    <19>���پ�ҩ��ֲ��԰   <20>�Ϻ� * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <21>�̹��Ĵ�   <22>���͹㳡   <23>��������    * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * *  <24>������վ                                      * *\n");
	printf("\t\t\t\t * *                                                    * *\n");
	printf("\t\t\t\t * ****************************************************** *\n");
	printf("\t\t\t\t * * * * * * * * * * * * * * ** * * * * * * * * * * * * * *\n");
	printf("\n\n\n");
} 

int changeToId(char s[]){
	//�����뾰������ʱ��ѯ�Ƿ���ڣ����ڵĻ����ض�Ӧ�ı�� 
	int f=0,i;
	for(i=1;i<=25;i++){
		if(strcmp(d[i].name,s) == 0){
			return i;
		}
	}
	return -1;
}

void dijkstra(int v0,int v1){//vo����ʼλ�ã�v1����ֹλ�� 
	int min,i,j,u,v; 
	int postion[100],l[100];//postion�ǵ�ǰλ�õı�ǣ� 
	memset(postion,-1,sizeof(postion));//����ĳ�ʼ����ֵ 
	memset(l,0,sizeof(l));//����ĳ�ʼ����ֵ 
	memset(book,0,sizeof(book));//����ĳ�ʼ����ֵ 
	//forѭ������ 
	for(i=1;i<=25;i++){
		distance[i] = map[v0][i];
			if(distance[i]<inf){
				postion[i] = v0; //��ǰλ�ø���Ϊi 
			}
		}
		book[v0] = 1;//voΪ�Ѿ�·�� 
		for(i=1;i<=25;i++){
			min = inf;
			for(j=1;j<=25;j++){
				if(book[j] == 0 && distance[j] < min){//forѭ�������ҳ���Χ·���е����·�� 
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
	printf("·��Ϊ��\n");
	printf("%s--->",d[v0].name);
	for(i=u;i>=1;i--)
		printf("%s--->",d[l[i]].name); 
	printf("%s\n",d[v1].name);
	printf("���·������Ϊ��%d ��\n",distance[v1]*15);

}


void showInformation(int Id){
	printf("\n\n��������:%s\n\n������ϸ��Ϣ:%s\n\n",d[Id].name,d[Id].information);
}
