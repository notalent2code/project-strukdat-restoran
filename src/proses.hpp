// file header untuk memproses pesanan pada antrian

// fungsi untuk memproses pesanan berdasarkan prioritas
void menuProses(){
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Proses Pesanan\n";

    if (queuePelanggan.head == nullptr) {
    cout << "Antrian kosong !\n";
    }
    else {
        DataPelanggan *helpAntrian = nullptr;
        dequeueAntrian(helpAntrian);
        stackCheckout.pushStackCheckout(helpAntrian);
        cout << "Pesanan dengan No. Order : " << helpAntrian->nomorOrder <<
                " telah diproses !\n";
    }
}