/*       ***********PROJECT************       */
/*CUSTOMER MANAGEMENT IN MOBILE SERVICE CENTER*/
/*CREATED BY-------
			RAHUL KUNDU
			
*/
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<stdlib.h>
	struct date
	{
		int dd,mm,yy;
	};
	struct cust
	{
		long unsigned int imeino;
		char name[20];
		struct date dob;
		char model[10];
		char address[15];
	       //	long unsigned int phno[15];
	       char phno[15];
	}c;

	struct modl
	{
		char model[10];
		char facility[30];
	}m;

	struct pro
	{
	  long unsigned int imeino;
	  char problem[25];
	  int charge;
	  struct date dos;
	  struct date dop;
	}p;

class box                                  //program to create box
{
		char tl,tr,bl,br,v,h;
		int bt;
	public:
	       box(int,int,int,int,int);
 };
 box::box(int r1=1, int c1=1, int r2=24, int c2=80, int bt=1)
 {
	if(bt==1)
	{
		tl=218; tr=191;
		bl=192; br=217;
		v=179; h=196;
	}
	else
	{
		tl=201; tr=187;
		bl=200; br=188;
		v=186; h=205;
	}
		int i;
	gotoxy(c1,r1);
	cout<<tl;
	gotoxy(c1,r2);
	cout<<bl;
	for(i=c1+1;i<c2;++i)
	{
		gotoxy(i,r1);
		cout<<h;
		gotoxy(i,r2);
		cout<<h;
	}
	for(i=r1+1;i<r2;++i)
	{
		gotoxy(c1,i);
		cout<<v;
		gotoxy(c2,i);
		cout<<v;
	}
	{
		gotoxy(c2,r1);
		cout<<tr;
		gotoxy(c2,r2);
		cout<<br;
	 }
 }

//#include"header.cpp"                        //program to create the starting screen
//#include"menu.cpp"
void menu();
void subadd();
void subdispl();
void submenu();
void modifyf();
void erasef();
void main()
{
	void welcomec();
	clrscr();
	textbackground(WHITE);
	welcomec();
}
	void welcomec()
	{
		int cho;
		do
		{
			box z1(1,14,14,68,2);
			box z2(11,25,13,55,1);
			gotoxy(25,3);
			textcolor(BLUE+BLINK);
			cprintf("WELCOME TO NOKIA SERVICE CENTER");
			textcolor(BROWN);
			gotoxy(16,5);
			cprintf("A projact created by Rahul Kundu");
			textcolor(RED);
			gotoxy(30,8);
			cprintf("Press <1> for MENU");
			gotoxy(30,10);
			cprintf("Press <2> for EXIT");
			gotoxy(28,12);
			cprintf("Enter your choice<1-2>:");
			cin>>cho;
			switch(cho)
			{
				case 1:
					menu();
					break;
				case 2:
					clrscr();
					box r1(1,24,10,60,2);
					textcolor(BLUE+BLINK);
					gotoxy(25,3);
					cprintf(" THANKS FOR VISITING THE PROJECT");
					gotoxy(30,5);
					printf("Created by-----");
					gotoxy(35,7);
					cprintf("Rahul Kundu");
					getch();
					return;
			}
			clrscr();
		}while(cho!=2);
}


