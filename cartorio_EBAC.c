//as bibliotecas s�o as primeiras coisas que devem ser adc em um codigo
//o comanodo include serve para incluir coisas, nesse caso foram incluidas bibliotecas necess�rias para o software
#include <stdio.h> //biblioteca de comunica��o com  o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //fun��o registro, respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o das vari�veis/strings(conjunto de vari�veis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char contato[100];
	//final das vari�veis
	
	printf("Digite o CPF (para brasileiros) ou o RNE (para estrangeiros) a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s se refere a string, est� armazenando o cpf na string cpf
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; //cria um arquivo para armazenar as informa��es inseridas pelo usu�rio
	file = fopen(arquivo, "W"); //o "W" cria o arquivo
	fprintf(file,cpf); //vai salvar o valor da vari�vel CPF no arquivo 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //o "a" abre o arquivo que foi criado anteiormente
	fprintf(file,"\n"); //agora estamos adc o \n para dar enter pois espa�a melhor as informa��es e facilita para o cliente
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //momento que o usu�rio digita o nome para cadastro
	scanf("%s",nome); //salva o nome na vari�vel nome
	
	file = fopen(arquivo,"a"); //abertura do arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); 
	fprintf(file,"\t"); //o \t nesse caso foi utilizado para espa�ar o nome do sobrenome, pois os restantes dos dados s�o apresentados em linhas diferentes
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,sobrenome); 
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,"\n"); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,cargo); 
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,"\n"); 
	fclose(file);
	
	printf("Digite um e-mail para contato a ser cadastrado: ");
	scanf("%s",contato);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,contato); 
	fclose(file);
	
	file = fopen(arquivo,"a"); 
	fprintf(file,"\n"); 
	fclose(file);
	
	system("pause");
}

int consulta()
{ 
	setlocale(LC_ALL,"Portuguese"); 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF ou RNE a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // o"r" � para rodar o arquivo, no caso, ler
	
	if(file == NULL) //quando o arquivo for "nulo/inexistente", dever� apresentar a frase abaixo para o usu�rio ser alertado
	{
		printf("N�o foi poss�vel localizar o cadastro, revise os dados! \n");
		system("pause");
	}
	
	printf("\nEssas s�o as informa��es do cadastro: "); 
	
	while(fgets(conteudo, 200, file) != NULL) //quando o ID do usu�rio (no caso, cpf) for digitado corretamente, acionar� esse comando que mostrar� os dados cadastrados na ID
	{
		
		printf("%s", conteudo); //aqui estamos puxando os dados do cadastro consultado 
		printf("\n");
	}

	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF ou RNE a ser deletado: "); //o usu�rio digita o ID do cadastro que deseja deletar
	scanf("%s",cpf);
		
	remove(cpf); //comando deletar que j� esta incluso em uma das bilbiotecas adc no inicio deste codigo
	
	FILE *file;
	file = fopen(cpf,"r"); //novamente rodando o arquivo CPF pois cada fun��o precisa rodar
	
	if (file == NULL) //quando o arquivo for "nulo/inexistente", dever� apresentar a frase abaixo para o usu�rio ser alertado
	{
		printf("Cadastro deletado com sucesso! \n");
		system("pause");
	}
		
	fclose(file);
	system("pause"); //sempre usamos o system pause para parar a tela e o usu�rio conseguir ler a mensagem
}


int main () //sempre que for iniciar uma fun��o, deve colotar os parenteses depois as chaves, o que estiver dentro das chaves � a fun��o - neste caso a fun��o MAIN � para definirmos vari�veis
{
	int opcao=0;  //definindo as variaveis, por "bom costume" sempre utilizar o numero 0
	int laco=1;
		
	for(laco=1;laco=1;) //FOR significa repita, fa�a qtas vezes eu solicitar	
	{
		system ("cls"); //respons�vel por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //defini��o da linguagem
	
		printf("\tSeja Bem Vindo ao Cart�rio da EBAC! \n\n"); //titulo do menu, inicio
		printf("Escolha a op��o desejada no menu abaixo:\n\n"); //o barra N � para dar um enter
		printf("\t1 - Novo cadastro\n"); //o barra T � para dar um espa�amento tipo um tab
		printf("\t2 - Consultar banco de dados\n");
		printf("\t3 - Deletar cadastro\n\n"); 
		printf("Op��o:"); //fim do menu de op��es
	
		scanf("%d", &opcao); //o comando SCANF serve para armazenar a escolha do usu�rio dentro da variavel, possui diversas poncentagens e caracteres, depende da necessidade, o & serve para definir em qual variavel ser� armazenada a esolha do usu�rio, ela foi colocada la em cima j� **olhar no material para saber qual usar em outros casos
	
		system("cls"); //esse comando serve para "limpar a tela" nesse caso a tela vai ser limpa depois que o usu�rio escolher a op��o que deseja
	
		switch(opcao) //� uma minimza��o do comando IF, para menus � util - inicio da sele��o do menu
		{
			case 1: //para iniciar � preciso usar :
			registro(); //chamada de fun��es
			break; //para finalizar utilizar a palavra break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
					
			default: 
			printf("Essa op��o n�o est� dispon�vel, revise o menu de op��es!\n");
			system("pause");
			break;
		}
	
    }
}


