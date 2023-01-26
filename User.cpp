#include <iostream>
#include "User.h"
#include <string>
#include <sstream> 
#include <iomanip>

#include<mysql.h>
#include <mysqld_error.h>

using namespace std;

User::User()
{
	setUserName("");
	setPassword("");
}
User::~User()
{
	
}
void User::setUserName(string _userName)
{
	userName =_userName;
}
void User::setPassword(string _password)
{
	password=_password;
}
string User::getUserName()
{
	return userName;
}
string User::getPassword()
{
	return password;
}
int User::userSquery()
{
	MYSQL* connect;
	MYSQL_ROW row;
	MYSQL_RES* res;
	
		
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	if(connect)
	{
		int qstate = mysql_query(connect,"select * from users ");
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
void User::addUser()
{
	system("Cls");
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	
	
	cout<<endl<<"Please enter the new user ID: ";
	cin>>id;
	cout<<endl<<"Please enter the new user name: ";
	cin>>userName;
	cout<<endl<<"Please enter the new password: ";
	cin>>password;
	
	
	
	stringstream ss;
	ss<<"INSERT INTO users(userId, userName, password) VALUES ('"<<id<<"','"<<userName<<"','"<<password<<"')";
	string query = ss.str();
	const char* q = query.c_str();
	mysql_query(connect,q);
	
	
	
	
}
