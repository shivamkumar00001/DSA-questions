#include <bits/stdc++.h>
using namespace std;

void maxMatrixSum(vector<vector<int> >& matrix)
{
    int n = matrix.size(); 
    int m = matrix[0].size();
    int maxsum = INT_MIN;
    int top = 0, bottom = 0, left = 0, right = 0;
   
    for (int i = 0; i < n; i++) {
      
        for (int j = 0; j < m; j++) {
         
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < m; l++) {
                   
                    int curr = 0;
                    for (int x = i; x <= k; x++) {
                       
                        for (int y = j; y <= l; y++) {
                          
                            curr += matrix[x][y];
                        }
                    }
                  
                    if (curr > maxsum) {
                        maxsum = curr;
                        top = i;
                        left = j;
                        right = k;
                        bottom = l;
                    }
                }
            }
        }
    }
    cout << "( Top , Left )"
         << "( " << top << " , " << left << " )" << endl;
    cout << "( Bottom , Right )"
         << "( " << bottom << " , " << right << " )"
         << endl;
    cout << "The sum of this rectangle is: " << maxsum
         << endl;
}
int main()
{
    vector<vector<int> > v = { { 1, 2, -1, -4, -20 },
                               { -8, -3, 4, 2, 1 },
                               { 3, 8, 10, 1, 3 },
                               { -4, -1, 1, 7, -6 } };
    maxMatrixSum(v);
    return 0;
}
