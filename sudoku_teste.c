#include<stdio.h>
#include<stdlib.h>
#define N 9
#ifdef __unix__
    char * s = "clear";
#else
    char *s = "cls";
#endif

int linha , coluna , numero;

int facil[N][N] = {{ 0, 6, 0, 1, 0, 4, 0, 5,  0},
 { 0, 0, 8, 3, 0, 5, 6, 0, 0},
 { 2, 0, 0, 0, 0, 0, 0, 0, 1},
 { 8, 0, 0, 4, 0, 7, 0, 0, 6},
 { 0, 0, 6, 0, 0, 0, 3, 0, 0},
 { 7, 0, 0, 9, 0, 1, 0, 0, 4},
 { 5, 0, 0, 0, 0, 0, 0, 0, 2},
 { 0, 0, 7, 2, 0, 6, 9, 0, 0},
 { 0, 4, 0, 5, 0, 8, 0, 7, 0}};


int medio[N][N] = {{ 0, 0, 0, 1, 0, 4, 0, 0,  0},
   { 0, 0, 8, 0, 0, 5, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 4, 0, 0, 0, 0, 6},
   { 0, 0, 6, 0, 0, 0, 3, 0, 0},
   { 0, 0, 0, 0, 0, 1, 0, 0, 0},
   { 5, 0, 0, 0, 0, 0, 0, 0, 2},
   { 0, 0, 7, 0, 0, 0, 9, 0, 0},
   { 0, 0, 0, 5, 0, 0, 0, 7, 0}};


int dificil[N][N] =  {{ 0, 0, 0, 0, 0, 4, 0, 0,  0},
   { 0, 0, 8, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0, 3, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 0, 0, 0, 0, 0, 2},
   { 0, 0, 0, 0, 0, 0, 0, 0, 0},
   { 0, 0, 0, 5, 0, 0, 0, 0, 0}};


