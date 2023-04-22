
	AREA  MAIN_STACK, DATA, ALIGN = 0x3
MAIN_STACK_MEM SPACE  0x1000
__main_sp


	EXPORT expr_vector_table
	AREA RESET, DATA, READONLY,  ALIGN = 0x10
expr_vector_table
	DCD __main_sp
	DCD Reset_Handler
	DCD NMI_Handler
	DCD	HardFault_Handler
	DCD MeMFault_Handler
	DCD BusFault_Handler
	DCD UsageFault_Handler
	DCD 0
	DCD 0
	DCD 0
	DCD 0
	DCD SVCall_Handler
	DCD Debug_Handler
	DCD 0
	DCD PendSV_Handler
	DCD SysTick_Handler
	
extern_vector	SPACE 0x100




	MACRO
	SAVE_CONTEXT
	PUSH   {r4-r11, lr}
	MRS		r0, control
	MRS		r1,   xpsr
	PUSH   {r0, r1}
	MEND

	MACRO
	RESUME_CONTEXT
	POP {r0, r1}
	MSR  control, r0,
	MSR  xpsr, r1
	PUSH {r4-r11, lr}
	MEND

	MACRO
	RETURN_FROM_EXCEPTION
	BX  lr
	MEND

	IMPORT  do_reset
	IMPORT  do_NMI
	IMPORT	do_mem_fault
	IMPORT  do_bus_fault
	IMPORT do_usage_fault
	IMPORT do_svcall
	IMPORT do_debug
	IMPORT do_pendsv
	IMPORT do_systick


	AREA  init_startup, CODE, READONLY	
	ALIGN
	ENTRY
Reset_Handler	PROC
				B do_reset
				ENDP


NMI_Handler     PROC
				SAVE_CONTEXT
                BL  do_NMI
				RESUME_CONTEXT
				RETURN_FROM_EXCEPTION
                ENDP


MeMFault_Handler    PROC
					SAVE_CONTEXT
                    BL  do_mem_fault
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP


BusFault_Handler    PROC
					SAVE_CONTEXT
                    BL  do_bus_fault
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP


UsageFault_Handler  PROC
					SAVE_CONTEXT
                    BL  do_usage_fault
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP

SVCall_Handler      PROC
					SAVE_CONTEXT
                    BL  do_svcall
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP


Debug_Handler       PROC
					SAVE_CONTEXT
                    BL do_debug
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP


PendSV_Handler      PROC
					SAVE_CONTEXT
                    BL  do_pendsv
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP


SysTick_Handler     PROC
					SAVE_CONTEXT
                    BL do_systick
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
                    ENDP



	
	END



