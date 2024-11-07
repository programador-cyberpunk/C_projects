#include<stdio.h>
#include<stdlib.h>

int main (){

 int a,b;
 // comando if-else
printf("digite dois numeros: ");
scanf(" %d,%d", &a, &b);

/*if(a == b){
printf("os numeros sao iguais.\n");
}else if(a > b){
printf("o primeiro numero eh maior\n\n");
}else if(a < b){
printf("o segundo numero eh maior\n\n");
}else{
 printf("os numeros sao diferentes: \n\n");
 }
 */

 // ternario
 /*printf("digite dois numeros: ");
 scanf("&d", &a);
 b = (a > 12) ? 100 : 200;
 printf("valor de b: &d \n\n", b);
 */

 //switch

 /*char escolha;
 printf("Quer continuar [s - sim /n - nao]?: \n");
 scanf(%c, escolha);
 switch(escolha){
 case 's' :
    printf("Vc escolheu continuar \n");
    break;
 case 'n' :
    printf("Vc escolheu parar \n");
    break;
 default:
    printf("Escolha invalida! \n");
 }
*/
 // comando for


 /*int i;
 char  letra = 'a';
 for(i = 0; i < 26; i++){
   printf(" %c", letra);
   letra++;
 }
 // comando while
 int i = 0;
 while (i < 10){
    printf("Valor de i: %d \n", i);
    i++;
 }
 */
 // comando continue
 /*int i;
 for(i = 0; i < 26; i++){
    if(i ==5 ){
       printf("\n\n\n \t\t\t captura de i em %d: ", i);
       continue;
    }
    printf("Valor de i em: %d\n", i);
 }
 */
 // comando break

 /*int i;
 for(i = 0; i < 26; i++){
    if(i ==5 ){
       printf("\n\n\n \t\t\t captura de i em %d: ", i);
       break;
    }
    printf("Valor de i em: %d\n", i);
    */

    // comando goto

    /* int j = 5;
     if(j==5){
        j++;
       goto imprimir;
     }
    imprimir:
       printf("Valor de j: %d", j);
       */

system("pause");
return 0;
}
