#include <iostream>
using namespace std; 

int main()
{
    int value;
    long long factorial = 1;

    cout << "Digite um número inteiro: " << endl;
    cin >> value;

    if (value < 0){
        cout << "Digite apenas números positivos!" << endl;
    }else{
        for(int i = 1; i <= value; i++){
            factorial *= i;
        }
        cout << "Fatorial de " << value << " é: " << factorial << endl;
    }
    

    return 0;
}
