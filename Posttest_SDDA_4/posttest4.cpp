#include <iostream>
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
    // Cek apakah data drone ada
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
    nodeBelanja*newNode = new nodeBelanja;
//    newNode->drone = temp->drone; // Salin data drone
    newNode->buy = buy;           // Salin data pembeli
    newNode->nextBelanja = nullptr;

    if (isQueueEmpty()) {
        newNode->prevBelanja = nullptr;
        headBelanja = newNode;
        lastBelanja = newNode; // Inisialisasi head dan last
    } else {
        newNode->prevBelanja = lastBelanja;
        lastBelanja->nextBelanja = newNode;
        lastBelanja = newNode; // Update last
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
        cout << "  1. TAMBAH DATA (depan)                " << endl;
        cout << "  2. LIHAT DATA (yang baru ditambahkan) " << endl;
        cout << "  3. LIHAT DATA                         " << endl;
        cout << "  4. UBAH DATA                          " << endl;
        cout << "  5. HAPUS DATA                         " << endl;
        cout << "  6. HAPUS DATA (yang baru ditambahkan) " << endl;
        cout << "  7. TAMBAH PEMBELI                     " << endl;
        cout << "  8. LAYANI PEMBELI                     " << endl;
        cout << "  9. LIHAT ANTRIAN                      " << endl;
        cout << "  0. KELUAR                             " << endl;
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
