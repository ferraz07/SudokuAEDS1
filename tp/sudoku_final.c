#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h> //Essa biblioteca foi incluida para utilização no cálculo e retorno do tempo de jogo.

//Essa constante foi definida para facilitar a manipulação e declaração das matrizes, comparações nos for e if's.

#define N 9

//Esse ifdef foi utilizado para unificar a função system("clear") e system("cls"), assim funcionando tanto para Windows, quanto para Linux e Unix.

#ifdef __unix__
    char * s = "clear";
#else
    char *s = "cls";
#endif

//Declaração de variaveis globais utilizadas para comparações na matriz principal
//A variável linha serve para percorrer as linhas da matriz.
//A variável coluna serve para percorrer as colunas da matriz.
//A variável número serve para colocar e comparar o número na matriz.

int linha , coluna , numero;

//Declaração do ponteiro utilizado para apontar para o arquivo em que o jogo é salvo e carregado.

FILE *arquivo;

//Essa é a matriz relativamente mais fácil.

int facil[N][N] = {{ 0, 6, 0, 1, 0, 4, 0, 5, 0},
 { 0, 0, 0, 3, 0, 5, 6, 0, 0},
 { 2, 0, 4, 0, 0, 0, 0, 0, 1},
 { 8, 0, 0, 4, 0, 7, 0, 0, 6},
 { 0, 0, 6, 0, 0, 0, 3, 0, 0},
 { 7, 0, 0, 9, 0, 1, 0, 0, 4},
 { 5, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 7, 2, 0, 6, 9, 0, 0},
 { 0, 4, 0, 5, 0, 8, 0, 0, 3}};

//Essa é a matriz de dificuldade mediana.

int medio[N][N] = {{ 0, 0, 0, 1, 0, 4, 0, 0,  0},
 { 0, 0, 0, 0, 0, 5, 0, 0, 0},
 { 0, 0, 4, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 4, 0, 0, 0, 0, 6},
 { 0, 0, 6, 0, 0, 0, 3, 0, 0},
 { 0, 0, 0, 0, 0, 1, 0, 0, 0},
 { 5, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 7, 0, 0, 0, 9, 0, 0},
 { 0, 0, 0, 5, 0, 0, 0, 0, 3}};

//Essa é a matriz mais dificil de resolver do jogo.

int dificil[N][N] =  {{ 0, 0, 0, 0, 0, 4, 0, 0,  0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 4, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 3, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 3}};

//Essa é a matriz utilizada para resolver o Sudoku, partindo do principio que cada tabuleiro só tem uma única resolução.

 int resolucao[N][N] =  {{ 9, 6, 3, 1, 7, 4, 2, 5,  8},
  { 1, 7, 8, 3, 2, 5, 6, 4, 9},
  { 2, 5, 4, 6, 8, 9, 7, 3, 1},
  { 8, 2, 1, 4, 3, 7, 5, 9, 6},
  { 4, 9, 6, 8, 5, 2, 3, 1, 7},
  { 7, 3, 5, 9, 6, 1, 8, 2, 4},
  { 5, 8, 9, 7, 1, 3, 4, 6, 2},
  { 3, 1, 7, 2, 4, 6, 9, 8, 5},
  { 6, 4, 2, 5, 9, 8, 1, 7, 3}};

//Essa é a matriz utilizada no jogo.

int principal[N][N];

//Aqui são as funções utilizadas no decorrer do jogo.

void inicio_do_jogo();
void dificuldade();
void desenha_grade(int principal[N][N]);
void geratela();
int coordenadavalida(int linha, int coluna);
int numerovalido(int numero);
int checar(int linha, int coluna);
int tenta_colocar_linha(int linha, int coluna, int numero);
int tenta_colocar_coluna(int linha, int coluna, int numero);
int tenta_colocar_matriz(int linha, int coluna, int numero);
void escreve(int linha, int coluna, int numero);
void jogo(int linha, int coluna, int numero);
int terminar(int principal[N][N]);

// Menu inicial do jogo

