#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <string>
using namespace std;

class Warehouse
{
	public:
		Warehouse();
		~Warehouse();
		void addProduct();
		void changeProduct();
		void deleteProduct();
		void showProduct();
	private:
		int productId;
		string productName;
		float purchase;
		float sale;
		int  numberOfProduct;
		
};

#endif
