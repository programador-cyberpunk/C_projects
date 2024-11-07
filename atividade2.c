    #include<stdlib.h>
    #include<stdio.h>

    int main(){
     int escolha = 0;
    printf("Escolha um numero: \n");
    scanf("%d", &escolha);

     switch(escolha){
      case 1:
      printf("Vc escolheu 1 e saiu A.\n");
      break;
      case 2:
      printf("Vc escolheu 2 e saiu B.\n");
      break;
      case 3:
      printf("Vc escolheu 3 e saiu C.\n");
      break;
      case 4:
      printf("Vc escolheu 4 e saiu d.\n");
      break;
      default:
      printf("Nada foi escolhido \n");
      break;
     }



    system("pause");
    return 0;
    }
