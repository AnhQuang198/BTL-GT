#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct DaiLy
{
    char Tensach[30];
    char Theloai[20];
    int mass;
    char Tentg[20];
    int gia;
    char ngaynhap[10];
    char ngayban[10];
    char NXB[20];
    int slnhap;
    int slban;
    int namxb;

};

struct node
{
    DaiLy Data;
    node *Next;
    node *Prev;
};
struct node *Head, *Tail;

void init()
{
    Head=NULL;
    Tail-NULL;
}


node *GetNode(DaiLy x)
{
     node *p;
    p= new node ;
    if( p == NULL)
    {
        return NULL;
    }
    p->Data = x;
    p->Next=NULL;
    p->Prev=NULL;
    return p;
}


void AddHead(DaiLy x)
{
    node *p=GetNode(x);
     if(Head==NULL)
    {
        Head=p;
        Tail=Head;

    }
    else
    {

        Head->Prev=p;
          p->Next=Head;

        Head=p;
    }
}



void AddTail(DaiLy x)
{
    node *p=GetNode(x);
     if(Head==NULL)
    {
        Head=p;
        Tail=Head;

    }
    else
    {
        Tail->Next=p;
        p->Prev=Tail;
        Tail=p;
    }
}


void nhapds(DaiLy &x)
{
    fflush(stdin);
     printf("\n Nhap Ten sach: ");
     gets(x.Tensach);
     printf("\n The loai sach: ");
     gets(x.Theloai);
     fflush(stdin);
     printf("\n Ma so sach: ");
     scanf("%d",&x.mass);
     fflush(stdin);
     printf("\n Ten Tac gia: ");
     gets(x.Tentg);
     printf("\n Gia ban: ");
     scanf("%d",&x.gia);
     fflush(stdin);
     printf("\n Ngay nhap: ");
     gets(x.ngaynhap);
     printf("\n Ngay ban: ");
     gets(x.ngayban);
     printf("\n Nha xuat ban: ");
     gets(x.NXB);
     fflush(stdin);
     printf("\n So luong nhap: ");
     scanf("%d",&x.slnhap);
     printf("\n So luong ban: ");
     scanf("%d",&x.slban);
     printf("\n Nam xuat ban: ");
     scanf("%d",&x.namxb);
}


void Input()
{
    int n;
    printf("\n So sach ban dau cua Dai Ly: ");
    scanf("%d",&n);
    int i=0;
    DaiLy x;
    while(i!=n)
    {
        nhapds(x);
        AddTail(x);
        i++;
    }
}




void hiends(DaiLy &x)
{
    printf("\n------------------------------------");
        printf("\nTen sach     :  %s", x.Tensach);
        printf("\nThe loai     :  %s", x.Theloai);
        printf("\nma sach      :  %d", x.mass);
        printf("\nTac gia      :  %s", x.Tentg);
        printf("\nNha xuat ban :  %s", x.NXB);
        printf("\nGia ban      :  %d", x.gia);
        printf("\n------------------------------------");
}

void hiends2(DaiLy &x)
{
    printf("\n------------------------------------");
        printf("\nTen sach     :  %s", x.Tensach);
        printf("\nma sach      :  %d", x.mass);
        printf("\nNgay nhap    :  %s", x.ngaynhap);
        printf("\nSl nhap      :  %d", x.slnhap);
        printf("\nNha xuat ban :  %s", x.NXB);
        printf("\nNam xb       :  %d", x.namxb);
        printf("\n------------------------------------");
}

void hiends3(DaiLy &x)
{
    int dg= x.slban * x.gia;
    printf("\n------------------------------------");
        printf("\nTen sach     :  %s", x.Tensach);
        printf("\nma sach      :  %d", x.mass);
        printf("\nSl ban       :  %d", x.slban);
        printf("\nGia ban      :  %d", x.gia);
        printf("\nNgay ban     :  %s", x.ngayban);
        printf("\n Don gia     :  %d", dg);
        printf("\n------------------------------------");
}

