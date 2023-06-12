	
	.syntax	unified
	.arch	armv7-m

	.section  .main.stack, "w" 
main_sp:  .space  0x1000

	.section  .process.stack, "w" 
process_sp:  .space  0x1000





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

	.extern  do_reset
	.extern  do_NMI
	.extern	 do_mem_fault
	.extern  do_bus_fault
	.extern  do_usage_fault
	.extern  do_svcall
	.extern  do_debug
	.extern  do_pendsv
	.extern  do_systick

	.section  .start.init, "x"
	.align   2
	.func  reset_handler
		b  do_reset
	.endfunc


	.func  NMI_handler
		SAVE_CONTEXT
		bl  do_NMI
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION
    .endfunc


	.func  memory_fault_handler
		SAVE_CONTEXT
		bl  do_mem_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION
    .endfunc


	.func  bus_fault_handler
		SAVE_CONTEXT
		bl  do_bus_fault
		RESUME_CONTEXT
		RETURN_FROM_EXCEPTION
	.endfunc


	.func  usage_fault_handler
					SAVE_CONTEXT
                    bl  do_usage_fault
					RESUME_CONTEXT
					RETURN_FROM_EXCEPTION
	.endfunc

	.section  .exception.table, "o"
expr_vector_table:  .word main_sp
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
	.global  main_sp
	.global  process_sp
	.global  expr_vector_table




@ #define BUILD_EXCEPTION(name, fn)	\
@ 	.func  (name)	\
@ 		SAVE_CONTEXT;		\
@ 		bl  (fn);	\
@ 		RESUME_CONTEXT;		\
@ 		RETURN_FROM_EXCEPTION;		\
@ 	.endfunc





	
	.end



