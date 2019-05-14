/* 
nama : Sina Mustopa
kelas : A
NPM : 140810180017
Deskripsi : Tree Menu dengan traversal
*/

#include<iostream>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul(pointer& pBaru){
    pBaru=new Simpul;
    cout<<"Masukkan satu angka : ";
    cin>>pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}
void insertBST (Tree& Root, pointer pBaru){
    if(Root==NULL){
        Root=pBaru;
    }
    else if (pBaru->info < Root->info){
        insertBST(Root->left,pBaru);
    }
    else if (pBaru->info > Root->info){
        insertBST(Root->right,pBaru);
    }
    else{
        cout<<"Sudah ada"<<endl;
    }
}
void preOrder (Tree Root) {
    if (Root != NULL){
        cout<< Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}
void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}

void notasiKurung(Tree Root){
    if (Root != NULL){
        cout << "(" << Root->info << " ";
        notasiKurung(Root->left);
        notasiKurung(Root->right);
        cout << ")";
    }
}

int main(){
    Tree Root;
    pointer p;
	int n,pil;
	char jawab;
	
    Root=NULL;
do{
    system("cls");
  cout<<"===================================="<<endl;
  cout<<"||    Program TRAVERSAL TREE      ||"<<endl;
  cout<<"===================================="<<endl;
  cout<<"1. Input Data " << endl;
  cout<<"2. Pre Order" << endl;
  cout<<"3. In Order" << endl;
  cout<<"4. Post Order "<< endl;
  cout<<"5. Notasi Kurung "<<endl;
  cout<<"Input <1/2/3/4> : "; cin >> pil;
  

  switch(pil){
       case 1:
       	cout<<"Input Jumlah Data : ";cin>>n;
    for (int i=0;i<n;i++){
        createSimpul(p);
        insertBST(Root,p);
    }
       break;
       
       case 2:
       preOrder(Root);cout<<" , ";
       break;
       
       case 3:
       inOrder(Root);cout<<" , ";
	   break;
	   
	   case 4:
	   postOrder(Root);cout<<" , ";
	   break;
	   
	   case 5:
		notasiKurung(Root);
		break;

       case 0:
        return 0;
       break;
      }
        cout<<"\nKembali ke Menu ? (Y/N) :     ";cin>>jawab;
  }

       while(jawab=='Y' || jawab=='y');
       if(jawab =='n' || jawab=='N'){
       	return 0;
	   }
} 
