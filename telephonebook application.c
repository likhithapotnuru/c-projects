#include<stdio.h>
void add();
void remov();
void search();
void edit();
void display();
int main()
{
	system("color 1e");
	system("cls");
	int op;
	printf("\t\t\t\t*****PHONEBOOK APPLICATION*****\n");
	printf("\tEnter any option from the below list for it's respective operation to perform\n");
	printf("\t\t\t\t\t1.Add Contact\n");
	printf("\t\t\t\t\t2.Delete Contact\n");
	printf("\t\t\t\t\t3.Search Contact\n");
	printf("\t\t\t\t\t4.Modify Contact\n");
	printf("\t\t\t\t\t5.Display Contact\n");
	printf("\t\t\t\t\t6.Exit\n");
	printf("Enter the option : ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:add();
		break;
		case 2:remov();
		break;
		case 3:search();
		break;
		case 4:edit();
		break;
		case 5:display();
		break;
		case 6:exit(1);
		default:main();
	}
}
void add()
{
	system("cls");
	FILE *fp;
	char name[50],phone[50];
	printf("\t*ADD CONTACT*");
	fp=fopen("phone.txt","a");
	printf("\n\tName : "); 
	scanf("%s",name); 
	printf("\n\tMob No. : " );
	scanf("%s",phone);
	fprintf(fp,"%s %s\n",name,phone); 
	fclose(fp); 
	printf("\n\tContact added successfully\n");
	sleep(2);
	system("cls");
	main();
}
void remov()
{
	system("cls");
	FILE *fp,*fp1;
	int flag=0;
	char name[50],name1[50],phone[50];
	fp=fopen("phone.txt","r+");
	printf("\t*DELETE CONTACT*");
	if(fp==NULL)
	{
		printf("\n\tNo contacts yet!");
	}
	else
	{
		fp1=fopen("temp.txt","w");
		printf("\n\tName : "); 
		scanf("%s",name1);
		while(fscanf(fp,"%s %s",name,phone)!=EOF) 
		{
				if(strcmp(name1,name)==0)
				{ 
					flag=1;
					continue; 
				}
			fprintf(fp1,"%s %s\n",name,phone); 
		}
		fclose(fp); 
		fclose(fp1); 
		fp=fopen("phone.txt","w");
		fp1=fopen("temp.txt","r"); 
		while(fscanf(fp1,"%s %s",name,phone)!=EOF) 
		{ 
			fprintf(fp,"%s %s\n",name,phone); 
		} 
		fclose(fp);
		fclose(fp1);
		if(flag!=1)
		{
			printf("\n\tContact doesn't exist");
			remove("temp.txt");
		}
		else
		{
			remove("phone.txt");
			rename("temp.txt","phone.txt");
			printf("\n\tContact deleted successfully");
		}
	}
	sleep(2);
	system("cls");
	main();
}
void search()
{
	system("cls");
	FILE *fp;
	char name[50],name1[50],phone[50];
	int flag=0,count=0;
	fp=fopen("phone.txt","r"); 
	printf("\t*SEARCH CONTACT*");
	if(fp==NULL)
	printf("\n\tNo contacts yet!");
	else
	{
		printf("\n\tName : ");  
		scanf("%s",name1); 
		while(fscanf(fp,"%s %s",name,phone)!=EOF) 
		{ 
			if(strcmp(name,name1)==0) 
			{ 
				flag=1;
				printf("\n\tNAME : %s\n",name); 
				printf("\n\tMOB NO. : %s\n",phone);
				count++; 
			}
		}
		fclose(fp);
		if(flag==1)
		printf("\n\t%d contacts found",count);
		else
		printf("\n\tNo matches found");
	}
	sleep(3);
	system("cls");
	main();
}
void edit()
{
	system("cls");
    FILE *fp,*fp1;
    int flag=0;
	char name[50],name1[50],name2[50],phone[50],phone1[50];
	printf("\t*MODIFY CONTACT*");
	fp=fopen("phone.txt","r+");
	if(fp==NULL)
	{
		printf("\n\tNo contacts yet!");
	}
	else
	{
		fp1=fopen("temp1.txt","w");
		printf("\n\tName to modify : ");
        scanf("%s",name1);
        while(fscanf(fp,"%s %s",name,phone)!=EOF)
        {
            if(strcmp(name,name1)==0)
            {
				printf("\n\tName : ");
                scanf("%s",name2);
                printf("\n\tMOB No : ");
                scanf("%s",phone1);
                flag=1;
                fprintf(fp1,"%s %s\n",name2,phone1);
			}
			else
			fprintf(fp1,"\n%s %s\n",name,phone);
        }
        fclose(fp1);
        fclose(fp);
        fp=fopen("phone.txt","w");
		fp1=fopen("temp1.txt","r"); 
		while(fscanf(fp1,"%s %s",name,phone)!=EOF) 
		{ 
			fprintf(fp,"%s %s\n",name,phone); 
		} 
		fclose(fp);
		fclose(fp1);
        if(flag==1)
        {
            printf("\n\tContact modified successfully");
            remove("temp1.txt");
        }
        else
        {
            printf("\n\tContact not found");
            remove("temp1.txt");
        }
	}
	sleep(2);
	system("cls");
	main();
}
void display()
{
	system("cls");
	int count;
	FILE *fp;
	char name[50],phone[50];
	printf("\t**ALL CONTACTS**");
	fp=fopen("phone.txt","r");
	while(fscanf(fp,"%s %s",name,phone)!=EOF) 
	{
		printf("\n\tNAME : %s",name); 
		printf("\n\tMOB NO. : %s",phone);
		count++;
	}
	fclose(fp);
	printf("\n\t%d Contacts are there\n",count);
	printf("\n\n\tPress any key to continue");
	getch();
	system("cls");
	main();
}
