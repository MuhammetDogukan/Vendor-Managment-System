#include "Producers.h"
#include <iostream>
#include<string>
#include <sstream> 
#include <iomanip>

#include<mysql.h>
#include <mysqld_error.h>

Producers::Producers()
{
	
}

Producers::~Producers()
{
	
}
void Producers::showProducers()
{
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	MYSQL_ROW row;
	MYSQL_RES* res;
	
	int state = mysql_query(connect,"SELECT * FROM producers");
	cout<<"----------------------------------------------------"<<endl;
	cout<< " |  PRODUCT ID  |  PRODUCER NAME  |  PRODUCER TELL"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	
	if (!state)
	{
		res = mysql_store_result(connect);
		while((row = mysql_fetch_row(res)))
		{
			cout <<" |"<<setw(7) <<row [0]<<setw(9)<<"  |  "<<row[1]<<setw(14)<<" | "<<row [2]<<endl;
			
		}
		cout<<"-------------------------------------------------"<<endl;
	}
}
void Producers::addProducers(int productId)
{
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	
	cout<<endl<<"Please enter the producer name: ";
	cin>>producerName;
	cout<<endl<<"Please enter the producer tell: ";
	cin>>producerTell;
	
	
	stringstream ss;
	ss<<"INSERT INTO producers(productId, producerName, producerTell) VALUES ('"<<productId<<"','"<<producerName<<"','"<<producerTell<<"')";
	string query = ss.str();
	const char* q = query.c_str();
	mysql_query(connect,q);
	
	
}