/*#include"subadd.cpp"
#include"submenu.cpp"
#include"subdispl.cpp"
#include"erasef.cpp"
#include"modifyf.cpp"
*/
void menu()                 //program to create main menu
{
	int cho, r=27;
	do
	{
		clrscr();
		box b1(1,15,19,70,2);
	   //	getch();
		box d2(16,16,18,68,1);
	    //	getch();
		gotoxy(r+5,3);
		textcolor(BLUE+BLINK);
		cprintf("****** M E N U ******");
		textcolor(RED);
		gotoxy(r,5);
		cprintf("1.ADD DETAILS");
		textcolor(RED);
		gotoxy(r,7);
		cprintf("2.DISPLAY DETAILS");
		textcolor(RED);
		gotoxy(r,9);
		cprintf("3.SEARCH");
		textcolor(RED);
		gotoxy(r,11);
		cprintf("4.DELETE");
		textcolor(RED);
		gotoxy(r,13);
		cprintf("5.MODIFY");
		gotoxy(r,15);
		cprintf("6.Exit");
		gotoxy(r-2,17);
		cprintf("Enter your choice(1-6):-");
		cin>>cho;
	switch(cho)
	{
		case 1:
			subadd();
			break;
		case 2:
			subdispl();
			break;
		case 3:
			submenu();
			break;
		case 4:
			erasef();
			break;
		case 5:
			modifyf();
			break;
		case 6:
			return;
	}
	clrscr();
	}while(cho!=6);
}

void addf();
void addm();
void addp();
/*#include"addf.cpp"
#include"model.cpp"
#include"prob.cpp"
*/
void subadd()                      //subprogram for Add menu
{
	int cho, r=27;
	do
	{
		clrscr();
		box z1(1,15,15,70,2);
	   //	getch();
		box z2(12,17,14,68,1);
	    //	getch();
		gotoxy(r+2,3);
		textcolor(BLUE+BLINK);
		cprintf("****** ADD DETAILS ******");
		textcolor(RED);
		gotoxy(r,5);
		cprintf("1.ADD CUSTOMER DETAILS");
		textcolor(RED);
		gotoxy(r,7);
		cprintf("2.ADD MODEL DETAILS");
		textcolor(RED);
		gotoxy(r,9);
		cprintf("3.ADD PROBLEM DETAILS");
		textcolor(RED);
		gotoxy(r,11);
		cprintf("4.BACK");
		gotoxy(r-2,13);
		cprintf("Enter your choice(1-4):-");
		cin>>cho;
	switch(cho)
	{
		case 1:
			addf();
			break;
		case 2:
			addm();
			break;
		case 3:
			addp();
			break;
		case 4:
			return;
	}
	clrscr();
	}while(cho!=4);
}

	void addf()                    //program to add customer details
	{
		char cho;
		FILE *fp;
		fp=fopen("custin.dat","ab");
	do
	{
		clrscr();
		 box x(2,20,25,60,1);
	       //	 getch();
		gotoxy(30,5);
		textcolor(RED);
		cprintf("Add Customer Details:");
		gotoxy(35,7);
		textcolor(BLUE);
		cprintf("IMEI no:");
		scanf("%lu",&c.imeino);
		gotoxy(38,9);
		cprintf("Name:");
		scanf("%s",&c.name);
		gotoxy(25,11);
		cprintf("Enter date of buy:");
		scanf("%d%d%d",&c.dob.dd,&c.dob.mm,&c.dob.yy);
		gotoxy(33,13);
		cprintf("Model no:");
		scanf("%s",&c.model);
		gotoxy(35,15);
		cprintf("Address:");
		scanf("%s",&c.address);
		gotoxy(33,17);
		cprintf("Phone no:");
		scanf("%s",&c.phno);
		fwrite(&c,sizeof(c),1,fp);
		gotoxy(25,19);
		textcolor(RED);
		cprintf("Wants to continue...(Y/N):");
		cin>>cho;
	}while(cho=='y');
	fclose(fp);
	}


	void addm()                       //program to add model details
	{
		char cho;
		FILE *fp;
		fp=fopen("model.dat","ab");
	do
	{
		clrscr();
		 box x(2,20,15,60,1);
	       //	 getch();
		gotoxy(30,5);
		textcolor(RED);
		cprintf("Add Mobile Details:");
		gotoxy(36,7);
		textcolor(BLUE);
		cprintf("MODEL:");
		scanf("%s",&m.model);
		gotoxy(33,9);
		cprintf("Facility:");
		scanf("%s",&m.facility);
		fwrite(&m,sizeof(m),1,fp);
		gotoxy(25,12);
		textcolor(RED);
		cprintf("Wants to continue...(Y/N):");
		cin>>cho;
	}while(cho=='y');
	fclose(fp);
	}


	void addp()                        //program to add problem details
	{
		char cho;
		FILE *fp;
		fp=fopen("prob.dat","ab");
	do
	{
		clrscr();
		box x1(2,20,20,60,1);
		gotoxy(30,5);
		textcolor(RED);
		cprintf("Add Problem Details:");
		gotoxy(36,7);
		textcolor(BLUE);
		cprintf("IMEI no:");
		scanf("%lu",&p.imeino);
		gotoxy(35,9);
		cprintf("Problems:");
		scanf("%s",&p.problem);
		gotoxy(26,11);
		cprintf("Enter date of Buy:");
		scanf("%d%d%d",&p.dop.dd,&p.dop.mm,&p.dop.yy);
		gotoxy(22,13);
		cprintf("Enter date of Service:");
		scanf("%d%d%d",&p.dos.dd,&p.dos.mm,&p.dos.yy);
		gotoxy(37,15);

	    //  int pd=p.dop.dd,p.dop.mm,p.dop.yy;
	     // int cd=p.dos.dd,p.dos.mm,p.dos.yy;

		if(p.dos.dd<p.dop.dd)
		{

		p.dos.dd=p.dos.dd+30;
		p.dos.mm=p.dos.mm-1;
		}
		if(p.dos.mm<p.dos.mm)
		{
		p.dos.mm=p.dos.mm+12;
		p.dos.yy=p.dos.yy-1;
		}
	      int ty=p.dos.yy-p.dop.yy;
	       if(ty<=1)
	       {
		//scanf("%d",&p.charge);
		cprintf("Charge:Null");
	       }
		else
	       {
		cprintf("Charge:");
		scanf("%d",&p.charge);
		}
		fwrite(&p,sizeof(p),1,fp);
		gotoxy(25,17);
		textcolor(RED);
		cprintf("Wants to continue...(Y/N):");
		cin>>cho;
	}while(cho=='y');
	fclose(fp);
	}

