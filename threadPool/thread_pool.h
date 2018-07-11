#ifndef _THREADPOOL_
#define _THREADPOOL_

#ifdef __cplusplus
extern "C" {
#endif


/* =================================== API ======================================= */


typedef struct thpool_* threadpool;


/**
* @brief  Initialize threadpool
* This function will not return untill all threads have initialized successfully.
* @param  num_threads   number of threads to be created in the threadpool
* @return threadpool    created threadpool on success, NULL on error
*/
threadpool thpool_init(int num_threads);


/**
* @brief Add work to the job queue
* Takes an action and its argument and adds it to the threadpool's job queue.
* If you want to add to work a function with more than one arguments then
* a way to implement this is by passing a pointer to a structure.
* NOTICE: You have to cast both the function and argument to not get warnings.
* @param  threadpool    threadpool to which the work will be added
* @param  function_p    pointer to function to add as work
* @param  arg_p         pointer to an argument
* @return 0 on successs, -1 otherwise.
*/
int thpool_add_work(threadpool, void (*function)(void*), void *arg_p);


/**
* @brief Wait for all queued jobs to finish
* Will wait for all jobs - both queued and currently running to finish.
* Once the queue is empty and all work has completed, the calling thread
* (probably the main program) will continue.
* Smart polling is used in wait. The polling is initially 0 - meaning that
* there is virtually no polling at all. If after 1 seconds the threads
* haven't finished, the polling interval starts growing exponentially
* untill it reaches max_secs seconds. Then it jumps down to a maximum polling
* interval assuming that heavy processing is being used in the threadpool.
* @param threadpool     the threadpool to wait for
* @return nothing
*/
void thpool_wait(threadpool);


/**
 * @brief Pauses all threads immediately
 * The threads will be paused no matter if they are idle or working.
 * The threads return to their previous states once thpool_resume is called.
 * While the thread is being paused, new work can be added.
 * @param threadpool    the threadpool where the threads should be paused
 * @return nothing
 */
void thpool_pause(threadpool);


/**
 * @brief Unpauses all threads if they are paused
 * @param threadpool     the threadpool where the threads should be unpaused
 * @return nothing
 */
void thpool_resume(threadpool);


/**
 * @brief Destroy the threadpool
 * This will wait for the currently active threads to finish and then 'kill'
 * the whole threadpool to free up memory.
 * @param threadpool     the threadpool to destroy
 * @return nothing
 */
void thpool_destroy(threadpool);


/**
 * @brief Show currently working threads
 * Working threads are the threads that are performing work (not idle).
 * @param threadpool     the threadpool of interest
 * @return integer       number of threads working
 */
int thpool_num_threads_working(threadpool);


#ifdef __cplusplus
}
#endif

#endif