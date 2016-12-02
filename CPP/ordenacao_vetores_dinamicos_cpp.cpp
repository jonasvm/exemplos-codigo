#include
#include
using namespace std;
// shellsort ..........................................
void shellsort(int x[], int tamanho, int nPassos)
{
    int incr,i,j,k,span,y;
    int *incrementos;
    incrementos = new int[nPassos];
    for (i=0;i<=nPassos;i++)
        incrementos[i] = (int)round(exp((nPassos-i)*log(2.0)));
    for (incr=0;incr<=nPassos;incr++)
    {
        //span é o tamanho de incrementos
        span = incrementos[incr];
        for (j=span;j=0 && y< pivo)
             esq++;
        while (vetor[dir] > pivo)
            dir--;
        if (esq <= dir)
        {
            trab = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = trab;
            esq++;
            dir--;
        }
    }while (esq <= dir);     if (dir-i >= 0)
        quickSort(vetor,tamanho,i,dir);
    if (j-esq >= 0)
        quickSort(vetor, tamanho, esq, j);
}
int main(){
    int *vetor;
    int aux,aux2,aux3;
    cout << "Quantos elementos voce deseja armazenar?" << endl;
    cin >> aux;
    vetor = new int[aux];
    for(int i=0;i<< "Entre com um número." << endl;
        cin >> aux2;
        vetor[i] = aux2;
        }
    cout << "Entre com 1 para ordenar usando o quickSort ou 2 para ordenar usando o shellsort."    << endl;
    cin >> aux3;
        if(aux3==1)
            quickSort(vetor,aux,0,aux-1);
        if(aux3==2)
            shellsort(vetor,aux,2);
    cout << "O vetor ordenado é: " << endl;
    for(int j=0;j<< vetor[j] << " ";
        }
    delete [] vetor;
}