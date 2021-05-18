// file header untuk struct

// FUNGSI
// inisialisasi menu hidangan bawaan/preset
void _inisialisasiMenuPreset();
// print menu hidangan restoram
void printMenu();
// fungsi untuk generate timestamp
string getTime();
// fungsi untuk traversal laporan penjualan

struct Layanan;
template<typename T>
struct List;
template<typename T>
struct ListQueue;
struct HidanganRestoran;
struct action;
template<typename T>
struct Stack;
struct SalesReport;
struct DataPelanggan;
struct HidanganPelanggan;

struct action{
    std::function<int()> undo, redo;
    action *next = nullptr;

    action(){

    }
};

void traversalReport(List<DataPelanggan> &listPelanggan);
template<typename T, typename LT>
void pushDeleteAction(T *node, int index, LT list);


template<typename T>
struct Stack{
    T *top = nullptr;
    void push(T *&newNode){
        newNode->next = top;
        top = newNode;
    }
    T* pop(T *node = nullptr){
        if(!top) return nullptr;
        node = top;
        top = top->next;
        return node;
    }
    T* pop(Stack &stack){
        T *node;

        if(!top) return nullptr;

        node = top;

        top = top->next;

        stack.push(node);

        return node;
    }
    void clear(){
        T *pDelete;
        while(top){
            pDelete = top;
            top = top->next;
            free(pDelete);
        }
        top = nullptr;
    }
};

Stack<action> UndoStack, RedoStack;

// struct untuk struktur data queue
template<typename T>
struct ListQueue{
    // iterator untuk fungsi operator[]
    
    // index untuk operator

    T *head = nullptr;
    T *tail = nullptr;

