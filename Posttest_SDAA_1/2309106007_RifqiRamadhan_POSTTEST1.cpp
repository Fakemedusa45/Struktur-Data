#include <iostream>
using namespace std;


int menaraHanoi(int piring, string menaraAsal, string menaraSementara, string menaraTujuan) {
    if (piring == 0){
        return 0;
    }
    menaraHanoi (piring-1, menaraAsal, menaraTujuan, menaraSementara);
    cout << "Pindahkan piringan " << piring << " dari " << menaraAsal << " ke " << menaraTujuan << endl;
    menaraHanoi (piring-1, menaraSementara, menaraAsal, menaraTujuan);

    return 0;
}

int main () {
    int piring = 3;

    string menaraAsal = "menara asal";
    string menaraSementara = "menara sementara";
    string menaraTujuan = "menara tujuan";

    menaraHanoi(piring, menaraAsal, menaraSementara, menaraTujuan);
    return 0;
}
