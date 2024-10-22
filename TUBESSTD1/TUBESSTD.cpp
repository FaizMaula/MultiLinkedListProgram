#include "STD.h"

void createListPenyewa(listPenyewa &LP){
    first(LP) = NULL;
}
void createListBarang(listBarang &LB){
    first(LB) = NULL;
}

void createListRelation(listRelation &LR){
    first(LR) = NULL;
}

adr_penyewa alokasiPenyewa(penyewa x) {
    adr_penyewa P = new elmPenyewa;
    next(P) = NULL;
    info(P) = x;
    createListRelation(relasi(P));
    return P;
}

adr_barang alokasiBarang(barang x){
    adr_barang P = new elmBarang;
    next(P) = NULL;
    info(P) = x;
    return P;
}

adr_relation alokasiRelasi(adr_barang x){
    adr_relation P = new elmrelation;
    nextB(P) = x;
    next(P) = NULL;
    return P;
}
void insertPenyewa(listPenyewa &LP,adr_penyewa P,string posisi){
    if(first(LP) == NULL) {
        first(LP) = P;
    } else if (posisi == "Awal"){
        next(P) = first(LP);
        first(LP) = P;
    } else {
        adr_penyewa q = first(LP);
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = P;
    }
}
void insertBarang(listBarang &LB, adr_barang P){
    if (first(LB) == NULL){
        first(LB) = P;
    } else {
        adr_barang q = first(LB);
        while (next(q) != NULL) {
            q = next(q);
        }
        next(q) = P;
    }
}

