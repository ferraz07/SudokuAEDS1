# SudokuAEDS1
Relatório TP Sudoku

AEDs 1

Prof: Vinícius Durelli


Grupo: Alexandre Lima, Felipe Ferraz, Júlio César












O #ifdef tem função de definir o comando “clear” para Windows e para o sistema do Linux, independente de qual o sistema que o programa estiver rodando a tela será limpada.


Definimos as matrizes para cada uma das dificuldades disponíveis no jogo, uma fácil, uma média e uma difícil. O “N” foi definido como 9 para o tamanho da matriz.


As variáveis “linha”, ”coluna” e “número” foram declaradas no escopo global para evitar avisos no compilador e deixar a transferência dos valores de forma correta.


O ponteiro FILE *arquivo foi declarado para salvar e carregar o jogo em arquivos.


*void inicio_do_jogo: Representa o menu do jogo, abre a tela principal onde o jogador tem a opção de escolher entre começar um jogo novo, carregar um jogo antigo, sair do programa e ler as regras do jogo sudoku.


*void dificuldade: Essa função permite o jogador escolher o nível de dificuldade do jogo de sudoku, ela vária em fácil, médio e difícil, após o jogador escolher a dificuldade o programa transfere os valores da matriz da dificuldade definida para uma matriz principal, que é onde as jogadas serão feitas e salvas.


*void desenha_grade: Essa função serve para desenhar a grade do sudoku e facilitar a visualização do usuário do programa.


*void geratela: Essa função serve para adicionar jogadas, remover uma jogada anterior, salvar seu jogo e resolver o sudoku. Escolhendo adicionar jogada o usuário deve escolher uma linha, uma coluna e um número para ser adicionado. Caso escolha remover uma jogada, deve digitar uma linha e uma coluna onde se deseja remover o número. Escolhendo a opção de salvar, o jogo é salvo em arquivo e o programa se encerra. Caso escolha resolver o sudoku o jogo é resolvido automaticamente, mostra na tela ele completamente resolvido e o programa se encerra.


*int coordenadavalida: Essa função serve para analisar se os números de linha e coluna digitados pelo usuário servem no jogo, eles devem ser entre 1 e 9. Caso não seja o jogador volta para tela e tem que digitar novamente os números.


*int numerovalido: Essa função serve para determinar se o número digitado pelo usuário está dentro das regras do jogo, ele deve ser entre 1 e 9.  Caso não seja o jogador volta para tela e tem que digitar novamente o número.


*int checar: Essa função serve para checar se a posição onde o jogador quer colocar o número está vazia e consequentemente disponível para receber um número. Caso não seja o jogador volta para tela e tem que digitar novamente os números.


*int tenta_colocar_linha: Essa função serve para verificar se o número que o usuário digitou já existe na linha escolhida. Caso já exista o jogador retorna a tela e deve digitar os números novamente.


*int tenta_colocar_coluna: Essa função serve para verificar se o número que o usuário digitou já existe na coluna escolhida. Caso já exista o jogador retorna a tela e deve digitar os números novamente.


*int tenta_colocar_matriz: Essa função serve para verificar se o número que o usuário digitou já existe na matriz 3x3 escolhida. Caso já exista o jogador retorna a tela e deve digitar os números novamente.


*void escreve: Essa função serve para pegar a linha, a coluna e o número digitados pelo usuário e salva em sua devida posição, completando a jogada.


*void jogo: É a função onde as regras do jogo são implementadas, todas a funções anteriormente explicadas são chamadas e testadas uma por uma, cada vez que uma função está correta ela é contada +1, se esse valor chegar a 6, a jogada é computada e salva. Após essa jogada a função chama a função terminar para ver se o jogo está completo, caso não esteja, a função geratela é chamada novamente com o novo número salvo nela, caso esteja finalizado, uma mensagem parabenizando o jogador é mostrada na tela.


*int terminar: Essa função checa após toda jogada se os 81 lugares na matriz estão preenchidos, se estiver o jogo se encerra, mostrando o tempo e uma mensagem parabenizando o jogador.


Matriz Resolução: Ela é a matriz totalmente resolvida de forma correta, independente da dificulade escolhida.


*int main: A função principal do jogo, ela chama a inicio_do_jogo e inicia o programa. Ela também é responsável por salvar o tempo em que o jogador ficou com o programa aberto e jogando, quando ele se encerra, ela mostra o tempo de demora do usuário, em horas, minutos e segundos.
 	

Alexandre Lima, Felipe Ferraz, Júlio César.
--------------------------------------------------------------------------------------
