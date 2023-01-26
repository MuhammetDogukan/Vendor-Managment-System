#include "Sales.h"
#include "Warehouse.h"
#include <iostream>
#include <sstream> 
#include <iomanip>
#include <cstdlib>
#include <string>

#include<mysql.h>
#include <mysqld_error.h>


Sales::Sales()
{
	
}

Sales::~Sales()
{
	
}
void Sales::buySales()
{
	string id;
	int number;
	
	
	
	Sales mySales;
	mySales.showSale();
	
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);

	cout<<"Please enter the product Id you want to buy: "<<endl;
	cin>>id;
	cout<<"Please enter the number of product you want to buy"<<endl;
	cin>>number;
	
	
	stringstream ss;
	ss<<"Update warehouse Set numberOfProduct = numberOfProduct -'"<<number<<"' where productId = '"<<id<<"'";
	string query = ss.str();
	const char* q = query.c_str();
	mysql_query(connect,q);
	
	stringstream aa;
	aa<<"INSERT INTO saleshistory (id, numberOfProduct) VALUES ('"<<id<<"','"<<number<<"')";
	string querya = aa.str();
	const char* a = querya.c_str();
	mysql_query(connect,a);
	
}
void Sales::salesHistory()
{
	system("Cls");
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	MYSQL_ROW row;
	MYSQL_RES* res;
	
	int state = mysql_query(connect,"SELECT * FROM saleshistory");
	cout<<"-----------------------------------------"<<endl;
	cout<< " |  PRODUCT ID  |  PRODUCT NUMBER  "<<endl;
	cout<<"-----------------------------------------"<<endl;
	
	if (!state)
	{
		res = mysql_store_result(connect);
		while((row = mysql_fetch_row(res)))
		{
			cout <<" |"<<setw(7) <<row [0]<<setw(9)<<"  |  "<<row[1]<<endl;
			
		}
		cout<<"---------------------------------------------"<<endl;
	}
}
void Sales::showSale()
{
	system("Cls");
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	MYSQL_ROW row;
	MYSQL_RES* res;
	
	int state = mysql_query(connect,"SELECT productId, productName, numberOfProduct, sale FROM warehouse");
	cout<<"------------------------------------------------------------------------"<<endl;
	cout<< " |  PRODUCT ID  |  PRODUCT NAME  |  NUMBER PRODUCT  |  PRODUCT PRICE"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
	
	if (!state)
	{
		res = mysql_store_result(connect);
		while((row = mysql_fetch_row(res)))
		{
			cout <<" |"<<setw(7) <<row [0]<<setw(9)<<"  |  "<<row[1]<<setw(14)<<" | "<<row [2]<<setw(18)<<" | "<<row [3]<<endl;
			
		}
		cout<<"-----------------------------------------------------------------------------------------"<<endl;
	}
	
	
}
