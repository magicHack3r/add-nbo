#include <stdio.h>
#include <netinet/in.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char* argv[]){

	char a[25] = "";
	char b[25] = "";

	if ( argc != 3){
		printf("syntax: ./add-nbo <file1> <file2>\n");
		return 1;
	}

	memcpy(a, argv[1], strlen(argv[1]));
	memcpy(b, argv[2], strlen(argv[2]));

	a[strlen(argv[1])]=0;
	b[strlen(argv[2])]=0;

	FILE *fp1= fopen(a, "rb");
        FILE *fp2= fopen(b, "rb");

	// check file pointer
        uint8_t chk_fail_fp = 0;	
	if(fp1 == NULL){
		chk_fail_fp=1;
		printf("No such file '%s'\n", a);
	}
	if(fp2 == NULL){
		chk_fail_fp=1;
		printf("No such file '%s'\n", b);
	}
	if(chk_fail_fp == 1){
		return 1;
	}

	//file read
	uint32_t n1, n2;
	fread(&n1, sizeof(uint32_t), 1, fp1);
	fread(&n2, sizeof(uint32_t), 1, fp2);

	//result 
	uint32_t sum;
	n1 = ntohl(n1);
	n2 = ntohl(n2);	
	sum = n1 + n2;
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum); 

	//stream close
	if(fp1 != NULL) fclose(fp1);
	if(fp2 != NULL) fclose(fp2);
	return 0;
}
