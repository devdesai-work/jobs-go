#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>


struct application
{
    char usn[25];
    char file_name[100];
    struct application *link;
};
struct application *start = NULL;

struct company
{
    char com_name[25];
    char com_file[25];
    char det[100];
    int flag;
    struct company *link;
};

struct det
{
    char bus[100];
    struct det *link;
};
typedef struct company company;
typedef struct det det;
company *beg = NULL;
det *st = NULL;

struct user
{
    int f;
    char detail[100];
    struct user *link;
};

//typedef struct application apply;
typedef struct user u;
u *first = NULL;

u *creat()
{
    u *p,*t;
    p = (struct user *)malloc(sizeof(struct user));
    if(first == NULL)
    {
        first = p;
        first->link = NULL;
    }
    else
    {
        t = first;
        while(t->link!=NULL)
            t=t->link;
        t->link = p;
        p->link = NULL;
    }
    return p;
}

void set_login()
{
     struct application *p,*t;
     p = (struct application *)malloc(sizeof(struct application));
     fflush(stdin);
     printf("\nEnter the serial no of the applicant: \n");
     gets(p->usn);
     fflush(stdin);
     printf("\nEnter the file name of applicants resume: \n");
     gets(p->file_name); 
     if(start==NULL)
     {
         start = p;
         start->link = NULL;
     }
     else
     {
         t = start;
         while (t->link!=NULL)
            t = t->link;
        t->link = p;
        p->link = NULL;
     }
     
}


void login_read()
{
    u *p;
    struct application *det;
    int i=0;
    char buff[100],name[25];
    FILE *f;
    det = start;
    fflush(stdin);
    while(det!=NULL)
    {    
        printf("\nEnter the serial number  : \n");
        gets(name);
        while(strcmp(det->usn,name)!=0)
            {
                det = det->link;
                
            }
        if(strcmp(det->usn,name)!=0)
            i =1;
        if(i==1)
            printf("\nYou have not registered");
        else
        {
            printf("Applicant Found\n");
            printf("\nReading their Details");
            for(i=0;i<5;i++)
            {
                printf(".");
                Sleep(250);
            }
            f = fopen(det->file_name,"r");
            if(f!=NULL)
            {
                while(fgets(buff,sizeof(buff),f))
                {
                    p = creat();
                    strcpy(p->detail,buff);
                }
                fclose(f);
            }
            else
                printf("\nError While opening the file");
        }
        p=creat();
        strcpy(p->detail,"--------------------");
        det = det->link;
    }
}

/*company *make()
{
    company *p,*t;
    p = (company *)malloc(sizeof(company));
    if(beg == NULL)
    {
        beg = p;
        beg->link = NULL;
    }
    else
    {
        t = beg;
        while(t->link!=NULL)
            t=t->link;
        t->link = p;
        p->link = NULL;
    }
    return p;
}*/

det *mk()
{
    det *p,*t;
    p = (det *)malloc(sizeof(det));
    if(st == NULL)
    {
        st = p;
        st->link = NULL;
    }
    else
    {
        t = st;
        while(t->link!=NULL)
            t=t->link;
        t->link = p;
        p->link = NULL;
    }
    return p;
}
void  make_company()
{
    company *p,*t;
    if(beg == NULL)
    {
        p = (company *)malloc(sizeof(company));
        strcpy(p->com_name,"Baski Co.");
        strcpy(p->com_file,"bask_file.txt");
        beg =  p;
        t=p;
        beg->link = NULL;
    }
    p = (company *)malloc(sizeof(company));
    t->link = p;
    t = p;
    strcpy(p->com_name,"Ron & Deer");
    strcpy(p->com_file,"r&d.txt");
    
    p = (company *)malloc(sizeof(company));
    t->link = p;
    t = p;
    strcpy(p->com_name,"Grim Tech.");
    strcpy(p->com_file,"gt.txt");
    
   p = (company *)malloc(sizeof(company));
    t->link = p;
    t = p;
    strcpy(p->com_name,"Zootopia Inc.");
    strcpy(p->com_file,"zi.txt");
    
    p = (company *)malloc(sizeof(company));
    t->link = p;
    t = p;
    strcpy(p->com_name,"Kickass Company");
    strcpy(p->com_file,"kc.txt");
    t->link = NULL;
}

