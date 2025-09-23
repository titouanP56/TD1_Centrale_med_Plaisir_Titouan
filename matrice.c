#include <stdio.h>
#include <stdlib.h>

int** saisir(int ligne, int column);

int** creer_mat(int ligne, int column){

    int** tab = (int**)malloc(ligne * sizeof(int*));
    if(tab == NULL){
        printf("Erreur d'allocation de mémoire pour les lignes.");
        return NULL;
    }
    for(int i = 0; i < ligne; i++){
        tab[i] = (int*)malloc(column * sizeof(int));
        if(tab[i] == NULL){
            printf("Erreur d'allocation de mémoire pour la colonne %d.", i);
            return NULL;
        }
    }
    return tab;
}



void afficher(int n, int m, int** matrice){

    printf("[");
    for(int i = 0; i<n; i ++){
        printf("[");
        for(int j = 0; j<m; j++){
            printf(" %d ",matrice[i][j]);
        }
        printf("] ");
    }
    printf("]");
}

int** additioner(int n, int m, int** mat1, int ** mat2){

    for(int i = 0; i<n; i ++){
        for(int j = 0; j<m; j++){
            mat1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat1;
}

int** multiplier(int ligne1, int m, int column2, int** mat1, int** mat2){

    int** rep = creer_mat(ligne1, column2);

    for(int i = 0; i<ligne1; i ++){
        for(int k = 0; k<column2; k++){
            rep[i][k] = 0;
            for(int j = 0; j<m; j++){
                rep[i][k] = rep[i][k] + mat1[i][j] * mat2[j][k];
            }
        }
    }

    return rep;
}



int main(){
    int n = 2;
    int m = 2;
    int k = 3;

    int** tab = (int**)malloc(n * sizeof(int*));
    if(tab == NULL){
        printf("Erreur d'allocation de mémoire pour les lignes.");
        return 1;
    }

    for(int i = 0; i < n; i++){
        tab[i] = (int*)malloc(m * sizeof(int));
        if(tab[i] == NULL){
            printf("Erreur d'allocation de mémoire pour la colonne %d.", i);
            return 1;
        }
    }

    int** tab2 = (int**)malloc(m * sizeof(int*));
    if(tab2 == NULL){
        printf("Erreur d'allocation de mémoire pour les lignes.");
        return 1;
    }

    for(int i = 0; i < m; i++){
        tab2[i] = (int*)malloc(k * sizeof(int));
        if(tab2[i] == NULL){
            printf("Erreur d'allocation de mémoire pour la colonne %d.", i);
            return 1;
        }
    }

    tab[0][0] = 4;
    tab[0][1] = 3;
    tab[1][0] = 2;
    tab[1][1] = 0;

    tab2[0][0] = 1;
    tab2[0][1] = 1;
    tab2[0][2] = 2;
    tab2[1][0] = 1;
    tab2[1][1] = 1;
    tab2[1][2] = 2;



    int ** mult = multiplier(n,m,k,tab,tab2);
    afficher(m, k, mult);


    for (int i = 0; i < n; i++) {
        free(tab[i]);
    }
    free(tab);

    for (int i = 0; i < m; i++) {
        free(tab2[i]);
    }
    free(tab2);

    for (int i = 0; i < k; i++) {
        free(mult[i]);
    }
    free(mult);

    return 0;
}