void insertRelasi(listRelation &LR, adr_relation P){
    if (first(LR) == NULL){
        first(LR) = P;
    } else {
        adr_relation q = first(LR);
        while (next(q) != NULL){
            q = next(q);
        }
        next(q) = P;
    }
}
void delete_penyewa(listPenyewa &LP, int NIK){
    adr_penyewa P = first(LP);
    adr_penyewa Prec = NULL;
    adr_penyewa p = cariPenyewa(LP,NIK);
    if(P == NULL){
        cout << "List Kosong" << endl;
    } else {
        if (p == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
        while (P != NULL && info(P).NIK != NIK) {
            Prec = P;
            P = next(P);
        }
        if (P != NULL) {
            if (Prec == NULL) {
                first(LP) = next(P);
            } else {
                next(Prec) = next(P);
            }
            P = NULL;
        }
    }
}
void delete_relasi(listRelation &LR, int ID){
    adr_relation P = first(LR);
    adr_relation Prec = NULL;
    if(P == NULL){
        cout << "Tidak sedang menyewa barang" << endl;
    } else {
        /*if (p == NULL){
            cout << "Data tidak ditemukan" << endl;
        }*/
        while (P != NULL && info(nextB(P)).ID != ID) {
            Prec = P;
            P = next(P);
        }
        if (P != NULL) {
            if (Prec == NULL) {
                first(LR) = next(P);
            } else {
                next(Prec) = next(P);
            }
            P = NULL;
            cout << "Data Berhasil Dihapus" << endl;
        } else {
            cout << "Data Barang Tidak Ditemukan" << endl;
        }

    }
}

void delete_barang(listBarang &LB, int ID){
    adr_barang P = first(LB);
    adr_barang Prec = NULL;
    adr_barang p = cariBarang(LB,ID);
    if(P == NULL){
        cout << "List Kosong" << endl;
    } else {
        if (p == NULL){
            cout << "Data tidak ditemukan" << endl;
        }
        while (P != NULL && info(P).ID != ID) {
            Prec = P;
            P = next(P);
        }
        if (P != NULL) {
            if (Prec == NULL) {
                first(LB) = next(P);
            } else {
                next(Prec) = next(P);
            }
            P = NULL;
        }
    }
}

void showPenyewa(listPenyewa LP){
    adr_penyewa q = first(LP);
    while (q != NULL){
        cout << "NAMA                : " << info(q).nama << endl;
        cout << "NIK                 : " << info(q).NIK << endl;
        cout << "Tanggal Penyewaan   : " << info(q).tPenyewaan << endl;
        cout << "Tanggal Pengembalian: " << info(q).tPengembalian << endl;
        cout << " " << endl;
        q = next(q);
    }
}
void showBarang(listBarang LB){
    adr_barang p = first(LB);
    if (first(LB) == NULL) {
        cout << "List Kosong " <<endl;
    }else {
        while (p != NULL){
            cout << "ID           : " << info(p).ID <<endl;
            cout << "Nama Barang  : " <<info(p).namaBarang << endl;
            cout << "Jumlah barang: " << info(p).kuantitas << endl;
            cout << " " << endl;
            p = next(p);
        }
        cout << endl;
    }
}
void showListRelasi(listRelation LR){
    adr_relation p = first(LR);
     if (first(LR) == NULL) {
        cout << "List Kosong " <<endl;
    }else {
        while (p != NULL){
            cout << "ID           : " << info(nextB(p)).ID <<endl;
            cout << "Nama Barang  : " << info(nextB(p)).namaBarang << endl;
            cout << "Jumlah barang: " << info(nextB(p)).kuantitas << endl;
            cout << " " << endl;
            p = next(p);
        }
        cout << endl;
    }
}

void showAllData(listPenyewa LP){
    adr_penyewa q = first(LP);
    if (first(LP) == NULL) {
        cout << "List Kosong " <<endl;
    }else {
        while (q != NULL){
            cout << "NAMA: " << info(q).nama << endl;
            cout << "NIK : " << info(q).NIK << endl;
            cout << "Tanggal Penyewaan   : " << info(q).tPenyewaan << endl;
            cout << "Tanggal Pengembalian: " << info(q).tPengembalian << endl;
             if (first(relasi(q)) != NULL) {
                cout << "Sedang menyewa " << HitungJumlahChild(LP,info(q).NIK) << " barang" << endl;
                showListRelasi(relasi(q));
            }else {
                cout << "Tidak ada barang yang disewa " << endl;
            }
            cout << " " << endl;
            q = next(q);
        }
    }
}


int showMenu() {
    int pilihan;
    system("cls");
    cout <<"=======================================" << endl;
    cout <<"   APLIKASI PENYEWAAN BARANG ELEKTRONIK    "<< endl;
    cout <<"           TELKOM UNIVERSITY           "<< endl;
    cout <<"======================================="<< endl;
    cout <<"1. Masukan data penyewa"<< endl;
    cout <<"2. Barang yang ingin disewa "<< endl;
    cout <<"3. Cari Data "<< endl;
    cout <<"4. Admin "<< endl;
    cout <<"0. Exit" << endl;
    cout <<"======================================="<< endl;
    cout << "Masukan Pilihan menu: ";

    int input = 0;
    cin >> input;

    cout << " " << endl;

    return input;

}

int showAdmin(){
    int pilihan;
    system("cls");
    cout <<"=======================================" << endl;
    cout <<"                  ADMIN                "<< endl;
    cout <<"======================================="<< endl;
    cout <<"1. Memasukan Data Barang "<< endl;
    cout <<"2. Menampilkan List Penyewa "<< endl;
    cout <<"3. Menampilkan List Barang "<< endl;
    cout <<"4. Menampilkan Semua Data "<< endl;
    cout <<"5. Hapus Data "<< endl;
    cout <<"0. Exit " << endl;
    cout <<"======================================="<< endl;
    cout << "Masukan Pilihan menu: ";
    int input = 0;
    cin >> input;
    cout << " " << endl;
    return input;
}

int showCari(){
    int pilihan;
    system("cls");
    cout <<"=======================================" << endl;
    cout <<"               Pencarian               "<< endl;
    cout <<"======================================="<< endl;
    cout <<"1. Mencari Data Penyewa "<< endl;
    cout <<"2. Mencari Data Barang "<< endl;
    cout <<"0. Exit" << endl;
    cout <<"======================================="<< endl;
    cout << "Masukan Pilihan menu: ";
    int input = 0;
    cin >> input;
    cout << " " << endl;
    return input;
}

int showDelete(){
    int pilihan;
    system("cls");
    cout <<"=======================================" << endl;
    cout <<"               Hapus Data              "<< endl;
    cout <<"======================================="<< endl;
    cout <<"1. Hapus Data Penyewa"<< endl;
    cout <<"2. Hapus Data Barang "<< endl;
    cout <<"3. Hapus Data Barang yang Sedang Disewa " << endl;
    cout <<"0. Exit" << endl;
    cout <<"======================================="<< endl;
    cout << "Masukan Pilihan menu: ";
    int input = 0;
    cin >> input;
    cout << " " << endl;
    return input;
}


void sewaBarang(listPenyewa &P, listBarang B, int NIK, int ID){
    adr_penyewa p;
    adr_barang q;
    adr_relation r;
    listRelation L3;
    p = cariPenyewa(P,NIK);
    q = cariBarang(B,ID);
    if (p !=NULL and q !=NULL and info(q).kuantitas > 0){
        updateKuantitas(B, ID);
        r = alokasiRelasi(q);
        L3 = relasi(p);
        insertRelasi(L3,r);
        relasi(p) = L3;
        cout << "Barang berhasil disewa oleh " << info(p).nama << endl;
    } else {
        cout << "Penyewa atau barang tidak ditemukan atau stok habis." << endl;
    }
}

void inputAwal(listBarang &B){
    barang x;
    x.ID = 01;
    x.namaBarang = "SteelSeries Rival 600";
    x.kuantitas = 2;
    adr_barang P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 02;
    x.namaBarang = "SteelSeries Arctis Pro";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 03;
    x.namaBarang = "Asus ROG Zephyrus G14";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 04;
    x.namaBarang = "Lenovo ThinkPad X1 Carbon";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 05;
    x.namaBarang = "MacBook Pro";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 06;
    x.namaBarang = "Playstation 5";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 07;
    x.namaBarang = "Xbox Series X ";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 8;
    x.namaBarang = "Sony WH-1000XM4";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
    x.ID = 9;
    x.namaBarang = "Apple AirPods Pro";
    x.kuantitas = 2;
    P = alokasiBarang(x);
    insertBarang(B,P);
}

void updateKuantitas(listBarang &LB, int ID) {
    adr_barang B = cariBarang(LB, ID);
    if (B != NULL && info(B).kuantitas > 0) {
        info(B).kuantitas--;
    } else {
        cout << "Barang tidak ditemukan atau stok habis." << endl;
    }
}

adr_penyewa cariPenyewa(listPenyewa P, int NIK){
    adr_penyewa p = first(P);
    while (p!=NULL){
        if (info(p).NIK == NIK){
           return p;
        }
        p = next(p);
    }
    return NULL;
}


adr_barang cariBarang(listBarang B, int ID){
    adr_barang p = first(B);
    while (p!=NULL){
        if (info(p).ID == ID){
            return p;
        }
        p = next(p);
    }
    return NULL;
}

int HitungJumlahChild(listPenyewa LP,int NIK){
    int count = 0;
    adr_penyewa p = cariPenyewa(LP,NIK);
    adr_relation q = first(relasi(p));
    while (q != NULL) {
        q = next(q);
        count++;
    }
    return count;
}


void hapusDataChildfromParent(listPenyewa &LP,int NIK, int ID){
    adr_penyewa q = cariPenyewa(LP,NIK);
    if(q != NULL){
        delete_relasi(relasi(q),ID);
    }else{
        cout << " Data Tidak Ditemukan" << endl;
    }
}
