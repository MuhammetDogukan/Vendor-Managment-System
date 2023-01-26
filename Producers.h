#ifndef PRODUCERS_H
#define PRODUCERS_H
#include <string>

using namespace std;


class Producers
{
	public:
		Producers();
		~Producers();
		void showProducers();
		void addProducers(int productId);
	private:
		int productId;
		string producerName;
		string producerTell;
		
		
		
};

#endif
