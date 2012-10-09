#include "iostream"
#include"Global.h"
#include"string"
using namespace std;

void write_file()
{
	struct add_file file[100];
	FILE *fp;
	char ch,filename[10];
	cout<<"Please input file name for writing in:"<<endl;
	cin>>filename;
	if((fp=fopen(filename,"wb"))==NULL)
	{
		cout<<"can not open file"<<endl;
		exit(0);
	}
	ch=getchar();
	
	//将内存中的entry全部以add_file的格式写入文件
	flag5=head;
	for(int i=0;i<num_obj;i++)
	{
		file[i].name=flag5->entry.putname();
		file[i].mobile=flag5->entry.putmobile();
		file[i].address=flag5->entry.puthome_adr();
		flag5=flag5->next;
	}
	
	for(int j=0;j<num_obj;j++)
		if(fwrite(&file[j],sizeof(struct add_file),1,fp)!=1)
			cout<<"file write error"<<endl;
	fclose(fp);

}