#include<stdio.h>
#include<conio.h>
main()
{
    int fr[5],i,j,k,t[5],p=1,flag=0,page[25],psz,nf,t1,u[5];
    printf("Enter the number of frames:");
    scanf("%d",&nf);
    printf("\n Enter the page size");
    scanf("%d",&psz);

    printf("\nEnter the page sequence:");
    for(i=1; i<=psz; i++)
        scanf("%d",&page[i]);

    for(i=1; i<=nf; i++)
        fr[i]=-1;
    for(i=1; i<=psz; i++)
    {
        if(full(fr,nf)==1)
           break;
        else
        {
            flag=0;
            for(j=1; j<=nf; j++)
            {
               if(page[i]==fr[j])
                {
                    flag=1;
                    printf("          \t%d:\t",page[i]);
                    break;
                }
            }
            if(flag==0)
            {
                fr[p]=page[i];
                printf("          \t%d:\t",page[i]);
                p++;
            }

            for(j=1; j<=nf; j++)
                printf(" %d  ",fr[j]);
            printf("\n");
        }
    }
    p=0;
    for(; i<=psz; i++)
    {
        flag=0;
        for(j=1; j<=nf; j++)
        {
            if(page[i]==fr[j])
            {
                flag=1;
                break;
            }
        }
       if(flag==0)
        {
            p++;
            for(j=1; j<=nf; j++)
            {
                for(k=i+1; k<=psz; k++)
                {
                    if(fr[j]==page[k])
                    {
                        u[j]=k;
                        break;
                    }
                    else
                        u[j]=21;
                }
            }
            for(j=1; j<=nf; j++)
                t[j]=u[j];
            for(j=1; j<=nf; j++)
            {
                for(k=j+1; k<=nf; k++)
                {
                    if(t[j]<t[k])
                    {
                        t1=t[j];
                        t[j]=t[k];
                        t[k]=t1;
                    }
                }
            }
            for(j=1; j<=nf; j++)
            {
                if(t[1]==u[j])
                {
                    fr[j]=page[i];
                    u[j]=i;
                }
            }
            printf("Page fault\t");
        }
        else
            printf("          \t");
        printf("%d:\t",page[i]);
        for(j=1; j<=nf; j++)
            printf(" %d  ",fr[j]);
        printf("\n");
    }
    printf("\nTotal Page Faults:  %d",p+3);
// getch();
}
int full(int a[],int n)
{
    int k;
    for(k=1; k<=n; k++)
    {
        if(a[k]==-1)
            return 0;
    }
    return 1;
}