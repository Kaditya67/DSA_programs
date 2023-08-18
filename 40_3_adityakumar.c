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
	
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(s[i].roll_no>s[j].roll_no){
				temp = s[j].roll_no;
				s[i].roll_no = s[j].roll_no;
				s[j].roll_no=temp;
				
				strcpy(temp1, s[i].name);
		        	strcpy(s[i].name, s[j].name);
		        	strcpy(s[j].name, temp1);

				
				temp2 = s[i].perct;
				s[i].perct = s[j].perct;
				s[j].perct=temp2;
			
		
			}
	
		}
	}
	
	
	
	printf("\n\n");
		// Printing Values
	for(int i=0;i<5;i++){
	
		printf("The name of student : %d is %s\n",i+1,s[i].name);
		
		printf("The roll number of student : %d is %d\n",i+1,s[i].roll_no);
		
		printf("The percentage of student : %d is %d\n",i+1,s[i].perct);
		
		printf("\n\n");
	
	}

	return 0;

}
