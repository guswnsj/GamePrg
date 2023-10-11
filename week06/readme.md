
#include <stdio.h>
#include <stdlib.h>  // system 함수를 위해

void display_text(int count);
void display_question(void);
void display_result(void);
void intro_game(void);
char sol[10][11];  // 사용자의 입력 값을 저장할 배열

int main(void) {
    intro_game();
    display_question();
    printf("\n문제풀이가 모두 끝났습니다.\n");
    printf("\n\n풀이를 보려면 엔터키를 누르시오.");
    getchar();
    display_result();
    return 0;
}

void display_text(int count) {
    printf("다음 문제를 읽고 답을 입력하시오.\n\n");
    printf("(%d번 문제) \n\n", count + 1);
}

void display_question(void) {
    FILE *fp1;
    char chr1[82];
    int count=0;
    const char *file1="심리테스트질문.txt";
    
    // 질문이 시작되기 전에 박수 소리 재생
    #ifdef _WIN32  // Windows
        system("WaveSound.wav");  
    #elif __linux__  // Linux
        system("WaveSound.wav");  
    #endif

    fp1=fopen(file1, "r");
    while(!feof(fp1)) {
        fgets(chr1, 80, fp1);
        if (chr1[0]==10) {
            display_text(count);
            scanf("%s", sol[count]);
            count++;
        } else {
            printf("\033[0;34m%s\033[0m", chr1);  // 파란색 출력
        }
    }
    display_text(count);
    scanf("%s", sol[count]);
    fclose(fp1);
}

void display_result(void) {
    FILE *fp2;
    char chr1[82];
    int count=0;
    const char *file2="심리테스트해설.txt";
    fp2=fopen(file2, "r");
    while(!feof(fp2)) {
        fgets(chr1, 80, fp2);
        if (chr1[0]==10) {
            printf("당신의 답은 : %s\n", sol[count]);
            printf("다음문제의 해설은 엔터키를 누르시오.");
            getchar();
            count++;
        } else {
           printf("\033[1;31m%s\033[0m", chr1);  // 빨간색 및 굵은 폰트로 출력
        }
    }
    printf("당신의 답은 : %s\n", sol[count]);
    fclose(fp2);
}

void intro_game(void) {
    printf("심리테스트 게임\n\n");
    printf("제시되는 문제에 모두 답을 하고나면\n");
    printf("해설이 출력됩니다.\n\n");
    printf("엔터키를 누르면 시작합니다. ");
    getchar();
}

