/*	Korn Anin
	Som Puthea
	Chann Sothida
	Rin Vocuhnea
	Sath Maliya
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
# define SIZE 100

int im=0, de=0;
int ch;
int found = 0;
float total = 0;

//info for book
struct book{
  int ID;
  char name[10];
  char author[10];
  int qty;
  float  price;
}b;

//info for order
struct order{
  int ID;
  char name[10];
  char author[10];
  int qty;
  float  price;
}o;

void header(){
	printf(" \n\t\t\t\t\t          :-WELCOME TO:-");
	printf(" \n\t\t\t\t\t      :-HOPE BOOK STORE:-");
}

void importbook(){
	do{
		FILE *fp=fopen("Stok.txt","rb");
		if(fp==NULL){
            fp=fopen("Stock.txt","wr");
			fclose(fp);
			fp=fopen("stock.txt","rb");
		}
		printf("\nEnter book ID: "); scanf("%d", &b.ID); fflush(stdin);
		printf("Enter book name: "); gets(b.name); fflush(stdin);
		printf("Enter book author: "); gets(b.author); fflush(stdin);
		printf("Enter book quantity: "); scanf("%d", &b.qty); fflush(stdin);
		printf("Enter book price: "); scanf("%f", &b.price); fflush(stdin);
		fclose(fp);
		fp=fopen("Stock.txt","ab");
		fwrite(&b,sizeof(b),1,fp);
		fclose(fp);
		printf("\n1- to finish importing"); scanf("%d", &ch); fflush(stdin);
	}while ( ch != 1);

}

void removebook(){
 int id;
	FILE *fp1=fopen("temp.txt","wb"),*fp=fopen("Stock.txt","rb");
	printf("\nEnter book ID:");fflush(stdin);scanf("%d",&id); fflush(stdin);
	rewind(fp);
	while(fread(&o,sizeof(o),1,fp)!=0){
		if(id==o.ID)
			de=1;
		else
			fwrite(&o,sizeof(o),1,fp1);
	}
	fclose(fp);fclose(fp1);
	remove("Stock.txt");
	rename("temp.txt","Stock.txt");
	if(de==0)
  printf("ID not found\n");
	else
  printf("Delete Completed\n");
}

void showstock(){
	FILE *fp=fopen("Stock.txt","rb");
	printf("\n%10s%20s%20s%20s%20s","Book_ID","Book_Name", "Author","Book_Qty","Book_Price");
	while(fread(&b,sizeof(b),1,fp)!=0){
		printf("\n%10d%20s%20s%20d%20.2f$",b.ID,b.name, b.author,b.qty,b.price);
	}
	fclose(fp);
}

void orderbook(){
	int id;
	FILE *fp=fopen("Stock.txt","rb");
			printf("\nEnter book ID: "); scanf("%d", &id); fflush(stdin);
			while(fread(&b,sizeof(b),1,fp)!=0)
				if( id = b.ID){
					printf("\n%10s%20s%20s%20s%20s", "Book_ID", "Book_Name", "Author", "Book_Qty", "Book_Price");
					printf("\n%10d%20s%20s%20d%20.2f$", b.ID, b.name, b.author, b.qty, b.price);
					printf("\n\n\n\n\nDo you want to add this to you car? Type 3 to add\n"); scanf("%d", &ch); fflush(stdin);
					if( ch == 3){
						o.ID = b.ID;
						stpcpy( o.name, b.name);
						stpcpy( o.author, b.author);
						o.qty = b.qty;
						o.price = b.price;
						printf("\n\t\t\tAdded to cart");
						fclose(fp);
						fp=fopen("ShoppingCart.txt","ab");
						fwrite(&o,sizeof(o),1,fp);
						fclose(fp);

					}
				}
			if(found == 0){
				printf("Not in stock");
				getch();
			}
}
void searchforbook(){
	FILE *fp;
	char title[10], author[10];
	printf("\n\n\n\n\t\t\t1- to search for book by title\n\t\t\t2- to search for author");
	printf("\nEnter your choice: "); scanf("%d", &ch); fflush(stdin);
	switch (ch){
		case 1:
		printf("\n\t\t\tSearch book title");
			printf("\nEnter book title: "); gets(title); fflush(stdin);
			fp=fopen("Stock.txt","rb");rewind(fp);
			while(fread(&b,sizeof(b),1,fp)!=0)
				if(strcmp( title, b.name) == 0){
					printf("\n%10s%20s%20s%20s%20s", "Book_ID", "Book_Name", "Author", "Book_Qty", "Book_Price");
					printf("\n%10d%20s%20s%20d%20.2f$", b.ID, b.name, b.author, b.qty, b.price);
					printf("\n\n\n\n\nDo you want to add this to you car? Type 3 to add\n"); scanf("%d", &ch); fflush(stdin);
					if( ch == 3){
						o.ID = b.ID;
						stpcpy( o.name, b.name);
						stpcpy( o.author, b.author);
						o.qty = b.qty;
						o.price = b.price;
						printf("\n\t\t\tAdded to cart");
						fclose(fp);
						fp=fopen("ShoppingCart.txt","ab");
						fwrite(&o,sizeof(o),1,fp);
						fclose(fp);

					}
					found = 1;
				}
			if(found == 0){
				printf("Not in stock");
				getch();
			}
			break;
		case 2:
		 printf("\n\t\t\tSearch author");
			printf("\nEnter author: "); gets(author); fflush(stdin);
			fp=fopen("Stock.txt","rb");rewind(fp);
			while(fread(&b,sizeof(b),1,fp)!=0)
				if(strcmp( author, b.author) == 0){
					printf("\n%10s%20s%20s%20s%20s","Book_ID","Book_Name", "Author","Book_Qty","Book_Price");
					printf("\n%10d%20s%20s%20d%20.2f$",b.ID,b.name, b.author,b.qty,b.price);
					printf("\n\n\n\n\nDo you want to add this to you car? Type 3 to add\n"); scanf("%d", &ch); fflush(stdin);
					if( ch == 3){
						o.ID = b.ID;
						stpcpy( o.name, b.name);
						stpcpy( o.author, b.author);
						o.qty = b.qty;
						o.price = b.price;
						fclose(fp);
						fp=fopen("ShoppingCart.txt","ab");
						fwrite(&o,sizeof(o),1,fp);
						fclose(fp);
					}
					found =1; getch();
				}
				if(found == 0){
					printf("Not in stock");
					getch();
				}
			break;
	}
}

void showcart(){
	int id, b =0;
	FILE *fp1=fopen("temp.txt","wb"),*fp=fopen("ShoppingCart.txt","rb");
	printf("\n%10s%20s%20s%20s%20s","Book_ID","Book_Name", "Author","Book_Qty","Book_Price");
	rewind(fp);
	while(fread(&o,sizeof(o),1,fp)!=0){
		printf("\n%10d%20s%20s%20d%20.2f$",o.ID,o.name, o.author, o.qty, o.price);
	}
	printf("\n\n\nPress 1 check out\nPress 2 to remove book from the cart\n3 to order more"); scanf("%d", &ch); fflush(stdin);
	switch (ch){
		case 1:
		system("cls");
			header();
			printf("\n\t\t\t\t\tRecipe");
			printf("\n%10s%20s%20s%20s%20s","Book_ID","Book_Name", "Author","Book_Qty","Book_Price");
			rewind(fp);
			while(fread(&o,sizeof(o),1,fp)!=0){
				printf("\n%10d%20s%20s%20d%20.2f$",o.ID,o.name, o.author, o.qty, o.price);
				total = total + o.price;
			}
			printf("\n\nTotal : %f$", total);
			printf("\n\n\nPress 3 to accept payment"); scanf("%d", &ch); fflush(stdin);
			if( ch == 3)
				fclose(fp);
				remove("ShoppingCart.txt");
				printf("\n\t\t\t\t\tOrder Complete");
			break;
		case 2:
			fp=fopen("ShoppingCart.txt","rb");
			printf("Enter book ID:");fflush(stdin);scanf("%d",&id); fflush(stdin);
			rewind(fp);
			while(fread(&o,sizeof(o),1,fp)!=0){
				if(id==o.ID)
					b=1;
				else
					fwrite(&o,sizeof(o),1,fp1);
			}
			fclose(fp);fclose(fp1);
			remove("ShoppingCart.txt");
			rename("temp.txt","ShoppingCart.txt");
			if(b==0)printf("Delete not Completed\n");
			else printf("Delete Completed\n");
			break;
		case 3:
			break;
	}
}

int main(){
		header();
		printf("\n\n\n\n\n\t\t\t1- log in as admin\n\t\t\tPress other to enter as user"); scanf("%d", &ch); fflush(stdin);
		switch (ch) {
			case 1:
			 do{
     system("cls");
     printf("\n\n\n\n\n\t\t\t1- to import book\n\t\t\t2- to remove book\n\t\t\t3- to display book\n\t\t\t4- to exit"); scanf("%d", &ch); fflush(stdin);
     switch(ch){
      case 1:
       system("cls");
       printf("\n\t\t\t\t\tImport Book");
       importbook();
       break;
      case 2:
       system("cls");
       printf("\n\t\t\t\t\tRemove Book");
       showstock();
       removebook();
       break;
      case 3:
       system("cls");
        printf("\n\t\t\t\t\tStock");
        showstock();
        break;
     }
			 }while ( ch != 4 );
				break;
			default:
				do{
					system("cls");
					header();
					printf("\n\n\n\n\n\t\t\t1- to display available book\n\t\t\t2- to search for book\n\t\t\t3- to show ordered book\n\t\t\t6- to exit");
					printf("\nEnter your choice: "); scanf("%d", &ch); fflush(stdin);
					switch(ch) {
						case 1:
							system("cls");
							printf("\n\t\t\t\t\tDisplay avialable Book");
							showstock();
							printf("\n\n1 to order book\nOther to go back to main menu"); scanf("%d", &ch); fflush(stdin);
							switch(ch) {
        case 1:
         orderbook();
         break;
        case 2:
         break;
							}
							getch();
							break;
						case 2:
							system("cls");
							printf("\n\t\t\t\t\tLook for book");
							searchforbook();
							getch();
							break;
						case 3:
							system("cls");
							printf("\n\t\t\t\t\tShowed book on the cart");
							showcart();
							getch();
							break;
					}
				}while(ch != 6);
				break;
		}
	return 0;
	getch();
}
