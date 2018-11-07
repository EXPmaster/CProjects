#include <stdio.h>
#include <stdarg.h>
#define NUM 3

int sum(int,...);

typedef struct structure {
    int id;
    double grade;
}Student;

void struct_sort_grade(Student *ptd);
void input(Student *ptd);
void output(Student *ptd);

int main() {
    //printf("sum(1, 2, -1024) : %d\n ", sum(2, 1, 2, -1024));
    //printf("sum(1, 2, 3, 4, -1024) : %d\n", sum(4, 1, 2, 3, 4, -1024));
    Student info[NUM];
    input(&info[0]);
    struct_sort_grade(&info[0]);
    output(&info[0]);
    return 0;
}

void input(Student *ptd) {
    int number=1;
    for(int i=0;i<NUM;i++){
        printf("Please enter the id of the %d student:\n",number);
        scanf("%d",&ptd->id);
        printf("Please enter the grade of the %d student:\n",number);
        scanf("%lf",&ptd->grade);
        ptd++;
        number++;
    }
}

void struct_sort_grade(Student *ptd) {
    //ѡ������
    for(int i=0; i<NUM-1; i++) {
        for(int j=i+1; j<NUM; j++) {
            if((ptd+i)->grade < (ptd+j)->grade) {
                //grade����
                /*  �ٵ��㷨
                temp1 = (ptd+i)->grade;
                (ptd+i)->grade = (ptd+j)->grade;
                (ptd+j)->grade = temp1;
                //id��Ӧgrade
                temp2 = (ptd+i)->id;
                (ptd+i)->id = (ptd+j)->id;
                (ptd+j)->id = temp2;
                */
                Student temp;
                temp=*(ptd+i);
                *(ptd+i) = *(ptd+j);
                *(ptd+j) = temp;
            }
        }
    }
}

void output(Student *ptd) {
    for(int i=0; i<NUM; i++) {
        printf("id:%d\tgrade:%lf\n",(ptd+i)->id,(ptd+i)->grade);
    }
}

int sum(int lim,...) {  //��һ��������ʾ��������
    va_list ap; //������������Ķ���
    int sum = 0;
    va_start(ap, lim);  //��ap��ʼ��Ϊ�����б�
    for (int i = 0; i < lim; i++)
        sum += va_arg(ap, int);  //�����б��е�ÿһ������
    va_end(ap); //������
    return sum;
}

