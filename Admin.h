#ifndef ADMÝN_H
#define ADMÝN_H

#include <string>
using namespace std;

class Admin
{
	public:
		Admin();
		~Admin();
		void setAdminPassword(string _adminPassword);
		void setAdminUserName(string _adminUserName);
		void setEnteredPassword(string _enteredPassword);
		void setEnteredUserName(string _enteredUserName);
		string getAdminPassword();
		string getAdminUserName();
		string getEnteredUserName();
		string getEnteredPassword();
		void loginScreen();
		int adminSquery();
		
	protected:
		static string enteredUserName;
		static string enteredPassword;
	
	
	
	private:
		string adminUserName;
		string adminPassword;
			
};

#endif

