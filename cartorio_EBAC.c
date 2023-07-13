//as bibliotecas são as primeiras coisas que devem ser adc em um codigo
//o comanodo include serve para incluir coisas, nesse caso foram incluidas bibliotecas necessárias para o software
#include <stdio.h> //biblioteca de comunicação com  o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //função registro, responsável por cadastrar os usuários no sistema
{
	//inicio da criação das variáveis/strings(conjunto de variáveis)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char contato[100];
	//final das variáveis
	
	printf("Digite o CPF (para brasileiros) ou o RNE (para estrangeiros) a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s se refere a string, está armazenando o cpf na string cpf
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria um arquivo para armazenar as informações inseridas pelo usuário
	file = fopen(arquivo, "W"); //o "W" cria o arquivo
	fprintf(file,cpf); //vai salvar o valor da variável CPF no arquivo 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //o "a" abre o arquivo que foi criado anteiormente
	fprintf(file,"\n"); //agora estamos adc o \n para dar enter pois espaça melhor as informações e facilita para o cliente
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //momento que o usuário digita o nome para cadastro
	scanf("%s",nome); //salva o nome na variável nome
	
	file = fopen(arquivo,"a"); //abertura do arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); 
	fprintf(file,"\t"); //o \t nesse caso foi utilizado para espaçar o nome do sobrenome, pois os restantes dos dados são apresentados em linhas diferentes
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
	file = fopen(cpf,"r"); // o"r" é para rodar o arquivo, no caso, ler
	
	if(file == NULL) //quando o arquivo for "nulo/inexistente", deverá apresentar a frase abaixo para o usuário ser alertado
	{
		printf("Não foi possível localizar o cadastro, revise os dados! \n");
		system("pause");
	}
	
	printf("\nEssas são as informações do cadastro: "); 
	
	while(fgets(conteudo, 200, file) != NULL) //quando o ID do usuário (no caso, cpf) for digitado corretamente, acionará esse comando que mostrará os dados cadastrados na ID
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
	
	printf("Digite o CPF ou RNE a ser deletado: "); //o usuário digita o ID do cadastro que deseja deletar
	scanf("%s",cpf);
		
	remove(cpf); //comando deletar que já esta incluso em uma das bilbiotecas adc no inicio deste codigo
	
	FILE *file;
	file = fopen(cpf,"r"); //novamente rodando o arquivo CPF pois cada função precisa rodar
	
	if (file == NULL) //quando o arquivo for "nulo/inexistente", deverá apresentar a frase abaixo para o usuário ser alertado
	{
		printf("Cadastro deletado com sucesso! \n");
		system("pause");
	}
		
	fclose(file);
	system("pause"); //sempre usamos o system pause para parar a tela e o usuário conseguir ler a mensagem
}


int main () //sempre que for iniciar uma função, deve colotar os parenteses depois as chaves, o que estiver dentro das chaves é a função - neste caso a função MAIN é para definirmos variáveis
{
	int opcao=0;  //definindo as variaveis, por "bom costume" sempre utilizar o numero 0
	int laco=1;
		
	for(laco=1;laco=1;) //FOR significa repita, faça qtas vezes eu solicitar	
	{
		system ("cls"); //responsável por limpar a tela
		
		setlocale(LC_ALL,"Portuguese"); //definição da linguagem
	
		printf("\tSeja Bem Vindo ao Cartório da EBAC! \n\n"); //titulo do menu, inicio
		printf("Escolha a opção desejada no menu abaixo:\n\n"); //o barra N é para dar um enter
		printf("\t1 - Novo cadastro\n"); //o barra T é para dar um espaçamento tipo um tab
		printf("\t2 - Consultar banco de dados\n");
		printf("\t3 - Deletar cadastro\n\n"); 
		printf("Opção:"); //fim do menu de opções
	
		scanf("%d", &opcao); //o comando SCANF serve para armazenar a escolha do usuário dentro da variavel, possui diversas poncentagens e caracteres, depende da necessidade, o & serve para definir em qual variavel será armazenada a esolha do usuário, ela foi colocada la em cima já **olhar no material para saber qual usar em outros casos
	
		system("cls"); //esse comando serve para "limpar a tela" nesse caso a tela vai ser limpa depois que o usuário escolher a opção que deseja
	
		switch(opcao) //é uma minimzação do comando IF, para menus é util - inicio da seleção do menu
		{
			case 1: //para iniciar é preciso usar :
			registro(); //chamada de funções
			break; //para finalizar utilizar a palavra break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
					
			default: 
			printf("Essa opção não está disponível, revise o menu de opções!\n");
			system("pause");
			break;
		}
	
    }
}