void Output()
{
    node *p=Head;
    while(p!=NULL)
    {
        hiends(p->Data);
        p=p->Next;
    }
}

void Output2()
{
    node *p=Head;
    while(p!=NULL)
    {
        hiends2(p->Data);
        p=p->Next;
    }
}

void Output3()
{
    node *p=Head;
    while(p!=NULL)
    {
        hiends3(p->Data);
        p=p->Next;
    }
}

void giagiam()
{

   DaiLy tg;
   for(node *p=Head; p!=NULL;p=p->Next)
   {
       for(node *q=Head; q!=NULL; q=q->Next)
       {
           if(p->Data.gia>q->Data.gia)
           {
               tg = p->Data;
               p->Data = q->Data;
               q->Data = tg;
           }
       }
   }
}


void giatang()
{
    DaiLy tg;
    for(node* p= Head; p!=NULL; p=p->Next)
    {
        for(node *q = Head; q!=NULL; q=q->Next)
        {
            if(p->Data.gia<q->Data.gia)
            {
                tg=p->Data;
                p->Data=q->Data;
                q->Data=tg;
            }
        }
    }
}

int tongsach()
{
    DaiLy x;
    int dem = 0;
    for(node *p=Head; p!=NULL; p=p->Next)
    {
        if(x.Tensach[0])
            dem++;

    } return dem;
}

int tonggiaban()
{
    int x=0;
    for(node *p=Head;p!=NULL;p=p->Next)
    {
        x+=x+p->Data.gia;
    }
    return x;
}



void spmax()
{
    int max = Tail->Data.gia;
    for(node *p=Tail;p!=NULL; p=p->Prev)
    {
        if(p->Data.gia==max)
            max=p->Data.gia;
    }
    for(node *p=Head;p!=NULL;p=p->Next)
    {
        if(p->Data.gia==max)
        {
             printf("\nTen sach     :  %s", p->Data.Tensach);
             printf("\nGia ban      :  %d", p->Data.gia);
        }
    }
}

void slbanitnhat()
{
    int min = Head ->Data.slban;
    for(node *p =Head;p!=NULL;p=p->Next)
    {
        if(p->Data.slban=min)
            min = p->Data.slban;
    }
    for(node *p=Head;p!=NULL;p=p->Next)
    {
        if(p->Data.slban==min)
        {
        printf("\nTen sach     :  %s", p->Data.Tensach);
        printf("\nma sach      :  %d", p->Data.mass);
        printf("\nSl ban       :  %d", p->Data.slban);
        }

    }
}

void spcungnamsx(int namsx)
{
    for(node *p =Head;p!=NULL;p=p->Next)
    {
        if(p->Data.namxb==namsx)
        {
            printf("\nTen sach     :  %s", p->Data.Tensach);
            printf("\nNam xb       :  %d", p->Data.namxb);

        }
    }
}

char *trichTen(char *ttg)
{
    int k = strlen(ttg) - 1;
    while (k >= 0 && ttg[k] != ' ') k--;
    return (ttg + k + 1);
}

void timTheoTen(char ten[10])
{
    printf("\nNhung sach cua tg '%s':\n", ten);
    node *p = Head;
    while (p != NULL)                       //duyệt danh sách
    {
        if (strcmp(trichTen(p->Data.Tentg), ten) == 0)
             printf("\nTen sach     :  %s", p->Data.Tensach);
        p = p->Next;
    }
}



void timTheoSach(char tens[20])
{
    printf("\n Thong tin cua quyen sach '%s':\n",tens);
    node*p =Head;
    while (p!=NULL)
    {
        if(strcmp(trichTen(p->Data.Tensach),tens)==0)
        {
            printf("\nTen sach     :  %s", p->Data.Tensach);
        printf("\nThe loai     :  %s", p->Data.Theloai);
        printf("\nma sach      :  %d", p->Data.mass);
        printf("\nTac gia      :  %s", p->Data.Tentg);
        printf("\nNha xuat ban :  %s", p->Data.NXB);
        printf("\nGia ban      :  %d", p->Data.gia);
        }
       p=p->Next;

    }
}



