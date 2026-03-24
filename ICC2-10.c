#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Eduardo Malafronte Alves de Souza (nusp: 16862798)
// Humberto Henrique de Amorim (nusp: 16814612)
// Lucas Vinicius da Costa (nusp: 16885265)

int overlap(char *a, char *b) {
    int lena = strlen(a);
    int lenb = strlen(b);
    
    // verifica se b é substring de a
    if (strstr(a, b) != NULL) {
        return lenb;
    }
    
    // verifica se a é substring de b
    if (strstr(b, a) != NULL) {
        return lena;
    }
    
    // calcula overlap normal
    int maxov = (lena < lenb) ? lena : lenb;
    for (int k = maxov; k > 0; k--) {
        int overlapo = 1;
        for (int i = 0; i < k; i++) {
            if (a[lena - k + i] != b[i]) {
                overlapo = 0;
                break;
            }
        }
        if (overlapo) return k;
    }
    return 0;
}

void juntar(char *result, char *a, char *b, int ov) {
    int lena = strlen(a);
    int lenb = strlen(b);
    
    // se b é substring de a
    if (strstr(a, b) != NULL) {
        strcpy(result, a);
        return;
    }
    
    // se a é substring de b
    if (strstr(b, a) != NULL) {
        strcpy(result, b);
        return;
    }
    
    // junta normalmente
    strcpy(result, a);
    strcat(result, b + ov);
}

int main() {
    int n;
    scanf("%d", &n);
    
    char reads[100][1000];
    int total = n;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", reads[i]);
    }
    
    while (total > 1) {
        int maxov = -1;
        int idxa = -1, idxb = -1;
        
        // testa todas permutacoes
        for (int i = 0; i < total; i++) {
            for (int j = 0; j < total; j++) {
                if (i != j) {
                    int ov = overlap(reads[i], reads[j]);
                    if (ov > maxov) {
                        maxov = ov;
                        idxa = i;
                        idxb = j;
                    }
                }
            }
        }
        
        // junta as duas reads com maior overlap
        char nova[2000];
        juntar(nova, reads[idxa], reads[idxb], maxov);
        
        // remove as duas reads antigas
        char temp[100][1000];
        int pos = 0;
        
        strcpy(temp[pos++], nova);
        
        for (int i = 0; i < total; i++) {
            if (i != idxa && i != idxb) {
                strcpy(temp[pos++], reads[i]);
            }
        }
        
        // copia de volta
        for (int i = 0; i < pos; i++) {
            strcpy(reads[i], temp[i]);
        }
        
        total = pos;
    }
    
    printf("%s\n", reads[0]);
    
    return 0;
}