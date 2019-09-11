// 
//Makarov S.S. IU4-31B
// 
//All rights not reserved:(
// 
//  
// 
// 
// 07.09.2019 - 11.09.2019
// 
// 
#include <stdlib.h>
#include <stdio.h>
#define max_length 20

void PRINT(const int A, const int B, char **arr[A]){
    int j = 0;
    for (int i = 0; i < A; i++){
        printf("\n");
        for(j = 0; j < B; j++)
            printf("%s ", arr[i][j]);
        //printf("\n");
    }
    printf("\n");
}

void ADD(int A, int B, char **arr[A], int A1, int B1, char val[]){
    A1--;
    B1--;
    arr[A1][B1] = val;
    // arr[A][B] = arr[A1][B1];
    printf("Добавлено! \n \n");
    
}

void DEL (int A, int B, char **arr[A], int A1, int B1){
    A1--;
    B1--;
    arr[A1][B1] = 0;
    printf("Удалено( \n \n");
    
}





int main(){
    int A, B, A1, B1, j = 0;
    
    printf("Введите положение в массиве A: \n");
    scanf("%d", &A);
    printf("Введите положение в массиве B: \n");
    scanf("%d", &B);
    printf("Введите значение:\n");
    char **arr[A];
    char scan, *val;
    
    for (int i = 0; i < A; i++)
        arr[i] = calloc(B,sizeof (int));
    
    for (int i = 0; i < A; i++){
        while((scan = getchar()) != '\n'){
            arr[i][j][0] = scan; //-48
            j++;
            if (j < B){
                j = 0;
                i++;
            }
        }
        for (j=0;j<B;j++){
            arr[i][j] = calloc(max_length, sizeof(char));
            scanf("%s",arr[i][j]);
        }
    }
    
    
    int menu, exitflag = 1;
    while (exitflag){
        //printf("Выделена память для массива %d на %d типа char", A,B);
        printf(" Что делать дальше?\n");
        printf("Нажмите 1  для вывода элементов\n");
        printf("Нажмите 2  для добавления элемента\n");
        printf("Нажмите 3  для удаления элемента\n");
        printf("Нажмите 0  для завершения\n");
        scanf("%d",&menu);
        
        switch(menu){
            case 1:
                PRINT(A, B, arr);
                
                break;
            case 2:
                printf("Введите положение в массиве A:\n");
                scanf("%d", &A1);
                printf("Введите положение в массиве B:\n");
                scanf("%d", &B1);
                printf("Введите значение:\n");
                val = calloc(max_length, sizeof(char));
                scanf("%s", val);
                ADD(A, B, arr, A1, B1, val);
                val = NULL;
                break;
            case 3:
                printf("Введите положение в массиве A:\n");
                scanf("%d", &A1);
                printf("Введите положение в массиве B:\n");
                scanf("%d", &B1);
                DEL(A, B, arr, A1, B1);
                
                break;
            case 0:
                exitflag = 0;
                printf("Выходим...");
                free(arr); 
                break;
            default:
                printf("Такой опции нет.");
                break;
                
        }
    }

    return 0;
}
