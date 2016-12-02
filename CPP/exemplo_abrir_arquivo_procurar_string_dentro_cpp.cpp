#include <iostream>
#include <fstream>
#include  <cstring>

using namespace std;

int procura(char  *string, char *delim1, char *delim2, char *palavra)
{
     char  *inicio, *final;
     char *p;
     int i;
     inicio = strstr(string,  delim1);
	 
     if (inicio != NULL)
     {
          final =  strstr(string, delim2);
          i = 0;
          for(p=inicio+strlen(delim1);p<final;p++)
               palavra[i++] = *p;
		  
          palavra[i]= '';
          return 0;
     }
     else
          return 1;
}

int  main(int argc, char *argv[])
{
     char procurado[100];
     char aux[512];
     char palavra[512];
	 
     strcpy(procurado,argv[1]);
	 
     ifstream arquivo;
     arquivo.open("exemplo.txt");
	 
     if(arquivo.is_open())
     {
          while(!arquivo.eof())
          {
               arquivo.getline(aux,512);
               if  (procura(aux, "<hw>","</hw>",palavra)==0)
                    cout << "Palavra: " << palavra << endl;
			   
               if (procura(aux, "<def>","</def>",palavra)==0)
                    cout << "Definição: " << palavra << endl;
          }
		  
          arquivo.close();
     }
     else
          cout << "Cade o arquivo??" << endl;
		  
     return 0;
	 
	 // Para executar
	 //  g++ -o dict teste.cc
     // ./dict teste
}