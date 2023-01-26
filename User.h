#ifndef USER_H
#define USER_H

#include <string>
#include "Admin.h"
using namespace std;

class User : public Admin
{
	public:
		User();
		~User();
		void setUserName(string _userName);
		void setPassword(string _passworrd);
		string getUserName();
		string getPassword();
		int userSquery();
		void addUser();
		
	private:
		string userName;
		string password;
		int id;
	
};

#endif
