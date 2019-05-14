/* 
nama : Sina Mustopa
kelas : A
NPM : 140810180017
Deskripsi : Queue
*/


#include <iostream>
using namespace std;

const int maxElemen = 255;
struct Queue{
    char isi[maxElemen];
    int head;
    int tail; 
};
int empty(Queue Q){
    return Q.tail&&Q.head==-1;
}
void enQueue(Queue& Q, char elemen) {
    if (Q.tail==maxElemen-1){
        cout<<"Antrian sudah penuh"<<endl;
    }
    else {
        Q.tail=Q.tail + 1;
        Q.isi[Q.tail] = elemen;
    }
}
void deQueue(Queue& Q, char& elemenHapus){
    cout<<"Delete Queue (Antrian) "<<endl;
    if (empty(Q)){ 
        cout<<"Antrian kosong"<<endl;
    }
    else {
        elemenHapus= Q.isi[Q.head];
        for (int i=0;i<Q.tail;i++){ 
            Q.isi[i]=Q.isi[i+1];
        }
        Q.tail=Q.tail-1;
    }
}
int main(){
    Queue Q;
    char elemen;
    int x;

    Q.head = 0;
    Q.tail = -1;
    cout<<"Banyak data : ";cin>>x;
    for (int i=0;i<x;i++){
        enQueue(Q,elemen);
        cout<<"Input : ";cin>>Q.isi[Q.tail];
    }
    cout<<"Output Data = [ ";
    for (int i=0;i<x;i++){
        if(i==x-1){
            cout<<Q.isi[i]<<" ";
        }
        else{
            cout<<Q.isi[i]<<",";
        }
    }
    cout<<"]"<<endl;
}
