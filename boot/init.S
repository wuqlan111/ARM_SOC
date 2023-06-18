	
	.syntax	unified
	.arch	armv7-m


	.equ	MAIN_STACK_SIZE, 0x2000
	.equ	PROCESS_STACK_SIZE, 0x2000


	.section .main.stack
	.align	3
	.globl	MAIN_STACK_TOP
	.globl	MAIN_STACK_LIMIT
MAIN_STACK_LIMIT:
	.space	MAIN_STACK_SIZE
	.size	MAIN_STACK_LIMIT, . - MAIN_STACK_LIMIT
MAIN_STACK_TOP:
	.size	MAIN_STACK_TOP, . - MAIN_STACK_TOP

	.section .process.stack
	.align	3
	.globl	PROCESS_STACK_TOP
	.globl	PROCESS_STACK_LIMIT
PROCESS_STACK_LIMIT:
	.space	PROCESS_STACK_SIZE
	.size	PROCESS_STACK_LIMIT, . - PROCESS_STACK_LIMIT
PROCESS_STACK_TOP:
	.size	PROCESS_STACK_TOP, . - PROCESS_STACK_TOP


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
	.size	expr_vector_table, . - expr_vector_table


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


	.macro	def_irq_handler	handler_name
			.align	1
			.thumb_func
			.type	\handler_name, %function
			.size	\handler_name, . - \handler_name
			\handler_name:
	.endm


	.extern  do_reset
	.extern  do_NMI
	.extern  do_hard_fault
	.extern	 do_mem_fault
	.extern  do_bus_fault
	.extern  do_usage_fault
	.extern  do_svcall
	.extern  do_debug
	.extern  do_pendsv
	.extern  do_systick

	.text
	.thumb
	.thumb_func
	.align   2
	.global  reset_handler
	.type	reset_handler, %function
reset_handler:
		mov   r0,  7
		mov   r0,  7
		mov   r0,  7
		b  do_reset



    def_irq_handler  NMI_handler
		SAVE_CONTEXT
		bl  do_NMI
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION


    def_irq_handler  hard_fault_handler
		SAVE_CONTEXT
		bl  do_hard_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION

    def_irq_handler  memory_fault_handler
		SAVE_CONTEXT
		bl  do_mem_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION



    def_irq_handler  bus_fault_handler
		SAVE_CONTEXT
		bl  do_bus_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION


    def_irq_handler  usage_fault_handler
		SAVE_CONTEXT
		bl  do_usage_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION

    def_irq_handler  svcall_handler
			b  .

    def_irq_handler  debug_handler
			b  .

    def_irq_handler  pendsv_handler
			b   .

    def_irq_handler  systick_handler
			b  .


	
	.end



