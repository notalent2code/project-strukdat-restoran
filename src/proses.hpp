// file header untuk memproses pesanan pada antrian

// fungsi untuk memproses pesanan berdasarkan prioritas
void menuProses(){
    system("cls");
    printBatas();
    cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t\t      Menu Proses Pesanan\n";

    if (queuePelanggan.head == nullptr){
    cout << "Antrian kosong !\n";
    }
    else {
        DataPelanggan *pHelp = nullptr;
        queuePelanggan.dequeue(pHelp);
        queueCheckout.enqueue(pHelp);
        printBatas();
        pHelp->printDataPelanggan();
        printBatas();
        cout << "Pesanan dengan No. Order : " << pHelp->nomorOrder <<
                " telah diproses !\n"
                "Harap segera lakukan checkout pesanan !\n";
    }
}