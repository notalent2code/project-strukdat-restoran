// file header untuk struct
// struct untuk menyimpan data jenis layanan
struct Layanan {
    // enum untuk kode layanan
    enum enumLayanan {
        REGULER = 1,
        VIP
    };
    // array untuk nama layanan
    string nama[3] = {
        "Undefined",
        "Reguler",
        "VIP"
    };
}layanan;

// struct untuk menyimpan detail data hidangan
struct detailHidangan {
    // enum untuk jenis hidangan
    enum enumHidangan {
        NASI = 1,
        AYAM,
        IKAN,
        UDANG,
        CUMI,
        KERANG,
        KEPITING,
        JUS,
        ICECREAM,
        AIR
    };
    // array untuk nama hidangan
    string hidangan[11] = {
        "Undefined",
        "Nasi Goreng",
        "Ayam Bakar",
        "Ikan Nila Goreng",
        "Udang Telur Asin",
        "Cumi Goreng Tepung",
        "Kerang Dara Rebus",
        "Kepiting Saus Tiram",
        "Jus Jeruk",
        "Ice Cream",
        "Air Mineral"
    };
    // array untuk stok masing-masing hidangan
    int stok[11] = {
        0,
        19,
        20,
        25,
        23,
        32,
        21,
        30,
        27,
        22,
        35
    };
    // array untuk harga masing-masing hidangan 
    float harga[11] = {
        0,
        20000,
        25000,
        22000,
        38000,
        45000,
        48000,
        175000,
        15000,
        12000,
        5000
    };
    // array untuk menyimpan kuantitas hidangan yg dipesan
    int quantity[11] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
    };
}detail;


// struct untuk menyimpan data detail
struct Hidangan {
    int nomorOrder;
    int select;
    int quantity;
    string namaHidangan;
    float harga = 0;
    float subtotal = 0;
    Hidangan *next;

    // constructor
    Hidangan(){
        next = nullptr;
    }

