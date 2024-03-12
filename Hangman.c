// SHREYA CHINDEPALLI
// program on the Hangman Game

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>   // for call to time() in srand(time(NULL))

#define DEBUG 1  // 1-development mode, prints more info; 0 - user mode, prints less
#define MAX_WRONG 6

int play_session(int level);
void sessions_score(int Won,int Total);
void load_file(int level);
void print_init_hangman(void);
char filename[100];               // to store filename

int main(){
    int level;
    char enter;
    if (DEBUG == 1) {
        srand(1);  // the same sequence of random numbers will be generated for each run
    }
    else {
        srand(time(NULL));  // a different sequence of random numbers will be generated with each run
    }

    printf("Choose difficulty level (exit the game: 0, easy: 1, medium: 2, hard: 3): ");
    scanf("%d%c", &level, &enter);
    while (level!=0){
        play_session(level);
        printf("Choose difficulty level (exit the game: 0, easy: 1, medium: 2, hard: 3): ");
        scanf("%d%c", &level, &enter);
    }
    printf("\nThank you for playing our game! Goodbye!");
}

int play_session(int level){

    int N;                            // no of words in the  respective textfile
    int r = 0;                        // random number generated
    int ct = 0;
    char buff[50];                    // store word from the file
    int i = 0;
    int play_again = 1;               // to play game again
    char input_letter;                // stores input letters
    char used_letters[100];           // stores used letters
    char enter;                       // stores the new line character (ENTER)
    int bad_guesses = 0;              // stores number of bad guesses
    int input_count = 0;              // stores the number of input letters
    int n = 0;
    int total_games_played = 0;       // stores the total number of games played in one session
    int games_won = 0;                // stores the number of games won in one session
    int length = 0;                    // stores the length of the word stored in variable buff
    int j = 0;
    int k = 0;
    int l = 0;
    int p = 0;
    int flag = 0;
    int used_flag =0;
    int m = 0;

    FILE * fp = NULL;       // to open the file

    load_file(level);       // prints the level (easy.txt , medium.txt , hard.txt)

    while(play_again==1){
        input_letter = " ";
        enter = " ";
        input_count = 0;
        bad_guesses = 0;
        ct =0;

        fp = fopen(filename,"r+");

        // to check if the file has opened
        if(fp == NULL){
            printf("Will exit. Failed to open file: %s", filename);       // to indicate if the file did not open
            return 0;
        }
        else                //
            printf("Loading file: %s",filename);        // to print the file name if the file opened

        fscanf(fp,"%d",&N);
        r = rand()% N + 1;     // to generate random number

        // to store the word corresponding to the random number generated
        while(!feof(fp)&&(ct<r)){
            fscanf(fp,"%s", buff);           // storing the word in a variable buff
            ct++;
        }

        fclose(fp);      // closes the file

        printf("\n-----hidden word: |%s|\n", buff);    //buff now has the r-th word from the file. continue to use it as the hidden word word
        printf("\n\n\n\n\n\n\nLevel: %d\n\n", level);          // prints the level
        print_init_hangman();          // prints the initial hangman structure
        printf("Used Letters: \n");           // prints the used letters
        printf("Number of bad guesses: %d (out of 6)\n",bad_guesses);        // prints the current number of bad guesses


        length=0 ; // stores the length of the word stored in variable buff
        j=0;
        k=0;

        length = strlen(buff);

        char word[length];
        char buff_new[length];

        for(j=0;j<length;j++){
            word[j] = '-' ;
            buff_new[j]=buff[j];
        }

        for(k=0;k<length;k++){
            printf("%c",word[k]);            // prints the dashed word
        }

        printf("\n");

        input_count = 0;

        while((strncmp(buff_new,word,sizeof(buff_new)))!=0 && (bad_guesses<6)&&(input_letter!='0')){
            printf("\nEnter a letter :");         // printing
            scanf("%c%c", &input_letter, &enter);     // stores the input letter given by the user in corresponding variable

            if(input_letter!='0'){
                input_count = input_count + 1;
                used_letters[input_count - 1] = input_letter;             // storing used letters

                printf("\n\n\n\n\n\n\n\nLevel: %d\n\n", level);          // printing level(1, 2, or 3)



                l=0;
                p=0;
                flag = 0;
                used_flag =0;
                flag = 0;

                for(p=0;p<(input_count-1);p++){
                    if(used_letters[p]==input_letter){
                        used_flag = 1;
                    }
                }
                if (used_flag != 1){
                    for(l=0;l<length;l++){
                        if (buff[l]==input_letter){
                            word[l]=input_letter;
                            flag = 1;
                        }
                    }
                }
                // counting the number of bad guesses
                if (flag==1){
                    bad_guesses = bad_guesses;
                }
                else
                    bad_guesses = bad_guesses + 1;

                // printing the hangman structure
                if (bad_guesses==0){
                    print_init_hangman();
                }

                else if (bad_guesses==1){
                    printf("\n------|\n");
                    printf("|     |\n");
                    printf("|     o\n");
                    printf("|\n");
                    printf("|\n");
                    printf("|\n");
                    printf("|\n");
                    printf("-----------\n");
                }

                else if (bad_guesses==2){
                    printf("\n------|\n");
                    printf("|     |\n");
                    printf("|     o\n");
                    printf("|     |\n");
                    printf("|     |\n");
                    printf("|     |\n");
                    printf("|\n");
                    printf("|-----------\n");
                }

                else if (bad_guesses==3){
                    printf("\n------|\n");
                    printf("|     |\n");
                    printf("|     o\n");
                    printf("|     |\n");
                    printf("|    /|\n");
                    printf("|     |\n");
                    printf("|\n");
                    printf("-----------\n");
                }

                else if (bad_guesses==4){
                    printf("\n------|\n");
                    printf("|     |\n");
                    printf("|     o\n");
                    printf("|     |\n");
                    printf("|    /|\\\n");
                    printf("|     |\n");
                    printf("|\n");
                    printf("-----------\n");
                }

                else if (bad_guesses==5){
                    printf("\n------|\n");
                    printf("|     |\n");
                    printf("|     o\n");
                    printf("|     |\n");
                    printf("|    /|\\\n");
                    printf("|     |\n");
                    printf("|    /\n");
                    printf("-----------\n");
                }

                else if (bad_guesses==6){
                    printf("\n------|\n");
                    printf("|     |\n");
                    printf("|     o\n");
                    printf("|     |\n");
                    printf("|    /|\\\n");
                    printf("|     |\n");
                    printf("|    / \\\n");
                    printf("-----------\n");
                }

                printf("Used letters: ");              //printing used letters

                for(n=0;n<input_count;n++){
                    printf("%c",used_letters[n]);      // printing used letters
                }

                printf("\nNumber of bad guesses: %d (out of 6)\n",bad_guesses);              // printing the number of bad guesses


                m=0;
                for(m=0;m<length;m++){
                    printf("%c",word[m]);
                }

                printf("\n");
            }
        }
        if((bad_guesses == 6)||(input_letter == '0')){
            games_won = games_won;
            printf("\nSorry. You lost. Better luck next time.\nThe word was: %s\n\n",buff);

        }
        else if(bad_guesses<6){
            games_won = games_won + 1;
            printf("\nYou won!\n\n");
        }

        total_games_played = total_games_played + 1;         // total games played is incremented
        printf("Do you want to play again? (0-no, 1-yes) ");
        scanf("%d%c", &play_again,&enter);       // 0-no, 1-yes
    }


    sessions_score(games_won,total_games_played);     // prints the session score using sessions_score function

}



//Loads appropriate file depending on the level (user_input)
void load_file(int level){
    if(level==1){
        // loads easy.txt
        strcpy(filename,"easy.txt");
    }
    else if(level==2){
        // loads medium.txt
        strcpy(filename,"medium.txt");
    }
    else{
        // loads hard.txt
        strcpy(filename,"hard.txt");
    }
}

// function to print the sessions score
void sessions_score(int Won,int Total){
    printf("\n****************************\n");
    printf("*  Session score:   %d/%d    *\n",Won,Total);
    printf("****************************\n\n");

}

// function to print the initial hangman structure
void print_init_hangman(void){
    printf("\n------|\n");
    printf("|     |\n");
    printf("|\n|\n|\n|\n|\n");
    printf("-----------\n");
}





