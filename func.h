#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
int x2(int *A,int time)
{
    int i,sum=0,j;
    for(i=0; i<time; i++)
    {
        j=pow(2,time-1-i);
        sum+=(A[i]*j);
    }
    return sum;
}
void ano(int *A,int c)
{
    A[c]=(A[c]+1)%2;
}


#endif // FUNC_H_INCLUDED
