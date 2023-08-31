; Computes number of 1's in a given 32bit number
	AREA RESET, CODE
	ENTRY
	
	LDR R0, =DATA1
	LDR R1, [R0]
	MOV R2, #0 ; NO OF 1'S
	MOV R3, #COUNT ; NO OF BITS 

LOOP MOVS R1, R1, LSL#1
	ADDCS R2, #1
	SUBS R3, #1
	BNE LOOP

STOP B STOP

COUNT EQU 32
DATA1 DCD 0xAAAAAAAA
	END