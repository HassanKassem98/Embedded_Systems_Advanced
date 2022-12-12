/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/*------------------Standard includes-----------------------------*/	

#include <stdlib.h>
#include <stdio.h>

/*------------------Scheduler includes-----------------------------*/	

#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"
#include "lpc21xx.h"


/*------------------Prephirals Includes-----------------------------*/	

#include "serial.h"
#include "GPIO.h"

/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )



#define BTN1			PORT_1, PIN0
#define BTN2			PORT_1, PIN1

#define Tasks_Number	6


#define P6		pdMS_TO_TICKS(100)
#define P5		pdMS_TO_TICKS(10)


#define P1		pdMS_TO_TICKS(50)
#define P2		pdMS_TO_TICKS(50)
#define P3		pdMS_TO_TICKS(100)
#define P4		pdMS_TO_TICKS(20)

#define TracingIdleTask		PORT_0, PIN6
#define TracingSysTick		PORT_0, PIN7

#define TracingT6		PORT_0, PIN5
#define TracingT5		PORT_0, PIN4

#define TracingT1		PORT_0, PIN0
#define TracingT2		PORT_0, PIN1
#define TracingT3		PORT_0, PIN2
#define TracingT4		PORT_0, PIN3

#if(configUSE_STATS_FORMATTING_FUNCTIONS == 1)
#define RUNTIME_STATS_POLLING_RATE		pdMS_TO_TICKS(1000)
#endif

typedef struct
	{
	char *txt;
	int size;		
	}	Queuetxt;

#if(configUSE_TRACE_FACILITY == 1)
#define TracingPORT						PORT_0
#define CPU_PollRate			pdMS_TO_TICKS(100)
static TickType_t IdleTime;
static pinX_t TracingPINS[Tasks_Number+1] = {PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6};
#endif

/*-----------------------------------------------------------*/
/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/

void Load_1_Simulation 		(void *pvParameters);
void Load_2_Simulation		(void *pvParameters);
void Button_1_Monitor 	(void *pvParameters);
void Button_2_Monitor 	(void *pvParameters);
void Periodic_Transmitter		(void *pvParameters);
void Uart_Receiver 		(void *pvParameters);

/*-----------------------------------------------------------*/

/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
{
	QueueHandle_t UsedQueue;
	
	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
#if(configUSE_EDF_SCHEDULER == 1)
	/* Creating buffer */
	UsedQueue = xQueueCreate(3, sizeof(Queuetxt *));
	
	/* Reseting PINS */
	
	GPIO_write(TracingIdleTask, PIN_IS_LOW);
	GPIO_write(TracingSysTick, PIN_IS_LOW);
	GPIO_write(TracingT1, PIN_IS_LOW);
	GPIO_write(TracingT2, PIN_IS_LOW);
	GPIO_write(TracingT3, PIN_IS_LOW);
	GPIO_write(TracingT4, PIN_IS_LOW);
	GPIO_write(TracingT5, PIN_IS_LOW);
	GPIO_write(TracingT6, PIN_IS_LOW);

	
    /* Create Tasks here */
/*------------------TASK 1-----------------------------*/	
		xTaskPeriodicCreate(Button_1_Monitor, 
							"Button_1_Monitor", 
							configMINIMAL_STACK_SIZE, 
							(void *)&UsedQueue, 
							1, 
							NULL,
							P1);
/*------------------TASK 2-----------------------------*/		
		xTaskPeriodicCreate(Button_2_Monitor, 
							"Button_2_Monitor", 
							configMINIMAL_STACK_SIZE, 
							(void *)&UsedQueue, 
							1, 
							NULL,
							P2);
/*------------------TASK 3-----------------------------*/						
		xTaskPeriodicCreate(Periodic_Transmitter, 
							"Periodic_Transmitter", 
							configMINIMAL_STACK_SIZE, 
							(void *)&UsedQueue, 
							1, 
							NULL,
							P3);
/*------------------TASK 4-----------------------------*/					
		xTaskPeriodicCreate(Uart_Receiver, 
							"Uart_Receiver", 
							configMINIMAL_STACK_SIZE, 
							(void *)&UsedQueue,
							1, 
							NULL,
							P4);
/*------------------TASK 5-----------------------------*/						
		xTaskPeriodicCreate(Load_1_Simulation, 
							"Load_1_Simulation", 
							configMINIMAL_STACK_SIZE, 
							NULL, 
							1, 
							NULL,
							P5);
/*------------------TASK 6-----------------------------*/						
		xTaskPeriodicCreate(Load_2_Simulation, 
							"Load_2_Simulation", 
							configMINIMAL_STACK_SIZE + (((Tasks_Number+1) * 40 * (configUSE_STATS_FORMATTING_FUNCTIONS && 1)) / sizeof(size_t)),
							NULL, 
							1, 
							NULL,
							P6);
	/*-----------------------------------------------------------*/
#endif
	
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	vTaskStartScheduler();

	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}
