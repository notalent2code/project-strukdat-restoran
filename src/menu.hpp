// file header untuk fungsi menu utama


// struct menu utama
struct Menu {
    int select;
    // enum untuk select menu
    enum enumMenu {
        ANTRIAN = 1,
        PROSES,
        CHECKOUT,
        REPORT,
        UPDATE,
        TUTORIAL,
        UNDO,
        REDO,
        EXIT
    };
    // constructor
    Menu(){
        select = 0;
    }
    // fungsi untuk menampilkan menu utama
    void display(){
        while(true){
            system("cls");
            printBatas();
            cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
            printBatas();
            cout << "\t\t\t\t  Menu Utama\n";
            cout << "1. Antrian Pesanan\n"
                 << "2. Proses Pesanan\n"
                 << "3. Checkout\n"
                 << "4. Laporan Penjualan\n"
                 << "5. Update Stok Makanan\n"
                 << "6. Cara Penggunaan Program\n"
                 << "7. Undo\n"
                 << "8. Redo\n"
                 << "9. Exit Program\n";
            printBatas();
            cout << "Masukkan pilihan (1-9) : "; 
            cin >> select;

            switch(select){
                case ANTRIAN:
                    menuAntrian();
                    break;
                case PROSES:
                    menuProses();
                    break;
                case CHECKOUT:
                    menuCheckout();
                    break;
                case REPORT:
                    menuReport();
                    break;
                case UPDATE:
                    menuUpdate();
                    break;
                case TUTORIAL:
                    menuTutorial();
                    break;
                case UNDO:
                    _undo();
                    break;
                case REDO:
                    _redo();
                    break;                    
                case EXIT:
                    dealloc();
                    cout << "Program selesai !";
                    exit(0);
                    break;
                default:
                    if (cin.fail()){
                        fail();
                    }
                    cout << "Input salah !\n";
            }
            system("pause");
        }
    }
}menu;