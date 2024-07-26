#include <stdio.h>
#include <stdlib.h>

int* Two_concatenation(const int* array, const int arraySize,int* returnSize) {
    if(array == NULL) {
        exit(111);
    }
    int* newTab = malloc((2*arraySize)*sizeof(int)),size = 0;

    for(int i = 0;i<2;i++){
        for(int j = 0;j<arraySize;j++,size++){
            newTab[size] = array[j];
        }
    }
    *returnSize = 2*arraySize;
    return newTab;
}

int* Multi_concatenation(const int num_concatenation,const int* array,const int arraySize,int* returnSize) {
    if(array == NULL) {
        exit(111);
    }

    int* newTab = malloc((num_concatenation*arraySize)*sizeof(int)),size = 0;

    for(int i = 0;i<num_concatenation;i++) {
        for(int j = 0;j<arraySize;j++,size++) {
            newTab[size] = array[j];
        }
    }
    *returnSize = num_concatenation*arraySize;
    return newTab;
}

void afficheArray(const int* array,const int size) {
    if(array == NULL) {
        exit(111);
    }
    for(int i = 0 ;i<size;i++) {
        printf("%d    ",array[i]);
    }
}
int main(void)
{
    printf("Bienvenue dans l'application de doublage des donnees d'un tableaux!\n");
    printf("pour commencer creer un tableau de depart\n");

    int *array = NULL,sizeArray = 0, mode = 0,newSize,*newArray;

    printf("entrez le nombre de valeur du tableau\n");
    scanf("%d",&sizeArray);
    printf("maintenant passant au remplissage du tableau");

    array = malloc(sizeArray*sizeof(int));
    for(int i = 0;i<sizeArray;i++) {
        printf("\n entrez la valeur du numero %d :    ",i+1);
        scanf("%d",&array[i]);
    }
    printf("affichage du tableau entree\n");
    afficheArray(array,sizeArray);

    printf("choisissez un mode\n");

    printf("1- Doubler un tableaux\n 2- Multiplier le tableau par une valeur\n");
    printf("entrez votre choix : ");
    scanf("%d",&mode);

    if(mode == 1) {
        newArray = Two_concatenation(array,sizeArray,&newSize);
    }
    else {
        printf("vous avez choisi le mode 2\nentrez le nombre de fois que voulez multiplier le tableau  :  ");
        int number = 0;
        scanf("%d",&number);
        newArray = Multi_concatenation(number,array,sizeArray,&newSize);
    }
    printf("\n affichage du nouveau tableau \n");
    afficheArray(newArray,newSize);

    free(newArray);
    free(array);

    return 0;
}
