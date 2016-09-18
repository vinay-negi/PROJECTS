#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
void print();
struct course
	{
		char name[20];
		char subject[20][15];
		int creadit[20];
		int room;
		int totsub;
		int ctchr[20];
		int allsub;
		int breaks;
		
		int lbreak;
		
		char labname[10][15];
		int labhr[10];
		int labroom[10];
		int labtchr[10];
		int totlab;
		struct
		{
			struct
			{
				bool busy;
			}
			busy[10];
		}
		busy[10]; 
		
		struct
		{
		struct
		{
			bool lunch;
		}
		lunch[10];
		}
		lunch[2]; 	
		
	};
	struct course co[20];

/***********************************************/
struct teach
	{
		char name[20];
		int sub[11];
		int cors[11];
		int totsub;
		int allsub;
		struct
		{
		struct
		{
			bool busy;
		}
			busy[10];
		}
		busy[10]; 
		
	};
	struct teach th[20];
/***********************************************/	
struct room
	{
		char room[10];
		int allsub;
	struct
	{
		struct
		{
			bool busy;
		}
		busy[10];
	}
	busy[10]; 
 
		
	};struct room ro[20];
/***********************************************/

struct tmpsub
	{
	struct
	{
		struct
		{
			char tmpsub[20];
		}
		tmpsub[20];
	}
	tmpsub[20];
	}
	tmpsub[20];
/***********************************************/
struct tmptchr
	{
	struct
	{
		struct
		{
			char tmptchr[20];
		}
		tmptchr[20];
	}
	tmptchr[20];
	}
	tmptchr[20];
/***********************************************/
struct fisub
	{
	struct
	{
		struct
		{
			char fisub[20];
		}
		fisub[20];
	}
	fisub[20];
	}
	fisub[20];
/***********************************************/
struct fitch
	{
	struct
	{
		struct
		{
			char fitch[20];
		}
		fitch[10];
	}
	fitch[20];
	}
	fitch[20];

