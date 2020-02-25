#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h> 
/*int c(char c[9],int d[26]){
	int i=0;int n;
	char a[9];char b[26];
	strcpy(a,c);
	strcpy(b,d);
	for(;i<strlen(a);i++)
	{
		n=(int)a[i];
		b[n-97]--;
	}
	for(i=0;i<26;i++)
	{
		if(b[i]<0){
			return 0;
		}
	}
	return 1;
}*/
int main(void)
{
	int jy[26]={0};
	int bak[26]={0};
char yuanyin[44]="aaaaaaaaaeeeeeeeeeeeeeeeiiiiiiiioooooouuuuuu",fuyin[56]="bbccdddffgghhjklllllmmmnnnnnnppqrrrrrrssssssttttttvvwxyz";
 srand((unsigned)time(NULL));//给随机数提供种子 
 int n= rand()%100;//取100余数得一百以内的随机数 
 char spell_string[9];
 int choice=0,randnum;
 int i=0;
 for(;i<4;i++)
 {while(choice!=1&&choice!=2)
  {printf("请玩家1选择元音或辅音。1元音，2辅音\n");
   scanf("%d",&choice);
  }
  if(choice==1)
  {randnum = rand()%44;
   spell_string[2*i]=yuanyin[randnum];
   int sp=(int)yuanyin[randnum]-97;
   jy[sp]++;
   //printf("%d%c",sp,yuanyin[randnum]);
  }
  else if(choice==2)
  {randnum = rand()%56;
   spell_string[2*i]=fuyin[randnum];
   int sp=(int)fuyin[randnum]-97;
   jy[sp]++;
  }
  choice=0;
  while(choice!=1&&choice!=2)
  {printf("请玩家2选择元音或辅音。1元音，2辅音\n");
   scanf("%d",&choice);
  }
  if(choice==1)
  {randnum = rand()%44;
   spell_string[2*i+1]=yuanyin[randnum];
   int sp=(int)yuanyin[randnum]-97;
   jy[sp]++;
  }
  else if(choice==2)
  {randnum = rand()%56;
   spell_string[2*i+1]=fuyin[randnum];
  int sp=(int)fuyin[randnum]-97;
   jy[sp]++;
  }
  choice=0;
 } 
 while(choice!=1&&choice!=2)//玩家1要多进行一轮选择 
  {printf("请玩家1选择元音或辅音。1元音，2辅音\n");
   scanf("%d",&choice);
  }
  if(choice==1)
  {randnum = rand()%44;
   spell_string[2*i]=yuanyin[randnum];
   int sp=(int)yuanyin[randnum]-97;
   jy[sp]++;
  }
  else if(choice==2)
  {randnum = rand()%56;
   spell_string[8]=fuyin[randnum];
   int sp=(int)fuyin[randnum]-97;
   jy[sp]++;
  }
  
  system("cls");
  printf("抽到的字母有:%c%c%c%c%c%c%c%c%c\n",spell_string[0],spell_string[1],spell_string[2],spell_string[3],spell_string[4],spell_string[5],spell_string[6],spell_string[7],spell_string[8]); 
  /*int zz=0;
  for(zz=0;zz<26;zz++){
  	printf("%c:%d\n",zz+97,jy[zz]);
  }*/
  char play_1[9],play_2[9];
  int h=0;
  for(;h<26;h++)
 {
   bak[h]=jy[h];
 }
  
    char check[60000][20];//存储读取的单词 
	int sum=0;          //用于数组计数
	int num;            //用于判断是否查找到结果
	
	FILE *fp;           //定义文件指针
	fp=fopen("1.txt","r"); //打开文件，只读模式
	
	if(fp == NULL)
    {
        printf("Open file failed.Please check and try again.");
        return 0;
    } //检测字典文件是否正常打开 
    
    while(!feof(fp))
	{
		fscanf(fp, "%s", check[sum]);//读取字典 
		sum++;
	}
	
	fclose(fp); 
	
	num=0;
	int ii=0;int nn=0;int result=1;
	/*
	
	for(;ii<strlen(play_1);ii++)
	{
		n=(int)play_1[ii];
		jy[n-97]--;
	}
	for(ii=0;ii<26;ii++)
	{
		if(jy[ii]<0){
			return 0;
		}
	}
	return 1;
	*/
	while(1){
		printf("请玩家1输入单词：");
    	scanf("%s",play_1);
    	//bool result=check(,);
		while(strcmp(check[num],play_1)!=0){
			num++;
			if(num>59877){
				printf("字典校验不通过，玩家1输入无效,请重新输入!\n");
				break;
			}
		}
		if(strcmp(check[num],play_1)==0)
		{
			//while(1){
				result=1;
				for(ii=0;ii<strlen(play_1);ii++)
				{
					nn=(int)play_1[ii]-97;
					jy[nn]--;
				}
			
				for(ii=0;ii<26;ii++)
				{
					if(jy[ii]<0){
						result=0;
						break;
					}
				}
				
				for(h=0;h<26;h++)
 				{
   					jy[h]=bak[h];
 				}
				if(result==0){
					printf("字母超出范围，玩家1输入无效,请重新输入!\n");
					num=0;
					continue;
				}
			//}
			printf("玩家1输入有效!\n");
			break;
		}
		if(num>59877)
		{
			num=0;
		}
	}
	
	num=0; 
	while(1){
		printf("请玩家2输入单词：");
    	scanf("%s",play_2);
		while(strcmp(check[num],play_2)!=0){
			num++;
			if(num>59877){
				printf("字典校验不通过，玩家2输入无效,请重新输入!\n");
				break;
			}
		}
		if(strcmp(check[num],play_2)==0)
		{
			result=1;
				for(ii=0;ii<strlen(play_2);ii++)
				{
					nn=(int)play_2[ii]-97;
					jy[nn]--;
				}
			
				for(ii=0;ii<26;ii++)
				{
					if(jy[ii]<0){
						result=0;
						break;
					}
				}
				for(h=0;h<26;h++)
 				{
   					jy[h]=bak[h];
 				}
				if(result==0){
					printf("字母超出范围，玩家2输入无效,请重新输入!\n");
					num=0;
					continue;
				}
			
			printf("玩家2输入有效!\n");
			break;
		}
		if(num>59877)
		{
			num=0;
		}
	}
	system("cls");
	int win1=strlen(play_1);
	int win2=strlen(play_2);
	if(win1>win2){
		printf("玩家1获胜！\n");
		printf("按任意键退出");
	}
	if(win1<win2){
		printf("玩家2获胜！\n");
		printf("按任意键退出");
	} 
	if(win1==win2){
		printf("二人平局！\n");
		printf("按任意键退出");
	} 
	getchar();
	getchar();
    return 0;
}