void list1();
void list2();
void list3();
/*#include"link.cpp"
#include"link2.cpp"
#include"link3.cpp"
*/
void subdispl()                           //subprogram for display menu
{
	int cho, r=27;
	do
	{
		clrscr();
		box b1(1,15,15,70,2);
	   //	getch();
		box d2(12,17,14,68,1);
	    //	getch();
		gotoxy(r+5,3);
		textcolor(BLUE+BLINK);
		cprintf("****** DISPLAY DETAILS ******");
		textcolor(RED);
		gotoxy(r,5);
		cprintf("1.DISPLAY CUSTOMER DETAILS");
		textcolor(RED);
		gotoxy(r,7);
		cprintf("2.DISPLAY MODEL DETAILS");
		textcolor(RED);
		gotoxy(r,9);
		cprintf("3.DISPLAY PROBLEM DETAILS");
		textcolor(RED);
		gotoxy(r,11);
		cprintf("4.BACK");
		gotoxy(r-2,13);
		cprintf("Enter your choice(1-4):-");
		cin>>cho;
	switch(cho)
	{
		case 1:
			list1();
			break;
		case 2:
			list2();
			break;
		case 3:
			list3();
			break;
		case 4:
			return;
	}
	clrscr();
	}while(cho!=4);
}

	void list1()               //program to display customer details
	{
		FILE *fp;
		int rc=1;
		void head();
		fp=fopen("custin.dat","rb");
		clrscr();
		head();
		rc=2;
		while(fread(&c,sizeof(c),1,fp)!=NULL)
		{
			if(rc%19 !=0)
			{
			printf("%-7lu  %-8s %11d-%2d-%4d %-7s %-12s %15s\n",c.imeino,c.name,c.dob.dd,c.dob.mm,c.dob.yy,c.model,c.address,c.phno);
			rc++;
			}
			else
			{
			printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Press any kye to continue...");
			getch();
			clrscr();
			head();
			rc=4;
			}
		 }
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		fclose(fp);
		getch();
	}
	void head()
	{
		textcolor(RED+BLINK);
		cprintf("        List of Customer ");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("IMEI NO     NAME          DATE_OF_BUY  MODEL  ADDRESS                 PH_No");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}

	void list2()                       //program to display model details
	{
		FILE *fp;
		int rc=0;
		void display();
		fp=fopen("model.dat","rb");
		clrscr();
		display();
		rc=4;
		while(fread(&m,sizeof(m),1,fp)!=NULL)
		{
			if(rc%21 !=0)
			{
			printf(" %5s  %12s\n",m.model,m.facility);
			rc++;
			}
			else
			{
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Press any kye to continue...");
			getch();
			clrscr();
			display();
			rc=4;
			}
		  }
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		fclose(fp);
		getch();
	}
	void display()
	{
		textcolor(RED+BLINK);
		cprintf("        MOBILE DETAILS ");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("MODEL         FACELITY");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}

	void list3()                      //program to display problem details
	{
		FILE *fp;
		int rc=0;
		void display2();
		fp=fopen("prob.dat","rb");
		clrscr();
		display2();
		rc=4;
		while(fread(&p,sizeof(p),1,fp)!=NULL)
		{
			if(rc%21 !=0)
			{
			printf(" %-5lu  %-15s %6d-%2d-%4d %6d-%2d-%4d %6d\n",p.imeino,p.problem,p.dop.dd,p.dop.mm,p.dop.yy,p.dos.dd,p.dos.mm,p.dos.yy,p.charge);
			rc++;
			}
			else
			{
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			printf("Press any kye to continue...");
			getch();
			clrscr();
			display2();
			rc=4;
			}   }
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		fclose(fp);
		getch();
	}
	void display2()
	{
		textcolor(RED+BLINK);
		cprintf("        SERVICE DETAILS ");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("IMEI NO  PROBLEM            DATE_OF_BUY  SERVICE_DATE  CHARGE");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}

