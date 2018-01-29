#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int i = 1 , move = 10;
    char message, input[256] ,output[256] ,read1 ,read2;
    FILE *fin,*fout;

//Determining the Action of the User

while(i==1){
    printf("Enter an 'e' from the keyboard to encode a message, or a 'd' from the keyboard for decode: \n");
    scanf("%c",&message);
    switch(message){
        case 'e':;
        i = 0;
        break;
        case 'd':;
        i = 0;
        break;
        default:;
        break; //if user enters anything else besides 'e' or 'd', it will continue to loop
    }
}

//Encoding Part

if(message == 'e'){
    printf("Enter the name for the file to encode \n"); //user enters name of the file they want to encode
    scanf(" %s", &input);
    printf("Enter the name for the output file \n"); //user enters name of the output file
    scanf(" %s", &output);

    fin = fopen(input,"r");
    fout = fopen(output,"w");

    while( fscanf(fin, "%c", &read1) != EOF){ //a while loop until EOF equals the input file
        read2 = read1;
        if (97 <= read2 && read2 <= 122)
            move = 0;
        else if (48 <= read2 && read2 <= 57)
            move = 1;
        else if (read2 == 32)
            move = 2;
        else if (read2 == 46)
            move = 3;
        else if (read2 == 10)
            move = 4;
        else{
            move = 10;
            continue;}
         switch(move){
            case 0:;
                fprintf(fout,"%c",*&read2-64);
                continue;
            case 1:;
                fprintf(fout,"%c",*&read2+11);
                continue;
            case 2:;
                fprintf(fout,"%c",*&read2+37);
                continue;
            case 3:;
                fprintf(fout,"%c",*&read2+24);
                continue;
            case 4:;
                fprintf(fout,"%c",*&read2+61);
                continue;
            case 10:;
                continue;

        }
    }
    }
//Decoding Part

if(message == 'd'){

    printf("Enter the name for the file to decode \n");
    scanf(" %s", &input);
    printf("Enter the name for the decoded file \n");
    scanf(" %s", &output);

     fin = fopen(input,"r"); // opens the file the user entered to decode
    fout = fopen(output,"w");

     while( fscanf(fin,"%c", &read1) != EOF){ // creates a while loop that reads the file to decode until it is not equal EOF
        read2 = read1;
        if (33 <= read2 && read2 <= 58) //long if statement which goes through all possible readings and determines which switch statement to use
            move = 0;
        else if (59 <= read2 && read2 <= 68)
            move = 1;
        else if (read2 == 69)
            move = 2;
        else if (read2 == 70)
            move = 3;
        else if (read2 == 71)
            move = 4;
        else
            continue;
        switch(move){
            case 0:;
                fprintf(fout,"%c",*&read2+64);
                continue;
            case 1:;
                fprintf(fout,"%c",*&read2-11);
                continue;
            case 2:;
                fprintf(fout,"%c",*&read2-37);
                continue;
            case 3:;
                fprintf(fout,"%c",*&read2-24);
                continue;
            case 4:;
                fprintf(fout,"%c",*&read2-61);
                continue;
            case 10:;
                continue;

        }
    }
     }

    return 0;
}