void inicio_do_jogo(){

 int numero; //A váriavel número é utilizada para escolha no switch case, determinando qual a opção do menu será selecionada.
 int i,j; //A variável i serve para percorrer as linhas da matriz enquanto a variável j serve para percorrer as colunas da matriz.
 system(s); //O System(s) é fruto do ifdef declarado inicialmente, sua função é limpar a tela, deixando o jogo visualmente mais limpo.
printf("Bem vindo ao Sudoku");
 printf("\n1| Novo jogo");
 printf("\n2| Carregar");
 printf("\n3| Sair");
 printf("\n0| Regras\n");
 scanf("%d",&numero); //Esse scanf lê para qual parte do menu o jogo será direcionado.
  switch(numero){ //Esse switch serve para direcionar o jogo entre as opções do menu.
    case 1:{ //O jogo irá iniciar.
      system(s); //Limpa a tela.
      dificuldade(); //Chama a função que direciona para escolha da dificuldade do jogo.
}
      break;

    case 2:{ //Será carregado um jogo anteriormente salvo.
      arquivo = fopen("save.txt" , "r"); //Faz com que o ponteiro arquivo aponte para o documento onde o jogo está salvo, na modalidade de leitura.
      if(arquivo == NULL){ //Correção de erro caso não possa, por algum motivo, abrir o arquivo de texto.
        printf("Erro ao carregar o jogo.\n"); //Imprime a mensagem de erro.
        exit(1); //Encerra a execução do arquivo caso não funcione.
}
      for(i=0;i<N;i++){ //Esse for serve para percorrer as linhas, enquanto menores que a constante, ou seja, 9 linhas.
        for(j=0;j<N;j++) //Esse for serve para percorrer as colunas, enquanto menores que a constante, ou seja, 9 colunas.
        fscanf(arquivo, "%d\n", &principal[i][j]); //Faz-se a leitura do arquivo de texto, coletando as informações anteriormente salvas.
}}
      geratela(); //Chama a função que gera a tela do jogo, possibilitando as jogadas.
      break;

    case 3:{ //O jogo será encerrado.
}
    break;

    case 0:{ //Serão mostradas as regras do jogo.
      system(s); //Limpa a tela.
      printf("O objetivo do jogador %c completar um grid 9x9 (colunas verticais e linhas\n",130);
      printf("horizontais), preenchendo os espa%cos vazios com n%cmeros de 1 a 9. Por%cm, um\n",135,163,130);
      printf("dado n%cmero n%co pode ser repetido na mesma coluna, linha ou bloco. Em\n",163,198);
      printf("outras palavras, basta o jogador preencher o grid com n%cmeros sem repeti-los\n",163);
      printf("na horizontal, vertical ou nos quadrados menores (de 9 c%clulas, quadrados de\n",130);
      printf("tamanho 3x3).\n\n\n\n");
      printf("Caso queira desistir do jogo digite '0' para linha, coluna, n%cmero.\n\n",163);

      int x; //A variável x serve para ler um número qualquer que é o gatilho para a volta ao menu inicial do jogo.

      printf("Digite qualquer n%cmero para voltar ao menu.\n",163); //Aqui o número é pedido.
      scanf("%d",&x); //Aqui o número é lido.
      switch(x){ //Esse switch compara o valor da variável x.
      default:{ //Para todos os casos de números o jogo retornará para o menu principal do jogo.
      return inicio_do_jogo(); //Retorna a função do menu principal do jogo.
      break;
}}}}}

