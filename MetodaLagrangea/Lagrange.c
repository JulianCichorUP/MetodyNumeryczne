#include <stdio.h>

int main()
{
    double x[1000], y[1000], wyniki[1000];
    int ilosc;
    scanf("%d",&ilosc);
    int argument;
    double wynik=0;
    scanf("%d",&argument);
    for(int i=0;i<ilosc;i++)
    {
        printf("x%d:",i+1);
        scanf("%lf",&x[i]);
        printf("y%d:",i+1); 
        scanf("%lf",&y[i]);
        wyniki[i] = y[i];
        for(int j=0;j<ilosc;j++)
        {
            if(x[i]!=x[j])
            {
                wyniki[i] *= 1.000*((argument-x[j])/(x[i]-x[j]));
            }
        }
        if(i!=0)
        {
            wynik += (1.000*wyniki[i]);
        }
    }
    printf("%lf",wynik);
    return 0;
}
