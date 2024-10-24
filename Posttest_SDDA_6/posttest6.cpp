#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

struct drones {
    string merk;
    string harga;
    string series;
    string tahun;
    int stok;
};

struct belanja {
    string nama;
    string merk;
    int jumlah;
};

struct node{
    drones drone;
    node*next;
    node*prev;
};

struct nodeBelanja {
    belanja buy;
    nodeBelanja*nextBelanja;
    nodeBelanja*prevBelanja;
};

struct node*head=NULL;
struct node*last=NULL;

struct nodeBelanja*headBelanja;
struct nodeBelanja*lastBelanja;


bool kosong(){
    return head==NULL;
}


bool isQueueEmpty() {
    return headBelanja == nullptr;
}

int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int min(int x, int y) { return (x <= y) ? x : y; }

//STACK (PEEK)
void peek(){
    if(kosong()){
        cout<<"Data kosong, tidak ada yang bisa ditampilkan"<<endl;
        return;
    }
    else{
        cout << "Merk Drone : " << last->drone.merk << endl;
        cout << "Harga Drone : " << last->drone.harga << endl;
        cout << "Series Drone : " << last->drone.series << endl;
        cout << "Tahun rilis Drone : " << last->drone.tahun << endl;
        cout << "Stok Drone : " << last->drone.stok << endl;
    }
}

void lihatDrone (){


    cout << "========================================" << endl;
    cout << "               DATA DRONE               " << endl;
    cout << "========================================" << endl;
    if(kosong()){
        cout << "Data kosong, tidak ada yang bisa ditampilkan"<<endl;
        cout << "========================================" << endl;

        return;
    }
    else{
        int hitung = 1;
        node*temp=head;
        while (temp != NULL) {
            cout << "data ke-" << hitung << endl;
            cout << "Merk Drone : " << temp->drone.merk << endl;
            cout << "Harga Drone : " << temp->drone.harga << endl;
            cout << "Series Drone : " << temp->drone.series << endl;
            cout << "Tahun rilis Drone : " << temp->drone.tahun << endl;
            cout << "Stok Drone : " << temp->drone.stok << endl;
            cout << "========================================" << endl;


            temp = temp->next;
            hitung += 1;
        }
    }
}

//STACK (PUSH)
int tambahDroneDepan(drones drone){

    cout << "========================================" << endl;
    cout << "           TAMBAH DATA DRONE            " << endl;
    cout << "========================================" << endl;
    cout << "Masukkan merk drone : ";
    getline (cin, drone.merk);
    cout << "Masukkan harga drone : ";
    getline (cin, drone.harga);
    cout << "Masukkan series : ";
    getline (cin, drone.series);
    cout << "Masukkan tahun rilis : ";
    getline (cin, drone.tahun);
    cout << "Masukkan stok drone : ";
    cin >> drone.stok;

    if (kosong()) {
        node*baru=new node;
        baru->drone=drone;
        baru->next=NULL;
        baru->prev=NULL;
        head=baru;
        last=baru;
    }else {
    node*baru=new node;
    baru->drone=drone;
    baru->prev=last;
    last->next=baru;
    baru->next=NULL;
    last=baru;
    }
    return 0;
}

void ubahDrone (node *head){
    string merk;
    lihatDrone();
    node *temp = head;

    if (temp == nullptr) {
        return;
    }

    cout << "========================================" << endl;
    cout << "            UBAH DATA DRONE             " << endl;
    cout << "========================================" << endl;
    cout << "Masukkan merk drone yang ingin diubah : ";
    getline(cin, merk);
    cout << endl;

    while(temp != nullptr && temp->drone.merk != merk){
        temp = temp->next;
    }

    if (temp == nullptr){
        cout << "Data tidak ditemukan..." << endl;
        cout << "========================================" << endl;
        return;
    }


    cout << "Masukkan merk drone baru: ";
    getline(cin, temp->drone.merk);
    cout << "Masukkan harga drone baru: ";
    getline(cin, temp->drone.harga);
    cout << "Masukkan series baru: ";
    getline(cin, temp->drone.series);
    cout << "Masukkan tahun rilis baru: ";
    getline(cin, temp->drone.tahun);
    cout << "Masukkan stok drone baru: ";
    cin >> temp->drone.stok;
    cin.ignore();

    cout << "\nData dengan merk " << merk << " berhasil diubah." << endl;
}


