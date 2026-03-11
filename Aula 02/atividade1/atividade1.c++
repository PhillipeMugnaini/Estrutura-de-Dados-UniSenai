#include <iostream>

using namespace std;

int main(int argc,char** argv){

    int x =10;
    int y = 20;
    int *p = &x;
    int *q = &y;

    cout << *p << endl;


    *p = *q;

    cout << *p << endl;
    cout << *q << endl;

    return 0;

}