#include <stdio.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char* argv[]){

	char a[25] = "";
	char b[24] = "";

	memcpy(a, argv[1], strlen(argv[1]));
	memcpy(b, argv[2], strlen(argv[2]));

	printf("%s\n", a);
	printf("%s\n", b);

	FILE *fp1= fopen(a, "rb");
        FILE *fp2= fopen(b, "rb");

	if(fp1 == NULL || fp2 == NULL){
		puts("file read error");
		return -1;
	}

	//file read
	int n1, n2;
	fread(&n1, sizeof(int), 1, fp1);
	fread(&n2, sizeof(int), 1, fp2);

	//result 
	int sum;
	n1 = ntohl(n1);
	n2 = ntohl(n2);	
	sum = n1 + n2;
	printf("result: %d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, sum, sum); 

	//stream close
	if(fp1 != NULL) fclose(fp1);
	if(fp2 != NULL) fclose(fp2);
	return 0;
}
