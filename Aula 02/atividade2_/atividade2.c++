#include <iostream>

using namespace std;

void maiorMenor(int *a, int *b){
    if (*a > *b) {
        int x = *a;
        *a = *b;
        *b = x;
    }
}

int main(){

    int a, b;

   cout << "Digite o primeiro valor \n>>";
   cin >> a;

   cout << "Digite o segundo valor\n>>";
   cin >> b;

   maiorMenor(&a,&b);

   cout << "(menor) = " << a << endl;
   cout << "(maior) = " << b << endl;

   cout << "endereço do maior = " << &a << endl;
   cout << "endereço do menor = " << &b << endl;

    return 0;

}