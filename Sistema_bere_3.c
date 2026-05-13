#include <stdio.h>

int main() {
    float valor_compra, valor_pendente, valor_pago;
    float lucro_dia;
    int forma_pagamento, cartao_aprovado;
    int forma_do_cartao;
    FILE *cfPtr;

    printf("Valor total da compra: R$ ");
    scanf("%f", &valor_compra);
    
    
    valor_pendente = valor_compra;

    
    while (valor_pendente > 0) {
        printf("Falta pagar: R$ %.2f \n", valor_pendente);
        printf("1 -  Dinheiro \n");
        printf("2 - Cartao \n");
        printf("3 - Pix \n");
        printf("Escolha: ");
        scanf("%d", &forma_pagamento);

        if (forma_pagamento == 1) {
            printf("Valor em dinheiro recebido: R$ ");
            scanf("%f", &valor_pago);

            if (valor_pago < valor_pendente) {
                printf("Dinheiro insuficiente para o total. Abatendo R$ %.2f.\n", valor_pago);
                valor_pendente =- valor_pago;
                lucro_dia = lucro_dia + valor_pago;
            } else {
                printf("Pagamento aprovado! Troco a devolver: R$ %.2f\n", valor_pago - valor_pendente);
                lucro_dia =+ valor_pendente;
                valor_pendente = 0; 
            }
        } 
        else if (forma_pagamento == 2) {

            printf("1 - Debito \n");
            printf("2 - Credito \n");
            scanf("%d", &forma_do_cartao);



            printf("Passou o cartao? (1 - Sim / 0 - Nao): ");
            scanf("%d", &cartao_aprovado);

            if (cartao_aprovado == 1) {
                printf("Qual valor foi passado no cartao? R$ ");
                scanf("%f", &valor_pago);
                
                
                if (valor_pago > valor_pendente) {
                    valor_pago = valor_pendente; 
                }
                
                printf("Pagamento no cartao abatido com sucesso!\n");
                valor_pendente =- valor_pago;
                lucro_dia =+ valor_pago;
            } else {
                printf("Cartao recusado! Selecione a forma de pagamento novamente.\n");
            }
        } 
        else if (forma_pagamento == 3) {
            printf("Valor que deseja pagar no pix: R$ ");
            scanf("%f", &valor_pago);

            if (valor_pago < valor_pendente) {
                printf("Dinheiro insuficiente para o total. Abatendo R$ %.2f.\n", valor_pago);
                valor_pendente =- valor_pago;
                lucro_dia =+ valor_pago;
            } else {
                printf("Pagamento aprovado! Troco a devolver: R$ %.2f\n", valor_pago - valor_pendente);
                lucro_dia =+ valor_pendente;
                valor_pendente = 0; 
            }
        }
        else {
            printf("Opcao invalida. Tente novamente.\n");
        }


        
    }
     

   printf("\nCOMPRA FINALIZADA!\n");
    printf("Lucro acumulado: R$ %.2f\n", lucro_dia);

    // Tentando abrir o arquivo
    cfPtr = fopen("clientes.dat", "a"); 

    if (cfPtr == NULL) {
        printf("ERRO CRITICO: Nao foi possivel abrir o arquivo para gravar!\n");
    } else {
        
        fprintf(cfPtr, "Registro: %.2f\n", lucro_dia);
        
        
        fflush(cfPtr); 
        
        fclose(cfPtr);
        
        printf("Sucesso! Os dados foram enviados para o disco.\n");
    }

    return 0;
}