void search();
void search_char();
/*#include"ser_char.cpp"
#include"search.cpp"
*/
void submenu()                      //subprogram for search menu
{
	int cho, r=27;
	do
	{
		clrscr();
		box b1(1,15,13,70,1);
	   //	getch();
		box d2(10,17,12,68,1);
	    //	getch();
		gotoxy(r+5,3);
		textcolor(BLUE+BLINK);
		cprintf("****** S E A R C H ******");
		textcolor(RED);
		gotoxy(r,5);
		cprintf("1.SEARCH BY IMEI NO");
		textcolor(RED);
		gotoxy(r,7);
		cprintf("2.SEARCH BY CUSTOMER NAME");
		textcolor(RED);
		gotoxy(r,9);
		cprintf("3.BACK");
		gotoxy(r-2,11);
		cprintf("Enter your choice(1-3):-");
		cin>>cho;
	switch(cho)
	{
		case 1:
			search();
			break;
		case 2:
			search_char();
			break;
		case 3:
			return;
	}
	clrscr();
	}while(cho!=3);
}


	void search()                     //program for search by number
	{
		FILE *fp;
		int found=0,ino;
		void get();
		fp=fopen("custin.dat","rb");
		clrscr();
		cout<<"\n Enter IMEI no to be search:";
		cin>>ino;
		//head();
		while(fread(&c,sizeof(c),1,fp)!=NULL)
		{
			if(c.imeino==ino)
			{
			get();
			printf("%-5lu  %10s %13d-%d-%d %7s %6s %15s\n",c.imeino,c.name,c.dob.dd,c.dob.mm,c.dob.yy,c.model,c.address,c.phno);
			found=1;
			break;
			}

		 }
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		if(found==0)
		{
			printf("Record Not Found");
		}
		fclose(fp);
		getch();
	}
	void get()
	{
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("         Customer Details");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("IMEI NO     NAME          DATE_OF_BUY  MODEL  ADDRESS            PH_No    ");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}


	void search_char()                  //program for search by name
	{
		FILE *fp;
		int found=0;
		char cname[20];
		void get1();
		fp=fopen("custin.dat","rb");
		clrscr();
		cout<<"\n Enter Name to be search:";
		cin>>cname;
		//head();
		while(fread(&c,sizeof(c),1,fp)!=NULL)
		{
			if(strcmpi(c.name,cname)==0)
			{
			get1();
			printf("%5lu  %8s %13d-%d-%d %7s %6s %15s\n",c.imeino,c.name,c.dob.dd,c.dob.mm,c.dob.yy,c.model,c.address,c.phno);
			found=1;
			break;
			}

		 }
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Press any key...");
		if(found==0)
		{
			printf("Record Not Found");
		}
		fclose(fp);
		getch();
	}
	void get1()
	{
		textcolor(RED+BLINK);
		printf("\n");
		cprintf("         Customer Details");
		printf("\n\t\t\t\t\tDate:-%s\n",__DATE__);
		textcolor(BLUE);
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		cprintf("IMEI NO     NAME          DATE_OF_BUY  MODEL  ADDRESS       PH_No      ");
		printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		}


