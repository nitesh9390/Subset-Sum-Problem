#include <iostream>

using namespace std;
int issum(int a[],int n,int sum)
{
    bool b[n+1][sum+1];

    for(int i=0;i<=n;i++)
    b[i][0]=true;
    for(int i=1;i<=sum;i++)
    b[0][i]=false;


    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=sum;j++)
        {
            if(a[i-1]>j)
                b[i][j]=b[i-1][j];
            else
                b[i][j]=b[i-1][j]||b[i-1][j-a[i-1]];
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<b[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    int countsum=0;
    for(int i=0;i<=n;i++)
    {
        if(b[i][sum]==1)
            countsum++;
    }
    int sub[n],x=0,y=0,z=0;
    while(x<n)
    {int j=sum,flag=0;
    z=0;
        for(int i=n-x;i>0;i--)
        {
            if(b[i][j]==1)
            {
                if(j>=a[i-1])
                {
                    sub[z++]=a[i-1];
                    j=j-a[i-1];
                }
            }
            if(j==0)
            {

                flag=1;
                break;
            }
            else if(j<0)
            {

                break;
            }

        }

            if(flag==1)
            for(int i=z-1;i>=0;i--)
            cout<<sub[i]<<" ";
        cout<<endl;
        x++;

    }



    return countsum;

}

int main()
{
    cout<<"enter size to set:";
    int n,sum;
    cin>>n;
    int a[n];
    cout<<endl<<"enter value in set:";
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<endl<<"enter value of sum:";
    cin>>sum;
    int flag=issum(a,n,sum);

    if(flag!=0)
    cout<<"\n No. of subset sum is possible:"<<flag;
    else
        cout<<"\n sum is not possible:";
}
