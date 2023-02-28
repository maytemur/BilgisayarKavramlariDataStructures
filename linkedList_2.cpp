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

int main(){
	node * root; //bir tane root node'u tanýmlýyoruz
	root= (node *)malloc(sizeof(node));
	root -> x=10;
	root -> next= (node *) malloc (sizeof(node));
	root -> next -> x=20; //burada istediðim kadar ardýþýk baðlý data oluþturabilirim
	root -> next -> next = (node *) malloc(sizeof(node));
	root -> next -> next -> x=30;
	root -> next -> next -> next = NULL;
	node * iter;
	iter= root; // hem root hem iter ayný kutuyu gösterecek burada
	printf("1nci eleman %d \n",iter->x); // ilk kutudaki deðer 10 u basar
	iter= iter ->next; //burada iter bir sonraki kutuya geçecek
	printf("2nci eleman %d \n",iter->x); // ikinci kutudaki deðer 20 yi basar
	// buraya kadar next next diyerek yaptýk , döngü kullanarak yapalým
	iter= root;
	int i=0;
	while (iter->next!=NULL){ //iter!=NULL dan deðiþtirdik. En sona bir kutu eklemek için bir önceki 
	//pointer'a gitmemiz lazým buda iter->next'i null olanýn bir öncesi	
		i++;
		printf("%dinci eleman(while): %d \n",i,iter->x);
		iter= iter -> next;		
	}
	for(i=0;i<5;i++){
		iter->next = (node *)malloc(sizeof(node));
		iter= iter -> next;
		iter->x= i*10;
		iter->next=NULL;
	}
	//datastructure'da hiçbir þey elle tutulur gözle görülür deðildir hatta yazdýrýlabilir bile deðildir.
	//herþey kafamýzda hayaller üzerinden iþte bir kutu var o kutunun next'i var diyerek vs hafýzada tutulmasý
	//gerekerek yapýlýr, dolayýsý ile hayal gücümüzün biraz kuvvetli olmasý gerekiyor!
	//iþi biraz daha ileri götürüp bir linklist alýp içeriðini yazdýran bir fonksiyon yazalým
	yazdir(root); //root tan baþlayarak null 'a kadar linklist'in deðerlerini bastýracak. 10 20 30'u elle eklemiþtik
	//bunun üstüne döngü ile gelen deðerleride ekleyerek bastýracak	
}
