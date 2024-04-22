#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
pthread_t tid;
pthread_t writerthreads[100], readerthreads[100];
int readercount = 0;
void *reader(void *param)
{
    readercount++;
    printf("%d reader is inside\n", readercount);
    usleep(3);
    printf("%d Reader is leaving\n", readercount);
    readercount--;
    return NULL;
}
void *writer(void *param)
{
    printf("Writer is trying to enter\n");
    printf("Writer has entered\n");
    printf("Writer is leaving\n");
    return NULL;
}
int main()
{
    int n2, i;
    printf("Enter the number of readers: ");
    scanf("%d", &n2);
    printf("\n");
    for (i = 0; i < n2; i++)
    {
        pthread_create(&writerthreads[i], NULL, reader, NULL);
        pthread_create(&readerthreads[i], NULL, writer, NULL);
    }
    for (i = 0; i < n2; i++)
    {
        pthread_join(writerthreads[i], NULL);
        pthread_join(readerthreads[i], NULL);
    }
    return 0;
}
