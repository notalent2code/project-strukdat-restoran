// file header untuk update stok hidangan

// fungsi untuk cek stok hidangan
void cekStok(){
    int size = sizeof(::detail.hidangan)/sizeof(::detail.hidangan[0]);
    // print data hidangan
    cout << "No. " << setw(22) << left << "Nama Hidangan" << setw(2) << left << "Stok\t   "<< "Harga\n";
    for (int i=1; i<size; i++){
        cout << setw(4) << left << i << setw(22) << left << ::detail.hidangan[i] << setw(2) << ::detail.stok[i] 
             << " pcs " << "  Rp " << ::detail.harga[i] << "\n";
    }
}

// fungsi untuk update stok hidangan
void updateStok(){
    int select, stok;
    int size = sizeof(::detail.hidangan)/sizeof(::detail.hidangan[0]);
    cout << "No. " << setw(22) << left << "Nama Hidangan" << setw(2) << left << "Stok\t   "<< "Harga\n";
    for (int i=1; i<size; i++){
        cout << setw(4) << left << i << setw(22) << left << ::detail.hidangan[i] << setw(2) << ::detail.stok[i] 
             << " pcs " << "  Rp " << ::detail.harga[i] << "\n";
    }
    printBatas();
    while(true){
        cout << "Pilih hidangan (1-10) : ";
        cin >> select;
        if (!cin.fail() && select < ::detail.NASI && select > ::detail.AIR){
            cout << "Input salah !\n";
            break;
        }
        else if (!cin.fail() && (select >= ::detail.NASI && select <= ::detail.AIR)){
            while(true){
                cout << "Tambahkan berapa ? : ";
                stok = 0;
                cin >> stok;
                if (!cin.fail() && stok > 0){
                    ::detail.stok[select] += stok;
                    printBatas();
                    cout << "Penambahan stok " << ::detail.hidangan[select] << " sebanyak " << stok << " pcs berhasil !\n";
                    break;
                }
                fail();
                cout << "Input salah !\n";
            }
            break;
        }
        fail();
        cout << "Input salah !\n";
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