//STACK (POP)
void Pop(drones drone) {
    if(kosong()){
        cout<<"Data kosong, tidak ada yang dihapus"<<endl;
        cout << "========================================" << endl;
        return;
    }
    else if(head==last) {
        delete head;
        head=NULL;
        last=NULL;
    }
    else{
        node*temp=last;
        last=last->prev;
        last->next=NULL;
        delete temp;
    }
}

void hapusDrone (node *&head) {
    string merk;
    lihatDrone();
    node *temp = head;

    if (temp == nullptr) {
        cout << "Data tidak ditemukan..." << endl;
        cout << "========================================" << endl;
        return;
    }

    cout << "========================================" << endl;
    cout << "            HAPUS DATA DRONE            " << endl;
    cout << "========================================" << endl;
    cout << "Masukkan merk drone yang ingin dihapus : ";
    getline(cin, merk);

    if (temp->drone.merk == merk) {
        head = temp->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        cout << "Data dengan merk " << merk << " berhasil dihapus." << endl;
        return;
    }

    while (temp != nullptr && temp->drone.merk != merk) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Data tidak ditemukan..." << endl;
        return;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Data dengan merk " << merk << " berhasil dihapus." << endl;
}

void tambahPembeli(drones drone, belanja buy) {
    if (kosong()) {
        cout << "Data drone kosong, tidak ada yang bisa dibeli." << endl;
        cout << "========================================" << endl;
        return;
    }

    lihatDrone();

    cout << "Nama Pembeli: ";
    getline(cin, buy.nama);
    cout << "Merk Drone: ";
    getline(cin, buy.merk);
    cout << "Jumlah yang Dibeli: ";
    cin >> buy.jumlah;
    cin.ignore();

    // Cari drone berdasarkan merk
    node* temp = head;
    while (temp != nullptr && temp->drone.merk != buy.merk) {
        temp = temp->next;
    }

    // Cek apakah drone ditemukan
    if (temp == nullptr) {
        cout << "Drone merk " << buy.merk << " tidak ditemukan." << endl;
        return;
    }

    // Cek apakah stok mencukupi
    if (buy.jumlah > temp->drone.stok) {
        cout << "Stok tidak mencukupi! Stok yang tersedia hanya " << temp->drone.stok << " unit." << endl;
        return;
    }

    temp->drone.stok -= buy.jumlah;

    // Tambahkan transaksi ke antrian
    nodeBelanja*newnode = new nodeBelanja;
//    newnode->drone = temp->drone;
    newnode->buy = buy;
    newnode->nextBelanja = nullptr;

    if (isQueueEmpty()) {
        newnode->prevBelanja = nullptr;
        headBelanja = newnode;
        lastBelanja = newnode;
    } else {
        newnode->prevBelanja = lastBelanja;
        lastBelanja->nextBelanja = newnode;
        lastBelanja = newnode;
    }

    cout << "Pembelian berhasil! " << buy.jumlah << " unit drone " << buy.merk << " telah ditambahkan ke dalam antrian." << endl;
}


