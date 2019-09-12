#include <stdio.h>
#define NUM 2000
int main(int argc, char* argv[])
{
    signed long pow[NUM],val[NUM],x,num,ten;
    int i,j,count;
    for(num=2; num<NUM; num++)
    {
        for(i=0; i<NUM; pow[i++]=0);
        count=0;
        for(ten=9,x=1; x<NUM; x++)
        {
            val[x]=ten;

            for(j=0; j<NUM; j++)if(pow[j]&&!pow[(j+ten)%num]&&pow[j]!=x)pow[(j+ten)%num]=x;
            if(!pow[ten])pow[ten]=x;
            ten=(10*ten)%num;
            if(pow[0])break;
        }

        x=num;
        printf("%ld\tdivides\t",x=num);
        if(pow[0])
        {
            while(x)
            {
                while(--count>pow[x%num]-1)printf("0");
                count=pow[x%num]-1;
                printf("9");
                x=(num+x-val[pow[x%num]])%num;
            }
            while(count-->0)printf("0");
        }
        printf("\n");
    }
}
