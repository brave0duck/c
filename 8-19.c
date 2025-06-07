#include <stdio.h>                                                           
#include <stdlib.h>                                                          
#include <string.h>                                                          
                                                                             
void add(char* str);   // 문자열 배열(포인터 배열)에 문자열(str)을 추가하는 함수          
void printArr(void);                                                         
void sort(char* str[]);

char* strArr[10];     // 문자열을 저장할 배열                                      
int   pos = 0;        // 문자열을 저장할 위치(배열 strArr의 index)                   
                                                                             
int main(void) {                                                             
	char input[50]={0};   	// 사용자가 입력한 단어를 저장할 배열                    
                                                                             
	printf("저장할 단어를 입력하세요.(ENTER:종료)\n>");                             
    while(scanf("%49[^\n]%*c", input) != 0){
        add(input);
        printf(">");
    }

    // while(fgets(input, sizeof(input),stdin) != NULL)
    // {
    //     add(input);
    //     printf(">");
    // }
	printf("\n입력하신 단어는 다음과 같습니다.\n");                                  
	printArr();
    
    printf("\n정렬후 단어는 다음과 같습니다.\n");                                  
    sort(strArr);
    printArr();
    for(int i=0; i<=pos; i++)
        free(strArr[i]);
    
	return 0;                                                               
}
void sort(char* str[]){
    char * tmp;
    for(int i=0; i<pos-1; i++)
    {
        for(int j=i+1; j<pos; j++)
        {
            if(strcmp(str[i],str[j]) > 0)
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }

    }
    
}
void add(char* str) {                                                        
	
	char* tmp = malloc(sizeof(char)*(strlen(str)+1));                       
                                                                             
	strcpy(tmp, str);
	strArr[pos++] = tmp;
}                                                                            
                                                                             
void printArr(void) {                                                        
	int i;                                                                  
	printf("[");                                                            
                                                                             
	for (i=0;i<pos;i++)                                                     
		printf("%s, ", strArr[i]);                                      
	printf("]\n");                                                          
}                            