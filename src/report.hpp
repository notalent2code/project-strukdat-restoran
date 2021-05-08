// file header untuk laporan penjualan

// fungsi untuk traversal laporan penjualan
void menuReport(){
    if (::salesReport.listPelanggan == nullptr){
        system("cls");
        printBatas();
        cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
        printBatas();
        cout << "\t\t  Menu Laporan Penjualan\n";
        cout << "Laporan penjualan kosong !\n";
        return;
    }
    char select;
    int nomorOrder, flag = 0;
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Laporan Penjualan\n";
    salesReport.traversalReport();
    printBatas();
    cout << "Lihat detail ? (Y/N) : ";
    cin >> select;
    if (!cin.fail() && (select == 'Y' || select == 'y')){       
        while (true){
        cout << "Masukkan nomor order : ";
        cin >> nomorOrder;
            if (!cin.fail() && nomorOrder > 0){
                break;
            }
            else {
                fail();
                cout << "Input salah !\n"; 
            }
        }
        DataPelanggan *pHelp = ::salesReport.listPelanggan;
        while (pHelp != nullptr){
            if (pHelp->nomorOrder == nomorOrder){
                system("cls");
                printBatas();
                cout << "\t\t\tDetail Pesanan\n";
                printBatas();
                pHelp->printDataPelanggan();
                flag = 1;
            }
            pHelp = pHelp->next;
        }
        if (flag == 0){
            cout << "Nomor order tidak tersedia !\n";
        }
    }
}