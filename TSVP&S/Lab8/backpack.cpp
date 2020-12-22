#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int a[2000][2000];
 
int main() {
    int N, W;
    cout << "Enter Num of things and Capacity:";
    cin >> N >> W
 
    vector<int> cost(N + 1);
    vector<int> weight(N + 1);
 
    cout << "m" << "  " << "c" << endl;
    for (int i = 0; i < N; i++)
    {
    	cout << i+1 << ") ";
    	cin  >> weight[i + 1] >> cost[i + 1];
    }
 
    for (int j = 0; j <= W; j++)
        a[0][j] = 0;
 
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= W; j++)
            if (j - weight[i] < 0)
                a[i][j] = a[i - 1][j];
            else
                a[i][j] = max(a[i - 1][j], a[i][j - weight[i]] + cost[i]);
 
    vector<int> answer;
    int i = N, j = W;
    while (i && j)
    {
        if (j - weight[i] < 0 || a[i][j - weight[i]] + cost[i] < a[i][j])
            i = i - 1;
        else
        {
            answer.push_back(i);
            j = j - weight[i];
        }
    }
 
    cout << endl << "Best backpack's price: " << a[N][W] << endl << "The backpack contains: ";
 
	int sum_w = 0;
   //int repeat[W] = {0};
   int * repeat = new int [W];
   //repeat
   for (int i = 0; i < W; i++)
   {
       repeat[i] = 0;
   }
   for (int i = 0; i < answer.size(); i++)
		repeat[answer[i]] +=1;
	   for (int i = 0; i <= N; i++)
		if (repeat[i] > 0)
		{
			cout << i << " ("  << weight[i] << "; "<< cost[i] << ") " << " - "<< repeat[i] << " pcs    ";// << repeat[i] * cost[i]<< endl;
			//sum_w += weight[i] * repeat[i];
		}
			
	//cout << "The backpack's weight: " << sum_w;	
	
    /*for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';*/
}
