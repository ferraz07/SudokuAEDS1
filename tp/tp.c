#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

#define N 9

#ifdef __unix__
    char * s = "clear";
#else
    char *s = "cls";
#endif

int linha , coluna , numero;
FILE *arquivo;

int facil[N][N] = {{ 0, 6, 0, 1, 0, 4, 0, 5, 0},
 { 0, 0, 0, 3, 0, 5, 6, 0, 0},
 { 2, 0, 4, 0, 0, 0, 0, 0, 1},
 { 8, 0, 0, 4, 0, 7, 0, 0, 6},
 { 0, 0, 6, 0, 0, 0, 3, 0, 0},
 { 7, 0, 0, 9, 0, 1, 0, 0, 4},
 { 5, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 7, 2, 0, 6, 9, 0, 0},
 { 0, 4, 0, 5, 0, 8, 0, 0, 3}};

int medio[N][N] = {{ 0, 0, 0, 1, 0, 4, 0, 0,  0},
 { 0, 0, 0, 0, 0, 5, 0, 0, 0},
 { 0, 0, 4, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 4, 0, 0, 0, 0, 6},
 { 0, 0, 6, 0, 0, 0, 3, 0, 0},
 { 0, 0, 0, 0, 0, 1, 0, 0, 0},
 { 5, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 7, 0, 0, 0, 9, 0, 0},
 { 0, 0, 0, 5, 0, 0, 0, 0, 3}};

int dificil[N][N] =  {{ 0, 0, 0, 0, 0, 4, 0, 0,  0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 4, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 3, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 0, 0, 0, 0, 0, 0, 0},
 { 0, 0, 0, 0, 0, 0, 0, 0, 3}};

 int resolucao[N][N] =  {{ 9, 6, 3, 1, 7, 4, 2, 5,  8},
  { 1, 7, 8, 3, 2, 5, 6, 4, 9},
  { 2, 5, 4, 6, 8, 9, 7, 3, 1},
  { 8, 2, 1, 4, 3, 7, 5, 9, 6},
  { 4, 9, 6, 8, 5, 2, 3, 1, 7},
  { 7, 3, 5, 9, 6, 1, 8, 2, 4},
  { 5, 8, 9, 7, 1, 3, 4, 6, 2},
  { 3, 1, 7, 2, 4, 6, 9, 8, 5},
  { 6, 4, 2, 5, 9, 8, 1, 7, 3}};

int principal[N][N];

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




void inicio_do_jogo(){
    // Menu inicial do jogo
 int numero;
 int i,j;
 system(s);
printf("Bem vindo ao Sudoku");
 printf("\n1| Novo jogo");
 printf("\n2| Carregar");
 printf("\n3| Sair");
 printf("\n0| Regras\n");
 scanf("%d",&numero);
  switch(numero){
    case 1:{
      // o jogo ira iniciar
      system(s);
      dificuldade();
}
      break;

    case 2:{
      arquivo = fopen("save.txt" , "r");
      if(arquivo == NULL){
        printf("Erro ao carregar o jogo.\n");
        exit(1);
}
      for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        fscanf(arquivo, "%d\n", &principal[i][j]);
}}
      geratela();
      break;

    case 3:{
      //O jogo será encerrado
}
    break;

    case 0:{
      // regras do jogo
      system(s);
      printf("O objetivo do jogador %c completar um grid 9x9 (colunas verticais e linhas\n",130);
      printf("horizontais), preenchendo os espa%cos vazios com n%cmeros de 1 a 9. Por%cm, um\n",135,163,130);
      printf("dado n%cmero n%co pode ser repetido na mesma coluna, linha ou bloco. Em\n",163,198);
      printf("outras palavras, basta o jogador preencher o grid com n%cmeros sem repeti-los\n",163);
      printf("na horizontal, vertical ou nos quadrados menores (de 9 c%clulas, quadrados de\n",130);
      printf("tamanho 3x3).\n\n\n\n");
      printf("Caso queira desistir do jogo digite '0' para linha, coluna, n%cmero.\n\n",163);

      int x;

      printf("Digite qualquer n%cmero para voltar ao menu.\n",163);
      scanf("%d",&x);
      switch(x){
      default:{
      return inicio_do_jogo();
      break;
}}}}}

void dificuldade(){
  // menu para a escolha da dificuldade do jogo.
  system(s);
  int num,i,j;

  printf("1| F%ccil",160);
  printf("\n2| M%cdio",130);
  printf("\n3| Dif%ccil\n",161);
  scanf("%d",&num);
  // o switch serve para adicionar os valores da dificuldade escolhida na matriz do jogo.
    switch(num){
      case 1:{
        for(i=0;i<N;i++){
          for(j=0;j<N;j++)
          principal[i][j]= facil[i][j];
}}

      geratela();
      break;

      case 2:{
        for(i=0;i<N;i++){
          for(j=0;j<N;j++){
          principal[i][j]= medio[i][j];
}}}
      geratela();
      break;

      case 3:{
      for(i=0;i<N;i++){
        for(j=0;j<N;j++)
        principal[i][j]= dificil[i][j];
}}
      geratela();
      break;
      default:{
            dificuldade();

}
  break;
}}

