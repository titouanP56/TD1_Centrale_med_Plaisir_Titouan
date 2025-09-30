#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

void saisir(int** Mat, int nb)
{
    int i,j;

    printf ("entrer les valeurs de la matrice\n");
    for (i = 0; i < nb; i++)
    {
         printf(" ligne numero %d \n",i+1);
         for(j=0;j<nb;j++)
         {
             // Accès correct à l'élément de la matrice allouée dynamiquement
             printf ("M[%d][%d] = ", i+1,j+1);
             // Le rewind(stdout) n'est généralement pas nécessaire et peut causer des problèmes. Je l'ai retiré.
             // On utilise simplement Mat[i][j] car c'est déjà l'adresse d'un entier après le double déréférencement
             scanf ("%d", &(Mat[i][j]));
         }
    }
}


int** creer_mat(){

    int** tab = (int**)malloc(MAX * sizeof(int*));
    if(tab == NULL){
        printf("Erreur d'allocation de mémoire pour les lignes.");
        return NULL;
    }
    for(int i = 0; i < MAX; i++){
        tab[i] = (int*)malloc(MAX * sizeof(int));
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

int** additioner(int n, int** mat1, int ** mat2){

    for(int i = 0; i<n; i ++){
        for(int j = 0; j<n; j++){
            mat1[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat1;
}

int** multiplier(int n, int** mat1, int** mat2){

    int** rep = creer_mat(n, n);

    for(int i = 0; i<n; i ++){
        for(int k = 0; k<n; k++){
            rep[i][k] = 0;
            for(int j = 0; j<n; j++){
                rep[i][k] = rep[i][k] + mat1[i][j] * mat2[j][k];
            }
        }
    }

    return rep;
}


int** menu() {
    char buffer[50];
    scanf("saisissez une operation a realiser (multiplier ou additioner) : %49s", buffer);

    int n;
    scanf("taille de la matrice : %d", n);
    
    int** mat1 = creer_mat(MAX, MAX);
    int** mat2 = creer_mat(MAX, MAX);

    saisir(mat1,n);
    saisir(mat2, n);

    if (strcmp(buffer, "multiplier") == 0){
        return multiplier(n, mat1, mat2);
    }
    else{
        return additioner(n, mat1, mat2);
    }

}



int main(){
    int n = 2;
    int m = 2;
    int k = 2;

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
    tab2[1][0] = 1;
    tab2[1][1] = 1;



    int ** mult = multiplier(n,tab,tab2);
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