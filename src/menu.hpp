// file header untuk fungsi menu utama

void _undo(){
    if(UndoStack.top){
        int code = UndoStack.top->undo();
        auto temp = UndoStack.pop();
        // cout<<"code"<< code;
        switch(code){
            case DELETE_PELANGGAN:
                globalNomorOrder++;
                break;
            case ADD_PELANGGAN:
                globalNomorOrder--;
                break;
            case 2:
                _undo();
                break;
            default:
                break;
        } 
        RedoStack.push(temp);
    }
}
void _redo(){
    if(RedoStack.top){
        int code = RedoStack.top->redo();
        auto temp = RedoStack.pop();
        switch(code){
            case DELETE_PELANGGAN:
                globalNomorOrder--;
                break;
            case ADD_PELANGGAN:
                globalNomorOrder++;
                break;
            case REPEAT:
                _redo();
                break;
            default:
                break;
        }
        UndoStack.push(temp);
    }
}
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
                 << "7. Exit Program\n"
                 << "8. Undo\n"
                 << "9. Redo\n";
            printBatas();
            cout << "Masukkan pilihan (1-7) : "; 
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
                case EXIT:
                    dealloc();
                    cout << "Program selesai !";
                    exit(0);
                    break;
                case 8:
                    _undo();
                    break;
                case 9:
                    _redo();
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