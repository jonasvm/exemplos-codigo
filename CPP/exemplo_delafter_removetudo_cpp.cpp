#include <iostream>
using namespace std;

struct no
{
     int info;
     no* next;
};

typedef no* noptr;

void push (noptr &s, int t)
{
     no *p;
     p = new no;
     p->info = t;
	 
     if (s == NULL)
          p->next=NULL;
     else
          p->next = s;
		  
     s=p;
};

void delafter(noptr &p, int &x)
{
     noptr q;
     q = p->next;
     x = q->info;
     p->next = q->next;
     delete q;
}

int pop (noptr &lista)
{
     int q;
     no *p;
	 
     if (lista == NULL)
          cout << "Lista vazia";
     else
     {
          p=lista;
          lista = p->next;
          q = p->info;
          delete p;
     }
	 
     return q;
};

void removetudo(noptr &lista, int x)
{
     noptr p,q;
     int aux;
     q = NULL;
     p = lista;
	 
     while(p != NULL)
     {
          if (p->info == x)
               if (q == NULL) // remove o primeiro da lista
               {
                    aux = pop(lista);
                    p = lista;
               }
               else
               {
                    p = p->next;
                    delafter(q,aux);
               }
          else // continua atravessando a lista
          {
               q = p;
               p = p->next;
          }
     }
}

int main()
{
     noptr lista = NULL;
     int informacao;
     int auxtel;
	 
     cout <<"Entre com o número do telefone (-1 para sair)" << endl;
     cin >> informacao;
	 
     while (informacao != -1)
     {
          push(lista, informacao);
          cout <<"Entre com o número do telefone (-1 para sair)" << endl;
          cin >> informacao;
     }
	 
     cout << "Digite o telefone que você deseja remover." << endl;
     cin >> auxtel;
	 
     removetudo(lista, auxtel);
	 
     cout << "Sua nova lista é: " << endl;
	 
     while (lista != NULL)
     {
          informacao=pop(lista);
          cout << informacao << endl;
     }
	 
     return 0;
}