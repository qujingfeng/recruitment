#ifndef GLOBAL_H
#define GLOBAL_H
#include"string"
#include"iostream"


using namespace std;

class address
{
public:
	address()
	{
	}
	address(string name1,string mobile_num1,string home_adr1)
	{
		name=name1;
		mobile_num=mobile_num1;
		home_adr=home_adr1;
	}
	void getname()
	{
		char ss[20];
		gets_s(ss);
		name=ss;

	}
	void getmobile()
	{
		char ss1[20];
		gets_s(ss1);
		mobile_num=ss1;
		
	}
    void gethome_adr()
	{
		char ss2[20];
		gets_s(ss2);
		home_adr=ss2;
	}
	void getname_(string na)
	{
		name=na;
	}
	void getmobile_(string mo)
	{
		mobile_num=mo;
	}
	void gethome_(string ho)
	{
		home_adr=ho;
	}

	string putname()
	{
		return name;
	}
	string putmobile()
	{
		return mobile_num;
	}
	string puthome_adr()
	{
		return home_adr;
	}
	
	friend address add(address a);
	friend void search();

private:
	string name;
	string mobile_num;
	string home_adr;
};

struct addr
{
	address entry;
	struct addr * next;
};

struct add_file
{
	string name;
	string mobile;//考虑移动电话11位数字，不能用long int
	string address;
};
extern struct addr *head;
extern struct addr *flag;
extern struct addr *flag2;
extern struct addr *flag3;
extern struct addr *flag4;
extern struct addr *flag5;
extern struct addr *flag6;


extern int num_obj;


#endif