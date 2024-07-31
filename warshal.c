#include<stdio.h>
void warsh(int p[][10],int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    p[i][j]=p[i][j]||p[i][j]&&p[k][j];
}
int main()
{
    int a[10][10],n,i,j;
    printf("\nenter the n value:");
    scanf("%d",&n);
    printf("\n enter the grap data:\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    warsh(a,n);
    printf("\n resultant path matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        printf("%d",a[i][j]);
        printf("\n");

    }

    return 0;

}