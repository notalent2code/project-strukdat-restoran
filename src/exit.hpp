// file header untuk fungsi exit

// dealokasi memori seluruh pointer yang digunakan
void dealloc(){
    queuePelanggan.clear();
    queueCheckout.clear();
    salesReport.listPelanggan.clear();
    UndoStack.clear();
    RedoStack.clear();

    /*
    if (queuePelanggan.head != nullptr){
        DataPelanggan *pHelp = nullptr;
        while (queuePelanggan.head != nullptr){
            pHelp = queuePelanggan.head;
            queuePelanggan.head = queuePelanggan.head->next;
            free(pHelp);
        }
    delete pHelp;
    }

    if (stackCheckout.listPelanggan != nullptr){
        DataPelanggan *pHelp = nullptr;
        while (stackCheckout.listPelanggan != nullptr){
            pHelp = stackCheckout.listPelanggan;
            stackCheckout.listPelanggan = stackCheckout.listPelanggan->next;
            free(pHelp);
        }
    delete pHelp;
    }

    if (salesReport.listPelanggan != nullptr){
        DataPelanggan *pHelp = nullptr;
        while (salesReport.listPelanggan != nullptr){
            pHelp = salesReport.listPelanggan;
            salesReport.listPelanggan = salesReport.listPelanggan->next;
            free(pHelp);
        }
    delete pHelp;        
    }
    */
}