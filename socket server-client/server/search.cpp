#include"iostream"
#include"global.h"
#include"string"
using namespace std;

void search_name();
void search_mobile();
void search_address();
void search()
{
	char search_way[10];
	cout<<"by(name|mobile|address):";
	cin>>search_way;
	if(strcmp(search_way,"name")==0)
		search_name();
	else if(strcmp(search_way,"mobile")==0)
		search_mobile();
	else if(strcmp(search_way,"address")==0)
		search_address();
	else
		cout<<"error!"<<endl;
}

void search_name()
{
	string name;
	char ss[20];
	int j=0;
	cout<<"name:";
	getchar();
    gets_s(ss);
	name=ss;
	for(int i=0;i<num_obj;i++)
	{
		if(i==0)
			flag2=head->next;

	
		if(i==0 && head->entry.putname()==name)//search头指针
		{
			j++;
			cout<<"entry"<<j<<":"<<endl;
			cout<<"name:"<<head->entry.putname()<<endl;
			cout<<"mobile:"<<head->entry.putmobile()<<endl;
			cout<<"address:"<<head->entry.puthome_adr()<<endl;
			cout<<endl;
		}

		else if(i>0 && flag2->entry.putname()==name)//search其他指针
		{
			j++;
			cout<<"entry"<<j<<":"<<endl;
			cout<<"name:"<<flag2->entry.putname()<<endl;
			cout<<"mobile:"<<flag2->entry.putmobile()<<endl;
			cout<<"address:"<<flag2->entry.puthome_adr()<<endl;
			cout<<endl;
		}
		if(i>0)
			flag2=flag2->next;
	
	}
	if(j==0)
			cout<<"Nobody!"<<endl;

}

void search_mobile()
{
	string mobile;
	char ss1[20];
	cout<<"mobile:";
	getchar();
	gets_s(ss1);
    mobile=ss1;
	for(int i=0,j=0;i<num_obj;i++)
	{
		if(i==0)
			flag2=head->next;

		if(i==0 && head->entry.putmobile()==mobile)
		{
			j++;
			cout<<"entry"<<j<<":"<<endl;
			cout<<"name:"<<head->entry.putname()<<endl;
			cout<<"mobile:"<<head->entry.putmobile()<<endl;
			cout<<"address:"<<head->entry.puthome_adr()<<endl;
			cout<<endl;
		}

		else if(i>0 && flag2->entry.putmobile()==mobile)
		{
			j++;
			cout<<"entry"<<j<<":"<<endl;
			cout<<"name:"<<flag2->entry.putname()<<endl;
			cout<<"mobile:"<<flag2->entry.putmobile()<<endl;
			cout<<"address:"<<flag2->entry.puthome_adr()<<endl;
			cout<<endl;
		}
		if(i>0)
			flag2=flag2->next;
		if(j==0)
			cout<<"none"<<endl;
	
	}
}

void search_address()
{
	string address;
	char ss2[20];
	cout<<"address:";
	getchar();
	gets_s(ss2);
	address=ss2;
	for(int i=0,j=0;i<num_obj;i++)
	{
		if(i==0)
			flag2=head->next;

		if(i==0 && head->entry.puthome_adr()==address)
		{
			j++;
			cout<<"entry"<<j<<":"<<endl;
			cout<<"name:"<<head->entry.putname()<<endl;
			cout<<"mobile:"<<head->entry.putmobile()<<endl;
			cout<<"address:"<<head->entry.puthome_adr()<<endl;
			cout<<endl;
		}

		else if(i>0 && flag2->entry.puthome_adr()==address)
		{
			j++;
			cout<<"entry"<<j<<":"<<endl;
			cout<<"name:"<<flag2->entry.putname()<<endl;
			cout<<"mobile:"<<flag2->entry.putmobile()<<endl;
			cout<<"address:"<<flag2->entry.puthome_adr()<<endl;
			cout<<endl;
		}
		if(i>0)
			flag2=flag2->next;
		if(j==0)
			cout<<"none"<<endl;
	
	}
	

}