void dificuldade(){ //Essa função gera o menu para a escolha da dificuldade do jogo.
  system(s); //Limpa a tela.
  int num,i,j; //A variável num serve para selecionar a dificuldade que será comparada no switch.
              //A variável i serve para percorrer as linhas da matriz enquanto a variável j serve para percorrer as colunas da matriz.

  printf("Escolha a dificuldade:\n\n");
  printf("1| F%ccil",160);
  printf("\n2| M%cdio",130);
  printf("\n3| Dif%ccil\n",161);
  scanf("%d",&num);//Aqui é lido o número, de acordo com os disponibilizados no menu.

    switch(num){ //O switch serve para adicionar os valores da dificuldade escolhida na matriz do jogo.
      case 1:{ //Esse caso gera a matriz da dificuldade Fácil.
        for(i=0;i<N;i++){ //Esse for percorre as linhas da matriz.
          for(j=0;j<N;j++) //Esse for percorre as colunas da matriz.
          principal[i][j]= facil[i][j]; //Aqui a matriz recebe os valores em seus devidos índices.
}}

      geratela(); //Chama a função que gera a tela do jogo, possibilitando as jogadas.
      break;

      case 2:{ //Esse caso gera a matriz da dificuldade Média.
        for(i=0;i<N;i++){ //Esse for percorre as linhas da matriz.
          for(j=0;j<N;j++){ //Esse for percorre as linhas da matriz.
          principal[i][j]= medio[i][j]; //Aqui a matriz recebe os valores em seus devidos índices.
}}}
      geratela(); //Chama a função que gera a tela do jogo, possibilitando as jogadas.
      break;

      case 3:{ //Esse caso gera a matriz da dificuldade Difícil.
      for(i=0;i<N;i++){ //Esse for percorre as linhas da matriz.
        for(j=0;j<N;j++) //Esse for percorre as linhas da matriz.
        principal[i][j]= dificil[i][j]; //Aqui a matriz recebe os valores em seus devidos índices.
}}
      geratela(); //Chama a função que gera a tela do jogo, possibilitando as jogadas.
      break;
      default:{  //Para qualquer outro número digitado a função dificuldade até que seja satisfeito o switch, ou seja, com os numeros 1, 2 ou 3.
            dificuldade(); //Chama a função que direciona para escolha da dificuldade do jogo.
}
  break;
}}

void desenha_grade(int principal[N][N]){ //Essa função serve para desenhar o quadro do sudoku formatado.
  int i,j; //A variável i serve para percorrer as linhas da matriz enquanto a j serve para percorrer as colunas.

    printf("   1  2  3   4  5  6   7  8  9   \n");
    printf(" +---------+---------+---------+ \n");
    for (i = 0; i < N; i++){ //Esse for percorre as linhas incluindo os números ou espaços vazios, seguindo a formatação implementada.
      printf("%d|", i+1);
	  for (j = 0; j < N; j++){ //Esse for percorre as colunas incluindo os números ou espaços vazios, seguindo a formatação implementada.
	     if (principal[i][j] != 0) //Esse if faz a comparação, caso a posição não tenha o número 0, ela imprime o número definido pela matriz principal.
	      printf(" %d ", principal[i][j]);
	  else //Se não, ou seja, se a posição possua um 0 é imprimido um espaço vazio.
	   printf("   ");
	   if (j % 3 == 2) //Se a coluna seja a da esquerda ou direita da matriz 3x3 é impresso esse caractere afim de formatação.
	    printf("|");
}
	   if (i % 3 == 2) //Caso a linha seja a superior ou inferior das matrizes 3x3 são impressos esses caracteres afim de formatação.
	    printf("\n +---------+---------+---------+ ");
	    printf("\n");
}}