    //constructor
    ListQueue(){
    }
    //copy assignment
    void operator=(const ListQueue &ref){
        clear();
        T *pHelp = ref.head;
        while(pHelp){
            push_back(*pHelp);
            pHelp = pHelp->next; 
        }
    }
    int index(T *node){
        T *pHelp = head;
        int count = 0;
        while(pHelp && pHelp != node){
            count++;
            pHelp = pHelp->next;
        }
        if(!pHelp) return -1;
        return count;
    }
    void push_back(T node){
        T *pNode = new T;
        *pNode = node;
        enqueue(pNode);
    }
    int size(){
        T *pHelp = head;
        int count = 0;
        while(pHelp){
            count++;
            pHelp = pHelp->next;
        }
        return count;
    }
    //destructor
    void clear(){
        T *pDelete;
        while(head){
            pDelete = head;
            head = head->next;
            free(pDelete);
        }
        delete pDelete;
        head = nullptr;
        tail = nullptr;
    }
    //true if queue empty
    bool empty(){
        if(head == nullptr) return true;
        return false;
    }
    //fungsi untuk menghapus node pada index tertentu
    void remove(int index, bool isDestructive  = 1){
        // cout<<"INDEX "<<index<<endl;
        T *pHelp = head, *pDelete = head;
        if(index == 0){
            if(head){
                if(tail == head) tail = tail->next;
                head = head->next;
                if(isDestructive) delete pDelete;
                return;
            }
            else return;
        }

        for(int i=0;i<index;i++){
            pHelp = pDelete;
            pDelete = pDelete->next;
        }
        if(pDelete == tail){
            if(isDestructive) delete pDelete;
            pHelp->next = nullptr;
            tail = pHelp;
        }
        pHelp->next = pDelete->next;
        if(isDestructive) delete pDelete;
    }
    void insert(int index, T *node){
        node->next = nullptr;
        if(index == 0){
            node->next = head;
            head = node;
            return;
        }
        T *pPrev = head, *pHelp = head;
        for(int i = 0;i < index;i++){
            pPrev = pHelp;
            pHelp = pHelp->next;
        }
        if(!pHelp){
            pPrev->next = node;
            tail = node;
            return;
        }
        pPrev->next = node;
        node->next = pHelp;
        return;
    }
    // fungsi untuk enqueue dengan skala prioritas yang diambil dari fungsi priority() pada node
    void priority_enqueue(T *newNode){
        newNode->priority();
        T *pPrev = nullptr;
        T *pHelp = head;
        if (head == nullptr || tail == nullptr){
            cout<<0;
            head = newNode;
            tail = newNode;
            return;
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
        int count = 0;

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
        T *iterator = nullptr;
        int iteratorIndex = 0;
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
 
// struct untuk struktur data linked list
template<typename T>
struct List{
    // iterator untuk fungsi operator[]

    T *head = nullptr;

    //constructor
    List(){
    }
    //copy constructor
    List(const List &ref){
        clear();
        T *pHelp = ref.head;
        while(pHelp){
            push_back(*pHelp);
            pHelp = pHelp->next; 
        }
    }
    void operator=(const List &ref){
        clear();
        T *pHelp = ref.head;
        while(pHelp){
            push_back(*pHelp);
            pHelp = pHelp->next; 
        }
    }
    int index(T *node){
        T *pHelp = head;
        int count = 0;
        while(pHelp && pHelp != node){
            count++;
            pHelp = pHelp->next;
        }
        if(!pHelp) return -1;
        return count;
    }
   void push_back(T node){
        T *pNode = new T;
        *pNode = node;
        push_back(pNode);
    }
    
    int size(){
        T *pHelp = head;
        int count = 0;
        while(pHelp){
            count++;
            pHelp = pHelp->next;
        }
        return count;
    }
    //destructor
    void clear(){
        T *pDelete;
        while(head){
            pDelete = head;
            head = head->next;
            free(pDelete);
        }
        delete pDelete;
        head = nullptr;
    }
    // hapus node di index
    void remove(int index,  bool isDestructive  = 1){
        T *pHelp = head, *pDelete = head;
        if(index == 0){
            if(head){
                head = head->next;
                if(isDestructive) delete pDelete;
                return;
            }
            else return;
        }

        for(int i=0;i<index;i++){
            pHelp = pDelete;
            pDelete = pDelete->next;
        }
        pHelp->next = pDelete->next;
        if(isDestructive) delete pDelete;
    }
    void insert(int index, T *node){
        node->next = nullptr;
        if(index == 0){
            node->next = head;
            head = node;
            return;
        }
        T *pPrev = head, *pHelp = head;
        for(int i = 0;i < index;i++){
            pPrev = pHelp;
            pHelp = pHelp->next;
        }
        if(!pHelp){
            pPrev->next = node;
            return;
        }
        pPrev->next = node;
        node->next = pHelp;
        return;
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
        T *iterator = nullptr;
        // index untuk operator
        int iteratorIndex = 0;
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


// queue untuk pelanggan
ListQueue<DataPelanggan> queuePelanggan;
// queue untuk checkout
ListQueue<DataPelanggan> queueCheckout;
// sales report
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
    void traversalReport(){
        ::traversalReport(this->listPelanggan);
    }
    
};

SalesReport salesReport;

// struct untuk menyimpan data hidangan dalam menu restoran
struct HidanganRestoran {
    int nomorOrder;
    //jumlah dalam stok
    int stok = 0;
    string nama;
    float harga = 0;
    HidanganRestoran *next = nullptr;

    // constructor
    HidanganRestoran(){
        next = nullptr;
    }
    //copy constructor
    HidanganRestoran(const HidanganRestoran &ref){
        nomorOrder = ref.nomorOrder;
        stok = ref.stok;
        nama = ref.nama;
        harga = ref.harga;
        next = ref.next;
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


template<typename T, typename LT>
int removeNode(LT *list ,int index, T *node, int code = 0){
    list->remove(index,0);
    return code;
}
template<typename T, typename LT>
int addNode(LT *list ,int index, T *node, int code = 0){
    list->insert(index, node);
    return code;
}
template<typename T>
int editNode(T *oldNode, T newValue, int code = 0){
    *oldNode = newValue;
    return code;
}
template<typename T>
int pushEditAction(T *oldNode, T newValue, int code = 0){
    action *aksi = new action;
    aksi->undo = std::bind(editNode<T>, oldNode, *oldNode, code);
    aksi->redo = std::bind(editNode<T>, oldNode, newValue, code);
    UndoStack.push(aksi);
    RedoStack.clear();
}
template<typename T, typename LT>
int pushDeleteAction(T *node, LT *list, int code = 0){
    int index = list->index(node);
    // cout<<"INDEX "<<index<<endl;
    T *bak = new T(*node);
    action *aksi = new action;
    aksi->undo = std::bind(addNode<T, LT>, list, index, bak, code);
    aksi->redo = std::bind(removeNode<T, LT>, list, index, bak, code);
    UndoStack.push(aksi);
    RedoStack.clear();
}
template<typename T, typename LT>
int pushAddAction(T *node, LT *list, int code = 0){
    int index = list->index(node);
    // cout<<"INDEX "<<index<<endl;
    T *bak = new T(*node);
    action *aksi = new action;
    aksi->redo = std::bind(addNode<T, LT>, list, index, bak, code);
    aksi->undo = std::bind(removeNode<T, LT>, list, index, bak, code);
    UndoStack.push(aksi);
    RedoStack.clear();
}
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
    Layanan(string Nama, float Biaya, int Priority){
        nama = Nama;
        biaya = Biaya;
        priority = Priority;
    }
    //copy constructor
    Layanan(const Layanan &ref){
        priority = ref.priority;
        nama = ref.nama;
        biaya = ref.biaya;
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
    Layanan("VIP",0.1f,VIP)
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
    //copy constructor
    HidanganPelanggan(const HidanganPelanggan &ref){
        hidangan = ref.hidangan;
        quantity = ref.quantity;
        next = ref.next;
    }
    // constructor
    HidanganPelanggan(){
        next = nullptr;
    }
    // return quantity * harga hidangan
    float subtotal(){
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
    float biayaTotal, biayaLayanan; 
    //total biaya yang harus dibayar saat checkout
    //list pesanan yang dipilih pelanggan
    List<HidanganPelanggan> pesanan;
    DataPelanggan *next;

    // constructor
    DataPelanggan(){
        nomorOrder = globalNomorOrder;
        next = nullptr;
    }
    //copy constructor
    DataPelanggan(const DataPelanggan &ref){
        cout<<"yuuhuu";
        // system("pause");
        nomorOrder = ref.nomorOrder;
        cout<<1;
        nama = ref.nama;
        cout<<2;
        timestamp = ref.timestamp;
        cout<<3;
        layanan = ref.layanan;
        cout<<4;
        biayaTotal = ref.biayaTotal;
        cout<<5;
        biayaLayanan = ref.biayaLayanan;
        cout<<6;
        pesanan = ref.pesanan;
        cout<<7;
        next = ref.next;
        cout<<8;
        return;
    }
    // return priority dari layanan sekarang
    int priority(){
        return layanan->priority;
    }
    void hapus(){
        pushDeleteAction(this, &queuePelanggan);
        UndoStack.top->redo();
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
                fail();
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
                countBiaya();
                
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
        bool isExist = 0;
        int quantity = 0;
        printMenu();
        while (true){
            int select;
            cout << "Pilih hidangan : ";
            cin >> select;
            newHidangan->hidangan = menuHidanganRestoran[select-1];
            for(int i = 0;pesanan[i];i++){
                if(pesanan[i]->hidangan == newHidangan->hidangan) {newHidangan = pesanan[i]; isExist = 1; break;}
            }

            if(cin.fail()){
                fail();
                cout << "Input salah !\n";
                continue;
            }

            if (!newHidangan->hidangan){
                cout << "Input salah !\n";
                continue;
            }            
            else {
                
                if ( newHidangan->hidangan->stok == 0){
                    cout << "Stok hidangan habis !\n";
                    break;
                }
                while (true){
                    cout << "Berapa banyak ? : ";
                    cin >> quantity;
                    
                    if (quantity > 0 && quantity+newHidangan->quantity <= newHidangan->hidangan->stok){
                        newHidangan->quantity += quantity;
                        break;
                    }
                    fail();
                    cout << "Input salah !\n";
                }
                break;
            }
            
        }
        if(!isExist) pesanan += newHidangan;
    }
    // fungsi untuk traversal data hidangan
    void traversalHidangan(){
        for(int i = 0;pesanan[i];i++){
            cout << "\t\t\t  " << setw(22) << left << pesanan[i]->hidangan->nama << setw(2) << left << pesanan[i]->quantity
                 << " pcs   @Rp " << setw(6) << pesanan[i]->hidangan->harga << " = Rp " << setw(6) << left
                 << pesanan[i]->subtotal() << "\n";
        }
    }
    // fungsi untuk mencatat biaya-biaya (menyimpan ke variabel)
    void countBiaya(){
        biayaLayanan = getBiayaLayanan();
        biayaTotal = getBiayaTotal();
    }
    // fungsi untuk menghitung biaya layanan
    float getBiayaLayanan(){
        float total = 0;
        for(int i = 0;pesanan[i];i++)
            total += pesanan[i]->subtotal();
        return total * layanan->biaya;
    }
    // fungsi untuk menghitung total biaya int layanan, float subtotal
    float getBiayaTotal(){
        float total = 0;
        for(int i = 0;pesanan[i];i++)
            total += pesanan[i]->subtotal();
        return total + getBiayaLayanan();
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
        cout << "Subtotal\t\t: Rp " << fixed << setprecision(0) << biayaTotal - biayaLayanan << "\n";
        cout << "Biaya Layanan\t\t: Rp " << biayaLayanan << "\n";
        cout << "Total Biaya\t\t: Rp " << fixed << setprecision(0) << biayaTotal<< "\n";
    }
}pelanggan;


// fungsi untuk traversal laporan penjualan
void traversalReport(List<DataPelanggan> &listPelanggan){

    if (listPelanggan.empty()){
        cout << "Laporan penjualan kosong !\n";
        return;
    } 

    cout << "Nomor\tNo. Order\tNama Pelanggan\t\tLayanan\t\tTotal Biaya\n";
    for(int i=0;listPelanggan[i];i++){

        printBatas();
        cout << setw(8) << left << i+1 << setw(16) << left << listPelanggan[i]->nomorOrder
                << setw(24) << left << listPelanggan[i]->nama << setw(16) << left <<  listPelanggan[i]->layanan->nama
                << "Rp "<< fixed << setprecision(0) << setw(6) << left <<  listPelanggan[i]->biayaTotal << "\n";
    }
}



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



/*
// void addNode(ListQueue<DataPelanggan> list ,int index, DataPelanggan *node){
//     list.insert(index, node);
// }
// void removeNode(ListQueue<DataPelanggan> list ,int index, DataPelanggan *node){
//     list.remove(index);
// }
// void addNode(List<HidanganRestoran> list ,int index, HidanganRestoran *node){
//     list.insert(index, node);
// }
// void addNode(List<HidanganRestoran> list ,int index, HidanganRestoran *node){
//     list.insert(index, node);
// }

// void replaceNode(HidanganPelanggan *oldNode, HidanganPelanggan *newNode){
//     oldNode = newNode;
// }
// void replaceNode(HidanganPelanggan oldNode, HidanganPelanggan newNode){
//     oldNode = newNode;
// }
// void replaceNode(HidanganRestoran *oldNode, HidanganRestoran *newNode){
//     oldNode = newNode;
// }
// void replaceNode(HidanganRestoran oldNode, HidanganRestoran newNode){
//     oldNode = newNode;
// }
struct AR_node{
    AR_node *next;
    int type = NULL;

    function<void()> bound = std::bind(replaceNode<AR_node>, next, next);


    enum Enum{
        Upg = 11,
        Ume = 12,
        Uup = 13,
        Ust = 14,
        Rpg = 21,
        Rme = 22,
        Rup = 23,
        Rst = 24
    };
    union Undo
    {
        std::function<void(ListQueue<DataPelanggan>  ,int, DataPelanggan *)> pelanggan;
        std::function<void(ListQueue<HidanganRestoran>  ,int, HidanganRestoran *)> menu;
        std::function<void(HidanganPelanggan *, HidanganPelanggan *)> upgrade;
        std::function<void(HidanganRestoran *, HidanganRestoran *)> stok;  
    }undo;
    union Redo
    {
        std::function<void(ListQueue<DataPelanggan>  ,int, DataPelanggan *)> pelanggan;
        std::function<void(ListQueue<HidanganRestoran>  ,int, HidanganRestoran *)> menu;
        std::function<void(HidanganPelanggan *, HidanganPelanggan *)> upgrade;
        std::function<void(HidanganRestoran *, HidanganRestoran *)> stok; 
    }redo;
    void bind(ListQueue<DataPelanggan>  List, int Index, DataPelanggan *Pelanggan){
        bound();
        switch(type){
            case Upg:
                undo.pelanggan;
                break;
            case Ume:
                undo.menu;
                break;
            case Uup:
                undo.upgrade;
                break;
            case Ust:
                undo.stok;
                break;
            case Rpg:
                redo.pelanggan;
                break;
            case Rme:
                redo.menu;
                break;
            case Rup:
                redo.upgrade;
                break;
            case Rst:
                redo.stok;
                break;
        }
    }

};
*/





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