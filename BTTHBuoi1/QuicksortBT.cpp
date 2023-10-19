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

int FindPivot(recordtype a[], int i, int j){
	keytype firstkey;
	int k;
	k = i+1;
	firstkey = a[i].key;
	while (k <= j && a[k].key == firstkey) k++;
	if(k >j) return -1;
	if( a[k].key < firstkey ) return k; else return i;
	return i;
}

int Partition( recordtype a[], int i, int j, keytype pivot){
	int L, R;
	L=i;
	R= j;
	while ( L<= R){
		while (a[L].key <= pivot) L++;
		while (a[R].key > pivot) R--;
		
		if( L<R) Swap (&a[L], &a[R]);
	}
	return L;
}

void QuicksortBT(recordtype a[], int i, int j){
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a, i, j);
	if( pivotindex != -1){
		pivot = a[pivotindex].key;
		k = Partition(a, i, j, pivot);
		QuicksortBT(a, i , k-1);
		QuicksortBT(a, k, j);
	}
}
 main(){
	recordtype a[30];
	int n;
	
	printf("Thuat toan Quick Sort Bien The\n\n");
	Read(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	Print(a,n);
	
	QuicksortBT(a,0,n-1);
	printf("Du lieu sau khi sap xep la:\n");
	Print(a,n);
	
	return 0;
	
}