void geratela(){ //Essa função é a tela principal do jogo, onde são feitas as jogadas.

  int linha,coluna,numero; //A váriavel linha recolhe o número da linha desejada, a variável coluna recolhe o número da coluna desejada.
  int remove_linha,remove_coluna,escolha; //A variável remove_linha recolhe o número da linha a ser removida, a variável remove_coluna recolhe a coluna a ser removida.
  int i,j; //A variável i percorre as linhas da matriz no for para salvar o jogo, a variável j percorre as colunas da matriz no for para salvar o jogo.

  system(s); //Limpa a tela.
  desenha_grade(principal); //Imprime e formata a matriz principal na tela.

  printf("\n0| Remover jogada");
  printf("\n1| Adicionar jogada");
  printf("\n2| Salvar o jogo");
  printf("\n3| Resolver sudoku\n");
  scanf("%d",&escolha); //Recolhe o numero para a ação a ser tomada pelo switch.

  switch(escolha){ //Esse switch serve para decidir a jogada a ser feita.

   case 0:{ //Nesse caso será removido um número da matriz.
    printf("Digite uma linha: ");
 		scanf("%d", &remove_linha); //Aqui é lido o número da linha.

   	printf("Digite uma coluna: ");
   	scanf("%d", &remove_coluna); //Aqui é lido o número da coluna.
		principal[remove_linha-1][remove_coluna-1] = 0; //Aqui o número é removido na posição indicada anteriormente.
}
		return geratela(); //Essa função é a tela principal do jogo, onde são feitas as jogadas.
		break;

	 case 1:{ //Nesse caso será feita uma jogada.
	linha=0; //A linha é zerada.
	coluna=0; //A coluna é zerada.
	numero=0; //O número é zerado.

    printf("Digite uma linha: ");
    scanf("%d", &linha); //É lida a linha.

    printf("Digite uma coluna: ");
    scanf("%d", &coluna); //É lida a coluna.

    printf("Digite o n%cmero: ",163);
    scanf("%d", &numero); //É lido o Número.

    if(linha==0 && coluna==0 && numero==0){ //Caso a linha, a coluna e o número sejam 0, você desiste da partida e retorna ao menu principal do jogo.
    return inicio_do_jogo(); //Retorna a função do menu principal do jogo.
}
    jogo(linha, coluna, numero); //Aqui a linha, a coluna e o número são enviados para a função jogo que é encarregada de fazer as comparações com a regra do jogo.
}
    break;

	default:{ //Caso o número digitado não seja um número válido, a tela de jogadas é chamada novamente.
		return geratela(); //Essa função é a tela principal do jogo, onde são feitas as jogadas.
}
  break;

  case 2:{ //Nesse caso o jogo será salvo em um arquivo de texto.
    arquivo = fopen("save.txt" , "w"); //O ponteiro arquivo é direcionado a apontar para o arquivo onde o jogo será salvo na modalidade de escrita.
    if(arquivo == NULL){ //Correção de erro, caso, por algum motivo, não seja possível acessar o arquivo de texto.
      printf("Erro ao salvar o jogo.\n"); //É printada na tela a mensagem de erro.
      exit(1); //Finaliza a execução do arquivo de texto.
}
    for(i=0;i<N;i++){ //Esse for percorre as linhas da matriz.
    	for(j=0;j<N;j++) //Esse for percorre as colunas da matriz.
    		fprintf(arquivo, "%d\n",principal[i][j]); //Aqui é escrito no arquivo de texto indíce por indíce os dados da matriz.
}
  printf("\nSeu jogo foi salvo.\n"); //É Exibida a mensagem que o jogo foi salvo corretamente.
  fclose(arquivo); //Encerra a manipulação do arquivo.
  break;
}

  case 3:{ //Nesse caso é chamada a matriz resolvida do sudoku.
    system(s); //Limpa a tela.
    printf("SUDOKU RESOLVIDO:\n\n");
    desenha_grade(resolucao); //Imprime e formata a matriz resolvida na tela.
}
  break;
}}

int coordenadavalida(int linha, int coluna){ //Essa função checa se a linha e a coluna lidas são válidas.

  int cont=0; //Aqui é declarado um contador que será utilizado como parametro de comparação.

  if(linha>=0 && linha <9) cont++; //Aqui compara se a linha está em um intervalo válido.
  if(coluna>=0 && coluna <9) cont++; //Aqui compara se a coluna está em um intervalo válido.

	if(cont == 2) return 1; //Caso o contador compute 2, é retornado o valor 1.
  else return 0; //Caso contrário, será retornado o valor 0.
}

int numerovalido(int numero){ //Essa função checa se o número lido é válido.

  if(numero>0 && numero <=9){ //Aqui compara se o número está no intervalo válido.
	return 1; //Caso seja, é retornado o valor 1.
}
  else{
	return 0; //Caso contrário, será retornado o valor 0.
}}