void display()
{
    u *p;
    p = first;
    while(p!=NULL)
    {
        puts(p->detail);
        p=p->link;
    }
}

void com_dis()
{
    company *p;
    p = beg;
    while(p!=NULL)
    {
        puts(p->com_name);
        p=p->link;
    }
}
void read_comp(char s[])
{
    FILE *fp;
    company *p;
    det *k;
    char buff[150];
    p = beg;
    while(strcmp(p->com_name,s)!=0)
        p=p->link;
    fp = fopen(p->com_file,"r");
    if(fp!=NULL)
    {
        while(fgets(buff,sizeof(buff),fp))
        {
            k = mk();
            strcpy(k->bus,buff);
        }
        fclose(fp);
    }
    else
        printf("\nError While opening the file");
    

}
struct package
{
    char info[100];
    struct package *link;
};
typedef struct package pack;
pack *this=NULL;

struct selected 
{
    char com[100];
    char name[100];
    struct selected *link;
};
typedef struct selected giv;
giv *lo=NULL;

void comp()
{
    company *p;
    det *t;
    pack *l,*temp;
    giv *x,*h;
    char name[100];
    char co[100]="";
    int c_marks_10,c_marks_12,u_marks_10,u_marks_12;
    float c_cgpa,u_cgpa;
    u *u;
    u = first;
    p = beg;
    while(u!=NULL)
    {
        strcpy(name,u->detail);
        u=u->link;
        u=u->link;
        sscanf(u->detail,"%d",&u_marks_10);        
        u=u->link;
        sscanf(u->detail,"%d",&u_marks_12);
        u=u->link;
        sscanf(u->detail,"%f",&u_cgpa);
        u=u->link;
        //printf("%d %d %f",u_marks_10,u_marks_12,u_cgpa);
        p=beg;
        strcpy(co,"");
        while(p!=NULL)
        {
            read_comp(p->com_name);
            t = st;
           
            t=t->link;
            l = (pack *)malloc(sizeof(pack));
            if(this==NULL)
            {
                this = l;
                l->link = NULL;
                strcpy(l->info,t->bus);
            }
            else
            {
                temp = this;
                while(temp->link!=NULL)
                    temp=temp->link;
                temp->link = l;
                strcpy(l->info,t->bus);
                temp=temp->link;
                temp->link=NULL;
            }
            
            t=t->link;
            sscanf(t->bus,"%d",&c_marks_10);       
            t=t->link;
            sscanf(t->bus,"%d",&c_marks_12);
            t=t->link;
            sscanf(t->bus,"%f",&c_cgpa);
            //printf("%d %d %f",c_marks_10,c_marks_12,c_cgpa);
            if((u_marks_10>=c_marks_10)&&(u_marks_12>=c_marks_12)&&(u_cgpa>=c_cgpa))
                {
                    h = (giv *)malloc(sizeof(giv));
                    if(lo == NULL)
                    {
                       lo = h;
                       lo=lo->link;
                    }
                    else
                    {
                        x = h;
                        while(x->link!=NULL)
                            x = x->link;
                        x->link = h;
                        x=x->link;
                        x->link = NULL;
                    }
                    strcat(co,p->com_name);
                    strcat(co," |#| ");
                }
            
            
            p=p->link;
            st = NULL;
        }

        printf("%s is elligible for",name);printf("\t");
        puts(co);
       /* h = (giv *)malloc(sizeof(giv));
        strcpy(h->name,name);
        strcpy(h->com,co);
        if(lo == NULL)
        {
             lo = h;
             lo=lo->link;
        }
        else
        {
            x = lo;
            while(x->link!=NULL)
             x = x->link;
            x->link = h;
            x=x->link;
            x->link = NULL;
        }*/
        st=NULL;
        u = u->link;
    }

}

void just_call()
{
    det *k;
    k = st;
    while(k!=NULL)
    {
        puts(k->bus);
        k=k->link;
    }
}

void dis_elli()
{
    giv *p;
    p = lo;
    printf("The companies elligible are: ");
    while(p!=NULL)
    {
        puts(p->name);
        puts(p->com);
        printf("#################");
        p=p->link;
    }
    
}

