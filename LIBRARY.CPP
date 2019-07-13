/* books.png , std_acc.txt , lib_acc.txt , borrow.txt */
/* std_acc_selector size is 3 and main library selector size is 5 and after login selector size id 6  */
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>

typedef struct
{
   char bname[20];
   char aname[20];
   int qty;
   char ch;
}book;

int l_count;                                //this veriable shows current position

int lib_index[7]={125,175,225,275,325,375,425}; //index is used to fill color in choices for library
int gd=0,gm;

void login_screen(void)                     //this will create whole login screen
{
     settextstyle(0,0,2);
     outtextxy(225,50," LOGIN ");
     rectangle(200,100,450,150);
     rectangle(200,150,450,200);
     rectangle(200,200,450,250);
     rectangle(200,250,450,300);
     rectangle(200,300,450,350);
     setfillstyle(1,GREEN);
     floodfill(250,125,WHITE);
     setfillstyle(1,RED);
     floodfill(250,175,WHITE);
     floodfill(250,225,WHITE);
     floodfill(250,275,WHITE);
     floodfill(250,325,WHITE);
     settextstyle(0,0,2);
     outtextxy(210,110,"STUDENT");
     outtextxy(210,160,"LIBRARIAN");
     outtextxy(210,210,"NEW STUDENT");
     outtextxy(210,260,"NEW LIBRARIAN");
     outtextxy(210,310,"EXIT");
}


void selector(int f,int size)       			//size = 3 std_acc selector
{                                                       //size = 5 lib selector
	if(f==1)                                        //size = 6 lib login selector
	{
	  if(l_count==0)
	  return;
	  setfillstyle(1,RED);
	  floodfill(250,lib_index[l_count],WHITE);
	  l_count--;
	  setfillstyle(1,GREEN);
	  floodfill(250,lib_index[l_count],WHITE);
	}
	else
	{
	 if(l_count==size)
	 return;
	 setfillstyle(1,RED);
	 floodfill(250,lib_index[l_count],WHITE);
	 l_count++;
	 setfillstyle(1,GREEN);
	 floodfill(250,lib_index[l_count],WHITE);
	}
}

void get_s_password(char d_id[],char fpassword[])
{
	int f=0;
	char fid[20],temp[20];
	FILE* fp=fopen("C:\\TC\\stdacc.txt","r");
	while(!feof(fp))
	{
	   fscanf(fp,"%s	%s",fid,temp);
	   if(!strcmp(d_id,fid))
	   {
	     f=1;
	     break;
	   }

	}
	if(f==1)
	{
	  strcpy(fpassword,temp);
	}
	else
	{
	 fpassword[0]='\0';
	}

}

void lib_screen(void)
{
     settextstyle(0,0,2);
     outtextxy(225,50," LIBRARIAN ");
     rectangle(200,100,450,150);
     rectangle(200,150,450,200);
     rectangle(200,200,450,250);
     rectangle(200,250,450,300);
     rectangle(200,300,450,350);
     rectangle(200,350,450,400);
     rectangle(200,400,450,450);
     setfillstyle(1,GREEN);
     floodfill(250,125,WHITE);
     setfillstyle(1,RED);
     floodfill(250,175,WHITE);
     floodfill(250,225,WHITE);
     floodfill(250,275,WHITE);
     floodfill(250,325,WHITE);
     floodfill(250,375,WHITE);
     floodfill(250,425,WHITE);
     outtextxy(210,110,"ADD BOOKS");
     outtextxy(210,160,"DELETE BOOKS");
     outtextxy(210,210,"BORROW BOOKS");
     outtextxy(210,260,"RETURN BOOKS");
     outtextxy(210,310,"LIST");
     outtextxy(210,360,"DELETE STUDENT");
     outtextxy(210,410,"EXIT");
}

