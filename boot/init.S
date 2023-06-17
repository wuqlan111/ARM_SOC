	
	.syntax	unified
	.arch	armv7-m

	.section .main.stack
	.align	3
#ifdef _MAIN_STACK_SIZE
	.equ	MAIN_STACK_SIZE, _MAIN_STACK_SIZE
#else
	.equ	MAIN_STACK_SIZE, 0x1000
#endif
	.globl	MAIN_STACK_TOP
	.globl	MAIN_STACK_LIMIT
MAIN_STACK_LIMIT:
	.space	MAIN_STACK_SIZE
	@ .size	MAIN_STACK_LIMIT, . - MAIN_STACK_LIMIT
MAIN_STACK_TOP:
	@ .size	MAIN_STACK_TOP, . - MAIN_STACK_TOP

	.section .process.stack
	.align	3
#ifdef _PROCESS_STACK_SIZE
	.equ	PROCESS_STACK_SIZE, _PROCESS_STACK_SIZE
#else
	.equ	PROCESS_STACK_SIZE, 0x1000
#endif
	.globl	PROCESS_STACK_TOP
	.globl	PROCESS_STACK_LIMIT
PROCESS_STACK_LIMIT:
	.space	PROCESS_STACK_SIZE
	@ .size	PROCESS_STACK_LIMIT, . - PROCESS_STACK_LIMIT
PROCESS_STACK_TOP:
	@ .size	PROCESS_STACK_TOP, . - PROCESS_STACK_TOP


	.macro  SAVE_CONTEXT
			push   {r0-r7}
			mrs	   r0, control
			push   {r0}
	.endm

	.macro  RESUME_CONTEXT
			pop  {r0}
			msr  control, r0
			pop  {r0-r7}
	.endm

	.macro  RETURN_FROM_EXCEPTION
		bx  lr
	.endm


	.section  .exception.table, "a",%progbits
	.align  2	
	.global  expr_vector_table
expr_vector_table:
	.word MAIN_STACK_TOP
	.word reset_handler
	.word NMI_handler
	.word hard_fault_handler
	.word memory_fault_handler
	.word bus_fault_handler
	.word usage_fault_handler
	.word 0
	.word 0
	.word 0
	.word 0
	.word svcall_handler
	.word debug_handler
	.word 0
	.word pendsv_handler
	.word systick_handler
extern_vector:	.space  0x1000
	@ .size	expr_vector_table, . - expr_vector_table




	.extern  do_reset
	.extern  do_NMI
	.extern	 do_mem_fault
	.extern  do_bus_fault
	.extern  do_usage_fault
	.extern  do_svcall
	.extern  do_debug
	.extern  do_pendsv
	.extern  do_systick

	.text
	.thumb
	.align   2
	.global  reset_handler
reset_handler:
		b  do_reset



NMI_handler:
		SAVE_CONTEXT
		bl  do_NMI
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION


hard_fault_handler:
			b  .

memory_fault_handler:
		SAVE_CONTEXT
		bl  do_mem_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION



bus_fault_handler:
		SAVE_CONTEXT
		bl  do_bus_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION


usage_fault_handler:
					SAVE_CONTEXT
                    bl  do_usage_fault
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION

svcall_handler:
			b  .

debug_handler:
			b  .

pendsv_handler:
			b   .

systick_handler:
			b  .









@ #define BUILD_EXCEPTION(name, fn)	\
@ 	.func  (name)	\
@ 		SAVE_CONTEXT;		\
@ 		bl  (fn);	\
@ 		RESUME_CONTEXT;		\
@ 		RETURN_FROM_EXCEPTION;		\
@ 	.endfunc





	
	.end



