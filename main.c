#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int choice;

typedef struct Contacts{
    char Name[100];
    int Contact_No;
    struct Contacts *NextContact;
}Contact;

typedef struct ContactList{
    int count;
    struct Contacts *Head;
}*ContactList;

void Menu(ContactList ContList);
void Contacts(ContactList ContList);
void Messages();
void Add_Contact(ContactList ContList,char Name[],int Cont_No);
void Update_Contact(ContactList ContList);
void Display_Contact(ContactList ContList);
void Delete_Contact(ContactList ContList);
void Search_Contact(ContactList ContList);
void Compose_Message();
void Display_Message();
void Delete_Message();
void SaveFile_Contact(ContactList ContList);

Contact *End;
int main(){
    ContactList ContList;
    ContList->count=0;
    ContList->Head=NULL;
    Menu(ContList);
    return 0;
}
void Menu(ContactList ContList){
    printf("=====Menu=====\n");
    printf("   1.Contacts\n");
    printf("   2.Messages\n");
    printf("   3.Exit\n");
    scanf("%d",&choice);
    if(choice==1){
        Contacts(ContList);
    }
//    else if(choice==2){
//        Messages();
//    }
    else if(choice==3){
        SaveFile_Contact(ContList);
        exit(1);
    }
    else{
        printf("!!! invalid input !!!");
        Menu(ContList);
    }
}

void Contacts(ContactList ContList){
    char Name[100];
    int Cont_No;
    printf("   1.Add Contact\n");
    printf("   2.Update Contact\n");
    printf("   3.Display Contacts\n");
    printf("   4.Delete Contact\n");
    printf("   5.Search Contact\n");
    printf("   6.Back\n");
    scanf("%d",&choice);
    switch(choice){
            case 1:
                printf("Name:");
                getchar();
                gets(Name);
                printf("Contact No:");
                scanf("%d",&Cont_No);
            Add_Contact(ContList,Name,Cont_No);
            break;
//            case 2:
//               Update_Contact();
//               break;
            case 3:
            Display_Contact(ContList);
            break;
            case 4:
               Delete_Contact(ContList);
               break;
            case 5:
               Search_Contact(ContList);
               break;
            case 6:
                Menu(ContList);
                break;
        default:
            Contacts(ContList);

    }
    Contacts(ContList);

}
//void Messages(){
//        printf("   1.Compose Message\n");
//        printf("   2.Display Message\n");
//        printf("   3.Delete Message\n");
//        printf("   3.Back\n");
//        scanf("%d",&choice);
//        switch(choice){
//            case 1:
//               Compose_Message();
//               break;
//            case 2:
//               Display_Message();
//               break;
//            case 3:
//               Delete_Message();
//               break;
//            case 4:
//               main();
//               break;
//            default:
//                Messages();
//
//        }
//}

void Add_Contact(ContactList ContList,char Name[],int Cont_No){
    Contact *Cont,*Temp;
    Cont=(Contact*)malloc(sizeof(Contact));
    strcpy(Cont->Name,Name);
    Cont->Contact_No=Cont_No;
    // Enter the Element to an Empty List***
    if(ContList->Head==NULL){
        Cont->NextContact=NULL;
        ContList->Head=Cont;
        ContList->count++;
        End=Cont;
    }
    //Enter the Element at the begining***
    else if(strcmp(ContList->Head->Name,Cont->Name)>0){
        Cont->NextContact=ContList->Head;
        ContList->Head=Cont;
        ContList->count++;
    }
    //Enter an Element to the end of the list
    else if(strcmp(End->Name,Cont->Name)<0){
        Temp=ContList->Head;
        while(Temp->NextContact!=NULL){
            Temp=Temp->NextContact;
        }
        Temp->NextContact=Cont;
        Cont->NextContact=NULL;
        End=Cont;
        ContList->count++;
    }
    //Enter an Element to a Specific position at the list
    else{
        Temp = ContList->Head;
        while (strcmp(Temp->NextContact->Name, Cont->Name) < 0 ) {
            Temp = Temp->NextContact;
        }
        Cont->NextContact=Temp->NextContact;
        Temp->NextContact=Cont;
        ContList->count++;
    }

    }

void Display_Contact(ContactList ContList){
    Contact *Temp;
    if(ContList->Head==NULL){
        printf("Contact List is empty");
    }
    else{
        Temp=ContList->Head;
        while(Temp!=NULL){
            printf("%s %d\n",Temp->Name,Temp->Contact_No);
            Temp=Temp->NextContact;
        }
    }

}
void Delete_Contact(ContactList ContList){
    char Name[100];
    Contact *Temp1,*Temp2;
    Temp1=ContList->Head;
    printf("Name:");
    getchar();
    gets(Name);
    if(strcmp(ContList->Head->Name,Name)==0){
        ContList->Head=ContList->Head->NextContact;
        printf("\nContact \"%s\" is Deleted Sucessfully!\n",Name);
        return;
    }
    while(Temp1->NextContact->NextContact!=NULL){
        if(strcmp(Temp1->NextContact->Name,Name)==0){
            Temp2=Temp1->NextContact;
            Temp1->NextContact=Temp2->NextContact;
            printf("\nContact \"%s\" is Deleted Sucessfully!\n",Name);
            return;
        }
        Temp1=Temp1->NextContact;
    }
    if(strcmp(Temp1->NextContact->Name,Name)==0){
        Temp2=Temp1->NextContact;
        Temp1->NextContact=NULL;
        printf("\nContact \"%s\" is Deleted Sucessfully!\n",Name);
        return;
    }
    printf("Contact Name is not Found to Delete");
}
void Search_Contact(ContactList ContList){
    char Name[100];
    Contact *Temp;
    Temp=ContList->Head;
    printf("Name:");
    getchar();
    gets(Name);
    while(Temp!=NULL){
        if(strcmp(Temp->Name,Name)==0){
            printf("Contact found,\nResult:\n\t%s  %d\n",Temp->Name,Temp->Contact_No);
            return;
        }
        Temp=Temp->NextContact;
    }
    if(Temp==NULL){
        printf("\nContact is not found!\n");
    }
}

void Update_Contact(ContactList ContList){

    char Name[100],New_Name[100];
    int New_ContactNo;
    Contact *Temp;
    Temp=ContList->Head;
    printf("Name:");
    getchar();
    gets(Name);
    while(Temp!=NULL){
        if(strcmp(Temp->Name,Name)==0){
            printf("Contact found,\nResult:\n\t%s  %d\n",Temp->Name,Temp->Contact_No);
            printf("\nEnter new Name:");
            gets(New_Name);
            printf("\nEnter Contact_No:");
            scanf("%d",New_ContactNo);
            return;
        }
        Temp=Temp->NextContact;
    }
    if(Temp==NULL){
        printf("\nContact is not found!\n");
    }
}

void SaveFile_Contact(ContactList ContList) {
    Contact *Temp;
    FILE *Contact_List;
    Contact_List = fopen("ContactList.txt", "a+");
    if (Contact_List == NULL) {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    } else {
        Temp = ContList->Head;
        while (Temp != NULL) {
            fputs(Temp->Name, Contact_List);
            fprintf(Contact_List," %d",Temp->Contact_No);
            fprintf(Contact_List,"\n");
            Temp = Temp->NextContact;
        }
        printf("Contacts Saved Successfully.\n");
    }
    fclose(Contact_List);
}