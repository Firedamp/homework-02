#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sum(int *tmpsum, int h, int l, int i, int j, int k, int **num){
	int a, tmpnum, s = 0;
	*tmpsum = 0;
	for(a = i; a <= j; a++){
		tmpnum = num[(a >= h ? a-h : a)][(k >= l ? k-l : k)];
		s = *tmpsum + tmpnum;
		if((*tmpsum > 0 && tmpnum > 0 && (s <= *tmpsum || s <= tmpnum)) || (*tmpsum < 0 && tmpnum < 0 && (s >= *tmpsum || s >= tmpnum)))
			return 0;
		*tmpsum = s;
	}
	return 1;
}

int main(int argc, char *argv[]){
	int h, l, i, j, k, m, max, maxend, **num, ult, super, tmpsum, isv = 0, ish = 0;
	char buf[257], *p;
	FILE *in;
	for(i = 1; i < argc-1; i++){
		if(!strcmp(argv[i], "/v"))
			isv = 1;
		else if(!strcmp(argv[i], "/h"))
			ish = 1;
		else if(!strcmp(argv[i], "/a")){
			printf("ERROR: \"/a\" not support yet\n");
			return 0;
		}
		else{
			printf("ERROR: command input error\n");
			return 0;
		}
	}
	if((in = fopen(argv[argc-1], "r")) == NULL){
		printf("ERROR: file open failed\n");
		return 0;
	}
	if(fgets(buf, 256, in) == NULL){
		printf("ERROR: file input error\n");
		return 0;
	}
	h = atoi(buf);
	if(h == 0 && buf[0] != '0'){
		printf("ERROR: file input error\n");
		return 0;
	}
	if(fgets(buf, 256, in) == NULL){
		printf("ERROR: file input error\n");
		return 0;
	}
	l = atoi(buf);
	if(l == 0 && buf[0] != '0'){
		printf("ERROR: file input error\n");
		return 0;
	}

	num = (int **)malloc(h * sizeof(int));
	for(i = 0; i < h; i++)
		num[i] = (int *)malloc(l * sizeof(int));
	for(i = 0; i < h; i++){
		if(fgets(buf, 256, in) == NULL){
			printf("ERROR: file input error\n");
			return 0;
		} 
		for(j = 0; j < l; j++){
			p = (j == 0 ? strtok(buf, ",") : strtok(NULL, ","));
			if(p == NULL){
				printf("ERROR: file input error\n");
				return 0;
			}
			num[i][j] = atoi(p);
			if(num[i][j] == 0 && p[0] != '0'){
				printf("ERROR: file input error\n");
				return 0;
			}
		}
	}
	ult = num[0][0];
	for(i = 0; i < h; i++){
		for(j = i; j < (isv ? h+i : h); j++){
			super = num[0][0];
			for(m = 0; m < (ish ? l : 1); m++){
				if(!sum(&max, h, l, i, j, m, num)){
					printf("ERROR: int overflow\n");
					return 0;
				}
				maxend = max;
				for(k = m+1; k < (ish ? l+m : l); k++){
					if(!sum(&tmpsum, h, l, i, j, k, num)){
						printf("ERROR: int overflow\n");
						return 0;
					}
					if((maxend > 0 && tmpsum > 0 && (maxend+tmpsum <= maxend || maxend+tmpsum <= tmpsum)) || (maxend < 0 && tmpsum < 0 && (maxend+tmpsum >= maxend || maxend+tmpsum >= tmpsum))){
						printf("ERROR: int overflow\n");
						return 0;
					}
					maxend = maxend+tmpsum > tmpsum ? maxend+tmpsum : tmpsum;
					max = max > maxend ? max : maxend;
				}
				super = max > super ? max : super;
			}
			ult = super > ult ? super : ult;
		}
	}
	printf("%d\n", ult);
}