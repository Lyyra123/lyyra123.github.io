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

void Pushdown(recordtype a[], int first, int last){
	int r=first;
	while (r<=(last-1)/2)
	if(last == 2*r +1){
		if(a[r].key > a[last].key) Swap(&a[r],&a[last]);
		r = last;
	} else
	if((a[r].key>a[2*r +1].key) && (a[2*r +2].key)){
		Swap(&a[r], &a[2*r +1]);
		r = 2*r +1;
	} else 
	if ((a[r].key) > a[2*r+2].key && (a[2*r+2].key < a[2*r+1].key))
	{
		Swap(&a[r], &a[2*r +2]);
		r = 2*r +2;
	} else 
	r = last;
}

void Heapsort(recordtype a[], int n){
	int i;
	
	for (i=(n-2)/2; i >=0; i--)
		Pushdown(a,i,n-1);
		for(i = n-1; i>=2; i--){
			Swap(&a[0], &a[i]);
			Pushdown(a,0,i-1);
		}
		Swap(&a[0],&a[1]);
}


main(){
	recordtype a[30];
	int n;
	
	printf("Thuat toan Heap Sort\n\n");
	Read(a,&n);
	printf("Du lieu truoc khi sap xep:\n");
	Print(a,n);
	
	Heapsort(a,n);
	printf("Du lieu sau khi sap xep la:\n");
	Print(a,n);
	
	return 0;
	
}
