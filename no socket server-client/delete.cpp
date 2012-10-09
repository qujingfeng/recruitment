#include"iostream"
#include"Global.h"
#include"string"
using namespace std;


void delete_name1(int,char []);
void delete_name2(int,char []);

void delete_name()
{
	char name[20];
	int Len;
	cout<<"name:";
	getchar();
	gets_s(name);
	Len=strlen(name);
	if(name[Len-2]=='.' && name[Len-1]=='*')
		delete_name1(Len,name);
	else
		delete_name2(Len,name);
}

//������Ϊ�ؼ��ֵ�ɾ����ʽ1:xx.*
void delete_name1(int Len,char name[20])
{
	string name1,name2;	
	name1=name;
	int j=0;
	const char *p1=name1.c_str();
	for(int i=0;i<num_obj;i++)
	{	
		if(i==0)//���head�Ƿ���ɾ������
		{
			string ss=head->entry.putname();
			const char *p2=ss.c_str();
			flag3=head->next;
			int dele=0;
			for(int k=0;k<Len-2;k++)
			{
				if(*(p1+k)==*(p2+k))
				{
					dele++;
				}
				else
					break;//������һ���в���ͬ���ַ�������ѭ��
			}	
			if(dele==Len-2)//ֻ�е�.*ǰ����ַ�ȫ����Ӧ��ͬʱ������Ϊ��ɾ������
			{	
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<head->entry.putname()<<endl;
				cout<<"mobile:"<<head->entry.putmobile()<<endl;
				cout<<"address:"<<head->entry.puthome_adr()<<endl;
				head=flag3;
			}	
			flag4=head;				
			dele=0;	
		}					
		if(i>0)//�������ָ���Ƿ���ɾ������
		{
			string ss1;
			ss1=flag3->entry.putname();
			const char *p3=ss1.c_str();
			int dele=0;
			for(int k1=0;k1<Len-2;k1++)
			{
				if(*(p1+k1)==*(p3+k1))
				{
					dele++;
				}
				else
					break;
			}
			if(dele==Len-2)
			{
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<flag3->entry.putname()<<endl;
				cout<<"mobile:"<<flag3->entry.putmobile()<<endl;
				cout<<"address:"<<flag3->entry.puthome_adr()<<endl;
				if(flag3==head)
				{
					head=flag3->next;
					flag4=head;
				}
				else
				{
					if(flag3==flag)
					{
						flag=flag4;
					}
					else
						flag4->next=flag3->next;
				}
			}	
			else
			{
				flag4=flag3;
				flag4->next=flag3->next;
			}
			flag3=flag3->next;
		}			
	}	
	if(j==0)
		cout<<"Nobody!"<<endl;
	num_obj=num_obj-j;	
}

//������Ϊ�ؼ��ֵ�ɾ����ʽ2:xxxx(ȫ��)
void delete_name2(int Len,char name[20])
{
	string name1,name2;	
	name1=name;
	int j=0;
	const char *p1=name1.c_str();
	for(int i=0;i<num_obj;i++)
	{	
		if(i==0)
		{
			string ss=head->entry.putname();
			const char *p2=ss.c_str();
			flag3=head->next;
			int dele=0;
			for(int k=0;k<Len;k++)
			{
				if(*(p1+k)==*(p2+k))
				{
					dele++;
				}
				else
					break;
			}	
			if(dele==Len)
			{	
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<head->entry.putname()<<endl;
				cout<<"mobile:"<<head->entry.putmobile()<<endl;
				cout<<"address:"<<head->entry.puthome_adr()<<endl;
				head=flag3;
			}	
			flag4=head;				
			dele=0;	
		}					
		if(i>0)
		{
			string ss1;
			ss1=flag3->entry.putname();
			const char *p3=ss1.c_str();
			int dele=0;
			for(int k1=0;k1<Len;k1++)
			{
				if(*(p1+k1)==*(p3+k1))
				{
					dele++;
				}
				else
					break;
			}
			if(dele==Len)
			{
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<flag3->entry.putname()<<endl;
				cout<<"mobile:"<<flag3->entry.putmobile()<<endl;
				cout<<"address:"<<flag3->entry.puthome_adr()<<endl;
				if(flag3==head)
				{
					head=flag3->next;
					flag4=head;
				}
				else
				{
					if(flag3==flag)
					{
						flag=flag4;
					}
					else
						flag4->next=flag3->next;
				}
			}	
			else
			{
				flag4=flag3;
				flag4->next=flag3->next;
			}
			flag3=flag3->next;
		}			
	}	
	if(j==0)
		cout<<"Nobody!"<<endl;
	num_obj=num_obj-j;	
}

