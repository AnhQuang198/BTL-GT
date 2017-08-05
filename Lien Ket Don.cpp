#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct KS
{
    char MKH[20];
    char HT[25];
    char GT[10];
    int Tuoi;
    char MP[10];
    float TG,GTien;
};

struct Node
{
    KS Infor;
    struct Node *Next;
};

struct list
{
    Node*Head;
    Node*Tail;
};

void khoitao(list &Q)
{
    Q.Head = NULL;
    Q.Tail = NULL;
}

Node *getNode(KS x)
{
    Node *p;
    p = new Node;
    if(p == NULL)
    {
        printf("\n Cap phat ko thanh cong");
        exit(1);
    }
    p->Infor = x;
    p->Next = NULL;
    return p;
}

void chencuoi(list &Q, Node *p)
{
    if(Q.Head == NULL)
    {
        Q.Head = p;
        Q.Tail = p;
    }
    else
    {
        Q.Tail ->Next=p;
        Q.Tail = p;
    }
}

void nhap(KS &x)
{
    printf("\n Nhap Ho ten:");fflush(stdin);
    gets(x.HT);
    printf(" Nhap tuoi:");
    scanf("%d",&x.Tuoi);
    printf(" Nhap ma khach hang: ");fflush(stdin);
    gets(x.MKH);
    printf(" Nhap gioi tinh:");fflush(stdin);
    gets(x.GT);
    printf(" Nhap thoi gian thue phong:");fflush(stdin);
    scanf("%f",&x.TG);
    printf(" Nhap ma phong:");fflush(stdin);
    gets(x.MP);
    x.GTien = x.TG*50000;
}

void inds(KS x)
{
    printf("\n %15s",x.HT);
    printf("%7s",x.GT);
    printf("%5d",x.Tuoi);
    printf("%7.0f",x.TG);
    printf("%5s",x.MP);
    printf("%7s",x.MKH);
    printf("%15.0f",x.GTien);
}

void nhapdskh(list &Q)
{
    Node *p;
    int n,i;
    KS x;
    printf("\n Nhap so khach thue phong:");scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        nhap(x);
        p=getNode(x);
        chencuoi(Q,p);
    }
}

void indskh(list Q)
{
    Node *p;
    for(p=Q.Head;p!=NULL;p=p->Next)
        inds(p->Infor);
}

void chenvitribatky(list &Q){
	Node *p, *q;
	KS x;
	char a[10];
	printf("\n \n Chen 1 vao sau 1 khach hang co ma la:"); fflush(stdin); gets(a);
	for(p=Q.Head;p!=NULL;p=p->Next){
		if(strcmp(p->Infor.MKH,a)==0){
			printf ("\n Nhap thong tin khach hang can chen:");
			nhap(x);
			q=getNode(x);
			q->Next=p->Next;
			p->Next=q;
			if(p==Q.Tail)
				Q.Tail=q;
			break;
		}
	}
		indskh(Q);
}

void xoadau(list &Q)
{
    Node *p;
    if(Q.Head != NULL)
    {
        p = Q.Head;
        Q.Head = Q.Head->Next;
        delete p;
        if(Q.Head == NULL)
            Q.Tail = NULL;
    }
}


void sxdsachtuoigiam(list &Q)
{
    Node *p,*q;
    KS tg;
    for(p=Q.Head;p!=NULL;p=p->Next)
        for(q=p->Next;q!=NULL;q=q->Next)
            if(p->Infor.Tuoi < q->Infor.Tuoi)
            {
                tg = p->Infor;
                p->Infor = q->Infor;
                q->Infor = tg;
            }
}

void khcotienphongcaonhat(list Q)
{
    Node *p;
    float a;
    a = Q.Head ->Infor.GTien;
    for(p=Q.Head;p!=NULL;p=p->Next)
        if(p->Infor.GTien==a)
            a=p->Infor.GTien;
    printf("\n Khach hang co so tien phong cao nhat la:");
    for(p=Q.Head;p!=NULL;p=p->Next)
        if(p->Infor.GTien == a)
            printf("%15s",p->Infor.HT);
}

Node *TimMaPhong(list Q, char x[20])
{
    Node *p;
    for(p=Q.Head;p!=NULL;p=p->Next)
        if(strcmp(p->Infor.MP,x) == 0)
            break;
    return p;
}
void tongtien(list Q)
{
    Node *p;
    float s=0;
    for(p=Q.Head;p!=NULL;p=p->Next)
        s=s+p->Infor.GTien;
    printf("\n Tong so tien phong thu duoc: %10.0f",s);
}
int main()
{
    list Q;
    Node *p,*q;
    char mp[10];
    khoitao(Q);
    nhapdskh(Q);
    printf("\n Danh sach khach hang da nhap:");
    indskh(Q);
    printf("\n Nhap ma phong can tim:");
    gets(mp);
    p = TimMaPhong(Q,mp);
    if(p == NULL)
        printf("\n ko tim thay");
    else
        printf("\n co tim thay");
    tongtien(Q);
    sxdsachtuoigiam(Q);
    printf("\n Danh sach khach hang sau khi sap xep:");
    indskh(Q);
    khcotienphongcaonhat(Q);
    printf("\n Danh sach sau khi chen:");
    chenvitribatky(Q);
    getch();
}
