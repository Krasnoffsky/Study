#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

const int INF = 1e9;

using namespace std;

struct edge
{
    int weight, a, b;
};

int main(){
	
	ifstream inf("C:\\Study\\Course 3 Sem 1\\TSVP&S\\Lab7\\file.txt");

    int n, m;
    inf >> n >> m;

    vector <edge> g(m);

    for (int i = 0; i < m; i++)
    {
        int a, b, weight;
//        cout << i+1 << ") ";
        inf >> a >> b >> weight;
        edge e;
        e.weight = weight;
        e.a = a - 1;
        e.b = b - 1;
        g[i] = e;
    }

//    cout << "Input start vertex:" << endl;
    long long start;
    inf >> start;
    
/*    cout << "Input end vertex:" << endl;
    long long end;
    cin >> end;
*/
    vector <int> d(n, INF);
    d[start-1] = 0;

                
    for (int i = 0; i < n - 1; i++)
    {
    	cout << "Step " << i + 1 << endl;
    	for (int j = 0; j < m; j++)
    	{
    		cout << "D[" << g[j].b << "] =  D[" << g[j].a << "] + " << g[j].weight << " = ";
			
 	    	if ((d[g[j].a] != INF) && (d[g[j].b] > d[g[j].a] + g[j].weight))
            {
            	cout << d[g[j].a] + g[j].weight << endl;
	            d[g[j].b] = d[g[j].a] + g[j].weight;
            }
            else if (d[g[j].a] == INF)
            	cout << "INF" << endl;
            else
            	cout << d[g[j].a] + g[j].weight << endl;
    	}  
    }   

    for (int i = 0; i < n; i++)
    {
//    	if (i == end - 1){
        	if (d[i] != INF)
            	cout << "Min path between " << start << " and " << i+1 << " = " << d[i] << endl;
        	else
            	cout << "No path between " << start << " and " << i+1 << endl;
 //       }
    }
    cout << endl;
    inf.close();

    return 0;
}


/*
6 8
1 2 1
2 3 4
1 3 6
1 4 2
2 5 2
3 6 3
4 5 5
5 6 4
*/

/*
7 13
1 2 3
1 3 4
1 4 3
2 3 1
3 4 2
3 5 1
4 5 2
3 7 1
2 7 2
5 7 3
7 6 6
5 6 1
4 6 4
*/


