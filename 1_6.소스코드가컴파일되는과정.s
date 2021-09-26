	.file	"1_6.\274\322\275\272\304\332\265\345\260\241\304\304\306\304\300\317\265\307\264\302\260\372\301\244.c"
	.def	___main;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB10:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	andl	$-16, %esp
	subl	$272, %esp
	.cfi_offset 7, -12
	call	___main
	movl	$1819043144, 16(%esp)
	movl	$111, 20(%esp)
	leal	24(%esp), %edx
	movl	$0, %eax
	movl	$62, %ecx
	movl	%edx, %edi
	rep stosl
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	_puts
	movl	$0, %eax
	movl	-4(%ebp), %edi
	leave
	.cfi_restore 5
	.cfi_restore 7
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE10:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_puts;	.scl	2;	.type	32;	.endef