int compare(char detail[],char name[])
{
    char d[100],na[100];
    int i;
    strcpy(d,detail);
    strcpy(na,name);
    for(i=0;d[i] && na[i];++i)
    {
        if(d[i] == na[i] || (d[i] ^ 32) == na[i])
            continue;
        else
            break;
    }

    if(d[i]==na[i])
        return 0;
    if((d[i] | 32)<(na[i] | 32))
        return -1;
    return 1;


}
struct h
{
    char king[100];
    struct h *link;
};
typedef struct h pip;
pip *rod=NULL;
void call(int o)
{
    pip *y;
    u *details,*temp,*f,*v;
    char name[100],d[50];
    int a;
    while(o)
            {            

                printf("\n1.Change the applicnat data. \n2.Delete applicant data \n3.Do Nothing");
                scanf("%d",&a);
                if(a==1)
                {
                    printf("\nEnter the Name of the applicant whoes details you want to change: \n");
                    fflush(stdin);
                    gets(name);
                    details = first;
                    while(details->link!=NULL)
                    {
                        if(strcmp(details->detail,name)==0)
                            break;
                        details=details->link;
                    }
                    printf("\nEnter the details you want to change \n1.USN \n2.10th marks \n3.12th marks \n4.Cumilative CGPA");
                    scanf("\n%d",&o);
                    if(o==1)
                    {
                        y = (pip *)malloc(sizeof(pip));
                        details = details->link;
                        printf("Enter the Changed USN");
                        fflush(stdin);
                        gets(d);
                        strcpy(y->king,d);
                        free(details->detail);
                        strcpy(details->detail,y->king);
                        printf("\nHH");
                    }
                    else if(o==2)
                    {
                        details = details->link;
                        details = details->link;
                        printf("Enter the Changed 10th marks");
                        gets(d);
                        strcpy(details->detail,d);
                        
                    }
                   else  if (o==3)
                    {
                        details = details->link;
                        details = details->link;
                        details = details->link;
                        printf("Enter the Changed 12th marks");
                        gets(d);
                        strcpy(details->detail,d);
                    }
                    else if (o==4)
                    {
                        details = details->link;
                        details = details->link;
                        details = details->link;
                        details = details->link;
                        printf("Enter the Changed cummilative CGPA");
                        gets(d);
                        strncpy(details->detail,d,sizeof(d));
                    }
                    else
                        printf("Invalid Input");
                    
                    
                }
                else if(a==2)
                {
                    printf("Enter the name of the student whoes data you want to delete");
                    fflush(stdin);
                    gets(name);
                    details = first;
                    while(strcmp(details->detail,name)!=0)
                    {
                        temp = details;
                        details=details->link;
                    }
                    f = details;
                    details = details->link;
                    free(f);
                    f=details;
                    details = details->link;
                    free(f);
                    f=details;
                    details = details->link;
                    free(f);
                    f=details;
                    details = details->link;
                    free(f);
                    f = details;
                    details = details->link;
                    free(f);
                    temp->link = details;

                }
                else if(a==3)
                    o=0;

                else
                {
                    printf("Wrong input");
                
                     printf("Do you want to continue formatting the applicant  data? \n1.Yes \n0.N0");
                    scanf("%d",&o);
                }
                printf("Do you want to continue? \n1.Yes \n0.No");
                scanf("%d",&o);
            }
}


int main()
{
     u *details,*temp,*f,*v;
     int w;
     char pipe[150],name[100];
     char *d = 0;
     struct application *user;
     int ch, i,k=1,o=1,a;
     FILE *fp;
     fp = fopen("struct.txt","r");
     printf("-------------------------------------------------JOBS GO----------------------------------------------------");
     printf("\nThe Company Data and the User Details should be in the below format.\n");
     while(fgets(pipe,sizeof(pipe),fp))
        fputs(pipe,stdout);
     make_company();
     //com_dis();
     while(k)
     {
        printf("\n1.New Applicant \n2.Existing Applicant\n");
        scanf("%d",&ch);
        if(ch == 1)
            set_login();
        else if(ch == 2)
        {
            login_read();
            printf("\nDo you want to see the data of all the applicants? \n1.Yes \n0.NO\n");
            scanf("%d",&i);
            if(i)
                  display();
            //call(o);
            comp();
            //dis_elli();
            //just_call();
        }
        printf("\nDo You want to continue ?\n 1.Yes \n 0.No ");
        scanf("%d",&k);
     }
     printf("All well!!");
     return 0;
}