void std_acc_screen()
{
     settextstyle(0,0,2);
     outtextxy(225,50," STUDENT ");
     rectangle(200,100,450,150);
     rectangle(200,150,450,200);
     rectangle(200,200,450,250);

     settextstyle(0,0,2);
     setfillstyle(1,GREEN);
     floodfill(250,125,WHITE);
     setfillstyle(1,RED);
     floodfill(250,175,WHITE);
     floodfill(250,225,WHITE);
     outtextxy(210,110," BORROWED ");
     outtextxy(210,160," SEARCH ");
     outtextxy(210,210," EXIT ");
}

void after_std_login(char id[])
{
	closegraph();
	char did[20],daname[20],dbname[20];
	if(l_count==0)
	{
		gotoxy(0,2);
		FILE* fp = fopen("C:\\TC\\borrow.txt","r");
		printf("\t\t***********************************************");
		printf("\n\t\t\tBOOKS BORROWED BY STUDENT ID %s \n",id);
		printf("\t\t***********************************************\n");
		int i=1;
		while(!feof(fp))
		{
			fscanf(fp,"%s	%s	%s",did,daname,dbname);
			if(feof(fp))break;
			if(!strcmp(did,id))
			{
				printf("\n\t%d) %-20s   %-20s   %s",i,did,daname,dbname);
				i++;
			}
		}
		if(i==1)
		{
			printf("\n\n\t\t YOU DID NOT BORROW ANY BOOK ");
		}
		fclose(fp);
		getch();

	}

	else if(l_count==1)
	{
	     book dobj;
	     FILE* f;
	     int flag=0;

	     printf("\t\t************************************");
	     printf("\n\t\t\t\tSEARCH \n");
	     printf("\t\t***********************************\n");

	     f=fopen("C:\\TC\\books.png","rb");
	     printf("\nENTER BOOK NAME  :");
	     scanf("%s",dbname);
	     printf("\nAUTHOR NAME :");
	     scanf("%s",daname);
	     while(fread(&dobj,sizeof(dobj),1,f))
	     {
		   if((!strcmp(dobj.bname,dbname))&&(!strcmp(dobj.aname,daname))&&(dobj.ch!='*'))
		   {
		     printf("\n\n\nBOOK\tAUTHOR\tQUNTITY");
		     printf("\n**************************");
		     printf("\n\n%s\t%s\t%d",dobj.bname,dobj.aname,dobj.qty);
		     flag=1;
		     break;
		   }

	     }
	     if(flag==0)
	     {
		printf("\r\n\r\nBOOK IS NOT IN LIBRARY...");
	     }
	     getch();
	}

	else if(l_count==2)
	{
		return ;
	}

}

