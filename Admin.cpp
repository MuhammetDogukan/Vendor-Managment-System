#include <iostream>
#include "Admin.h"

#include<mysql.h>
#include <mysqld_error.h>

using namespace std;

string Admin::enteredUserName="";
string Admin::enteredPassword="";

Admin::Admin()
{
	setAdminPassword("");
	setAdminUserName("");
	setEnteredPassword("");
	setEnteredUserName("");
}
Admin::~Admin()
{
	
}
void Admin::setAdminUserName(string _adminUserName)
{
	adminUserName=_adminUserName;
}
void Admin::setAdminPassword(string _adminPassword)
{
	adminPassword=_adminPassword;
}
void Admin::setEnteredUserName(string _enteredUserName)
{
	enteredUserName=_enteredUserName;
}
void Admin::setEnteredPassword(string _enteredPassword)
{
	enteredPassword=_enteredPassword;
}
string Admin::getAdminUserName()
{
	return adminUserName;
}
string Admin::getAdminPassword()
{
	return adminPassword;
}
string Admin::getEnteredUserName()
{
	return enteredUserName;
}
string Admin::getEnteredPassword()
{
	return enteredPassword;
}
void Admin::loginScreen()
{
	system("Cls");
	cout<<"\tPlease enter your user name: ";
	cin>>enteredUserName;
	cout<<endl<<"\tPlease enter your password: ";
	cin>>enteredPassword;
	
	
}
int Admin::adminSquery()
{
	MYSQL* connect;
	MYSQL_ROW row;
	MYSQL_RES* res;
	
		
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	if(connect)
	{
		int qstate = mysql_query(connect,"select * from admin ");
		if(!qstate)
		{
			res = mysql_store_result(connect);
			while(row = mysql_fetch_row(res))
			{
				if(row[1]==enteredUserName)
				{
					if(row[2]==enteredPassword)
					{
			
						return 1;
						
					}
					else
					{
						cout<<endl<<"\t\t!Wrong Password!"<<endl<<endl<<"\t";
						system("pause");
						return 0;
					}
			
				}
				else 
				{
					cout<<endl<<"\t\t!Wrong User Name!"<<endl<<endl<<"\t";
					system("pause");
						return 0;
				}
				
			}
			
			
		}
	}
}