int checar(int linha, int coluna){ //Essa função checa se a linha e a coluna lidas estão vazias.

  if (principal[linha][coluna]==0){ //Aqui é comparado se o índice indicado está vazio.
	return 1; //Caso esteja, é retornado o valor 1.
}
	else{
	return 0; //Caso contrário, é retornado o valor 0.
}}

int tenta_colocar_linha(int linha, int coluna, int numero){ //Essa função faz comparações para ver se é possível colocar o número na linha indicada.

  int i,cont=0; //A variável i serve para percorre as linhas da matriz e a variável cont serve para fazer a comparação se é possível ser colocado o número.

  for(i=0;i<N;i++){ //Esse for percorre as linhas da matriz.
    if(numero != principal[i][coluna]) cont++; //Se o número não for igual a algum número que já esteja na horizontal o contador computa +1.
}
  if(cont == N ){ //Se o contador tiver computado 9 será retornado o valor 1.
  return 1; //É retornado o valor 1.
}
  else{ //Caso contrário, será retornado o valor 0.
  return 0; //É retornado o valor 0.
}}

int tenta_colocar_coluna(int linha, int coluna, int numero){ //Essa função faz comparações para ver se é possível colocar o número na coluna indicada.

  int i,cont=0; //A variável i serve para percorre as colunas da matriz e a variável cont serve para fazer a comparação se é possível ser colocado o número.

  for(i=0;i<N;i++){ //Esse for percorre as colunas da matriz.
    if(numero != principal[linha][i]) cont++; //Se o número não for igual a algum número que já esteja na vertical o contador computa +1.
}
  if(cont == N ){ //Se o contador tiver computado 9 será retornado o valor 1.
    return 1; //É retornado o valor 1.
}
  else{ //Caso contrário, será retornado o valor 0.
    return 0; //É retornado o valor 0.
}}

int tenta_colocar_matriz(int linha, int coluna, int numero){ //Essa função faz comparações para ver se é possível colocar o número no quadrante indicado.

  int c,l; //A variável c serve para percorre as colunas da matriz e a variável i serve para percorrer as linhas da matriz.

  for (l = 0; l < N; l++) //Esse for percorre as linhas.
	 if (principal[l][coluna] == numero) //Caso em algum lugar na linha haja o número é retornado o valor 0.
	 return 0; //É retornado o valor 0.
  for (c = 0; c < N; c++) //Esse for percorre as colunas.
	 if (principal[linha][c] == numero) //Caso em algum lugar na coluna haja o número é retornado o valor 0.
	 return 0; //É retornado o valor 0.
  for (l = linha - linha % 3; l < linha - linha % 3 +3; l++) //Esse for percorre a linha em um tamanho de 3.
	 for (c = coluna - coluna % 3; c < coluna - coluna % 3 + 3; c++) //Esse for percorre a linha em um tamanho de 3.
	  if (principal[l][c] == numero) //Caso nesse quadrante o número lido já esteja encontrado é retornado o valor 0.
	  return 0; //É retornado o valor 0.
    principal[linha][coluna] = numero; //Caso possa ser escrito, o número é enviado para a posição indicada anteriormente.
    desenha_grade(principal); //Imprime e formata a matriz principal na tela.
    return 1; //É retornado o valor 1.
}

void escreve(int linha, int coluna, int numero){ //Essa função tem a responsabilidade apenas de escrever, na posição indicada, o número na matriz.
  principal[linha][coluna]=numero; //O número é escrito na posição indicada na matriz principal.
}

