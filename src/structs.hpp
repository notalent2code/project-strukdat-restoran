// file header untuk struct

// FUNGSI
// inisialisasi menu hidangan bawaan/preset
void _inisialisasiMenuPreset();
// print menu hidangan restoram
void printMenu();
// fungsi untuk generate timestamp
string getTime();

// STRUCT
// struct untuk menyimpan data jenis layanan
struct Layanan {
    //skala prioritas layanan, semakin besar semakin didahulukan
    int priority;
    //nama layanan untuk di print
    string nama;
    //persenan biaya untuk layanan
    float biaya;

    //constructor
    Layanan(string Nama, int Biaya, int Priority){
        nama = Nama;
        biaya = Biaya;
        priority = Priority;
    }
};
// enum untuk kode layanan
enum enumLayanan {
        REGULER,
        VIP
    };
// daftar layanan yang tersedia
Layanan LAYANAN[2] = {
    Layanan("Reguler",0,REGULER),
    Layanan("VIP",0.1,VIP)
};

// struct untuk struktur data linked list
template<typename T>
struct List{
    // iterator untuk fungsi operator[]
    T *iterator = nullptr;
    // index untuk operator
    int iteratorIndex = 0;
    T *head = nullptr;

    // hapus semua isi list
    void clear(){
        T *pDelete;
        while(head){
            pDelete = head;
            head = head->next;
            free(pDelete);
        }
        delete pDelete;
    }
    // hapus node di index
    void remove(int index){
        T *pHelp = head, *pDelete = head;

        for(int i=0;i<index;i++){
            pHelp = pDelete;
            pDelete = pDelete->next;
        }
        pHelp->next = pDelete->next;
        delete pDelete;
    }
    // return true jika kosong
    bool empty(){
        if(head == nullptr) return true;
        return false;
    }
    // push back
    void push_back(T *NewNode){
        NewNode->next = nullptr;
        T *pHelp = head;

        if(!pHelp){
            head = NewNode;
            return;
        }
        while(pHelp->next){
            pHelp = pHelp->next;
        }
        pHelp->next = NewNode;
    }
    // push back
    void operator+=(T *NewNode){
        push_back(NewNode);
    }
    //return pointer ke node di index
    T* operator[](int index){
        if(index < 0) return nullptr;
        if(iteratorIndex > index || !iterator){ // jika iterator lebih dari index atau null 
            iteratorIndex = 0;
            iterator = head;
        }
        while(iteratorIndex < index && iterator != nullptr){
            iterator = iterator->next;
            iteratorIndex++;
        }
        return iterator;
    }
};

// struct untuk struktur data queue
template<typename T>
struct ListQueue{
    // iterator untuk fungsi operator[]
    T *iterator = nullptr;
    // index untuk operator
    int iteratorIndex = 0;
    T *head = nullptr;
    T *tail = nullptr;

    //destructor
    void clear(){
        T *pDelete;
        while(head){
            pDelete = head;
            head = head->next;
            free(pDelete);
        }
        delete pDelete;
    }
    //true if queue empty
    bool empty(){
        if(head == nullptr) return true;
        return false;
    }
    //fungsi untuk menghapus node pada index tertentu
    void remove(int index){
        T *pHelp = head, *pDelete = head;

        for(int i=0;i<index;i++){
            pHelp = pDelete;
            pDelete = pDelete->next;
        }
        pHelp->next = pDelete->next;
        delete pDelete;
    }
    // fungsi untuk enqueue dengan skala prioritas yang diambil dari fungsi priority() pada node
    void priority_enqueue(T *newNode){
        T *pPrev = nullptr;
        T *pHelp = head;
        if (head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
        }
        else {
            while (newNode->priority() <= pHelp->priority()){
                if (pHelp->next == nullptr){
                    break;
                }
            pPrev = pHelp;
            pHelp = pHelp->next;
            }
            if (pHelp == head && newNode->priority() > pHelp->priority()){
                newNode->next = pHelp;
                head = newNode;
            }
            else if (pHelp == tail && newNode->priority() <= pHelp->priority()){
                pHelp->next = newNode;
                tail = newNode;
            }
            else {
                pPrev->next = newNode;
                newNode->next = pHelp;
            }
        }
    }
    // fungsi untuk enqueue tanpa skala prioritas
    void enqueue(T *newNode){
        T *pPrev = nullptr;

        if (head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = nullptr;
        tail->next = newNode;
        tail = newNode;
    }
    // fungsi untuk dequeue antrian
    T *dequeue(T *&temp = nullptr){
        temp = head;
        if (head == nullptr && tail == nullptr){
            temp = nullptr;
        }
        else if (head->next == nullptr){
            head = nullptr;
            tail = nullptr;
        }
        else{
            temp = head;
            head = head->next; 
        }
        temp->next = nullptr;
        return temp;
    }
    //operator untuk memakai index
    T* operator[](int index){
        if(index < 0) return nullptr;
        if(iteratorIndex > index || !iterator){ // jika iterator lebih dari index atau null 
            iteratorIndex = 0;
            iterator = head;
        }
        while(iteratorIndex < index && iterator != nullptr){
            iterator = iterator->next;
            iteratorIndex++;
        }
        return iterator;
    }
};

// struct untuk menyimpan data hidangan dalam menu restoran
struct HidanganRestoran {
    int nomorOrder;
    //jumlah dalam stok
    int stok = 0;
    string nama;
    int harga = 0;
    HidanganRestoran *next = nullptr;