    // fungsi untuk insert data hidangan
    void insertDataHidangan(int globalNomorOrder){
        nomorOrder = globalNomorOrder;
        // variabel untuk menyimpan banyaknya hidangan
        int size = sizeof(::detail.hidangan)/sizeof(::detail.hidangan[0]);
        // print data hidangan
        cout << "No. " << setw(22) << left << "Nama Hidangan" << setw(2) << left << "Stok\t   "<< "Harga\n";
        printBatas();
        for (int i=1; i<size; i++){
            cout << setw(4) << left << i << setw(22) << left << ::detail.hidangan[i] << setw(2) << ::detail.stok[i] 
                 << " pcs " << "  Rp " << ::detail.harga[i] << "\n";
        }
        printBatas();
        while (true){
            cout << "Pilih hidangan (1-10) : ";
            cin >> select;
            if (!cin.fail() && select < ::detail.NASI && select > ::detail.AIR){
                cout << "Input salah !\n";
                break;
            }            
            else if (!cin.fail() && (select >= ::detail.NASI && select <= ::detail.AIR)){
                if (::detail.stok[select] == 0){
                quantity = 0;
                cout << "Stok hidangan habis !\n";
                break;
                }
                while (true){
                    cout << "Berapa banyak ? : ";
                    cin >> quantity;
                    if (!cin.fail() && (quantity > 0 && quantity <= ::detail.stok[select])){
                        ::detail.quantity[select] = quantity;
                        namaHidangan = ::detail.hidangan[select];
                        quantity = ::detail.quantity[select];
                        harga = ::detail.harga[select]; 
                        subtotal = quantity * harga;                          
                        ::detail.stok[select] -= quantity;
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
};

// struct untuk menyimpan data pelanggan
struct DataPelanggan {
    int nomorOrder;
    string nama;
    string timestamp;
    int layanan;
    float biayaLayanan;
    float totalBiaya;
    Hidangan *listHidangan;
    DataPelanggan *next;

    // constructor
    DataPelanggan(){
        nomorOrder = globalNomorOrder;
        listHidangan = nullptr;
        next = nullptr;
    }

    // fungsi untuk generate timestamp
    string getTime(){
        time_t curr_time;
	    curr_time = time(0);
	    return ctime(&curr_time);
    }

    // fungsi untuk insersi data pelanggan
    void insertDataPelanggan(){
        int count = 1;
        char decision;
        cin.ignore();
        cout << "Masukkan nama pelanggan : ";
        getline(cin, nama);
        printBatas();
        timestamp = getTime();
        cout << "Jenis layanan :\n";
        for (int i=1; i<=2; i++){
            cout << i << " - " << ::layanan.nama[i] <<"\n";
        }
        printBatas();
        while (true){
            cout << "Pilih jenis layanan : ";
            cin >> layanan;
            if (!cin.fail() && (layanan == ::layanan.REGULER || layanan == ::layanan.VIP)){
                break;
            }
            fail();
            cout << "Input salah !\n";
        }
        while (true){
            system("cls");
            printBatas();
            cout << "\t\t\t   SISTEM PELAYANAN RESTORAN\n";
            printBatas();
            cout << "\t\t\t      Menu Tambah Pesanan\n";
            printBatas();
            cout << "Pilih hidangan ke-" << count << "\n";
            printBatas();
            insertListHidangan();
            printBatas();
            cout << "Tambah hidangan lain ? (Y/N) : ";
            cin >> decision;
            if (decision=='Y' || decision=='y'){                
                count ++;
                continue;
            }
            else {
                system("cls");
                printBatas();
                cout << "\t\t\t\tDetail Pesanan\n";
                printBatas();
                printDataPelanggan();
                printBatas();
                break;
            }
        }
        globalNomorOrder++;
    }

    // fungsi untuk insersi list hidangan masing-masing pelanggan
    void insertListHidangan(){
        Hidangan *newHidangan = new Hidangan;
        newHidangan->insertDataHidangan(nomorOrder);
        if (listHidangan == nullptr){
            listHidangan = newHidangan;
        }
        else {
            Hidangan *pHelp = listHidangan;
            while (pHelp->next != nullptr){
                pHelp = pHelp->next;
            }
            pHelp->next = newHidangan;
        }
    }

    // fungsi untuk traversal data hidangan
    void traversalHidangan(){
        Hidangan *pHelp = listHidangan;
        while (pHelp != nullptr){
            if (pHelp->quantity == 0){
                pHelp = pHelp->next;
            }
            else{
            cout << "\t\t\t  " << setw(22) << left << pHelp->namaHidangan << setw(2) << left << pHelp->quantity
                 << " pcs   @Rp " << setw(6) << pHelp->harga << " = Rp " << fixed << setprecision(0) << setw(6) << left << pHelp->subtotal << "\n";
            pHelp = pHelp->next;
            }
        }
    }

    // fungsi untuk menghitung total biaya int layanan, float subtotal
    void countTotal(float &biayaLayanan, float &totalBiaya){
        biayaLayanan = 0;
        totalBiaya = 0;
        Hidangan *pHelp = listHidangan;
        while (pHelp != nullptr){
            totalBiaya += pHelp->subtotal;
            pHelp = pHelp->next;
            
        }
        if (layanan == ::layanan.VIP){
            biayaLayanan = totalBiaya * 0.1;
        }
        totalBiaya += biayaLayanan;
    }

    // fungsi untuk print data pelanggan
    void printDataPelanggan(){
        cout << "Nomor Order\t\t: " << nomorOrder << "\n";
        cout << "Nama Pelanggan\t\t: " << nama << "\n";
        cout << "Layanan\t\t\t: " << ::layanan.nama[layanan] << "\n";
        cout << "Tanggal Transaksi\t: " << timestamp;
        cout << "Hidangan yang dipesan\t: \n";
        traversalHidangan();
        countTotal(biayaLayanan, totalBiaya);
        printBatas();
        cout << "Subtotal\t\t: Rp " << fixed << setprecision(0) << totalBiaya - biayaLayanan << "\n";
        cout << "Biaya Layanan\t\t: Rp " << biayaLayanan << "\n";
        cout << "Total Biaya\t\t: Rp " << fixed << setprecision(0) << totalBiaya<< "\n";
    }
}pelanggan;

// struct untuk menyimpan data antrian pelanggan
struct antrianPelanggan {
    DataPelanggan *head;
    DataPelanggan *tail;

    // constructor
    antrianPelanggan(){
        head = nullptr;
        tail = nullptr;
    }
}queuePelanggan;
    
// struct untuk menyimpan data pembayaran
struct stackCheckout {
    DataPelanggan *listPelanggan;

    // constructor
    stackCheckout(){
        listPelanggan = nullptr;
    }

    // fungsi untuk push ke stack checkout dari popped queue
    void pushStackCheckout(DataPelanggan *&poppedPelanggan){
        if (listPelanggan == nullptr){
            listPelanggan = poppedPelanggan;
        }
        else {
            poppedPelanggan->next = listPelanggan;
            listPelanggan = poppedPelanggan;
        }
    }

    //fungsi untuk pop stack checkout
    void popStackCheckout(DataPelanggan *&poppedPelanggan){
        if (listPelanggan == nullptr){
            poppedPelanggan = nullptr;
        }
        else {
            poppedPelanggan = listPelanggan;
            listPelanggan = listPelanggan->next;
            poppedPelanggan->next = nullptr;
        }
    }
}stackCheckout;

// struct untuk menyimpan laporan penjualan
struct salesReport {
    DataPelanggan *listPelanggan;

    // constructor
    salesReport(){
        listPelanggan = nullptr;
    }

    // fungsi untuk push ke single list laporan penjualan
    void pushListReport(DataPelanggan *&poppedPelanggan){
        if (listPelanggan == nullptr){
            listPelanggan = poppedPelanggan;
        }
        else {
            DataPelanggan *pHelp = listPelanggan;
            while (pHelp->next != nullptr){
                pHelp = pHelp->next;
            }
            pHelp->next = poppedPelanggan;
        }
    }
    
    // fungsi untuk traversal laporan penjualan
    void traversalReport(){
    DataPelanggan *pHelp = listPelanggan;
    string namaLayanan;
    int count = 1;
        if (listPelanggan == nullptr){
            cout << "Laporan penjualan kosong !\n";
        } else {
            cout << "Nomor\tNo. Order\tNama Pelanggan\t\tLayanan\t\tTotal Biaya\n";
            while(pHelp != nullptr){
                string namaLayanan = ::layanan.nama[pHelp->layanan];
                printBatas();
                cout << setw(8) << left << count << setw(16) << left << pHelp->nomorOrder
                     << setw(24) << left << pHelp->nama << setw(16) << left << namaLayanan
                     << "Rp "<< fixed << setprecision(0) << setw(6) << left << pHelp->totalBiaya << "\n";
                pHelp = pHelp->next;
                count++;
            }
        }
    }
}salesReport;