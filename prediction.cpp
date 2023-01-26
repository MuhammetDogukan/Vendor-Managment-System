#include "prediction.h"
#include "prediction.h"
#include <iostream>
#include<string>
#include <fstream>

using namespace std;

prediction::prediction()
{
}

prediction::~prediction()
{
}
float prediction::getAverage(int arr[], int size) {
	int total = 0;
	for(int i = 0; i < size; i++) {
		total += arr[i];
	}
	total /= size;
	return total;
}

void prediction::showWinterHoldPredictionWithTxt() {
	
	int nextYearPrediction[12];
	
	ifstream fin;	
	double alpha = 0.1;
	double beta = 0.1;
	double gamma = 0.1;
	fin.open("fourYearsData.txt");
	
	prediction fourYearsData[4];
	prediction predictionYear;
	
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 12; j++) {
			fin >> fourYearsData[i].yearSold[j];
		}
	}
	
	fin.close();
	
	//Algorithm Part
	for(int i = 0; i < 12; i++)
	{
		fourYearsData[0].yearSeasonal[i] = fourYearsData[0].yearSold[i]/getAverage(fourYearsData[0].yearSold, 12);
	}
	
	fourYearsData[1].yearLevel[0] = fourYearsData[1].yearSold[0]/fourYearsData[0].yearSeasonal[0];
	fourYearsData[1].yearTrend[0] = (fourYearsData[1].yearSold[0]/fourYearsData[0].yearSeasonal[0]) - (fourYearsData[0].yearSold[11]/fourYearsData[0].yearSeasonal[11]);
	fourYearsData[1].yearSeasonal[0] = gamma*fourYearsData[1].yearSold[0]/fourYearsData[1].yearLevel[0]+(1-gamma)*fourYearsData[0].yearSeasonal[0];

	
	int j = 0;
	float prevTrend = 0;
	float prevLevel = 0;
	for(int i = 1; i < 4; i++)
	{
		if(i == 1) {
			j = 1;
		}
		else {
			j = 0;
		}
		for(;j < 12; j++) {
			if(j == 0) {
				prevLevel = fourYearsData[i-1].yearLevel[11];
				prevTrend = fourYearsData[i-1].yearTrend[11];				
			}
			else {
				prevLevel = fourYearsData[i].yearLevel[j-1];
				prevTrend = fourYearsData[i].yearTrend[j-1];
			}
			fourYearsData[i].yearLevel[j] = alpha*fourYearsData[i].yearSold[j]/fourYearsData[i-1].yearSeasonal[j] + (1 - alpha) * (prevLevel + prevTrend);
			fourYearsData[i].yearTrend[j] = beta*(fourYearsData[i].yearLevel[j]-prevLevel)+(1-beta)*prevTrend;
			fourYearsData[i].yearSeasonal[j] = gamma*fourYearsData[i].yearSold[j]/fourYearsData[i].yearLevel[j]+(1-gamma)*fourYearsData[i-1].yearSeasonal[j];
			fourYearsData[i].yearForecast[j] = (prevLevel + prevTrend)*fourYearsData[i-1].yearSeasonal[j];
			fourYearsData[i].yearError[j] = fourYearsData[i].yearSold[j] - fourYearsData[i].yearForecast[j];
		}
	}
	
//Displaying Part
//	for(int j = 1; j < 4; j++) {
//		cout << "\n----------------------------------------------" << endl;
//		cout << "YEAR " << j+1 << endl;
//		for(int i = 0; i < 12; i++) {
//			cout << "\n----------------------------------------------" << endl;
//			cout << "\tYear seasonal " << i << ":" << fourYearsData[j].yearSeasonal[i] << endl;
//			cout << "\tYear trend " << i << ":" << fourYearsData[j].yearTrend[i] << endl;
//			cout << "\tYear level " << i << ":" << fourYearsData[j].yearLevel[i] << endl;
//			cout << "\tYear forecasting " << i << ":" << fourYearsData[j].yearForecast[i] << endl;
//			cout << "\tYear error " << i << ":" << fourYearsData[j].yearError[i] << endl;
//			cout << "\n----------------------------------------------" << endl;		
//		}
//		cout << "\n----------------------------------------------" << endl;
//	}
	
//Prediction
	cout << endl << "PREDICTION" << endl;
	string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
	for(int i = 0; i < 12; i++) {
		
		nextYearPrediction[i] = (fourYearsData[3].yearLevel[11] + i * fourYearsData[3].yearTrend[11])*fourYearsData[3].yearSeasonal[i];
		cout << months[i] << " - " << nextYearPrediction[i] << endl; 
	}

}
