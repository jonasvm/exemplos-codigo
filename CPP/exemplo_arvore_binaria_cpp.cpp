#include
using namespace std;
struct treenode
{
    int info;
    treenode *left;
    treenode *right;
};
typedef treenode *treenodeptr;
void tInsere(treenodeptr &p, int x)
{
    if (p == NULL) // insere na raiz
    {
        p = new treenode;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else
    {
        if(x < p->info)//insere na subarvore esquerda
            tInsere(p->left, x);
        else
            tInsere(p->right, x);
    }
}
void emOrdem(treenodeptr arvore, int &x)
{
    if(arvore != NULL)
    {
        emOrdem(arvore->left,x);
        x = x + arvore->info;
        emOrdem(arvore->right,x);
    }
}
void soma(treenodeptr arvore)
{
    int x = 0;
    emOrdem(arvore, x);
    cout << "Somatório dos elementos da árvore: " << x << endl;
}
int main(){
    int x = 0;
    treenodeptr arvore = NULL;
    while (x != -1)
    {
        cout << "Digite elemento a ser inserido." << endl;
        cin >> x;
        if (x != -1)
            tInsere(arvore, x);
    }
    soma(arvore);
}