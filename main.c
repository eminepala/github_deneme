#include <stdio.h>

int substractDays(int, int, int, int, int, int);
double calculateLateFee(int);


int main(void)
{

    int dueDay, dueMonth, dueYear;
    int returnDay, returnMonth, returnYear;
    int totalDay;
    double lateFee;

    printf("Enter due date DD MM YY: ");//Kullanicidan teslim etmesi gereken tarihi istedim.
    scanf("%d%d%d", &dueDay, &dueMonth, &dueYear);//Kullanicidan teslim etmesi gereken tarihi aldým.

    if(dueDay>31 || dueDay<01)//Gun sayisi 31'den fazla,1'den az olamayacagi için bu aralikta deger alinirsa kodun calismasini engelledim ve neden calismadigini kullaniciya acikladim.
    {
        printf("Your due date information is incorrect.");
        return 0;
    }

    if(dueMonth>12 || dueMonth<01)//Ay sayisi 12'den fazla,1'den az olamayacagi icin bu aralikta deger alinirsa kodun calismasini engelledim ve neden calismadigini kullaniciya acikladim.
    {
        printf("Your due date information is incorrect.");
        return 0;
    }


    printf("Enter return date DD MM YY: ");//Kullanicidan teslim ettigi tarihi istedim.
    scanf("%d%d%d", &returnDay, &returnMonth, &returnYear);//Kullanicidan teslim ettigi tarihi aldim.

    if(dueDay>31 || dueDay<01)//Gun sayisi 31'den fazla,1'den az olamayacagi için bu aralikta deger alinirsa kodun calismasini engelledim ve neden calismadigini kullaniciya acikladim.
    {
        printf("Your due date information is incorrect.");
        return 0;
    }

    if(dueMonth>12 || dueMonth<01)//Ay sayisi 12'den fazla,1'den az olamayacagi icin bu aralikta deger alinirsa kodun calismasini engelledim ve neden calismadigini kullaniciya acikladim.
    {
        printf("Your due date information is incorrect.");
        return 0;
    }


    totalDay = substractDays(dueDay, dueMonth, dueYear, returnDay, returnMonth, returnYear);//Toplam gec geldigi günü hesaplayan fonksiyon



    if(totalDay>=0)//Toplam gun 0 ve 0'dan buyukse
    {
        if(totalDay>0)//Toplam gun 0'dan buyukse
        {
            lateFee = calculateLateFee(totalDay);//Odemesi gereken ucreti hesapladim

            printf("You are late %d days and your late fee is %.3lf.",totalDay,lateFee);//Kac gun geciktirdigi ve ödemesi gereken ucreti acikladim.
        }
        else//Toplam gun 0'sa ürünün zamaninda teslim edildigini acikladim.
        {
            printf("You returned on the time");
        }
    }
      else//Toplam gun 0'dan kucukse kodun calismasini engelledim.
      {
          return 0;
      }
}


int substractDays(int dueDay,int dueMonth,int dueYear,int returnDay,int returnMonth,int returnYear)//Toplam gunu aciklayan fonksiyon
{
int dayDifferences,monthDifferences,yearDifferences,totalDay;

    dayDifferences = returnDay - dueDay;//Gun farki
    monthDifferences = returnMonth - dueMonth;//Ay farki
    yearDifferences = returnYear - dueYear;//Yil farki
    totalDay = yearDifferences * 365 + monthDifferences * 30 + dayDifferences * 1;//Toplam gun

        return totalDay;
}





double calculateLateFee(int totalDay)//Odenmesi gereken ucreti hesaplayan fonksiyon
{
double lateFee;




            if ( 0 < totalDay &&  totalDay <= 5)//Toplam gun 0'dan büyük,5'ten kucukse
            {
            lateFee = 10 * totalDay;//Her  bir gun icin 10 lira
            }

            else if ( 5 < totalDay &&  totalDay <= 15)//Toplam gun 5'den fazla,15 gunden azsa
            {
            lateFee = 50 + ( totalDay - 5) * 15;// Ilk 5 gun icin 50 lira,sonraki her gun icin 15 lira
            }

            else if (15 < totalDay &&  totalDay <= 30)//Toplam gun 15'den fazla,30'dan azsa
            {
            lateFee = 50 + 150 + ( totalDay- 15) * 20;// Ilk 15 gun icin 200 lira,sonraki her gun icin 20 lira
            }

            else//Toplam gun 30'dan fazlaysa
            {
            lateFee = totalDay * 20;//Her gun icin 20 lira
            }


           return lateFee;

}
