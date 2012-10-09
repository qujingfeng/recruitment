#include "iostream"
#include"Global.h"
#include"string"
using namespace std;

void read_file()
{
	FILE *fp;
	struct add_file file[100];	
	char filename[10];
	cout<<"Reload file name:"<<endl;
	cin>>filename;
	if((fp=fopen(filename,"rb"))==NULL)
	{
		cout<<"No such file!"<<endl;
	}
	else
	{   
		//将文件里的entry读入
		for(int j=0;j<100;j++)	  	
		{
			if(fread(&file[j],sizeof(struct add_file),1,fp)!=1)
			{
				cout<<"read file: entry number is "<<j<<endl;
			    num_obj=j;
			    break;
		    }
		}
		fclose(fp);
	
	    //将读入的entry建立成有head指针的链表
		if(num_obj>0)
		{
			for(int k=0;k<num_obj;k++)
			{			
				addr *p;
				p=new addr;
				p->entry.getname_(file[k].name);
				p->entry.getmobile_(file[k].mobile);
				p->entry.gethome_(file[k].address);
					
				if(k==0)
				{
					head=p;
					head->next=NULL;
					flag=head;
				}
				if(k>0)
				{
					flag->next=p;
		            p->next=NULL;
		            flag=p;
				}
			}
		}
	}
}
