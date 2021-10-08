#include <iostream>
#include <vector>

using namespace std;

int cambiar(vector<int> &coins, int amount)
{
  vector<int> minMonedas(amount + 1);

  //inicializamos la cantidad de monedas
  for (int i = 1; i < minMonedas.size(); i++)
    minMonedas[i] = amount + 1;

  for (int i = 1; i < minMonedas.size(); i++)
  {
    // se busca el valor minimo 
    for (auto &&v : coins)
    {
      // verificamos que el valor de moneda sea valido
      if (i - v < 0)
        continue;
      minMonedas[i] = min(minMonedas[i - v] + 1, minMonedas[i]);
    }
  }

  return minMonedas.back() != amount + 1 ? minMonedas.back() : -1;
}

int main()
{
  vector<int> monedas = {2};
  int amount = 3;
  cout << cambiar(monedas, amount) << endl;
  return 0;
}