void layani (belanja buy){
    if (isQueueEmpty()) {
        cout << "Antrian kosong, tidak ada yang bisa dilayani." << endl;
        return;
    }

    node* temp = head;

    if (head == last) {
        head = last = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    cout << "Transaksi berhasil dilayani dan dihapus dari antrian." << endl;
}

void lihatAntrian() {
    if (isQueueEmpty()) {
        cout << "Antrian kosong." << endl;
        return;
    }

    nodeBelanja* temp = headBelanja;
    cout << "========================================" << endl;
    cout << "             DATA ANTRIAN               " << endl;
    cout << "========================================" << endl;

    while (temp != nullptr) {
        cout << "Nama Pembeli: " << temp->buy.nama << endl;
        cout << "Merk Drone: " << temp->buy.merk << endl;
        cout << "Jumlah Beli: " << temp->buy.jumlah << endl;
        cout << "========================================" << endl;
        temp = temp->nextBelanja;
    }
}

void swapDrones(drones& a, drones& b) {
    drones temp = a;
    a = b;
    b = temp;
}

//QUICK SORT
node* partition(node* low, node* high) {
    string pivot = high->drone.harga;
    node* i = low->prev;

    for (node* j = low; j != high; j = j->next) {
        if (j->drone.harga >= pivot) {
            i = (i == nullptr) ? low : i->next;
            swapDrones(i->drone, j->drone);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swapDrones(i->drone, high->drone);
    return i;
}

void quickSort(node* low, node* high) {
    if (high != nullptr && low != high && low != high->next) {
        node* pi = partition(low, high);
        quickSort(low, pi->prev);
        quickSort(pi->next, high);
    }
}

void quickSortDesc() {
    if (head == nullptr) return;
    quickSort(head, last);
}

//SHELL SORT
void shellSort(node* head) {
    int n = 0;
    node* temp = head;

    while (temp != nullptr) {
        n++;
        temp = temp->next;
    }

    drones* arr = new drones[n];
    temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = temp->drone;
        temp = temp->next;
    }

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            drones temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap].harga > temp.harga; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }

    temp = head;
    for (int i = 0; i < n; i++) {
        temp->drone = arr[i];
        temp = temp->next;
    }

    delete[] arr;
}

// Fibonacci Search
int fibMonaccianSearch(node *head, int x, int n)
{
    node *temp = head;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);

        temp = head;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        if (temp->drone.stok < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (temp->drone.stok > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
            return i;
    }
    temp = head;
    for (int j = 0; j < offset + 1; j++)
    {
        temp = temp->next;
    }
    if (fibMMm1 && temp->drone.stok == x)
        return offset + 1;
    return -1;
}

// Jump Search
int findnode(node *head, int idx)
{
    for (int i = 0; i < idx; i++)
    {
        head = head->next;
    }
    return head->drone.stok;
}

int jumpSearch(node *head, int x, int n)
{
    int step = sqrt(n);
    int prev = 0;

    int idx = min(step, n) - 1;
    while (findnode(head, idx) < x)
    {
        prev = step;
        step += sqrt(n);
        idx = min(step, n) - 1;
        if (prev >= n)
        {
            return -1;
        }
    }
    while (findnode(head, prev) < x)
    {
        prev++;
    }
    if (findnode(head, prev) == x)
    {
        return prev;
    }
    return -1;
}

