// file header untuk menu checkout

// fungsi untuk checkout pesanan
void menuCheckout(){
    int cash, change;
    system("cls");
    printBatas();
    cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t\t     Menu Checkout Pesanan\n";
    
    DataPelanggan *pHelp = ::stackCheckout.listPelanggan;
    if (pHelp == nullptr){
        cout << "Tidak ada pesanan yang diproses !\n";
        return;
    }
    else {
        cout << "Detail Pesanan\n";
        pHelp->printDataPelanggan();
        while(true){
            printBatas();
            cout << "Cash\t: Rp ";
            cin >> cash;
            if (!cin.fail() && (cash > 0 && cash >= pHelp->totalBiaya)){
                break;
            }
            fail();
            cout << "Input salah !\n";
        }
        change = 0;
        change = cash - pHelp->totalBiaya;
        if (change > 0){
            cout << "Change\t: Rp " << change << "\n";
        }
        DataPelanggan *poppedPelanggan = nullptr;
        stackCheckout.popStackCheckout(poppedPelanggan);
        salesReport.pushListReport(poppedPelanggan);                    
    }
}