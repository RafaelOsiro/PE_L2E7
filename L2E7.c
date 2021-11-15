/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 7. Faça um programa que armazene uma frase a ser transmitida aos candidatos da próxima eleição 
com até 50 caracteres. Após o armazenamento da frase, solicite o primeiro nome do candidato e transforme-o 
todo em maiúsculo, concatenando-o com a frase, além de dois pontos. O resultado deverá ser apresentado a 
partir da linha 5. Após a apresentação o programa deverá ser encerrado imediatamente após 10 segundos 
(ver função sleep).
*/

//!LIBRARIES _______________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput();
void messageConfirmExit();
void messageExit();
void messageName(char *text);

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(char *text, int size, int option);
void functionUpString(char *text);
void functionFormateString(char *text1, char *text2);


int main()
{
    int option, quantityOfError = 0, size;
    char fullName[100], speech[50];
    bool validation = false, exitValidation = false;

    size = sizeof(fullName)/sizeof(fullName[0]);

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            
            functionInputString(speech, size, 1);
            functionInputString(fullName, size, 2);
            functionUpString(fullName);
            functionFormateString(fullName, speech);

            messageName(fullName);
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA FORMATAR UM DISCURSO.\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("--------------------\n");
    printf("[1] ENTRADA DE NOMES\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("--------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int option)
{
    switch (option)
    {
    case 1:
        printf("DIGITE O DISCURSO : ");
        break;
    
    case 2:
        printf("DIGITE O NOME DO CANDIDATO: ");
        break;

    default:
        break;
    }
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(char *text)
{      
    printf("%s\n", text);
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == '\n' || string[index] == ' ' || string[index] == '\0' || string[index] == '\r' || 
        string[index] == '\r\n' || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != "\0" && string[index] != "\r" && 
            string[index] != "\r\n" && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(char *text, int size, int option)
{
    int quantityOfError = 0, count = 0;
    bool validation = false;

    
    messageTitle();
    while (validation == false)
    {
        messageNameInput(option);
        fflush(stdin);
        fgets(text, size, stdin);
        validation = validationString(text);

        if (strlen(text) == (size - 1))
        {
            char charactere;
            while ((charactere = getchar()) != '\n' && charactere != EOF);
        }

        if (validation == false)
        {
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 2);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
        }
    }

    system("cls");
    count = 0;
    validation = false;
}

//  FUNCTION TO CONCATENATE STRING
void functionUpString(char *text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        text[i] = toupper(text[i]);
    }
}

void functionFormateString(char *text1, char *text2)
{
    int i = strlen(text1);

    text1[i-1] = '\072';
    text1[i] = '\040';
    text1[i+1] = '\0';

    strcat(text1, text2);
}