/*-----------------------------------------------------------*/
/* Create Tasks Here */
#if(configUSE_EDF_SCHEDULER == 1)
/* Task 1 */
void Button_1_Monitor(void *pvParameters)
	{
	const TickType_t xFrequency = P1;
	pinState_t Status;
	static pinState_t InitCase = PIN_IS_HIGH;
		
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const QueueHandle_t UsedQueue = *((QueueHandle_t *)pvParameters);
	
	Queuetxt *TxtPtr[2];
		
	Queuetxt Txt0 = {"First Button Falling Edge\n", 17};
	Queuetxt Txt1 = {"First Button Rising Edge\n" , 16};
	
	TxtPtr[0] = &Txt0;
	TxtPtr[1] = &Txt1;

	/* Super loop */
	while(1)
	{		
/*------------------Checking First Button Status-----------------------------*/		
		
	Status = GPIO_read(BTN1);
		
	if(Status != InitCase)
		{
/*------------------Send text to the queue-----------------------------*/	
			if(UsedQueue != NULL)
				{
				xQueueSend(UsedQueue, (void *)&TxtPtr[Status], 0);
				}
			InitCase = Status;
		}
			vTaskDelayUntil(&xLastWakeTime, xFrequency);
			xLastWakeTime = xTaskGetTickCount();	
	}
}
/*------------------TASK 2-----------------------------*/		

void Button_2_Monitor(void *pvParameters){
	
	const TickType_t xFrequency = P2;
	pinState_t Status;
	static pinState_t InitCase = PIN_IS_HIGH;
	
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const QueueHandle_t UsedQueue = *((QueueHandle_t *)pvParameters);
	

	Queuetxt *TxtPtr[2];
	
	Queuetxt Txt0 = {"Second Button Falling Edge\n", 17};
	Queuetxt Txt1 = {"Second Button Rising Edge\n" , 16};
	
	TxtPtr[0] = &Txt0;
	TxtPtr[1] = &Txt1;
		
	/* Super loop */
	
	while(1)
		{
/*------------------Checking Second Button Status-----------------------*/		
		Status = GPIO_read(BTN2);
		if(Status != InitCase)
			
			{
/*------------------Send text to the queue-----------------------------*/	
			if(UsedQueue != NULL)
			{
				xQueueSend(UsedQueue, (void *)&TxtPtr[Status], 0);
			}
			
				InitCase = Status;
			}

			vTaskDelayUntil(&xLastWakeTime, xFrequency);
			xLastWakeTime = xTaskGetTickCount();
	}
}
/*------------------TASK 3-----------------------------*/		

void Periodic_Transmitter(void *pvParameters){
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xFrequency = P3;
	
	const QueueHandle_t UsedQueue = *((QueueHandle_t *)pvParameters);
	
	Queuetxt txt = {"Periodic Text\n", 15};
	Queuetxt *TxtPtr = &txt;
		
	/* Super loop */
	while(1)
		{
/*------------------Send text to the queue-----------------------------*/	
		if(UsedQueue != NULL)
			{
			xQueueSend(UsedQueue, (void *)&TxtPtr, 0);
			}
		
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		xLastWakeTime = xTaskGetTickCount();
	}
}
/*------------------TASK 4-----------------------------*/		

