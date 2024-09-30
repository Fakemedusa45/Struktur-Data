#include <iostream>
using namespace std;

struct drones {
    string merk;
    string harga;
    string series;
    string tahun;
    int stok;
    drones *next;
};

void lihatDrone (drones *head){
    drones *temp = head;
    int hitung = 1;

    cout << "====================================" << endl;
    cout << "             DATA DRONE             " << endl;
    cout << "====================================" << endl;
    if (temp == nullptr){
        cout << "Data Masih Kosong";
        cout << "====================================" << endl;
        return;
    }

    while (temp != nullptr) {
        cout << "data ke-" << hitung << endl;
        cout << "Merk Drone : " << temp->merk << endl;
        cout << "Harga Drone : " << temp->harga << endl;
        cout << "Series Drone : " << temp->series << endl;
        cout << "Tahun rilis Drone : " << temp->tahun << endl;
        cout << "Stok Drone : " << temp->stok << endl;
        cout << "====================================" << endl;

        hitung += 1;
        temp = temp->next;
    }

    hitung = 0;
}

int tambahDroneDepan(drones *&head){
    drones *newNode = new drones;

    cout << "====================================" << endl;
    cout << "         TAMBAH DATA DRONE          " << endl;
    cout << "====================================" << endl;
    cout << "Masukkan merk drone : ";
    getline (cin, newNode->merk);
    cout << "Masukkan harga drone : ";
    getline (cin, newNode->harga);
    cout << "Masukkan series : ";
    getline (cin, newNode->series);
    cout << "Masukkan tahun rilis : ";
    getline (cin, newNode->tahun);
    cout << "Masukkan stok drone : ";
    cin >> newNode->stok;

    if (head == nullptr) {
        newNode->next = nullptr;
        head = newNode;
        return 0;
    }

    newNode->next = head;
    head = newNode;
    return 0;
}

int tambahDroneBelakang(drones *&head){
    drones *newNode = new drones;

    cout << "====================================" << endl;
    cout << "         TAMBAH DATA DRONE          " << endl;
    cout << "====================================" << endl;
    cout << "Masukkan merk drone : ";
    getline (cin, newNode->merk);
    cout << "Masukkan harga drone : ";
    getline (cin, newNode->harga);
    cout << "Masukkan series : ";
    getline (cin, newNode->series);
    cout << "Masukkan tahun rilis : ";
    getline (cin, newNode->tahun);
    cout << "Masukkan stok drone : ";
    cin >> newNode->stok;

    if (head == nullptr) {
        head = newNode;
        return 0;
    }

    drones *temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }

    newNode->next = nullptr;
    head->next = newNode;

    return 0;
}

void ubahDrone (drones *head){

    string merk;

    lihatDrone(head);
    drones *temp = head;

    if (temp == nullptr) {
        return;
    }

    cout << "====================================" << endl;
    cout << "          UBAH DATA DRONE           " << endl;
    cout << "====================================" << endl;
    cout << "Masukkan merk drone yang ingin diubah : ";
    getline(cin, merk);
    cout << endl;

    while(temp != nullptr && temp->merk != merk){
        temp = temp->next;
    }

    if (temp == nullptr){
        cout << "Data tidak ditemukan...";
        return;
    }

    cout << "Masukkan merk drone : ";
    getline (cin, temp->merk);
    cout << "Masukkan harga drone : ";
    getline (cin, temp->harga);
    cout << "Masukkan series : ";
    getline (cin, temp->series);
    cout << "Masukkan tahun rilis : ";
    getline (cin, temp->tahun);
    cout << "Masukkan stok drone : ";
    cin >> temp->stok;

    cout << "\n \nData dengan merk " << merk << " berhasil diubah." << endl;

}

void hapusDrone (drones *&head){
    string merk;

    lihatDrone(head);
    drones *temp = head;

    if (temp == nullptr) {
        return;
    }

    cout << "====================================" << endl;
    cout << "          HAPUS DATA DRONE          " << endl;
    cout << "====================================" << endl;
    cout << "Masukkan merk drone yang ingin dihapus : ";
    getline(cin, merk);
    cout << endl;

    while(temp != nullptr && temp->merk != merk){
        temp = temp->next;
    }

    if (temp != nullptr && temp->merk == merk) {
        head = temp->next;
        delete temp;
        cout << "Data dengan merk " << merk << " berhasil dihapus (node pertama)." << endl;
        return;
    }

      while (temp != nullptr && temp->next != nullptr && temp->next->merk != merk) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Data tidak ditemukan..." << endl;
        return;
    }

    drones *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    cout << "Data dengan merk " << merk << " berhasil dihapus." << endl;

}

int main (){
    int pilihan;
    drones *head = nullptr;

//    drone[0].merk = "DJI Mavic Mini 2";
//    drone[0].harga = "5.000.000";
//    drone[0].series = "Mavic";
//    drone[0].tahun = "2015";
//    drone[0].stok = 7;

    while (true){
        cin.clear();
        system("cls");
        cout << "==============================" << endl;
        cout << "             MENU             " << endl;
        cout << "==============================" << endl;
        cout << "  1. TAMBAH DATA (depan)      " << endl;
        cout << "  2. TAMBAH DATA (belakang)   " << endl;
        cout << "  3. LIHAT DATA               " << endl;
        cout << "  4. UBAH DATA                " << endl;
        cout << "  5. HAPUS DATA               " << endl;
        cout << "  0. KELUAR                   " << endl;
        cout << "==============================" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        cin.ignore();


        switch (pilihan){
            case 1:
                tambahDroneDepan (head);
                break;
            case 2:
                tambahDroneBelakang (head);
                break;
            case 3:
                lihatDrone (head);
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
