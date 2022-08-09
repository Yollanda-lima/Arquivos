

Página
1
de 4
//QUESTÃO 01
#include <stdio.h>
#include <string.h>
int main(){
int valor;
char alfabetoMa [26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alfabetoMi [28]=" abcdefghijklmnopqrstuvwxyz";
FILE *arq;
arq = fopen("alfabeto.txt","w");
for(int i=0;i<26;i++){
fprintf(arq, "%c,", alfabetoMa[i]);
}
fprintf(arq, "\n");
for(int i = strlen(alfabetoMi)-1; (i>0 || i<0); i--){
fprintf(arq, "%c,", alfabetoMi[i]);
}
return 0;
}
//QUESTÃO 02
#include <stdio.h>
#include <stdlib.h>
void criar(){
FILE *arq;
arq=fopen("aula.txt","w");
}
void ler(int caracter){
int letra=0;
FILE *arq;
arq=fopen("aula.txt","a");
while(!feof(arq)){
char lLetra=fgetc(arq);
if(caracter==lLetra){
letra++;
printf("Encontrado(s) %d caractere(s) %c",letra,caracter);
}
}
}
int main(){
criar();
printf("Informe o nome do arquivo:\n");
char nome;
scanf("%c", &nome);
printf("Informe o caracter que deseja contar:\n");
char caracter;
scanf("%c", &caracter);
return 0;
}
//QUESTÃO 03
#include <stdio.h>
#include <string.h>
int main()
{
FILE *arquivo;
printf("Programa de Nomes em C");
int escolha;
char reta[50];
char Consulta;
char oi = 'o';
do
{
puts("\n\nDigite: 0 - sair | 1 - adicionar nome | 2 - consultar nomes 
por letra \n");
scanf("%i", &escolha);
if (escolha == 1)
{
arquivo = fopen("nomes.txt", "a");
char novoNome[50];
printf("Nome: ");
scanf("%s", novoNome);
fputs(novoNome, arquivo);
fprintf(arquivo, "\n");
fclose(arquivo);
}
if (escolha == 2)
{
arquivo = fopen("nomes.txt", "r");
printf("Digite a letra inicial a ser consultada: ");
scanf(" %c", &Consulta);
getchar();
// Programa para ler
while (!feof(arquivo))
{
fgets(reta, sizeof(reta), arquivo);
if (reta[0] == Consulta)
{
printf("%s", reta);
}
}
fclose(arquivo);
}
} while (escolha != 0);
return 0;
}
//QUESTÃO 04
#include <stdio.h>
int main(){
FILE *arq;
int opcao;
float entradaTotal = 0, saidaTotal=0, saldo=0;
char balanco[10];
arq = fopen("entradas.txt", "w");
fclose(arq);
while (!feof(arq)){
float valor = 0;
fscanf(arq,"%f",&valor);
entradaTotal = entradaTotal + valor;}
fclose(arq);
arq = fopen("saida.txt", "w");
fclose(arq);
while (!feof(arq)){
float valor = 0;
fscanf(arq,"%f",&valor);
saidaTotal = saidaTotal + valor;}
fclose(arq);
do{
puts("Balanço: Escolha uma opção\n0 - Sair | 1-entrada | 2-saída | 3-
balanço | 0-sair\n");
scanf("%i",&opcao);
if (opcao == 1){
float entrada;
printf("Digite o valor de entrada:\n");
scanf("%f",&entrada);
arq = fopen("entrada.txt","w");
fprintf(arq,"%.2f\n",entrada);
fclose(arq);
entradaTotal = entradaTotal + entrada;}
if (opcao == 2){
float saida;
printf("Digite o valor de saida:\n");
scanf("%f",&saida);
arq = fopen("saida.txt","a");
fprintf(arq,"%.2f\n",saida);
fclose(arq);
saidaTotal = saidaTotal + saida; }
if (opcao == 3){
if (entradaTotal == 0){
arq = fopen ("entradas.txt","r");
while (!feof(arq)){
float valor = 0;
fscanf(arq, "%f",&valor);
entradaTotal = entradaTotal + valor;}}
if (saidaTotal == 0){
arq = fopen ("saidas.txt","r");
while (!feof(arq)){
float valor = 0;
fscanf(arq, "%f",&valor);
saidaTotal = saidaTotal + valor;}}
saldo = entradaTotal - saidaTotal;
printf("\nEntradas: (%.2f), Saídas: (%.2f), Saldo: (%.2f), 
Balanço",entradaTotal, saidaTotal, saldo);
if (saldo > 0){
printf("Balanço positivo \n");}
else if (saldo == 0){
printf("Zero \n");}
else{
printf("Balanço negativo\n");}
}
}
while (opcao != 0);
return 0;
}
