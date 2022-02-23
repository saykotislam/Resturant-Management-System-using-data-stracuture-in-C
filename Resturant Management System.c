#include <stdio.h>
#include <stdlib.h>

struct node
{
  int x;//x=food_id
  char food_name[100];
  int f_price;    //price

  struct node *next;
  struct node *prev;

}*head=NULL, *tail= NULL;



void create()
{
    int n_node,i;

    FILE *file;

    file=fopen("Food_list.txt", "a+");


    struct node *new_node, *current;
    printf("Enter Food number: ");
    scanf("%d", &n_node);





    for(i=0;i<n_node;i++){
        new_node=(struct node*)malloc(sizeof(struct node));

            printf("Enter Food ID: ");
            scanf("%d", &new_node->x);         //food id

            printf("Enter Food Name: ");
            scanf("%s", &new_node->food_name); //food name

            printf("Enter Food Price: ");
            scanf(" %d", &new_node->f_price);

        fprintf(file,"Food ID:%d\tFood Name: %s\t price: %d\n\n", new_node->x, new_node->food_name, new_node->f_price);
        //fprintf(file,"name = %s            roll = %d\n", name,roll);


        new_node->next= NULL;
        new_node->prev=NULL;



        if(head==NULL && tail==NULL){
            head = new_node;
            tail= new_node;

            current = new_node;
        }

        else{
            current->next=new_node;
            new_node->prev= current;


            tail=new_node;
            current=new_node;

        }
    }
    fclose(file);// file colse

}


void traversal()
{
    struct node *temp;
    temp=head;


    printf("--------------------------------------------------------------------------\n");
    printf("                                 Food Menu\n");
    printf("--------------------------------------------------------------------------\n\n\n");

    while(temp!= NULL){
        printf("Id      = %d\nName    = %s\nFood Price: %d\n\n", temp->x,temp->food_name, temp->f_price);      //print food name

        temp=temp->next;
    }
    temp=tail;

}



void t_bill()
{
    int id,qu,tb;
    struct node *current;

    FILE *file;

    file=fopen("order_list.txt", "a+");



    current=head;

    printf("Enter the ID:   ");
    scanf("%d", &id);
   // printf("Food Id: %d", id);


    printf("\nEnter Quantity: ");
    scanf("%d", &qu);
    //printf("Food q: %d", qu);

    //date
    printf("\nAdd Discount: ");
    int d;
    scanf("%d", &d);

    while(current!=NULL){

        if(current->x == id){
            tb=current->f_price*qu;

        }
        current=current->next;
    }


    printf("Total Bill: %d", tb-d);

    fprintf(file,"Food ID:  %d\tFood Quantity:  %d\tTotal Bill:  %d TK\n\n", id,qu,tb);
    fclose(file);// file colse

}


void insert_fooditeam()
{
    struct node *new_node, *current;
    new_node= (struct node*)malloc(sizeof(struct node));

    FILE *file;

    file=fopen("Food_list.txt", "a+");

    printf("Enter the new food Details: \n");

            printf("Enter Food ID: ");
            scanf("%d", &new_node->x);         //food id

            printf("Enter Food Name: ");
            scanf("%s", &new_node->food_name); //food name

            printf("Enter Food Price: ");
            scanf(" %d", &new_node->f_price);

    fprintf(file,"Food ID:%d\tFood Name: %s\t price: %d\n\n", new_node->x, new_node->food_name, new_node->f_price);
    fclose(file);// file colse

    new_node->next=NULL;
    new_node->prev=NULL;

    current=tail;


    current->next= new_node;
    new_node->prev=current;
    tail=new_node;

}



int search(int node_delete)
{
    int pos=0;
    struct node *current;
    current= head;

    while(current!=NULL){
            pos++;
        if(node_delete==current->x){
            return pos;
        }
        current=current->next;
    }
}



void delete_food()
{
    int node_delete,pos,i;
    struct node *current,*temp1, *temp2;
    printf("\n\nEnter the Food Id that you want to delete: ");
    scanf("%d",&node_delete);
    pos=search(node_delete);
    current=head;

    for(i=1;i<pos;i++){
         current=current->next;
    }

    if(current==head && current->prev==NULL){
        temp1=current->next;
        head=temp1;
        temp1->prev=NULL;
    }

    else if(current->next==NULL && current==tail){
       temp1=current->prev;
       temp1->next=NULL;
       tail=temp1;

    }

    else{
        temp1=current->prev;
        temp2=current->next;

        temp1->next=temp2;
        temp2->prev=temp1;
    }
}


void view_orderlist()
{
    FILE *view;
    char viw;
    view = fopen("order_list.txt","rt");
    while((viw=fgetc(view))!=EOF)
    {
        printf("%c",viw);
    }
    fclose(view);

}

void view_foodlist()
{
    FILE *view;
    char viw;
    view = fopen("Food_list.txt","rt");
    while((viw=fgetc(view))!=EOF)
    {
        printf("%c",viw);
    }
    fclose(view);

}

void decoration()
{
        printf("**************************************************************************\n");
        printf("                      Restaurants Management System\n");
        printf("**************************************************************************\n\n\n");
        //printf("Press 1 - For making food list\n");
        printf("Press 1 - For Add Food in the list\n"   );
        printf("Press 2 - For Delete Food Iteam\n");
        //printf("\n");
        printf("Press 3 - For Order Food\n");
        printf("Press 4 - For See order List\n");
        printf("Press 5 - For See the Food List\n");
        printf("Press 6 - About Us\n");
        printf("Press 0 - For EXIT\n");

        printf("\nPress Number: ");
}

void progress()
{
    int wait;
	//printf("In progress :");
        for(wait=0;wait<=50000;wait++){
		printf("\rIn progress : %d",wait/500);
        }
}


void aboutus()
{
    printf("\n\n**********************About Us**********************\n\n");
    printf("Md Saykot Islam        Id: 201-15-13993\n");
    printf("Sajid-ul Anam Sochcoo  Id: 201-15-14074\n");
    printf("Md.Muzahidul Islam     Id: 201-15-14073\n");
    printf("Aboni Rebeca Biswas    Id:  201-15-13908\n");
    printf("Ashik Billah Rifat     Id: 201-15-14072\n");
}

int main()
{
        printf("******************************************************************************************************\n");
        printf("                                       Restaurants Management System\n");
        printf("******************************************************************************************************\n\n");

        int n;
       printf("\n\n**********************Make your Food Menu**********************\n\n");
            create();
            traversal();

    while(1){

        decoration();
        scanf("%d", &n);




        if(n==1){
            progress();
            printf("\n\n**************************************************\n\n");
            insert_fooditeam();
            traversal();

        }
        if(n==2){
            progress();

             delete_food();
             traversal();
        }

        if(n==3){
            progress();
            printf("\n\n**********************Order List**********************\n\n");
            t_bill();
            printf("\n<<<<Thanks for the order>>>>\n");


        }
        if(n==4){
            progress();
            printf("\n\n**********************Order List**********************\n\n");
            view_orderlist();

        }

        if(n==5){
            progress();
            printf("\n\n**********************Food List**********************\n\n");
            view_foodlist();

        }
        if(n==6){
            printf("\n");
            aboutus();
            printf("\n");
        }

        if(n==0){
            exit(0);
        }

        if(n<0 || n>5){
            printf("\n\n\n\nWrong Input !!! \nPlease Enter The Correct Option.........\n\n");
            continue;
        }




    }
}
