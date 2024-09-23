#include <iostream>
using namespace std;

struct drones {
    string merk;
    string harga;
    string series;
    string tahun;
    int stok;
};

void lihatDrone (drones drone[], int banyakDataDrone){
    cout << "====================================" << endl;
    cout << "             DATA DRONE             " << endl;
    cout << "====================================" << endl;
    if (banyakDataDrone != 0){
    for (int i = 0; i < banyakDataDrone; i++) {
        cout << (i+1) << "." << "Merk Drone : " << drone[i].merk << endl;
        cout << "  Harga Drone : " << drone[i].harga << endl;
        cout << "  Series Drone : " << drone[i].series << endl;
        cout << "  Tahun rilis Drone : " << drone[i].tahun<< endl;
        cout << "  Stok Drone : " << drone[i].stok << endl;
        cout << "====================================" << endl;
    }
    }
    else {
        cout << "Data Drone Kosong :(" << endl;
    }
}

int tambahDrone(drones drone[], int *banyakDataDrone){

    drones droneBaru;

    cout << "Masukkan merk drone : ";
    getline (cin, droneBaru.merk);
    cout << "Masukkan harga drone : ";
    getline (cin, droneBaru.harga);
    cout << "Masukkan series : ";
    getline (cin, droneBaru.series);
    cout << "Masukkan tahun rilis : ";
    getline (cin, droneBaru.tahun);
    cout << "Masukkan stok drone : ";
    cin >> droneBaru.stok;
    cin.ignore();

    drone[*banyakDataDrone] = droneBaru;
    (*banyakDataDrone)++;

    return 0;
}

void ubahDrone (drones drone[], int banyakDataDrone){

    int ubah;
    if (banyakDataDrone == 0) {
        cout << "Tidak ada data yang bisa diubah." << endl;
        return;
    }
    lihatDrone (drone, banyakDataDrone);

    drones droneUbah;

    cout << "Data ke berapa yang ingin anda ubah : ";
    cin >> ubah;
    cin.ignore();

    if (ubah <= 0 || ubah > banyakDataDrone) {
        cout << "Data tidak valid!" << endl;
        return;
    }

    cout << "Masukkan merk drone : ";
    getline (cin, droneUbah.merk);
    cout << "Masukkan harga drone : ";
    getline (cin, droneUbah.harga);
    cout << "Masukkan series : ";
    getline (cin, droneUbah.series);
    cout << "Masukkan tahun rilis : ";
    getline (cin, droneUbah.tahun);
    cout << "Masukkan stok drone : ";
    cin >> droneUbah.stok;
    cin.ignore();

    drone[ubah-1] = droneUbah;
    cin.clear();
}

void hapusDrone (drones drone[], int *banyakDataDrone){
    int hapus;
    if (*banyakDataDrone == 0) {
        cout << "Tidak ada data yang bisa dihapus." << endl;
        return;
    }

    lihatDrone(drone, *banyakDataDrone);

    cout << "Data ke berapa yang ingin anda hapus : ";
    cin >> hapus;
    cin.ignore();

    if (hapus <= 0 || hapus > *banyakDataDrone) {
        cout << "Input tidak valid!" << endl;
        return;
    }

    for (int i = hapus - 1; i < *banyakDataDrone - 1; i++) {
        drone[i] = drone[i + 1];
    }
    (*banyakDataDrone)--;
}

int main (){
    int pilihan;
    int banyakDataDrone = 1;

    drones drone[10];

    drone[0].merk = "DJI Mavic Mini 2";
    drone[0].harga = "5.000.000";
    drone[0].series = "Mavic";
    drone[0].tahun = "2015";
    drone[0].stok = 7;

    while (true){
        system("cls");
        cout << "==============================" << endl;
        cout << "             MENU             " << endl;
        cout << "==============================" << endl;
        cout << "  1. TAMBAH DATA              " << endl;
        cout << "  2. LIHAT DATA               " << endl;
        cout << "  3. UBAH DATA                " << endl;
        cout << "  4. HAPUS DATA               " << endl;
        cout << "  0. KELUAR                   " << endl;
        cout << "==============================" << endl;
        cout << "Masukkan pilihan anda : ";
        cin >> pilihan;
        cin.ignore();


        switch (pilihan){
            case 1:
                tambahDrone (drone, &banyakDataDrone);
                break;
            case 2:
                lihatDrone (drone, banyakDataDrone);
                break;
            case 3:
                ubahDrone (drone, banyakDataDrone);
                break;
            case 4:
                hapusDrone (drone, &banyakDataDrone);
                break;
            case 0:
                cout << "==============================" << endl;
                cout << "Terima Kasih dan sampai jumpa!" << endl;
                cout << "==============================" << endl;
                return 0;
            default:
                cout << "INPUT INVALID!" << endl;

        }
    }
    return 0;
}
