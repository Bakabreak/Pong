#include <iostream>
#include <windows.h>


using namespace std;

class Player {
public:
    float pos_x;
    float pos_y;

    float getposx(){
        return pos_x;
    }

    float getposy() {
        return pos_y;gggg
    }
};

class Ball {
public:
    float pos_x;
    float pos_y;
    float speed;
    float angle;

};

class Updater {
};
int main() {
    while(true){
//        cout << (GetKeyState('G')& 0x8000) << endl;
//        if(GetKeyState('G') & 0x0008){
            cout << (GetKeyState('G')& 0x8000) << endl;
//        }
    }
}
