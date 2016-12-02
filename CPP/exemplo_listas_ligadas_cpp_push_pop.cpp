#include <iostream>
using namespace std;

struct no
{
     char nome[200];
     int tel;
     no* next;
};

typedef no* noptr;

void push (noptr &s, int x, char a[])
{
     no *p;
     p = new no;
     p->tel = x;
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
          delete p;
     }
};

int main()
{
     int ver2; // verifica se o usuario deseja excluir um contato
     int ver=1; // verifica se o usuario deseja adicionar um contato
     int y; //y é o telefone do contato
     char contato[200];
     noptr lista = NULL;
     
	 while (ver == 1)
     {    
	      cout << "Entre com o telefone do seu contato." << endl;
          cin.ignore();
          cin >> y;
          cout << "Entre com o nome do seu contato." << endl;
          cin.ignore();
          cin.getline(contato,200);
		  
          push(lista,y,contato);
		  
          cout << "Digite 1 para armazenar outro contato, 2 para sair ou 3 para deletar um contato." << endl;
          cin >> ver;
		  
          ver2=ver;
		  
          if (ver2 == 3)
          {
               pop(lista, y, contato);
			   
               cout << contato << endl;
               cout << y << endl;
               cout << "Deseja deletar outro contato? 2 para sair ou 3 para deletar!" << endl;
          }
     }
	 
     system("Pause");
}