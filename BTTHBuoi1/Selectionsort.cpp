#include <stdio.h>

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
} recordtype;

void Swap(
recordtype *x,recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void Selectionsort(recordtype a[], int n){
	int i,j, lowindex;
	keytype lowkey;
	
	for (i=0; i<=n-2;i++){
		lowkey = a[i].key;
		lowindex = i;
		
		for (j = i+1; j<= n-1;j++){
			if (a[j].key < lowkey){
				lowkey = a[j].key;
				lowindex = j;
		}
	}
	Swap(&a[i], &a[lowindex]);
	
	}
	
}

void Read(recordtype a[], int *n){
	FILE *f;
	f = fopen("Data.txt", "r");
	int i =0;
	 if( f!=NULL)
	 while( !feof(f)){
	 	fscanf (f, "%d%f", &a[i].key, &a[i].otherfields);
	 	i++;
	 	
}
	 else printf("loi mo file\n");
	 fclose(f);
	 *n = i;
}

void Print(recordtype a[], int n){
	int i;
	for (i=0; i<n; i++)
	printf ("%3d%5d%8.2f\n", i +1, a[i].key, a[i].otherfields );
	
}

 main(){
	recordtype a[30];
	int n;
	
	printf("Thuat toan Selection Sort\n\n");
	Read(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	Print(a,n);
	
	Selectionsort(a,n);
	printf("Du lieu sau khi sap xep la:\n");
	Print(a,n);
	
	return 0;
	
}


