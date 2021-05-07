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
    
    while(true){
        system("cls");
        cout << "Masukkan nomor order : ";
        cin >> nomorOrder;
        if (!cin.fail()){
            break;
        }
        fail();
        cout << "Input salah !\n";
    }
    DataPelanggan *pHelp = ::stackCheckout.listPelanggan;
    while(pHelp->next != nullptr){
        if (pHelp->nomorOrder == nomorOrder){
            pHelp->printDataPelanggan();
            while(true){
                printBatas();
                cout << "Masukkan nominal pembayaran : ";
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
                cout << "Change : " << change << "\n";
            }

            flag = 1;
        }
        pHelp = pHelp->next;
    }
    if (flag == 0) {
    cout << "No. Order tidak ada !\n";
    }
}