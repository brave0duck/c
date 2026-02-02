#include <stdio.h>                                                                
#include <time.h>                                                                 
#include <stdlib.h>                                                               
                                                                                  
int main(void) {                                                                  
	char data[] = { 'A', 'A', 'B', 'C' };                                        
	int count[sizeof(data) / sizeof(data[0])] = { 0 }; // �󵵼��� ������ �迭         
                                                                                  
	char dArr[sizeof(data) / sizeof(data[0])] = { 0 };                           
	const int LEN = sizeof(data) / sizeof(data[0]);                              
                                                                                  
	int i, j;                                                                    
	int pos = 0, sum = 0;;                                                       
                                                                                  
	srand((unsigned)time(NULL));                                                 
                                                                                  
	for (i=0;i<100;i++)                                                          
		count[rand() % LEN]++; // ���Ƿ� ���õ� ����� ���� ������Ų��.                
                                                                                  
	for (i=0;i<LEN;i++)                                                          
		printf("%c=%d\n", data[i], count[i]); // �� �������� �󵵼��� ���          
                                                                                  
	printf("\n== sum ==\n");                                                     
                                                                                  
	for (i=0;i<LEN;i++) {                                                        
		for (j=0;j<pos && dArr[j] != data[i];j++); // �ߺ�üũ                  
                                                                                  
		if (j == pos)  // j==pos�� ���̸�, �ߺ��� ���� ���ٴ� �ǹ�                    
			dArr[pos++] = data[i];  // data[i]�� �迭 dArr�� �߰�            
	}                                                                            
                                                                                  
	for (i=0;i<pos;i++) {                                                        
		sum=0;                                                               
		for (j=0;j<LEN;j++) {                                                
			if (dArr[i] == data[j])                                      
				sum += count[j];                                     
		}                                                                    
		printf("%c=%d", dArr[i], sum);                                     
		for(int z=0; z<sum;z++)
			printf("*");
		printf("\n");
	}                                                                            
                                                                                  
	return 0;                                                                    
}                                                                                 
