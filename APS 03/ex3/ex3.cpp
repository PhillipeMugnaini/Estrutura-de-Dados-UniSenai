#include <iostream>
#include <string>

using namespace std;

struct Turma {
    int codigo;
    string nomeTurma;
    string periodo;

    Turma* prox;
};

struct Aluno {
    string nome;
    int matricula;

    float nota1;
    float nota2;
    float media;

    int codigoTurma;

    Aluno* prox;
};

Turma* listaTurmas = NULL;
Aluno* listaAlunos = NULL;


void cadastrarTurma() {

    Turma* nova = new Turma;

    cout << "\nCodigo da turma: ";
    cin >> nova->codigo;

    cin.ignore();

    cout << "Nome da turma: ";
    getline(cin, nova->nomeTurma);

    cout << "Periodo: ";
    getline(cin, nova->periodo);

    nova->prox = NULL;

    if(listaTurmas == NULL) {
        listaTurmas = nova;
    }
    else {

        Turma* temp = listaTurmas;

        while(temp->prox != NULL) {
            temp = temp->prox;
        }

        temp->prox = nova;
    }

    cout << "\nTurma cadastrada com sucesso!\n";
}


void listarTurmas() {

    if(listaTurmas == NULL) {
        cout << "\nNenhuma turma cadastrada!\n";
        return;
    }

    Turma* temp = listaTurmas;

    cout << "\n===== TURMAS =====\n";

    while(temp != NULL) {

        cout << "Codigo: " << temp->codigo << endl;
        cout << "Nome: " << temp->nomeTurma << endl;
        cout << "Periodo: " << temp->periodo << endl;
        cout << "----------------------\n";

        temp = temp->prox;
    }
}

Turma* buscarTurma(int codigo) {

    Turma* temp = listaTurmas;

    while(temp != NULL) {

        if(temp->codigo == codigo) {
            return temp;
        }

        temp = temp->prox;
    }

    return NULL;
}

void cadastrarAluno() {

    Aluno* novo = new Aluno;

    cin.ignore();

    cout << "\nNome do aluno: ";
    getline(cin, novo->nome);

    cout << "Matricula: ";
    cin >> novo->matricula;

    cout << "Nota 1: ";
    cin >> novo->nota1;

    cout << "Nota 2: ";
    cin >> novo->nota2;

    novo->media = (novo->nota1 + novo->nota2) / 2;

    cout << "Codigo da turma: ";
    cin >> novo->codigoTurma;

    // verifica se a turma existe
    if(buscarTurma(novo->codigoTurma) == NULL) {

        cout << "\nTurma nao encontrada!\n";

        delete novo;
        return;
    }

    novo->prox = NULL;

    if(listaAlunos == NULL) {
        listaAlunos = novo;
    }
    else {

        Aluno* temp = listaAlunos;

        while(temp->prox != NULL) {
            temp = temp->prox;
        }

        temp->prox = novo;
    }

    cout << "\nAluno cadastrado com sucesso!\n";
}

void listarAlunos() {

    if(listaAlunos == NULL) {
        cout << "\nNenhum aluno cadastrado!\n";
        return;
    }

    Aluno* temp = listaAlunos;

    cout << "\n===== ALUNOS =====\n";

    while(temp != NULL) {

        cout << "Nome: " << temp->nome << endl;
        cout << "Matricula: " << temp->matricula << endl;
        cout << "Nota 1: " << temp->nota1 << endl;
        cout << "Nota 2: " << temp->nota2 << endl;
        cout << "Media: " << temp->media << endl;

        Turma* turma = buscarTurma(temp->codigoTurma);

        if(turma != NULL) {
            cout << "Turma: " << turma->nomeTurma << endl;
        }

        cout << "----------------------\n";

        temp = temp->prox;
    }
}

void removerAluno() {

    int matricula;

    cout << "\nDigite a matricula do aluno: ";
    cin >> matricula;

    Aluno* atual = listaAlunos;
    Aluno* anterior = NULL;

    while(atual != NULL && atual->matricula != matricula) {

        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL) {
        cout << "\nAluno nao encontrado!\n";
        return;
    }

    // remove primeiro elemento
    if(anterior == NULL) {
        listaAlunos = atual->prox;
    }
    else {
        anterior->prox = atual->prox;
    }

    delete atual;

    cout << "\nAluno removido com sucesso!\n";
}

void atualizarAluno() {

    int matricula;

    cout << "\nDigite a matricula do aluno: ";
    cin >> matricula;

    Aluno* temp = listaAlunos;

    while(temp != NULL) {

        if(temp->matricula == matricula) {

            cin.ignore();

            cout << "Novo nome: ";
            getline(cin, temp->nome);

            cout << "Nova nota 1: ";
            cin >> temp->nota1;

            cout << "Nova nota 2: ";
            cin >> temp->nota2;

            temp->media = (temp->nota1 + temp->nota2) / 2;

            cout << "\nAluno atualizado!\n";

            return;
        }

        temp = temp->prox;
    }

    cout << "\nAluno nao encontrado!\n";
}

int main() {

    int opcao;

    do {

        cout << "\n=========== MENU ===========\n";

        cout << "1 - Cadastrar turma\n";
        cout << "2 - Listar turmas\n";

        cout << "3 - Cadastrar aluno\n";
        cout << "4 - Listar alunos\n";

        cout << "5 - Remover aluno\n";
        cout << "6 - Atualizar aluno\n";

        cout << "0 - Sair\n";

        cout << "Opcao: ";
        cin >> opcao;

        switch(opcao) {

            case 1:
                cadastrarTurma();
                break;

            case 2:
                listarTurmas();
                break;

            case 3:
                cadastrarAluno();
                break;

            case 4:
                listarAlunos();
                break;

            case 5:
                removerAluno();
                break;

            case 6:
                atualizarAluno();
                break;

            case 0:
                cout << "\nEncerrando sistema...\n";
                break;

            default:
                cout << "\nOpcao invalida!\n";
        }

    } while(opcao != 0);

    return 0;
}