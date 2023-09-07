#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1, rear = -1;
int data;

void EnQRear(int x){
	
	if ((rear == MAX_SIZE - 1 && front == 0) || (front == rear + 1)) {
		printf("Queue is Overflow\n");
	}
	else{
		if (front == -1 && rear == -1) {
			front = rear = 0;
	} else {
	
		rear =(rear+1)%MAX_SIZE;
		queue[rear] = data;
	    	printf("%d Enqueued successfully.\n", data);
	    	
	    }
    }
}

void EnQFront(int x){
		
	if ((rear == MAX_SIZE - 1 && front == 0) || (front == rear + 1)) {
	printf("Queue is Overflow\n");
	}
	else{
	    if (front == 0) {
		front = MAX_SIZE -1;
		queue[front]= data;
		printf("%d Enqueued successfully.\n", data);
	    } else {
		front--;
		queue[front] = data;
	        printf("%d Enqueued successfully.\n", data);
	    }
	}
}

void DeQFront() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
    }

    printf("%d Dequeued successfully.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front=(front+1)%MAX_SIZE;
    }
}

void DeQRear(){

	if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
	}

	printf("%d Dequeued successfully.\n", queue[front]);

	if (front == rear) {
		front = rear = -1;
	} else {
		
		if( rear == 0 ){
		
			rear = MAX_SIZE -1;
		
		}
		else{
		
			rear--;
		
		}
		
	}

}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n\n1. Enqueue from rear\n2. Enqueue from front\n3. Dequeue from front\n4. Dequeue from rear\n5. Display\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter data to enqueue from rear: ");
                scanf("%d", &data);
                EnQRear(data);
                break;
            case 2:
                printf("\nEnter data to enqueue from front: ");
                scanf("%d", &data);
                EnQFront(data);
                break;
            case 3:
                DeQFront();
                break;
            case 4:
                DeQRear();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}




