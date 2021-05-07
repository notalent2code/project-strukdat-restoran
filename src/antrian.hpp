// file header untuk fungsi antrian pesanan

// fungsi untuk enqueue dengan skala prioritas
// #include "structs.h"
void enqueueAntrian(){
    DataPelanggan *newPelanggan = new DataPelanggan;
    // cin.ignore();
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
    // if (queuePelanggan.head == nullptr){
    //     queuePelanggan.head = newPelanggan;
    //     queuePelanggan.tail = newPelanggan;
    // } 
    // else {
    //     // priority queue
    //     DataPelanggan *pHelp = queuePelanggan.head;
    //     while(pHelp->next != nullptr){
    //         if(pHelp->next->layanan >= newPelanggan->layanan){
    //             pHelp = pHelp->next;
    //         } else {
    //             break;
    //         }
    //     }
    //     if ((pHelp == queuePelanggan.head) && (pHelp->layanan < newPelanggan->layanan)){
    //         newPelanggan->next = queuePelanggan.head;
    //         queuePelanggan.head = newPelanggan;
    //     } else if (pHelp->next != nullptr){
    //         newPelanggan->next = pHelp->next;
    //         pHelp->next = newPelanggan;
    //     } else {
    //         queuePelanggan.tail->next = newPelanggan;
    //         queuePelanggan.tail = newPelanggan;
    //     }
    // }
}

// fungsi untuk dequeue antrian
void dequeueAntrian(DataPelanggan *&temp){
    if (queuePelanggan.head == nullptr && queuePelanggan.tail == nullptr) {
        temp = nullptr;
    }
    else if (queuePelanggan.head->next == nullptr)  {
        queuePelanggan.head = nullptr;
        queuePelanggan.tail = nullptr;
    }
    else{
        temp = queuePelanggan.head;
        queuePelanggan.head = queuePelanggan.head->next; 
        temp->next = nullptr;
    }
    // temp = queuePelanggan.head;
    // if (queuePelanggan.head->next == nullptr){
    //     queuePelanggan.head = nullptr;
    //     queuePelanggan.tail = nullptr;
    // } else {
    //     queuePelanggan.head = queuePelanggan.head->next;
    // }
    // temp->next = nullptr;
}

// fungsi untuk cancel pesanan
// void cancelPesanan(){
//     system("cls");
//     int nomorOrder, flag = 0;
//     while (true){
//         cout << "Masukkan nomor order : ";
//         cin >> nomorOrder;
//         if (!cin.fail()){
//             break;
//         }
//         fail();
//         cout << "Input salah !\n";        
//     }
//     if (queuePelanggan.head == nullptr && queuePelanggan.tail == nullptr){
//         cout << "Antrian pesanan kosong !\n";
//         return;
//     }
//     else if (queuePelanggan.head->next == nullptr && queuePelanggan.head->nomorOrder == nomorOrder){
//         DataPelanggan *pDelete = queuePelanggan.head;
//         queuePelanggan.head == nullptr;
//         queuePelanggan.tail == nullptr;
//         flag = 1;
//     }
//     else{
//         DataPelanggan *pPrev = nullptr;
//         DataPelanggan *pDelete = nullptr;
//         DataPelanggan *pHelp = queuePelanggan.head;
//         while(pHelp->next != nullptr){
//             if (pHelp->next == queuePelanggan.tail && pHelp->next->nomorOrder == nomorOrder){
//                 pPrev = pHelp;
//                 pDelete = pPrev->next;
//                 queuePelanggan.tail = queuePelanggan.head;
//                 pPrev->next = nullptr;
//                 flag = 1;
//             }
//             else if (pHelp->next->nomorOrder == nomorOrder){
//                 pPrev = pHelp;
//                 pDelete = pPrev->next;
//                 pPrev->next = pHelp->next->next;
//                 pDelete->next = nullptr;
//                 flag = 1;
//             }
//             pHelp = pHelp->next;
//         }
//         delete pDelete;
//     }
//     if (flag == 1){
//         cout << "Pesanan dengan No. Order : " << nomorOrder << " telah dibatalkan !\n";
//     }
//     else {
//         cout << "Nomor order tidak ditemukan !\n";
//     }
// }

// fungsi untuk traversal antrian
void traversalAntrian(){
    DataPelanggan *pHelp = queuePelanggan.head;
    int count = 1;
    if (queuePelanggan.head == nullptr){
        cout << "Antrian kosong !\n";
    } else {
        system("cls");
        do {
            printBatas();
            cout << "\t\t  Antrian ke-" << count << "\n";
            printBatas();
            pHelp->printDataPelanggan();
            pHelp = pHelp->next;
            count++;
        } while(pHelp != nullptr);
    }
}

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
        cout << "Antrian kosong !\n";
    }
    else {
        while(pHelp != nullptr){
            if (pHelp->nomorOrder == nomorOrder){
                flag = 1;
                system("cls");
                printBatas();
                cout << "\t\t\tDetail Pesanan\n";
                printBatas();
                pHelp->printDataPelanggan();
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
    enum enumMenuAntrianPesanan
    {
        TAMBAHPESANAN = 1,
        BATALKANPESANAN,
        LIHATANTRIAN,
        PRINTDETAIL
    };
    int select;
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Antrian Pesanan\n"
            "1. Tambah Pesanan\n"
            "2. Batalkan Pesanan\n"
            "3. Lihat Antrian\n"
            "4. Cetak Detail Pesanan\n";
            printBatas();
    cout << "Masukkan pilihan (1-4) : ";
    cin >> select;
    printBatas();
    switch (select){
        case TAMBAHPESANAN:
            enqueueAntrian();
            break;
        case BATALKANPESANAN:
            // cancelPesanan();
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
