#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 5

int stack[TAMANHO];
int top = -1;

bool isEmpty() {
    return top == -1;
}


bool isFull() {
    return top == TAMANHO - 1;
}


void push(int data) {
    if (isFull()) {
        printf("Pilha cheia! Nao possivel empilhar.\n");
        return;
    }
    top++;
    stack[top] = data;
    printf("Elemento %d empilhado com sucesso.\n", data);
}


int pop() {
    if (isEmpty()) {
        printf("Pilha vazia! Nao possivel desempilhar.\n");
        return -1;
    }
    int temp = stack[top];
    top--;
    printf("Elemento %d desempilhado com sucesso.\n", temp);
    return temp;
}


void imprime_pilha() {
    if (isEmpty()) {
        printf("Pilha vazia.\n");
        return;
    }

    printf("Pilha: ");
    int i; 
    for (i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i < top) {
            printf(" -> ");
        }
    }
    printf(" <- topo\n");
}


void topo_pilha() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Topo da pilha: %d\n", stack[top]);
}


int main() {
    int opcao, valor;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1. Empilhar (push)\n");
        printf("2. Desempilhar (pop)\n");
        printf("3. Imprimir pilha\n");
        printf("4. Mostrar topo\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Encerrando o programa.\n");
            break;
        }

        switch (opcao) {
            case 1:
                printf("Informe um valor para empilhar: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido!\n");
                    while (getchar() != '\n'); 
                    break;
                }
                push(valor);
                break;
            case 2:
                pop();
                break;
            case 3:
                imprime_pilha();
                break;
            case 4:
                topo_pilha();
                break;
            case 5:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
