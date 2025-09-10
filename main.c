#include <stdio.h>
#include <string.h>

int main()
{
    //Cadastro
    char nomes[4][30];
    int tamanhoNome = 0;
    int nomeValido = 0;
    
    float valoresPedidos[4];
    int pedidoInvalido = 0;
    
    char sexo[4];
    char sexoInformado;
    int sexoValido = 0;
    
    int codigoPedido[4];
    int codigoValido = 0;
    
    //Menu
    char menuPrincipal;
    int menu = 0;
    
    float valor = 0;
    
	int qtdAcima = 0;
	int qtdDe20a30 = 0;
	int qtdO = 0;
	float valorMulheres = 0;
	float pedidoMaisCaro = 0;
	int qtdCodigos = 0;
	float media = 0;
	
    char nomeInformado[30];
    int comp = 0;
    int nomePesquisa = 0;
    float soma = 0;
    
    int contagem[10];
	int codigoMaisVendido = 0;
   
    // Cadastro
    for(int i = 0; i < 4; i++){
        
        // Nome
        do{
            nomeValido = 0;
            
            printf("\n-----------\n CADASTRO \n-----------\n");
            printf("\n Digite seu nome: ");
            scanf("%s", nomes[i]);
            
            tamanhoNome = strlen(nomes[i]);
            if(tamanhoNome > 1){
                nomeValido++;
            }
            else{
                printf("\n Nome muito curto. Digite novamente.\n");
            }
            
        }while(nomeValido == 0);
        
        
        // Valor do Pedido
        do{
            pedidoInvalido = 0;
            
            printf("\n Digite o valor do pedido: ");
            scanf("%f", &valoresPedidos[i]);
            
            if (valoresPedidos[i] < 0){
                printf("\n Valor inválido! Digite um valor positivo.");
                pedidoInvalido++;
            }
        
        }while(pedidoInvalido != 0);
        
        // Sexo
        do{
            sexoValido = 0;
            printf("\n-----------\n SEXO \n-----------\n M - Masculino \n F - Feminino \n O - Outro \n Digite o sexo: ");
            scanf(" %c", &sexo[i]);
            if(sexo[i] == 'M' || sexo[i] == 'm' || sexo[i] == 'F' || sexo[i]  == 'f'|| sexo[i] == 'o'|| sexo[i] == 'O'){
                sexoValido++;
            }
            else {
                printf("\n O sexo informado é inválido. Insira novamente.\n");
            }
        }while(sexoValido == 0);
        
        // Códigos
        do{
            codigoValido = 0;
            printf("\n-----------\n COMBOS \n-----------");
            printf("\n Combo 1 - Individual");
            printf("\n Combo 2 - Família");
            printf("\n Combo 3 - Casal");
            printf("\n Combo 4 - Doces");
            printf("\n Combo 5 - Dupla");
            printf("\n Combo 6 - Trio");
            printf("\n Combo 7 - Surpresa");
            printf("\n Combo 8 - Econômico");
            printf("\n Combo 9 - Oferta do dia");
            printf("\n Combo 10 - Kit Festa");
            printf("\n Digite o número do combo: ");
            scanf("%d", &codigoPedido[i]);
            
            if(codigoPedido[i] >= 1 && codigoPedido[i] <= 10){
                codigoValido++;
                contagem[i]++; 
            }
            else{
                printf("\n Código inválido! Digite novamente.\n");
            }
        
        }while(codigoValido == 0);
    }
    
    //Menu
    do{
        menuPrincipal = 'n';
        
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\n----------------\n MENU PRINCIPAL \n----------------\n");
        printf(" 1 - Informação de pedidos baseados no nome do usuário\n");
        printf(" 2 - ver informação de todos os pedidos cadastrados\n");
        printf(" 3 - Encerrar ou continuar\n");
        printf(" Escolha uma das opções: ");
        scanf("%d", &menu);
        
        switch (menu){
            case 1:
            nomePesquisa = 0;
			printf(" Informe o nome: ");
			scanf("%s", nomeInformado);
            
			for(int i = 0; i < 4; i++){
                
				comp = strcmp(nomes[i], nomeInformado);
                
				if(comp == 0){
				    printf("\n--------------------\n DADOS DO PEDIDO \n--------------------\n");
                        //Valor do pedido
                        printf(" \nO valor do pedido foi de: R$%.2f\n ", valoresPedidos[i]);
                        
                        //Código do pedido
                        printf(" \nO código do pedido realizado foi: %d\n", codigoPedido[i]);
                        
                        //Soma total dos pedidos
                        
                        soma += valoresPedidos[i];
                        nomePesquisa = 1;
				    }
                }
                if(nomePesquisa == 1){
                    printf("\n--------------------\n SOMA DOS PEDIDOS \n--------------------\n");
                    printf(" A soma total dos pedidos é: %.2f\n", soma);
                }
                else{
                    printf("\n Nenhum pedido encontrado\n");
                }
                
                printf("\n Retomar para o menu principal? (S ou N): ");
                scanf(" %c", &menuPrincipal);
                break; 
            case 2: 
                // variáveis 
                qtdAcima = 0;
                qtdDe20a30 = 0;
                qtdO = 0;
                valorMulheres = 0;
                pedidoMaisCaro = 0;
                qtdCodigos = 0;
                soma = 0;
                
                //pedidos acima do valor que digitar
                
                printf(" Digite um valor: ");
                scanf("%f", &valor);
                for(int i = 0; i < 4; i++){
                    if(valoresPedidos[i] > valor){
                    qtdAcima++;
                    }
                }
                
                for(int i = 0; i < 4; i++){
                    //pedidos entre 20 e 30
                    if(valoresPedidos[i] >= 20 && valoresPedidos[i] <= 30){
                        qtdDe20a30++;
                    }
                }
                
                for(int i = 0; i < 4; i++){
                    //pessoas que escolheram sexo o
                    if(sexo[i] == 'o' || sexo[i] == 'O'){
                        qtdO++;
                    }
                }
                    
                for(int i = 0; i < 4; i++){
                    //total comprado por mulheres
                    if(sexo [i] == 'f' || sexo[i] == 'F'){
                        valorMulheres = valoresPedidos[i] + valorMulheres;
                    }
                }
                
                for(int i = 0; i < 4; i++){
                    //valor médio entre os pedidos
                    soma = soma + valoresPedidos[i];
                }
                
                for(int i = 0; i < 4; i++){
                    //valor do pedido mais caro
                    if(valoresPedidos[i] > pedidoMaisCaro){
                        pedidoMaisCaro = valoresPedidos[i]; 
                    }
                }
                
                for(int i = 0; i < 4; i++){
                    //a quantidade de vendas com o código 1 ou 2
                    if(codigoPedido[i] == 1 || codigoPedido[i] == 2){
                        qtdCodigos++;
                    }
                }
                
                media = soma / 4;
                
                printf("\n----------------\n INFORMAÇÕES \n----------------\n");
                printf(" Quantidade de pedidos acima do valor informado: %d \n", qtdAcima);
                printf(" Quantidade de pedidos entre R$20,00 e R$30,00: %d \n", qtdDe20a30);
                printf(" Quantidade de compradores que escolheram sexo “o”: %d \n", qtdO);
                printf(" O valor total comprado pelas mulheres é: R$ %.2f \n", valorMulheres);
                printf(" O valor médio entre os pedidos é: R$ %.2f \n", media);
                printf(" O valor do pedido mais caro é: R$ %.2f \n", pedidoMaisCaro);
                printf(" A quantidade de vendas com o código 1 ou 2 é: %d \n", qtdCodigos);
                printf(" Retomar para o menu principal? (S ou N): ");
                scanf(" %c", &menuPrincipal);
                break;
            case 3:
                menuPrincipal == 'n';
                break;
            default:
                printf(" Numero invalido.\n");
                printf(" Retomar para o menu principal? (S ou N): ");
                scanf(" %c", &menuPrincipal);
        }
        
    }while(menuPrincipal == 's' || menuPrincipal == 'S');
    
    return 0;
}