#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int c1=0,c2=0,c3=0;
struct tree
{
    int id;
    int weight;
    tree *l,*r;
};
tree *A=NULL;
void push(tree* &tr,int x, int y)
{
    if(tr==NULL)
    {
        tree *tmp=new tree;
        tmp->id=x;
        tmp->weight=y;
        tr=tmp;
        tr->l=NULL;
        tr->r=NULL;
        return;
    }
    else
    {
        if(x<tr->id)push(tr->l,x,y);
        else
            push(tr->r,x,y);

    }

}
void show(tree *t, int n)
{
    if(t!=NULL)
    {
        show(t->l,n+1);
        cout <<setw(n*3)<<t->id<<"("<<t->weight<<")"<<endl;
        show(t->r,n+1);
    }

}
tree* m(tree* &tr)
{
    if(tr->r==NULL)
    {
        tree* tmp=new tree;
        tmp=tr;
        tree* n=new tree;
        n->id=tr->id;
        n->weight=tr->weight;
        tr=tr->l;
        delete(tmp);
        return n;

    }
    else return m(tr->r);

}
void pop(tree* &tr, int x)
{
    if(tr==NULL) return;
    if(x<tr->id)
    {
        pop(tr->l,x);
        return;
    }
    if(x>tr->id)
    {
        pop(tr->r,x);
        return;
    }
    if(x==tr->id)
    {
        if(tr->l==NULL&&tr->r==NULL)
        {
            tree* tmp=new tree;
            tmp=tr;
            tr=NULL;
            delete(tmp);
            return;
        }
        if(tr->l!=NULL&&tr->r==NULL)
        {
            tree* tmp=new tree;
            tmp=tr;
            tr=tr->l;
            delete(tmp);
            return;
        }
        if(tr->l==NULL&&tr->r!=NULL)
        {
            tree* tmp=new tree;
            tmp=tr;
            tr=tr->r;
            delete(tmp);
            return;
        }
        if(tr->l!=NULL&&tr->r!=NULL)
        {
            tree* tmp=m(tr->l);
            tr->id=tmp->id;
            tr->weight=tmp->weight;
            delete(tmp);
            return;

        }
    }

}
void individual(tree *t)
{
    if(t!=NULL)
    {
        if(t->id%2==0&&t->weight==-1)c1++;
        if(t->id%2==0&&t->weight==0)c2++;
        if(t->id%2==0&&t->weight==1)c3++;
      individual(t->l);
      individual(t->r);
    }

}
void menu(int a)
{
    int b;
    int x;
    int y;
    switch(a)
    {
    case 1:
        cout<<"Vvedite id"<<endl;
        cin >>x;
        cout<< "Vvedite ves"<<endl;
        cin>>y;
        push(A,x,y);
        break;
    case 2:
        cout<<"Vvedite id"<<endl;
        cin>>x;
        pop(A,x);
        break;
    case 3:
        show(A,2);
        break;
    case 4:
        individual(A);
        if(c1==2||c2==2||c3==2)cout<<"Da"<<endl;
        else cout <<"Net"<<endl;
        break;
    }
    cin >>b;
    if(b==0)return;
    else
        menu(b);
}
int main()
{
    int i;
    for(i=0; i<10; i++)push(A,rand()%100,rand()%3-1);
    cout << "Vvedite 0, chtoby vyiti iz menu" << endl;
    cout <<"Vvedite 1, chtoby dobavit element"<<endl;
    cout<<"Vvedite 2, chtoby udalit element"<<endl;
    cout<<"Vvedite 3, chtoby vyvesti na ekran"<<endl;
     cout<<"4 - individualnoe zadanie"<<endl;
    cin >>i;
    menu(i);
    return 0;
}
