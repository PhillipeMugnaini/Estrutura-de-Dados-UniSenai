#include <iostream>
using namespace std; 

int main()
{
    int option;
    int num1, num2;
    

    while (true){

        double result = 0;

        cout << endl << "--- MENU ---" << endl;
        cout << "1. Soma " << endl;
        cout << "2. Subtração " << endl;
        cout << "3. Multiplicação " << endl;
        cout << "4. Divisão " << endl;
        cout << "5. Sair " << endl;
        cout << "------------" << endl;
        cin >> option;

        if(option == 5){
            cout << "Saindo do programa..." << endl;
            break;
        }

        cout << endl;
        cout << "Digite o primeiro número: " << endl;
        cin >> num1;
        cout << "Digite o segundo número: " << endl;
        cin >> num2;

        switch (option)
        {
        case 1:
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case 3:
            for(int i = 1; i<=num2; i++){
                result += num1;
            }
            cout << "Resultado: " << result << endl;
            break;
        case 4:
            if(num2 == 0){
                cout << "Não é possível fazer divisão por zero!" << endl;
            }else{
                int cont = 0;
                int temp = num1;

                while(temp >= num2){
                    temp -= num2;
                    cont++;
                }
                cout << "Resultado: " << cont << endl;
            }
            break;
    
        default:
        cout << "Opção inválida!" << endl;
            break;
        }
    }



    return 0;
}
