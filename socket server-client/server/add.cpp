#include "iostream"
#include"Global.h"
#include"string"
using namespace std;

void add()
{
	addr *p;
	p=new addr;
	cout<<"name:";
	getchar();
	p->entry.getname();
	cout<<"mobile:";
	p->entry.getmobile();
	cout<<"address:";
	p->entry.gethome_adr();
	cout<<"address entry added"<<endl;
	num_obj++;

	//将add的entry加入链表
	if(num_obj==1)
	{
		head=p;
		head->next=NULL;
		flag=head;
	}
	if(num_obj>1)
	{
		flag->next=p;
		p->next=NULL;
		flag=p;
		
	}
	
}