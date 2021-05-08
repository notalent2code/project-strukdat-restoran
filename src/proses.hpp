// file header untuk memproses pesanan pada antrian

// fungsi untuk memproses pesanan berdasarkan prioritas
void menuProses(){
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Proses Pesanan\n";

    if (queuePelanggan.head == nullptr){
    cout << "Antrian kosong !\n";
    }
    else {
        DataPelanggan *pHelp = nullptr;
        dequeueAntrian(pHelp);
        stackCheckout.pushStackCheckout(pHelp);
        cout << "Detail pesanan\n";
        printBatas();
        pHelp->printDataPelanggan();
        printBatas();
        cout << "Pesanan dengan No. Order : " << pHelp->nomorOrder <<
                " telah diproses !\n";
    }
}