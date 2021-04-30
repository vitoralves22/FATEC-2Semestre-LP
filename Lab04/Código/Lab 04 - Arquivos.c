#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Codigo[11];
typedef char String[100];

typedef struct{
    Codigo codigo;
    String nome;
} Categoria, Cliente, Fornecedor;

typedef struct{
    Codigo fornecedor;
    Codigo codigo;
    String descricao;
    float valUnitario;
    int qtdEstoque;
    int qtdMinima;
    int necessidadeCompra;
} Produto;

typedef struct{
    Codigo cliente;
    Codigo produto;
    int quantidade;
    float valUnitario;
} Entrada, Relatorio;

    Codigo auxFornecedor;
    Codigo auxCodigo;

    String auxDescricao;
    String auxCliente;
	String auxProduto;
	String auxProdutoQtd;
	String auxClienteQtd;

    float auxValUnitario;
    float compras[30];
	float auxCompras;
	float auxValunit;

    int auxQtdEstoque;
    int auxQtdMinima;
    int auxNecCompra;
	int auxQuantidade;




int main(){
    Categoria listaCategorias[30];
    Cliente listaClientes[30];
    Fornecedor listaFornecedores[30];
    Produto listaProdutos[30];
    Entrada listaEntradas[30];
    Relatorio listaRelatorio[30];

    FILE *pCategoria;
    FILE *pCliente;
    FILE *pFornecedor;
    FILE *pProduto;
    FILE *pEntrada;

    pCategoria = fopen("categorias.txt", "r");
    pCliente = fopen("clientes.txt", "r");
    pFornecedor = fopen("fornecedores.txt", "r");
    pProduto = fopen("produtos.txt", "r+");
    pEntrada = fopen("entradas.txt", "r");

    if( pCategoria==NULL ||
            pCliente==NULL ||
            pFornecedor==NULL ||
            pProduto==NULL ||
            pEntrada==NULL){
        printf("Erro na leitura do arquivo\n");
        exit(1);
    }

    char linha[100];
    int indiceLinha;

    // LEITURA PRODUTOS
    indiceLinha=0;
    int qtdProdutos;
    while(fgets(linha,sizeof(linha),pProduto)!=NULL){
        if(indiceLinha!=0){
            char *letra = linha;
            int nPalavras = 1;

            while (*letra != '\0'){
                if (*(letra++) == ' ') nPalavras++;
            }

            char *vPalavras[nPalavras];
            char *palavra = strtok(linha, " ");

            int i=0;
            while (palavra != NULL){
                vPalavras[i++] = palavra;
                palavra = strtok(NULL, " ");
            }

            String descricaoProduto;
            strcpy(descricaoProduto,vPalavras[2]);

            for(int i=3; i<(nPalavras-3); i++){
                if(i!=(nPalavras-3)) strcat(descricaoProduto," ");
                strcat(descricaoProduto,vPalavras[i]);
            }

            int indiceProduto=indiceLinha-1;
            strcpy(listaProdutos[indiceProduto].fornecedor, vPalavras[0]);
            strcpy(listaProdutos[indiceProduto].codigo, vPalavras[1]);
            strcpy(listaProdutos[indiceProduto].descricao, descricaoProduto);
            listaProdutos[indiceProduto].valUnitario = atof(vPalavras[nPalavras-3]);
            listaProdutos[indiceProduto].qtdEstoque = atoi(vPalavras[nPalavras-2]);
            listaProdutos[indiceProduto].qtdMinima = atoi(vPalavras[nPalavras-1]);
            listaProdutos[indiceProduto].necessidadeCompra = listaProdutos[indiceProduto].qtdMinima - listaProdutos[indiceProduto].qtdEstoque;
        }else{
            qtdProdutos = atoi(linha);
        }
        indiceLinha++;
    }

    // LEITURA ENTRADAS
    indiceLinha=0;
    int qtdEntradas;
    while(fgets(linha,sizeof(linha),pEntrada)!=NULL){
        if(indiceLinha!=0){
            int indiceEntrada = indiceLinha-1;
            sscanf(linha,"%s %s %d %f", listaEntradas[indiceEntrada].cliente, listaEntradas[indiceEntrada].produto, &listaEntradas[indiceEntrada].quantidade, &listaEntradas[indiceEntrada].valUnitario);
        }else{
            qtdEntradas = atoi(linha);
        }
        indiceLinha++;
    }




    //<<ORDENAR PRODUTOS POR PRECO/DESCRICAO>>
    for(int i=0;i<qtdProdutos-1;i++){
        for(int j=i+1;j<qtdProdutos;j++){
            if ((listaProdutos[i].valUnitario>listaProdutos[j].valUnitario) ||
                ((listaProdutos[i].valUnitario==listaProdutos[j].valUnitario) && strcmp(listaProdutos[i].descricao,listaProdutos[j].descricao)>0)){

                strcpy(auxFornecedor, listaProdutos[i].fornecedor);
                strcpy(auxCodigo, listaProdutos[i].codigo);
                strcpy(auxDescricao, listaProdutos[i].descricao);
                auxValUnitario = listaProdutos[i].valUnitario;
                auxQtdEstoque = listaProdutos[i].qtdEstoque;
                auxQtdMinima = listaProdutos[i].qtdMinima;
                auxNecCompra = listaProdutos[i].necessidadeCompra;

                strcpy(listaProdutos[i].fornecedor, listaProdutos[j].fornecedor);
                strcpy(listaProdutos[i].codigo, listaProdutos[j].codigo);
                strcpy(listaProdutos[i].descricao, listaProdutos[j].descricao);
                listaProdutos[i].valUnitario = listaProdutos[j].valUnitario;
                listaProdutos[i].qtdEstoque = listaProdutos[j].qtdEstoque;
                listaProdutos[i].qtdMinima = listaProdutos[j].qtdMinima;
                listaProdutos[i].necessidadeCompra = listaProdutos[j].necessidadeCompra;

                strcpy(listaProdutos[j].fornecedor, auxFornecedor);
                strcpy(listaProdutos[j].codigo, auxCodigo);
                strcpy(listaProdutos[j].descricao, auxDescricao);
                listaProdutos[j].valUnitario = auxValUnitario;
                listaProdutos[j].qtdEstoque = auxQtdEstoque;
                listaProdutos[j].qtdMinima = auxQtdMinima;
                listaProdutos[i].necessidadeCompra = auxNecCompra;
            }
        }
    }


    // IMPRIMIR ARQUIVO PRODUTOS ORDENADOS
    FILE *pProduto2;
    pProduto2 = fopen("produtos.txt", "w");

    for(int i=-1; i<qtdProdutos; i++){
        if(i==-1){
            fprintf(pProduto2,"%d", qtdProdutos);
        }else{
            fprintf(pProduto2,"\n%s %s %s %.2f %d %d", listaProdutos[i].fornecedor, listaProdutos[i].codigo,
                    listaProdutos[i].descricao, listaProdutos[i].valUnitario, listaProdutos[i].qtdEstoque, listaProdutos[i].qtdMinima);
        }
    }


    // ORDENAR PRODUTOS FORNECEDOR/COD.PRODUTOS
    for(int i=0; i<qtdProdutos-1; i++){
        for(int j=i+1; j<qtdProdutos; j++){
            if  ((strcmp(listaProdutos[i].fornecedor,listaProdutos[j].fornecedor)>0) ||
                    ((strcmp(listaProdutos[i].fornecedor,listaProdutos[j].fornecedor)==0) &&
                     (strcmp(listaProdutos[i].codigo,listaProdutos[j].codigo)>0))){

                strcpy(auxFornecedor, listaProdutos[i].fornecedor);
                strcpy(auxCodigo, listaProdutos[i].codigo);
                strcpy(auxDescricao, listaProdutos[i].descricao);
                auxValUnitario = listaProdutos[i].valUnitario;
                auxQtdEstoque = listaProdutos[i].qtdEstoque;
                auxQtdMinima = listaProdutos[i].qtdMinima;
                auxNecCompra = listaProdutos[i].necessidadeCompra;

                strcpy(listaProdutos[i].fornecedor, listaProdutos[j].fornecedor);
                strcpy(listaProdutos[i].codigo, listaProdutos[j].codigo);
                strcpy(listaProdutos[i].descricao, listaProdutos[j].descricao);
                listaProdutos[i].valUnitario = listaProdutos[j].valUnitario;
                listaProdutos[i].qtdEstoque = listaProdutos[j].qtdEstoque;
                listaProdutos[i].qtdMinima = listaProdutos[j].qtdMinima;
                listaProdutos[i].necessidadeCompra = listaProdutos[j].necessidadeCompra;

                strcpy(listaProdutos[j].fornecedor, auxFornecedor);
                strcpy(listaProdutos[j].codigo, auxCodigo);
                strcpy(listaProdutos[j].descricao, auxDescricao);
                listaProdutos[j].valUnitario = auxValUnitario;
                listaProdutos[j].qtdEstoque = auxQtdEstoque;
                listaProdutos[j].qtdMinima = auxQtdMinima;
                listaProdutos[i].necessidadeCompra = auxNecCompra;
            }
        }
    }

    // IMPRIMIR ARQUIVO PRODUTO_FORNECEDOR
    FILE *pProdutoFornecedor;
    pProdutoFornecedor = fopen("produtos_fornecedor.txt", "w");

    for(int i=0; i<qtdProdutos; i++){
        fprintf(pProdutoFornecedor,"%s %s %s", listaProdutos[i].fornecedor, listaProdutos[i].codigo,
                listaProdutos[i].descricao);
        if(i!=qtdProdutos-1){
            fprintf(pProdutoFornecedor,"\n");
        }
    }
    fclose(pProduto);
    fclose(pProduto2);

	FILE *pProdutoCategoria;
	pProdutoCategoria = fopen("produto_por_categoria.txt","w");

	 for(int i=0;i<qtdProdutos;i++){
        for(int j=i+1;j<qtdProdutos;j++){
            if (strcmp(listaProdutos[i].codigo,listaProdutos[j].codigo)>0){

                strcpy(auxFornecedor, listaProdutos[i].fornecedor);
                strcpy(auxCodigo, listaProdutos[i].codigo);
                strcpy(auxDescricao, listaProdutos[i].descricao);
                auxValUnitario = listaProdutos[i].valUnitario;
                auxQtdEstoque = listaProdutos[i].qtdEstoque;
                auxQtdMinima = listaProdutos[i].qtdMinima;
                auxNecCompra = listaProdutos[i].necessidadeCompra;

                strcpy(listaProdutos[i].fornecedor, listaProdutos[j].fornecedor);
                strcpy(listaProdutos[i].codigo, listaProdutos[j].codigo);
                strcpy(listaProdutos[i].descricao, listaProdutos[j].descricao);
                listaProdutos[i].valUnitario = listaProdutos[j].valUnitario;
                listaProdutos[i].qtdEstoque = listaProdutos[j].qtdEstoque;
                listaProdutos[i].qtdMinima = listaProdutos[j].qtdMinima;
                listaProdutos[i].necessidadeCompra = listaProdutos[j].necessidadeCompra;

                strcpy(listaProdutos[j].fornecedor, auxFornecedor);
                strcpy(listaProdutos[j].codigo, auxCodigo);
                strcpy(listaProdutos[j].descricao, auxDescricao);
                listaProdutos[j].valUnitario = auxValUnitario;
                listaProdutos[j].qtdEstoque = auxQtdEstoque;
                listaProdutos[j].qtdMinima = auxQtdMinima;
                listaProdutos[i].necessidadeCompra = auxNecCompra;
            }
        }
    }

    for(int i=-1;i<qtdProdutos;i++){
        if(i==-1){
            fprintf(pProdutoCategoria,"%d", qtdProdutos);
        }else{
    		fprintf(pProdutoCategoria,"\n%s %s %s %.2f %d %d", listaProdutos[i].fornecedor, listaProdutos[i].codigo,
            listaProdutos[i].descricao, listaProdutos[i].valUnitario, listaProdutos[i].qtdEstoque, listaProdutos[i].qtdMinima);
	}
}

    // <<DEBITAR ESTOQUE>>
    for(int i=0; i<qtdEntradas; i++){
        for(int j=0; j<qtdProdutos; j++){
            if(strcmp(listaProdutos[j].codigo,listaEntradas[i].produto)==0){
                listaProdutos[j].qtdEstoque-=listaEntradas[i].quantidade;
                listaProdutos[j].necessidadeCompra=listaProdutos[j].qtdMinima - listaProdutos[j].qtdEstoque;
	        }
	    }
	}

	// <<GERAR ARQUIVO COMPRAS>>
    FILE *pCompra;
    pCompra = fopen("compras.txt", "w");
    for(int i=0; i<qtdProdutos; i++){
        if(listaProdutos[i].necessidadeCompra>0){
            fprintf(pCompra,"%s %s %d\n", listaProdutos[i].fornecedor, listaProdutos[i].codigo, listaProdutos[i].necessidadeCompra);
		}
	}


    // ORDENAR MAIOR VALOR RELATÓRIO_GERENCIAL

	for(int i=0; i<qtdEntradas; i++){
		strcpy(listaRelatorio[i].cliente, listaEntradas[i].cliente);
		strcpy(listaRelatorio[i].produto, listaEntradas[i].produto);
		listaRelatorio[i].quantidade = listaEntradas[i].quantidade;
		listaRelatorio[i].valUnitario = listaEntradas[i].valUnitario;
	}

	for(int i=0; i<qtdEntradas; i++){
		compras[i] = listaRelatorio[i].quantidade*listaRelatorio[i].valUnitario;
	}

    for(int i=0; i<qtdEntradas; i++){
        for(int j=i+1; j<qtdEntradas; j++){
            if  (compras[i] < compras[j]){

				strcpy(auxCliente, listaRelatorio[i].cliente);
                strcpy(auxProduto, listaRelatorio[i].produto);
                auxCompras = compras[i];

                strcpy(listaRelatorio[i].cliente, listaRelatorio[j].cliente);
                strcpy(listaRelatorio[i].produto, listaRelatorio[j].produto);
                compras[i] = compras[j];

                strcpy(listaRelatorio[j].cliente, auxCliente);
                strcpy(listaRelatorio[j].produto, auxProduto);
                compras[j] = auxCompras;
            }
        }
    }

    // ORDENAR QUANTIDADE DE PRODUTOS


    for(int i=0; i<qtdEntradas; i++){
        for(int j=i+1; j<qtdEntradas; j++){
            if  (listaRelatorio[i].quantidade < listaRelatorio[j].quantidade){

				strcpy(auxClienteQtd, listaRelatorio[i].cliente);
                strcpy(auxProdutoQtd, listaRelatorio[i].produto);
                auxQuantidade = listaRelatorio[i].quantidade;

                strcpy(listaRelatorio[i].cliente, listaRelatorio[j].cliente);
                strcpy(listaRelatorio[i].produto, listaRelatorio[j].produto);
                listaRelatorio[i].quantidade = listaRelatorio[j].quantidade;

                strcpy(listaRelatorio[j].cliente, auxClienteQtd);
                strcpy(listaRelatorio[j].produto, auxProdutoQtd);
                listaRelatorio[j].quantidade = auxQuantidade;
            }
        }
    }

	// IMPRIMIR ARQUIVO RELATÓRIO_GERENCIAL
	FILE *pRG;
    pRG = fopen("relatorio_gerencial.txt", "w");

    fprintf(pRG, "Lista ordenada por quantidade financeira.\n");
	for(int i=0; i<qtdEntradas; i++){
    fprintf(pRG,"%s %s R$%.2f\n", listaRelatorio[i].cliente, listaRelatorio[i].produto, compras[i]);
	}

	fprintf(pRG, "\nLista ordenada por quantidade vendida.\n");
	for(int i=0; i<qtdEntradas; i++){
    fprintf(pRG,"%s %s %d\n", listaRelatorio[i].cliente, listaRelatorio[i].produto, listaRelatorio[i].quantidade);
	}


	//LISTA DE PRODUTOS POR CATEGORIAS ANTIGAMENTE


    return 0;
}
