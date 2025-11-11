#include <stdio.h>

int gera (void)
{
    return rand() % 9999 + 1000;
}
int main() {
    /*// Cabeçalho
    printf("\n%-5s | %-15s | %-10s | %-15s | %-20s | %-10s\n",
           "ID", "Vendedor", "Matrícula", "Cliente", "Data de Transação", "Valor(R$)");
    printf("---------------------------------------------------------------------------------------------\n");

    // Linhas da tabela
    printf("%-5d | %-15s | %-10d | %-15s | %-20s | %-10.2f\n",
           1, "Carlos Silva", 12345, "João Souza", "10/11/2025", 1500.75);
    printf("%-5d | %-15s | %-10d | %-15s | %-20s | %-10.2f\n",
           2, "Maria Lima", 67890, "Ana Costa", "11/11/2025", 230.50);
    printf("%-5d | %-15s | %-10d | %-15s | %-20s | %-10.2f\n",
           3, "João Pedro", 11223, "Carlos Alberto", "12/11/2025", 12000.00);

    return 0;*/
    int i=gera();
    printf("%d", i);

}
