#include <iostream>
using namespace std;

class Tumbuhan{
    public:
    struct Pohon{
    string namaPohon;
    string jenisBiji;
    int masaHidup;
    Pohon* next;
    };
    Pohon *head, *tail, *cur, *newNode, *del, *before;
public:
    Tumbuhan() : head(nullptr), tail(nullptr), cur(nullptr) {}
void createSingleLinkedList(string nP, string jB, int mH){
    head = new Pohon();
    head->namaPohon = nP;
    head-> jenisBiji = jB;
    head->masaHidup = mH;
    tail =head;
}
int countSingleLinkedList(){
    cur = head;
    int jumlah = 0;
while(cur != NULL){
    jumlah++;
    cur= cur->next;
    }
    return jumlah;
}  
    void addFirst(string namaPohon, string jensiBiji, int mH){
    newNode = new Pohon();
    newNode->namaPohon = namaPohon;
    newNode->jenisBiji = jensiBiji;
    newNode->masaHidup= mH;
    newNode->next = head;
    head = newNode;
}
void addLast(string namaPohon, string jenisBiji, int mH){
    newNode = new Pohon();
    newNode->namaPohon = namaPohon;
    newNode->jenisBiji = jenisBiji;
    newNode->masaHidup= mH;
    newNode->next = nullptr;
    tail->next = newNode;
    tail= newNode;
}
    //middle single linked list
    void addMiddle(string namaPohon, string jenisBiji, int mH, int posisi){
        if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar nalar" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        newNode = new Pohon();
        newNode->namaPohon = namaPohon;
        newNode->jenisBiji = jenisBiji;
        newNode->masaHidup= mH;

        cur= head;
        int nomor = 1;
        while(nomor < posisi - 1){
            cur=cur->next;
            nomor++;
        }
        newNode->next =cur->next;
        cur->next=newNode;
    }
}
void removeFirst(){
    del = head;
    head = head->next;
    delete del;
}
void removeLast(){
    del = tail;
    cur = head;
    while (cur->next != tail){
        cur = cur->next;
    }
    tail = cur;
    tail->next = nullptr;
    delete del;
}
void removeMiddle(int posisi) {
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar nalar" << endl;
    }
    else if (posisi == 1 || posisi == countSingleLinkedList()) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        int nomor = 1;
        cur = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                before = cur;
            }
            if (nomor == posisi) {
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}
void changeFirst(string namaPohon, string jenisBiji, int mH){
    head->namaPohon = namaPohon;
    head->jenisBiji = jenisBiji;
    head->masaHidup= mH;
}
void changeLast(string namaPohon, string jenisBiji, int mH){
    tail->namaPohon = namaPohon;
    tail->jenisBiji = jenisBiji;
    tail->masaHidup= mH;
}
void changeMiddle(string namaPohon, string jenisBiji, int mH,int posisi){
    if (posisi < 1 || posisi > countSingleLinkedList()) {
        cout << "Posisi diluar nalar" << endl;
    }
    else if (posisi == 1 || posisi == countSingleLinkedList()) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        cur= head;
        int nomor = 1;
        while(nomor < posisi){
            cur=cur->next;
            nomor++;
        }
    cur->namaPohon = namaPohon;
    cur->jenisBiji = jenisBiji;
    cur->masaHidup= mH;
    }
}
void printSingleLinkedList(){
    cout<<"jumlah data ada: " << countSingleLinkedList()<<endl;
    cur = head;
while (cur != nullptr) {
    cout<<"Nama Pohon: Pohon "<< cur->namaPohon<<endl;
    cout<<"jenis Biji: "<< cur->jenisBiji<<endl;
    cout<<"masaHidup : "<< cur->masaHidup<<" tahun"<<endl;
    cur = cur->next;
    }
    }
};

int main(){
    Tumbuhan tumbuhan;

    tumbuhan.createSingleLinkedList("Pohon Mangga", "dikotil", 300);
    tumbuhan.printSingleLinkedList();
    cout << "\n\n" << endl;

    tumbuhan.addFirst("Kelapa", "Monokotil", 100);
    tumbuhan.printSingleLinkedList();

    cout << "\n\n" << endl;

    tumbuhan.addLast("Durian", "Dikotil", 200);
    tumbuhan.printSingleLinkedList();

    cout << "\n\n" << endl;

    tumbuhan.removeFirst();
    tumbuhan.printSingleLinkedList();

    cout << "\n\n" << endl;

    tumbuhan.addLast("Pisang", "Monokotil", 30);
    tumbuhan.printSingleLinkedList();

    cout << "\n\n" << endl;

    tumbuhan.removeLast();
    tumbuhan.printSingleLinkedList();

    cout << "\n\n" << endl;

    tumbuhan.changeFirst("Cemara", "Dikotil", 1000);
    tumbuhan.printSingleLinkedList();

    cout << "\n\n" << endl;

    tumbuhan.changeLast("Beringin", "Dikotil", 16);
    tumbuhan.printSingleLinkedList();

    tumbuhan.addMiddle("mawar", "dikotil", 10, 2);
    tumbuhan.printSingleLinkedList();
        
    cout<<"\n\n"<<endl;

    tumbuhan.addMiddle("nangka", "monokotil", 100, 2);
    tumbuhan.printSingleLinkedList();
        
    cout<<"\n\n"<<endl;

    tumbuhan.removeMiddle(5);
    tumbuhan.printSingleLinkedList();
        
    cout<<"\n\n"<<endl;

    tumbuhan.changeMiddle("sirsak", "dikotil", 15, 2);
    tumbuhan.printSingleLinkedList();
        
    cout<<"\n\n"<<endl;
    
}