void sach1gia(int giaban)
{
    for(node *p=Head;p!=NULL;p=p->Next)
    {
        if(p->Data.gia==giaban)
        {
            printf("\nTen sach     :  %s",p->Data.Tensach);
        }
    }
}

void gialonhonXXX(int giab)
{
    for(node *p =Head;p!=NULL;p=p->Next)
    {
        if(p->Data.gia>giab)
        {
            printf("\nTen sach     :  %s",p->Data.Tensach);
             printf("\nGia ban      :  %d", p->Data.gia);
        }
    }
}


void xoadau()
{
    Head = Head -> Next;
}


void xoacuoi()
{
    Tail->Prev=Tail;
    Tail -> Next = NULL;
}

int main()
{

   int k;
    char x[20];
    printf("\n===MENU===");
        printf("\n 1.Tao danh sach");
        printf("\n 2.Xem danh sach");
        printf("\n 3.Xem sach nhap");
        printf("\n 4.Xem sach ban");
        printf("\n 5.Sx gia giam dan");
        printf("\n 6.Sx gia tang dan");
        printf("\n 7.Tong sach");
        printf("\n 8.Tong thu nhap:");
        printf("\n 9.Gia max:");
        printf("\n 10.Sach co cung nam xb:");
        printf("\n 11.Xoa dau:");
        printf("\n 12.Xoa cuoi:");
        printf("\n 13.Sach cua tac gia:");
        printf("\n 14.Sach co cung gia ban:");
        printf("\n 15.Sach co gia lon hon 1 gia ???:");
        printf("\n 16.Sach ban duoc it nhat trong Dai ly:");
        printf("\n 17.Tim kiem thong tin sach:");
        printf("\n 20.Thoat");

    do
    {

        printf("\nBan chon:   ");
        scanf("%d",&k);
        fflush(stdin);
        switch(k)
        {
            case 1: Input();
                    break;
            case 2:
                printf("\n Thong tin sach: ");
                Output();
                    break;
            case 3:
                printf("\n Sach duoc Dai Ly nhap ve: ");
                Output2();
                break;

            case 4:
                printf("\n Sach da ban:");
                Output3();
                break;

            case 5:
                printf("\n Danh sach giam dan theo gia ban: ");
                giagiam();
                    Output();
                    break;

            case 6:
                printf("\n Danh sach tang dan theo gia ban la: ");
                giatang();
                Output();
                break;

            case 7:
                {
               int sach= tongsach();
               printf("\n Tong sach: %d",sach);
                break;
                }

            case 8:
                {
                    int sach = tonggiaban();
                    printf("\n Tong gia sach : %d",sach);
                    break;
                }

            case 9:
                {
                    spmax();
                    break;
                }

            case 10:
                {
                    int namsx;
                    printf("\n Nhap nam: ");
                    scanf("%d",&namsx);
                    spcungnamsx(namsx);
                    break;
                }

            case 11:
                {
                    xoadau();
                    Output();
                    break;
                }

            case 12:
                {
                    xoacuoi();
                    Output();
                    break;
                }

            case 13:
                {
                    char ten[20];
                    printf("\nTen tac gia: ");
                    fflush(stdin);
                    gets(ten);
                    timTheoTen(ten);
                    break;

                }

            case 14:
                {
                    int giaban;
                    printf("\n Nhap gia: ");
                    scanf("%d",&giaban);
                    sach1gia(giaban);
                    break;
                }

            case 15:
                {
                    int giab;
                    printf("\n Nhap gia:");
                    scanf("%d",&giab);
                    gialonhonXXX(giab);
                    break;
                }

            case 16:
                {
                    slbanitnhat();
                    break;
                }

            case 17:
                {
                    char tens[20];
                    printf("\n Ten sach: ");
                    fflush(stdin);
                    gets(tens);
                    timTheoSach(tens);
                    break;
                }

            case 20:break;
        }
    }      while(k != 20);
   return 0;
}
