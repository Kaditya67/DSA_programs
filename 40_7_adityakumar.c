#include <stdio.h>

struct time_struct {
    int hour;
    int minute;
    int second;
};

void inputTime(struct time_struct *time) {
    printf("Enter hour: ");
    scanf("%d", &time->hour);
    printf("Enter minute: ");
    scanf("%d", &time->minute);
    printf("Enter second: ");
    scanf("%d", &time->second);
}

void displayTime(const struct time_struct time) {
    printf("Time: %02d:%02d:%02d\n", time.hour, time.minute, time.second);
}

struct time_struct updateTime(struct time_struct time) {
    time.second++;
    if (time.second == 60) {
        time.second = 0;
        time.minute++;
        if (time.minute == 60) {
            time.minute = 0;
            time.hour++;
            if (time.hour == 24) {
                time.hour = 0;
            }
        }
    }
    return time;
}

int main() {
    struct time_struct myTime;
    inputTime(&myTime);
    
    printf("Initial ");
    displayTime(myTime);
    
    myTime = updateTime(myTime);
    printf("After incrementing by one second: ");
    displayTime(myTime);
    
    return 0;
}
