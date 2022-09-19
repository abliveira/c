/*

- Variável: nada além de um nome dado ao local que pode conter um valor.
- Variável local estática: variável que preserva seu valor, mesmo depois de estar
fora de seu escopo. Uma vez inicializado, não é inicializada novamente.
- Variável local regular: o escopo é limitado a uma função em si ou só pode ser
usada em uma função onde é declarada. O valor não é mantido entre as chamadas da função.

A principal diferença entre variável estática e normal é que a variável estática é
inicializada apenas uma vez no programa e mantém seu valor, diferentemente do valor
normal que é inicializado a cada vez.

- Variável regular global: a variável global é variável que é declarada fora de todas
as funções. Seu escopo está ao longo do programa, e pode ser acessada em arquivos
externos se o seu arquivo de origem for incluso. Seu valor pode ser recuperado por
todas as outras funções.
- Variável ou função estática global: seu escopo é limitado ao seu arquivo de origem,
mesmo incluindo o arquivo a que pertence,

- Variável volátil: seu valor pode ser alterado por código fora do escopo do código
atual a qualquer momento.A palavra -chave volátil destina -se a impedir que o compilador
de qualquer otimização.

*/

#include <stdio.h> 

// int a, b = 10;

void func_1() { 
    int a = 1; 
    static int b = 100; 
    printf("a = %d\n", a); 
    printf("b = %d\n\n", b); 
    a++; 
    b++; 
} 


static void func() { // Função static Somente pode ser acessada neste próprio arquivo 
    static int static_var=1; 
    int non_static_var=1; 
 
    static_var++; 
    non_static_var++; 
 
    printf("Static = %d\n", static_var);
    printf("NonStatic = %d\n", non_static_var);
} 


/*
volatile tells the compiler not to optimize anything that has to do with the volatile variable.

There are at least three common reasons to use it, all involving situations where the value
of the variable can change without action from the visible code: 
- When you interface with hardware that changes the value itself; 
- when there's another thread running that also uses the variable;
- when there's a signal handler that might change the value of the variable.

Let's say you have a little piece of hardware that is mapped into RAM somewhere and that has
 two addresses: a command port and a data port:
*/
typedef struct
{
  int command;
  int data;
  int isBusy;
} MyHardwareGadget;
// Now you want to send some command:

void SendCommand (MyHardwareGadget * gadget, int command, int data) {
  // wait while the gadget is busy:
  while (gadget->isBusy) {
    // do nothing here.
  }
  // set data first:
  gadget->data = data;
  // writing the command starts the action:
  gadget->command = command;
}

/*
Looks easy, but it can fail because the compiler is free to change the order in which data and commands are written. This would cause our little gadget to issue commands with the previous data-value. Also take a look at the wait while busy loop. That one will be optimized out. The compiler will try to be clever, read the value of isBusy just once and then go into an infinite loop. That's not what you want.

The way to get around this is to declare the pointer gadget as volatile. This way the compiler is forced to do what you wrote. It can't remove the memory assignments, it can't cache variables in registers and it can't change the order of assignments either

This is the correct version:
*/
void SendCommand2 (volatile MyHardwareGadget * gadget, int command, int data) {
  // wait while the gadget is busy:
  while (gadget->isBusy) {
    // do nothing here.
  }
  // set data first:
  gadget->data = data;
  // writing the command starts the action:
  gadget->command = command;
}

 
int main() {

    func_1(); 
    func_1(); 
    func_1(); 

    // Expected Output:

    // a = 1 
    // b = 100 
    
    // a = 1 
    // b = 101 
    
    // a = 1 
    // b = 102 

    

    int i; 
    for (i = 0; i < 5; i++) { 
        func(); 
    } 

    // The above gives output as:

    // Static=2 
    // Nonstatic=2 

    // Static=3 
    // Nonstatic=2 

    // Static=4 
    // Nonstatic=2 

    // Static=5 
    // Nonstatic=2 

    // Static=6 
    // Nonstatic=2 

    return 0; 
} 