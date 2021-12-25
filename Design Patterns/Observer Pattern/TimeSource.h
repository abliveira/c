#ifndef TIME_SOURCE_H
#define TIME_SOURCE_H
#include "TimeObserver.h"

static void appendToList(const TimeObserver* observer);

static void removeFromList(const TimeObserver* observer);

static SystemTime calculateNewTime(void);

void attach(const TimeObserver* observer);

void detach(const TimeObserver* observer);

void msTick();

#endif