    // constructor
    HidanganRestoran(){
        next = nullptr;
    }
    // constructor lengkap
    HidanganRestoran(string Nama, int Stok, int Harga){
        next = nullptr;
        nama =  Nama;
        harga = Harga;
        stok = Stok;
    }
};
// list untuk menu hidangan restoran
List<HidanganRestoran> menuHidanganRestoran;
// preset untuk menu hidangan restoran
HidanganRestoran *PRESET_HIDANGAN[10] = {
    new HidanganRestoran("Nasi Goreng",19,20000),
    new HidanganRestoran("Ayam Bakar",20,25000),
    new HidanganRestoran("Ikan Nila Goreng",25,22000),
    new HidanganRestoran("Udang Telur Asin",23,38000),
    new HidanganRestoran("Cumi Goreng Tepung",32,45000),
    new HidanganRestoran("Kerang Dara Rebus",21,48000),
    new HidanganRestoran("Kepiting Saus Tiram",30,175000),
    new HidanganRestoran("Jus Jeruk",27,15000),
    new HidanganRestoran("Ice Cream",22,12000),
    new HidanganRestoran("Air Mineral",35,5000)
};

// struct untuk menyimpan data hidangan pesanan pelanggan
struct HidanganPelanggan {
    //hidangan dalam menunya
    HidanganRestoran *hidangan = nullptr;
    //jumlah yang dipesan oleh pelanggan
    int quantity = 0;
    HidanganPelanggan *next = nullptr;

    // constructor lengkap
    HidanganPelanggan(HidanganRestoran *Hidangan, int Quantity){
        hidangan = Hidangan;
        quantity = Quantity;
        next = nullptr;
    }
    // constructor
    HidanganPelanggan(){
        next = nullptr;
    }
    // return quantity * harga hidangan
    int subtotal(){
        return quantity*hidangan->harga;
    }
};

// struct untuk menyimpan data pelanggan
struct DataPelanggan {
    int nomorOrder;
    //nama pelanggan
    string nama;
    //waktu order
    string timestamp;
    //layanan yang dipilih pelanggan
    Layanan *layanan = new Layanan("",0,0);
    //total biaya yang harus dibayar saat checkout
    //list pesanan yang dipilih pelanggan
    List<HidanganPelanggan> pesanan;
    DataPelanggan *next;

