// file header untuk update stok hidangan

// fungsi untuk update stok hidangan
void cekStok(){
    int size = sizeof(::detail.hidangan)/sizeof(::detail.hidangan[0]);
    // print data hidangan
    cout << "Nama Hidangan\tStok\tHarga\n";
    for (int i=1; i<size; i++){
        cout << i << " - " << ::detail.hidangan[i] << " - " << ::detail.stok[i] << " pcs - " << " Rp " << ::detail.harga[i] << "\n";
    }
}

void updateStok(){
    int select, stok;
    int size = sizeof(::detail.hidangan)/sizeof(::detail.hidangan[0]);
    // print data hidangan
    cout << "Nama Hidangan\tStok\tHarga\n";
    for (int i=1; i<size; i++){
        cout << i << " - " << ::detail.hidangan[i] << " - " << ::detail.stok[i] << " pcs - " << " Rp " << ::detail.harga[i] << "\n";
    }
    printBatas();
    while(true){
        cout << "Pilih hidangan (1-3) : ";
        cin >> select;
        if (!cin.fail()){
            break;
        }
        fail();
        cout << "Input salah !\n";
    }
    if (!cin.fail() && select >= 1 && select <= 3){
        while(true){
            cout << "Tambahkan berapa ? : ";
            cin >> stok;
            if (!cin.fail() && stok > 0){
                ::detail.stok[select] += stok;
                break;
            }
            fail();
            cout << "Input salah !\n";
        }
    }
}

void menuUpdate(){
    enum enumMenuUpdate{
        CEK = 1,
        UPDATE
    };
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Update Stok\n"
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