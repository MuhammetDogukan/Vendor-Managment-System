#include <iostream>
#include "Warehouse.h"
#include "Producers.h"
#include<string>
#include <sstream> 
#include <iomanip>

#include<mysql.h>
#include <mysqld_error.h>

using namespace std;


Warehouse::Warehouse()
{
	
}

Warehouse::~Warehouse()
{
	
}
void Warehouse::addProduct()
{
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	
	
	
	cout<<endl<<"Please enter the product Id: ";
	cin>>productId;
	cout<<endl<<"Please enter the product name: ";
	cin>>productName;
	cout<<endl<<"Please enter the purchase price of the product: ";
	cin>>purchase;
	cout<<endl<<"Please enter the sale price of the product: ";
	cin>>sale;
	cout<<endl<<"Please enter the number of the product: ";
	cin>>numberOfProduct;
	
	stringstream ss;
	ss<<"INSERT INTO warehouse(productId, productName, purchase, sale, numberOfProduct) VALUES ('"<<productId<<"','"<<productName<<"','"<<purchase<<"','"<<sale<<"','"<<numberOfProduct<<"')";
	string query = ss.str();
	const char* q = query.c_str();
	mysql_query(connect,q);
	
	Producers myProducers;
	myProducers.addProducers(productId);
	
	
}
void Warehouse::changeProduct()
{
	
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	
	
	cout<<endl<<"Please enter the product Id you want to change: ";
	cin>>productId;
	
	cout<<endl<<"Please enter the new product name: ";
	cin>>productName;
	cout<<endl<<"Please enter the new purchase price of the product: ";
	cin>>purchase;
	cout<<endl<<"Please enter the new sale price of the product: ";
	cin>>sale;
	cout<<endl<<"Please enter the new number of the product: ";
	cin>>numberOfProduct;
	
	stringstream ss;
	ss<<"Update warehouse Set productId='"<<productId<<"', productName ='"<<productName<<"', purchase = '"<<purchase<<"', sale = '"<<sale<<"', numberOfProduct = '"<<numberOfProduct<<"' where productId = '"<<productId<<"'";
	string query = ss.str();
	const char* q = query.c_str();
	mysql_query(connect,q);
	
	
}
void Warehouse::deleteProduct()
{
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	
	cout<<endl<<"Please enter the product Id you want to delete: ";
	cin>>productId;
	
	stringstream ss;
	ss<<"DELETE FROM warehouse WHERE productId = '"<<productId<<"'";
	string query = ss.str();
	const char* q = query.c_str();
	mysql_query(connect,q);
	
}
void Warehouse::showProduct()
{
	system("Cls");
	MYSQL *connect;
	connect = mysql_init(0);
	connect = mysql_real_connect(connect,"localhost","root","123321","vendordb",3306,NULL,0);
	MYSQL_ROW row;
	MYSQL_RES* res;
	
	int state = mysql_query(connect,"SELECT * FROM warehouse");
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	cout<< " |  PRODUCT ID  |  PRODUCT NAME  |  PRODUCT PURCHASE  |  PRODUCT SALE  |  NUMBER PRODUCT"<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	
	if (!state)
	{
		res = mysql_store_result(connect);
		while(row = mysql_fetch_row(res))
		{
			cout <<" |"<<setw(7) <<row [0]<<setw(9)<<"  |  "<<row[1]<<setw(11)<<" | "<<row [2]<<setw(14)<<" | "<<row [3]<<setw(14)<<" | "<<row [4]<<endl;
			
		}
		cout<<"----------------------------------------------------------------------------------------"<<endl;
	}
	
	
}
