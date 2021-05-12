// file header untuk laporan penjualan

// fungsi untuk traversal laporan penjualan
void menuReport(){
    if (::salesReport.listPelanggan.empty()){
        system("cls");
        printBatas();
        cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
        printBatas();
        cout << "\t\t\t    Menu Laporan Penjualan\n";
        printBatas();
        cout << "Laporan penjualan kosong !\n";
        return;
    }
    char select;
    int nomorOrder, flag = 0;
    system("cls");
    printBatas();
    cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t\t    Menu Laporan Penjualan\n";
    printBatas();
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
        for(int i=0;salesReport.listPelanggan[i];i++){
            if (salesReport.listPelanggan[i]->nomorOrder == nomorOrder){
                system("cls");
                printBatas();
                cout << "\t\t\t\tDetail Pesanan\n";
                printBatas();
                salesReport.listPelanggan[i]->printDataPelanggan();
                flag = 1;
            }
        }
        if (flag == 0){
            cout << "Nomor order tidak tersedia !\n";
        }
    }
}