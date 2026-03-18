#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;

    cout << "Digite a quantidade de números a serem armazenados" << endl << ">>";
    cin >> n;

    int *vect1 = (int*) malloc(n * sizeof(int));

    for(int i=0; i<n; i++){
        cout << "Digite o " << i+1 << "º valor" << endl << ">>";
        cin >> vect1[i];

    }

    int auxM = vect1[0];
    int auxMm = vect1[0];

    for(int i=0; i<n; i++){
        cout << vect1[i] << " | ";
        if(auxM < vect1[i]){
            auxM = vect1[i];
        }

        if(auxMm > vect1[i]){
            auxMm = vect1[i];
        }
    }

    cout << endl << "Maior: " << auxM << endl;
    cout << "Menor: " << auxMm << endl;
    
    free(vect1);

    return 0;
}
