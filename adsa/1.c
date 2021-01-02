#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int roll;
    char name[5];
} st;
typedef struct btech
{
    st *s;
    int cgpa;
} bt;
void print(st *s)
{
    printf("%d\n", s->roll);
    printf("%s\n", s->name);
}
void bprint(bt *b)
{
    print(b->s);
    //printf("%d\n", b->s->roll);
    printf("%d\n", b->cgpa);
}

void main()
{
    st *s;
    s = (st *)malloc(sizeof(st));
    s->roll = 1;
    strcpy(s->name, "jack");
    //print(s);
    bt *b;
    b = (bt *)malloc(sizeof(bt));
    b->s = s;
    b->cgpa = 10;
    bprint(b);
}