#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int max=1;
void intial();
struct studentrecord{
	char s_name[30];
	char grade;
	int roll_no;
	char f_name[30];
	char m_name[30];
	char contact[11];
}stu;
struct studentrecord *p=&stu;
void xyz(int n)
{ 
	int i;
	int b=n;
	int a=1;
	printf("\n*****************************************************************************************\n");
	printf("\t\t\t\tSTUDENTS RECORDS\n");
	printf("SL.NO\t\tROLL.NO\t\tGRADE\t\tCONTACT DETAILES\t\tNAME\n");
	printf("*****************************************************************************************\n");
	for(i=0;i<b;i++){
	 	printf("%d\t\t%d\t\t%c",a,(p+i)->roll_no,(p+i)->grade);
	 	printf("\t\t%s\t\t%s\n",(p+i)->contact,(p+i)->s_name);
	 	a++;
	}
	printf("press any key to continue!");
	getch();
}
int std_rec()
{
	p=(struct studentrecord*)realloc(p,max*sizeof(struct studentrecord));
	char yn;
	int a,l;
	printf("\n*****************************************************************************************\n");
	printf("\t\t\t\tADD STUDENT RECORD\n");
	printf("*****************************************************************************************\n");
	static int n=0;
	a=n;
	printf("Student Name:");
	fflush(stdin);
	gets((p+n)->s_name);
	printf("Grade:");
	fflush(stdin);
	(p+n)->grade=getch();
	printf("%c\n",(p+n)->grade);
	printf("Roll number:");
	fflush(stdin);
	scanf("%d",&(p+n)->roll_no);
	printf("Fathers name:");
	fflush(stdin);
	gets((p+n)->f_name);
	printf("Mothers name:");
	fflush(stdin);
	gets((p+n)->m_name);
	printf("Enter contact number:");
	fflush(stdin);
	gets((p+n)->contact);
	max++;
	printf("Do you want  to add one more record(Yes-y/No-n):");
	fflush(stdin);
	scanf("%s",&yn);
	if(yn=='y'||yn=='Y')
	{
		n++;
		std_rec();
	}
	else{
	printf("THE RECORDES ARE ADDED SUCCESSFULLY :)");
	l=getch();
	n++;
	return n;
    }
}
void search_rec(int x)
{
	//system("cls");
	int fi=0,n=0,i;
	char l;
	printf("\n*****************************************************************************************\n");
	printf("\t\t\t\tSEARCH STUDENT RECORD\n");
	printf("*****************************************************************************************\n");
	printf("\t\tEnter the student Roll.no to search a record:");
	scanf("%d",&fi);
	while(n<=x)//here x is length of array of structure
	{
		if((p+n)->roll_no==fi)
		{
			printf("\n______________________________________________________________________________\n");
            printf("\t\tTHE STUDENT RECORD WITH ROLL.NO %d IS FOUND:",fi);
            printf("\nNAME=%s\nGRADE=%c\nFATHER NAME=%s\nMOTHER NAME=%s\nCONTACT NO.=%s",(p+n)->s_name,(p+n)->grade,(p+n)->f_name,(p+n)->m_name,(p+n)->contact);
            //break;
            printf("\nPRESS 'Y' TO SEARCH AGAIN!\nPRESS 'N' TO GOTO MAIN MENU!\n");
		     l=getch();
		     if(l=='Y'||l=='y'){
		      	search_rec(x);
		      }
		else
		{
			main();
		}
	    }
	    else
	    n++;  
	}
	if(n>x)
	{
		printf("\n______________________________________________________________________________\n");
		printf("\t\t  The record was not found :(\n");
		printf("______________________________________________________________________________\n");
		printf("PRESS 'Y' TO SEARCH AGAIN!\nPRESS 'N' TO GOTO MAIN MENU!\n");
		l=getch();
		if(l=='Y'||l=='y'){
			search_rec(x);
		}
		else
		{
			main();
		}
		
	}
	//return 0;
}
int abc()
{
	int abc;
	printf("\n1.ADD STUDENT RECORDS\n2.SEARCH A STUDENT RECORD\n3.MODIFY A STUDENT RECORD\n4.DISPLAY ALL RECORDS\n5.EXIT\n");
    printf("Enter the choice :");
    scanf("%d",&abc);
	return abc;
}
void rec_mod(int x)
{
	int sec=0,n=0,i,l;
	printf("\n*****************************************************************************************\n");
	printf("\t\t\tMODIFY A STUDENT RECORD\n");
	printf("*****************************************************************************************\n");
	printf("\t\tENTER THE STUDENT ROLL.NO TO MODIFY THE RECORD:");
	scanf("%d",&sec);
	while(n<=x)//here 20 is length of array of structure
	{
		if((p+n)->roll_no==sec)
		{
			printf("\n_________________________________________________________________________________________\n");
            printf("the student record with roll.no %d is found:",sec);
            printf("\nNAME:%s    ROLL.NO:%d\n",(p+n)->s_name,(p+n)->roll_no);
            printf("_________________________________________________________________________________________\n");
            printf("Enter New grade:");
            fflush(stdin);
            (p+n)->grade=getch();
            printf("%c\n",(p+n)->grade);
            printf("Enter New contact number:");
            scanf("%s",(p+n)->contact);
            printf("\n________________________________________________________________\n");
            printf("THE RECORD IS UPDATED SUCCESSFUL:)\n");
            printf("________________________________________________________________\n");
            printf("PRESS 'Y' TO SEARCH AGAIN!\nPRESS 'N' TO GOTO MAIN MENU!\n");
		    l=getch();
		    if(l=='Y'||l=='y'){
			rec_mod(x);
		    }
		    else
		    {
			main();
		    }
	    }
	    else
	    n++;  
	}
	if(n>x)
	{
		printf("The record was not found :(");
		printf("PRESS 'Y' TO SEARCH AGAIN!\nPRESS 'N' TO GOTO MAIN MENU!\n");
		    l=getch();
		    if(l=='Y'||l=='y'){
			rec_mod(x);
		    }
		    else
		    {
			main();
		    }
	}
}
	