int principal[N][N];



  void inicio_do_jogo(){
    // Menu inicial do jogo
    int numero;
    //system(s);
    printf("Bem vindo ao sudoku!\n");
    printf("1| Novo jogo\n");
    printf("0| Regras\n");
    scanf("%d",&numero);
    switch(numero){
      case 1:{
        // o jogo ira iniciar
        ////system(s);
    printf("Boa sorte!\n");
    dificuldade();
    }
    break;
      case 0:{
      // regras do jogo
     //system(s);
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
    }
    }
    }
    }
    }

    void dificuldade(){
      // menu para a escolha da dificuldade do jogo.
      //system(s);
      int num,i,j;
      printf("Escolha a dificuldade do jogo.\n");
      printf("1| F%ccil\n",160);
      printf("2| M%cdio\n",130);
      printf("3| Dif%ccil\n",161);
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
            for(j=0;j<N;j++)
            principal[i][j]= medio[i][j];
          }}
            geratela();
      break;

      case 3:{
      for(i=0;i<N;i++){
          for(j=0;j<N;j++)
          principal[i][j]= dificil[i][j];
        }}
          geratela();
    break;

    default:
            dificuldade();
            break;

}
}

        void desenha_grade() {
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
  }
}

		void geratela(){
	// essa função serve para adicionar as jogadas
	int linha,coluna,numero,remove_linha,remove_coluna,escolha;
	//system(s);
   desenha_grade();

   printf("Digite 1 para adicionar uma jogada.\nDigite 0 para remover uma jogada.\n");
   scanf("%d",&escolha);

   switch(escolha) {
	   case 0: { printf("Digite uma linha: ");
 			scanf("%d", &remove_linha);

   			printf("Digite uma coluna: ");
   			scanf("%d", &remove_coluna);
			principal[remove_linha-1][remove_coluna-1] = 0;
		   }
		   return geratela();
		   break;
	case 1:

   printf("Digite uma linha: ");
   scanf("%d", &linha);
   printf("%d\n",linha);

   printf("Digite uma coluna: ");
   scanf("%d", &coluna);
   printf("%d\n",coluna);

   printf("Digite o n%cmero: ",163);
   scanf("%d", &numero);
   printf("%d\n",numero);
   jogo(linha, coluna, numero);
   if(linha==0 && coluna==0 && numero==0){
   printf("Você desistiu. Bom jogo!\n");
   return inicio_do_jogo();
   break;}

	default:{
			printf("N%cmero inv%clido.\n",163,160);
			return geratela();
		}
		break;
   //jogo();
}
}
      int coordenadavalida(int linha, int coluna){

        int cont=0;
  printf("%d, %d\n",linha,coluna);
  if(linha>=0 && linha <9) cont++;
  if(coluna>=0 && coluna <9) cont++;

	if(cont == 2) return 1;
  else return 0;
}


      int numerovalido(int numero)
{
  printf("%d n\n",numero);
  if(numero>0 && numero <=9)
	 return 1;
   else
	  return 0;

}
int checar(int linha, int coluna) {
	 if (principal[linha][coluna]==0)
		 return 1;
	 else
		 return 0;
}



      int tenta_colocar_linha(int linha, int coluna, int numero) {
        int i,cont=0;

      for(i=0;i<N;i++){
        if(numero != principal[i][coluna-1]) cont++;
      }
      if(cont == N ) return 1;
      else return 0;
    }



    int tenta_colocar_coluna(int linha, int coluna, int numero) {
      int i,cont=0;

    for(i=0;i<N;i++){
      if(numero != principal[linha-1][i]) cont++;
    }
    if(cont == N ) return 1;
    else return 0;
  }


  int tenta_colocar_matriz(int linha, int coluna, int numero){

    int testelinha,testecoluna,i,j,cont;

    if(linha<=0 || linha<=2){
      if(coluna<=0 || coluna<=2) testelinha=linha; testecoluna=coluna;
      if(coluna<=3 || coluna<=5) testelinha=linha; testecoluna=coluna;
      if(coluna<=6 || coluna<=8) testelinha=linha; testecoluna=coluna;
    }
    if(linha<=3 || linha<=5){
      if(coluna<=0 || coluna<=2) testelinha=linha; testecoluna=coluna;
      if(coluna<=3 || coluna<=5) testelinha=linha; testecoluna=coluna;
      if(coluna<=6 || coluna<=8) testelinha=linha; testecoluna=coluna;
    }
    if(linha<=6 || linha<=8){
      if(coluna<=0 || coluna<=2) testelinha=linha; testecoluna=coluna;
      if(coluna<=3 || coluna<=5) testelinha=linha; testecoluna=coluna;
      if(coluna<=6 || coluna<=8) testelinha=linha; testecoluna=coluna;
    }
    for(i=testelinha;i<=testelinha+2;i++){
      for(j=testecoluna;j<=testecoluna+2;j++){
        if(numero != principal[i][j]) cont++;
      }
}
    if(cont == N) return 1;
    else return 0;
  }


      void escreve(int linha, int coluna, int numero) {
	         principal[linha][coluna]=numero;
}
void jogo(int linha, int coluna, int numero){

  int flag=0;

  if(coordenadavalida(linha, coluna)==1) {
    flag++;
    printf("Coordenada: %d, %d, %d\n",linha, coluna, numero);}

  if(numerovalido(numero)==1){
    flag++;
    printf("Numero %d, %d, %d\n",linha, coluna, numero);}
  if(checar(linha, coluna)==1){
    flag++;
    printf("Checar.\n %d, %d, %d\n",linha, coluna, numero);}
  if(tenta_colocar_linha(linha-1, coluna-1, numero)==1){
    flag++;
    printf("Linha.\n %d, %d, %d\n",linha, coluna, numero);}
  if(tenta_colocar_coluna(linha-1, coluna-1, numero)==1){
    flag++;
    printf("Coluna.\n %d, %d, %d\n",linha, coluna, numero);}
  if(tenta_colocar_matriz(linha-1, coluna-1, numero)==1){
    flag++;
    printf("Matriz.\n %d, %d, %d\n",linha, coluna, numero);}
  if(flag == 6) escreve(linha, coluna, numero);

  else printf("N%co foi poss%cvel fazer esta jogada.\n",198,161);
}



  int main(){
    inicio_do_jogo();
    geratela();
    return 0;
}