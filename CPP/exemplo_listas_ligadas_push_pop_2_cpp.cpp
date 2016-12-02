#include <iostream>
using namespace std;

struct no
{
     char nome[200];
     int tel;
     no* next;
};

typedef no* noptr;

void push (noptr &s, int t, char a[])
{
     no *p;
     p = new no;
     p->tel = t;
     strcpy(p->nome,a);
	 
     if (s == NULL)
          p->next=NULL;
     else
          p->next = s;
		  
     s=p;
};

void pop (noptr &lista, int &tele, char nomeA[])
{
     no *p;
	 
     if (lista == NULL)
          cout << "Lista vazia";
     else
     {
          p=lista;
          lista = p-> next;
          tele = p-> tel;
          strcpy(nomeA,p-> nome);
		  
          //cout << nomeA << " " <<tele << endl;
          delete p;
     }
};

void conta (noptr &lista)
{
     no *p;
     int cont = 0;
     p = lista;
	 
     while (p != NULL)
     {
          cont++;
          p = p-> next;
     }
	 
     cout << "Você tem " << cont << " contatos na sua lista" << endl;
};

int main()
{
     noptr lista = NULL;
     char nome[200];  
	 int tel;
	 
     cout <<"Entre com o número do telefone (-1 para sair)" << endl;
     cin >> tel;
	 
     while (tel != -1)
     {
          cout << "Entre com o nome do contato" << endl;
          cin.ignore();
          cin.getline(nome,200);
		  
          push(lista,tel,nome);
		  
          cout <<"Entre com o número do telefone (-1 para sair)" << endl;
          cin >> tel;
     }
	 
     conta(lista);
	 
     cout << "Os contatos adicionados à  lista são: " << endl;
	 
     while (lista != NULL)
     {
          pop(lista, tel, nome);
          cout << nome << " " << tel << endl;
     }
	 
     return 0;
}