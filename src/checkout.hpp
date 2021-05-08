// file header untuk menu checkout

// fungsi untuk checkout pesanan
void menuCheckout(){
    int nomorOrder, flag = 0;;
    int cash, change;
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Checkout Pesanan\n";
    
    DataPelanggan *pHelp = nullptr;
    pHelp = ::stackCheckout.listPelanggan;
    if (pHelp == nullptr){
        cout << "Tidak ada pesanan yang diproses !\n";
        return;
    }
    while(pHelp != nullptr){
        while(true){

            cout << "Masukkan nomor order : ";
            cin >> nomorOrder;
            printBatas();
            if (!cin.fail()){
                break;
            }
            fail();
            cout << "Input salah !\n";
        }
        if (pHelp->nomorOrder == nomorOrder){
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
            flag = 1;
            break;
        }
        pHelp = pHelp->next;
    }
    if (flag == 0) {
    cout << "No. Order tidak ada !\n";
    }
}