void jogo(int linha, int coluna, int numero){ //Essa função é encarregada de verificar as regras do jogo para tornar possível as jogadas.

  int flag=0; //Essa variável flag serve para comparações.

  if(coordenadavalida(linha-1, coluna)==1){ //Esse if compara se a função coordenadavalida está retornando o valor 1.
    flag++; //Se sim, a flag computa +1.
}
  if(numerovalido(numero)==1){ //Esse if compara se a função numerovalido está retornando o valor 1.
    flag++; //Se sim, a flag computa +1.
}
  if(checar(linha-1, coluna-1)==1){ //Esse if compara se a função checar está retornando o valor 1.
    flag++; //Se sim, a flag computa +1.
}
  if(tenta_colocar_linha(linha-1, coluna-1, numero)==1){ //Esse if compara se a função tenta_colocar_linha está retornando o valor 1.
    flag++; //Se sim, a flag computa +1.
}
  if(tenta_colocar_coluna(linha-1, coluna-1, numero)==1){ //Esse if compara se a função tenta_colocar_coluna está retornando o valor 1.
    flag++; //Se sim, a flag computa +1.
}
  if(tenta_colocar_matriz(linha-1, coluna-1, numero)==1){ //Esse if compara se a função tenta_colocar_matriz está retornando o valor 1.
    flag++; //Se sim, a flag computa +1.
}
  if(flag == 6){ //Se a flag tiver computado 6, a função escreve pode ser chamada.
   escreve(linha-1, coluna-1, numero); //Aqui é escrito o número lido na posição indicada na matriz principal.
   if(terminar(principal)==1){ //Se a função terminar esteja retornando o valor 1, o jogo será encerrado.
    system(s); //Limpa a tela.
   	printf("DEITOU, VOC%c GANHOU!!!!!!!!\n",210); //É printada a mensagem de congratulação e o jogo será encerrado.
}
  else{ //Caso a função terminar ainda não tenha o retorno do número 1.
    geratela(); //A função que possibilita as jogadas é chamada.
}}
  else{ //Se a flag não tiver computado 6 é chamada a função geratela.
  geratela(); //É chamada a função que possibilita as jogadas.
}}

int terminar(int principal[N][N]){ //Essa função está encarregada de verificar se a matriz está completa.
  int i,j,cont=0; //A variável i serve para percorrer as linhas da matriz, a variável j serve para percorrer as colunas da matriz e o contador é para comparações.
  for(i=0;i<N;i++){ //Esse for percorre as linhas.
	   for(j=0;j<N;j++){ //Esse for percorre as colunas.
	   if(principal[i][j]!=0){ //Compara se não há posições com o valor 0.
	   cont++; //O contador computa quantas posições não estão vazias.
}}}
  if(cont==81){ //Caso o contador compute 81, o jogo será encerrado.
	return 1; //Retorna o valor 1 que é o valor que valida o if na função jogo, fazendo com o que o jogo se encerre.
}
  else{ //Caso contrário, o jogo se manterá funcionando normalmente.
  return 0; //É retornado o valor 0.
}}

int main(){ //Essa é a função main, onde o jogo é jogado.
  time_t start=time(NULL); //Essa função serve para iniciar a contagem do tempo em que o jogo ficou aberto.
  inicio_do_jogo(); //Aqui é chamado o menu principal do jogo para que ele comece a ser jogado.
  time_t diff=time(NULL)-start; //Essa função retorna o valor do tempo final subtraído do tempo inicial, ou seja, o tempo em que o jogo ficou aberto.
    int hora=0,min=0,segundo=diff; //A variável hora serve para armazenar a quantidade de horas, a variável min serve para armazenar a quantidade de minutos e a variável segundo, armazena o resultado da função do tempo do jogo em geral.
    while(segundo>60){ //Esse while compara se os segundos estão maior que 60.
    if(segundo>=60){ //Se os segundos forem maiores que 60, os minutos serão incrementados.
    	min++; //Os minutos sendo incrementados.
    	segundo-=60; //É subtraído o valor de 1 minuto, ou seja, 60 segundos da variável segundos.
}}
	while(min>60){ //Esse while compara se os minutos estão maior que 60.
	if(min>=60){ //Se os minutos forem maiores que 60, as horas serão incrementadas.
		hora++; //As horas sendo incrementadas.
		min-=60; //É subtraído o valor de 1 hora, ou seja, 60 minutos da variável minutos.
}}
  printf("\nVoc%c demorou: %d hora(s) %d minuto(s) %d segundos.\n\n\n",136,hora,min,segundo); //Aqui é printado o tempo em que o jogo ficou aberto.
  return 0;
}
