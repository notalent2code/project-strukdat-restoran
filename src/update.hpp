// file header untuk update stok hidangan

// fungsi untuk cek stok hidangan
void cekStok(){
    // print data hidangan
    printMenu();
}

// fungsi untuk update stok hidangan
void updateStok(){
    int select, stok;
    printMenu();
    while(true){
        cout << "Pilih hidangan (1-10) : ";
        cin >> select;
        if(cin.fail()){
                fail();
                cout << "Input salah !\n";
                continue;
            }

        if (select < 1){
            cout << "Input salah !\n";
            continue;
        }     
        else {
            while(true){
                cout << "Tambahkan berapa ? : ";
                stok = 0;
                cin >> stok;
                if (!cin.fail() && stok > 0){
                    menuHidanganRestoran[select]->stok += stok;
                    printBatas();
                    cout << "Penambahan stok " << menuHidanganRestoran[select]->nama << " sebanyak " << stok << " pcs berhasil !\n";
                    break;
                }
                fail();
                cout << "Input salah !\n";
            }
            break;
        }
    }
}

// fungsi untuk menampilkan pilihan menu update
void menuUpdate(){
    enum enumMenuUpdate{
        CEK = 1,
        UPDATE
    };
    system("cls");
    printBatas();
    cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t\t       Menu Update Stok\n"
         << "1. Cek Stok Hidangan\n"
         << "2. Update Stok Hidangan\n";
         printBatas();
    int select;
    cout << "Masukkan pilihan (1-2) : ";
    cin >> select;
    printBatas();
    switch (select){
        case CEK:
            cekStok();
            break;
        case UPDATE:
            updateStok();
            break;
        default:
            if (cin.fail()){
                fail();
            }
            cout << "Input salah !\n";
    }
}