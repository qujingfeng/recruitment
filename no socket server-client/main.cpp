#include"iostream"
#include"string"

using namespace std;
void add();
void search();
void delete_();
void help();
void help_();//输入错误命令下的提示
void write_file();
void read_file();

int main()
{
	read_file();
	char input[10];

	for(int i=0;i<100;i++)
	{
		cin>>input;
		if(strcmp(input,"add")==0)
			add();	
		else if(strcmp(input,"search")==0)
			search(); 
		else if(strcmp(input,"delete")==0)
			delete_();
		else if(strcmp(input,"!quit")==0)
		{
			write_file();
			break;
		}
		
		else if(strcmp(input,"!help")==0)
			help();
		else
			help_();
	}
	
	return 0;
}