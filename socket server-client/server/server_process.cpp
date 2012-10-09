#include"iostream"
#include"string"

using namespace std;
void add();
void search();
void delete_();
void help();
void help_();//输入错误命令下的提示
void write_file();

void read_file(char filename[10]);

void server_process(char input[10],char exportfilename[10])
{
	read_file(exportfilename);
	cout<<"server_process start"<<endl;
	for(int i=0;i<100;i++)
	{
		//cin>>input;
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
	
}

