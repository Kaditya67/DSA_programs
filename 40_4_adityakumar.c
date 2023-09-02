#include<stdio.h>
#include<string.h>

struct stud_details{

	int roll_no;
	char name[20];
	int perct;

};

int main(){

	struct stud_details s[5];
	
	// Accepting Details
	for(int i=0;i<5;i++){
	
		printf("Enter the name of student : %d ",i+1);
		scanf("%s",s[i].name);
		
		printf("Enter the roll number of student : %d ",i+1);
		scanf("%d",&s[i].roll_no);
		
		printf("Enter the percentage of student : %d ",i+1);
		scanf("%d",&s[i].perct);
	
	}
	

	
	int temp,temp2;
	char temp1[20];

	
	for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (s[j].perct < s[j + 1].perct) {
                // Swap the students
                struct stud_details temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

	
	
	
	
	
	
	printf(" \n \n");
	
		// Printing Values
	for(int i=0;i<5;i++){
	
		printf("The name of student : %d is %s \n",i+1,s[i].name);
		
		printf("The roll number of student : %d is %d \n",i+1,s[i].roll_no);
		
		printf("The percentage of student : %d is %d \n",i+1,s[i].perct);
		printf("\n \n");
	
	}

	return 0;

}