//��address��mobileΪɾ���ؼ��ֵ�˼·ͬname
void delete_address()
{
	char address[20];
	cout<<"address:";
	getchar();
	gets_s(address);
	string address1,address2;	
	address1=address;
	int Len;
	Len=strlen(address);
	int j=0;
	const char *p1=address1.c_str();
	for(int i=0;i<num_obj;i++)
	{	
		if(i==0)
		{
			string ss=head->entry.puthome_adr();
			const char *p2=ss.c_str();
			flag3=head->next;
			int dele=0;
			for(int k=0;k<Len;k++)
			{
				if(*(p1+k)==*(p2+k))
				{
					dele++;
				}
				else
					break;
			}	
			if(dele==Len)
			{	
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<head->entry.putname()<<endl;
				cout<<"mobile:"<<head->entry.putmobile()<<endl;
				cout<<"address:"<<head->entry.puthome_adr()<<endl;
				head=flag3;
			}	
			flag4=head;				
			dele=0;	
		}					
		if(i>0)
		{
			string ss1;
			ss1=flag3->entry.puthome_adr();
			const char *p3=ss1.c_str();
			int dele=0;
			for(int k1=0;k1<Len;k1++)
			{
				if(*(p1+k1)==*(p3+k1))
				{
					dele++;
				}
				else break;
			}
			if(dele==Len)
			{
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<flag3->entry.putname()<<endl;
				cout<<"mobile:"<<flag3->entry.putmobile()<<endl;
				cout<<"address:"<<flag3->entry.puthome_adr()<<endl;
				if(flag3==head)
				{
					head=flag3->next;
					flag4=head;
				}
				else
				{
					if(flag3==flag)
					{
						flag=flag4;
					}
					else
						flag4->next=flag3->next;
				}
			}	
			else
			{
				flag4=flag3;
				flag4->next=flag3->next;
			}
			flag3=flag3->next;
		}			
	}	
	num_obj=num_obj-j;	
}

void delete_mobile()
{
	char mobile[20];
	cout<<"mobile:";
	getchar();
	gets_s(mobile);
	string mobile1,mobile2;	
	mobile1=mobile;
	int Len;
	Len=strlen(mobile);
	int j=0;
	const char *p1=mobile1.c_str();
	for(int i=0;i<num_obj;i++)
	{	
		if(i==0)
		{
			string ss=head->entry.putmobile();
			const char *p2=ss.c_str();
			flag3=head->next;
			int dele=0;
			for(int k=0;k<Len;k++)
			{
				if(*(p1+k)==*(p2+k))
				{
					dele++;
				}
				else
					break;
			}	
			if(dele==Len)
			{	
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<head->entry.putname()<<endl;
				cout<<"mobile:"<<head->entry.putmobile()<<endl;
				cout<<"address:"<<head->entry.puthome_adr()<<endl;
				head=flag3;
			}	
			flag4=head;				
			dele=0;	
		}					
		if(i>0)
		{
			string ss1;
			ss1=flag3->entry.putmobile();
			const char *p3=ss1.c_str();
			int dele=0;
			for(int k1=0;k1<Len;k1++)
			{
				if(*(p1+k1)==*(p3+k1))
				{
					dele++;
				}
				else
					break;
			}
			if(dele==Len)
			{
				j++;
				cout<<"deleted entry:"<<j<<endl;
				cout<<"name:"<<flag3->entry.putname()<<endl;
				cout<<"mobile:"<<flag3->entry.putmobile()<<endl;
				cout<<"address:"<<flag3->entry.puthome_adr()<<endl;
				if(flag3==head)
				{
					head=flag3->next;
					flag4=head;
				}
				else
				{
					if(flag3==flag)
					{
						flag=flag4;
					}
					else
						flag4->next=flag3->next;
				}
			}	
			else
			{
				flag4=flag3;
				flag4->next=flag3->next;
			}
			flag3=flag3->next;
		}			
	}	
	num_obj=num_obj-j;	
}


void delete_()
{
	char search_way[10];
	cout<<"by(name|mobile|address):";
	cin>>search_way;
	if(strcmp(search_way,"name")==0)
		delete_name();
	else if(strcmp(search_way,"mobile")==0)
		delete_mobile();
	else if(strcmp(search_way,"address")==0)
		delete_address();
	else
		cout<<"Plese input correct command!"<<endl;
}