// Boyer-Moore
const int NO_OF_CHARS = 256;
void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS])
{
    for (int i = 0; i < NO_OF_CHARS; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}

void search(node *head, string pat)
{
    int m = pat.size();
    node *temp = head;
    while (temp != NULL)
    {
        int n = temp->drone.merk.size();
        int badChar[NO_OF_CHARS];
        badCharHeuristic(pat, m, badChar);
        int s = 0;

        while (s <= (n - m))
        {
            int j = m - 1;
            while (j >= 0 && pat[j] == temp->drone.merk[s + j])
            {
                j--;
            }
            if (j < 0)
            {
                cout << temp->drone.merk << endl;
                break;
            }
            else
            {
                s += max(1, j - badChar[temp->drone.merk[s + j]]);
            }
        }
        temp = temp->next;
    }
}

void menuSearch(){
    int c, x, idx;
    string xs;

    int pilih;
    cout << "========================================" << endl;
    cout << "               CARI DATA                " << endl;
    cout << "========================================" << endl;
    cout << " 1. STOK DRONE (Fibonacci Search)       " << endl;
    cout << " 2. STOK DRONE (Jump Search)            " << endl;
    cout << " 3. MERK DRONE (Boyer-Moore Search)     " << endl;
    cout << "========================================" << endl;
    cout << "Masukkan pilihan anda : ";
    cin >> pilih;
    cin.ignore();

    switch (pilih){
        case 1:

            if (kosong()) {
                cout << "Data drone kosong, tidak ada yang bisa dicari" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                return;
            }

            lihatDrone();
            cout << "Cari data stok drone: ";
            cin >> x;

            idx = fibMonaccianSearch(head, x, length(head));
            if (idx >= 0)
            {
                cout << "Found at index: " << idx << endl;
                node *current = head;
                for (int i = 0; i < idx; i++) {
                    current = current->next;
                }

                cout << "========================================" << endl;
                cout << "Merk Drone : " << current->drone.merk << endl;
                cout << "Harga Drone : " << current->drone.harga << endl;
                cout << "Series Drone : " << current->drone.series << endl;
                cout << "Tahun Rilis Drone : " << current->drone.tahun << endl;
                cout << "Stok Drone : " << current->drone.stok << endl;
                cout << "========================================" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                cin.ignore();
                break;
            }
            else
            {
                cout << x << " isn't present in the array" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }
        case 2:

            if (kosong()) {
                cout << "Data drone kosong, tidak ada yang bisa dicari" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                return;
            }

            lihatDrone();
            cout << "Cari data stok drone : ";
            cin >> x;

            idx = jumpSearch(head, x, length(head));
            if (idx >= 0)
            {
                cout << "Found at index: " << idx << endl;
                node *current = head;
                for (int i = 0; i < idx; i++) {
                    current = current->next;
                }

                cout << "========================================" << endl;
                cout << "Merk Drone : " << current->drone.merk << endl;
                cout << "Harga Drone : " << current->drone.harga << endl;
                cout << "Series Drone : " << current->drone.series << endl;
                cout << "Tahun Rilis Drone : " << current->drone.tahun << endl;
                cout << "Stok Drone : " << current->drone.stok << endl;
                cout << "========================================" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                cin.ignore();
                break;
            }
            else
            {
                cout << x << " isn't present in the array" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            }
        case 3:

            if (kosong()) {
                cout << "Data drone kosong, tidak ada yang bisa dicari" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                return;
            }

            lihatDrone();
            cout << "Cari string: ";
            cin >> xs;

            search(head, xs);
            cout << "\n Tekan Enter untuk melanjutkan...";
            cin.get();
            break;
        default:
            cout << "INPUT INVALID!" << endl;
            cout << "\n Tekan Enter untuk melanjutkan...";
            cin.get();
    }
}


int main (){
    int pilihan;
    drones drone;
    belanja buy;

    while (true){
        cin.clear();
        system("cls");
        cout << "========================================" << endl;
        cout << "                  MENU                  " << endl;
        cout << "========================================" << endl;
        cout << "  1.  TAMBAH DATA (depan)               " << endl;
        cout << "  2.  LIHAT DATA (yang baru ditambahkan)" << endl;
        cout << "  3.  LIHAT DATA                        " << endl;
        cout << "  4.  UBAH DATA                         " << endl;
        cout << "  5.  HAPUS DATA                        " << endl;
        cout << "  6.  HAPUS DATA (yang baru ditambahkan)" << endl;
        cout << "  7.  TAMBAH PEMBELI                    " << endl;
        cout << "  8.  LAYANI PEMBELI                    " << endl;
        cout << "  9.  LIHAT ANTRIAN                     " << endl;
        cout << "  10. SHELL SORT (ASCENDING)            " << endl;
        cout << "  11. QUICK SORT (DESCENDING)           " << endl;
        cout << "  12. CARI DATA                         " << endl;
        cout << "  0.  KELUAR                            " << endl;
        cout << "========================================" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        cin.ignore();


        switch (pilihan){
            case 1:
                tambahDroneDepan (drone);
                break;
            case 2:
                peek ();
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 3:
                lihatDrone ();
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 4:
                ubahDrone (head);
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 5:
                hapusDrone (head);
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 6:
                Pop (drone);
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 7:
                tambahPembeli (drone, buy);
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 8:
                layani (buy);
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 9:
                lihatAntrian ();
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 10:
                shellSort(head);
                cout << "Data berhasil diurutkan secara ascending menggunakan Shell Sort." << endl;
                lihatDrone ();
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 11:
                quickSortDesc();
                cout << "Data berhasil diurutkan secara descending menggunakan Quick Sort." << endl;
                lihatDrone ();
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();
                break;
            case 12:
                system("cls");
                menuSearch();
                break;
            case 0:
                system("cls");
                cout << "==============================" << endl;
                cout << "Terima Kasih dan sampai jumpa!" << endl;
                cout << "==============================" << endl;
                return 0;
            default:
                cout << "INPUT INVALID!" << endl;
                cout << "\n Tekan Enter untuk melanjutkan...";
                cin.get();

        }
    }
    return 0;
}
