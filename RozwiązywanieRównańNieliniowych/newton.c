#include <stdio.h>
#include <math.h>

const double EPS0 = 0.0000000001; // dokładność porównania z zerem
const double EPSX = 0.0000000001; // dokładność wyznaczenia pierwiastka

double funkcja (double x) // funkcja
{
  return sin (x) - pow (M_E, -x);
}

double funkcja_pochodna (double x) // funkcja po obliczeniu pochodnej
{
  return cos (x) - pow (M_E, -x);
}

int main ()
{
  double x0; // punkt startowy 
  double x1; // poprzednie przybliżenie pierwiastka funkcji
  double f0; // wartość funkcji w punkcie x0 
  double f1; // wartości pierwszej pochodnej funkcji punkcie x0
  int i; // obieg pętli
  scanf("%lf",&x0);
  x1 = x0 - 1;
  f0 = funkcja(x0);
  i = 100;
  while((i>0) && fabs(x1-x0)>EPSX && fabs(f0)>EPS0)
  {
      f1 = funkcja_pochodna(x0);
      if(fabs(f1)<EPS0)
      {
          printf("Zly punkt startowy");
          i=0;
          break;
      }
      x1 = x0;
      x0 = x0-(f0/f1);
      f0 = funkcja(x0);
      if(!(--i))
      {
          printf("Przekroczony limit obiegow");
      }
  }
  if(i)
  {
      printf("%f",x0);
  }
  return 0;
}
