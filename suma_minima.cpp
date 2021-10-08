#include <iostream>
#include <vector>

using namespace std;

int sumaMinima(vector<vector<int>> &matrix)
{
  vector<vector<int>> minSumaa;
  minSumaa = matrix;
  int minimo = 0;

  for (int i = 1; i < matrix.size(); i++)
  {
    for (int j = 0; j < matrix[0].size(); j++)
    {
      minimo = minSumaa[i - 1][j];
      
      if (j > 0)
        minimo = min(minimo, minSumaa[i - 1][j - 1]);
      
      if (j < matrix[0].size() - 1)
        minimo = min(minimo, minSumaa[i - 1][j + 1]);
      
      minSumaa[i][j] = matrix[i][j] + minimo;
    }
  }

  minimo = minSumaa.back()[0];
  for (int i = 1; i < minSumaa[0].size(); i++)
  {
    if(minSumaa.back()[i] < minimo)
      minimo = minSumaa.back()[i];
  }
  return minimo;
}

int main()
{
  vector<vector<int>> matrix;
  matrix.push_back({2, 1, 3});
  matrix.push_back({6, 5, 4});
  matrix.push_back({7, 8, 9});
  cout << sumaMinima(matrix) << endl;
  return 0;
}