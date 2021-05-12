#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <ctime>
#include <vector>
#include <string>
using namespace std;

// variabel untuk menyimpan nomor order
int globalNomorOrder = 1;

// prototype fungsi print batas tanda samadengan
void printBatas(); 

// prototype fungsi fail
void fail();

// header file yang menyimpan data structs
#include "structs.hpp"
#include "antrian.hpp"
#include "proses.hpp"
#include "checkout.hpp"
#include "report.hpp"
#include "update.hpp"
#include "tutorial.hpp"
#include "exit.hpp"
#include "menu.hpp"
int main(){
    _inisialisasiMenuPreset();
    system("pause");
    menu.display();
}

// fungsi fail, clear flag cin dan clear cin
void fail(){
    std::cin.clear();
    
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// fungsi mencetak batas dengan simbol samadengan
void printBatas(){
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 80; j++){
            cout << "=";
        }
        cout << "\n";
    }
}