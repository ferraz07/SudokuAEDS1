# SudokuAEDS1
Trabalho de AEDs 1, um programa que se faz um jogo de Sudoku 
Função desenha_grade serve para desenhar a grade em volta da matriz
com os respectivos números de linhas e colunas, utilizando | para 
fazer o desenho e limitação.
Função checar serve pra conferir se onde o numero vai ser colocado
está vazio.
Função tenta_colocar confere se há a possibilidade de colocar o
numero desejado na posição que foi selecionadam caso funcione, gera
a tela com o numero em sua posição, caso contrário, a grade é gerada
sem o número.
Função coordenadavalida confere se a coordenada desejada está disponível
e é válida nas matrizes.
Função numerovalido confere se o número está entre 1 e 9.
Função existenaColuna confere se o número digitado pelo usuário já 
está presente na coluna desejada
Função existenalinha confere se o número digitado pelo usuário já 
está presente na linha desejada
Função escreve introduz na matriz[linha][coluna] o número digitado
pelo usuário
Função jogo é a função em que o jogo acontece.
Função terminar é a função que acaba de completar o jogo
Função gerar tela chama a função desenha_grade e inicia o jogo
chamando a função jogo, após pedir a linha, coluna e o número desejados.
--------------------------------------------------------------------------------------
