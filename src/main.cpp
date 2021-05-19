#include <iostream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <ctime>
#include <vector>
#include <string>
#include <functional>
// #include <type_traits>

using namespace std;

// variabel untuk menyimpan nomor order
int globalNomorOrder = 1;

// prototype fungsi print batas tanda samadengan
void printBatas(string title = "", char filler = '=', int count = 80); 

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


void pri(string x){
    cout<<x;
}

int main(){
    // consolee conMain = consolee(0);

    // getch();
    // // conMain.setWindowSize(50,100);

    _inisialisasiMenuPreset();
    system("pause");
    menu.display();
}

// fungsi fail, clear flag cin dan clear cin
void fail(){
    std::cin.clear();
    
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// fungsi mencetak batas
void printBatas(string title, char filler, int count){
    for(int i=count/2 - title.size()/2;i>0;i--){
        cout<<filler;
    }
    cout<<title;
    for(int i=(count - count/2) - (title.size() - title.size()/2);i>0;i--){
        cout<<filler;
    }
    cout<<endl;
}