void desenha_grade(int principal[N][N]){
  //essa função serve para desenhar o quadro do sudoku
  int i,j;

    printf("   1  2  3   4  5  6   7  8  9   \n");
    printf(" +---------+---------+---------+ \n");
    for (i = 0; i < N; i++) {
      printf("%d|", i+1);
	  for (j = 0; j < N; j++) {
	     if (principal[i][j] != 0)
	      printf(" %d ", principal[i][j]);
	  else
	   printf("   ");
	   if (j % 3 == 2)
	    printf("|");
}
	   if (i % 3 == 2)
	    printf("\n +---------+---------+---------+ ");
	    printf("\n");
}}

void geratela(){
	// essa função serve para adicionar as jogadas
	int linha,coluna,numero,remove_linha,remove_coluna,escolha;
  int i,j;

  system(s);
  desenha_grade(principal);

  printf("\n0| Remover jogada");
  printf("\n1| Adicionar jogada");
  printf("\n2| Salvar o jogo");
  printf("\n3| Resolver sudoku\n");
  scanf("%d",&escolha);

  switch(escolha) {

   case 0: {
    printf("Digite uma linha: ");
 		scanf("%d", &remove_linha);

   	printf("Digite uma coluna: ");
   	scanf("%d", &remove_coluna);
		principal[remove_linha-1][remove_coluna-1] = 0;
}
		return geratela();
		break;

	 case 1:
	linha=0;
	coluna=0;
	numero=0;

    printf("Digite uma linha: ");
    scanf("%d", &linha);

    printf("Digite uma coluna: ");
    scanf("%d", &coluna);

    printf("Digite o n%cmero: ",163);
    scanf("%d", &numero);

    if(linha==0 && coluna==0 && numero==0){
    return inicio_do_jogo();
}
    jogo(linha, coluna, numero);
	  break;

	default:{
		return geratela();
}
  break;

  case 2:{
    arquivo = fopen("save.txt" , "w");
    if(arquivo == NULL){
      printf("Erro ao salvar o jogo.\n");
      exit(1);
}
    for(i=0;i<N;i++){
    	for(j=0;j<N;j++)
    		fprintf(arquivo, "%d\n",principal[i][j]);
}
  fclose(arquivo);
  break;
}

  case 3:{
    system(s);
    printf("SUDOKU RESOLVIDO:\n\n");
    desenha_grade(resolucao);
}
  break;
}}

int coordenadavalida(int linha, int coluna){

  int cont=0;
  if(linha>=0 && linha <9) cont++;
  if(coluna>=0 && coluna <9) cont++;

	if(cont == 2) return 1;
  else return 0;
}

int numerovalido(int numero){

  if(numero>0 && numero <=9){
	return 1;
}
  else{
	return 0;
}}

int checar(int linha, int coluna){

  if (principal[linha][coluna]==0){
	return 1;
}
	else{
	return 0;
}}

int tenta_colocar_linha(int linha, int coluna, int numero){
  int i,cont=0;

  for(i=0;i<N;i++){
    if(numero != principal[i][coluna]) cont++;
}
  if(cont == N ){
  return 1;
}
  else{
  return 0;
}}

int tenta_colocar_coluna(int linha, int coluna, int numero){
  int i,cont=0;

  for(i=0;i<N;i++){
    if(numero != principal[linha][i]) cont++;
}
  if(cont == N ){
    return 1;
}
  else{
    return 0;
}}

int tenta_colocar_matriz(int linha, int coluna, int numero){
  int c,l;

  for (l = 0; l < N; l++)
	 if (principal[l][coluna] == numero)
	 return 0;
  for (c = 0; c < N; c++)
	 if (principal[linha][c] == numero)
	 return 0;
  for (l = linha - linha % 3; l < linha - linha % 3 +3; l++)
	 for (c = coluna - coluna % 3; c < coluna - coluna % 3 + 3; c++)
	  if (principal[l][c] == numero)
	  return 0;
    principal[linha][coluna] = numero;
    desenha_grade(principal);
    return 1;
}

void escreve(int linha, int coluna, int numero){
  principal[linha][coluna]=numero;
}

void jogo(int linha, int coluna, int numero){
  int flag=0;

  if(coordenadavalida(linha-1, coluna)==1){
    flag++;
}
  if(numerovalido(numero)==1){
    flag++;
}
  if(checar(linha-1, coluna-1)==1){
    flag++;
}
  if(tenta_colocar_linha(linha-1, coluna-1, numero)==1){
    flag++;
}
  if(tenta_colocar_coluna(linha-1, coluna-1, numero)==1){
    flag++;
}
  if(tenta_colocar_matriz(linha-1, coluna-1, numero)==1){
    flag++;
}
  if(flag == 6){
   escreve(linha-1, coluna-1, numero);
   if(terminar(principal)==1){
    system(s);
   	printf("DEITOU, VOC%c GANHOU!!!!!!!!\n",210);
}
  else{
    geratela();
}}
  else{
  geratela();
}}

int terminar(int principal[N][N]){
  int i,j,cont=0;
  for(i=0;i<N;i++){
	   for(j=0;j<N;j++){
	   if(principal[i][j]!=0){
	   cont++;
}}}
  if(cont==81){
	return 1;
}
  else{
  return 0;
}}


int main(){
  time_t start=time(NULL);
  inicio_do_jogo();
  time_t diff=time(NULL)-start;
    int hora=0,min=0,segundo=diff;
    while(segundo>60){
    if(segundo>=60){
    	min++;
    	segundo-=60;
}}
	while(min>60){
	if(min>=60){
		hora++;
		min-=60;
}}
  printf("\nVoc%c demorou: %d hora(s) %d minuto(s) %d segundos.\n\n\n",136,hora,min,segundo);
  return 0;
}
