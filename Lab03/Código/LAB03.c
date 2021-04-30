/*********************************************************************/
/* Alunos: Kauan Linhares, Lenita Misaki, Pedro Freitas, Vitor Alves */
/* Linguagem de Programação                                          */
/* Prof. Eliane                                                      */
/*********************************************************************/

#include <stdio.h>
#include <math.h>
#include <conio.h>

#define true 1
#define false 0
#define pulaLinha printf("\n")
#define pula2Linha printf("\n\n")
#define pula3Linha printf("\n\n\n")

void imprimirObjetivoLab();
int testarDivisibilidade(int dividendo, int divisor);
int divisibilidade2(int num);
int divisibilidade3(int num);
int divisibilidade4(int num);
int divisibilidade5(int num);
int divisibilidade6(int num);
int divisibilidade7(int num);
int divisibilidade8(int num);
int divisibilidade9(int num);
int divisibilidade10(int num);
int divisibilidade11(int num);
int divisibilidade12(int num);
int divisibilidade15(int num);
int divisibilidade25(int num);
int ultimoDigito, somaDigitos, somaDigitosPares, somaDigitosImpares, casaPar;
int divisivel;
char novoTeste,novoTesteInvalido=false;

int dividendo, divisor, divisorInvalido=false;

int main(){
    imprimirObjetivoLab();
    do{
        do{
            pulaLinha;
			printf("Dividendo: ");	scanf(" %d", &dividendo);
            printf("Divisor: ");	scanf(" %d", &divisor);
            pulaLinha;
            
            divisorInvalido = false;
           
		   	if((divisor!=2) && (divisor!=3) && (divisor!=4) && (divisor!=5) && (divisor!=6) && (divisor!=7) && (divisor!=8) && (divisor!=9) && (divisor!=10) && (divisor!=11) && (divisor!=12) && (divisor!=15) && (divisor!=25)){
                divisorInvalido =true;
                pulaLinha;
				printf("Divisor invalido! Favor informar novos valores.");
                pula2Linha;
            }
        }while (divisorInvalido==true);
        
        
        if(testarDivisibilidade(dividendo,divisor)==true){
           	printf("%d eh divisivel por %d", dividendo, divisor);
        } else {
           	printf("%d NAO eh divisivel por %d", dividendo, divisor);
        }
        pula3Linha;
        
		printf("Deseja realizar novo teste (s/n)? ");
        do{
            novoTeste = getche();
            novoTesteInvalido = false;
            if(novoTeste!='S' && novoTeste!='s' && novoTeste!='N' && novoTeste!='n'){
                novoTesteInvalido = true;
                pulaLinha;
				printf("Opcao invalida! Deseja realizar novo teste (s/n)? ");
            }
        }while (novoTesteInvalido == true);
        pula2Linha;
    }while (novoTeste == 'S' || novoTeste == 's');
    printf("Finalizando aplicacao...");
    return 0;
}

void imprimirObjetivoLab(){
    printf("Programa TESTE DE DIVISIBILIDADE");
    pula2Linha;
    printf("O programa tem por objetivo informar se um determinado numero eh ou nao divisivel por outro.");
    pula2Linha;
    printf("Os testes de divisibilidade sao validos para os seguintes divisores: 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15 e 25.");
    pula2Linha;
}

int testarDivisibilidade(int dividendo, int divisor){
    if(divisor==2)  divisivel = divisibilidade2(dividendo);    
    else if(divisor==3)  divisivel = divisibilidade3(dividendo);
    else if(divisor==4)  divisivel = divisibilidade4(dividendo);
    else if(divisor==5)  divisivel = divisibilidade5(dividendo);
    else if(divisor==6)  divisivel = divisibilidade6(dividendo);
    else if(divisor==7)  divisivel = divisibilidade7(dividendo);
    else if(divisor==8)  divisivel = divisibilidade8(dividendo);
    else if(divisor==9)  divisivel = divisibilidade9(dividendo);
    else if(divisor==10)  divisivel = divisibilidade10(dividendo);
    else if(divisor==11)  divisivel = divisibilidade11(dividendo);
    else if(divisor==12)  divisivel = divisibilidade12(dividendo);
    else if(divisor==15)  divisivel = divisibilidade15(dividendo);
    else if(divisor==25)  divisivel = divisibilidade25(dividendo);
    else divisivel = false;
    return divisivel;
}

int divisibilidade2(int num){
    ultimoDigito = num % 10;
    if((ultimoDigito==2) || (ultimoDigito==4) || (ultimoDigito==6) || (ultimoDigito==8) || (ultimoDigito==0)){
        divisivel = true;
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade3(int num){
    do{
        somaDigitos = 0;
        while (num != 0){
            ultimoDigito = num % 10;
            somaDigitos += ultimoDigito;
            num /= 10;
        }
        num = somaDigitos;
    } while (somaDigitos > 9);
    
    if((somaDigitos==3) || (somaDigitos==6) || (somaDigitos==9)){
        divisivel = true;
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade4(int num){
    if(divisibilidade2(num)==true){
        divisivel = divisibilidade2(num/2);
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade5(int num){
    ultimoDigito = num % 10;
    if((ultimoDigito==5) || (ultimoDigito==0)){
        divisivel = true;
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade6(int num){
    divisivel = divisibilidade2(num) * divisibilidade3(num);
    return divisivel;
}

int divisibilidade7(int num){
    do{
        ultimoDigito = num % 10;
        num /= 10;
        num = fabs(num - ultimoDigito * 2);
    } while (num > 70);
    
    if((num==0) || (num==7) || (num==14) || (num==21) || (num==28) || (num==35) || (num==42) || (num==49) || (num==56) || (num==63) || (num==70)){
        divisivel = true;
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade8(int num){
    divisivel = false;
    if(divisibilidade2(num)==true){
        if (divisibilidade2(num/2)==true){
            divisivel = divisibilidade2(num/2/2);
        }
    }
    return divisivel;
}

int divisibilidade9(int num){
    if(divisibilidade3(num)==true){
        divisivel = divisibilidade3(num/3);
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade10(int num){
    ultimoDigito = num % 10;
    if((ultimoDigito==0)){
        divisivel = true;
    } else {
        divisivel = false;
    }
    return divisivel;
}

int divisibilidade11(int num){
    do{
        somaDigitosPares = 0;
        somaDigitosImpares = 0;
        casaPar=false;
        while (num != 0){
            ultimoDigito = num % 10;
            if (casaPar==true){
                somaDigitosPares += ultimoDigito;
            } else {
                somaDigitosImpares += ultimoDigito;
            }
            num /= 10;
            if (casaPar==true){
                casaPar=false;
            } else {
                casaPar=true;
            }
        }
        num = fabs(somaDigitosImpares - somaDigitosPares);
    } while (num > 9);
    
    if(num==0){
        divisivel = 1;
    } else {
        divisivel = 0;
    }
    return divisivel;
}

int divisibilidade12(int num){
    divisivel = divisibilidade3(num) * divisibilidade4(num);
    return divisivel;
}

int divisibilidade15(int num){
    divisivel = divisibilidade3(num) * divisibilidade5(num);
    return divisivel;
}

int divisibilidade25(int num){
    if(divisibilidade5(num)==true){
        divisivel = divisibilidade5(num/5);
    } else {
        divisivel = false;
    }
    return divisivel;
}
