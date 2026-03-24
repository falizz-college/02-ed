// Fábio Luís de Carvalho Terra- 2321055
#include <stdio.h>

// move o cursor para a posiÃ§Ã£o (x,y) do console
void gotoxy(int x, int y) {
    printf("\033[%d;%df", y, x);
}

// limpa a tela do console
void clear() {
    printf("\033[2J");
}

// funÃ§Ã£o para desenhar um pixel na posiÃ§Ã£o (x,y) do console
void draw_xy(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    // get console coordinates and draw rgbaPixel
    gotoxy(x, y);
    printf("\033[48;2;%d;%d;%dm \033[0;00m", r, g, b);
}

#define R 0xff000000
#define G 0x00ff0000
#define B 0x0000ff00
#define A 0x000000ff
#define RGBA(r, g, b, a) (r << 24 | g << 16 | b << 8 | a)

int main() {
    // declaração de variáveis
    int x;
    int y;
    int i;

    // imagem 10x10
    int imagem[10][10] = {
        {RGBA(255, 0, 0, 255), RGBA(230, 25, 25, 255), RGBA(204, 51, 51, 255), RGBA(179, 76, 76, 255), RGBA(153, 102, 102, 255), RGBA(128, 128, 128, 255), RGBA(102, 153, 153, 255), RGBA(76, 179, 179, 255), RGBA(51, 204, 204, 255), RGBA(25, 230, 230, 255)},
        {RGBA(255, 25, 0, 255), RGBA(230, 51, 25, 255), RGBA(204, 76, 51, 255), RGBA(179, 102, 76, 255), RGBA(153, 128, 102, 255), RGBA(128, 153, 128, 255), RGBA(102, 179, 153, 255), RGBA(76, 204, 179, 255), RGBA(51, 230, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 51, 0, 255), RGBA(230, 76, 25, 255), RGBA(204, 102, 51, 255), RGBA(179, 128, 76, 255), RGBA(153, 153, 102, 255), RGBA(128, 179, 128, 255), RGBA(102, 204, 153, 255), RGBA(76, 230, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 76, 0, 255), RGBA(230, 102, 25, 255), RGBA(204, 128, 51, 255), RGBA(179, 153, 76, 255), RGBA(153, 179, 102, 255), RGBA(128, 204, 128, 255), RGBA(102, 230, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 102, 0, 255), RGBA(230, 128, 25, 255), RGBA(204, 153, 51, 255), RGBA(179, 179, 76, 255), RGBA(153, 204, 102, 255), RGBA(128, 230, 128, 255), RGBA(102, 255, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 128, 0, 255), RGBA(230, 153, 25, 255), RGBA(204, 179, 51, 255), RGBA(179, 204, 76, 255), RGBA(153, 230, 102, 255), RGBA(128, 255, 128, 255), RGBA(102, 255, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 153, 0, 255), RGBA(230, 179, 25, 255), RGBA(204, 204, 51, 255), RGBA(179, 230, 76, 255), RGBA(153, 255, 102, 255), RGBA(128, 255, 128, 255), RGBA(102, 255, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 179, 0, 255), RGBA(230, 204, 25, 255), RGBA(204, 230, 51, 255), RGBA(179, 255, 76, 255), RGBA(153, 255, 102, 255), RGBA(128, 255, 128, 255), RGBA(102, 255, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 204, 0, 255), RGBA(230, 230, 25, 255), RGBA(204, 255, 51, 255), RGBA(179, 255, 76, 255), RGBA(153, 255, 102, 255), RGBA(128, 255, 128, 255), RGBA(102, 255, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)},
        {RGBA(255, 230, 0, 255), RGBA(230, 255, 25, 255), RGBA(204, 255, 51, 255), RGBA(179, 255, 76, 255), RGBA(153, 255, 102, 255), RGBA(128, 255, 128, 255), RGBA(102, 255, 153, 255), RGBA(76, 255, 179, 255), RGBA(51, 255, 204, 255), RGBA(25, 255, 230, 255)}
    };

    // copia imagem original para imagem 2
    int imagem2[10][10];
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++)
            imagem2[x][y] = imagem[x][y];
    }

    // copia imagem original para imagem 3 (corrigido o comentário repetido)
    int imagem3[10][10];
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++)
            imagem3[x][y] = imagem[x][y];
    }

    // imagem em branco
    int imagem4[10][10];
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++)
            imagem4[x][y] = 0xFFFFFFFF; // Branco
    }

    // ExercÃ cio 1
    unsigned char *pchar2 = (unsigned char *)imagem2;
    // insira o seu cÃ³digo abaixo
    // soluÃ§ao:
    for(int x = 0; x < 10; x ++){
        for(int y = 0; y < 1; y ++){
            pchar2[(((x*10) + y)*4 + 1)] = 0;
            pchar2[((x*10) + y)*4 + 2] = 0;
            pchar2[((x*10) + y)*4 + 3] = 255;
        }
        for(int y = 0; y < 10; y += 9){
            pchar2[(((y*10) + x)*4 + 1)] = 0;
            pchar2[((y*10) + x)*4 + 2] = 0;
            pchar2[((y*10) + x)*4 + 3] = 255;
        }
        for(int y = 9; y < 10; y ++){
            pchar2[(((x*10) + y)*4 + 1)] = 0;
            pchar2[((x*10) + y)*4 + 2] = 0;
            pchar2[((x*10) + y)*4 + 3] = 255;
        }
    }
    // insira o seu cÃ³digo acima

    // ExercÃ cio 2
    unsigned char *pchar3 = (unsigned char *)imagem3;
    // insira o seu cÃ³digo abaixo
    // soluÃ§ao:
    for(int x = 0; x < 10; x ++){
        for(int y = 0; y < 10; y ++){
            if(x == y) {
                pchar3[(((x*10) + y)*4 + 1)] = 255;
                pchar3[((x*10) + y)*4 + 2] = 0;
                pchar3[((x*10) + y)*4 + 3] = 0;
            }
            if (x + y == 9){
                pchar3[(((x*10) + y)*4 + 1)] = 255;
                pchar3[((x*10) + y)*4 + 2] = 0;
                pchar3[((x*10) + y)*4 + 3] = 0;
            }
        }
    }

    // ExercÃ cio 3
    pchar2 = (unsigned char *)imagem2;
    pchar3 = (unsigned char *)imagem3;
    unsigned char *pchar4 = (unsigned char *)imagem4;
    // insira o seu cÃ³digo abaixo
    // soluÃ§ao:
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            pchar4[((x * 10) + y) * 4] = pchar3[((x * 10) + y) * 4];
            pchar4[(((x * 10) + y) * 4) + 1] = pchar3[(((x * 10) + y) * 4) + 1];
            pchar4[(((x * 10) + y) * 4) + 2] = pchar3[(((x * 10) + y) * 4) + 2];
            pchar4[(((x * 10) + y) * 4) + 3] = pchar3[(((x * 10) + y) * 4) + 3];
        }
    }
    for (int x = 0; x < 10; x++){
        for (int y = 0; y < 10; y++){
            if (x == 0 || x == 9){
                pchar4[(((x * 10) + y) * 4) + 1] = pchar2[(((x * 10) + y) * 4) + 1];
                pchar4[(((x * 10) + y) * 4) + 2] = pchar2[(((x * 10) + y) * 4) + 2];
                pchar4[(((x * 10) + y) * 4) + 3] = pchar2[(((x * 10) + y) * 4) + 3];
            }
            else if (y == 0 || y == 9){
                pchar4[(((x * 10) + y) * 4) + 1] = pchar2[(((x * 10) + y) * 4) + 1];
                pchar4[(((x * 10) + y) * 4) + 2] = pchar2[(((x * 10) + y) * 4) + 2];
                pchar4[(((x * 10) + y) * 4) + 3] = pchar2[(((x * 10) + y) * 4) + 3];
            }
        }
    }

    // limpa a tela
    clear();
    gotoxy(1, 1);
    printf("Imagem original\n");
    // desenha a imagem original a partir da posiÃ§Ã£o (0,2)
    int xoffset = 1, yoffset = 3;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            draw_xy(x + xoffset, y + yoffset, (imagem[x][y] & R) >> 24, (imagem[x][y] & G) >> 16, (imagem[x][y] & B) >> 8);
        }
    }

    gotoxy(25, 1);
    printf("Imagem2 com quadrado vermelho\n");
    xoffset = 25, yoffset = 3;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            draw_xy(x + xoffset, y + yoffset, (imagem2[x][y] & R) >> 24, (imagem2[x][y] & G) >> 16, (imagem2[x][y] & B) >> 8);
        }
    }

    gotoxy(1, 14);
    printf("Imagem3 com X azul\n");
    xoffset = 1, yoffset = 17;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            draw_xy(x + xoffset, y + yoffset, (imagem3[x][y] & R) >> 24, (imagem3[x][y] & G) >> 16, (imagem3[x][y] & B) >> 8);
        }
    }

    gotoxy(25, 14);
    printf("Imagem4 com a sobreposiÃ§Ã£o");
    gotoxy(25, 15);
    printf("da imagem2 em imagem3");
    xoffset = 25, yoffset = 17;
    for (x = 0; x < 10; x++) {
        for (y = 0; y < 10; y++) {
            draw_xy(x + xoffset, y + yoffset, (imagem4[x][y] & R) >> 24, (imagem4[x][y] & G) >> 16, (imagem4[x][y] & B) >> 8);
        }
    }
    printf("\n");

    return 0;
}