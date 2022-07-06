#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include<stdbool.h>

int main()
{
	char palavra[100]; 
    char letra;
    int i;
    int vida = 6;

	printf("Digite uma palavra: \n");
	fgets(palavra, sizeof(palavra), stdin);
    
    system("cls"); 

    char underline[strlen(palavra)]; 
    //Essa função vai copiar as letras da palavra para o underline - String Copy;
    strcpy(underline, palavra); 

    for(i = 0; i < strlen(palavra)-1; i++) 
    {
        underline[i] = '_';
    }

////////////////////UPDATE//////////////////////////////////////////////
 
    while(1)
    {
        printf("Tentativas restantes: %d\n\n\n\n", vida);

        //Mostrar na tela os underlines para cada letra da palavra 
        for(i = 0; i < strlen(underline)-1; i++)
        {
            printf("%c ", underline[i]);
        }
        
        //Pegando a letra que o jogador digitar
        printf("\n\nDigite uma letra: ");
        scanf("%c", &letra); 

        bool errou = true;
        for(i = 0; i< strlen(underline); i++)
        {
            //Se a letra for igual a palavra do inicio
            if(letra == palavra[i]) 
            {
                //Substituindo o underline pela letra
                underline[i] = letra;
                errou = false; //Se alguma for igual ele não errou
            }
        }
        system("cls");

        if(errou) vida--;

        /*
        if(underline == palavra)
        {
            Win();
            break;
        }
        */

        //Player ganhou
        if(strcmp(underline, palavra) == 0)
        {
            Win();
            break;
        }

        if(vida <= 0) //Game Over
        {
            GameOver();
            break;
        }
    }
            system("pause");
	return 0;
}

void Win()
{
    printf("                     __     __                    _       \n");
    printf("                     \\ \\   / /                   (_)      \n");
    printf("                      \\ \\_/ /__  _   _  __      ___ _ __  \n");
    printf("                       \\   / _ \\| | | | \\ \\ /\\ / / | '_ \\ \n");
    printf("                        | | (_) | |_| |  \\ V  V /| | | | |\n");
    printf("                        |_|\\___/ \\__,_|   \\_/\\_/ |_|_| |_|\n");
    printf("                                                          \n");
}

void GameOver()
{
    printf("                          _____                         ____                 \n");
    printf("                         / ____|                       / __ \\                \n");
    printf("                        | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n");
    printf("                        | | |_ |/ _` | '_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ '__|\n");
    printf("                        | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n");
    printf("                         \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n");
}
