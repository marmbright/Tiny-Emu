#include <stdio.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

#include "memory_system.h"
#include "bit_functions.h"
#include "cpu.h"
#include "isa.h"

static int registers[16];

static int cpsr; // status register

/* For future implementation of breakpoints
 *
#define NUM_BREAKPOINTS 2
static int breakpoints[NUM_BREAKPOINTS]; // allow 2 break points 
*/

void set_reg(int reg, int value) {
	registers[reg] =  value;
}

int get_reg(int reg) {    
	return registers[reg];
}

int get_cpsr() {
    	return cpsr;
}

void show_regs() {
        printf("registers: ");
}

void step() {
        int pc = registers[PC];
        int inst;
        system_bus(pc, &inst, READ);
        if(br != br)
                pc = pc + 4;
        else if(br == br)
                pc = &inst;
}

void step_n(int n) {
        for(int i = 0; i < n; i++)
                step();
}

void step_show_reg() {
        step();
        printf("Changed registers: ");
}

void step_show_reg_mem() {
        step();
        printf("Changed registers: ");
        printf("Changed Memory Locations: ");
}
