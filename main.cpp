#include <iostream>
#include "helper.h"
using namespace std;

//deklarasi array dan index
string nama_barang [10];
int harga_barang [10];
int stok_barang [10];
int index = -1;

void view_header(){
    println("-----------------------------");
    println("PROGRAM KASIR SEDERHANA 2022");
    println("-----------------------------");
}

void view_menu(){
    println("MENU PROGRAM");
    println("1. view all BARANG");
    println("2. tambah BARANG");
    println("3. delete BARANG");
    println("4. update stok BARANG");
    println("5. EXIT");
}

void tambah_barang(){
    index ++;
    println("masukkan nama barang : ");
    cin>>nama_barang[index];
    println("masukkan harga barang : ");
    cin>>harga_barang[index];
    println("masukkan stok awal : ");
    cin>>stok_barang[index];
    println("input success");
}


void tambah_barang_static(string nama, int harga, int stok){
    index ++;
    nama_barang[index] = nama;
    harga_barang[index] = harga;
    stok_barang[index] = stok;
}
void view_barang(){
    cout<<"list barang"<<endl;
    for(int i=0 ;i<=index;i++){
        cout<<"nama barang : "<<nama_barang[i]<<endl;
        cout<<"harga barang : "<<harga_barang[i]<<endl;
        cout<<"stok barang : "<<stok_barang[i]<<endl;
    }
}
void data_barang_static(){
    //data input static barang
    tambah_barang_static("odol",5000,10);
    tambah_barang_static("sabun",3000,5);
    tambah_barang_static("shampo",18000,8);
    tambah_barang_static("sikat",10000,4);
    tambah_barang_static("detergen",5500,3);
}
int search_by_name(string name){
    int temp_index = -1;
    for (int i = 0 ; i <= index ; i++){
        if (name == nama_barang[i]){
            temp_index = i;
        }
    }
    return temp_index;
}

void update_barang(){
    println("masukkan nama barang yang akan di update : ");
    string nama;
    cin>>nama;
    int temp_index = search_by_name(nama);
    cout<<"masukkan stok baru : ";
    cin>>stok_barang[temp_index];
}

int main() {
    view_header();
    data_barang_static();

    int pilih;
    while (pilih != 5){
        view_menu();
        print("masukkan pilihan menu : ");
        cin>>pilih;
        switch (pilih) {
            case 1:
                println("menu view barang");
                cout<<"cek index : "<<index;
                view_barang();
                break;
            case 2:
                println("menu insert barang");
                tambah_barang();
                break;
            case 3:
                println("menu transaksi baru");
                break;
            case 4:
                println("menu update barang");
                update_barang();
                break;
            case 5:
                println("menu EXIT");
                break;
        }
    }
    return 0;
}