#include <iostream>

using namespace std;

class dataPembeli
{
public:

    string nama;
    string kode;
    string status;

    dataPembeli(string inputNama, string inputKode, string inputStatus)
    {
        nama = inputNama;
        kode = inputKode;
        status = inputStatus;
    }
    void display()
    {
        cout<< "Kode pembeli : "<<kode<<endl;
        cout<< "Nama pembeli : " <<nama<<endl;
        cout<< "Status pembeli : "<<status<<endl<<endl;

    }
};

class dataBarang
{
public:

    string nama;
    string kode;
    int harga;

    dataBarang(string inputNama, string inputKode, int inputHarga)
    {
        nama = inputNama;
        kode = inputKode;
        harga = inputHarga;
    }
    void display()
    {
        cout<<kode;
        cout<< "                  "<<nama;
        cout<< "              "<<harga<<endl;

    }
};

int main()
{
    dataPembeli pembeli1 = dataPembeli("Diana", "P001", "Member");
    dataPembeli pembeli2 = dataPembeli("Rina", "P002", "Bukan Member");
    dataPembeli pembeli3 = dataPembeli("Lina", "P003", "Bukan Member");
    dataPembeli pembeli4 = dataPembeli("Doni", "P004", "Member");
    dataPembeli pembeli5 = dataPembeli("Dodi", "P005", "Member");

    dataBarang barang1 = dataBarang("Pensil   ", "BRG001", 2500);
    dataBarang barang2 = dataBarang("Buku Tulis", "BRG002", 3500);
    dataBarang barang3 = dataBarang("Penghapus", "BRG003", 1000);
    dataBarang barang4 = dataBarang("Penggaris", "BRG004", 1500);
    dataBarang barang5 = dataBarang("Ballpoint  ", "BRG005", 2500);

    string kode;
    string kodeBarang[100];
    int a = 0;
    int totalHarga = 0, hargaDiskon = 0, bayar = 0;
    int potHarga = 300;
    bool isRunning = true;

    cout<< "==========================================================="<<endl;
    cout<< "============== SELAMAT DATANG DI JAYA STORE ==============="<<endl;
    cout<< "===========================================================\n"<<endl;

    cout<< "Masukkan kode pembeli : ";
    cin>>kode;

    while(isRunning)
    {
        int jumlah;
        string pil;
        char confirm;
        cout<< "Input kode barang ke-"<<a+1<< " : ";
        cin>>pil;
        if(pil == "brg001" || "brg002" || "brg003" || "brg004" || "brg005" ) kodeBarang[a] = pil;
        else
        {
            cout<< "Input anda salah!!";
            exit(0);
        }
        a++;
        cout<< "Tambah barang atau tidak ? (y/t) : ";
        cin>>confirm;
        isRunning = (confirm == 't')? false : true;
    }

    cout<< "\nKode Barang            Nama Barang            Harga Barang"<<endl;
    cout<< "=========================================================="<<endl;
    for(int i = 0; i <= a; i++ )
    {
        if(kodeBarang[i] == "brg001")
        {
            barang1.display();
            totalHarga += barang1.harga;
        }
        else if(kodeBarang[i] == "brg002")
        {
            barang2.display();
            totalHarga += barang2.harga;
        }
        else if(kodeBarang[i] == "brg003")
        {
            barang3.display();
            totalHarga += barang3.harga;
        }
        else if(kodeBarang[i] == "brg004")
        {
            barang4.display();
            totalHarga += barang4.harga;
        }
        else if(kodeBarang[i] == "brg005")
        {
            barang5.display();
            totalHarga += barang5.harga;
        }
    }

    cout<< "=========================================================="<<endl;


    cout<< "                                        Total harga : "<<totalHarga<<endl;

    if(kode == "p001" || kode == "p004" || kode == "p005" )
    {
       hargaDiskon = totalHarga/10;
       cout<< "                                  Diskon member 10% : "<<hargaDiskon<<endl;
    }
    else hargaDiskon = 0;

    if(a > 3) cout<< "                       Potongan harga barang >3 pcs : "<<potHarga<<endl;
    else potHarga = 0;

    totalHarga = totalHarga - hargaDiskon - potHarga;
    cout<< "                                        Total harga : "<<totalHarga<<endl;
    cout<< "                                        Uang anda   : "; cin>>bayar;
    if (bayar < totalHarga) cout<< "Uang anda tidak cukup!!"<<endl;
    else
    {
        bayar -= totalHarga;
        cout<< "                                        Kembali     : "<<bayar<<endl<<endl;
    }
    if(kode == "p001")
    {
        pembeli1.display();
    }
    else if(kode == "p002")
    {
        pembeli2.display();
    }
    else if(kode == "p003")
    {
        pembeli3.display();
    }
    else if(kode == "p004")
    {
        pembeli4.display();
    }
    else if(kode == "p005")
    {
        pembeli5.display();
    }
    else
    {
        cout<< "Inputan Anda salah!!"; exit(0);
    }

    cout<< "=============== TERIMA KASIH ===============";






}