/***********************************************/	
long int crs,tch,room,dys,lects,tmptch,tmproom,set,settmp,done,lxx;
/***********************************************/	
void input()
{	
	int i,j,k;
	FILE *f1;
	printf("enter total days, \nlectures,\ncources,\nteachers,\nrooms");

 	f1 = fopen("e:\\input.txt","r");
	if(f1==NULL)
	{
		printf("file not found");
	 	exit(0);
	}
	fscanf(f1,"%d %d %d %d %d",&dys,&lects,&crs,&tch,&room);
 	printf("\n%d %d %d %d %d\n",dys,lects,crs,tch,room);
  	//scanf(" %d %d %d %d",&lects,&crs,&tch,&room);
	//rooms...
	for(i=0;i<room;i++)
	{
		printf("enter room name %d ",i+1);
		//fgets(ro[i].room,10,f1);
		fscanf(f1,"%s",ro[i].room);
		printf("%s\n",ro[i].room);
	}
	//teachers
	for(i=0;i<tch;i++)
	{
			printf("\nenter teachr name %d ",i+1);
	
			fscanf(f1,"%s",th[i].name);
			printf("%s ",th[i].name);
	
	//	scanf("%s",th[i].name);
	}
	//courses
	for(i=0;i<crs;i++)
	{
		printf("\nenter course name %d",i+1);
		//scanf("%s",co[i].name);
		fscanf(f1,"%s",co[i].name);
		printf(" %s \n",co[i].name);
	
		printf("enter total subjects ");//less than m x n
		//scanf("%d",&co[i].totsub);
		fscanf(f1,"%d",&co[i].totsub);
		printf(" %d \n",co[i].totsub);
		
		printf("enter total labs ");//less than m x n
		//scanf("%d",&co[i].totlab);
		fscanf(f1,"%d",&co[i].totlab);
		printf(" %d \n",co[i].totlab);
		
		for(j=0;j<co[i].totsub;j++)
		{
			printf("enter subject name ");
			//scanf("%s",co[i].subject[j]);
			fscanf(f1,"%s",co[i].subject[j]);
			printf(" %s \n",co[i].subject[j]);
		
			
			printf("enter subject creadit ");
		//	scanf("%d",&co[i].creadit[j]);
			fscanf(f1,"%d",&co[i].creadit[j]);
			printf(" %d \n",co[i].creadit[j]);
		
			co[i].allsub+=co[i].creadit[j];//less than m x m
			if(co[i].allsub>lects*dys-dys)//check total sub limit for a course
			{
				printf("more than limited sub to a course");
				getch();
				 exit(0);
			}
			
			printf("select a teacher for subject %d",j+1);
			for(k=0;k<tch;k++)
			printf(" %d.%s\t",k,th[k].name);
		//	scanf("%d",&tmptch);
			fscanf(f1,"%d",&tmptch);
			printf(" %d \n",tmptch);
		
			co[i].ctchr[j]=tmptch;
			th[tmptch].sub[th[tmptch].totsub]=j; //not used yet
			th[tmptch].cors[th[tmptch].totsub]=i;//not used yet
			th[tmptch].totsub++;	//	less than m x n
		
			th[tmptch].allsub+=co[i].creadit[j];
			if(th[tmptch].allsub>lects*dys-dys)//check total sub limit for a teacher
			{
				printf("more than limited sub to a teacher");
				getch();
				exit(0);
			}
			
		}
		
		printf("enter a room for this course\n");//			room for course
		for(j=0;j<room;j++)
		{
			printf(" room %d %s",j,ro[j].room);
		}
		//scanf("%d",&tmproom);	
		fscanf(f1,"%d",&tmproom);
		printf(" %d \n",tmproom);
		
		co[i].room=tmproom;
		ro[tmproom].allsub+=co[i].allsub;
		if(ro[tmproom].allsub>lects*dys)//check total room sub limit
		{
			printf("more than limited sub in a room");
			getch();
			exit(0);
		}
		
		
		for(j=0;j<co[i].totlab;j++)	//				feeding lab details
		{
			printf("enter lab name  ");
			fscanf(f1,"%s",co[i].labname[j]);
			printf("%s\n",co[i].labname[j]);
			printf("enter lab hrs ");
			fscanf(f1,"%d",&co[i].labhr[j]);
			printf("%d\n",co[i].labhr[j]);
			
			co[i].allsub+=co[i].labhr[j];
			if(co[i].allsub>lects*dys-dys)//check total sub limit for a course
			{
				printf("more than limited sub in a course");
				getch();
				 exit(0);
			}
			
			printf("select a teacher for lab %d",j+1);
			for(k=0;k<tch;k++)
			printf(" %d.%s\t",k,th[k].name);
			fscanf(f1,"%d",&tmptch);
			printf("%d\n",tmptch);
			
			co[i].labtchr[j]=tmptch;
			 
		
			th[tmptch].allsub+=co[i].labhr[j];
			if(th[tmptch].allsub>lects*dys-dys)//check total sub limit for a teacher
			{
				printf("more than limited sub to a teacher");
				getch();
				exit(0);
			}
			 
			printf("enter a room for this lab\n");
			for(k=0;k<room;k++)
			{
				printf(" room %d %s",k,ro[k].room);
			}
			fscanf(f1,"%d",&tmproom);
			printf("%d\n",tmproom);
			
			ro[tmproom].allsub+=co[i].labhr[j];
			if(ro[tmproom].allsub>lects*dys)//check total room sub limit
			{
				printf("more than limited sub in a room");
				getch();
				exit(0);
			}
			co[i].labroom[j]=tmproom;
			 
		}
		
	}
	
}
/************************/
void save(int x)
{
	int i,j,k;
	for(i=0;i<=x;i++)
	for(j=0;j<lects;j++)
	for(k=0;k<dys;k++)
	{
		strcpy(fitch[i].fitch[j].fitch[k].fitch,tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
		strcpy(fisub[i].fisub[j].fisub[k].fisub,tmpsub[i].tmpsub[j].tmpsub[k].tmpsub);
	}
}
int freelab(int x,int i,int j,int k)
{
	int c=1;int z;
	for(z=0;z<co[i].labhr[x];z++)
	if( (th[co[i].labtchr[x]].busy[j+z].busy[k].busy!=false) || (ro[co[i].labroom[x]].busy[j+z].busy[k].busy!=false) ||  
			   co[i].busy[j+z].busy[k].busy!=false)
	c=0;
	
	if(lects/2<j+co[i].labhr[x] && (lects/2)-1>=j)
	c=0;
	
	return c;
			  
}

void generate(int i,int j,int k)
{
  	int x;
	if((i<crs)&&(set<crs))
	{ 
													//feeding lunch
		 				 
		if( ( (j==(lects/2)-1 &&  (ro[co[i].room].busy[j+1].busy[k].busy==false) ) || 		(j==(lects/2) && co[i].lunch[0].lunch[k].lunch==false ) )	&& (co[i].allsub<((dys*lects)-co[i].breaks)))
		{
			strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,"     ");
			strcpy(tmpsub[i].tmpsub[j].tmpsub[k].tmpsub,"lunch");
			if(j==(lects/2)-1)
			{
				co[i].lunch[0].lunch[k].lunch=true;
			}
			else
			{
				co[i].lunch[1].lunch[k].lunch=true;
			}
			co[i].breaks++;
			co[i].lbreak++;
			
			co[i].busy[j].busy[k].busy=true;//for busy of course
			//   	save(i);print();//getch();
		
			for(lxx=1; ((i+(j+(k+1)/dys)/lects)<crs&&((j+(k+1)/dys)%lects)<lects&&((k+1)%dys)<dys) 
			&& co [ i+(j+(k+lxx)/dys)/lects].busy[ (j+(k+lxx)/dys)%lects].busy[(k+lxx)%dys].busy!=false; lxx++);
			 
			// printf("lunch");
			
			generate(i+(j+(k+lxx)/dys)/lects,(j+(k+lxx)/dys)%lects,(k+lxx)%dys);
			
			if(!done)
			{
				co[i].busy[j].busy[k].busy=false;//for busy of course
				tmptchr[i].tmptchr[j].tmptchr[k].tmptchr[0]='\0';
				tmpsub[i].tmpsub[j].tmpsub[k].tmpsub[0]='\0';
			
			if(j==(lects/2)-1)
			{
				co[i].lunch[0].lunch[k].lunch=false;
			}
			else
			{
				co[i].lunch[1].lunch[k].lunch=false;
			}
			co[i].breaks--;
			co[i].lbreak--;
			}
			
			
		}
													//feeding subjects
		for(x=0;x<co[i].totsub;x++)
		{
			 
			if(j!=(lects/2) || co[i].lunch[0].lunch[k].lunch!=false)
			if((th[co[i].ctchr[x]].busy[j].busy[k].busy==false) && 
			(ro[co[i].room].busy[j].busy[k].busy==false) && (co[i].creadit[x]>0) 
				&& (co[i].allsub<=((dys*lects)-co[i].breaks)) && 
				co[i].busy[j].busy[k].busy==false)
			{
			 // printf("subject  ");
				co[i].busy[j].busy[k].busy=true;	//  for busy of course
				
				strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,th[co[i].ctchr[x]].name);
				strcpy(tmpsub[i].tmpsub[j].tmpsub[k].tmpsub,co[i].subject[x]);
			 
				co[i].creadit[x]--;
				
				th[co[i].ctchr[x]].busy[j].busy[k].busy=true;
				ro[co[i].room].busy[j].busy[k].busy=true;
				
				if(j==(lects-1) && k==(dys-1))
					set++;
				
				if(settmp<set)
				{
					settmp=set;
					save(i); 
				}
				//   save(i);print();//getch();
				 
				for(lxx=1; ((i+(j+(k+1)/dys)/lects)<crs&&((j+(k+1)/dys)%lects)<lects&&((k+1)%dys)<dys) 
			&& co [ i+(j+(k+lxx)/dys)/lects].busy[ (j+(k+lxx)/dys)%lects].busy[(k+lxx)%dys].busy!=false; lxx++);
				
			generate(i+(j+(k+lxx)/dys)/lects,(j+(k+lxx)/dys)%lects,(k+lxx)%dys);
			   
			if(!done)
			{
					co[i].busy[j].busy[k].busy=false;	//  for busy of course
				
				if(j==(lects-1) && k==(dys-1))				//backtrack start
					set--;	
				
				co[i].creadit[x]++;
				
				th[co[i].ctchr[x]].busy[j].busy[k].busy=false;
				ro[co[i].room].busy[j].busy[k].busy=false;
				
				tmptchr[i].tmptchr[j].tmptchr[k].tmptchr[0]='\0';
				tmpsub[i].tmpsub[j].tmpsub[k].tmpsub[0]='\0';
			}
				
			}
		}
															//feeding labs
		
	 
		for(x=0;x<co[i].totlab;x++)
		 {
		 	if(j!=(lects/2) || co[i].lunch[0].lunch[k].lunch!=false)
		 
			if( (j+co[i].labhr[x]<=lects) && co[i].labhr[x]>0 &&freelab(x,i,j,k)  )
			  { 
				int z,lh=co[i].labhr[x];
				for(z=0;z<lh;z++)
				{
					co[i].busy[j+z].busy[k].busy=true;	//  for busy of course
					strcpy(tmptchr[i].tmptchr[j+z].tmptchr[k].tmptchr,th[co[i].labtchr[x]].name);
					strcpy(tmpsub[i].tmpsub[j+z].tmpsub[k].tmpsub,co[i].labname[x]);
					
					th[co[i].labtchr[x]].busy[j+z].busy[k].busy=true;
					ro[co[i].labroom[x]].busy[j+z].busy[k].busy=true;	
					co[i].labhr[x]--;	
				}
	
				if(j==(lects-1) && k==(dys-1))
					set++;
				
				if(settmp<set)
				{
					settmp=set;
					save(i); 
				}
				 //  save(i);print();//getch();
				for(lxx=1; ((i+(j+(k+1)/dys)/lects)<crs&&((j+(k+1)/dys)%lects)<lects&&((k+1)%dys)<dys) 
			&& co [ i+(j+(k+lxx)/dys)/lects].busy[ (j+(k+lxx)/dys)%lects].busy[(k+lxx)%dys].busy!=false; lxx++);
				 
			//printf("lab  ");
			  	
				generate(i+(j+(k+lxx)/dys)/lects,(j+(k+lxx)/dys)%lects,(k+lxx)%dys);
			//    printf("blab  ");
			  	
				if(!done)
				{
				 
				for(z=0;z<lh;z++)
				{
					co[i].busy[j+z].busy[k].busy=false;	//  for busy of course
					
					tmptchr[i].tmptchr[j+z].tmptchr[k].tmptchr[0]='\0';
					tmpsub[i].tmpsub[j+z].tmpsub[k].tmpsub[0]='\0';
					
					th[co[i].labtchr[x]].busy[j+z].busy[k].busy=false;
					ro[co[i].labroom[x]].busy[j+z].busy[k].busy=false;	
					co[i].labhr[x]++;	
				}
	
				if(j==(lects-1) && k==(dys-1))				//backtrack start
					set--;	
				
				  
				}
				
			  	//getch();
			  	//printf("0000000000000000000000000000000000000000");
			  }
		 }
		
			//	*******************************	//*******breaks************
		if(j==(lects/2) && co[i].lunch[0].lunch[k].lunch==false)
			{}
			else																
		if(co[i].allsub<((lects*dys)-(dys-co[i].lbreak)-(co[i].breaks))&& co[i].busy[j].busy[k].busy==false)
		{// printf("break ");
		 	co[i].breaks++;
				strcpy(tmptchr[i].tmptchr[j].tmptchr[k].tmptchr,"Nill");
				strcpy(tmpsub[i].tmpsub[j].tmpsub[k].tmpsub,"brk");
			 
			 
			if(j==(lects-1) && k==(dys-1))
				set++;
				
			if(settmp<set)
			{
				settmp=set;
				save(i);
				//print();
			}
			//  	save(i);print();//getch();
			for(lxx=1; ((i+(j+(k+1)/dys)/lects)<crs&&((j+(k+1)/dys)%lects)<lects&&((k+1)%dys)<dys) 
			&& co [ i+(j+(k+lxx)/dys)/lects].busy[ (j+(k+lxx)/dys)%lects].busy[(k+lxx)%dys].busy!=false; lxx++);
			 
		//	printf("got break  ");
			generate(i+(j+(k+lxx)/dys)/lects,(j+(k+lxx)/dys)%lects,(k+lxx)%dys);
		//	printf(" bkbreak  ");
			 	
			if(!done)
			{	
				tmptchr[i].tmptchr[j].tmptchr[k].tmptchr[0]='\0';
				tmpsub[i].tmpsub[j].tmpsub[k].tmpsub[0]='\0';
			
				if(j==(lects-1) && k==(dys-1))				//backtrack start
				set--;
				co[i].breaks--;	
			
			}
		}
		
	}
	
	else
	{
		done=1;  
	}	
} 
/***************************************/
void print()
{
	int i,j,k;
	for(i=0;i<crs;i++)
	{
		printf("\t");
		for(j=0;j<dys;j++)
		printf("\t  day %d\t",j+1);
		printf("\n.......................................................................................................\n");
		for(j=0;j<lects;j++)
		{
			printf("  lecture %d   ",j+1);
			for(k=0;k<dys;k++)
			{
				//printf("%s \t",fitch[i].fitch[j].fitch[k].fitch);//tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
				printf(" %9s\t",fisub[i].fisub[j].fisub[k].fisub);//
			//	printf(" %9d\t",co[i].busy[j].busy[k].busy);
			}
			printf("\n              ");
			for(k=0;k<dys;k++)
			{
				printf(" %9s\t",fitch[i].fitch[j].fitch[k].fitch);//tmptchr[i].tmptchr[j].tmptchr[k].tmptchr);
				//printf("\t %9s ",fisub[i].fisub[j].fisub[k].fisub);//
				//printf("%s ",tmpsub[i].tmpsub[j].tmpsub[k].tmpsub);
			}
			printf("\n\n");
		}printf("\n\n");
	}
}
int main()
{  
	input();
	generate(0,0,0);
	print();
	getch();
	return 0;
	
}
