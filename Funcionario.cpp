#include <iostream>
#include <locale.h>
using namespace std;
//Eduardo Miranda
//CB3026604

struct Funcionario{
	int prontuario;
	string nome;
	double salario;
	Funcionario *prox;
};
Funcionario* init() {
	return NULL;
};

bool verifyPront(Funcionario* funcionario, int prontuario) {
    Funcionario* aux = funcionario;
    while (aux != NULL) {
        if (aux->prontuario == prontuario) {
            return true; // Prontuário encontrado
        }
        aux = aux->prox;
        
    }
    return false; // Prontuário não encontrado
};

Funcionario* insert(Funcionario* funcionario, string name, int i, double sal){
	Funcionario* novo = new Funcionario();
    cout << "Opção 1 - Incluir" << endl;
    cout << "Escreva as informações:" << endl;
    do {
    	cout << endl;
        cout << "Nome do Funcionário: ";
        cin >> novo->nome;
        cout << "Prontuário: ";
        cin >> novo->prontuario;
        if (verifyPront(funcionario, novo->prontuario)) {
            cout << "Prontuário já existe! Por favor, digite outro prontuário." << endl;
        }
    } while (verifyPront(funcionario, novo->prontuario));
    cout << "Salário: ";
    cin >> novo->salario;
    cout << endl;
    novo->prox = funcionario; 
    return novo;
};

Funcionario* find(Funcionario* funcionario, int prontuario) {
    Funcionario* aux;
    aux = funcionario;
    bool encontrado = false;
    cout << "Digite o Prontuário: ";
    cin >> prontuario;
    
    while (aux != NULL) {
        if (aux->prontuario == prontuario) {
            cout << "Funcionário encontrado:" << endl;
            cout << endl;
            cout << "Nome: " << aux->nome << endl;
            cout << "Prontuário: " << aux->prontuario << endl;
            cout << "Salário: " << aux->salario << endl;
            cout << endl;
            encontrado = true;
            break;
        }
        aux = aux->prox;
    }
    
    if (!encontrado) {
        cout << "Funcionário não encontrado!" << endl;
    }
    
    return aux;
}

Funcionario* remove(Funcionario* funcionario, int i) {
    Funcionario* aux;
    Funcionario* ant = NULL;
    string esc;
    
     cout << "Opção 2 - Excluir" << endl;
     cout << "Digite o prontuário: ";
     cin >> i;
     cout << "Você tem certeza de que quer excluir?" << endl;
     cout << "Digite SIM ou NAO: ";
     cin >> esc;
     
    if(esc == "SIM" || esc == "sim" ){
    aux = funcionario;
    while (aux != NULL && aux->prontuario != i) {
        ant = aux;  
        aux = aux->prox;
    }
    
    if (aux == NULL) { // não encontrado
        return funcionario;
    }   
    
    if (ant == NULL) { // era o primeiro
        funcionario = aux->prox;
    }
    else { // estava no meio
        ant->prox = aux->prox;
    }
    delete aux;
    return funcionario;
	}
	else{
		return funcionario;
	}
}


void freeFunc(Funcionario* funcionario) {
    Funcionario* aux;
	aux = funcionario;
	while (aux != NULL) {
		Funcionario *ant = aux->prox;
		delete(aux);
		aux = ant;
	}	
}



void print(Funcionario* funcionario) {
	Funcionario* aux;
	aux = funcionario;
	double totalSal;
	while (aux != NULL) {
		cout << "<--------------->" <<endl;
		cout << endl;
		cout << "Funcionario: " << aux->nome << endl
			 << "Prontuario: " << aux->prontuario << endl
		     << "Salario: " << aux->salario << endl;
		     cout << endl;
			 cout << "<--------------->" << endl;
			totalSal += aux->salario;
        	aux = aux->prox;
        	
	}
	cout << "Total de sálario: " << totalSal << endl;
	cout << endl;
}

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	setlocale(LC_ALL, "");
    Funcionario *novoFunc;
    novoFunc = init();

    int opcao;
    do {
        cout << "----- Menu -----" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cout << "----- // -----" << endl;

        switch(opcao) {
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                novoFunc = insert(novoFunc, "", NULL, NULL);
                break;
            case 2:
            	novoFunc = remove(novoFunc, NULL);
            	cout << endl;
            	cout << "Funcionário Removido!" << endl;
                
                break;
            case 3:
                cout << "Opção 3 - Pesquisar" << endl;
                cout << endl;
                find(novoFunc, NULL);

	
                break;
            case 4:
                cout << "Opção 4 - Listar" << endl;
                print(novoFunc);
                break;
            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    } while(opcao != 0);

    freeFunc(novoFunc);
    return 0;
}
	
	

