#include <stdio.h>
int manual();
int automatic();
int begin();
int changemode();
int manual_dial(int dial);
int main()
{
	
	printf("----Electric Water Bucket-----\n");
    begin();
	
}
int begin()
{
    int start;
    printf("Press 1 - To start \nPress 2 - To off \n");
    scanf("%d",&start);
    if(start==1)
    {
        changemode();
    }
    else if(start==2)
    {
        printf("Electric water bucket Turned Off.\n");
    }
    else{
        printf("Invalid input\n");
        begin();
    }

}
int changemode()
{
    int mode;
    printf("Press 1 - for Manual mode\nPress 2 - for Automatic mode\n");
    scanf("%d",&mode);
    if(mode==1)
    manual();
    else if(mode==2)
    automatic();
    else{
        printf("invalid input\n");
        changemode();
    }
}
int manual()
{
    int current;
    printf("----Manual mode-----\n");
    printf("Enter the value through dial ranging from 0(No current) to 100(Full current).\n");
    scanf("%d",&current);
    manual_dial(current);

   
}

int manual_dial(int current)
{
    int change;
     if(current>=0 && current<=100){
        do{
            if(current<20)
            printf("At this current time required to heat water till equllibrium will take 40 minute.\n");
            else if(current<40)
            printf("At this current time required to heat water till equllibrium will take 30 minute.\n");
            else if(current<60)
            printf("At this current time required to heat water till equllibrium will take 20 minute.\n");
            else if(current<80)
            printf("At this current time required to heat water till equllibrium will take 20 minute.\n");
            else if(current<=100)
            printf("At this current time required to heat water till equllibrium will take 10 minute.\n");
            
            printf("\nPress 1 - If u want to change the current value again.\n");
            printf("Press 2 - If u want to change the mode.\n");
            scanf("%d", &change);
            if(change==1)
            {
                printf("enter value of current from 0 to 100\n");
                scanf("%d",&current);
                manual_dial(current);
            }
            else if(change==2)
            {
                changemode();
            }
            else
            {
                printf("invalid input\n");
                manual_dial(current);

            }
    }while(current>=0 && current<=100);
    } 
    else
    {
        printf("invalid input\n");
        manual();

    }
}
int automatic()
{
	printf("auto");
}




