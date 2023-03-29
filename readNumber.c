#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//tạo kiểu dữ liệu chứa độ dài của dãy số và con trỏ mảng chứa các phần tử của dãy số
typedef struct
{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;


//chuyển đổi dãy số thành mảng 
typeArray *NumToArr(uint32_t num){

    static typeArray arr; 
    arr.size = 0;
    int index = 0;
    
    uint32_t temp = num;
    while (temp > 0)
    {
        temp = temp /10;
        arr.size++;
    } 

    arr.firstAdd = (uint8_t*)calloc(arr.size,sizeof(uint8_t));
    while (num > 0)
    {
        uint8_t temp = num % 10;
        num = num /10;
        arr.firstAdd[index]= temp;
        index++;
    }
    
    return &arr;
}

void readUnits(uint8_t num, int index, typeArray *ptr){
    switch (num)
    {
    
    case 0:                                                                                             // có 3 TH: 1. đọc không, 2. đọc lẻ, 3. không đọc
        if(index % 3 == 1 && ptr->firstAdd[index - 1] != 0){                                            // nếu số 0 ở vị trí hàng chục và số hàng đơn vị !=0 thì in ra lẻ
            printf("le_");
        }else if (index % 3 == 2 && (ptr->firstAdd[index - 1 ] != 0 || ptr->firstAdd[index - 2] != 0)) // nếu số 0 ở hàng trăm và số hàng chục hoặc hàng đơn vị =! 0 thì in ra không
        {
            printf("khong_");
        }                                                                                              //trường hợp còn lại thì không đọc
        ;
        break;

    case 1:                                                                                           // có 3 TH: 1. đọc mốt, 2. mười, 3. đọc một
        if(index % 3 == 0 && ptr->firstAdd[index + 1] != 0 && ptr->firstAdd[index + 1] != 1 ){                                         // đọc 1 nếu ở hàng đơn vị
        printf("mot'_");
        }else if (index % 3 == 1){                                                                    // đọc mười nếu ở hàng chục

            printf("muoi`_");

        }else printf("mot_");                                                                         // đọc một ở những th còn lại
            break;  

    case 2:
        printf("hai_");
            break;   

    case 3:
        printf("ba_");
            break;  

    case 4:
        printf("bon_");
            break;

    case 5:                                                                                             // có 2TH: 1.đọc lăm, 2.đọc năm
        if(index % 3 == 0 && ptr->firstAdd[index + 1] != 0 ){
        printf("lam_");    
        }else printf("nam_");
            break;                  
    case 6:
        printf("sau_");
            break;        
    case 7:
        printf("bay_");
            break;        
    case 8:
        printf("tam_");
            break;        
    case 9:
        printf("chin_");                              
        break;
    default: 
        break;
    }

}

void readDecimals(uint8_t index, typeArray *ptr){
      switch (index){
        
    case 0:
        break;

    case 1:
    case 4:
    case 7:
    case 10:
        if (ptr->firstAdd[index] != 1 && ptr->firstAdd[index] != 0 )                                            // đọc mươi nếu giá trị tại vị trí đó =! 0,1
        {
            printf("muoi_");
        }              
        break;

    case 2:
    case 5:
    case 8:
    case 11:
        if (ptr->firstAdd[index] == 0 && ptr->firstAdd[index-1] == 0 && ptr->firstAdd[index-2] == 0){          // không đọc gì nếu hàng trăm = hàng chục = hàng đơn vị = 0

        }else        printf("tram_");
        break;

    case 3:
        if(ptr->firstAdd[index] != 0 || (ptr->firstAdd[index+1] != 0 || ptr->firstAdd[index+2] != 0))          // đọc nghìn nếu: 1 trong ba vị trí trăm nghìn, chục nghìn, nghìn khác 0
        printf("nghin_");
        break;

    case 6:
        if(ptr->firstAdd[index] != 0)
        printf("trieu_");
        break;

    case 9:
        if(ptr->firstAdd[index] != 0)
        printf("ty_");        
        break;
        default: printf("ERROR!!! không xác định");
        break;
    }
}  
        


void readArr(typeArray *ptr){

    for (int index = ptr->size - 1; index >=0; index--)    {
        readUnits(ptr->firstAdd[index],index,ptr);
        readDecimals(index, ptr);
    }
}






int main(int argc, char const *argv[])
{
   typeArray *ptr = NumToArr(1061301000);

   readArr(ptr);

    return 0;
}
