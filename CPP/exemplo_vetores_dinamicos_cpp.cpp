#include <iostream>
using namespace std;
int main ()
{
     //este struct monta uma "variavel" 
     //toda vez que eu escrever alunos o meu código
     //ja vai saber que esta "variavel" por sua vez tem 2 variáveis
     //que são nome e idade
     struct alunos
     {
          char nomeAluno[200];
          int idade;
     };
     char nomeAlunoVelho[200];
     int idadeVelho;
     char nomeAlunoNovo[200];
     int idadeNovo;
     int x; //x é o número de alunos da sala de aula
     int maisVelho; //pega a idade do aluno mais velho
     int maisNovo; //pega a idade do aluno mais novo
     char nome[200];
     alunos *sala = NULL;
     
	 cout << "Entre com o número de alunos da sala." << endl;
     cin >> x;
     
	 sala = new alunos[x]; //neste ponto o vetor é alocado dinamicamente
     //este vetor é do tipo alunos
     maisVelho=0;
     maisNovo=100; //inicializo o mais novo com 100 porque nenhum aluno vai ter no mínimo 101 anos
     
	 for(int i=0; i<x;i++)
     {
          cout << "Entre com o nome do aluno:" << i << endl;
          cin.ignore();
          cin.getline(sala[i].nomeAluno,200);
          cout << "Entre com a idade do aluno:" << i << endl;
          cin >> sala[i].idade;
          if(maisVelho < sala[i].idade)
          {
               strcpy(nomeAlunoVelho,sala[i].nomeAluno);
               idadeVelho=sala[i].idade;
               maisVelho=idadeVelho;
          }
     
	      if(maisNovo > sala[i].idade)
          {
               strcpy(nomeAlunoNovo,sala[i].nomeAluno);
               idadeNovo=sala[i].idade;
               maisNovo=idadeNovo;
          }
     }
	 
     cout << "O aluno mais velho é: " << nomeAlunoVelho << endl;
     cout << "A idade dele é: " << idadeVelho << endl;
     cout << "O aluno mais novo é: " << nomeAlunoNovo << endl;
     cout << "A idade dele é: " << idadeNovo << endl;
     
	 system("Pause");
     
	 delete [] sala;
     
	 return 0;
}