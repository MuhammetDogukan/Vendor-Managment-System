#include<iostream>
#include "Admin.h"
#include "User.h"
#include "Warehouse.h"
#include "Producers.h"
#include "Sales.h"
#include "prediction.h"

#include<mysql.h>
#include <mysqld_error.h>

using namespace std;


int main()
{
	int userType;
	int adminMove;
	int userMove;
	int trueLogin;
	cout<<"\n\n\n\t\t\t ************************************";
	cout<<    "\n\t\t\t **WELCOME VENDOR MANAGEMENT SYSTEM**";
	cout<<    "\n\t\t\t ************************************";
	cout<<"\n\t\t\t\t  Devoleped by \n\t\t\t    Muhammet Dogukan Bedir"<<endl;
	cout<<"\t\t\tOzlem Oztok-David Baimurzayev"<<endl<<endl<<"\n\t";

	
	
	
	system("pause");
	mainMenu:
	system("Cls");
	
	
	cout<<("\n\t1-Admin")<<endl<<("\t2-User")<<endl;
	cout<<endl<<("\tPlease choose your login type: ");
	cin>>userType;
	
	if(userType==1)
	{
		trueLogin=0;
		for(int i=0; i<3 && trueLogin != 1; i++)
		{
			Admin myAdmin;
			myAdmin.loginScreen();
			trueLogin = myAdmin.adminSquery();
		}
		if (trueLogin!=1)
		{
			system("Cls");
			cout<<endl<<"\t\t!You entered 3 wrong username or password!"<<endl<<endl<<"\t";
			system("pause");
			exit(0);
		}
		
		adminMenu:
		system("Cls");
		cout<<("\n\t1-Add product")<<endl;
		cout<<("\n\t2-Change product")<<endl;
		cout<<("\n\t3-Delete product")<<endl;
		cout<<("\n\t4-Show warehouse")<<endl;
		cout<<("\n\t5-Producers information")<<endl;
		cout<<("\n\t6-Prediction")<<endl;
		cout<<("\n\t7-Add New User")<<endl;
		cout<<("\n\t8-Main Menu");
		cout<<endl<<("\n\tPlease select the action you want to do: ");
		cin>>adminMove;
		
		Warehouse myWarehouse;
		if(adminMove == 1)
		{
			myWarehouse.addProduct();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 2)
		{
			myWarehouse.showProduct();
			myWarehouse.changeProduct();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 3)
		{
			myWarehouse.showProduct();
			myWarehouse.deleteProduct();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 4)
		{
			myWarehouse.showProduct();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 5)
		{
			Producers myProducers;
			myProducers.showProducers();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 6)
		{
			system("Cls");
			prediction myPrediction;
			myPrediction.showWinterHoldPredictionWithTxt();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 7)
		{
			User myUser;
			myUser.addUser();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto adminMenu;
		}
		else if(adminMove == 8)
		{
			goto mainMenu;
		}
		else
		{
			cout<<endl<<("\tYou entered invalid number")<<endl<<("\n\t");
			system("pause");
			goto adminMenu;
		}
		
	}
	else if(userType==2)
	{
		
		
		trueLogin=0;
		for(int i=0; i<3 && trueLogin != 1; i++)
		{
			User myUser;
			myUser.loginScreen();
			trueLogin = myUser.userSquery();
		}
		if (trueLogin!=1)
		{
			cout<<endl<<"\t\t!You entered 3 wrong username veya password!"<<endl<<endl<<"\t";
			system("pause");
			exit(0);
		}
		
		userMenu:
		system("Cls");
		cout<<("\n\t1-Buy product")<<endl;
		cout<<("\n\t2-Sales History")<<endl;
		cout<<("\n\t3-Main Menu");
		cout<<endl<<("\n\tPlease select the action you want to do: ");
		cin>>userMove;
		Sales mySales;
		
		if(userMove==1)
		{
			mySales.buySales();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto userMenu;
		}
		else if(userMove==2)
		{
			mySales.salesHistory();
			cout<<endl<<endl<<"\t";
			system("pause");
			goto userMenu;
		}
		else if(userMove==3)
		{
			goto mainMenu;
		}
		else
		{
			cout<<endl<<("\tYou entered invalid number")<<endl<<("\n\t");
			system("pause");
			goto userMenu;
		}
	}
	else 
	{
		cout<<("\tYou entered invalid number")<<endl<<("\n\t");
		system("pause");
		goto mainMenu;
		
	}
	

	
	
	
	
	
	
	
	
	
	
	return 0;
}