void after_lib()
{
	closegraph();
	window(30,5,70,20);
	book dobj,obj;
	if(l_count==0)
	{
			cprintf("ADD BOOKS \r\n");
			FILE* f=fopen("C:\\TC\\books.png","rb");
			cprintf("\r\nBOOK NAME :");
			scanf("%s",obj.bname);
			cprintf("\r\nAUTHOR NAME :");
			scanf("%s",obj.aname);
			cprintf("\r\nQUNTITY :  ");
			scanf("%d",&(obj.qty));
			obj.ch='\0';

			while(fread(&dobj,sizeof(dobj),1,f))
			{
			   if((!strcmp(dobj.bname,obj.bname))&&(!strcmp(dobj.aname,obj.aname))&&(dobj.ch!='*'))
			   {
			      cprintf("\r\n BOOK ALREADY AVAILABLE...");
			      getch();
			      return;
			   }
			}

			fclose(f);

			f=fopen("C:\\TC\\books.png","ab");
			fwrite(&obj,sizeof(obj),1,f);
			cprintf("\r\n DATA IS SUCCESSFULLY ENTERED...");
			fclose(f);
			getch();
	}
	else if(l_count==1)
	{
		     long int pos;
		     int flag=0;
		     cprintf("DELETE BOOKS \r\n");
		     FILE* f=fopen("C:\\TC\\books.png","rb+");
		     cprintf("\r\n ENTER BOOK NAME  :");
		     scanf("%s",dobj.bname);
		     cprintf("\r\nAUTHOR NAME :");
		     scanf("%s",dobj.aname);
		     pos=ftell(f);

		     while(fread(&obj,sizeof(obj),1,f))
		     {
			   if((!strcmp(dobj.bname,obj.bname))&&(!strcmp(dobj.aname,obj.aname))&&(obj.ch!='*'))
			   {
			     obj.ch='*';
			     fseek(f,pos,0);
			     fwrite(&obj,sizeof(obj),1,f);
			     flag=1;
			     fclose(f);
			     break;
			   }
			   pos=ftell(f);
		     }
		     if(flag==1)
		     cprintf("\r\n BOOK SUCCESSFULLY DELETED...");
		     else
		     cprintf("\r\n CANNOT FIND BOOK...");
		     getch();

	}
	else if(l_count==2)
	{

			long int pos;
			short some = 0;
			short fb=0;                          //this flag is used for whether book is there or not
			int fs=0;                          //it is used as flag to check wether student is there or not
			char sid[20],did[20],pass[20];

			cprintf("BORROW BOOKS \r\n");

			FILE* f=fopen("C:\\TC\\books.png","rb+");
			cprintf("\r\n ENTER THE NAME OF BOOK : ");
			scanf("%s",dobj.bname);
			cprintf("\r\n ENTER THE AUTHOR NAME : ");
			scanf("%s",dobj.aname);

			pos = ftell(f);

			while(fread(&obj,sizeof(obj),1,f))
			{
			   if((!strcmp(dobj.bname,obj.bname))&&(!strcmp(dobj.aname,obj.aname))&&(obj.ch!='*'))
			   {
				fb=1;
				if(obj.qty==0)     //if qty is zero that means out of stock
				{
					some=1;    //flag which checks stock is full or not
				}
				break;
			   }
			  pos=ftell(f);
			}
			fclose(f);

			if(fb==0 || some==1)
			{
			      if(some==0)
				   cprintf("\r\n cannot find the book...");
			      if(some!=0)
				   cprintf("\r\n book is already taken by someone...");
			      getch();

			      return;
			}
			else
			{
			      FILE* fp=fopen("C:\\TC\\stdacc.txt","r");
			      cprintf("\r\n ENTER THE ID OF BORROWER : ");
			      scanf("%s",sid);
			      while(!feof(fp))
			      {
				 fscanf(fp,"%s	%s",did,pass);
				 if(feof(fp))break;
				 if(!strcmp(did,sid))
				 {
				  fs=1;
				  break;
				 }
			      }
			      fclose(fp);
			      if(fs==0)
			      {
				cprintf("\r\n CANNOT FIND STUDENT ID...");
				getch();
			      }
			      else
			      {
				 f = fopen("C:\\TC\\books.png","rb+");

				 fp=fopen("C:\\TC\\borrow.txt","a");

				 fprintf(fp,"%s	%s	%s\n",sid,obj.bname,obj.aname);

				 --(obj.qty);

				fseek(f,pos,0);
				fwrite(&obj,sizeof(obj),1,f);
				cprintf("\r\nSUCCESSFULLY BORROW...");
				fclose(f);
				fclose(fp);
				getch();
			      }
			}
			fclose(f);

	}
	else if(l_count==3)
	{
			char did[20],dbname[20],daname[20];
			char id[20],bname[20],aname[20];
			long int pos;
			cprintf("RETURN BOOKS \r\n");

			cprintf("\r\n ENTER YOUR ID : ");
			scanf("%s",did);
			cprintf("\r\n ENTER BOOK NAME : ");
			scanf("%s",dbname);
			cprintf("\r\n ENTER AUTHOR NAME : ");
			scanf("%s",daname);

			FILE *b = fopen("C:\\TC\\borrow.txt","r+");
			pos = ftell(b);
			int flag=0;

			while(!feof(b))
			{
			    fscanf(b,"%s	%s	%s",id,bname,aname);
			    if(feof(b))break;

			    if((!strcmp(id,did))&&(!strcmp(bname,dbname))&&(!strcmp(aname,daname)))
			    {
				 flag=1;
				 break;
			    }
			    pos = ftell(b);
			}

			if(flag==1)
			{
				FILE* temp = fopen("C:\\TC\\temp.txt","w");
				fseek(b,0,0);

				while(!feof(b))
				{
				    if(ftell(b)==pos)
				    {
					fscanf(b,"%s	%s	%s",id,bname,aname);
					if(feof(b))break;
					continue;
				    }
				    fscanf(b,"%s	%s	%s",id,bname,aname);
				    if(feof(b))break;
				    fprintf(temp,"%s	%s	%s\n",id,bname,aname);
				}
				fclose(b);
				fclose(temp);

			       remove("C:\\TC\\borrow.txt") ;
			       rename("C:\\TC\\temp.txt","C:\\TC\\borrow.txt");

			       temp = fopen("C:\\TC\\books.png","rb+");

				pos = ftell(temp);
				while(fread(&obj,sizeof(obj),1,temp))
				{
					if((!strcmp(obj.bname,dbname))&&(!strcmp(obj.aname,daname)))
					{
						    break;
					}

					pos = ftell(temp);
				}


				(obj.qty)++;
				fseek(temp,pos,0);
				fwrite(&obj,sizeof(obj),1,temp);
				fclose(temp);
				cprintf("\r\n\r\n YOU SUCCESSFULLY RETURNED BOOK....");
			  }
			else
			{
			   cprintf("\r\n SOME INFORMATION IS WRONG...");
			}
			getch();

	}

	else if(l_count==4)
	{
			FILE* f=fopen("C:\\TC\\books.png","rb");

			printf("\n List of books : \n\n");
			printf("book_name           	author_name        	quntity\n");
			printf("------------------------------------------------------\n");

			while(fread(&dobj,sizeof(dobj),1,f))
			{
			   if(dobj.ch!='*')
			   printf("%-20s	%-20s	%-3d\n",dobj.bname,dobj.aname,dobj.qty);
			}
			getch();
			fclose(f);
	}

	else if(l_count==5)
	{
	     char id[20],password[20];
	     char f_id[20],f_pass[20];
	     short flag=0;           // check = check wether it is all book return or not
	     short check=1,force=1;  // flag = check wethter password is right or not
	     long int pos;           // force = forcefully delete all data

	     FILE* s = fopen("C:\\TC\\stdacc.txt","r+");
	     textcolor(RED);
	     cprintf(" DELETE ID\r\n");
	     textbackground(GREEN);
	     cprintf("\r\nENTER ID TO BE DELETED : \r\n");
	     scanf("%s",id);
	     cprintf("\r\nENTER  PASSWORD : \r\n");
	     scanf("%s",password);

	     pos = ftell(s);

	     while(!feof(s))
	     {
		    fscanf(s,"%s	%s",f_id,f_pass);
		    if(feof(s))break;
		    if((!strcmp(f_id,id))&&(!strcmp(f_pass,password)))
		    {
				flag=1;
				pos=ftell(s);
				break;
		    }
		    pos=ftell(s);
	     }

	     FILE* b = fopen("C:\\TC\\borrow.txt","r+");
	     while(!feof(b))
	     {

		fscanf(b,"%s	%s	%s",f_id,f_pass,password);        // f_pass is used for taking book name
		if(feof(b))break;

		if(!strcmp(f_id,id))
		{
			check=0;
			break;
		}
	     }

	     if(flag==0)
	     {
		fclose(s);
		fclose(b);
		cprintf("\r\n SOMETHING WRONG IN INFORMATION...");

	     }
	     else if(check==0)
	     {
		cprintf("\n\r SOME BOOKS DO NOT RETURNED BY YOU....");
		cprintf("\n\r\n\r FORCEFULLY DELETE (1/0): ");
		scanf("%hd",&force);
		if(force==0)
		{
			fclose(s);
			fclose(b);
			cprintf("\n\r FAIL TO DELETE...");
		}
	     }

	     if(force==1 && flag!=0)
	     {

			char aname[20];
			FILE* temp = fopen("C:\\TC\\temp.txt","w");
			fseek(s,0,0);
			while(!feof(s))
			{
				fscanf(s,"%s	%s",f_id,f_pass);
				if(feof(s))break;

				if(ftell(s)==pos)
				continue;
				fprintf(temp,"%s	%s\n",f_id,f_pass);
			}
			fclose(s);
			fclose(temp);
			remove("C:\\TC\\stdacc.txt") ;
			rename("C:\\TC\\temp.txt","C:\\TC\\stdacc.txt");

			temp = fopen("C:\\TC\\temp.txt","w");
			fseek(b,0,0);
			while(!feof(b))
			{
				fscanf(b,"%s	%s	%s",f_id,f_pass,aname);        // f_pass is used for taking book name
				if(feof(b))break;

				if(!strcmp(f_id,id))
				continue;
				fprintf(temp,"%s	%s	%s\n",f_id,f_pass,aname);
			}
			fclose(b);
			fclose(temp);
			remove("C:\\TC\\borrow.txt") ;
			rename("C:\\TC\\temp.txt","C:\\TC\\borrow.txt");
			cprintf("\r\n ID IS SUCCESSFULLY DELETED ");
	     }
	     getch();
	}

}


