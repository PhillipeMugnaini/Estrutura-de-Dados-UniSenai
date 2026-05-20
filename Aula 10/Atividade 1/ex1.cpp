#include <iostream>
using namespace std;

void imprimirVetor(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void bubbleSort(int arr[], int n, int &comparacoes, int &trocas)
{
    bool trocou;

    for (int i = 0; i < n - 1; i++)
    {
        trocou = false;

        for (int j = 0; j < n - 1 - i; j++)
        {
            comparacoes++;

            if (arr[j] > arr[j + 1])
            {
                // Troca
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                trocas++;
                trocou = true;
            }
        }

        if (!trocou)
        {
            break;
        }
    }
}

void selectionSort(int arr[], int n, int &comparacoes, int &trocas)
{
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;

        for (int j = i + 1; j < n; j++)
        {
            comparacoes++;

            if (arr[j] < arr[menor])
            {
                menor = j;
            }
        }

        if (menor != i)
        {
            int temp = arr[i];
            arr[i] = arr[menor];
            arr[menor] = temp;

            trocas++;
        }
    }
}

int main()
{
    int vetorOriginal[] = {64, 25, 12, 22, 11};

    int n = sizeof(vetorOriginal) / sizeof(vetorOriginal[0]);

    int vetorBubble[5];
    int vetorSelection[5];

    for (int i = 0; i < n; i++)
    {
        vetorBubble[i] = vetorOriginal[i];
        vetorSelection[i] = vetorOriginal[i];
    }

    int compBubble = 0, trocasBubble = 0;
    int compSelection = 0, trocasSelection = 0;

    bubbleSort(vetorBubble, n, compBubble, trocasBubble);

    selectionSort(vetorSelection, n, compSelection, trocasSelection);

    cout << "=== Bubble Sort ===" << endl;
    imprimirVetor(vetorBubble, n);
    cout << "Comparacoes: " << compBubble << endl;
    cout << "Trocas: " << trocasBubble << endl;

    cout << endl;

    cout << "=== Selection Sort ===" << endl;
    imprimirVetor(vetorSelection, n);
    cout << "Comparacoes: " << compSelection << endl;
    cout << "Trocas: " << trocasSelection << endl;

    return 0;
}

/*O Bubble Sort pode ser mais eficiente em vetores quase ordenados devido à otimização de parada antecipada.
O Selection Sort realiza menos trocas que o Bubble Sort, mas continua fazendo muitas comparações.*/