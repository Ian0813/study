/*
 * =====================================================================================
 *
 *       Filename:  ip_convert_int.c
 *
 *    Description:  a dotted-decimal notation IP convert to Int.
 *
 *        Version:  1.0
 *        Created:  2021年04月10日 14時27分21秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <math.h>


long long IP_Convert_Int(char *ip){

	char *save = NULL, ip_copy[INET_ADDRSTRLEN], index = 0, *result, aa[10];
	long long ip_number[4];
	memset(ip_number, 0, sizeof(ip_number));
	strcpy(ip_copy, ip);


	//printf("%s\n", ip_copy);
	//memset(ip_copy, 0, sizeof(ip_copy));
	//return 0;

	//do{

	//	if(index > 3){
	//		break;
	//	}

	//	result = strtok_r(ip_copy, ".", &save);
	//	if(ip_copy == NULL){
	//		printf("EXit");
	//		exit(1);
	//	}
	//	//printf("%d\n", strlen(ip_copy));
	//	//printf("%d\n", strlen(result));
	//	//printf("breakpoint result : %s\n", result);
	//	ip_number[index] = atoi(result);

	//	//printf("breakpoint\n");
	//	//printf("ip_number : %d\n", ip_number[index]);
	//	index++;
	//	bzero(ip_copy, strlen(ip_copy));
	//	strcpy(ip_copy, save);

	//}while(index < 4);
	
	result = strtok(ip_copy, ".");
	ip_number[index] = atoll(result);
	index++;

	while(index < 4){
		result = strtok(NULL, ".");
		ip_number[index] = atoll(result);
		index++;
	}

	return (ip_number[0] * pow(2, 24)) + (ip_number[1] * pow(2, 16)) + (ip_number[2] * pow(2, 8)) + ip_number[3];

}
int main(int argc, char *argv[]){

	if(argc < 1){
		printf("Please follow : %s [IP ADDRESS]\n", argv[0]);
		exit(1);
	}

	
	char ip[INET_ADDRSTRLEN] = {0};

	strcpy(ip, argv[1]);
	printf("%s\n", ip);

	long long result = IP_Convert_Int(ip);
	printf("Result : %lld\n", result);

	return 0;

}

