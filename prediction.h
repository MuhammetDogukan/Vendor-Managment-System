#ifndef PREDICTION_H
#define PREDICTION_H

class prediction
{
	public:
		prediction();
		~prediction();
		void showWinterHoldPredictionWithTxt();
		float getAverage(int arr[], int size);
		int yearSold[12];
		float yearSeasonal[12];
		float yearTrend[12];
		float yearLevel[12];
		int yearForecast[12];
		int yearError[12];
};

#endif
