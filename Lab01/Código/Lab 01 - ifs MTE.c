/*********************************************************************/
/* Alunos: Kauan Linhares, Lenita Misaki, Pedro Freitas, Vitor Alves */
/* Linguagem de Programação                                          */
/* Prof. Eliane                                                      */
/*********************************************************************/
#include <stdio.h>

int main()
{
    char aux, R1, R2;
    int tempoDeVinculo=0, parcelasFuturas=0, parcelasPassadas=0, quantDeParcelas=0, salariosZerados=0, quantDeSalarios=0;
    float ultimoSalario=0, penultimoSalario=0, antepenultimoSalario=0, mediaSalarial=0, valorBeneficio=0;
    
    printf("[R1] Verificação de direito ao benefício:\n");
    printf("\nÉ trabalhador formal? ([S]/[N]) ..............................: ");
    scanf(" %c", &aux);
    if(aux == 'S'){
        printf("É trabalhador doméstico? ([S]/[N]) ...........................: ");
        scanf(" %c", &aux);
        if(aux == 'N'){
            R1 = 'A';
        }else{
            R1 = 'B';
        }
    }else{
        printf("É trabalhador com bolsa de qualificação social? ([S]/[N]).....: ");
        scanf(" %c", &aux);
        if(aux == 'S'){
            R1 = 'C';
        }else{
            printf("É pescador artesanal? ([S]/[N]) ..............................: ");
            scanf(" %c", &aux);
            if(aux == 'S'){
                R1 = 'D';
            }else{
                printf("É trabalhador resgatado? ([S]/[N]) ...........................: ");
                scanf(" %c", &aux);
                if(aux == 'S'){
                    R1 = 'E';
                }else{
                    printf("Trabalhador sem direito ao benefício.");
                    return 0;
                }
            }
        }
    }

    printf("\n[R2] Verificação de condições para receber o benefício:\n");
    if(R1=='A'){
        printf("\nFoi dispensado sem justa causa? ([S]/[N]) ....................: ");
        scanf(" %c", &aux);
        if(aux == 'S'){
            printf("Recebeu salários de pessoa jurídica ou pessoa física, no período de 6 meses consecutivos, imediatamente anteriores à data de dispensa? ([S]/[N]): ");
            scanf(" %c", &aux);
            if(aux == 'S'){
                printf("Está desempregado no momento do requerimento do benefício? ([S]/[N]): ");
                scanf(" %c", &aux);
                if(aux == 'S'){
                    printf("Possui renda própria de qualquer natureza suficiente à sua manutenção e a de sua família? ([S]/[N]): ");
                    scanf(" %c", &aux);
                    if(aux == 'N'){
                        printf("Está em gozo de algum benefício previdenciário de prestação continuada, com exceção do auxílio-acidente e pensão por morte? ([S]/[N]): ");
                        scanf(" %c", &aux);
                        if(aux == 'N'){
                            printf("Esteve empregado de pessoa jurídica ou de pessoa física equiparada à jurídica, pelo menos 6 meses nos últimos 36 meses que antecedam a data de dispensa? ([S]/[N]): ");
                            scanf(" %c", &aux);
                            if(aux == 'S'){
                                R2='S';
                            }
                        }
                    }
                }
            }    
        }
    }else if(R1=='B'){
        printf("\nFoi dispensado sem justa causa? ([S]/[N]) ....................: ");
        scanf(" %c", &aux);
        if(aux == 'S'){
            printf("Trabalhou, exclusivamente, como empregado doméstico, pelo período mínimo de 15 meses nos últimos 24 meses que antecederam a data de dispensa que deu origem ao requerimento do seguro-desemprego? ([S]/[N]): ");
            scanf(" %c", &aux);
            if(aux == 'S'){
                printf("Possui renda própria de qualquer natureza suficiente à sua manutenção e a de sua família? ([S]/[N]):");
                scanf(" %c", &aux);
                if(aux == 'N'){
                    printf("Está em gozo de algum benefício previdenciário de prestação continuada, com exceção do auxílio-acidente e pensão por morte? ([S]/[N]): ");
                    scanf(" %c", &aux);
                    if(aux == 'N'){
                        R2='S';
                    }
                }
            }
        }
    }else if(R1=='C'){
        printf("\nEstá com o contrato de trabalho suspenso, em conformidade com o disposto em convenção ou acordo coletivo, devidamente matriculado em curso ou programa de qualificação profissional oferecido pelo empregador. A periodicidade, os valores e a quantidade de parcelas são os mesmos do benefício para o trabalhador formal, conforme o tempo de duração do curso de qualificação profissional. ([S]/[N]): ");
        scanf(" %c", &aux);
        if(aux == 'S'){
            R2='S';
        }
    }else if(R1=='D'){
        printf("\nPossui inscrição no INSS como segurado especial? ([S]/[N]) ...: ");
        scanf(" %c", &aux);
        if(aux == 'S'){
            printf("Possui comprovação de venda do pescado a adquirente pessoa jurídica ou cooperativa, no período correspondente aos últimos 12 meses que antecederam ao início do defeso? ([S]/[N]): ");
            scanf(" %c", &aux);
            if(aux == 'S'){
                printf("Está em gozo de algum benefício de prestação continuada da Previdência Social ou da Assistência Social, exceto auxílio-acidente ou pensão por morte? ([S]/[N]) ..................: ");
                scanf(" %c", &aux);
                if(aux == 'N'){
                    printf("Pode comprovar o exercício profissional da atividade de pesca artesanal objeto do defeso e que se dedicou à pesca, em caráter ininterrupto, durante o período compreendido entre o defeso anterior e o em curso? ([S]/[N]) .....: ");
                    scanf(" %c", &aux);
                    if(aux == 'S'){
                        printf("Possui vínculo de emprego ou outra relação de trabalho ou outra fonte de renda diversa da decorrente da atividade pesqueira? ([S]/[N]) .....................................: ");
                        scanf(" %c", &aux);
                        if(aux == 'N'){
                            R2='S';
                        }
                    }
                }
            }
        }
    }else if(R1=='E'){
        printf("\nFoi comprovadamente resgatado do regime de trabalho forçado ou da condição análoga à de escravo em decorrência de ação de fiscalização do MTE? ([S]/[N]) .....: ");
        scanf(" %c", &aux);
        if(aux == 'S'){
            printf("Está em gozo de algum benefício previdenciário de prestação continuada, com exceção do auxílio-acidente e pensão por morte? ([S]/[N]) ..........................: ");
            scanf(" %c", &aux);
            if(aux == 'N'){
                printf("Possui renda própria de qualquer natureza suficiente à sua manutenção e a de sua família? ([S]/[N]) ............................................................: ");
                scanf(" %c", &aux);
                if(aux == 'N'){
                    R2='S';
                }
            }
        }
    }
    
    if(R2!='S'){
        printf("\nTrabalhador com direito ao benefício.");
        printf("\nO trabalhador NÃO ATENDE as condições para receber do benefício.");
        return 0;
    }
    
    printf("\n[R3] Definição da quantidade de parcelas:\n");
    printf("\nO trabalhador já recebeu o benefício nos últimos 16 meses (período aquisitivo)? ([S]/[N]) .....: ");
    scanf(" %c", &aux);
    if(aux == 'S'){
        printf("Quantas parcelas foram recebidas? .....: ");
        scanf("%d", &parcelasPassadas);
        if(parcelasPassadas > 4){
            printf("O limite de parcelas do benefício dentro do período aquisitivo já foi atingido.");
            return 0;
        }
    }
    
    printf("Por quantos meses o trabalhador pode comprovar vínculo empregatício nos últimos 36 meses? .....: ");
    scanf("%d", &tempoDeVinculo);
    
    if(tempoDeVinculo<6){
        printf("Tempo insuficiente de vínculo empregatício.");
        return 0;
    }else{
        if(tempoDeVinculo<12){
            parcelasFuturas = 3;
        }else{
            if(tempoDeVinculo<24){
                parcelasFuturas = 4;
            }else{
                parcelasFuturas = 5;
            }
        }
        if((parcelasPassadas+parcelasFuturas)>5){
            quantDeParcelas = 5 - parcelasPassadas;
        }else{
            quantDeParcelas=parcelasFuturas;
        }
    }
    
    printf("\n\n[R4] Definição do valor do benefício:\n");
    printf("\nEntre com o valor do salário do último mês. .........: ");
    scanf("%f", &ultimoSalario);
    printf("Entre com o valor do salário do penúltimo mês. ......: ");
    scanf("%f", &penultimoSalario);
    printf("Entre com o valor do salário do antepenúltimo mês. ..: ");
    scanf("%f", &antepenultimoSalario);
    
    if (ultimoSalario == 0) {
        salariosZerados=salariosZerados+1;
    }
    if (penultimoSalario == 0) {
        salariosZerados=salariosZerados+1;
    }
    if (antepenultimoSalario == 0) {
        salariosZerados=salariosZerados+1;
    }
    
    quantDeSalarios = 3-salariosZerados;
    
    mediaSalarial = (ultimoSalario+penultimoSalario+antepenultimoSalario)/quantDeSalarios;
    
    if(mediaSalarial<=1222.77){
        valorBeneficio=mediaSalarial*0.8;
        if (valorBeneficio<788){
            valorBeneficio=788;
        }
    }else{
        if(mediaSalarial<=2038.15){
            valorBeneficio=978.22+(mediaSalarial-1222.77)*0.5;
        }else{
            valorBeneficio=1385.91;
        }
    }
    
    printf("\nTrabalhador com direito ao benefício.");
    printf("\nO trabalhador atende as condições para receber do benefício.\n");
    
    printf("\n\nCálculo de Parcelas:\n");
    printf("\nTempo de vínculo em número de meses: .....: %d \n", tempoDeVinculo);
    printf("\n[A] Salário do último mês: ...............: %.2f", ultimoSalario);
    printf("\n[B] Salário do penúltimo mês: ............: %.2f", penultimoSalario);
    printf("\n[C] Salário do antepenúltimo mês: ........: %.2f \n", antepenultimoSalario);
    printf("\nMédia salarial (A+B+C)/%d .................: %.2f\n", quantDeSalarios, mediaSalarial);
    printf("\nQuantidade de parcelas ...................: %d \n", quantDeParcelas);
    printf("\nValor do benefício .......................: %.2f", valorBeneficio);
    
    return 0;
}





