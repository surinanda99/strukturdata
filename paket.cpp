#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



int datake=1;
int maks=2;
struct paket
{
    char jenis_brg[30];
    char nama_pengirim[30];
    int berat;
    char kota[30];

};

struct paket kirim[2];

/*******************************************/
void bersihlayar()
{
    for(int m=0;m<80;m++)
    {
        for(int n=0;n<=24;n++)
        {
            gotoxy(m,n);cout<<" ";
        }
    }
}

void tambahdata()
{
    if(datake <= maks){
        gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
        cin>>kirim[datake].jenis_brg;
        gotoxy(20,16);cout<<"Inputkan Nama Pengirim   :";
        cin>>kirim[datake].nama_pengirim;
        gotoxy(20,17);cout<<"Inputkan Berat           :";
        cin>>kirim[datake].berat;
        gotoxy(20,18);cout<<"Inputkan Kota Tujuan     :";
        cin>>kirim[datake].kota;
        datake++;
    }else{
        gotoxy(20,14);cout << "Data Penuh" << endl;
    }
}

void tampildata()
{
    gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int m=1; m<datake; m++){
        gotoxy(40,19-a);
        cout<<m<<" ";
        cout<<kirim[m].jenis_brg<<" ";
        cout<<kirim[m].nama_pengirim<<" ";
        cout<<kirim[m].berat<<" ";
        cout<<kirim[m].kota<<endl;

    }
    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void hapusdata()
{
    if(datake>1){
        gotoxy(40,12);
        cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
        gotoxy(40,13);
        cout<<kirim[datake].jenis_brg<<" ";
        cout<<kirim[datake].nama_pengirim<<" ";
        cout<<kirim[datake].berat<<" Kg ";
        cout<<kirim[datake].kota<<endl<<endl;
        datake--;
    }else{
        gotoxy(40,12);cout << "Data Kosong" << endl;
    }
    gotoxy(40,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. Tambah Data";
        gotoxy(1,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(1,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(1,5);cout<<"9. Keluar"<<endl;

        gotoxy(1,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1){ /*Menambah data baru diletakan di DATAKE*/
                tambahdata();
            }
        if(pilih==2){ /*Menghapus Data Terakhir */
                hapusdata();
            }
        if(pilih==3) /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata();

    }
    while(pilih!=9);
    return 0;
}
