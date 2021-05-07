// file header untuk fungsi exit

// dealokasi memori seluruh pointer yang digunakan
void dealloc(){
    if (queuePelanggan.head != nullptr){
    DataPelanggan *pHelp = nullptr;
    while (queuePelanggan.head != nullptr){
        pHelp = queuePelanggan.head;
        queuePelanggan.head = queuePelanggan.head->next;
        free(pHelp);
    }
    delete pHelp;
    }
}