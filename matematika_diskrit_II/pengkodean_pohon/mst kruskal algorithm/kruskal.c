#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main() {
 int vertex, i, j, awal, kecil=999, v=0;

 printf("Masukkan jumlah vertex : ");
 scanf("%d", &vertex);
 int titik[vertex][vertex];
 int uji[vertex];
 
 for(i=1;i<=vertex;i++) {
    for(j=i;j<=vertex;j++) {
   if(i==j)
   {
    titik[i][j]=0;
   }
   else
   {
    printf("\n Bobot [%d-%d] : ",i,j);
    scanf("%d",&titik[i][j]);
    titik[j][i] = titik[i][j];
   }
  }
 }
 printf("\nBentuk dalam Matriks : \n");
    for (i=1;i<=vertex;i++)
    {
        printf("\n");
        for (j=1;j<=vertex;j++)
            printf("%d\t",titik[i][j]);
    }
 
 for(i=1;i<=vertex;i++)
 {
  for(j=i;j<=vertex;j++)
  {
   if(titik[i][j]<kecil&&titik[i][j]!=0)
   {
    kecil = titik[i][j];
   }
  }
 }
 awal = kecil;
 
 int batas=0, min=0, a, b, bobot=0;
 for(i=1;i<=vertex;i++)
 {
  uji[i]=999;
 }
 
 printf("\n\n");
 printf("Hasil : \n");
 uji[awal]=awal;
 while(1)
 {
  min=999;
  for(i=1;i<=vertex;i++)
  {
  if(uji[i]==i)
   {
    for(j=1;j<=vertex;j++)
    {
     if(titik[i][j]<min && titik[i][j]!=0)
     {
     min = titik[i][j];
     a=i;
     b=j;
     }
    } 
   }
  }
  titik[a][b]=0;
  titik[b][a]=0;
  
  int sama=0;
  for(i=1;i<=vertex;i++)
  {
   if(uji[i]==b)
   {
    sama++;
   }
    
  }
 
  if (sama==0)
  {
   printf("%d - %d : %d\n",a,b,min);
   bobot+=min;
   uji[b]=b;
   v++;
   
  }
  if(v == vertex-1)
  {
   break;
  }
  batas++;
 }
 
 printf("Total : %d", bobot);
}