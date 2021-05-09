// file header untuk fungsi antrian pesanan

// fungsi untuk enqueue dengan skala prioritas
void enqueueAntrian(){
    DataPelanggan *newPelanggan = new DataPelanggan;
    newPelanggan->insertDataPelanggan();
    DataPelanggan *pPrev = nullptr;
    DataPelanggan *pHelp = queuePelanggan.head;
    if (queuePelanggan.head == nullptr && queuePelanggan.tail == nullptr){
        queuePelanggan.head = newPelanggan;
        queuePelanggan.tail = newPelanggan;
    }
    else {
        while (newPelanggan->layanan <= pHelp->layanan){
            if (pHelp->next == nullptr){
                break;
            }
        pPrev = pHelp;
        pHelp = pHelp->next;
        }
        if (pHelp == queuePelanggan.head && newPelanggan->layanan > pHelp->layanan){
            newPelanggan->next = pHelp;
            queuePelanggan.head = newPelanggan;
        }
        else if (pHelp == queuePelanggan.tail && newPelanggan->layanan <= pHelp->layanan){
            pHelp->next = newPelanggan;
            queuePelanggan.tail = newPelanggan;
        }
        else {
            pPrev->next = newPelanggan;
            newPelanggan->next = pHelp;
        }
    }
}

// fungsi untuk dequeue antrian
void dequeueAntrian(DataPelanggan *&temp){
    temp = queuePelanggan.head;
    if (queuePelanggan.head == nullptr && queuePelanggan.tail == nullptr){
        temp = nullptr;
    }
    else if (queuePelanggan.head->next == nullptr){
        queuePelanggan.head = nullptr;
        queuePelanggan.tail = nullptr;
    }
    else{
        temp = queuePelanggan.head;
        queuePelanggan.head = queuePelanggan.head->next; 
    }
    temp->next = nullptr;
}

// fungsi untuk traversal antrian
void traversalAntrian(){
    DataPelanggan *pHelp = queuePelanggan.head;
    int count = 1;
    if (queuePelanggan.head == nullptr){
        cout << "Antrian kosong !\n";
    } else {
        system("cls");
        printBatas();
        cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
        printBatas();
        cout << "\t\t\t      Menu Antrian Pesanan\n";
        do {
            printBatas();
            cout << "Antrian ke-" << count << "\n";
            printBatas();
            pHelp->printDataPelanggan();
            pHelp = pHelp->next;
            count++;
        } while(pHelp != nullptr);
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
            enqueueAntrian();
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
