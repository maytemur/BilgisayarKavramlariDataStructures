#include <stdio.h>
#include <stdlib.h>
// bu dersden sonra haf�zada her t�rl� numara yap�labilir!
//ba�l� liste (linked List) normal listelerden farkl� olarak de�i�ken say�s� sabit de�il ne kadar eleman laz�m ise
//o kadar olu�turuluyor
// basitBagliListe.jpg dosyas�na bak

struct n {
	int x;
	n * next;
};
// Ba�l� listelere eri�im Sequential'd�r yani s�ral� olarak olabilir. Normal listelere eri�im ise Random'd�r. Yani
// herhangi bir liste eleman�na �rne�in a[7] diyerek eri�mek m�mk�nken bu ba�l� listelerde ancak o eleman�n bir
//�nceki pointer'� ile olur. Bunuda next next next diyerek yazamayaca��m�z i�in dng�leri kullan�r�z.

typedef n node;

int main(){
	node * root; //bir tane root node'u tan�ml�yoruz
	root= (node *)malloc(sizeof(node));
	root -> x=10;
	root -> next= (node *) malloc (sizeof(node));
	root -> next -> x=20; //burada istedi�im kadar ard���k ba�l� data olu�turabilirim
	root -> next -> next = (node *) malloc(sizeof(node));
	root -> next -> next -> x=30;
	root -> next -> next -> next = NULL;
	node * iter;
	iter= root; // hem root hem iter ayn� kutuyu g�sterecek burada
	printf("1nci eleman %d \n",iter->x); // ilk kutudaki de�er 10 u basar
	iter= iter ->next; //burada iter bir sonraki kutuya ge�ecek
	printf("2nci eleman %d \n",iter->x); // ikinci kutudaki de�er 20 yi basar
	// buraya kadar next next diyerek yapt�k , d�ng� kullanarak yapal�m
	iter= root;
	int i=0;
	while (iter!=NULL){ 
		i++;
		printf("%dinci eleman: %d \n",i,iter->x);
		iter= iter -> next;		
	}
}
