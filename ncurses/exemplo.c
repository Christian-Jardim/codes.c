#include <ncurses.h>
#include <stdlib.h>

int main() {
    int num1, num2, soma;
    char str1[10], str2[10];

    initscr();                // Inicia ncurses
    //cbreak();               // Entrada sem buffer
    //noecho();               // Não mostra o que o usuário digita
    //keypad(stdscr, TRUE);   // Habilita teclas especiais

    printw("Digite o primeiro número: ");
    getstr(str1);             // Lê string do usuário
    printw("Digite o segundo número: ");
    getstr(str2);

    // Converte strings para inteiros
    num1 = atoi(str1);
    num2 = atoi(str2);
    soma = num1 + num2;

    printw("\nA soma de %d + %d = %d", num1, num2, soma);
    printw("\nPressione qualquer tecla para sair...");
    refresh();                // Atualiza a tela
    getch();                  // Espera por uma tecla

    endwin();                 // Encerra ncurses
    return 0;
}
