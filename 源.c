//2026.10.11   21:05
#include <stdio.h>

int main() {
    char a[6][7] = {
        {'#','#','#','#','#','#','#'},
        {'#','.','.','.','.','.','#'},
        {'#','.','P','.','.','.','#'},
        {'#','.','.','B','.','.','#'},
        {'#','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#'}
    };
    char G = 'G';
    int goalI = 2;
    int goalJ = 3;
    a[goalI][goalJ] = G;
    int i = 0;
    int j = 0;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
    int playerI = 2;
    int playerJ = 2;
    char key;
    while (1) {
        printf("请输入方向(W/A/S/D) 输入Q退出：");
        scanf_s(" %c", &key,1);
        if (key == 'Q'|| key == 'q') {
            break;
        }
        if (key == 'W' || key == 'w') {
            if (a[playerI - 1][playerJ] == '.' || a[playerI - 1][playerJ] == 'G') {
                a[playerI][playerJ] = '.';
                playerI = playerI - 1;
                a[playerI][playerJ] = 'P';
                if (a[playerI + 1][playerJ] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
            else  if (a[playerI - 1][playerJ] == 'B' && (a[playerI - 2][playerJ] == '.' || a[playerI - 2][playerJ] == 'G')) {
                a[playerI][playerJ] = '.';
                playerI = playerI - 1;
                a[playerI][playerJ] = 'P';
                a[playerI - 1][playerJ] = 'B';
                a[playerI][playerJ] = 'P';
                if (a[playerI + 1][playerJ] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                if (playerI - 1 == goalI && playerJ == goalJ) {
                    printf("恭喜你，胜利了！\n");
                    break;
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        if (key == 'S' || key == 's') {
            if (a[playerI + 1][playerJ] == '.' || a[playerI + 1][playerJ] == 'G') {
                a[playerI][playerJ] = '.';
                playerI = playerI + 1;
                a[playerI][playerJ] = 'P';
                if (a[playerI - 1][playerJ] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
            else  if (a[playerI + 1][playerJ] == 'B' && (a[playerI + 2][playerJ] == '.' || a[playerI + 2][playerJ] == 'G')) {
                a[playerI][playerJ] = '.';
                playerI = playerI + 1;
                a[playerI][playerJ] = 'P';
                a[playerI + 1][playerJ] = 'B';
                if (a[playerI - 1][playerJ] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                if (playerI + 1 == goalI && playerJ == goalJ) {
                    printf("恭喜你，胜利了！\n");
                    break;
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        if (key == 'A' || key == 'a') {
            if (a[playerI][playerJ - 1] == '.' || a[playerI][playerJ - 1] == 'G') {
                a[playerI][playerJ] = '.';
                playerJ = playerJ - 1;
                a[playerI][playerJ] = 'P';
                if (a[playerI][playerJ + 1] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
            else  if (a[playerI][playerJ - 1] == 'B' && (a[playerI][playerJ - 2 ] == '.' || a[playerI][playerJ - 2] == 'G')) {
                a[playerI][playerJ] = '.';
                playerJ = playerJ - 1;
                a[playerI][playerJ] = 'P';
                a[playerI][playerJ - 1] = 'B';
                if (a[playerI][playerJ + 1] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                if (playerI == goalI && playerJ - 1 == goalJ) {
                    printf("恭喜你，胜利了！\n");
                    break;
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        if (key == 'D' || key == 'd') {
            if (a[playerI][playerJ + 1] == '.' || a[playerI][playerJ + 1] == 'G') {
                a[playerI][playerJ] = '.';
                playerJ = playerJ + 1;
                a[playerI][playerJ] = 'P';
                if (a[playerI][playerJ - 1] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
            else  if (a[playerI][playerJ + 1] == 'B' && (a[playerI][playerJ + 2] == '.' || a[playerI][playerJ + 2] == 'G')) {
                a[playerI][playerJ] = '.';
                playerJ = playerJ + 1;
                a[playerI][playerJ] = 'P';
                a[playerI][playerJ + 1] = 'B';
                if (a[playerI][playerJ - 1] == a[goalI][goalJ]) {
                    a[goalI][goalJ] = 'G';
                }
                if (playerI == goalI && playerJ + 1 == goalJ) {
                    printf("恭喜你，胜利了！\n");
                    break;
                }
                for (i = 0; i < 6; i++) {
                    for (j = 0; j < 7; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
        }
        printf("当前的坐标为第%d行,第%d列\n", playerI + 1, playerJ + 1);
    }
    return 0;
}