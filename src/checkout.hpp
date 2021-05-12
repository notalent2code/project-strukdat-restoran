// file header untuk menu checkout

// fungsi untuk checkout pesanan
void menuCheckout(){
    int cash, change;
    system("cls");
    printBatas();
    cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t\t     Menu Checkout Pesanan\n";
    
    if (queueCheckout.empty()){
        cout << "Tidak ada pesanan yang diproses !\n";
        return;
    }
    else {
        DataPelanggan *poppedPelanggan = nullptr;
        cout << "Detail Pesanan\n";
        queueCheckout.dequeue(poppedPelanggan)->printDataPelanggan();
        while(true){
            printBatas();
            cout << "Cash\t: Rp ";
            cin >> cash;
            if (!cin.fail() && (cash > 0 && cash >= poppedPelanggan->biayaTotal())){
                break;
            }
            fail();
            cout << "Input salah !\n";
        }
        change = 0;
        change = cash - poppedPelanggan->biayaTotal();
        if (change > 0){
            cout << "Change\t: Rp " << change << "\n";
        }
        salesReport.pushListReport(poppedPelanggan);                    
    }
}