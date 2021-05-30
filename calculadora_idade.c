#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#ifdef __unix__
     
    #include <unistd.h>

#elif defined(_WIN32) || defined(WIN32)

   #define OS_Windows
   #include <windows.h>

#endif


//Feito por Henrique Jucá


int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "");
	
	#ifdef OS_Windows
	
 		//Para Windows
    	//Aceitar acentuação e caracteres especiais
		system("CHCP 1252 >NUL");
    	
	#else
	
    	
	#endif
	
	
	
    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    
    int idade;
    char nome[100];
    int dia;
    int mes;
    int ano;
    int bissexto_nasci;
    int i;
    
    
    
    
    printf("\n - Só use letras, espaços, caracteres especiais ou acentuação no nome da pessoa\n\n");
    
    printf("\nDigite o nome da pessoa: ");//Nome da pessoa
    fgets(nome,99,stdin);
    for(i=0; nome[i]; i++) if(nome[i]=='\n') nome[i]=0;
    
    
    printf("\n\nDigite a data de nascimento de %s:\n\n", nome);
    
    
    do{//Ano de nascimento
    	
    	printf("\n  - Ano (Use valores negativos para a.C.): ");
    	scanf("%d", &ano);
    	
    	if(ano == 0 || tm.tm_year + 1900 < ano){
		
		printf("\nO ano deve ser diferente de zero e igual ou inferior ao ano atual\n");
		
		}
		
    	
	}while(ano == 0 || tm.tm_year + 1900 < ano);
	
	
	
	do{//Mês de nascimento
    	
    	printf("\n  - Mês: ");
    	scanf("%d", &mes);
    	
    	
    	if(mes <= 0 || mes > 12){
		
		printf("\nO mês deve ser diferente de zero e igual ou inferior a doze\n");
		
		}
		
		if(tm.tm_mon + 1 < mes && tm.tm_year + 1900 == ano){
		
		printf("\nO mês deve ser igual ou inferior ao atual, caso o ano seja %d\n", ano);
		
		}
		
		
    	
	}while(mes <= 0 || mes > 12 || (tm.tm_mon + 1 < mes && tm.tm_year + 1900 == ano));
	
	
	
	
	if(mes == 2){
	
		do{
			printf("\nO ano de nascimento é bissexto? (Sim = 1 / Não = 0) : ");//Ainda está vivo
    		scanf("%d", &bissexto_nasci);
    
    
    		if(bissexto_nasci == 1){
		
				//printf("\nÉ bissexto");
		
			}else if(bissexto_nasci == 0){
		
				//printf("\nNão é bissexto");
		
			}else{
		
				printf("\nDigite 1 para Sim ou 0 para Não\n");
		
			}
			
			
		}while(bissexto_nasci < 0 || bissexto_nasci > 1);
		
	}
	
	
    
    for (;;){//Dia do nascimento
    	
    	printf("\n  - Dia: ");
    	scanf("%d", &dia);
    	
    	//Janeiro/Março/Maio/Julho/Agosto/Outubro/Dezembro
    	if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
    		if(dia <= 0 || dia > 31){
    			
    			printf("\nO dia desse mês deve ser um número de 1 a 31\n");
    			
			}	
		}
		
		//Abril/Junho/Setembro/Novembro
		if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
    		if(dia <= 0 || dia > 30){
    			
    			printf("\nO dia desse mês deve ser um número de 1 a 30\n");
    			
			}
		}
		
		//Fevereiro bissexto
		if(mes == 2 && bissexto_nasci == 1){
    		if(dia <= 0 || dia > 29){
    			
    			printf("\nO dia desse mês deve ser um número de 1 a 29\n");
    			
			}
		}
		
		//Fevereiro não bissexto
		if(mes == 2 && bissexto_nasci == 0){
    		if(dia <= 0 || dia > 28){
    			
    			printf("\nO dia desse mês deve ser um número de 1 a 28\n");
    			
			}
		}
		
		
		
		//Bloqueio de data
		if(tm.tm_year + 1900 == ano && tm.tm_mon + 1 == mes && tm.tm_mday < dia){
			
			printf("\nA data digitada não pode ser maior que a atual\n");
			
		}
		
		//Quebrar loop
		if(!(tm.tm_year + 1900 == ano && tm.tm_mon + 1 == mes && tm.tm_mday < dia)){
		
			//Janeiro/Março/Maio/Julho/Agosto/Outubro/Dezembro
			//Terminar loop
			if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
    			if(dia > 0 && dia <= 31){
    			
    				break;
    			
				}	
			}
		
			//Abril/Junho/Setembro/Novembro
			//Terminar loop
			if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
    			if(dia > 0 && dia <= 30){
    			
    				break;
    			
				}
			}
		
			//Fevereiro bissexto
			//Terminar loop
			if(mes == 2 && bissexto_nasci == 1){
    			if(dia > 0 && dia <= 29){
    			
    				break;
    			
				}
			}
		
			//Fevereiro não bissexto
			//Terminar loop
			if(mes == 2 && bissexto_nasci == 0){
    			if(dia > 0 && dia <= 28){
    			
    				break;
    			
				}
			}
		
		
		
		
		}
  	}
    
    
    

    
    
    
    //Para anos d.C.
    if(mes - (tm.tm_mon + 1) <= -1 && ano >= 1){//Mês do aniversário ou depois
    	
    	idade = tm.tm_year + 1900 - ano;
    	
	}else if(mes - (tm.tm_mon + 1) > 0 && ano >= 1){//Mês antes do aniversário
		
		idade = tm.tm_year + 1900 - (ano + 1);
		
	}else if(mes - (tm.tm_mon + 1) == 0 && dia - tm.tm_mday <= 0 && ano >= 1){//Dia do aniversário ou depois
		
		idade = tm.tm_year + 1900 - ano;
		
	}else if(mes - (tm.tm_mon + 1) == 0 && dia - tm.tm_mday > 0 && ano >= 1){//Dia antes do aniversário
		
		idade = tm.tm_year + 1900 - (ano + 1);
		
		
		
	//Para anos a.C.
	}else if(mes - (tm.tm_mon + 1) <= -1 && ano <= -1){//Mês do aniversário ou depois
    	
    	idade = (tm.tm_year + 1900 - ano) -1;
    	
	}else if(mes - (tm.tm_mon + 1) > 0 && ano <= -1){//Mês antes do aniversário
		
		idade = (tm.tm_year + 1900 - (ano + 1)) -1;
		
	}else if(mes - (tm.tm_mon + 1) == 0 && dia - tm.tm_mday <= 0 && ano <= -1){//Dia do aniversário ou depois
		
		idade = (tm.tm_year + 1900 - ano) -1;
		
	}else if(mes - (tm.tm_mon + 1) == 0 && dia - tm.tm_mday > 0 && ano <= -1){//Dia antes do aniversário
		
		idade = (tm.tm_year + 1900 - (ano + 1)) -1;	
		
		
	}else{
		
		printf("\nAlgum valor foi digitado errado\n");
		
	}
	
	
	
	//Limpar terminal
	#ifdef OS_Windows
	
 		//Windows
    	system("cls");
    	
	#else
	
 		//Outros sistemas
    	system("clear");
    	
	#endif
	
	
	
	//Imprimir idade
	if(idade > 1){
		
		printf("\n\t%s tem %d anos\n", nome, idade);
	
	}else if(idade == 0 || idade == 1){
		
		printf("\n\t%s tem %d ano\n", nome, idade);
		
	}else{
		
		printf("\nA idade é um valor negativo\n");
		
	}
	
	
	//O ano é d.C.
	if(dia < 10 && mes < 10 && ano > 0){
		
		printf("\n\tNasceu em: 0%d/0%d/%d\n", dia, mes, ano);
		
	}else if(dia < 10 && mes >= 10 && ano > 0){
		
		printf("\n\tNasceu em: 0%d/%d/%d\n", dia, mes, ano);
		
	}else if(dia >= 10 && mes < 10 && ano > 0){
		
		printf("\n\tNasceu em: %d/0%d/%d\n", dia, mes, ano);
		
	}else if(dia == 10 && mes == 10 && ano > 0){
		
		printf("\n\tNasceu em: %d/%d/%d\n", dia, mes, ano);
		
	//O ano é antes a.C.
		
	}else if(dia < 10 && mes < 10 && ano < 0){
		
		printf("\n\tNasceu em: 0%d/0%d/%d a.C.\n", dia, mes, -ano);
		
	}else if(dia < 10 && mes >= 10 && ano < 0){
		
		printf("\n\tNasceu em: 0%d/%d/%d a.C.\n", dia, mes, -ano);
		
	}else if(dia >= 10 && mes < 10 && ano < 0){
		
		printf("\n\tNasceu em: %d/0%d/%d a.C.\n", dia, mes, -ano);
		
	}else if(dia == 10 && mes == 10 && ano < 0){
		
		printf("\n\tNasceu em: %d/%d/%d a.C.\n", dia, mes, -ano);
		
	//O ano é 0
		
	}else if(dia < 10 && mes < 10 && ano == 0){
		
		printf("\n\tNasceu em: 0%d/0%d/000%d\n", dia, mes, ano);
		
	}else if(dia < 10 && mes >= 10 && ano == 0){
		
		printf("\n\tNasceu em: 0%d/%d/000%d\n", dia, mes, ano);
		
	}else if(dia >= 10 && mes < 10 && ano == 0){
		
		printf("\n\tNasceu em: %d/0%d/000%d\n", dia, mes, ano);
		
	}else if(dia == 10 && mes == 10 && ano == 0){
		
		printf("\n\tNasceu em: %d/%d/000%d\n", dia, mes, ano);
		
	}else{
		
		printf("\nErrado");
		
	}
	
	
	
	printf("\n\n");
	
	
	#ifdef OS_Windows
	
 		//Windows
 		printf("\n Pressione qualquer tecla para terminar...");
    	getch();
    	
    	
	#else
	
 		//Linux
 		printf("\n Pressione qualquer tecla para terminar...\n");
    	getchar();
    	getchar();
    	
	#endif
	
	return 0;
}
