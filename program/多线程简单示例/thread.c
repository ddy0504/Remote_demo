#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *count();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

main()
{

  int rc1,rc2;
  pthread_t thread1,thread2;
  if((rc1 = pthread_create(&thread1,NULL,&count,NULL)))
  {
     printf("");
  }
  if((rc2 = pthread_create(&thread2,NULL,&count,NULL)))
  {
     printf("");
  }

  pthread_join(thread1,NULL);
  pthread_join(thread2,NULL);

  exit(0);
}

void *count()
{
   pthread_mutex_lock(&mutex1);
   counter++;
   printf("Counter value: %d\n",counter);
   pthread_mutex_unlock(&mutex1);
}
