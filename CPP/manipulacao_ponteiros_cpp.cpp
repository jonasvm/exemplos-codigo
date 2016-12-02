#include
using namespace std;
int main ()
{
     float valorProdutos;
     float *vendEmpresa;
     int y; //y é o número de vendedores da empresa
     int x; //x aqui é o número de produtos vendidos por cada vendedor

	 cout << "Entre com o número de vendedores de sua empresa." << endl;
	 cin >> y;

	 vendEmpresa = new float[y];

	 for (int i=0;i<y;i++)
     {
	      cout << "Entre com o número de produtos vendidos pelo vendedor " << i << endl;
          cin >> x;
          float totalProdutos=0;
          for (int j=0;j<x;j++)
          {
               cout << "Entre com o valor do produto" << j << endl;
               cin >> valorProdutos;
               totalProdutos = totalProdutos+valorProdutos;
          }
          vendEmpresa[i]=totalProdutos*0.1;
     }
     
	 for (int i=0;i<y;i++)
     {
          cout << "Total da comissão do vendedor" << i << endl;
          cout << vendEmpresa[i] <<endl;
     }

	 system("Pause");
     
	 delete [] vendEmpresa;

	 return 0;
}