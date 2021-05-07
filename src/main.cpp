#include <iostream>
#include <limits>
#include <math.h>
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
// #include "checkout.hpp"
// #include "report.hpp"
// #include "exit.hpp"
#include "menu.hpp"
int main(){
    menu.display();
}

// fungsi fail
void fail(){
    std::cin.clear();
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// fungsi mencetak batas dengan simbol samadengan
void printBatas(){
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 58; j++){
            cout << "=";
        }
        cout << "\n";
    }
}