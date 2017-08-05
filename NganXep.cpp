#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

struct KS{
    char MKH[20];
    char GT[20];
    char HT[20];
    int Tuoi;
    char MP[20];
    float TG,GTien;
};

struct Node{
    KS infor;
    struct Node*Next;
};

struct list{
    Node*Top;
};
list S;

void init(list &S)
{
    S.Top = NULL;
}

void push(list &S, KS x)
{
    Node *p;
    p = (Node*)calloc(1,sizeof(Node));
    if(p == NULL)
    {
        printf("\n ko du bo nho");
        exit(1);
    }
    p->infor = x;
    p->Next = S.Top;
    S.Top = p;
}

void nhapfile(list S)
{
    FILE *f;
    f=fopen("KS.dat","wb");
    Node *p=S.Top;
    while(p!=NULL)
    {
        fwrite(&p->infor,sizeof(p->infor),1,f);
        p=p->Next;
    }
    fclose(f);
}

void chen(list &S, KS x)
{
    int n;
	printf("\n Nhap so khach hang: ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("\n Nhap khach hang thu %d",i);
		printf("\n Nhap ten khach hang: ");fflush(stdin);
        gets(x.HT);
        printf("\n Nhap gioi tinh: ");
        gets(x.GT);
        printf("\n Nhap tuoi: ");
        scanf("%d",&x.Tuoi);
        printf("\n Nhap ma khach hang: ");fflush(stdin);
        gets(x.MKH);
        printf("\n Nhap ma phong: ");
        fflush(stdin);gets(x.MP);
        printf("\n Nhap thoi gian thue phong: ");
        scanf("%f",&x.TG);
        x.GTien=x.TG*50000;
        printf("\n -------------------------");
        push(S,x);
	}
}

void hien(list S)
{
    Node *p;
    p = S.Top;
    printf("  Ho ten  Gioi tinh  Tuoi  Ma phong   MKH  Thoi gian  Gia tien");
    while(p!=NULL)
    {
        printf("\n %7s %7s %5d %7s %10s %5.0f %10.0f ",p->infor.HT,p->infor.GT,p->infor.Tuoi,p->infor.MP,p->infor.MKH,p->infor.TG,p->infor.GTien);
        p=p->Next;
    }
}

void docfile(list &S)
{

    KS x;
    FILE *f;
    f=fopen("KS.dat","rb");
    fread(&x,sizeof(x),1,f);
	while(!feof(f))
    {
        push(S,x);
        fread(&x,sizeof(x),1,f);
    }
       fclose(f);
 	printf("\n---------------------------\n");
}

void timkiem(list S,KS x)
{
	Node *p=S.Top;
	char a[30],b[20],c[20];
	int k;
	printf("\n1.Tim kiem theo ten");
    printf("\n2.Tim kiem theo ma phong");
    printf("\n3.Tim kiem theo ma khach hang");
    printf("\n Nhap dieu kien tim kiem: ");
    scanf("%d",&k);
    switch(k)
    {
    	case 1:
    		printf("\n Nhap ten khach hang can tim:");
            fflush(stdin);
            gets(a);
			break;
		case 2:
			printf("\n Nhap ma phong can tim: ");
			fflush(stdin);
            gets(b);
			break;
        case 3:
			printf("\n Nhap ma khach hang can tim: ");
			fflush(stdin);
            gets(c);
			break;
		default: printf("\n Vui long nhap lai");
    }
    while (p!=NULL)
    {
    	if(strcmp(p->infor.HT,a)==0)
    	{
    		printf("  Ho ten  Gioi tinh  Tuoi  Ma phong   MKH  Thoi gian  Gia tien");
			printf("\n %7s %7s %5d %7s %10s %5.0f %10.0f ",p->infor.HT,p->infor.GT,p->infor.Tuoi,p->infor.MP,p->infor.MKH,p->infor.TG,p->infor.GTien);
    	}
    	if(strcmp(p->infor.MP,b)==0)
    	{
    		printf("  Ho ten  Gioi tinh  Tuoi  Ma phong   MKH  Thoi gian  Gia tien");
			printf("\n %7s %7s %5d %7s %10s %5.0f %10.0f ",p->infor.HT,p->infor.GT,p->infor.Tuoi,p->infor.MP,p->infor.MKH,p->infor.TG,p->infor.GTien);
    	}
    	if(strcmp(p->infor.MKH,c)==0)
    	{
    		printf("  Ho ten  Gioi tinh  Tuoi  Ma phong   MKH  Thoi gian  Gia tien");
			printf("\n %7s %7s %5d %7s %10s %5.0f %10.0f ",p->infor.HT,p->infor.GT,p->infor.Tuoi,p->infor.MP,p->infor.MKH,p->infor.TG,p->infor.GTien);
    	}
    	p=p->Next;
    }
	printf("\n--------------------------\n");
}