void Uart_Receiver(void *pvParameters)
	{
	const QueueHandle_t UsedQueue = *((QueueHandle_t *)pvParameters);
	Queuetxt *TBuffer;
	const TickType_t xFrequency = P4;
	TickType_t xLastWakeTime = xTaskGetTickCount();

	/* Super loop */
	while(1)
		{
		if(UsedQueue != NULL)
			{
/*------Read Text From The Queue & Send it--------*/	
	if(xQueueReceive(UsedQueue, (void *)&TBuffer, 0) == pdTRUE)	
			{
				while(vSerialPutString(TBuffer->txt, TBuffer->size)!= pdTRUE);
			}
		}
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		xLastWakeTime = xTaskGetTickCount();
	}
}
/*------------------TASK 5-----------------------------*/		

void Load_1_Simulation(void *pvParameters)
	{
	int x;	
	TickType_t xLastWakeTime = xTaskGetTickCount();
	const TickType_t xFrequency = P5;

	/* Super loop */
	while(1)
		{
		
/*----------Delaying 5 ms------------*/		
		for(x=0; x<37000; x++);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		xLastWakeTime = xTaskGetTickCount();
	}
}
/*------------------TASK 6-----------------------------*/		
void Load_2_Simulation(void *pvParameters)
	{
		
#if(configUSE_TRACE_FACILITY == 1)
	TickType_t PresTim;
	static TickType_t PTime;
	static uint16_t load;
	static uint8_t count;
#endif	
		
	int x;
	const TickType_t xFrequency = P6;	
	TickType_t xLastWakeTime = xTaskGetTickCount();

	
	/* Super loop */
	while(1){
/*----------Delaying 12 ms--------*/		
		for(x=0; x<90000; x++);
			
		vTaskDelayUntil(&xLastWakeTime, xFrequency);
		xLastWakeTime = xTaskGetTickCount();

#if(configUSE_TRACE_FACILITY == 1)		
		count++;
		
		if((count % (CPU_PollRate / P6)) == 0)	
		{
			PresTim = T1TC;
			load = 100 - (IdleTime * 100 / (PresTim - PTime));
			IdleTime = 0;
			PTime = PresTim;
		}
		
	#if(configUSE_STATS_FORMATTING_FUNCTIONS == 1)
		if((count % (RUNTIME_STATS_POLLING_RATE / P6)) == 0){
			char lg[40*(Tasks_Number+1)];
			char *s;
			int i;
			
			vTaskGetRunTimeStats(lg);
			
			s = lg;
			i = 0;
			while(*s++){
				i++;
			}
			
			while(vSerialPutString(lg, i) == pdFALSE);
			count = 0;
		}
	#endif
#endif
	}
}

#endif

/*------------------Tick Hook-----------------------------*/	
#if(configUSE_TICK_HOOK == 1)
void vApplicationTickHook( void ){
	GPIO_write(TracingSysTick, PIN_IS_HIGH);
	GPIO_write(TracingSysTick, PIN_IS_LOW);
}
#endif

/*------------------Idle hook-----------------------------*/	
#if(configUSE_IDLE_HOOK == 1)
void vApplicationIdleHook( void ){
	GPIO_write(TracingT1, PIN_IS_LOW);
	GPIO_write(TracingT2, PIN_IS_LOW);
	GPIO_write(TracingT3, PIN_IS_LOW);
	GPIO_write(TracingT4, PIN_IS_LOW);
	GPIO_write(TracingT5, PIN_IS_LOW);
	GPIO_write(TracingT6, PIN_IS_LOW);
	GPIO_write(TracingIdleTask, PIN_IS_HIGH);
}
#endif
/*------------------Tracing Function CW-----------------------------*/	
#if(configUSE_TRACE_FACILITY == 1)
void TracingT(UBaseType_t TaskNumber, uint8_t State)
	{
	TickType_t PresTim = T1TC;
	static TickType_t Trecord;

	switch(State)
		{
		case 1:
			GPIO_write(TracingPORT, TracingPINS[TaskNumber], PIN_IS_HIGH);
			if(TaskNumber == Tasks_Number)
			{
				Trecord = PresTim;
			}
		break;
		case 0:
			GPIO_write(TracingPORT, TracingPINS[TaskNumber], PIN_IS_LOW);
		
			if(TaskNumber == Tasks_Number)
			{
				IdleTime += (PresTim - Trecord);
			}
		break;
	}
}
#endif
/*----------------------------------------------------------*/
