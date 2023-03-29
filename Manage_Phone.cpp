#include <conio.h>
#include <string.h>
#include <stdint.h>
#include <vector>
#include <stdio.h>

#define TRUE 1
#define FALSE 0


class Phone{

    private:
    uint8_t ID;
    char namePhone[20];
    char manufacturer[20];
    double phonePrice;

    public:

    Phone(const char temp_namePhone[], const char temp_manufacturer[], double temp_phonePrice);

    uint8_t getID();
    const char* getNamePhone() const;
    const char* getManufacturer() const;
    double getPhonePrice() const;

    void setPhoneName(const char namePhone[]);
    void setManufacturer(const char manufacturer[]);
    void setPhonePrice(double phonePrice);
    
};

//---------------//
Phone::Phone(const char temp_namePhone[], const char temp_manufacturer[], double temp_phonePrice){

    static uint8_t temp_ID = 100;
    Phone::ID = temp_ID;
    temp_ID++;
    strcpy(Phone::namePhone, temp_namePhone);
    strcpy(Phone::manufacturer, temp_manufacturer);
    Phone::phonePrice = temp_phonePrice;
    
}

uint8_t Phone::getID(){
    return this->ID;
}

const char* Phone::getNamePhone() const{
    return namePhone;
}

const char* Phone::getManufacturer() const{
    return manufacturer;
}

double Phone::getPhonePrice() const{
    return phonePrice;
}

//---------------//
void Phone::setPhoneName(const char temp_namePhone[]){
    strcpy(Phone::namePhone, temp_namePhone);

}

void Phone::setManufacturer(const char temp_manufacturer[]){
    strcpy(Phone::manufacturer, temp_manufacturer);
}

void Phone::setPhonePrice(double temp_phonePrice){
    Phone::phonePrice = temp_phonePrice;
}

class ManagePhone{

    private:
        enum option{
            ADD = 1,
            DEL,
            EDIT,
            SHOW,
        }option;

        std::vector<Phone> dataBase;

    public:
        ManagePhone();
        void addPhone();
        void delPhone();
        void editPhone();
        void showPhone();


};

ManagePhone::ManagePhone(){

    int run = TRUE;
    
    while (run){

        int choice;
        printf("\n---------------------MENU-------------------\n");
        printf("1. Add Phone\n");
        printf("2. Delete Phone\n");
        printf("3. Edit Phone\n");
        printf("4. Show List of Phone\n");
        printf("Please enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice){

        case ADD:
            printf("---------Add---------\n");
            addPhone();
            break;

        case DEL:
            printf("---------Delete---------\n");
            delPhone();
            break;

        case EDIT:
            printf("---------Edit-----------\n");
            editPhone();
            break;

        case SHOW:
            printf("---------Show---------\n");
            showPhone();
            break;

        default:
            printf("Your choice: %d", choice);
            printf("Invalid input, please try again.\n");
            continue;
        }

    }
    
}

void ManagePhone::addPhone(){

    char temp_namePhone[20];
    char temp_manufacturer[20];
    double temp_phonePrice;
    char key;
    
    do{

    printf("Enter name phone\n");
    scanf("%s",temp_namePhone);

    printf("Enter manufacturer\n");
    scanf("%s", temp_manufacturer);

    printf("Enter phone price\n");
    scanf("%lf",&temp_phonePrice);


    Phone addphone(temp_namePhone, temp_manufacturer, temp_phonePrice);

    dataBase.push_back(addphone);

    printf("Do you want to add another phone? (y/n): \n");
    scanf(" %c",&key);

    }while (key == 'y');
  
}

void ManagePhone::delPhone(){

    char key;
    bool check = FALSE;
    
    do{
        int id_delPhone;
        printf("Enter ID \n");
        scanf("%d",&id_delPhone);

        for(int i=0; i < dataBase.size(); i++){
            if(id_delPhone == dataBase[i].getID()){
                dataBase.erase(dataBase.begin() + i);
                check = TRUE;
            }
        }
        if (check == FALSE) printf("ERROR!!! ID false\n");
        printf("Do you want to delete another phone? (y/n): \n");
        scanf(" %c",&key);
    }while (key == 'y');
    

}

void ManagePhone::editPhone(){

    int id_edit;
    char exit;
    printf("Enter ID edit\n");
    scanf(" %d", &id_edit);


    do{
        for(int i=0; i < dataBase.size(); i++){
            if(id_edit == dataBase[i].getID()){
                printf("Number 1: Edit name phone\n");
                printf("Number 2: Edit manufacturer\n");
                printf("Number 3: Edit phone price\n");
                printf("Number 4: Edit all\n");

                int key;
                scanf(" %d", &key);

                switch (key)
                {
                case 1:
                    char temp_phoneName[20];
                    printf("New name is:\n");
                    scanf(" %s", temp_phoneName);
                    dataBase[i].setPhoneName(temp_phoneName);
                    break;
                
                case 2:
                    char temp_manufacturer[20];
                    printf("New manufacturer is:\n");
                    scanf(" %s", temp_manufacturer);
                    dataBase[i].setManufacturer(temp_manufacturer);
                    break;

                case 3:
                    double temp_phonePrice;
                    printf("New price is:\n");
                    scanf(" %lf", &temp_phonePrice);
                    dataBase[i].setPhonePrice(temp_phonePrice);
                    break;

                case 4:
                    printf("New name is:\n");
                    scanf(" %s", temp_phoneName);
                    dataBase[i].setPhoneName(temp_phoneName);

                    printf("New manufacturer is:\n");
                    scanf(" %s", temp_manufacturer);
                    dataBase[i].setManufacturer(temp_manufacturer);    

                    printf("New price is:\n");
                    scanf(" %lf", &temp_phonePrice);
                    dataBase[i].setPhonePrice(temp_phonePrice);            
                
                default:
                    printf("ERROR!!! Enter fail, enter again\n");
                    continue;
                }


            }
        }

        printf("Do you want select another(y/n)\n");
        scanf(" %c",&exit);

    }while(exit == 'y');     
}


void ManagePhone::showPhone(){

    
    char key_exit;    
    
    if(dataBase.empty()==1){
        printf("Emty list!!!\n");
    }else{
        for(int i=0; i < dataBase.size(); i++){
            printf("%d %s %s %lf\n", dataBase[i].getID(), dataBase[i].getNamePhone(), dataBase[i].getManufacturer(), dataBase[i].getPhonePrice());
        }
    }
    printf("Press any key to exit..\n");
    scanf(" %c",&key_exit);
    
}


int main(int argc, char const *argv[])
{
    ManagePhone mn;
}