int main()
{
	static int l=0,x;
	int choice,n;
	if(l==0)
	{
		intial();
		printf("\n==========================================================================================\n");
	    printf("\t\t\tWELCOME TO STUDENT RECORD MANAGEMENT SYSTEM\n");
    	printf("==========================================================================================\n");
		l++;
	}
    do
    {
    
		if(l>=2)
		{
			printf("\n==========================================================================================\n");
	        printf("\t\t\tSTUDENT RECORD MANAGEMENT SYSTEM\n");
    	    printf("==========================================================================================\n");
		}
        choice=abc();
        lmn:
        if(choice>=6||choice<1)
        {
          	printf("Enter a correct choice again! :");
            scanf("%d",&choice);
        	//main();
            goto lmn;
	    }
	    do{
		
            if(choice==1)
            {
            	x=std_rec();
            	l++;
            	main();
			}
            if((choice>=2&&choice<5)&&(l==1&&x==0))
            {
            	printf("ADD ATLEAST ONE STUDENT RECORD...\n");
            	getch();
            	//l++;
            	main();
			}
			if(0)
            x=std_rec();
            else if(choice==2)
            search_rec(x);
            else if(choice==3)
            rec_mod(x);
            else if(choice==4)
            {
            	xyz(x);
            break;
			}
            else
		    {
			    free(p);
        	    printf("---------------------------THANK YOU :)------------------------------------");
        	    exit(0);
		    }
       
           }while(choice!=5);
            l++;
    }while(choice!=5);

   return 0; 
}
void intial()
{
	p=(struct studentrecord*)malloc(max*sizeof(struct studentrecord));
}
