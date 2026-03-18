#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int n =5;
    
    //-------
    //MALLOC
    
    int *vetor1 = (int*) malloc(n * sizeof(int));

    cout << "Preenchendo vetor 1 criado" << endl;

    for(int i = 0; i < n; i++){
        cout << vetor1[i] << " ";
    }

    //-------
    //CALLOC

    int *vetor2 = (int*) calloc(n,sizeof(int));

    cout << endl << "Preenchendo vetor 2 criado" << endl;

    for(int i=0; i<n; i++){
        cout << vetor2[i] << " ";
    }

    //------
    //REALLOC

    int novo_tamanho = 8;

    cout << endl;
    cout << "Imprimindo vetor 1 com novo tamanho" << endl;
    cout << "Endereco de vetor1:" << vetor1 << endl;

    vetor1 = (int*) realloc(vetor1, novo_tamanho * sizeof(int));

     cout << "Endereco de vetor1:" << vetor1 << endl;

    for(int i =0; i<novo_tamanho; i++){
        cout << vetor1[i] << " ";
    }

    cout << endl;

    //----------
    //FREE

    free(vetor1);
    free(vetor2);

    cout << endl << endl;
    cout << *vetor1 << endl;

    return 0;
}
