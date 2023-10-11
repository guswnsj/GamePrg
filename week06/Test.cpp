#include <stdio.h>
#include <stdlib.h>  // system �Լ��� ����

void display_text(int count);
void display_question(void);
void display_result(void);
void intro_game(void);
char sol[10][11];  // ������� �Է� ���� ������ �迭

int main(void) {
    intro_game();
    display_question();
    printf("\n����Ǯ�̰� ��� �������ϴ�.\n");
    printf("\n\nǮ�̸� ������ ����Ű�� �����ÿ�.");
    getchar();
    display_result();
    return 0;
}

void display_text(int count) {
    printf("���� ������ �а� ���� �Է��Ͻÿ�.\n\n");
    printf("(%d�� ����) \n\n", count + 1);
}

void display_question(void) {
    FILE *fp1;
    char chr1[82];
    int count=0;
    const char *file1="�ɸ��׽�Ʈ����.txt";
    
    // ������ ���۵Ǳ� ���� �ڼ� �Ҹ� ���
    #ifdef _WIN32  // Windows ȯ��
        system("WaveSound.wav");  
    #elif __linux__  // Linux ȯ��
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
            printf("\033[0;34m%s\033[0m", chr1);  // �Ķ��� ���
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
    const char *file2="�ɸ��׽�Ʈ�ؼ�.txt";
    fp2=fopen(file2, "r");
    while(!feof(fp2)) {
        fgets(chr1, 80, fp2);
        if (chr1[0]==10) {
            printf("����� ���� : %s\n", sol[count]);
            printf("���������� �ؼ��� ����Ű�� �����ÿ�.");
            getchar();
            count++;
        } else {
           printf("\033[1;31m%s\033[0m", chr1);  // ������ �� ���� ��Ʈ�� ���
        }
    }
    printf("����� ���� : %s\n", sol[count]);
    fclose(fp2);
}

void intro_game(void) {
    printf("�ɸ��׽�Ʈ ����\n\n");
    printf("���õǴ� ������ ��� ���� �ϰ���\n");
    printf("�ؼ��� ��µ˴ϴ�.\n\n");
    printf("����Ű�� ������ �����մϴ�. ");
    getchar();
}

