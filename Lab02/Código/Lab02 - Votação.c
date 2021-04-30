/*********************************************************************/
/* Alunos: Kauan Linhares, Lenita Misaki, Pedro Freitas, Vitor Alves */
/* Linguagem de Programação                                          */
/* Prof. Eliane                                                      */
/*********************************************************************/
#include <stdio.h>
#include <string.h>


int main()
{
	char secaoZonaEleitoral[10];
	int numEleitores=0;
	char codUrnaElet[10];

	int numVotos=0, proxEleitor=1;
	int votoInvalido;
	char votoPrefeito[3], votoVereador[3];

	int votosPDB=0, votosPSB=0;
	int votosPref=0, votosVer=0;
	int votosC1=0, votosC2=0, votosC3=0, votosC4=0, votosBrancosPref=0, votosNulosPref=0;
	int votosV1=0, votosV2=0, votosV3=0, votosV4=0, votosBrancosVer=0, votosNulosVer=0;

    char encerraVotacao;
    int respInvalida=1;

    int votosAux=0,votosPref1=0,votosPref2=0,votosPref3=0,votosPref4=0,votosVer1=0,votosVer2=0,votosVer3=0,votosVer4=0;
    char nomeAux[100],nomePref1[100],nomePref2[100],nomePref3[100],nomePref4[100],nomeVer1[100],nomeVer2[100],nomeVer3[100],nomeVer4[100];

	char prefMaisVotado[100], verMaisVotado[100];

	/*1.1 Identificação da Urna Eletrônica*/

	printf("\nIDENTIFICAÇÃO DA URNA ELETRÔNICA\n\n");
	printf("\tIdentificação da Seção e Zona Eleitoral..........: ");scanf(" %s", secaoZonaEleitoral);
	printf("\tTotal dos Eleitores que podem votar..............: ");scanf(" %d", &numEleitores);
	printf("\tCódigo de Identificação da Urna Eletrônica.......: ");scanf(" %s", codUrnaElet);

	/*1.2 Votação Individual*/

	printf("\nVOTAÇÃO INDIVIDUAL\n");
	while (numVotos<numEleitores && proxEleitor==1){
		printf("\n\tEleitor %d\n\n", numVotos+1);
		do{
			votoInvalido=0;
			printf("\t\tVoto ao Candidato à Prefeitura...........: ");scanf(" %s", votoPrefeito);
			if (strcmp(votoPrefeito,"C1")==0){
        		votosC1++;
        		votosPDB++;
        		votosPref++;
        	}else if (strcmp(votoPrefeito,"C2")==0){
        		votosC2++;
        		votosPDB++;
        		votosPref++;
        	}else if (strcmp(votoPrefeito,"C3")==0){
        		votosC3++;
        		votosPSB++;
        		votosPref++;
        	}else if (strcmp(votoPrefeito,"C4")==0){
        		votosC4++;
        		votosPSB++;
        		votosPref++;
        	}else if (strcmp(votoPrefeito,"VB")==0){
        		votosBrancosPref++;
        	}else if (strcmp(votoPrefeito,"VN")==0){
        		votosNulosPref++;
        	}else{
        		printf("\t\t\tVoto Inválido.\n");
        		votoInvalido=1;
        	}
		} while (votoInvalido==1);

		do{
			votoInvalido=0;
			printf("\t\tVoto ao Candidato a Vereador.............: ");scanf(" %s", votoVereador);
			if (strcmp(votoVereador,"V1")==0){
        		votosV1++;
        		votosPDB++;
        		votosVer++;
        	}else if (strcmp(votoVereador,"V2")==0){
        		votosV2++;
        		votosPDB++;
        		votosVer++;
        	}else if (strcmp(votoVereador,"V3")==0){
        		votosV3++;
        		votosPSB++;
        		votosVer++;
        	}else if (strcmp(votoVereador,"V4")==0){
        		votosV4++;
        		votosPSB++;
        		votosVer++;
        	}else if (strcmp(votoVereador,"VB")==0){
        		votosBrancosVer++;
        	}else if (strcmp(votoVereador,"VN")==0){
        		votosNulosVer++;
        	}else{
        		printf("\t\t\tVoto Inválido.\n");
        		votoInvalido=1;
        	}
		} while (votoInvalido==1);
		numVotos++;
        printf("\tVoto número %d Computado\n\n", numVotos);

		if(numVotos<numEleitores){
            do{
                respInvalida=0;
                printf("\tDeseja encerrar a votação? [S/N].................: "); scanf(" %s", &encerraVotacao);
                if(encerraVotacao=='S'){
                    proxEleitor=0;
                }else if(encerraVotacao=='N'){
                    proxEleitor=1;
                }else{
                    printf("\t\tResposta Inválida.\n");
                    respInvalida=1;
                }
            } while (respInvalida==1);
		}
	}
	printf("\nENCERRAMENTO DAS ELEIÇÕES\n\n");

	/*1.3 Totalização dos Votos*/

		votosPref1 = votosC1;	sprintf(nomePref1,"Candidato C1");
		votosPref2 = votosC2;	sprintf(nomePref2,"Candidato C2");
		votosPref3 = votosC3;	sprintf(nomePref3,"Candidato C3");
		votosPref4 = votosC4;	sprintf(nomePref4,"Candidato C4");

	if(votosPref1<votosPref2){
		votosAux=votosPref2;	sprintf(nomeAux,"%s",nomePref2);
		votosPref2=votosPref1;	sprintf(nomePref2,"%s",nomePref1);
		votosPref1=votosAux;	sprintf(nomePref1,"%s",nomeAux);
	}
	if(votosPref1<votosPref3){
		votosAux=votosPref3;	sprintf(nomeAux,"%s",nomePref3);
		votosPref3=votosPref1;	sprintf(nomePref3,"%s",nomePref1);
		votosPref1=votosAux;	sprintf(nomePref1,"%s",nomeAux);
	}
	if(votosPref1<votosPref4){
		votosAux=votosPref4;	sprintf(nomeAux,"%s",nomePref4);
		votosPref4=votosPref1;	sprintf(nomePref4,"%s",nomePref1);
		votosPref1=votosAux;	sprintf(nomePref1,"%s",nomeAux);
	}
	if(votosPref2<votosPref3){
		votosAux=votosPref3;	sprintf(nomeAux,"%s",nomePref3);
		votosPref3=votosPref2;	sprintf(nomePref3,"%s",nomePref2);
		votosPref2=votosAux;	sprintf(nomePref2,"%s",nomeAux);
	}
	if(votosPref2<votosPref4){
		votosAux=votosPref4;	sprintf(nomeAux,"%s",nomePref4);
		votosPref4=votosPref2;	sprintf(nomePref4,"%s",nomePref2);
		votosPref2=votosAux;	sprintf(nomePref2,"%s",nomeAux);
	}
	if(votosPref3<votosPref4){
		votosAux=votosPref4;	sprintf(nomeAux,"%s",nomePref4);
		votosPref4=votosPref3;	sprintf(nomePref4,"%s",nomePref3);
		votosPref3=votosAux;	sprintf(nomePref3,"%s",nomeAux);
	}
	if(votosPref1!=votosPref2){
		sprintf(prefMaisVotado,"O candidato mais votado foi o %s.",nomePref1);
	}else if(votosPref2!=votosPref3){
		sprintf(prefMaisVotado,"Houve um empate entre o %s e o %s.",nomePref1, nomePref2);
	}else if(votosPref3!=votosPref4){
		sprintf(prefMaisVotado,"Houve um empate entre o %s, o %s e o %s.",nomePref1, nomePref2, nomePref3);
	}else{
		sprintf(prefMaisVotado,"Todos os candidatos empataram");
	}

		votosVer1 = votosV1;	sprintf(nomeVer1,"Candidato V1");
		votosVer2 = votosV2;	sprintf(nomeVer2,"Candidato V2");
		votosVer3 = votosV3;	sprintf(nomeVer3,"Candidato V3");
		votosVer4 = votosV4;	sprintf(nomeVer4,"Candidato V4");

	if(votosVer1<votosVer2){
		votosAux=votosVer2;		sprintf(nomeAux,"%s",nomeVer2);
		votosVer2=votosVer1;	sprintf(nomeVer2,"%s",nomeVer1);
		votosVer1=votosAux;		sprintf(nomeVer1,"%s",nomeAux);
	}
	if(votosVer1<votosVer3){
		votosAux=votosVer3;		sprintf(nomeAux,"%s",nomeVer3);
		votosVer3=votosVer1;	sprintf(nomeVer3,"%s",nomeVer1);
		votosVer1=votosAux;		sprintf(nomeVer1,"%s",nomeAux);
	}
	if(votosVer1<votosVer4){
		votosAux=votosVer4;		sprintf(nomeAux,"%s",nomeVer4);
		votosVer4=votosVer1;	sprintf(nomeVer4,"%s",nomeVer1);
		votosVer1=votosAux;		sprintf(nomeVer1,"%s",nomeAux);
	}
	if(votosVer2<votosVer3){
		votosAux=votosVer3;		sprintf(nomeAux,"%s",nomeVer3);
		votosVer3=votosVer2;	sprintf(nomeVer3,"%s",nomeVer2);
		votosVer2=votosAux;		sprintf(nomeVer2,"%s",nomeAux);
	}
	if(votosVer2<votosVer4){
		votosAux=votosVer4;		sprintf(nomeAux,"%s",nomeVer4);
		votosVer4=votosVer2;	sprintf(nomeVer4,"%s",nomeVer2);
		votosVer2=votosAux;		sprintf(nomeVer2,"%s",nomeAux);
	}
	if(votosVer3<votosVer4){
		votosAux=votosVer4;		sprintf(nomeAux,"%s",nomeVer4);
		votosVer4=votosVer3;	sprintf(nomeVer4,"%s",nomeVer3);
		votosVer3=votosAux;		sprintf(nomeVer3,"%s",nomeAux);
	}
	if(votosVer1!=votosVer2){
		sprintf(verMaisVotado,"O candidato mais votado foi o %s.",nomeVer1);
	}else if(votosVer2!=votosVer3){
		sprintf(verMaisVotado,"Houve um empate entre o %s e o %s.",nomeVer1, nomeVer2);
	}else if(votosVer3!=votosVer4){
		sprintf(verMaisVotado,"Houve um empate entre o %s, o %s e o %s.",nomeVer1, nomeVer2, nomeVer3);
	}else{
		sprintf(verMaisVotado,"Todos os candidatos empataram.");
	}

	/*1.4 Divulgação dos Resultados*/

	printf("\tIdentificação da seção e da zona eleitoral.......: %s\n", secaoZonaEleitoral);
	printf("\tTotal de eleitores que podem votar...............: %d\n", numEleitores);
	printf("\tTotal de eleitores que votaram...................: %d\n", numVotos);
	printf("\tTotal de eleitores que faltaram..................: %d\n", numEleitores-numVotos);
	printf("\tCódigo de Identificação da urna eletrônica.......: %s\n", codUrnaElet);
	printf("\tTotal de votos em branco e nulos para prefeito...: %d\n", votosBrancosPref+votosNulosPref);
	printf("\tTotal de votos em branco e nulos para vereador...: %d\n", votosBrancosVer+votosNulosVer);
	printf("\tTotal de votos apurados para prefeito............: %d\n", votosPref);
	printf("\tTotal de votos apurados para vereador............: %d\n\n", votosVer);

	printf("\tTotal de votos para o Partido PDB................: %d\n", votosPDB);
	printf("\tTotal de votos para o Partido PSB................: %d\n\n", votosPSB);

	printf("\tApuração de Votos para Prefeito\n");
	printf("\t\tTotal de votos para o Candidato C1.......: %d\n", votosC1);
	printf("\t\tTotal de votos para o Candidato C2.......: %d\n", votosC2);
	printf("\t\tTotal de votos para o Candidato C3.......: %d\n", votosC3);
	printf("\t\tTotal de votos para o Candidato C4.......: %d\n", votosC4);
	printf("\t\tTotal de votos brancos...................: %d\n", votosBrancosPref);
	printf("\t\tTotal de votos nulos.....................: %d\n\n", votosNulosPref);

	printf("\tApuração de Votos para Vereador\n");
	printf("\t\tTotal de votos para o Candidato V1.......: %d\n", votosV1);
	printf("\t\tTotal de votos para o Candidato V2.......: %d\n", votosV2);
	printf("\t\tTotal de votos para o Candidato V3.......: %d\n", votosV3);
	printf("\t\tTotal de votos para o Candidato V4.......: %d\n", votosV4);
	printf("\t\tTotal de votos brancos...................: %d\n", votosBrancosVer);
	printf("\t\tTotal de votos nulos.....................: %d\n\n", votosNulosVer);

	printf("\tCandidato a Prefeito mais votado.................: %s\n\n", prefMaisVotado);

	printf("\tCandidato a Vereador mais votado.................: %s\n\n", verMaisVotado);
	return 0;
}
