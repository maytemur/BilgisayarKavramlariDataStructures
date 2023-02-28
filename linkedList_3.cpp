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

void yazdir(node*r){ //burada *r bizim pointer'�m�z
	while(r!=NULL){
		printf("%d \n",r->x);
		r= r->next;
	}
}
void ekle(node *r,int x){
	while(r->next!=NULL){
		r=r->next;
	}
	r->next=(node*)malloc(sizeof(node));
	r->next->x=x;
	r->next->next=NULL;
}
int main(){
	node * root; //bir tane root node'u tan�ml�yoruz
	root=(node *) malloc(sizeof(node)); // ilk kutumuzun i�ine 500 koyduk
	root->next= NULL;
	root->x=500;
	int i=0;
	for(i=0;i<5;i++){
		ekle(root,i*10);
	}
	//datastructure'da hi�bir �ey elle tutulur g�zle g�r�l�r de�ildir hatta yazd�r�labilir bile de�ildir.
	//her�ey kafam�zda hayaller �zerinden i�te bir kutu var o kutunun next'i var diyerek vs haf�zada tutulmas�
	//gerekerek yap�l�r, dolay�s� ile hayal g�c�m�z�n biraz kuvvetli olmas� gerekiyor!
	//i�i biraz daha ileri g�t�r�p bir linklist al�p i�eri�ini yazd�ran bir fonksiyon yazal�m
	yazdir(root); //root tan ba�layarak null 'a kadar linklist'in de�erlerini bast�racak. 10 20 30'u elle eklemi�tik
	//bunun �st�ne d�ng� ile gelen de�erleride ekleyerek bast�racak	
}
