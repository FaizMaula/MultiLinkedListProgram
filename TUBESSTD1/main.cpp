#include "STD.h"

using namespace std;

int main()
{
    listBarang B;
    listPenyewa P;
    createListBarang(B);
    createListPenyewa(P);
    penyewa xp;
    barang xb;
    adr_penyewa p;
    adr_barang b;
    int NIK,ID, pilihan, choose, x, z;
    string tPenyewaan, tPengembalian;
    char y;
    inputAwal(B);
    pilihan = 0;
    pilihan = showMenu();
    while(pilihan != 0){
        switch(pilihan){
        case 1:
            cout << "==============================" << endl;
            cout << "  input Nama dan NIK penyewa  " << endl;
            cout << "==============================" << endl;

                cout << "Nama                : ";
                cin >> xp.nama;

                cout << "NIK                 : ";
                cin >> xp.NIK;

                cout << "Tanggal Penyewaan   : ";
                cin >> xp.tPenyewaan;

                cout << "Tanggal Pengembalian: ";
                cin >> xp.tPengembalian;

                cout << " " << endl;
                p = alokasiPenyewa(xp);
                insertPenyewa(P,p,"Awal");
                break;
        case 2:
            cout << "================================================" << endl;
            cout << "            Barang yang ada di gudang           " << endl;
            cout << "================================================" << endl;
            showBarang(B);
            cout << "================================================" << endl;
            cout << "            Barang yang ingin disewa            " << endl;
            cout << "================================================" << endl;

            cout << "NIK: ";
            cin >> NIK;
            cout << "ID : ";
            cin >> ID;
            cout << " " << endl;
            sewaBarang(P,B,NIK,ID);
            break;
        case 3:
            choose = 0;
            choose = showCari();
            while(choose != 0){
                if(choose == 1){
                    cout << "===================================" << endl;
                    cout << "        Mencari Data Penyewa       " << endl;
                    cout << "===================================" << endl;
                    cout << "Masukan NIK: ";
                    cin >> NIK;
                    adr_penyewa Q = cariPenyewa(P, NIK);
                    cout << "Nama                : " << info(Q).nama << endl;
                    cout << "NIK                 : " << info(Q).NIK << endl;
                    cout << "Tanggal Penyewaan   : " << info(Q).tPenyewaan << endl;
                    cout << "Tanggal Pengembalian: " << info(Q).tPengembalian << endl;
                } else if(choose == 2){
                    cout << "===================================" << endl;
                    cout << "        Mencari Data Penyewa       " << endl;
                    cout << "===================================" << endl;
                    cout << "Masukan ID: ";
                    cin >> ID;
                    adr_barang Q = cariBarang(B, ID);
                    cout << "Nama Barang: " << info(Q).namaBarang << endl;
                    cout << "ID         : " << info(Q).ID << endl;
                }
                cout << "Kembali ke menu Cari Data? (Y/N): ";
                cin >> y;
                while(y != 'Y'){
                    cout << "Kembali ke menu Cari Data? (Y/N): ";
                    cin >> y;
                    y = toupper(y);
                }
                choose = showCari();
            break;
        case 4:
            choose = 0;
            choose = showAdmin();
            while(choose != 0){
                y = 'N';
                switch (choose){
                    while(y != 'Y'){
                    case 1:
                        cout << "===================================" << endl;
                        cout << "  input ID Barang dan nama barang  " << endl;
                        cout << "===================================" << endl;
                        cout << "ID         : ";
                        cin >> xb.ID;
                        cout << "Nama Barang: ";
                        cin >> xb.namaBarang;
                        cout << "Jumlah barang: ";
                        cin >> xb.kuantitas;
                        cout << " " << endl;
                        b = alokasiBarang(xb);
                        insertBarang(B,b);
                        break;
                    case 2:
                        cout << "====================" << endl;
                        cout << "    List Penyewa    " << endl;
                        cout << "====================" << endl;
                        showPenyewa(P);
                        cout << " " << endl;
                        cout << "Kembali ke Menu Sebelumnya? y/n" << endl;
                        cin >> y;
                        y = toupper(y);
                        break;
                    case 3:
                        cout << "===============" << endl;
                        cout << "  List Barang  " << endl;
                        cout << "===============" << endl;
                        showBarang(B);
                        cout << " " << endl;
                        cout << "Kembali ke Menu Sebelumnya? y/n" << endl;
                        cin >> y;
                        y = toupper(y);
                        break;
                    case 4:
                        cout << "=================" << endl;
                        cout << "  Show All Data  " << endl;
                        cout << "=================" << endl;
                         showAllData(P);
                        cout << " " << endl;
                        cout << "Kembali ke Menu Sebelumnya? y/n" << endl;
                        cin >> y;
                        y = toupper(y);
                        break;
                    case 5:
                        choose = 0;
                        choose = showDelete();
                        while(choose != 0){
                            y = 'N';
                            switch (choose){
                                case 1:
                                    while (y != 'Y'){
                                        cout << "======================" << endl;
                                        cout << "  Hapus Data Penyewa  " << endl;
                                        cout << "======================" << endl;
                                        cout << "Masukan NIK: ";
                                        cin >> NIK;
                                        delete_penyewa(P, NIK);
                                        cout << "Kembali ke menu Hapus Data? (Y/N): ";
                                        cin >> y;
                                        y = toupper(y);
                                    }
                                    break;
                                case 2:
                                    while (y != 'Y'){
                                        cout << "======================" << endl;
                                        cout << "  Hapus Data Barang   " << endl;
                                        cout << "======================" << endl;
                                        cout << "Masukan ID: ";
                                        cin >> ID;
                                        delete_barang(B, ID);
                                        cout << "Kembali ke menu Hapus Data? (Y/N): ";
                                        cin >> y;
                                        y = toupper(y);
                                    }
                                    break;
                                case 3:
                                    while (y != 'Y'){
                                        cout << "======================" << endl;
                                        cout << "  Hapus Data Barang yang Sedang Disewa   " << endl;
                                        cout << "======================" << endl;
                                        cout << "Masukan ID: ";
                                        cin >> ID;
                                        cout << "Masukan NIK";
                                        cin >> NIK;
                                        hapusDataChildfromParent(P,NIK,ID);
                                        cout << "Kembali ke menu Hapus Data? (Y/N): ";
                                        cin >> y;
                                        y = toupper(y);
                                    }
                                    break;
                            }
                            choose = showDelete();
                        }
                        break;
                        choose = showAdmin();
                    }
                     choose = showAdmin();
                }

                }
            }
        }
         pilihan = showMenu();
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
}
