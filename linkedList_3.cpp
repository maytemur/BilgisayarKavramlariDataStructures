#include <stdio.h>
#include <stdlib.h>
// bu dersden sonra hafýzada her türlü numara yapýlabilir!
//baðlý liste (linked List) normal listelerden farklý olarak deðiþken sayýsý sabit deðil ne kadar eleman lazým ise
//o kadar oluþturuluyor
// basitBagliListe.jpg dosyasýna bak

struct n {
	int x;
	n * next;
};
// Baðlý listelere eriþim Sequential'dýr yani sýralý olarak olabilir. Normal listelere eriþim ise Random'dýr. Yani
// herhangi bir liste elemanýna örneðin a[7] diyerek eriþmek mümkünken bu baðlý listelerde ancak o elemanýn bir
//önceki pointer'ý ile olur. Bunuda next next next diyerek yazamayacaðýmýz için dngüleri kullanýrýz.

typedef n node;

void yazdir(node*r){ //burada *r bizim pointer'ýmýz
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
	node * root; //bir tane root node'u tanýmlýyoruz
	root=(node *) malloc(sizeof(node)); // ilk kutumuzun içine 500 koyduk
	root->next= NULL;
	root->x=500;
	int i=0;
	for(i=0;i<5;i++){
		ekle(root,i*10);
	}
	//datastructure'da hiçbir þey elle tutulur gözle görülür deðildir hatta yazdýrýlabilir bile deðildir.
	//herþey kafamýzda hayaller üzerinden iþte bir kutu var o kutunun next'i var diyerek vs hafýzada tutulmasý
	//gerekerek yapýlýr, dolayýsý ile hayal gücümüzün biraz kuvvetli olmasý gerekiyor!
	//iþi biraz daha ileri götürüp bir linklist alýp içeriðini yazdýran bir fonksiyon yazalým
	yazdir(root); //root tan baþlayarak null 'a kadar linklist'in deðerlerini bastýracak. 10 20 30'u elle eklemiþtik
	//bunun üstüne döngü ile gelen deðerleride ekleyerek bastýracak	
}