void erasef()                               //program for deletion
{
	long unsigned int drno;
	clrscr();
	cout<<"\n Enter an IMEI NO to be delete:";
	cin>>drno;
	FILE *fp;
	FILE *ft;
	fp=fopen("custin.dat","rb");
	ft=fopen("temp.dat","wb");
	while(fread(&c,sizeof(c),1,fp)!=NULL)
	{
		if(c.imeino!=drno)
		{
			fwrite(&c,sizeof(c),1,ft);
		}
	}
	//fclose(fp);
	//fclose(ft);
	remove("custin.dat");
	rename("temp.dat","custin.dat");
	cout<<"\n------------------------------------------------------";
	cout<<"\nItem Deleted Successfully";
	cout<<"\n------------------------------------------------------";
	fclose(fp);
	fclose(ft);
       getch();
}


void modifyf()          		//program for modification
{
	long unsigned int drno;
	struct cust ts;
	clrscr();
	cprintf("Enter Imeino to be modify:");
	cin>>drno;
	FILE *fp;
	FILE *ft;
	fp=fopen("custin.dat","rb");
	ft=fopen("Temp.dat","wb");

	while(fread(&c,sizeof(c),1,fp)!=NULL)
	{
		printf("size of record %d and position %d\n",sizeof(c),ftell(fp));
		if(c.imeino!=drno)
		{
		fwrite(&c,sizeof(c),1,ft);
		}
		else
		{
		 /* do modification */
		 printf("\n\n\n");
		 cprintf("old values\n");
		 printf("%lu    %s %s  %d-%d-%d %s %s\n\n",c.imeino,c.name,c.model,c.dob.dd,c.dob.mm,c.dob.yy,c.address,c.phno);
		 cprintf("Enter New Name:");
		 scanf("%s",c.name);
		 strcpy(ts.name,c.name);
		 ts.imeino = c.imeino;
		 strcpy(ts.model,c.model);
		 ts.dob.dd=c.dob.dd;
		 ts.dob.mm=c.dob.mm;
		 ts.dob.yy=c.dob.yy;
		 strcpy(ts.address,c.address);
		 //ts.phno= c.phno;
		 strcpy(ts.phno,c.phno);
		 fwrite(&ts,sizeof(ts),1,ft);
		 }
	 }
	fclose(fp);
	fclose(ft);
	remove("custin.dat");
	rename("Temp.dat","custin.dat");
	cout<<"Data Modification Successfully";
	getch();
}
