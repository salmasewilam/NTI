/*
 * small_os.h
 *
 * Created: 11/08/23 9:28:46 PM
 *  Author: USER
 */ 


#ifndef SMALL_OS_H_
#define SMALL_OS_H_

typedef struct {
	u32 periodicity;
	void (*pfun) (void);
	}task_t;



#endif /* SMALL_OS_H_ */