    // constructor
    DataPelanggan(){
        nomorOrder = globalNomorOrder;
        next = nullptr;
    }
    // return priority
    int priority(){
        return layanan->priority;
    }
    // fungsi untuk insersi data pelanggan
    void insertDataPelanggan(){
        int count = 1, select;
        char decision;
        cin.ignore();
        cout << "Masukkan nama pelanggan : ";
        getline(cin, nama);
        printBatas();
        timestamp = getTime();
        cout << "Jenis layanan :\n";
        for (int i=0; i<2; i++){
            cout << i+1 << " - " << LAYANAN[i].nama <<"\n";
        }
        printBatas();
        while (true){
            cout << "Pilih jenis layanan : ";
            cin >> select;
            if(cin.fail() || select > sizeof(LAYANAN)/sizeof(Layanan) || select < 1){
                cin.clear();
                cout << "Input salah !\n";
                continue;
            }
            layanan = &LAYANAN[select-1];
            break;
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
        HidanganPelanggan *newHidangan = new HidanganPelanggan;
        HidanganRestoran *&hidangan = newHidangan->hidangan;
        int &quantity = newHidangan->quantity;
        printMenu();
        while (true){
            int select;
            cout << "Pilih hidangan (1-10) : ";
            cin >> select;
            hidangan = menuHidanganRestoran[select-1];

            if(cin.fail()){
                fail();
                cout << "Input salah !\n";
                continue;
            }

            if (!hidangan){
                cout << "Input salah !\n";
                continue;
            }            
            else {
                if ( hidangan->stok == 0){
                    cout << "Stok hidangan habis !\n";
                    break;
                }
                while (true){
                    cout << "Berapa banyak ? : ";
                    cin >> quantity;
                    if (quantity > 0 && quantity <= hidangan->stok){
                        hidangan->stok -= quantity;
                        break;
                    }
                    fail();
                    cout << "Input salah !\n";
                }
                break;
            }
            
        }
        pesanan += newHidangan;
    }
    // fungsi untuk traversal data hidangan
    void traversalHidangan(){
        for(int i = 0;pesanan[i];i++){
            cout << "\t\t\t  " << setw(22) << left << pesanan[i]->hidangan->nama << setw(2) << left << pesanan[i]->quantity
                 << " pcs   @Rp " << setw(6) << pesanan[i]->hidangan->harga << " = Rp " << setw(6) << left
                 << pesanan[i]->subtotal() << "\n";
        }
    }
    // fungsi untuk menghitung biaya layanan
    float biayaLayanan(){
        float total = 0;
        for(int i = 0;pesanan[i];i++)
            total += pesanan[i]->subtotal();
        return total * layanan->biaya;
    }
    // fungsi untuk menghitung total biaya int layanan, float subtotal
    float biayaTotal(){
        float total = 0;
        for(int i = 0;pesanan[i];i++)
            total += pesanan[i]->subtotal();
        return total + biayaLayanan();
    }
    // fungsi untuk print data pelanggan
    void printDataPelanggan(){
        cout << "Nomor Order\t\t: " << nomorOrder << "\n";
        cout << "Nama Pelanggan\t\t: " << nama << "\n";
        cout << "Layanan\t\t\t: " << layanan->nama << "\n";
        cout << "Tanggal Transaksi\t: " << timestamp;
        cout << "Hidangan yang dipesan\t: \n";
        traversalHidangan();
        printBatas();
        cout << "Subtotal\t\t: Rp " << fixed << setprecision(0) << biayaTotal() - biayaLayanan() << "\n";
        cout << "Biaya Layanan\t\t: Rp " << biayaLayanan() << "\n";
        cout << "Total Biaya\t\t: Rp " << fixed << setprecision(0) << biayaTotal()<< "\n";
    }
}pelanggan;

// struct untuk menyimpan laporan penjualan
struct SalesReport {
    List<DataPelanggan> listPelanggan;

    // constructor
    SalesReport(){
    }

    // fungsi untuk push ke single list laporan penjualan
    void pushListReport(DataPelanggan *poppedPelanggan){
        listPelanggan += poppedPelanggan;
    }
    
    // fungsi untuk traversal laporan penjualan
    void traversalReport(){
        if (listPelanggan.empty()){
            cout << "Laporan penjualan kosong !\n";
            return;
        } 
        cout << "Nomor\tNo. Order\tNama Pelanggan\t\tLayanan\t\tTotal Biaya\n";
        for(int i=0;listPelanggan[i];i++){
            printBatas();
            cout << setw(8) << left << i+1 << setw(16) << left << listPelanggan[i]->nomorOrder
                    << setw(24) << left << listPelanggan[i]->nama << setw(16) << left <<  listPelanggan[i]->layanan->nama
                    << "Rp "<< fixed << setprecision(0) << setw(6) << left <<  listPelanggan[i]->biayaTotal() << "\n";
        }
    }
};

// DEFINISI FUNGSI
void _inisialisasiMenuPreset(){
    for(int i = 0;i<10;i++)
    menuHidanganRestoran += PRESET_HIDANGAN[i];
}
void printMenu(){
    cout << "No. " << setw(22) << left << "Nama Hidangan" << setw(2) << left << "Stok\t   "<< "Harga\n";
    printBatas();
    for (int i=0;menuHidanganRestoran[i]; i++){
        cout << setw(4) << left << i+1 << setw(22) << left << menuHidanganRestoran[i]->nama << setw(2) <<  menuHidanganRestoran[i]->stok 
                << " pcs " << "  Rp " <<  menuHidanganRestoran[i]->harga << "\n";
    }   
    printBatas();
}
string getTime(){
    time_t curr_time;
    curr_time = time(0);
    return ctime(&curr_time);
}


// queue untuk pelanggan
ListQueue<DataPelanggan> queuePelanggan;
// queue untuk checkout
ListQueue<DataPelanggan> queueCheckout;
// sales report
SalesReport salesReport;

// stack checkout diganti dengan queue
/*
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
*/