void after_login()
{

	closegraph();
	window(30,5,70,20);
	if(l_count==4)
	{
	     return;
	}
	else if(l_count==3)
	{
	     char id[20],password[20];
	     char f_id[20],f_pass[20];
	     char n_id[20],n_pass[20];
	     FILE* fp=fopen("C:\\TC\\libacc.txt","r");

	     fscanf(fp,"%s	%s",f_id,f_pass);
	     textcolor(RED);
	     cprintf("NEW LIBRARAIN : \r\n");
	     textbackground(GREEN);
	     cprintf("\r\nENTER YOUR OLD LOGIN ID : \r\n");
	     scanf("%s",id);
	     cprintf("\r\nENTER OLD PASSWORD : \r\n");
	     scanf("%s",password);
	     getch();

	     if((strcmp(f_pass,password))||(strcmp(f_id,id)))
	     {
	       cprintf("\r\nINCORRECT PASSWORD/ID....");
	       return;
	     }
	     cprintf("\r\nENTER YOUR NEW LOGIN ID : \r\n");
	     scanf("%s",n_id);
	     cprintf("\r\nENTER NEW PASSWORD : \r\n");
	     scanf("%s",n_pass);
	     fclose(fp);
	     fp=fopen("C:\\TC\\libacc.txt","w");
	     fprintf(fp,"%s	%s",n_id,n_pass);
	     fclose(fp);
	     cprintf("\r\nID SUCCESSFULLY CHANGED...");
	     getch();

	}

	else if(l_count==2)
	{
	     char id[20],password[20],l_pass[20],f_pass[20];
	//     closegraph();
	     FILE* fp=fopen("C:\\TC\\libacc.txt","r");
	     fscanf(fp,"%s");
	     fscanf(fp,"%s",f_pass);
	     textcolor(RED);
	     cprintf("NEW STUDENT USER : \r\n");

	     textbackground(GREEN);
	     cprintf("\r\n ENTER LIBRARIAN PASSWORD : \r\n");
	     scanf("%s",l_pass);
	     if(strcmp(l_pass,f_pass))
	     {
		cprintf("\r\nINCORRECT PASSWORD...\r\n");
		  fclose(fp);
		return;
	     }
	     fclose(fp);
	     fp = fopen("C:\\TC\\stdacc.txt","a");

	     cprintf("\r\nENTER NEW ID : \r\n");
	     scanf("%s",id);
	     cprintf("\r\n ENTER PASSWORD : \r\n");
	     scanf("%s",password);

	     fprintf(fp,"%s	%s\n",id,password);
	     cprintf("\r\nSUCCESSFULLY CREATED ACCOUNT...");
	     getch();
	     fclose(fp);
	}

	else if(l_count==1)
	{
	     char id[20],password[20];
	     char f_id[20],f_pass[20];
	     FILE* fp=fopen("C:\\TC\\libacc.txt","r");
	     fscanf(fp,"%s	%s",f_id,f_pass);
	     fclose(fp);
	     textcolor(RED);
	     cprintf("WELCOME TO LIBRAINAN LOGIN : \r\n");
	     textbackground(GREEN);
	     cprintf("\r\n LOGIN ID : \r\n");
	     scanf("%s",id);
	     cprintf("\r\n PASSWORD : \r\n");
	     scanf("%s",password);
	     if((!strcmp(f_id,id))&&(!strcmp(f_pass,password)))
	     {
	       int key;
	       cprintf("\r\nSUCCFULLY LOGED IN...\r\n");
	       getch();
	       clrscr();
	       fclose(fp);
	       initgraph(&gd,&gm,"C:\\TC\\BGI");
	       l_count=0;
	       lib_screen();
	       while(1)
	       {
			key=getch();
			if(key==0)
			{
			    key=getch();
			}
			if(key==13)
			{
			   closegraph();
			   if(l_count==6)
			   {
			     break;
			   }
			   else
			   {
				after_lib();
				initgraph(&gd,&gm,"C:\\TC\\BGI");
				lib_screen();
				l_count=0;
			   }
			}
			if(key==72)                     //UP
			{
			   selector(1,6);               //selector() when call with 1 its mean up aerrow is pressed
			}
			else if(key==80)                //down
			{
			  selector(0,6);
			}
		  }
	     }
	     else
	     {
		cprintf("\r\nWRONG ID/PASSWORD...");
		getch();
	     }
	}

	else if(l_count==0)
	{

	     char id[20],password[20];
	     char f_pass[20];
	     textcolor(RED);
	     cprintf("WELCOME TO STUDENT LOGIN : \r\n");
	     textbackground(GREEN);
	     cprintf("\rENTER LOGIN ID : \r\n");
	     scanf("%s",id);
	     cprintf("\r\nENTER PASSWORD : \r\n");
	     scanf("%s",password);
	     get_s_password(id,f_pass);
	     if(f_pass[0]=='\0')
	     {
		cprintf("\r\nINCORRECT ID...");
		getch();
		return;
	     }
	     else if(strcmp(password,f_pass))
	     {
	       cprintf("\r\nINCORRECT PASSWORD...");
	       getch();
	       return;
	     }
	     else
	     {
		      cprintf("\r\nSUCCESSFULLY LOGIN....");
		      getch();
		      int key;
		      initgraph(&gd,&gm,"C:\\TC\\BGI");
		      l_count=0;
		      std_acc_screen();
		      while(1)
		      {
			    key=getch();
			    if(key==0)
			    {
				 key=getch();
			    }
			    if(key==13)
			    {
				 if(l_count==2)
				 {
					  break;
				 }
				 else
				 {
				      after_std_login(id);
				      initgraph(&gd,&gm,"C:\\TC\\BGI");
				      std_acc_screen();
				      l_count=0;
				 }
			    }
			    if(key==72)                     //UP
			    {
				selector(1,2);               //selector() when call with 1 its mean up aerrow is pressed
			    }
			    else if(key==80)                //down
			    {
				selector(0,2);
			    }
			}   //end while
		}           //end else
      }                     //end else if
}                           //end fun

int main()
{
   int key,temp;
   initgraph(&gd,&gm,"C:\\TC\\BGI");
   login_screen();
   while(1)
   {
	key=getch();
	if(key==0)
	{
	    key=getch();
	}
	if(key==13)
	{
	   if(l_count==4)
	   {
		break;
	   }
	   else
	   {
		after_login();
		delay(40);
		initgraph(&gd,&gm,"C:\\TC\\BGI");
		login_screen();
		l_count=0;
	   }
	}
	if(key==72)                //UP
	{
	 selector(1,4);               //selector() when call with 1 its mean up aerrow is pressed
	}
	else if(key==80)           //down
	{
	  selector(0,4);
	}
   }
   cleardevice();
   closegraph();
  // getch();
   return 0;
}