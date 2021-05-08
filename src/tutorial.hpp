// file header untuk menyimpan tutorial program

// fungsi untuk menampilkan tutorial
void menuTutorial(){
    system("cls");
    printBatas();
    cout << "\t\tSISTEM PELAYANAN RESTORAN\n";
    printBatas();
    cout << "\t\t  Menu Tutorial Program\n" 
        "Fungsi pada Program :\n"
        "1. Antrian Pesanan\t: Berfungsi untuk menambahkan pesanan, melihat antrian, \n"
        "\t\t\t  dan mencetak detail dari pesanan tertentu berdasarkan nomor pesanan\n"
        "2. Proses Pesanan\t: Berfungsi memproses pesanan pelanggan dengan memperhatikan\n"
        "\t\t\t  skala prioritas yang diinputkan pada fungsi tambah pesanan\n"
        "3. Checkout\t\t: Pembayaran pesanan oleh pelanggan\n"
        "4. Laporan Penjualan\t: Daftar transaksi yang telah dilakukan\n"
        "5. Update Stok \t\t: Berfungsi untuk mengupdate stok hidangan tertentu\n"
        "6. Tutorial Program\t: Berfungsi untuk menampilkan tata cara pengoperasian program\n"
        "7. Exit Program\t\t: Fungsi untuk keluar dari program\n";
}