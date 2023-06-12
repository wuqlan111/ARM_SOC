	
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


	.section  .exception.table, "o"
	.global  expr_vector_table
expr_vector_table:
	.word main_sp
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



