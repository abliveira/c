#include "TimeSubject.h"
#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct ListNode 
{
  TimeObserver item;
  struct ListNode* next; 
};

static struct ListNode observers; 
static SystemTime currentTime;
struct ListNode *head = &observers;

/* Local helper functions for managing the linked-list
  (implementation omitted). */
static void appendToList(const TimeObserver* observer)
{
  /* Append a copy of the observer to the linked-list. */
  
  if (NULL != head){
    struct ListNode *link = (struct ListNode*) malloc(sizeof(struct ListNode));
    
    link->item = *observer;
    link->next = head;
    head = link;
  }
}

static void removeFromList(const TimeObserver* observer)
{
  /* Identify the observer in the linked-list and
     remove that node. */ 

  struct ListNode* current = head;
  struct ListNode* previous = NULL;

  if(head == NULL) {
    return;
  }

  while(current->item.instance != (observer->instance)) {
    if(current->next == NULL) {
        break;
    } else {
        previous = current;
        current = current->next;
    }
  }
   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }
}

static SystemTime calculateNewTime(void)
{
  /* Time will pass slowly in this watch... */
  SystemTime newTime = {(rand()%2400)};
  return newTime;
}

/* 
  Checking Subject constraints with assertions.
*/
static int isNotifying = 0;

/* Implementation of the TimeSubject interface. */
void attach(const TimeObserver* observer)
{
  assert(0 == isNotifying);
  assert(NULL != observer);
  appendToList(observer);
}

void detach(const TimeObserver* observer) 
{
  assert(0 == isNotifying);
  assert(NULL != observer);
  removeFromList(observer);
}

/* Implementation of the original responsibility of the
   TimeSource (code for initialization, etc omitted). */
void msTick() 
{
  printf("\n* msTick -> Time Update\n");
  struct ListNode* node = head;
  /* Invoke a function encapsulating the knowledge
     about time representation. */
  currentTime = calculateNewTime();
  
  /* Ensure that no changes are done to the
     subject during notification. */
  isNotifying = 1;

  /* Walk through the linked-list and notify every 
     observer that another millisecond passed.\
   */
  while(NULL != node->next) {
    TimeObserver* observer = &node->item;
    observer->notification(observer->instance, &currentTime);
    node = node->next;
  }

  /* All observers notified, allow changes again. */
  isNotifying = 0;
 }