void hoanvi(Node *p, Node *q)
{
    KS x;
    x=p->infor;
    p->infor=q->infor;
    q->infor=x;
}

void sapxep(list S)
{

	int a;
	char r[30],t[30];
	printf("\n 1.Sap xep theo tuoi:");
	printf("\n 2.Sap xep theo tien phong:");
	printf("\n Nhap dieu kien sap xep: ");
	scanf("%d",&a);
	Node *p=S.Top;
    while(p!=NULL)
    {
        Node *q=p->Next;
        while(q!=NULL)
        {
        	if(a==1)
        	{
            	if(p->infor.Tuoi<q->infor.Tuoi)
                    hoanvi(p,q);
        	}
        	if(a==2)
        	{
            	if(p->infor.GTien>q->infor.GTien)
                    hoanvi(p,q);
        	}
        	q=q->Next;
    	}
    	p=p->Next;
    }
	printf("\n Danh sach sau khi duoc sap xep: \n");
	nhapfile(S);
	hien(S);
	printf("\n------------------------\n");
}

void pop(list &S, KS x)
{
	Node *p;
	if(S.Top==NULL)
	{
		printf("\n Danh sach rong");
		exit(1);
	}
	else
	{
		x=S.Top->infor;
		S.Top=S.Top->Next;
	}
}

void huy(list &S,KS x)
{
	Node *p;
	p=S.Top;
	char a[5];
	printf("\n Nhap Ma khach hang muon xoa ");
	scanf("%s",&a);
	while(p!=NULL)
	{
		if(strcmp(a,p->infor.MKH)==0)
		{
			pop(S,x);
			push(S,x);
		}
		p=p->Next;
	}
}

void menu()
{
    printf("\n ---------------------------");
    printf("\n ..::QUAN LY KHACH SAN::..");
    printf("\n \t Menu");
    printf("\n 1.Nhap thong tin khach hang");
    printf("\n 2.Hien thong tin khach hang");
    printf("\n 3.Xoa 1 khach hang theo ma khach hang");
    printf("\n 4.Doc danh sach tu file");
    printf("\n 5.Sap xep danh sach");
    printf("\n 6.Tim kiem trong danh sach");
    printf("\n Nhan 0 de thoat");
    printf("\n ---------------------------");
}

int main()
{
    int n;
    KS x;
    list S;
    init(S);
    while(n!=0)
    {
        menu();
        printf("\n Chon chuc nang: ");
        scanf("%d",&n);
    switch(n)
        {
        case 1:
            chen(S,x);
            nhapfile(S);
            break;
        case 2:
            hien(S);
            break;
        case 3:
            huy(S,x);
            nhapfile(S);
            hien(S);
            break;
        case 4:
            docfile(S);
            hien(S);
            break;
        case 5:
            sapxep(S);
            nhapfile(S);
            break;
        case 6:
            timkiem(S,x);
            break;
        }
    }
}


