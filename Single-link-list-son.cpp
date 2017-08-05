#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// khai bao cau truc du lieu
struct khachhang{
	char MKH[30];
	char HT[30];
	char GT[30];
	int	Tuoi;
	int	TG;
	int MP;
	float giatien;
};

struct Node{
	khachhang info;
	struct Node*next;
};

struct List{
	Node*Head;
	Node*Tail;
};

// cac chuong trinh chung

// 1. Tao 1 nut chua thong tin
Node *getNode(khachhang x){
	Node *p;
	p= new Node;
	if(p==NULL){
		printf("cap nhat thong tin that bai.");
		exit(1);
	}
	p->info=x;
	p->next=NULL;
	return p;

}


// 2.Tao danh sach chua nut
void khoitao(List &Q){
	Q.Head=NULL;
	Q.Tail=NULL;
}
// 3.Chen 1 nut vao cuoi danh sach
void Chencuoi(List &Q, Node *p){
	if(Q.Head==NULL)
	{
		Q.Head=p;
		Q.Tail=p;
	}
	else
	{
		Q.Tail->next=p;
		Q.Tail=p;
	}
}

// 3.Nhap 1 khach hang
void NhapKH(khachhang &x){
	printf ("\n \t Nhap Ma Khach Hang:"); 	fflush(stdin);	gets(x.MKH);
	printf ("\n Nhap ho va ten:"); 		fflush (stdin);		gets(x.HT);
	printf ("\n Nhap gioi tinh:");  	fflush (stdin);		gets(x.GT);
	printf ("\n Nhap tuoi:");				scanf("%d",&x.Tuoi);
	printf ("\n Nhap so gio thue phong:"); 	scanf("%d",&x.TG);
	printf ("\n Nhap Ma Phong:");			scanf("%d",&x.MP);
	x.giatien=x.TG*50000;
}
//  4.In thong tin cua 1 khach hang
void InKH(khachhang x){
	printf ("\n %7s", x.MKH);
	printf ("%15s",x.HT);
	printf ("%7s",x.GT);
	printf ("%15d",x.Tuoi);
	printf ("%10d", x.TG);
	printf ("%10d", x.MP);
	printf ("%10.0f", x.giatien);
}
// 5.Nhap danh sach khach hang
void NhapDSKH(List &Q){
	Node *p;
	int n,i;
	khachhang x;
	printf ("Nhap so khach hang: ");	scanf ("%d",&n);
	for (i=0; i<n;i++){
		NhapKH(x);
		p= getNode (x);
		Chencuoi (Q,p);
	}

}

// 6.In danh sach khach hang
void InDSKH(List Q){
	Node *p;
	for (p=Q.Head;p!=NULL;p=p->next)
		InKH(p->info);
}

// 7.Chen 1 khach hang vao vi tri bat ki
void chengiua(List &Q){
	Node *p, *q;
	khachhang x;
	char a[10];
	printf("\n \n Chen 1 vao sau 1 khach hang co ma la:"); fflush(stdin); gets(a);
	for(p=Q.Head;p!=NULL;p=p->next){
		if(strcmp(p->info.MKH,a)==0){
			printf ("\n Nhap thong tin khach hang can chen:");
			NhapKH(x);
			q=getNode(x);
			q->next=p->next;
			p->next=q;
			if(p==Q.Tail)
				Q.Tail=q;
			break;
		}
	}
		InDSKH(Q);
}

//10.Xoa 1 nut theo ma khach hang bat ki
void xoaK(List &Q){
	char K[10];
	Node *p, *q;
	printf ("\n Nhap ma khach hang can xoa: "); fflush(stdin); gets(K);
	for(p=Q.Head; p!=NULL; p=p->next)
	{
	q=p->next;
		if(strcmp(p->info.MKH,K)==0)
		{
			Q.Head=q;
			delete p;
			break;
		}
		else
		{
			if(strcmp(q->info.MKH,K)==0)
			{
				p->next=q->next;
				delete q;
				break;
			}
		}

	}

		if(Q.Head==NULL){
		printf("Het khach hang");
	}
	else{
		printf ("\n Danh sach sau khi xoa:");
		InDSKH(Q);
	}

}

