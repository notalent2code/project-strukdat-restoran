// file header untuk fungsi antrian pesanan






// fungsi untuk traversal antrian
void traversalAntrian(){
    if (queuePelanggan.head == nullptr){
        cout << "Antrian kosong !\n";
    } else {
        system("cls");
        printBatas();
        cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
        printBatas();
        cout << "\t\t\t      Menu Antrian Pesanan\n";
        for(int count = 0;queuePelanggan[count];count++) {
            printBatas();
            cout << "Antrian ke-" << count+1 << "\n";
            printBatas();
            queuePelanggan[count]->printDataPelanggan();
        }
    }
}

// fungsi untuk melihat detail pesanan 
void detailPesanan(){
    int nomorOrder;
    int flag = 0;
    while (true){
        cout << "Masukkan nomor order : ";
        cin >> nomorOrder;
        if (!cin.fail() && nomorOrder > 0){
            break;
        }
        fail();
        cout << "Input salah !\n";        
    }
    DataPelanggan *pHelp = queuePelanggan.head;
    if (pHelp == nullptr){
        system("cls");
        printBatas();
        cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
        printBatas();
        cout << "\t\t\t      Menu Detail Pesanan\n";
        cout << "Antrian kosong !\n";
    }
    else {
        while(pHelp != nullptr){
            if (pHelp->nomorOrder == nomorOrder){
                flag = 1;
                system("cls");
                printBatas();
                cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
                printBatas();
                cout << "\t\t\t      Menu Detail Pesanan\n";
                pHelp->printDataPelanggan();
                printBatas();
                break;
            } else {
                pHelp=pHelp->next;
            }
        }
        if (flag == 0){
            cout << "Nomor order tidak tersedia !\n";
        }
    }
}

// fungsi untuk menu antrian pesanan
void menuAntrian(){
    DataPelanggan *newPelanggan = new DataPelanggan;
    enum enumMenuAntrianPesanan{
        TAMBAHPESANAN = 1,
        LIHATANTRIAN,
        PRINTDETAIL
    };
    system("cls");
    printBatas();
        cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
        printBatas();
        cout << "\t\t\t      Menu Antrian Pesanan\n"
            "1. Tambah Pesanan\n"
            "2. Lihat Antrian\n"
            "3. Cetak Detail Pesanan\n";
            printBatas();
    int select;           
    cout << "Masukkan pilihan (1-3) : ";
    cin >> select;
    printBatas();
    switch (select){
        case TAMBAHPESANAN:
            newPelanggan->insertDataPelanggan();
            queuePelanggan.priority_enqueue(newPelanggan);
            break;
        case LIHATANTRIAN:
            traversalAntrian();
            break;
        case PRINTDETAIL:
            detailPesanan();
            break;
        default:
            if (cin.fail()){
                fail();
            }
            cout << "Input salah !\n";
    }
}
