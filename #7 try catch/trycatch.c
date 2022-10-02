#include <stdio.h>
#include<setjmp.h>
#include<stdint.h>

#define TRY if((value = setjmp(buf)) == 0)
#define CATCH(num) else if(value == num)
#define THROW(num) longjmp(buf,num)
#define CATCHALL else

// #define bool unsigned char
// #define true 1
// #define false 0

// bool equal(char arr1 , char arr2)
// {
//     if(arr1 == arr2)
//     {
//         return true;
//         }
    
//     else{
//         return false;
//     }
// }

jmp_buf buf;
int value = 0;
int size;
int i=0;
int j=0;
int arr1[] = {1,2,3,4,5};
int arr2[] = {1,2,3,4,5};
int compare();




// void sosanh()
// {
//     // TRY;
//     // int arr1[] = {1,2,3,4,5};
//     // int arr2[] = {1,2,3,4,5};
//     // compare(arr1,arr2);



// }

    //printf("i=%d\n", i-1);
    //return 0;

void main()
{
    TRY
    {
    
    compare(arr1,arr2);
    }
    CATCH(1)
    {
        printf("2 mang bang nhau\n");

    }
    CATCH(2)
    {
       printf("2 mang khong bang nhau\n");

    }
    CATCH(3)
    {
        printf("2 mang khong cung size\n");
    }
    printf("%d\n",arr1);

}

int compare(int arr1[],int arr2[])
{
    //int arr[5];

    
    while(arr1[i] != 0)
    {
        i++;
    }
     while(arr2[j] != 0)
    {
        j++;
    }
    if(i == j)
    {
        size = i;
        printf("aaa:%d",size) ;
        for (int i = 0; i<= size; i++) 
        {
            for (int j = 0; j<= size; j++) 
            {
                if (arr1[i] != arr2[j]) 
                    {
                        THROW(2);
    
                    }
                else
                THROW(1);
                
                       
            }
        }



    }
     if(i!=j)
    {
        THROW(3);
    }
    
    //for (size_t i = 0; i < size1; ++i) {
    //    if (arr1[i] != arr2[i])  return flag = 0; 
       
    }