// 11. Tim khach hang theo ten
Node *tim_ten(List Q){
	Node *p;
	char y[30];
	printf ("\n Nhap ten khach hang can tim:"); fflush(stdin); gets(y);
	for(p=Q.Head;p!=NULL; p=p->next)
		if(strcmp(p->info.HT,y)==0)
			break;
	return p;

}
// 12. Tim khach hang theo ma phong
Node *tim_mp(List Q){
	Node *p;
	int z;
	printf ("\n Nhap ma phong can tim:"); scanf("%d",&z);
	for(p=Q.Head;p!=NULL; p=p->next)
		if(p->info.MP==z)
				break;
	return p;
}
// 13. Tim kiem khach hang heo ma khach hang
Node *tim_mkh(List Q){
	Node *p;
	char t[30];
	printf ("\n Nhap ma khach hang can tim:"); fflush(stdin); gets(t);
	for(p=Q.Head;p!=NULL; p=p->next)
		if(strcmp(p->info.MKH,t)==0)
			break;
	return p;
}
// Hoan doi
void hoandoi(khachhang &a,khachhang &b){

	khachhang tg;
	tg=a;
	a=b;
	b=tg;
}
// 14. Sap xep khach hang theo tuoi giam dan
void sapxeptuoi_giamdan(List &Q){
	Node *p,*q;
	khachhang tg;
	for (p=Q.Head; p!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->info.Tuoi<q->info.Tuoi){
				hoandoi(p->info,q->info);
			}
		}
	}

	printf ("\n Danh sach khach hang sap xep theo tuoi giam dan la:");
	InDSKH(Q);
}
// 15.Sap xep khach hang theo tien phong tang dan
void sapxeptien_tangdan(List &Q){
	Node *p,*q;
	khachhang tg;
	for (p=Q.Head; p!=NULL; p=p->next){
		for(q=p->next;q!=NULL; q=q->next){
			if(p->info.giatien>q->info.giatien){
				hoandoi(p->info,q->info);
			}
		}
	}

	printf("\n Danh sach khach hang sap xep theo tien phong tang dan la:");
	InDSKH(Q);
}
// 16.In danh sach khach hang nho hon 20 tuoi
void KHnhohon20(List &Q){
	Node *p;
	printf ("\n Danh sach khach hang nho hon 20 tuoi la:");
	for (p=Q.Head;p!=NULL;p=p->next){
		if(p->info.Tuoi<20){
			InKH(p->info);
		}
	}
}
// 17.In dach sach khach hang co tien phong lon nhat
void Tienphongmax (List Q){
	Node *p;
	float max;
	max=Q.Head->info.giatien;
	printf ("\n Khach hang co tien phong lon nhat la");
	for(p=Q.Head;p!=NULL; p=p->next ){
		if(p->info.giatien>max){
			max=p->info.giatien;
		}
	}
	for (p=Q.Head;p!=NULL; p=p->next ){
		if(p->info.giatien==max){
			InKH(p->info);
		}
	}
}
// 18.Tính tong so tien thu duoc
void tongtien (List Q){
	Node *p;
	float tong=0;
	for(p=Q.Head;p!=NULL;p=p->next){
		tong=tong+p->info.giatien;
	}
	printf ("\n Tong so tien phong thu duoc la:%f",tong);
}
// 19.Dem so khach hang co so gio thue lon hon 3h
void dem_giolonhon3(List Q){
	Node *p;
	int dem=0;
	for (p=Q.Head; p!=NULL; p=p->next ){
		if(p->info.TG>3){
			dem=dem+1;
		}
	}
	printf (" \n So khach hang co gio thue lon hon 3 h la:%d",dem);

}
// 20.Dem so khach hang co tien phong lon hon 100.000
void dem_tienlonhon100(List Q){
	Node *p;
	int dem=0;
	for (p=Q.Head; p!=NULL; p=p->next ){
		if(p->info.giatien>100000){
			dem=dem+1;
		}
	}
	printf (" \n So khach hang co so tien phong lon hon 100.000 la:%d",dem);

}
 //..........::Ham Chinh::..............
int main (){
	List Q;
	Node *p;
	Node *q;
	int a,chon;
	khachhang x;
	khoitao(Q);
	do
	{
		system("cls");
		printf("\n ================QUAN LY KHACH SAN================\n");
		printf("\n Hay chon chuc nang:");
		printf("\n 1.Nhap danh sach khach hang");
		printf("\n 2.In danh sach khach hang ra man hinh");
		printf("\n 3.Xoa 1 khach hang bat ki theo ma khach hang");
		printf("\n 4.Chen 1 khach hang vao 1 vi tri bat ki");
		printf("\n 5.Tim kiem khach hang theo ten");
		printf("\n 6.Tim kiem theo ma phong");
		printf("\n 7.Tim kiem theo ma khach hang");
		printf("\n 8.Sap xep khach hang theo tuoi giam dan");
		printf("\n 9.Sap xep khach hang theo tien phong tang dan");
		printf("\n 10.In khach hang co tuoi nho hon 20");
		printf("\n 11.In khach hang co tien phong lon nhat");
		printf("\n 12.Tinh tong so tien thu duoc");
		printf("\n 13.Dem so khach hang co so gio thue lon hon 3");
		printf("\n 14.Dem so khach hang co so tien phong lon hon 100.000d");
		printf("\n Chon:"); scanf("%d",&chon);
		switch(chon)
		{
			case 1: system("cls");
			NhapDSKH(Q);
				break;
			case 2: system("cls");
			InDSKH(Q);
			getch();
				break;
			case 3: system("cls");  xoaK(Q); 		getch();	break;
			case 4: system("cls"); 	chengiua(Q);	getch();	break;
			case 5: system("cls");
			p=tim_ten(Q);
				if(p==NULL)
					printf("\n \tKhong tim thay khay hang");
				else
					InKH(p->info);
			getch();
			break;
			case 6: system("cls");
			p=tim_mp(Q);
				if(p==NULL)
					printf("\n \tKhong tim thay khach hang");
				else
					InKH(p->info);
			getch();
			break;
			case 7: system("cls");
			p=tim_mkh(Q);
				if(p==NULL)
			printf("\n \tKhong tim thay khach hang");
				else
			InKH(p->info);
			getch();
			break;
			case 8: system("cls"); sapxeptuoi_giamdan(Q);	getch();		break;
			case 9: system("cls"); sapxeptien_tangdan(Q);	getch();		break;
			case 10: system("cls"); KHnhohon20(Q);			getch();		break;
			case 11: system("cls"); Tienphongmax (Q);		getch();			break;
			case 12: system("cls"); tongtien (Q);			getch();			break;
			case 13: system("cls"); dem_giolonhon3(Q);		getch();		break;
			case 14: system("cls"); 	dem_tienlonhon100(Q);	getch();			break;
		}
	}
	while (chon!=0);
	return 0;
	getch ();
}

