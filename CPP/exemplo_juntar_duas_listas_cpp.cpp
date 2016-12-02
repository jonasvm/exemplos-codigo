#include <iostream>
using namespace std;

struct no
{
     char nome[200];
     int matricula;
     no* next;
};

typedef no* noptr;

void pushMeninos (noptr &s, int t, char a[])
{
     no *p;
     p = new no;
     p->matricula = t;
     strcpy(p->nome,a);
	 
     if (s == NULL)
          p->next=NULL;
     else
          p->next = s;
		  
     s=p;
};

void pushMeninas (noptr &s, int g, char b[])
{
     no *p;
     p = new no;
     p->matricula = g;
     strcpy(p->nome,b);
	 
     if (s == NULL)
          p->next=NULL;
     else
          p->next = s;
		  
     s=p;
};

void pop (noptr &lista, int &matricula, char nomeA[])
{
     no *p;
     
	 if (lista == NULL)
          cout << "Lista vazia";
     else
     {
          p=lista;
          lista = p-> next;
          matricula = p-> matricula;
          strcpy(nomeA,p-> nome);
          delete p;
     }
};

void juntaListas (noptr &lista, noptr &lista2)
{
     no *p;
     no *q;
     p = lista;
     q = lista2;
     
	 while (p->next != NULL)
     {
          p = p-> next;
     }
	 
     p->next = q;
};

int main()
{
     noptr lista2 = NULL;
     noptr lista = NULL;
     char nome[200];
     int matricula;
     char nome2[200];
     int matricula2;
	 
     cout << "Acrescentando os meninos da sala" << endl;
     cout <<"Entre com o número da matricula (-1 para sair)" << endl;
     cin >> matricula;
	 
     while (matricula != -1)
     {
          cout << "Entre com o nome do aluno" << endl;
          cin.ignore();
          cin.getline(nome,200);
          pushMeninos(lista,matricula,nome);
          cout <<"Entre com o número da matricula (-1 para sair)" << endl;
          cin >> matricula;
     }
	 
     cout << "Agora vamos acrescentar as meninas da sala." << endl;
     cout <<"Entre com o número da matricula (-1 para sair)" << endl;
     cin >> matricula2;
     
	 while (matricula2 != -1)
     {
          cout << "Entre com o nome do aluno" << endl;
          cin.ignore();
          cin.getline(nome2,200);
          pushMeninas(lista2,matricula2,nome2);
          cout <<"Entre com o nÃºmero da matricula (-1 para sair)" << endl;
          cin >> matricula2;
     }
     
	 juntaListas(lista,lista2);
     cout << "A lista de chamada da sala Ã©:" << endl;
     
	 while (lista != NULL)
     {
          pop(lista, matricula, nome);
          cout << nome << " " << matricula << endl;
     }
     
	 return 0;
}